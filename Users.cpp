/**
 * @file [Users.cpp]
 * @brief [Implementation of the abstract Users base class]
 * @author [Marodi Jessica, Okaile Gaesale]
 * @date [2025-09-24]
 */
#include "Users.h"
#include "Command.h"
#include "ChatRoom.h"
#include <iostream>

using namespace std;

ChatRoomIterator Users::createIterator()const{
    return ChatRoomIterator(chatRooms);
}

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
    chatRooms.clear();
    commandQueue.clear();
    cout << "User " << name << " destroyed" << endl;
}

string Users::getName() const {
    return name;
}

void Users::addChatRoom(ChatRoom* room) {
    if (room != nullptr) {
        chatRooms.push_back(room);
        cout << "User " << name << " added to room: "<<room->getRoomNameFunc() << endl;
    } else {
        cout << "Cannot add null chat room for user " << name << endl;
    }
}

void Users::removeChatRoom(ChatRoom* room) {
    if(room==nullptr){
        cout << "Cannot remove null chat room for user " << name << endl;
        return;
    }
    auto roomsIterator=createIterator();
    for(roomsIterator.first();roomsIterator.isDone();roomsIterator.next()){
        ChatRoom* currroom=roomsIterator.current();
        if(currroom==room){
            chatRooms.erase(chatRooms.begin()+roomsIterator.getIndex());
            cout << "User " << name << " removed from room: " << room->getRoomName() << endl;
        }
    }
    cout << "User " << name << " is not in room: " << room->getRoomName() << endl;
}

ChatRoom* Users::getChatRooms() const {
    return nullptr;
}
