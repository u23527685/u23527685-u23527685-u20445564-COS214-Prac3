#ifndef COMMAND_H
#define COMMAND_H

using namespace std;
#include <string>
#include <vector>

#include "Users.h"
#include "ChatRoom.h"


class Command{
    protected:
        string message;
        ChatRoom* room;
        Users* fromUser;

    public:
        virtual void execute()=0;
        Command(string m, ChatRoom* cr, Users* fu);
};

#endif