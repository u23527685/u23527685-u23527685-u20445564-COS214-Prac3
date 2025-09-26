#include"SendMessageCommand.h"
using namespace std;

void SendMessageCommand::execute(){
    room->sendMessage(&message,fromUser);
}