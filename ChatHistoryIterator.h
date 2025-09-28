/**
 * @file [ChatHistoryIterator.h]
 * @brief [Concrete class header implementation for Chat History Iterator]
 * @author [Okaile Gaesale]
 * @date [2025-09-28]
 */
#ifndef CHATHISTORYITERATOR_H
#define CHATHISTORYITERATOR_H

#include "Iterator.h"
#include <string>
#include <vector>

using namespace std;

/**
 * @class ChatHistoryIterator
 * @brief Conceret class representing the chat history iterator
 * 
 * Iterates through the chat history of the Chatroom
 */

class ChatHistoryIterator : public Iterator<string*> {
    private:
        const vector<string*>& history;
        size_t index;

    public:
        /**
         * @brief Constructor with history list 
         */
        ChatHistoryIterator(const vector<string*>& historyList) 
            : history(historyList), index(0) {}

        /**
         * @brief sets Iterator to the beginning 
         */
        void first() override;

        /**
         * @brief sets the  Iterator to the next chat
         */
        void next() override;

        /**
         * @brief checks if Iterator is at the end
         */
        bool isDone() const override;

        /**
         * @brief returns the chat that the iterator is on
        */
        string* current() const override ;

        /**
         * @brief returns the current index
         */
        size_t getIndex() const override;
};

#endif // CHATHISTORYITERATOR_H
