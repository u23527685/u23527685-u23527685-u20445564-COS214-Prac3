using namespace std;
#include "ChatRoomIterator.h"

void ChatRoomIterator::first(){ index = 0; }

void ChatRoomIterator::next(){ if (index < rooms.size()) ++index; }

bool ChatRoomIterator::isDone() const  { return index >= rooms.size(); }

ChatRoom* ChatRoomIterator::current()const {
    if (!isDone()) return rooms[index];
    return nullptr;
}

size_t ChatRoomIterator::getIndex()const{
    return index;
}