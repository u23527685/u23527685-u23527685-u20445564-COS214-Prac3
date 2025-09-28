/**
 * @file [CommandIterator.h]
 * @brief [Concrete class header implementation for Command Iterator]
 * @author [Okaile Gaesale]
 * @date [2025-09-28]
 */
#ifndef COMMANDITERATOR_H
#define COMMANDITERATOR_H

#include <cstddef>
#include "Iterator.h"
#include <vector>

class Command;

/**
 * @class CommandIterator
 * @brief Conceret class representing the Command iterator
 * 
 * Iterates through the chat history of the Chatroom
 */

class CommandIterator : public Iterator<Command*> {
private:
    const vector<Command*>& commands;
    size_t index;

public:
    /**
     * @brief Constructor with command list 
     */
    CommandIterator(const vector<Command*>& commandlist) 
        : commands(commandlist), index(0) {}

    /**
     * @brief sets Iterator to the beginning 
     */
    void first() override;

    /**
     * @brief sets the  Iterator to the next command
     */
    void next() override;

    /**
     * @brief checks if Iterator is at the end
     */
    bool isDone() const override;

    /**
     * @brief returns the command that the iterator is on
    */
    Command* current() const override ;
    
    /**
     * @brief returns the current index
     */
    size_t getIndex()const override;
};

#endif // COMMANDITERATOR_H
 