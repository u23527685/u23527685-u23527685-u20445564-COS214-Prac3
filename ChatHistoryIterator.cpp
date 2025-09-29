/**
 * @file [ChatHistoryIterator.cpp]
 * @brief [Implementation of the concrete ChatHistoryIterator class]
 * @author [Okaile Gaesale]
 * @date [2025-09-28]
 */
using namespace std;
#include "ChatHistoryIterator.h"

void ChatHistoryIterator::first(){ index = 0; }

void ChatHistoryIterator::next(){ if (index < history.size()) ++index; }

bool ChatHistoryIterator::isDone() const  { return index >= history.size(); }

string* ChatHistoryIterator::current()const {
    if (!isDone()) return history[index];
    return nullptr;
}

int ChatHistoryIterator::getIndex()const{
    return (int)index;
}