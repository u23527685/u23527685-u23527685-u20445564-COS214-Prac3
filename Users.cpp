/**
 * @file [Users.cpp]
 * @brief [Implementation of the abstract Users base class]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */
#include "Users.h"
#include "ChatRoom.h"
#include "Command.h"
#include <iostream>

using namespace std;

Users::Users() {
    name = "Default User";
    cout << "Base User created: " << name << endl;
}

Users::Users(const string& userName) {
    name = userName;
    cout << "Base User created: " << name << endl;
}

Users::~Users() {
   // destruct vectors
    cout << "User " << name << " destroyed" << endl;
}

string Users::getName() const {
    return name;
}

void Users::addChatRoom(ChatRoom* room) {
    /*if (room != nullptr) {
        chatRooms.push_back();
        cout << "User " << name << " added to room: " << room->getRoomName() << endl;
    } else {
        cout << "Cannot add null chat room for user " << name << endl;
    }*/
}

void Users::removeChatRoom(ChatRoom* room) {
    //iterator
    /*if (room != nullptr && chatRooms == room) {
        cout << "User " << name << " removed from room: " << room->getRoomName() << endl;
        chatRooms = nullptr;
    } else if (room == nullptr) {
        cout << "Cannot remove null chat room for user " << name << endl;
    } else {
        cout << "User " << name << " is not in room: " << room->getRoomName() << endl;
    }*/
}

ChatRoom* Users::getChatRooms() const {
    return nullptr;
}
