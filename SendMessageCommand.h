#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

using namespace std;
#include <string>
#include <vector>

#include "Command.h"


class SendMessageCommand: public Command{
    public:
            virtual void execute();
            SendMessageCommand(string m, ChatRoom* cr, Users* fu):Command(m,cr,fu){}
};

#endif