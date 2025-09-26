using namespace std;
#include "ChatHistoryIterator.h"

void ChatHistoryIterator::first(){ index = 0; }

void ChatHistoryIterator::next(){ if (index < history.size()) ++index; }

bool ChatHistoryIterator::isDone() const  { return index >= history.size(); }

string* ChatHistoryIterator::current()const {
    if (!isDone()) return history[index];
    return nullptr;
}

size_t ChatHistoryIterator::getIndex()const{
    return index;
}