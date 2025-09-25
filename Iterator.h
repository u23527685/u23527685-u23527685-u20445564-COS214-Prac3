#ifndef ITERATOR_H
#define ITERATOR_H

using namespace std;

template<typename T>
class Iterator{
    public:
        virtual T first()=0;
        virtual T next()=0;
        virtual T current();
        bool isDone(){return next != NULL};
};

#endif