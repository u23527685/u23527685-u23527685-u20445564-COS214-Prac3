/**
 * @file [CtrlCat.cpp]
 * @brief [Implementation of CtrlCat chat room]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#include "CtrlCat.h"
#include <iostream>

CtrlCat::CtrlCat() {
    cout << "CtrlCat room created! Welcome to the feline programming paradise!" << endl;
}

CtrlCat::~CtrlCat() {
    /*if (users != nullptr) {
        users = nullptr;
    }
    if (chatHistory != nullptr) {
        delete[] chatHistory;
        chatHistory = nullptr;
    }*/
}

void CtrlCat::registerUser(Users* user) {
    /*if (user != nullptr) {
        if (users == nullptr) {
            users = user;
        }
        
        cout << user->getName() << " (" << user->getUserType() 
                 << ") has joined CtrlCat!" << endl;
        
        user->addChatRoom(this);
    }*/
}

void CtrlCat::sendMessage(string* message, Users* fromUser) {
    if (message != nullptr && fromUser != nullptr) {
        cout << "[CtrlCat] " << fromUser->getName() 
                 << " says: " << *message << endl;
        
        //saveMessage(*message, fromUser);
    }
}

void CtrlCat::removeUser(Users* user) {
    /*if (user != nullptr) {
        cout << user->getName() << " has left CtrlCat!" << endl;
        
        user->removeChatRoom(this);
        
        if (users == user) {
            users = nullptr;
        }
    }*/
}

string CtrlCat::getRoomName() const {
    return "CtrlCat";
}

void CtrlCat::saveMessage(const string& message, Users* fromUser) {
    /*if (fromUser != nullptr) {
        string formattedMessage = "[CtrlCat] " + fromUser->getName() + ": " + message;
        
        if (chatHistory == nullptr) {
            chatHistory = new string(formattedMessage);
        }
    }*/
}