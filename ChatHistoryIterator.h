#ifndef CHATHISTORYITERATOR_H
#define CHATHISTORYITERATOR_H

#include "Iterator.h"
#include <string>
#include <vector>

using namespace std;

class ChatHistoryIterator : public Iterator<string*> {
private:
    const vector<string*>& history;
    size_t index;

public:
    ChatHistoryIterator(const vector<string*>& historyList) 
        : history(historyList), index(0) {}

    void first() override;

    void next() override;

    bool isDone() const override;

    string* current() const override ;
    size_t getIndex() const override;
};

#endif // CHATHISTORYITERATOR_H
