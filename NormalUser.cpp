
/**
 * @file [NormalUser.cpp]
 * @brief [Implementation of NormalUser class]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */
#include "NormalUser.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SaveMessageCommand.h"
#include "SendMessageCommand.h"
#include <iostream>

using namespace std;

NormalUser::NormalUser(): Users("NormalUser"){
    name = "Default User";
    cout << "NormalUser created: " << name << endl;
}

NormalUser::NormalUser(const string& userName): Users(userName){
    name = userName;
    cout << "NormalUser created: " << name << endl;
}

NormalUser::~NormalUser() {
    cout << "NormalUser " << name << " destroyed" << endl;
}

void NormalUser::send(const string& message, ChatRoom* room) {
    if (room != nullptr) {
        cout << name << " sends to " << room->getRoomName() 
             << ": " << message << endl;

        string userMessage = message;
        SaveMessageCommand savemessage(userMessage,room,this);
        SendMessageCommand sendmessage(userMessage,room,this);
        sendmessage.execute();
        savemessage.execute();
    } else {
        cout << "Cannot send message - room is null!" << endl;
    }
}

void NormalUser::receive(const string& message, Users* fromUser, ChatRoom* room) {
    if (fromUser != nullptr && room != nullptr) {
        cout << "[" << room->getRoomName() << "] " << name 
             << " received from " << fromUser->getName() << ": " << message << endl;

        if (message.find("[ADMIN]") != string::npos) {
            cout << name << " acknowledges admin message" << endl;
        } else if (message.find("[CO-ADMIN]") != string::npos) {
            cout << name << " notes co-admin message" << endl;
        }

        if (message.find("hello") != string::npos || message.find("hi") != string::npos) {
            cout << name << " smiles at the greeting" << endl;
        }
    } else {
        cout << "Cannot receive message - invalid parameters!" << endl;
    }
}

void NormalUser::addCommand(Command* command) {
    if (command != nullptr) {
        commandQueue.push_back(command);
        cout << name << " added command to queue" << endl;
    } else {
        cout << "Cannot add null command!" << endl;
    }
}

void NormalUser::executeAll() {
    //iterator
    if (!commandQueue.empty()) {
        cout << name << " executing all queued commands..." << endl;
        auto commIT= createcommandIterator();
        for(commIT.first();!commIT.isDone();commIT.next()){
            Command* com=commIT.current();
            com->execute();
        }
        cout << "All commands executed by " << name << endl;
    } else {
        cout << "No commands to execute for " << name << endl;
    }
}

string NormalUser::getUserType() const {
    return "Normal";
}

string NormalUser::getName() const {
    return name;
}

