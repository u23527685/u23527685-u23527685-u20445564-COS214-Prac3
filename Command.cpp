#include "Command.h"

using namespace std;

Command::Command(string m, ChatRoom cr, User fu){
    message=m;
    room=cr;
    fromUser=fu;
}
