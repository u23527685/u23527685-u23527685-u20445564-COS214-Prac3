#ifndef CHATROOMITERATOR_H
#define CHATROOMITERATOR_H

#include <cstddef>
class ChatRoom;
#include "ChatRoom.h"
#include "Iterator.h"
#include <vector>

class ChatRoomIterator : public Iterator<ChatRoom*> {
private:
    const vector<ChatRoom*>& rooms;
    size_t index;

public:
    ChatRoomIterator(const vector<ChatRoom*>& roomList) 
        : rooms(roomList), index(0) {}

    void first() override;

    void next() override ;

    bool isDone() const override ;

    ChatRoom* current() const override ;

    int getIndex()const override;
};

#endif // CHATROOMITERATOR_H
