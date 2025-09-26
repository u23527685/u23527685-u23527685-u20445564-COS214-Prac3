#include"SaveMessageCommand.h"
using namespace std;

void SaveMessageCommand::execute(){
    room->saveMessage(message,fromUser);
}