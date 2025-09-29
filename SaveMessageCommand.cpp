/**
 * @file [SaveMessageCommand.cpp]
 * @brief [Implementation of the concrete Save Message Command class]
 * @author [Okaile Gaesale]
 * @date [2025-09-24]
 */
#include"SaveMessageCommand.h"
using namespace std;

void SaveMessageCommand::execute(){
    room->saveMessage(message,fromUser);
}