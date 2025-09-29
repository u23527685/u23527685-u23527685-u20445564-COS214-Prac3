/**
 * @file [SendMessageCommand.h]
 * @brief [Concrete class header implementation for Send Message Command]
 * @author [Okaile Gaesale]
 * @date [2025-09-24]
 */
#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

using namespace std;
#include <string>
#include <vector>

#include "Command.h"

/**
 * @class SendMessageCommand
 * @brief Concrete class representing Send Message Command in the chat system
 *
 */
class SendMessageCommand: public Command{
    public:
        /**
         * @brief function for excecuting the command
         */
        virtual void execute();

        /**
         * @brief Constructor with message,chatroom and user
         * @param m the message
         * @param cr the chatroom the message is to be sent in
         * @param fu the user who sent the message
         */
        SendMessageCommand(string m, ChatRoom* cr, Users* fu):Command(m,cr,fu){}
};

#endif