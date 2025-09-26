/**
 * @file [CoAdminUser.cpp]
 * @brief [Implementation of CoAdminUser class]
 * @author [Marodi Jessica]
 * @date 2025-09-24
 */

#include "CoAdminUser.h"
#include "ChatRoom.h"
#include "Command.h"
#include <iostream>

CoAdminUser::CoAdminUser() {
    
    name = "Default CoAdmin";
    
    cout << "CoAdminUser created: " << name << endl;
}

CoAdminUser::CoAdminUser(const string& userName) {
    
    name = userName;
    
    cout << "CoAdminUser created: " << name << endl;
}

CoAdminUser::~CoAdminUser() {
    cout << "CoAdminUser " << name << " destroyed" << endl;
}

void CoAdminUser::send(const string& message, ChatRoom* room) {
    /*if (room != nullptr) {
        string coAdminMessage = "[CO-ADMIN] " + message;
        cout << "Co-Admin " << name << " sends to " << room->getRoomName() 
                 << ": " << coAdminMessage << endl;
        
        room->sendMessage(&coAdminMessage, this);
        
        room->saveMessage(coAdminMessage, this);
    } else {
        cout << "Cannot send message - room is null!" << endl;
    }*/
}

void CoAdminUser::receive(const string& message, Users* fromUser, ChatRoom* room) {
    /*if (fromUser != nullptr && room != nullptr) {
        cout << "[" << room->getRoomName() << "] Co-Admin " << name 
                 << " received from " << fromUser->getName() << ": " << message << endl;
        
        if (message.find("[URGENT]") != string::npos) {
            cout << "Co-Admin " << name << " flagged urgent message for review" << endl;
        }
    } else {
        cout << "Cannot receive message - invalid parameters!" << endl;
    }*/
}

void CoAdminUser::addCommand(Command* command) {
    /*if (command != nullptr) {
        commandQueue = command;
        cout << "Co-Admin " << name << " added command to queue" << endl;
    } else {
        cout << "Cannot add null command!" << endl;
    }*/
}

void CoAdminUser::executeAll() {
    /*if (commandQueue != nullptr) {
        cout << "Co-Admin " << name << " executing all queued commands..." << endl;
        
        commandQueue->execute();
        
        
        
        cout << "All commands executed by Co-Admin " << name << endl;
    } else {
        cout << "No commands to execute for Co-Admin " << name << endl;
    }*/
}

string CoAdminUser::getUserType() const {
    return "Co-Admin";
}

string CoAdminUser::getName() const {
    return name;
}

void CoAdminUser::assistModeration(const string& message, ChatRoom* room) {
    /*if (room != nullptr) {
        cout << "Co-Admin " << name << " is assisting with moderation of message: \"" 
                 << message << "\" in " << room->getRoomName() << endl;
        
        if (message.length() > 100) {
            cout << "Co-Admin " << name << " suggests: Message might be too long" << endl;
        }
        
        if (message.find("spam") != string::npos || message.find("SPAM") != string::npos) {
            cout << "Co-Admin " << name << " flagged potential spam content" << endl;
        }
        
        string moderationLog = "Co-Admin moderation by " + name + " on message: " + message;
        room->saveMessage(moderationLog, this);
    } else {
        cout << "Cannot assist moderation - room is null!" << endl;
    }*/
}