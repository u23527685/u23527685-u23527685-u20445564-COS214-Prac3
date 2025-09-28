/**
 * @file [SendMessageCommand.cpp]
 * @brief [Implementation of the concrete Send Message Command class]
 * @author [Okaile Gaesale]
 * @date [2025-09-24]
 */
#include"SendMessageCommand.h"
using namespace std;

void SendMessageCommand::execute(){
    room->sendMessage(&message,fromUser);
}