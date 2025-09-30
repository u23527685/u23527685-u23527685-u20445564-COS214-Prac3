
/**
 * @file [Users.h]
 * @brief [Abstract base class header implementation for all user types in the chat system]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#ifndef USERS_H
#define USERS_H

#include <string>
#include <iostream>
#include <vector>
#include "ChatRoomIterator.h"
#include "CommandIterator.h"

class ChatRoom;
class ChatRoomIterator;
class Command;

using namespace std;

/**
 * @class Users
 * @brief Abstract base class representing users in the chat system
 *
 * This class defines the interface for all user types (Admin, CoAdmin, Normal)
 * and implements the colleague role in the Mediator pattern.
 */
class Users
{
    protected:
         /**
         * @brief List of chat rooms this user is part of
         */
        vector<ChatRoom *>chatRooms;
         /**
         * @brief Name of the user
         */
        string name;
         /**
         * @brief Queue of commands for the Command pattern
         */

        vector<Command *>commandQueue;

    public:
        Users(const string &userName);
        virtual ~Users();
        
        /**
         * @brief Update method from Observer pattern
         * @param fromUser[user who sent the message]
         */
        void update(const Users* fromUser)  {
            cout << "[Observer] " << getName() << " received notification from " << fromUser->getName() << endl;
        }

        /**
         * @brief Create an iterator over the chat rooms the user is part of
         * @return ChatRoomIterator [Iterator over user's chat rooms]
         */

        ChatRoomIterator createIterator()const;

        /**
         * @brief Create an iterator over the user's command queue
         * @return CommandIterator [Iterator over user's commands]
         */

        CommandIterator createcommandIterator()const;

        /**
         * @brief Send a message to a chat room
         * @param message [Message content]
         * @param room [Chat room to send the message to]
         */
        virtual void send(const string &message, ChatRoom *room) = 0;


    /**
     * @brief Receive a message from another user in a chat room
     * @param message [Message content]
     * @param fromUser [Sender user]
     * @param room [Chat room where the message was sent]
     */

        virtual void receive(const string &message, Users *fromUser, ChatRoom *room) = 0;
        /**
     * @brief Add a command to the user's command queue
     * @param command [Command to add]
     */

        virtual void addCommand(Command *command) = 0;
           /**
         * @brief Execute all commands in the user's command queue
         */
        virtual void executeAll() = 0;
        virtual string getName() const;
        
        /**
         * @brief Add the user to a chat room
         * @param room [Chat room to add]
         */
        virtual void addChatRoom(ChatRoom *room);

        /**
         * @brief Remove the user from a chat room
         * @param room [Chat room to remove]
         */
        virtual void removeChatRoom(ChatRoom *room);
        /**
         * @brief Get the type of the user (Admin, CoAdmin, Normal)
         * @return string [User type]
         */
        virtual string getUserType() const = 0;
        /**
         * @brief Get a pointer to the user's chat rooms
         * @return ChatRoom* [Pointer to chat rooms; nullptr if none]
         */
        virtual ChatRoom *getChatRooms() const;
};


#endif // USERS_H