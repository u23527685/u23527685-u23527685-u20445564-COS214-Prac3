/**
 * @file [Dogorithm.cpp]
 * @brief [Implementation of Dogorithm chat room with dog-themed features]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#include "Dogorithm.h"
#include "Users.h"
#include <iostream>
#include <algorithm>

Dogorithm::Dogorithm() : ChatRoom() {
    cout << "\n" << string(60, '=') << endl;
    cout << "WELCOME TO DOGORITHM!" << endl;
    cout << "The most PAWsome programming community!" << endl;
    cout << "Where algorithms meet adorable canines!" << endl;
    cout << string(60, '=') << endl;
    cout << "Dogorithm room initialized successfully!" << endl;
    cout << "Room features: Dog puns, daily facts, and tail-wagging discussions!" << endl;
    cout << getRoomTheme() << endl;
    
    broadcastSystemMessage("Daily Fact: " + getDailyDogFact());
}

Dogorithm::~Dogorithm() {
    cout << "Dogorithm room is going to sleep..." << endl;
    cout << "Thanks for all the PAW-some conversations!" << endl;
    cout << "Until next time, keep your code as loyal as a golden retriever!" << endl;
}

void Dogorithm::registerUser(Users* user) {
    if (user == nullptr) {
        cout << "Cannot register a null user in Dogorithm!" << endl;
        return;
    }
    
    cout << "New pack member joining Dogorithm!" << endl;
    cout << "Preparing a RUFF-ly warm welcome for " << user->getName() << "!" << endl;
    
    ChatRoom::registerUser(user);
    
    welcomeUserWithDogPuns(user);
    
    if (user->getUserType() == "Admin") {
        broadcastSystemMessage("The pack leader " + user->getName() + " has arrived! All paws on deck!");
        broadcastSystemMessage("Admin " + user->getName() + " is now the TOP DOG in Dogorithm!");
    } else if (user->getUserType() == "Co-Admin") {
        broadcastSystemMessage("Second-in-command " + user->getName() + " has joined the pack!");
        broadcastSystemMessage("Co-Admin " + user->getName() + " is ready to help herd the discussions!");
    } else {
        broadcastSystemMessage(user->getName() + " has joined our pack of coding canines!");
        broadcastSystemMessage("Hope you're ready for some DOG-gone good programming discussions!");
    }
    
    cout << "Sharing daily dog fact with " << user->getName() << ": "<< getDailyDogFact() << endl;
}

void Dogorithm::sendMessage(string* message, Users* fromUser) {
    if (message == nullptr || fromUser == nullptr) {
        cout << "Dogorithm: Cannot send invalid message!" << endl;
        return;
    }
    
    if (message->empty()) {
        cout << fromUser->getName() << " tried to send an empty message. That's RUFF!" << endl;
        return;
    }
    cout << "[DOGORITHM] " << fromUser->getName() << " (" << fromUser->getUserType() 
             << ") is barking: \"" << *message << "\"" << endl;
    
    if (isDogThemed(*message)) {
        cout << "DOG-THEMED MESSAGE DETECTED! Extra enthusiasm incoming!" << endl;
        reactToDogMessage(*message, fromUser);
    }
    
    string lowerMessage = *message;
    transform(lowerMessage.begin(), lowerMessage.end(), lowerMessage.begin(), ::tolower);
    
    if (lowerMessage.find("algorithm") != string::npos || 
        lowerMessage.find("code") != string::npos ||
        lowerMessage.find("programming") != string::npos) {
        cout << "Programming discussion detected! Perfect for Dogorithm!" << endl;
        string encouragement = "Great topic, " + fromUser->getName() + "! Your programming skills are as sharp as a border collie's intelligence!";
        broadcastSystemMessage(encouragement);
    }
    if (lowerMessage.find("hello") != string::npos || lowerMessage.find("hi") != string::npos) {
        string greeting = fromUser->getName() + " says hello! The pack responds with excited tail wagging!";
        broadcastSystemMessage(greeting);
    }
    if (lowerMessage.find("help") != string::npos) {
        string helpMsg = fromUser->getName() + " needs help! Good thing we have loyal pack members ready to assist!";
        broadcastSystemMessage(helpMsg);
    }
    
    ChatRoom::sendMessage(message, fromUser);
}

void Dogorithm::removeUser(Users* user) {
    if (user == nullptr) {
        cout <<"Cannot remove null user from Dogorithm!" <<endl;
        return;
    }
    
    cout << "A pack member is leaving Dogorithm..." << endl;
    cout << user->getName() << " (" << user->getUserType() << ") is heading to the dog park" << endl;
    
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
    cout << user->getName() << " has left Dogorithm. The pack will miss them!" << endl;
}

string Dogorithm::getRoomName() const {
    return "Dogorithm";
}

string Dogorithm::getRoomTheme() const {
    return "Welcome to Dogorithm, where every algorithm is DOG-gone good!\n"
           "We discuss: Data Structures, Algorithms, and adorable canines!\n"
           "Our motto: 'Code with the loyalty of a Golden Retriever!'\n"
           "Remember: Good code is like a well-trained dog, reliable and obedient!";
}

string Dogorithm::getDailyDogFact() const {
    static const string dogFacts[] = {
        "A Greyhound algorithm would be perfect for racing through sorted data!",
        "Border Collies are so smart, they could probably debug your code!",
        "German Shepherds would make excellent security algorithms, always vigilant!",
        "Golden Retrievers would be perfect for data retrieval operations!",
        "Service dogs are like good APIs - helpful, reliable, and user-friendly!",
        "Dalmatians remind us that even with spots (bugs), code can still be beautiful!",
        "Huskies have such endurance, they'd never give up on infinite loops!",
        "Beagles' tracking skills would make them excellent search algorithms!",
        "Bulldogs teach us persistence, never give up on that difficult algorithm!",
        "Like a loyal dog, good code should always return to its owner!"
    };
    
    static int factIndex = 0;
    string fact = dogFacts[factIndex % 10];
    factIndex++;
    return fact;
}

void Dogorithm::welcomeUserWithDogPuns(Users* user) {
    if (user == nullptr) return;
    
    cout << "\nDOGORITHM WELCOME COMMITTEE ACTIVATED!" << endl;
    
    string welcomePuns[] = {
        user->getName() + ", you're PAW-sitively welcome here!",
        "We're RUFF-ly excited to have you join our pack!",
        "Hope you have a DOG-gone good time with us!",
        "You're going to have a BALL learning algorithms here!",
        "We promise our discussions will be im-PAWS-ibly good!"
    };
    
    static int punIndex = 0;
    string welcomeMsg = welcomePuns[punIndex % 5];
    punIndex++;
    
    cout << welcomeMsg << endl;
    broadcastSystemMessage(welcomeMsg);
    
    string personalWelcome = user->getName() + ", grab a virtual tennis ball and join our coding conversations!";
    broadcastSystemMessage(personalWelcome);
}

bool Dogorithm::isDogThemed(const string& message) const {
    string lowerMessage = message;
    transform(lowerMessage.begin(), lowerMessage.end(), lowerMessage.begin(), ::tolower);
    
    string dogWords[] = {"dog", "puppy", "woof", "bark", "tail", "paw", "bone", "fetch", 
                        "treat", "collar", "leash", "park", "walk", "good boy", "good girl",
                        "canine", "hound", "retriever", "shepherd", "husky", "beagle"};
    
    for (const string& word : dogWords) {
        if (lowerMessage.find(word) != string::npos) {
            return true;
        }
    }
    
    return false;
}

void Dogorithm::reactToDogMessage(const string& message, Users* fromUser) {
    if (fromUser == nullptr) return;
    
    cout << "MAXIMUM DOG EXCITEMENT ACTIVATED!" << endl;
    
    string reactions[] = {
        "WOOF WOOF! " + fromUser->getName() + " knows their dog facts!",
        "Great dog reference, " + fromUser->getName() + "!",
        "The pack approves of " + fromUser->getName() + "'s canine wisdom!",
        "More dog talk, please!",
        fromUser->getName() + " gets extra treats for the dog mention!"
    };
    
    static int reactionIndex = 0;
    string reaction = reactions[reactionIndex % 5];
    reactionIndex++;
    
    broadcastSystemMessage(reaction);
    
    string recognition = fromUser->getName() + " earned the 'Good Human' badge for dog appreciation!";
    cout << recognition << endl;
}