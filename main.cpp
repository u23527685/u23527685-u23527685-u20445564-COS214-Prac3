// /**
//  * @file [main.cpp]
//  * @brief [Comprehensive testing program for chat system design patterns]
//  * @author [Testing main for Dogorithm, and CtrlCat]
//  * @date [2025-09-24]
//  */

// #include <iostream>
// #include <string>
// #include <vector>
// #include <map>
// #include <list>

// #include "AdminUser.h"
// #include "NormalUser.h"
// #include "CoAdminUser.h"

// // #include "ChatHistoryIterator.h"
//  #include "ChatRoom.h"
// // #include "ChatRoomIterator.h"

// #include "Command.h"
// #include "Observer.h"
// // #include "CommandIterator.h"

// #include "Dogorithm.h"
// #include "CtrlCat.h"
// // #include "Iterator.h"
// #include "Users.h"

// using namespace std;

// int main()
// {
//   srand(time(nullptr));
    
//     cout << "=== CtrlCat Chat Room Testing ===" << endl << endl;
    
//     // Create chat room
//     CtrlCat CatLoversRoom;
    
//     // Create users
//     AdminUser *catAdmin = new AdminUser("Annie");
//     CoAdminUser *coCatAdmin = new CoAdminUser("Bobbie");
//     NormalUser *NormalCatUser1 = new NormalUser("Daisy");

//     cout << "\n--- User Registration ---" << endl;
//     CatLoversRoom.registerUser(catAdmin);
//     CatLoversRoom.registerUser(coCatAdmin);
//     CatLoversRoom.registerUser(NormalCatUser1);

//     // Add chat room to users (assuming Users class has addChatRoom method)
//     catAdmin->addChatRoom(&CatLoversRoom);
//     coCatAdmin->addChatRoom(&CatLoversRoom);
//     NormalCatUser1->addChatRoom(&CatLoversRoom);
    
//     // Display room theme
//     cout << "\n--- Room Information ---" << endl;
//     cout << "Room Theme: " << CatLoversRoom.getRoomTheme() << endl;
    
//     // Add observers
//     cout << "\n--- Adding Observers ---" << endl;
//     CatLoversRoom.addObserver(catAdmin);
//     CatLoversRoom.addObserver(coCatAdmin);
//     CatLoversRoom.addObserver(NormalCatUser1);
    
//     // Get daily cat fact
//     cout << "\n--- Daily Cat Fact ---" << endl;
//     cout << "Daily Cat Fact: " << CatLoversRoom.getDailyCatFact() << endl;
    
//     // Welcome message (this is already called in registerUser, but calling again for demo)
//     cout << "\n--- Welcome Message Demo ---" << endl;
//     CatLoversRoom.welcomeUserWithCatPuns(NormalCatUser1);
    
//     // Display registered users
//     cout << "\n--- Registered Users ---" << endl;
//     cout << "Registered Users in " << CatLoversRoom.getRoomName() << ":" << endl;
//     vector<Users*> users = CatLoversRoom.getUsers();
//     for (size_t i = 0; i < users.size(); i++) {
//         cout << "- " << users[i]->getName() << endl;
//     }
    
//     // Display room stats
//     cout << "\n--- Room Stats ---" << endl;
//     cout << "Getting room stats ready for you..." << endl;
//     cout << CatLoversRoom.getRoomStats() << endl;

//     cout << "\n--- Message Exchange ---" << endl;
//     // Send messages
//     catAdmin->send("Hello cat lovers!", &CatLoversRoom);
//     coCatAdmin->send("Hi everyone!", &CatLoversRoom);
    
//     string msg = "I love cats!";
//     NormalCatUser1->send(msg, &CatLoversRoom);
    
//     // React to cat message (this should already be called automatically in sendMessage)
//     cout << "\n--- Cat Message Reaction Demo ---" << endl;
//     CatLoversRoom.reactToCatMessage(msg, NormalCatUser1);
    
//     // Admin announcement
//     cout << "\n--- Admin Announcement ---" << endl;
//     catAdmin->makeAnnouncement("Daily cat fact: Cats sleep 16 hours a day!", &CatLoversRoom);

//     // Display chat history
//     cout << "\n--- Chat History ---" << endl;
//     vector<string*> history = CatLoversRoom.getChatHistory();
//     cout << "Chat History (" << history.size() << " messages):" << endl;
//     for (size_t i = 0; i < history.size(); i++) {
//         cout << "  " << *(history[i]) << endl;
//     }

//     cout << "\n--- User Removal ---" << endl;
//     // Remove user
//     catAdmin->removeUser(NormalCatUser1, &CatLoversRoom);
    
//     // Remove observers
//     CatLoversRoom.removeObserver(NormalCatUser1);
//     CatLoversRoom.removeObserver(coCatAdmin);
//     CatLoversRoom.removeObserver(catAdmin);

//     // Final room stats
//     cout << "\n--- Final Room Stats ---" << endl;
//     cout << CatLoversRoom.getRoomStats() << endl;

//     cout << "\n--- Cleanup ---" << endl;
//     // Clean up memory (remove duplicate delete)
//     delete catAdmin;
//     delete coCatAdmin;
//     delete NormalCatUser1;
  
//     cout << "\n Testing Complete for CtrlCat" << endl;
//     cout <<"Testing Dogorithm"<<endl;
   
//     Dogorithm DogLoversRoom;
    
//     // Create users with dog-themed names
//     AdminUser *dogAdmin = new AdminUser("AlphaDog");
//     CoAdminUser *coDogAdmin = new CoAdminUser("BetaBark");
//     NormalUser *normalDogUser1 = new NormalUser("PuppyLover");
//     NormalUser *normalDogUser2 = new NormalUser("CodeCollie");

//     cout << "\n--- User Registration ---" << endl;
//     // Register users (this will automatically call welcomeUserWithDogPuns)
//     DogLoversRoom.registerUser(dogAdmin);
//     DogLoversRoom.registerUser(coDogAdmin);
//     DogLoversRoom.registerUser(normalDogUser1);
//     DogLoversRoom.registerUser(normalDogUser2);

//     cout << "\n--- Room Information ---" << endl;
//     cout << "Room Name: " << DogLoversRoom.getRoomName() << endl;
//     cout << "Room Theme: " << DogLoversRoom.getRoomTheme() << endl;
    
//     cout << "\n--- Daily Dog Fact Demo ---" << endl;
//     for (int i = 0; i < 3; i++) {
//         cout << "Fact #" << (i+1) << ": " << DogLoversRoom.getDailyDogFact() << endl;
//     }
    
//     cout << "\n--- Adding Observers ---" << endl;
//     // Add observers to watch room activity
//     DogLoversRoom.addObserver(dogAdmin);
//     DogLoversRoom.addObserver(coDogAdmin);
//     DogLoversRoom.addObserver(normalDogUser1);
//     DogLoversRoom.addObserver(normalDogUser2);
    
//     cout << "\n--- Room Statistics ---" << endl;
//     cout << "Users in room: " << DogLoversRoom.getUserCount() << endl;
//     cout << DogLoversRoom.getRoomStats() << endl;
    
//     cout << "\n--- Regular Message Exchange ---" << endl;
//     // Send regular programming messages
//     dogAdmin->send("Welcome everyone to our algorithmic discussion!", &DogLoversRoom);
//     coDogAdmin->send("Let's talk about sorting algorithms today", &DogLoversRoom);
//     normalDogUser1->send("I love learning about data structures", &DogLoversRoom);
    
//     cout << "\n--- Dog-Themed Messages (Will Trigger Reactions) ---" << endl;
//     // Send dog-themed messages to trigger special reactions
//     string dogMessage1 = "This algorithm is pawsome!";
//     normalDogUser2->send(dogMessage1, &DogLoversRoom);
    
//     string dogMessage2 = "My code runs like a happy puppy!";
//     normalDogUser1->send(dogMessage2, &DogLoversRoom);
    
//     string dogMessage3 = "Woof! This sorting algorithm is fetch-ing data perfectly!";
//     coDogAdmin->send(dogMessage3, &DogLoversRoom);
    
//     string dogMessage4 = "Good boy algorithm - it never fails to fetch the right result!";
//     dogAdmin->send(dogMessage4, &DogLoversRoom);
    
//     cout << "\n--- Manual Dog Message Reaction Demo ---" << endl;
//     // Demonstrate manual reaction to dog messages
//     string testMessage = "This dog-themed chat is tail-waggingly good!";
//     DogLoversRoom.reactToDogMessage(testMessage, normalDogUser1);
    
//     cout << "\n--- Admin Functionality ---" << endl;
//     // Test admin-specific functionality
//     dogAdmin->makeAnnouncement("Pack meeting in 5 minutes - we'll discuss binary trees!", &DogLoversRoom);
    
//     cout << "\n--- System Messages ---" << endl;
//     // Test system message broadcasting
//     DogLoversRoom.broadcastSystemMessage("Server maintenance in 30 minutes - save your work!");
//     DogLoversRoom.broadcastSystemMessage("New feature: Puppy Points for helpful code reviews!");
    
//     cout << "\n--- Chat History Display ---" << endl;
//     vector<string*> history = DogLoversRoom.getChatHistory();
//     cout << "Chat History (" << history.size() << " messages):" << endl;
//     for (size_t i = 0; i < history.size(); i++) {
//         cout << "  [" << (i+1) << "] " << *(history[i]) << endl;
//     }
    
//     cout << "\n--- User List ---" << endl;
//     vector<Users*> users = DogLoversRoom.getUsers();
//     cout << "Current pack members (" << users.size() << "):" << endl;
//     for (size_t i = 0; i < users.size(); i++) {
//         cout << "  - " << users[i]->getName() << " (" << users[i]->getUserType() << ")" << endl;
//     }
    
//     cout << "\n--- Testing Dog-Themed Detection ---" << endl;
//     // Test various dog-themed messages
//     vector<string> testMessages = {
//         "I love dogs and coding!",
//         "This puppy is so cute",
//         "Woof woof, great algorithm!",
//         "My dog helps me debug code",
//         "Fetch me that data structure",
//         "Good boy for solving that bug!",
//         "This is just regular programming talk",
//         "Binary trees are interesting",
//         "The dog's tail wagging algorithm works perfectly"
//     };
    
//     cout << "Testing dog-theme detection:" << endl;
//     for (const string& msg : testMessages) {
//         bool isThemed = DogLoversRoom.isDogThemed(msg);
//         cout << "  \"" << msg << "\" -> " << (isThemed ? "DOG-THEMED ✓" : "Regular message") << endl;
//     }
    
//     cout << "\n--- User Removal Test ---" << endl;
//     // Test removing a user
//     cout << "Before removal - Users: " << DogLoversRoom.getUserCount() << endl;
    
//     dogAdmin->removeUser(normalDogUser2, &DogLoversRoom);
//     DogLoversRoom.removeObserver(normalDogUser2);
    
//     cout << "After removal - Users: " << DogLoversRoom.getUserCount() << endl;
    
//     cout << "\n--- Final Room Stats ---" << endl;
//     cout << DogLoversRoom.getRoomStats() << endl;
    
//     cout << "\n--- Additional Welcome Demo ---" << endl;
//     // Test welcome functionality manually
//     NormalUser *lateJoiner = new NormalUser("LatePup");
//     DogLoversRoom.registerUser(lateJoiner);
//     DogLoversRoom.addObserver(lateJoiner);
    
//     cout << "\n--- Final Message Exchange ---" << endl;
//     lateJoiner->send("Thanks for the warm welcome to this pawsome room!", &DogLoversRoom);
//     dogAdmin->send("Welcome to the pack, LatePup! Hope you enjoy our algorithmic adventures!", &DogLoversRoom);
    
//     cout << "\n--- Observer Removal ---" << endl;
//     DogLoversRoom.removeObserver(dogAdmin);
//     DogLoversRoom.removeObserver(coDogAdmin);
//     DogLoversRoom.removeObserver(normalDogUser1);
//     DogLoversRoom.removeObserver(lateJoiner);
    
//     cout << "\n--- Memory Cleanup ---" << endl;
//     // Clean up allocated memory
//     delete dogAdmin;
//     delete coDogAdmin;
//     delete normalDogUser1;
//     delete normalDogUser2;
//     delete lateJoiner;
    
//     cout << "\n=== Dogorithm Testing Complete - Thanks for being pawsome! ===" << endl;
    
//     return 0;
// }