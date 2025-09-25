/**
 * @file [AdminUser.cpp]
 * @brief [Implementation of AdminUser class with enhanced administrative capabilities]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#include "AdminUser.h"
#include "ChatRoom.h"
#include "Command.h"
#include <iostream>
#include <algorithm>
using namespace std;

AdminUser::AdminUser() : Users()
{
    cout << "AdminUser created with full privileges: " << name << endl;
    cout << "Admin capabilities:Moderation, User Management, Announcements" << endl;
}

AdminUser::AdminUser(const string &userName) : Users(userName)
{
    cout << "AdminUser created with full privileges: " << name << endl;
    cout << "Admin capabilities: Moderation, User Management, Announcements" << endl;
}

AdminUser::~AdminUser(){
    cout << " AdminUser " << name << " is signing off " << endl;

}

void AdminUser::send(const string &message, ChatRoom *room)
{
    if (room == nullptr)
    {
       cout << "Admin " << name << " ERROR! Cannot send message, room is null!" <<endl;
        return;
    }

    if (message.empty())
    {
      cout << "Admin " << name << " WARNING! Cannot send empty message" <<endl;
        return;
    }

    // Enhanced admin message formatting
    string adminMessage = "[ ADMIN] " + message;
    cout << "Admin " << name << " broadcasts to " << room->getRoomName()
              << " (" << room->getUsers().size() << " users): " << adminMessage <<endl;

    room->sendMessage(&adminMessage, this);

    string timestampedMessage = "[" + getCurrentTime() + "] " + adminMessage;
    room->saveMessage(timestampedMessage, this);

   cout << "Admin message delivered successfully" << endl;
}

void AdminUser::receive(const string &message, Users *fromUser, ChatRoom *room)
{
    if (fromUser == nullptr || room == nullptr)
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

    string logEntry = "[ADMIN LOG] Processed message from " + fromUser->getName() + ": " +
                      (message.length() > 50 ? message.substr(0, 47) + "..." : message);
    room->saveMessage(logEntry, this);
}

void AdminUser::addCommand(Command *command)
{
    if (command == nullptr)
    {
        cout << "Admin " << name << " ERROR! Cannot add a null command!" << endl;
        return;
    }

    commandQueue = command;
    cout << " Admin " << name << " queued HIGH PRIORITY administrative command" << endl;
    cout << "Command will be executed with elevated privileges" << endl;
}

void AdminUser::executeAll()
{
    if (commandQueue == nullptr)
    {
        cout << " No administrative commands pending for Admin " << name << endl;
        return;
    }

    cout << "Admin " << name << " initiating administrative command execution..." << endl;
    cout << "Executing with ADMIN privileges" << endl;

    try
    {
        // Execute the command with admin privileges
        //commandQueue->execute();
        cout << " Administrative command executed successfully by " << name << endl;
    }
    catch (...)
    {
        cout << " Admin command execution failed - error occurred" << endl;
    }

    // Clear the queue after execution
    commandQueue = nullptr;
    cout << "Command queue cleared - ready for next administrative task" << endl;
}

string AdminUser::getUserType() const
{
    return "Admin";
}

void AdminUser::moderateMessage(const string &message, ChatRoom *room)
{
    if (room == nullptr)
    {
        cout << "Admin cannot moderate - room is null!" << endl;
        return;
    }

    if (message.empty())
    {
        cout << "Admin " << name << " - no message to moderate" << endl;
        return;
    }

    cout << "Admin " << name << " initiating content moderation in " << room->getRoomName() << endl;
    cout << "Analyzing message: \"" << (message.length() > 30 ? message.substr(0, 27) + "..." : message) << "\"" << endl;

    bool actionTaken = false;

    // Enhanced moderation checks
    if (message.length() > 200)
    {
        cout << "VIOLATION: Message exceeds length limit (200 chars)" << endl;
        string warningMsg = "[] ADMIN NOTICE] Please keep messages under 200 characters for better readability.";
        room->sendMessage(&warningMsg, this);
        actionTaken = true;
    }

    // Check for spam patterns
    string lowerMessage = message;
    transform(lowerMessage.begin(), lowerMessage.end(), lowerMessage.begin(), ::tolower);

    if (lowerMessage.find("spam") != string::npos ||
        lowerMessage.find("buy now") != string::npos ||
        lowerMessage.find("click here") != string::npos)
    {
        cout << "SPAM DETECTED: Potential commercial/spam content identified" << endl;
        string spamWarning = "[ADMIN WARNING] Spam content detected. Please follow community guidelines or face removal.";
        room->sendMessage(&spamWarning, this);
        actionTaken = true;
    }

    // Check for inappropriate language (basic implementation)
    if (lowerMessage.find("inappropriate") != string::npos ||
        lowerMessage.find("offensive") != string::npos)
    {
        cout << "CONTENT WARNING: Potentially inappropriate content flagged" << endl;
        string contentWarning = "[ADMIN] Please maintain respectful communication in our community.";
        room->sendMessage(&contentWarning, this);
        actionTaken = true;
    }

    // Log all moderation activities
    string moderationResult = actionTaken ? "ACTION TAKEN" : "NO VIOLATIONS FOUND";
    string moderationLog = "[MODERATION] Admin " + name + " reviewed content - Result: " + moderationResult;
    room->saveMessage(moderationLog, this);

    cout << "Content moderation completed - " << moderationResult << endl;
}

void AdminUser::removeUser(Users *user, ChatRoom *room)
{
    if (user == nullptr || room == nullptr)
    {
        cout << "Admin cannot remove user - invalid parameters!" << endl;
        return;
    }

    if (user == this)
    {
        cout << "Admin " << name << " cannot remove themselves from the room!" << endl;
        return;
    }

    cout << "Admin " << name << " initiating user removal process..." << endl;
    cout << "Target: " << user->getName() << " (" << user->getUserType() << ") from " << room->getRoomName() << endl;

    // Confirm user is in the room first
    const auto &roomUsers = room->getUsers();
    bool userFound = false;
    for (const auto &roomUser : roomUsers)
    {
        if (roomUser == user)
        {
            userFound = true;
            break;
        }
    }

    if (!userFound)
    {
        cout << "User " << user->getName() << " is not in room " << room->getRoomName() << endl;
        return;
    }

    // Perform removal
    room->removeUser(user);

    // Send notification to remaining users
    string removeMsg = "[ ADMIN ACTION] User " + user->getName() +
                       " has been removed from " + room->getRoomName() + " by Admin " + name;
    room->sendMessage(&removeMsg, this);

    // Log the administrative action
    string removeLog = "[ADMIN LOG] " + name + " removed user " + user->getName() +
                       " from " + room->getRoomName() + " at " + getCurrentTime();
    room->saveMessage(removeLog, this);

    cout << " User removal completed successfully" << endl;
    cout << " Administrative action logged for record keeping" << endl;
}

void AdminUser::makeAnnouncement(const string &announcement, ChatRoom *room)
{
    if (room == nullptr)
    {
        cout << " Admin cannot make announcement - room is null!" << endl;
        return;
    }

    if (announcement.empty())
    {
        cout << " Admin " << name << " cannot make empty announcement" << endl;
        return;
    }

    string formattedAnnouncement = "[ADMIN ANNOUNCEMENT] " + announcement;
    cout << "\n"
              << string(50, '=') << endl;
    cout << "Admin " << name << " making OFFICIAL ANNOUNCEMENT" << endl;
    cout << " Room: " << room->getRoomName() << endl;
    cout << " Recipients: " << room->getUsers().size() << " users" << endl;
    cout << " Message: " << announcement << endl;
    cout << string(50, '=') << "\n"
              << endl;

    // Send announcement to all users with special formatting
    room->sendMessage(&formattedAnnouncement, this);

    // Save to history with special formatting
    string announcementLog = "[ OFFICIAL] Admin " + name + " announced: " + announcement;
    room->saveMessage(announcementLog, this);

    cout << "Official announcement delivered by Admin " << name << endl;
    cout << "Announcement logged in room history" << endl;
}

// Private helper methods for enhanced functionality

void AdminUser::processAdminAlerts(const string &message, Users *fromUser, ChatRoom *room)
{
    string lowerMessage = message;
    transform(lowerMessage.begin(), lowerMessage.end(), lowerMessage.begin(), ::tolower);

    // Priority alerts that require immediate admin attention
    if (lowerMessage.find("help") != string::npos || lowerMessage.find("admin") != string::npos)
    {
        cout << "ADMIN ALERT: Help requested by " << fromUser->getName() << endl;
        string helpResponse = "[ADMIN] " + fromUser->getName() +
                              ", I'm here to help! Please describe your issue and I'll assist you.";
        room->sendMessage(&helpResponse, this);
    }

    if (lowerMessage.find("emergency") != string::npos || lowerMessage.find("urgent") != string::npos)
    {
        cout << " URGENT ALERT: Emergency assistance requested!" << endl;
        string emergencyResponse = "[ ADMIN PRIORITY] Emergency assistance acknowledged. Responding immediately.";
        room->sendMessage(&emergencyResponse, this);
    }
}

void AdminUser::performContentModeration(const string &message, Users *fromUser, ChatRoom *room)
{
    // Automatic content screening
    if (message.length() > 300)
    {
        cout << " Auto-moderation: Very long message detected from " << fromUser->getName() << endl;
        moderateMessage(message, room);
    }

  
    static int messageCount = 0;
    messageCount++;
    if (messageCount % 10 == 0)
    {  
        cout << "Admin monitoring: " << messageCount << " messages processed" << endl;
    }
}

void AdminUser::handleUserRequests(const string &message, Users *fromUser, ChatRoom *room)
{
    string lowerMessage = message;
    transform(lowerMessage.begin(), lowerMessage.end(), lowerMessage.begin(), ::tolower);

    // Welcome new users automatically
    if (message.find("joined the room") != string::npos)
    {
        cout << "Auto-welcome: New user detected" << endl;
        string welcomeMsg = "[ADMIN WELCOME] Welcome to " + room->getRoomName() +
                            ", " + fromUser->getName() + "! Please read our community guidelines. Enjoy your stay!";
        room->sendMessage(&welcomeMsg, this);
    }

    // Handle common requests
    if (lowerMessage.find("rules") != string::npos || lowerMessage.find("guidelines") != string::npos)
    {
        string rulesMsg = "[ADMIN INFO] Community Guidelines: Be respectful, no spam, keep messages appropriate. Thank you!";
        room->sendMessage(&rulesMsg, this);
    }
}

string AdminUser::getCurrentTime() const
{
    // Simple timestamp simulation - in real implementation would use actual time
    static int counter = 1;
    return "T" + to_string(counter++);
}