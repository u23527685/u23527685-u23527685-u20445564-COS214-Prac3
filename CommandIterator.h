#ifndef COMMANDITERATOR_H
#define COMMANDITERATOR_H

#include "Iterator.h"
#include "Command.h"
#include <vector>

class CommandIterator : public Iterator<Command*> {
private:
    const vector<Command*>& commands;
    size_t index;

public:
    CommandIterator(const vector<Command*>& commandlist) 
        : commands(commandlist), index(0) {}

    void first() override;

    void next() override;

    bool isDone() const override;

    Command* current() const override ;
    
    size_t getIndex()const override;
};

#endif // COMMANDITERATOR_H
 