
/**
 * @file [Users.cpp]
 * @brief [Implementation of the abstract Users base class for all user types]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#include "Users.h"
#include "ChatRoom.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

// Constructor
Users::Users(const std::string &userName) : name(userName) {}

// Virtual destructor
Users::~Users() {}

// Return user's name
std::string Users::getName() const {
    return name;
}

// Add a chat room to the user's list
void Users::addChatRoom(ChatRoom *room) {
    if (!room) return;

    bool exists = false;
    for (size_t i = 0; i < chatRooms.size(); ++i) {
        if (chatRooms[i] == room) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        chatRooms.push_back(room);
    }
}


// Remove a chat room from the user's list
void Users::removeChatRoom(ChatRoom *room) {
    if (!room) return;
    for (size_t i = 0; i < chatRooms.size(); ++i) {
        if (chatRooms[i] == room) {
            // Remove element manually
            for (size_t j = i; j < chatRooms.size() - 1; ++j) {
                chatRooms[j] = chatRooms[j + 1];
            }
            chatRooms.pop_back();
            break;
        }
    }
}

// Return the user's chat rooms (example: first room)
ChatRoom* Users::getChatRooms() const {
    if (!chatRooms.empty()) {
        return chatRooms.front();
    }
    return nullptr;
}

// Create a chat room iterator
ChatRoomIterator Users::createIterator() const {
    return ChatRoomIterator(chatRooms);
}

// Create a command iterator
CommandIterator Users::createcommandIterator() const {
    return CommandIterator(commandQueue);
}

