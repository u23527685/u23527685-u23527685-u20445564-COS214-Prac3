/**
 * @file [Users.h]
 * @brief [Abstract base class header implementation for all user types in the chat system]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>
#include "ChatRoomIterator.h"
#include "CommandIterator.h"
#include "ChatRoom.h"

class ChatRoomIterator;

using namespace std;

// Forward declarations to avoid circular dependencies
class Command;

/**
 * @class Users
 * @brief Abstract base class representing users in the chat system
 *
 * This class defines the interface for all user types (Admin, CoAdmin, Normal)
 * and implements the colleague role in the Mediator pattern.
 */
class Users
{
    protected:                 // Changed to protected so derived classes can access
        vector<ChatRoom *>chatRooms;   ///< Pointer to chat rooms the user is in
        string name;           ///< User's name
        vector<Command *>commandQueue; ///< Queue of commands to execute

    public:
        /**
         * @brief Default constructor
         */
        Users();

        /**
         * @brief Constructor with name
         * @param userName The name of the user
         */
        Users(const string &userName);

        /**
         * @brief Virtual destructor for proper cleanup
         */
        virtual ~Users();

        /**
         * @brief factory method for chatroomiterator
         */
        ChatRoomIterator createIterator()const;

        /**
         * @brief factory method for commandIterator
         */
        CommandIterator createcommandIterator()const;

        /**
         * @brief Send a message to a chat room (pure virtual)
         * @param message The message to send
         * @param room Pointer to the chat room (corrected to pointer)
         */
        virtual void send(const string &message, ChatRoom *room) = 0;

        /**
         * @brief Receive a message from a chat room (pure virtual)
         * @param message The received message
         * @param fromUser Pointer to the user who sent the message (corrected to pointer)
         * @param room Pointer to the chat room (corrected to pointer)
         */
        virtual void receive(const string &message, Users *fromUser, ChatRoom *room) = 0;

        /**
         * @brief Add a command to the queue (pure virtual)
         * @param command Pointer to the command to add (corrected to pointer)
         */
        virtual void addCommand(Command *command) = 0;

        /**
         * @brief Execute all queued commands (pure virtual)
         */
        virtual void executeAll() = 0;

        /**
         * @brief Get the user's name
         * @return The user's name
         */
        virtual string getName() const;

        /**
         * @brief Add a chat room to user's list
         * @param room Pointer to the chat room to add
         */
        virtual void addChatRoom(ChatRoom *room);
        /**
         * @brief Get the mediator (chat room)
         * @return Pointer to the chat room mediator
         */
        /*virtual ChatRoom* getChatRoom() const {
            return chatRooms;
        }*/
        /**
         * @brief Remove a chat room from user's list
         * @param room Pointer to the chat room to remove
         */
        virtual void removeChatRoom(ChatRoom *room);

        /**
         * @brief Get user type as string (pure virtual)
         * @return String representing the user type
         */
        virtual string getUserType() const = 0;

        /**
         * @brief Get the chat rooms the user is in
         * @return Pointer to chat rooms
         */
        virtual ChatRoom *getChatRooms() const;
};

#endif // USERS_H