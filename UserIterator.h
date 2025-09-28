/**
 * @file [UsersIterator.h]
 * @brief [Concrete class header implementation for Users Iterator]
 * @author [Okaile Gaesale]
 * @date [2025-09-28]
 */
#ifndef USERITERATOR_H
#define USERITERATOR_H

class Users;

#include "Users.h"
#include "Iterator.h"
#include <vector>



/**
 * @class UsersIterator
 * @brief Conceret class representing the users iterator
 * 
 * Iterates through the users of the Chatroom
 */

class UsersIterator : public Iterator<Users*> {
private:
    const vector<Users*>& users;
    size_t index;

public:
    /**
     * @brief Constructor with users list 
     */
    UsersIterator(const vector<Users*>& usersList) 
        : users(usersList), index(0) {}

    /**
     * @brief sets Iterator to the beginning 
     */
    void first() override;

    /**
     * @brief sets the  Iterator to the next user
     */
    void next() override;

    /**
     * @brief checks if Iterator is at the end
     */
    bool isDone() const override;

    /**
     * @brief returns the user that the iterator is on
    */
    Users* current() const override ;
    
    /**
     * @brief returns the current index
     */
    int getIndex()const override;
};

#endif // USERITERATOR_H
 