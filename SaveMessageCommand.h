/**
 * @file [SaveMessageCommand.h]
 * @brief [Concrete class header implementation for Save Message Command]
 * @author [Okaile Gaesale]
 * @date [2025-09-24]
 */
#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

using namespace std;
#include <string>
#include <vector>

#include "Command.h"

/**
 * @class SaveMessageCommand
 * @brief Concrete class representing Save Message Command in the chat system
 *
 */
class SaveMessageCommand: public Command{
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
        SaveMessageCommand(string m, ChatRoom* cr, Users* fu):Command(m,cr,fu){}
};

#endif