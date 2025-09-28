/**
 * @file [UsersIterator.cpp]
 * @brief [Implementation of the concrete ChatHistoryIterator class]
 * @author [Okaile Gaesale]
 * @date [2025-09-28]
 */
using namespace std;
#include "UserIterator.h"

void UsersIterator::first(){ index = 0; }

void UsersIterator::next(){ if (index < users.size()) ++index; }

bool UsersIterator::isDone() const  { return index >= users.size(); }

Users* UsersIterator::current()const {
    if (!isDone()) return users[index];
    return nullptr;
}

size_t UsersIterator::getIndex()const{
    return index;
}