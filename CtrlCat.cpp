
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
    if (!user) return;

    // Check if the user is already registered
    bool exists = false;
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i] == user) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        users.push_back(user);
        cout << user->getName() << " (" << user->getUserType() << ") has joined CtrlCat!" << endl;
    }

    user->addChatRoom(this);
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

/**
 * @brief [React to cat-themed messages with enthusiasm and special responses]
 * @param message [The message to react to]
 * @param fromUser [Pointer to the user who sent the message]
 */
void CtrlCat::reactToCatMessage(const string& message, Users* fromUser) {
    if (fromUser == nullptr) return;
    
    cout << "MAXIMUM CAT EXCITEMENT ACTIVATED!" << endl;
    
    // Convert to lowercase manually for checking
    string lowerMessage = message;
    for (size_t i = 0; i < lowerMessage.length(); i++) {
        if (lowerMessage[i] >= 'A' && lowerMessage[i] <= 'Z') {
            lowerMessage[i] = lowerMessage[i] + ('a' - 'A');
        }
    }
    
    string reaction;
    
    if (lowerMessage.find("cat") != string::npos || 
        lowerMessage.find("kitten") != string::npos || 
        lowerMessage.find("meow") != string::npos) {
        reaction = fromUser->getName() + " loves cats! Everyone purr in celebration!";
    } 
    else if (lowerMessage.find("dog") != string::npos || 
             lowerMessage.find("puppy") != string::npos) {
        reaction = "Wait... " + fromUser->getName() + " mentioned a dog! Cats are giving the side-eye!";
    } 
    else if (lowerMessage.find("purr") != string::npos || 
             lowerMessage.find("whisker") != string::npos) {
        reaction = fromUser->getName() + " is speaking our feline language! *purrs approvingly*";
    }
    else {
        reaction = fromUser->getName() + " says: \"" + message + "\". How PAW-some!";
    }
    
    broadcastSystemMessage(reaction);
    
    string recognition = fromUser->getName() + " earned the 'Certified Cat Whisperer' badge for messaging!";
    cout << recognition << endl;
}
string CtrlCat::getRoomTheme() const {
    return "Welcome to CtrlCat";
}

bool CtrlCat::isCatThemed(const std::string& message){
    // make a lowercase copy without <algorithm>
    std::string lowerMessage = message;
    for (size_t i = 0; i < lowerMessage.size(); ++i) {
        char c = lowerMessage[i];
        if (c >= 'A' && c <= 'Z') {
            lowerMessage[i] = c - 'A' + 'a';
        }
    }

    std::string catWords[] = {
        "cat", "kitten", "kitty", "meow", "purr", "claw", "whisker", "tail", 
        "fur", "feline", "tabby", "siamese", "persian", "maine coon", "sphinx",
        "lynx", "cougar", "tiger", "lion", "panther"
    };

    for (size_t i = 0; i < sizeof(catWords)/sizeof(catWords[0]); ++i) {
        if (lowerMessage.find(catWords[i]) != std::string::npos) {
            return true;
        }
    }


    return false;
}