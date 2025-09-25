/**
 * @file [ChatRoom.cpp]
 * @brief [Implementation of the ChatRoom class]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#include "ChatRoom.h"
#include "Users.h"
#include <iostream>
#include <algorithm>

ChatRoom::ChatRoom() {
    // Initialize dynamic arrays with initial capacity
    maxUsers = 5;           // Initial capacity for users
    maxHistory = 50;        // Initial capacity for chat history
    userCount = 0;
    historyCount = 0;
    
    // Allocate initial arrays
    users = new Users*[maxUsers];
    chatHistory = new string[maxHistory];
    
    // Initialize arrays to nullptr/empty
    for (int i = 0; i < maxUsers; i++) {
        users[i] = nullptr;
    }
    
    cout << "ChatRoom base initialized (Capacity: " << maxUsers 
             << " users, " << maxHistory << " messages)" << endl;
}

ChatRoom::~ChatRoom() {
    cout << "ChatRoom destructor - cleaning up resources..." << endl;
    
    // Clean up users array
    if (users != nullptr) {
        cout << "Removing " << userCount << " users from room..." << endl;
        delete[] users;
        users = nullptr;
    }
    
    // Clean up chat history
    if (chatHistory != nullptr) {
        cout << "Clearing " << historyCount << " messages from history..." << endl;
        delete[] chatHistory;
        chatHistory = nullptr;
    }
    
    cout << "ChatRoom cleanup completed" << endl;
}

void ChatRoom::registerUser(Users* user) {
    if (user == nullptr) {
        cout << "Cannot register null user!" << endl;
        return;
    }
    
    // Check if user is already registered
    if (isUserInRoom(user)) {
        cout << "User " << user->getName() << " is already in " << getRoomName() << endl;
        return;
    }
    
    // Resize array if needed
    if (userCount >= maxUsers) {
        cout << "Room capacity reached, expanding user array..." << endl;
        resizeUsersArray();
    }
    
    // Add user to the room
    users[userCount] = user;
    userCount++;
    
    cout << "User " << user->getName() << " (" << user->getUserType() 
             << ") registered in " << getRoomName() << " (Total users: " << userCount << ")" << endl;
    
    // Add this room to user's room list
    user->addChatRoom(this);
    
    // Save join message to history
    string joinMessage = user->getName() + " (" + user->getUserType() + ") joined the room";
    saveMessage(joinMessage, user);
    
    // Welcome message
    broadcastSystemMessage("Welcome " + user->getName() + " to " + getRoomName() + "!");
}

void ChatRoom::sendMessage(string* message, Users* fromUser) {
    if (message == nullptr || fromUser == nullptr) {
        cout << "Cannot send message - invalid parameters!" << endl;
        return;
    }
    
    if (message->empty()) {
        cout << "Cannot send empty message from " << fromUser->getName() << endl;
        return;
    }
    
    if (!isUserInRoom(fromUser)) {
        cout << "User " << fromUser->getName() << " is not in " << getRoomName() 
                 << " - cannot send message!" << endl;
        return;
    }
    
    cout << "[" << getRoomName() << "] Broadcasting message from " 
             << fromUser->getName() << " to " << (userCount - 1) << " recipients" << endl;
    
    int deliveredCount = 0;
    
    // Send message to all users except the sender (Mediator pattern)
    for (int i = 0; i < userCount; i++) {
        if (users[i] != nullptr && users[i] != fromUser) {
            try {
                users[i]->receive(*message, fromUser, this);
                deliveredCount++;
            } catch (...) {
                cout << "Failed to deliver message to " << users[i]->getName() << endl;
            }
        }
    }
    
    cout << "Message delivered to " << deliveredCount << " users successfully" << endl;
}

void ChatRoom::saveMessage(const string& message, Users* fromUser) {
    if (fromUser == nullptr) {
        cout << "Cannot save message - sender is null!" << endl;
        return;
    }
    
    if (message.empty()) {
        cout << "Cannot save empty message from " << fromUser->getName() << endl;
        return;
    }
    
    // Resize history array if needed
    if (historyCount >= maxHistory) {
        cout << "History capacity reached, expanding history array..." << endl;
        resizeHistoryArray();
    }
    
    // Create formatted message for history
    string timestamp = getTimestamp();
    string formattedMessage = "[" + timestamp + "] [" + getRoomName() + "] " + 
                             fromUser->getName() + " (" + fromUser->getUserType() + "): " + message;
    
    // Save to history
    chatHistory[historyCount] = formattedMessage;
    historyCount++;
    
    cout << "Message saved to history (Total: " << historyCount << " messages)" << endl;
}

void ChatRoom::removeUser(Users* user) {
    if (user == nullptr) {
        cout << "Cannot remove null user!" << endl;
        return;
    }
    
    int userIndex = findUserIndex(user);
    if (userIndex == -1) {
        cout << "User " << user->getName() << " is not in " << getRoomName() << endl;
        return;
    }
    
    cout << "Removing user " << user->getName() << " from " << getRoomName() << "..." << endl;
    
    // Remove this room from user's room list
    user->removeChatRoom(this);
    
    // Shift array elements to fill the gap
    for (int i = userIndex; i < userCount - 1; i++) {
        users[i] = users[i + 1];
    }
    
    // Clear the last element and decrement count
    users[userCount - 1] = nullptr;
    userCount--;
    
    cout << "User " << user->getName() << " removed successfully (Remaining: " 
             << userCount << " users)" << endl;
    
    // Save leave message to history
    string leaveMessage = user->getName() + " (" + user->getUserType() + ") left the room";
    saveMessage(leaveMessage, user);
    
    // Notify remaining users
    if (userCount > 0) {
        broadcastSystemMessage(user->getName() + " has left " + getRoomName());
    }
}

int ChatRoom::getUserCount() const {
    return userCount;
}

int ChatRoom::getHistoryCount() const {
    return historyCount;
}

vector<Users*> ChatRoom::getUsers() const {
    vector<Users*> userList;
    for (int i = 0; i < userCount; i++) {
        if (users[i] != nullptr) {
            userList.push_back(users[i]);
        }
    }
    return userList;
}

vector<string> ChatRoom::getChatHistory() const {
    vector<string> history;
    for (int i = 0; i < historyCount; i++) {
        history.push_back(chatHistory[i]);
    }
    return history;
}

bool ChatRoom::isUserInRoom(Users* user) const {
    return findUserIndex(user) != -1;
}

string ChatRoom::getRoomStats() const {
    string stats = getRoomName() + " Statistics:\n";
    stats += "Users: " + to_string(userCount) + "/" + to_string(maxUsers) + "\n";
    stats += "Messages: " + to_string(historyCount) + "/" + to_string(maxHistory) + "\n";
    stats += "Current Users: ";
    
    for (int i = 0; i < userCount; i++) {
        if (users[i] != nullptr) {
            stats += users[i]->getName();
            if (i < userCount - 1) stats += ", ";
        }
    }
    
    return stats;
}

void ChatRoom::clearHistory() {
    cout << "Clearing chat history for " << getRoomName() << "..." << endl;
    
    // Clear all history entries
    for (int i = 0; i < historyCount; i++) {
        chatHistory[i] = "";
    }
    
    historyCount = 0;
    cout << "Chat history cleared successfully" << endl;
    
    // Notify users about history clearing
    broadcastSystemMessage("Chat history has been cleared by system administrator");
}

void ChatRoom::broadcastSystemMessage(const string& message) {
    if (message.empty() || userCount == 0) {
        return;
    }
    
    string systemMessage = "[SYSTEM] " + message;
    cout << "System broadcast in " << getRoomName() << ": " << message << endl;
    
    // Send to all users
    for (int i = 0; i < userCount; i++) {
        if (users[i] != nullptr) {
            // Create a temporary system user for the broadcast
            cout << "Notifying " << users[i]->getName() << ": " << systemMessage << endl;
        }
    }
    
    // Save system message to history
    string timestamp = getTimestamp();
    string formattedSystemMessage = "[" + timestamp + "] [" + getRoomName() + "] " + systemMessage;
    
    if (historyCount < maxHistory) {
        chatHistory[historyCount] = formattedSystemMessage;
        historyCount++;
    }
}

// Private helper methods

void ChatRoom::resizeUsersArray() {
    int newMaxUsers = maxUsers * 2;  // Double the capacity
    Users** newUsers = new Users*[newMaxUsers];
    
    // Copy existing users
    for (int i = 0; i < userCount; i++) {
        newUsers[i] = users[i];
    }
    
    // Initialize remaining slots
    for (int i = userCount; i < newMaxUsers; i++) {
        newUsers[i] = nullptr;
    }
    
    // Clean up old array and update
    delete[] users;
    users = newUsers;
    maxUsers = newMaxUsers;
    
    cout << "Users array resized to capacity: " << maxUsers << endl;
}

void ChatRoom::resizeHistoryArray() {
    int newMaxHistory = maxHistory * 2;  // Double the capacity
    string* newHistory = new string[newMaxHistory];
    
    // Copy existing history
    for (int i = 0; i < historyCount; i++) {
        newHistory[i] = chatHistory[i];
    }
    
    // Clean up old array and update
    delete[] chatHistory;
    chatHistory = newHistory;
    maxHistory = newMaxHistory;
    
    cout << "History array resized to capacity: " << maxHistory << endl;
}

int ChatRoom::findUserIndex(Users* user) const {
    if (user == nullptr) {
        return -1;
    }
    
    for (int i = 0; i < userCount; i++) {
        if (users[i] == user) {
            return i;
        }
    }
    
    return -1;  // User not found
}