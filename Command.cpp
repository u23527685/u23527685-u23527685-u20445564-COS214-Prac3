/**
 * @file [Command.cpp]
 * @brief [Implementation of the abstract Command base class]
 * @author [Okaile Gaesale]
 * @date [2025-09-24]
 */

#include "Command.h"

using namespace std;

Command::Command(string m, ChatRoom* cr, Users* fu){
    message=m;
    room=cr;
    fromUser=fu;
}
