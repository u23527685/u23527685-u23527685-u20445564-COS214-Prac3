using namespace std;
#include "CommandIterator.h"

void CommandIterator::first(){ index = 0; }

void CommandIterator::next(){ if (index < commands.size()) ++index; }

bool CommandIterator::isDone() const  { return index >= commands.size(); }

Command* CommandIterator::current()const {
    if (!isDone()) return commands[index];
    return nullptr;
}

size_t CommandIterator::getIndex()const{
    return index;
}