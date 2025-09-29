
/**
 * @file [ChatRoom.cpp]
 * @brief [Implementation of the ChatRoom class]
 * @author [Marodi Jessica,Okaile Gaesale]
 * @date [2025-09-24]
 */

#include "ChatRoom.h"
#include "Users.h"
#include <iostream>
#include <algorithm>
#include "ChatHistoryIterator.h"
#include "UserIterator.h"

ChatRoom::ChatRoom() {
    cout << "ChatRoom base initialized"<< endl;
}

ChatRoom::~ChatRoom() {
    cout << "ChatRoom destructor - cleaning up resources..." << endl;
    
    // Clean up users array
    users.clear();
    
    // Clean up chat history
    for (string* msg : chatHistory) {
        delete msg;  // Free the allocated string
    }
    chatHistory.clear();
    
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
    
    cout << "User " << user->getName() << " (" << user->getUserType() 
             << ") registered in " << getRoomName()<< endl;
    
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
    
    int deliveredCount = 0;
    
    auto userIt = createUserIterator();
    for (userIt.first(); !userIt.isDone(); userIt.next()) {
        Users* u = userIt.current();
        if (u && u!=fromUser) {
            try{
                u->receive(*message, fromUser, this);
                deliveredCount++;
            }catch (...) {
                cout << "Failed to deliver message to " << u->getName() << endl;
            }
            
        }
    }
    if(deliveredCount>0){
        notifyObservers(fromUser);
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

    // Create formatted message for history
    string* formattedMessage = new string(fromUser->getName() +  " (" + fromUser->getUserType() + "): " + message);
    chatHistory.push_back(formattedMessage);

    cout << "Message saved to history " << endl;
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

    auto userIt = createUserIterator();

    for (userIt.first(); !userIt.isDone(); userIt.next()) {
        Users* u = userIt.current();
        if (u && u==user) {
            size_t deli=userIt.getIndex();
            users.erase(users.begin()+deli);
        }
    }
    
    cout << "User " << user->getName() << " removed successfully"<<endl;
    
    // Save leave message to history
    string leaveMessage = user->getName() + " (" + user->getUserType() + ") left the room";
    saveMessage(leaveMessage, user);
    
    // Notify remaining users
    if (users.size() > 0) {
        broadcastSystemMessage(user->getName() + " has left " + getRoomName());
    }
}


vector<Users*> ChatRoom::getUsers() const {
    return users;
}

vector<string*> ChatRoom::getChatHistory() const {
    return chatHistory;
}

bool ChatRoom::isUserInRoom(Users* user) const {
    return findUserIndex(user) != -1;
}

void ChatRoom::notifyObservers(const Users* fromUser) {
    for (Users* user : users) {
        if (user != nullptr && user!=fromUser) {
            user->update(fromUser);
        }
    }
}
string ChatRoom::getRoomStats() const {
    string stats = getRoomName() + " Statistics:\n";
    stats += "Users: " + to_string(users.size()) + "\n";
    stats += "Messages: " + to_string(chatHistory.size())  + "\n";
    stats += "Current Users: ";

    auto userIt= createUserIterator();
    for (userIt.first(); !userIt.isDone(); userIt.next()) {
        Users* u = userIt.current();
        if (u) {
            stats += u->getName();
            if (!userIt.isDone()) stats += ", ";
            
        }
    }
    
    return stats;
}

ChatHistoryIterator ChatRoom::createChatHistoryIterator() const {
    return ChatHistoryIterator(chatHistory);
}

 UsersIterator ChatRoom::createUserIterator() const {
    return UsersIterator(users);
}

void ChatRoom::clearHistory() {
    cout << "Clearing chat history for " << getRoomName() << "..." << endl;
    
    // Clear all history entries
    for (string* msg : chatHistory) {
        delete msg;  // Free the allocated string
    }
    chatHistory.clear();

    cout << "Chat history cleared successfully" << endl;
    
    // Notify users about history clearing
    broadcastSystemMessage("Chat history has been cleared by system administrator");
}

void ChatRoom::broadcastSystemMessage(const string& message) {
    if (message.empty() || users.size() == 0) {
        return;
    }
    
    string systemMessage = "[SYSTEM] " + message;
    cout << "System broadcast in " << getRoomName() << ": " << message << endl;
    
    // Send to all users

    auto userIt = createUserIterator();

    for (userIt.first(); !userIt.isDone(); userIt.next()) {
        Users* u = userIt.current();
        if (u) {
            cout << "Notifying " << u->getName() << ": " << systemMessage << endl;
            
        }
    }
    
    // Save system message to history
    string* formattedSystemMessage = new string("[" + getRoomName() + "] " + systemMessage);
    chatHistory.push_back(formattedSystemMessage);
}

string ChatRoom::getRoomNameFunc(){
    return getRoomName();
}

// Private helper methods

int ChatRoom::findUserIndex(Users* user) const {

    auto userIt= createUserIterator();
    for (userIt.first(); !userIt.isDone(); userIt.next()) {
        Users* u = userIt.current();
        if (u&&u==user) {
            return (int) userIt.getIndex();
        }
    }
    return -1;

}