#ifndef ITERATOR_H
#define ITERATOR_H

using namespace std;

template<typename T>
class Iterator{
    public:
        virtual ~Iterator() {}
        virtual void first() = 0;         ///< Move to first element
        virtual void next() = 0;          ///< Move to next element
        virtual bool isDone() const = 0;  ///< Check if iteration is complete
        virtual T current() const = 0;
        virtual  size_t getIndex()const =0;
};

#endif