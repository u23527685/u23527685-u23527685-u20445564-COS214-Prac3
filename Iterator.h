/**
 * @file [Iterator.h]
 * @brief [Abstract class header implementation for Iterator]
 * @author [Okaile Gaesale]
 * @date [2025-09-28]
 */
#ifndef ITERATOR_H
#define ITERATOR_H

using namespace std;

/**
 * @class Iterator
 * @brief Abstract class representing the iterator
 * 
 * Iterates through the chat history of the Chatroom
 */

template<typename T>
class Iterator{
    public:
        /**
         * @brief default deconstructor
        */
        virtual ~Iterator() {}

        /**
         * @brief sets Iterator to the beginning 
         */
        virtual void first() = 0; 

        /**
         * @brief sets the  Iterator to the next Item
         */
        virtual void next() = 0; 

         /**
         * @brief checks if Iterator is at the end
         */
        virtual bool isDone() const = 0; 

        /**
         * @brief returns the chat that the iterator is on
        */
        virtual T current() const = 0;

        /**
         * @brief returns the current index
         */
        virtual  int getIndex()const =0;
};

#endif