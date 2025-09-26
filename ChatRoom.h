/**
 * @file [ChatRoom.h]
 * @brief [Abstract class ChatRoom header file]
 * @author [Marodi Jessica,Okaile Gaesale]
 * @date [2025-09-24]
 */

#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <vector>

#include "ChatHistoryIterator.h"
#include "UserIterator.h"

using namespace std;

// Forward declaration to avoid circular dependency
class Users;

/**
 * @class ChatRoom
 * @brief [Abstract mediator class that manages communication between users]
 * 
 * [This class serves as the abstract mediator in the Mediator pattern,
 * defining the interface for communication between users in a chat room.
 * It manages user registration, message distribution, and chat history.]
 */
class ChatRoom {
protected:
    vector<Users*> users;                    ///< [Dynamic array of user pointers]
    vector<string*> chatHistory;              ///< [Dynamic array of chat messages] 

private:
    
    /**
     * @brief [Find user index in the users vector]
     * @param user [Pointer to the user to find]
     * @return [Index of user, or -1 if not found]
     */
    int findUserIndex(Users* user) const;

public:
    /**
     * @brief [factory function for users iterator]
     */
    UsersIterator createUserIterator() const {
        return UsersIterator(users);
    }

    /**
     * @brief [factory function for chat history iterator]
     */
    ChatHistoryIterator createChatHistoryIterator() const {
        return ChatHistoryIterator(chatHistory);
    }
    /**
     * @brief [Constructor, initializes empty chat room]
     */
    ChatRoom();
    
    /**
     * @brief [Virtual destructor for proper cleanup]
     */
    virtual ~ChatRoom();
    
    /**
     * @brief [Register a user with the chat room]
     * @param user [Pointer to the user to register]
     */
    virtual void registerUser(Users* user);
    
    /**
     * @brief [Send a message to all users in the room (mediator function)]
     * @param message [Pointer to the message to send]
     * @param fromUser [Pointer to the user sending the message]
     */
    virtual void sendMessage(string* message, Users* fromUser);
    
    /**
     * @brief [Save a message to chat history]
     * @param message [The message to save]
     * @param fromUser [Pointer to the user who sent the message]
     */
    virtual void saveMessage(const string& message, Users* fromUser);
    
    /**
     * @brief [Remove a user from the chat room]
     * @param user [Pointer to the user to remove]
     */
    virtual void removeUser(Users* user);
    
    /**
     * @brief [Get the name of the chat room (pure virtual)]
     * @return [The name of the chat room]
     */
    virtual string getRoomName() const = 0;

    /**
     * @brief [calls the getroomname function]
     * @return [The name of the chat room]
     */
    string getRoomNameFunc();
    
    /**
     * @brief [Get the current number of users in the room]
     * @return [Number of users]
     */
    int getUserCount() const;
    
    /**
     * @brief [Get the current number of messages in history]
     * @return [Number of messages]
     */
    int getHistoryCount() const;
    
    /**
     * @brief [Get all users in the room (for admin purposes)]
     * @return [Vector containing all user pointers]
     */
    vector<Users*> getUsers() const;
    
    /**
     * @brief [Get chat history (for viewing/admin purposes)]
     * @return [Vector containing all chat messages]
     */
    vector<string*> getChatHistory() const;
    
    /**
     * @brief [Check if a user is in the room]
     * @param user [Pointer to the user to check]
     * @return [True if user is in room, false otherwise]
     */
    bool isUserInRoom(Users* user) const;
    
    /**
     * @brief [Get room statistics]
     * @return [String containing room information]
     */
    virtual string getRoomStats() const;
    
    /**
     * @brief [Clear all chat history (admin function)]
     */
    virtual void clearHistory();
    
    /**
     * @brief [Broadcast a system message to all users]
     * @param message [The system message to broadcast]
     */
    virtual void broadcastSystemMessage(const string& message);
};

#endif // CHATROOM_H
