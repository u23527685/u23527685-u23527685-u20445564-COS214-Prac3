/**
 * @file [CtrlCat.cpp]
 * @brief [Implementation of CtrlCat chat room]
 * @author [Marodi Jessica, Okaile Gaesale]
 * @date [2025-09-24]
 */

#include "CtrlCat.h"
#include "Users.h"
#include <iostream>

CtrlCat::CtrlCat() {
    cout << "CtrlCat room created! Welcome to the feline programming paradise!" << endl;
}

CtrlCat::~CtrlCat() {
    cout<<"CTRLCAT destructing"<<endl;
}

void CtrlCat::registerUser(Users* user) {
   ChatRoom::registerUser(user);
    cout << user->getName() << " (" << user->getUserType()<< ") has joined CtrlCat!" << endl;
}

void CtrlCat::sendMessage(string* message, Users* fromUser) {
    if (message != nullptr && fromUser != nullptr) {
        cout << "[CtrlCat] " << fromUser->getName() 
                 << " says: " << *message << endl;
        
        ChatRoom::sendMessage(message, fromUser);
    }
}

void CtrlCat::removeUser(Users* user) {
    if (user == nullptr) {
        cout <<"Cannot remove null user from CtrlCat!" <<endl;
        return;
    }
    
    cout << "A pack member is leaving CtrlCat..." << endl;
    cout << user->getName() << " (" << user->getUserType() << ") is heading to the CtrlCat park" << endl;
    
    if (user->getUserType() == "Admin") {
        broadcastSystemMessage("The pack leader " + user->getName() + " is leaving! Thanks for keeping us in line!");
        broadcastSystemMessage("Your leadership was as reliable as a German Shepherd's loyalty!");
    }
    else if (user->getUserType() == "Co-Admin") {
        broadcastSystemMessage("Co-Admin " + user->getName() + " is leaving the pack! Thanks for herding our discussions!");
        broadcastSystemMessage("Your assistance was as helpful as a service dog!");
    } 
    else {
        broadcastSystemMessage(user->getName() + " is leaving our coding pack!");
        broadcastSystemMessage("Thanks for all the PAW-some contributions!");
    }
    
    ChatRoom::removeUser(user);
    
    broadcastSystemMessage("Farewell " + user->getName() + "! Come back soon, we'll be waiting with treats!");
    cout << user->getName() << " has left CtrlCat. The pack will miss them!" << endl;
}

string CtrlCat::getRoomName() const {
    return "CtrlCat";
}