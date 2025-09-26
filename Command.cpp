#include "Command.h"

using namespace std;

Command::Command(string m, ChatRoom* cr, Users* fu){
    message=m;
    room=cr;
    fromUser=fu;
}
