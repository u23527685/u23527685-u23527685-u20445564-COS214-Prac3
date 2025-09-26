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

    void first() override { index = 0; }

    void next() override { if (index < history.size()) ++index; }

    bool isDone() const override { return index >= history.size(); }

    string* current() const override {
        if (!isDone()) return history[index];
        return nullptr;
    }
};

#endif // CHATHISTORYITERATOR_H
