#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

using namespace std;
#include <string>
#include <vector>

#include "Command.h"


class SaveMessageCommand: public Command{
    public:
            virtual void execute();
            SaveMessageCommand(string m, ChatRoom* cr, Users* fu):Command(m,cr,fu){}
};

#endif