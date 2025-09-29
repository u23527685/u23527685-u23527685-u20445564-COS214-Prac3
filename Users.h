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
#include "Observer.h"
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
class Users : public Observer
{
    protected:
        vector<ChatRoom *>chatRooms;
        string name;
        vector<Command *>commandQueue;

    public:
        Users(const string &userName);
        virtual ~Users();
        
        /**
         * @brief Update method from Observer pattern
         * @param msg The notification message
         * @param sender The sender's name
         */
        void update(const string& msg, const string& sender) override {
            cout << "[Observer] " << getName() << " received notification from " 
                 << sender << ": " << msg << endl;
        }

        ChatRoomIterator createIterator()const;
        CommandIterator createcommandIterator()const;

        virtual void send(const string &message, ChatRoom *room) = 0;
        virtual void receive(const string &message, Users *fromUser, ChatRoom *room) = 0;
        virtual void addCommand(Command *command) = 0;
        virtual void executeAll() = 0;
        virtual string getName() const;
        virtual void addChatRoom(ChatRoom *room);
        virtual void removeChatRoom(ChatRoom *room);
        virtual string getUserType() const = 0;
        virtual ChatRoom *getChatRooms() const;
};

#endif // USERS_H