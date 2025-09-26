#ifndef USERITERATOR_H
#define USERITERATOR_H

#include "Iterator.h"
#include "Users.h"
#include <vector>

class UsersIterator : public Iterator<Users*> {
private:
    const vector<Users*>& users;
    size_t index;

public:
    UsersIterator(const vector<Users*>& usersList) 
        : users(usersList), index(0) {}

    void first() override;

    void next() override;

    bool isDone() const override;

    Users* current() const override ;
    
    size_t getIndex()const override;
};

#endif // USERITERATOR_H
 