/**
 * @file [main.cpp]
 * @brief [Comprehensive testing program for chat system design patterns]
 * @author [Testing main for Dogorithm, and CtrlCat]
 * @date [2025-09-24]
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

#include "AdminUser.h"
#include "NormalUser.h"
#include "CoAdminUser.h"

#include "ChatHistoryIterator.h"
#include "ChatRoom.h"
#include "ChatRoomIterator.h"

#include "Command.h"
#include "Observer.h"
#include "CommandIterator.h"

#include "Dogorithm.h"
#include "CtrlCat.h"
#include "Iterator.h"
#include "Users.h"

using namespace std;

int main()
{
  srand(time(nullptr));
    
    cout << "CtrlCat Chat Room Testing" << endl << endl;
    
    // Create chat room
    CtrlCat CatLoversRoom;
    
    // Create users
    AdminUser *catAdmin = new AdminUser("Annie");
    CoAdminUser *coCatAdmin = new CoAdminUser("Bobbie");
    NormalUser *NormalCatUser1 = new NormalUser("Daisy");

    cout << "\n--- User Registration ---" << endl;
    CatLoversRoom.registerUser(catAdmin);
    CatLoversRoom.registerUser(coCatAdmin);
    CatLoversRoom.registerUser(NormalCatUser1);

    // Add chat room to users (assuming Users class has addChatRoom method)
    catAdmin->addChatRoom(&CatLoversRoom);
    coCatAdmin->addChatRoom(&CatLoversRoom);
    NormalCatUser1->addChatRoom(&CatLoversRoom);
    
    // Add observers
    cout << "\n--- Adding Observers ---" << endl;
    CatLoversRoom.addObserver(catAdmin);
    CatLoversRoom.addObserver(coCatAdmin);
    CatLoversRoom.addObserver(NormalCatUser1);
    

    // Display registered users
    cout << "\n--- Registered Users ---" << endl;
    cout << "Registered Users in " << CatLoversRoom.getRoomName() << ":" << endl;
    vector<Users*> users = CatLoversRoom.getUsers();
    for (size_t i = 0; i < users.size(); i++) {
        cout << "- " << users[i]->getName() << endl;
    }
    
    // Display room stats
    cout << "\n--- Room Stats ---" << endl;
    cout << "Getting room stats ready for you..." << endl;
    cout << CatLoversRoom.getRoomStats() << endl;

    cout << "\n--- Message Exchange ---" << endl;
    // Send messages
    catAdmin->send("Hello cat lovers!", &CatLoversRoom);
    coCatAdmin->send("Hi everyone!", &CatLoversRoom);
    
    string msg = "I love cats!";
    NormalCatUser1->send(msg, &CatLoversRoom);
    
    // Admin announcement
    cout << "\n--- Admin Announcement ---" << endl;
    catAdmin->makeAnnouncement("Daily cat fact: Cats sleep 16 hours a day!", &CatLoversRoom);

    // Display chat history
    cout << "\n--- Chat History ---" << endl;
    vector<string*> history = CatLoversRoom.getChatHistory();
    cout << "Chat History (" << history.size() << " messages):" << endl;
    for (size_t i = 0; i < history.size(); i++) {
        cout << "  " << *(history[i]) << endl;
    }

    cout << "\n--- User Removal ---" << endl;
    // Remove user
    catAdmin->removeOtherUser(NormalCatUser1, &CatLoversRoom);
    
    // Remove observers
    CatLoversRoom.removeObserver(NormalCatUser1);
    CatLoversRoom.removeObserver(coCatAdmin);
    CatLoversRoom.removeObserver(catAdmin);

    // Final room stats
    cout << "\n--- Final Room Stats ---" << endl;
    cout << CatLoversRoom.getRoomStats() << endl;

    cout << "\n--- Cleanup ---" << endl;
    delete catAdmin;
    delete coCatAdmin;
    delete NormalCatUser1;
 
    cout << "\n=== Testing Complete ===" << endl;
    return 0;
}