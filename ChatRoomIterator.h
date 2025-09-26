#ifndef CHATROOMITERATOR_H
#define CHATROOMITERATOR_H

#include "Iterator.h"
#include <vector>

class ChatRoom;

class ChatRoomIterator : public Iterator<ChatRoom*> {
private:
    const vector<ChatRoom*>& rooms;
    size_t index;

public:
    ChatRoomIterator(const vector<ChatRoom*>& roomList) 
        : rooms(roomList), index(0) {}

    void first() override { index = 0; }

    void next() override { if (index < rooms.size()) ++index; }

    bool isDone() const override { return index >= rooms.size(); }

    ChatRoom* current() const override {
        if (!isDone()) return rooms[index];
        return nullptr;
    }

    size_t getIndex()const override;
};

#endif // CHATROOMITERATOR_H
