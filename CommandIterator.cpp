/**
 * @file [CommandIterator.cpp]
 * @brief [Implementation of the concrete ChatHistoryIterator class]
 * @author [Okaile Gaesale]
 * @date [2025-09-28]
 */
using namespace std;
#include "CommandIterator.h"
#include "Command.h"

void CommandIterator::first(){ index = 0; }

void CommandIterator::next(){ if (index < commands.size()) ++index; }

bool CommandIterator::isDone() const  { return index >= commands.size(); }

Command* CommandIterator::current()const {
    if (!isDone()) return commands[index];
    return nullptr;
}

int CommandIterator::getIndex()const{
    return (int)index;
}