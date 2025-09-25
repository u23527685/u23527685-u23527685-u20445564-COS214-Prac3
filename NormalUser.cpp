/**
 * @file [NormalUser.cpp]
 * @brief [Implementation of NormalUser class]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */
#include "NormalUser.h"
#include "ChatRoom.h"
#include "Command.h"
#include <iostream>

using namespace std;

NormalUser::NormalUser() {
    chatRooms = nullptr;
    name = "Default User";
    commandQueue = nullptr;
    cout << "NormalUser created: " << name << endl;
}

NormalUser::NormalUser(const string& userName) {
    chatRooms = nullptr;
    name = userName;
    commandQueue = nullptr;
    cout << "NormalUser created: " << name << endl;
}

NormalUser::~NormalUser() {
    if (commandQueue != nullptr) {
        commandQueue = nullptr;
    }
    chatRooms = nullptr;
    cout << "NormalUser " << name << " destroyed" << endl;
}

void NormalUser::send(const string& message, ChatRoom* room) {
    if (room != nullptr) {
        cout << name << " sends to " << room->getRoomName() 
             << ": " << message << endl;

        string userMessage = message;
        room->sendMessage(&userMessage, this);
        room->saveMessage(userMessage, this);
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
        commandQueue = command;
        cout << name << " added command to queue" << endl;
    } else {
        cout << "Cannot add null command!" << endl;
    }
}

void NormalUser::executeAll() {
    if (commandQueue != nullptr) {
        cout << name << " executing all queued commands..." << endl;
        //commandQueue->execute();
        commandQueue = nullptr;
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
