/**
 * @file [AdminUser.cpp]
 * @brief [Implementation of AdminUser class with enhanced administrative capabilities]
 * @author [Marodi Jessica, Okaile Gaesale]
 * @date [2025-09-24]
 */

#include "AdminUser.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SaveMessageCommand.h"
#include "SendMessageCommand.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;



AdminUser::AdminUser(const string &userName) : Users(userName)
{
    cout << "AdminUser created with full privileges: " << name << endl;
    cout << "Admin capabilities: Moderation, User Management, Announcements" << endl;
}

AdminUser::~AdminUser()
{
    cout << "AdminUser " << name << " is signing off" << endl;
}

void AdminUser::send(const string &message, ChatRoom *room)
{
    if (!room)
    {
        cout << "Admin " << name << " ERROR! Cannot send message, room is null!" << endl;
        return;
    }
    if (message.empty())
    {
        cout << "Admin " << name << " WARNING! Cannot send empty message" << endl;
        return;
    }

    string adminMessage = "[ADMIN] " + message;
    string timestampedMessage = "[" + getCurrentTime() + "] " + adminMessage;

    SaveMessageCommand savemessage(timestampedMessage, room, this);
    SendMessageCommand sendmessage(timestampedMessage, room, this);
    sendmessage.execute();
    savemessage.execute();

    cout << "Admin message delivered successfully" << endl;
}

void AdminUser::receive(const string &message, Users *fromUser, ChatRoom *room)
{
    if (!fromUser || !room)
    {
        cout << "Admin cannot process message - invalid parameters!" << endl;
        return;
    }

    cout << "[" << room->getRoomName() << "] Admin " << name
         << " monitoring message from " << fromUser->getName()
         << " (" << fromUser->getUserType() << "): " << message << endl;

    processAdminAlerts(message, fromUser, room);
    performContentModeration(message, fromUser, room);
    handleUserRequests(message, fromUser, room);
}

void AdminUser::addCommand(Command *command)
{
    if (!command)
    {
        cout << "Admin " << name << " ERROR! Cannot add a null command!" << endl;
        return;
    }
    commandQueue.push_back(command);
    cout << "Admin " << name << " queued HIGH PRIORITY administrative command" << endl;
}

void AdminUser::executeAll()
{
    if (commandQueue.empty())
    {
        cout << "No administrative commands pending for Admin " << name << endl;
        return;
    }

    int commandCount = 0;
    while (!commandQueue.empty())
    {
        Command *com = commandQueue.front();
        commandQueue.erase(commandQueue.begin());
        if (com)
        {
            commandCount++;
            cout << "Executing command " << commandCount << "..." << endl;
            com->execute();
            delete com; // ensure Command has a virtual destructor
        }
    }

    cout << "All " << commandCount << " administrative commands executed by Admin " << name << endl;
}

string AdminUser::getUserType() const
{
    return "Admin";
}

void AdminUser::moderateMessage(const string &message, ChatRoom *room)
{
    if (!room || message.empty())
        return;

    cout << "Admin " << name << " moderating message in " << room->getRoomName() << endl;

    bool actionTaken = false;

    if (message.length() > 200)
    {
        cout << "VIOLATION: Message exceeds length limit (200 chars)" << endl;
        send("[ADMIN NOTICE] Keep messages under 200 characters.", room);
        actionTaken = true;
    }

    // Simple lowercase conversion without <algorithm>
    string lowerMessage;
    for (size_t i = 0; i < message.size(); i++)
    {
        char c = message[i];
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        lowerMessage += c;
    }

    // Check for spam or offensive words manually
    if (lowerMessage.find("spam") != string::npos ||
        lowerMessage.find("buy now") != string::npos ||
        lowerMessage.find("click here") != string::npos)
    {
        cout << "SPAM detected" << endl;
        send("[ADMIN WARNING] Spam content detected.", room);
        actionTaken = true;
    }

    if (lowerMessage.find("inappropriate") != string::npos ||
        lowerMessage.find("offensive") != string::npos)
    {
        cout << "CONTENT WARNING detected" << endl;
        send("[ADMIN] Please maintain respectful communication.", room);
        actionTaken = true;
    }

    string logMsg = "[MODERATION] Admin " + name + " reviewed message: ";
    logMsg += actionTaken ? "ACTION TAKEN" : "NO VIOLATIONS";
    send(logMsg, room);
}

void AdminUser::removeUser(Users *user, ChatRoom *room)
{
    if (!user || !room || user == this)
        return;

    if (!room->isUserInRoom(user))
        return;

    room->removeUser(user);
    string msg = "[ADMIN ACTION] User " + user->getName() + " removed by Admin " + name;
    send(msg, room);
}

void AdminUser::makeAnnouncement(const string &announcement, ChatRoom *room)
{
    if (!room || announcement.empty())
        return;

    string formatted = "[ADMIN ANNOUNCEMENT] " + announcement;
    send(formatted, room);
}

void AdminUser::processAdminAlerts(const string &message, Users *fromUser, ChatRoom *room)
{
    string lowerMessage;
    for (size_t i = 0; i < message.size(); i++)
    {
        char c = message[i];
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        lowerMessage += c;
    }

    if (lowerMessage.find("help") != string::npos || lowerMessage.find("admin") != string::npos)
        send("[ADMIN] " + fromUser->getName() + ", I'm here to help!", room);

    if (lowerMessage.find("emergency") != string::npos || lowerMessage.find("urgent") != string::npos)
        send("[ADMIN PRIORITY] Emergency assistance acknowledged.", room);
}

void AdminUser::performContentModeration(const string &message, Users *fromUser, ChatRoom *room)
{
    if (message.length() > 300)
        moderateMessage(message, room);
}

void AdminUser::handleUserRequests(const string &message, Users *fromUser, ChatRoom *room)
{
    if (message.find("joined the room") != string::npos)
        send("[ADMIN WELCOME] Welcome " + fromUser->getName() + "!", room);

    string lowerMessage;
    for (size_t i = 0; i < message.size(); i++)
    {
        char c = message[i];
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        lowerMessage += c;
    }

    if (lowerMessage.find("rules") != string::npos || lowerMessage.find("guidelines") != string::npos)
        send("[ADMIN INFO] Community Guidelines: Be respectful, no spam, keep messages appropriate.", room);
}

string AdminUser::getCurrentTime() const
{
    static int counter = 1;
    string timeStr = "T";
    int temp = counter++;
    string digits = "";
    if (temp == 0)
        digits = "0";
    while (temp > 0)
    {
        char d = '0' + (temp % 10);
        digits = d + digits;
        temp /= 10;
    }
    timeStr += digits;
    return timeStr;
}
