/**
 * @file [Command.h]
 * @brief [Abstract base class header implementation for all Command types in the chat system]
 * @author [Okaile Gaesale]
 * @date [2025-09-24]
 */
#ifndef COMMAND_H
#define COMMAND_H

using namespace std;
#include <string>
#include <vector>

#include "Users.h"
#include "ChatRoom.h"

/**
 * @class Command
 * @brief Abstract base class representing commands in the chat system
 *
 * This class defines the interface for all command types
 */
class Command{
    protected:
        string message;
        ChatRoom* room;
        Users* fromUser;

    public:
        /**
         * @brief pure virtual function for excecuting the command
         */
        virtual void execute()=0;
        /**
         * @brief Constructor with message,chatroom and user
         * @param m the message
         * @param cr the chatroom the message is to be sent in
         * @param fu the user who sent the message
         */
        Command(string m, ChatRoom* cr, Users* fu);
};

#endif