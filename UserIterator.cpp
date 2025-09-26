using namespace std;
#include "UsersIterator.h"

void UsersIterator::first(){ index = 0; }

void UsersIterator::next(){ if (index < users.size()) ++index; }

bool UsersIterator::isDone() const  { return index >= users.size(); }

Users* UsersIterator::current()const {
    if (!isDone()) return users[index];
    return nullptr;
}

size_t UsersIterator::getIndex(){
    return index;
}