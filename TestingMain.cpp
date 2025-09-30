
/**
 * @file [TestingMain.cpp]
 * @brief [Final 100% coverage test - targeting remaining gaps]
 * @author [Complete Coverage Testing]
 * @date [2025-09-29]
 */

#include "NormalUser.h"
#include "AdminUser.h" 
#include "CoAdminUser.h"
#include "Users.h"
#include "ChatRoom.h"
#include "Dogorithm.h"
#include "CtrlCat.h"
#include "Command.h"
#include "SaveMessageCommand.h"
#include "SendMessageCommand.h"
#include "Iterator.h"
#include "UserIterator.h"
#include "ChatHistoryIterator.h"
#include "ChatRoomIterator.h"
#include "CommandIterator.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printSeparator(const string& title = "") {
    cout << "\n" << string(70, '-') << endl;
    if (!title.empty()) {
        cout << "  " << title << endl;
        cout << string(70, '-') << endl;
    }
}

void demonstrateUserCreation() {
    printSeparator("DEMO 1: USER CREATION");
    
    cout << "\n--- Creating Different User Types ---\n" << endl;
    
    AdminUser* admin = new AdminUser("Alice");
    CoAdminUser* coAdmin = new CoAdminUser("Bob");
    NormalUser* user1 = new NormalUser("Charlie");
    NormalUser* user2 = new NormalUser("Diana");
    NormalUser* user3 = new NormalUser("Eve");
    
    cout << "\nUsers created successfully!" << endl;
    cout << "Admin: " << admin->getName() << " (" << admin->getUserType() << ")" << endl;
    cout << "Co-Admin: " << coAdmin->getName() << " (" << coAdmin->getUserType() << ")" << endl;
    cout << "Normal Users: " << user1->getName() << ", " << user2->getName() << ", " << user3->getName() << endl;
    
    delete admin;
    delete coAdmin;
    delete user1;
    delete user2;
    delete user3;
}

void demonstrateChatRoomCreation() {
    printSeparator("DEMO 2: CHAT ROOM CREATION");
    
    cout << "\n--- Creating Chat Rooms ---\n" << endl;
    
    Dogorithm* dogRoom = new Dogorithm();
    cout << "\n";
    CtrlCat* catRoom = new CtrlCat();
    
    cout << "\nChat rooms created!" << endl;
    cout << "Room 1: " << dogRoom->getRoomName() << endl;
    cout << "Room 2: " << catRoom->getRoomName() << endl;
    
    delete dogRoom;
    delete catRoom;
}

void demonstrateUserRegistration() {
    printSeparator("DEMO 3: USER REGISTRATION IN ROOMS");
    
    Dogorithm* dogRoom = new Dogorithm();
    CtrlCat* catRoom = new CtrlCat();
    
    AdminUser* admin = new AdminUser("Admin_Alex");
    CoAdminUser* coAdmin = new CoAdminUser("CoAdmin_Blake");
    NormalUser* user1 = new NormalUser("User_Chris");
    NormalUser* user2 = new NormalUser("User_Dana");
    
    cout << "\n--- Registering Users in Dogorithm ---\n" << endl;
    dogRoom->registerUser(admin);
    dogRoom->registerUser(coAdmin);
    dogRoom->registerUser(user1);
    
    cout << "\n--- Registering Users in CtrlCat ---\n" << endl;
    catRoom->registerUser(admin);
    catRoom->registerUser(user2);
    
    cout << "\n--- Attempting Duplicate Registration ---\n" << endl;
    dogRoom->registerUser(user1);  // Should show already registered
    
    delete dogRoom;
    delete catRoom;
    delete admin;
    delete coAdmin;
    delete user1;
    delete user2;
}

void demonstrateMessaging() {
    printSeparator("DEMO 4: MESSAGE SENDING & RECEIVING");
    
    Dogorithm* room = new Dogorithm();
    
    AdminUser* admin = new AdminUser("Admin_Morgan");
    CoAdminUser* coAdmin = new CoAdminUser("CoAdmin_Riley");
    NormalUser* user1 = new NormalUser("User_Sam");
    NormalUser* user2 = new NormalUser("User_Taylor");
    
    room->registerUser(admin);
    room->registerUser(coAdmin);
    room->registerUser(user1);
    room->registerUser(user2);
    
    cout << "\n--- Normal User Sending Message ---\n" << endl;
    user1->send("Hello everyone! Great to be here!", room);
    
    cout << "\n--- Admin Sending Official Message ---\n" << endl;
    admin->send("Welcome to our community! Please follow the rules.", room);
    
    cout << "\n--- Co-Admin Sending Message ---\n" << endl;
    coAdmin->send("I'm here to help if anyone needs assistance!", room);
    
    cout << "\n--- Dog-Themed Message (Dogorithm Special) ---\n" << endl;
    user2->send("I love dogs! My puppy is so cute!", room);
    
    delete room;
    delete admin;
    delete coAdmin;
    delete user1;
    delete user2;
}

void demonstrateAdminFunctions() {
    printSeparator("DEMO 5: ADMIN PRIVILEGES");
    
    Dogorithm* room = new Dogorithm();
    
    AdminUser* admin = new AdminUser("SuperAdmin");
    NormalUser* user1 = new NormalUser("GoodUser");
    NormalUser* user2 = new NormalUser("SpamUser");
    
    room->registerUser(admin);
    room->registerUser(user1);
    room->registerUser(user2);
    
    cout << "\n--- Admin Making Announcement ---\n" << endl;
    admin->makeAnnouncement("Server maintenance scheduled for tonight at 10 PM", room);
    
    cout << "\n--- Admin Moderating Content ---\n" << endl;
    string spamMessage = "Buy now! Click here! spam spam spam promotional content";
    admin->moderateMessage(spamMessage, room);
    
    cout << "\n--- Admin Removing User ---\n" << endl;
    admin->removeOtherUser(user2, room);
    
    cout << "\n--- Viewing Room Stats ---\n" << endl;
    cout << room->getRoomStats() << endl;
    
    delete room;
    delete admin;
    delete user1;
    delete user2;
}

void demonstrateCommandPattern() {
    printSeparator("DEMO 6: COMMAND PATTERN");
    
    Dogorithm* room = new Dogorithm();
    NormalUser* user = new NormalUser("CommandUser");
    
    room->registerUser(user);
    
    cout << "\n--- Creating and Queuing Commands ---\n" << endl;
    
    Command* cmd1 = new SendMessageCommand("First message", room, user);
    Command* cmd2 = new SaveMessageCommand("Saved message", room, user);
    Command* cmd3 = new SendMessageCommand("Second message", room, user);
    
    user->addCommand(cmd1);
    user->addCommand(cmd2);
    user->addCommand(cmd3);
    
    cout << "\n--- Executing All Queued Commands ---\n" << endl;
    user->executeAll();
    
    delete room;
    delete user;
    delete cmd1;
    delete cmd2;
    delete cmd3;
}

void demonstrateIteratorPattern() {
    printSeparator("DEMO 7: ITERATOR PATTERN");
    
    Dogorithm* dogRoom = new Dogorithm();
    CtrlCat* catRoom = new CtrlCat();
    
    NormalUser* user = new NormalUser("MultiRoomUser");
    
    dogRoom->registerUser(user);
    catRoom->registerUser(user);
    
    user->send("Message 1", dogRoom);
    user->send("Message 2", dogRoom);
    user->send("Message 3", catRoom);
    
    cout << "\n--- Iterating Through User's Chat Rooms ---\n" << endl;
    auto roomIterator = user->createIterator();
    for (roomIterator.first(); !roomIterator.isDone(); roomIterator.next()) {
        ChatRoom* room = roomIterator.current();
        if (room) {
            cout << "User is in room: " << room->getRoomName() << endl;
        }
    }
    
    cout << "\n--- Iterating Through Dogorithm's Users ---\n" << endl;
    auto userIterator = dogRoom->createUserIterator();
    for (userIterator.first(); !userIterator.isDone(); userIterator.next()) {
        Users* u = userIterator.current();
        if (u) {
            cout << "User in Dogorithm: " << u->getName() << " (" << u->getUserType() << ")" << endl;
        }
    }
    
    cout << "\n--- Iterating Through Chat History ---\n" << endl;
    auto historyIterator = dogRoom->createChatHistoryIterator();
    int msgCount = 0;
    for (historyIterator.first(); !historyIterator.isDone(); historyIterator.next()) {
        string* msg = historyIterator.current();
        if (msg) {
            msgCount++;
            cout << "Message " << msgCount << ": " << *msg << endl;
        }
    }
    
    delete dogRoom;
    delete catRoom;
    delete user;
}

void demonstrateObserverPattern() {
    printSeparator("DEMO 8: OBSERVER PATTERN");
    
    Dogorithm* room = new Dogorithm();
    
    NormalUser* user1 = new NormalUser("Observer1");
    NormalUser* user2 = new NormalUser("Observer2");
    NormalUser* user3 = new NormalUser("Observer3");
    
    room->registerUser(user1);
    room->registerUser(user2);
    room->registerUser(user3);
    
    cout << "\n--- Sending Message (Observers Get Notified) ---\n" << endl;
    user1->send("This will notify all other users!", room);
    
    delete room;
    delete user1;
    delete user2;
    delete user3;
}

void demonstrateRoomThemes() {
    printSeparator("DEMO 9: THEMED CHAT ROOMS");
    
    Dogorithm* dogRoom = new Dogorithm();
    CtrlCat* catRoom = new CtrlCat();
    
    NormalUser* user = new NormalUser("ThemeExplorer");
    
    cout << "\n--- Dogorithm Theme ---\n" << endl;
    dogRoom->registerUser(user);
    cout << dogRoom->getRoomTheme() << endl;
    user->send("I love algorithms and dogs!", dogRoom);
    
    cout << "\n--- CtrlCat Theme ---\n" << endl;
    catRoom->registerUser(user);
    cout << catRoom->getRoomTheme() << endl;
    user->send("Cats are amazing programmers!", catRoom);
    
    delete dogRoom;
    delete catRoom;
    delete user;
}

void demonstrateHistoryManagement() {
    printSeparator("DEMO 10: HISTORY MANAGEMENT");
    
    Dogorithm* room = new Dogorithm();
    AdminUser* admin = new AdminUser("HistoryAdmin");
    NormalUser* user1 = new NormalUser("HistoryUser1");
    NormalUser* user2 = new NormalUser("HistoryUser2");
    
    room->registerUser(admin);
    room->registerUser(user1);
    room->registerUser(user2);
    
    cout << "\n--- Generating Chat History ---\n" << endl;
    user1->send("First message", room);
    user2->send("Second message", room);
    admin->send("Admin message", room);
    
    cout << "\n--- Viewing History Count ---\n" << endl;
    cout << "Total messages in history: " << room->getChatHistory().size() << endl;
    
    cout << "\n--- Clearing History (Admin Function) ---\n" << endl;
    room->clearHistory();
    
    cout << "\n--- History After Clear ---\n" << endl;
    cout << "Messages remaining: " << room->getChatHistory().size() << endl;
    
    delete room;
    delete admin;
    delete user1;
    delete user2;
}

void demonstrateCompleteScenario() {
    printSeparator("DEMO 11: COMPLETE REAL-WORLD SCENARIO");
    
    cout << "\n=== Starting a New Chat Community ===\n" << endl;
    
    // Create rooms
    Dogorithm* dogRoom = new Dogorithm();
    CtrlCat* catRoom = new CtrlCat();

    cout<<"\n admin getting created"<<endl;
    
    // Create users
    AdminUser* admin = new AdminUser("CommunityLeader");
    cout<<"\n coadmin getting created"<<endl;
    CoAdminUser* coAdmin = new CoAdminUser("AssistantMod");
    cout<<"\n alice getting created"<<endl;
    NormalUser* alice = new NormalUser("Alice");
    cout<<"\n bob getting created"<<endl;
    NormalUser* bob = new NormalUser("Bob");
    cout<<"\n carol getting created"<<endl;
    NormalUser* carol = new NormalUser("Carol");
    
    // Day 1: Users join
    cout << "\n--- DAY 1: Community Launch ---\n" << endl;
    cout<<"\n register admin"<<endl;
    dogRoom->registerUser(admin);

    cout<<"\n register alice"<<endl;
    dogRoom->registerUser(alice);

    cout<<"\n register bob"<<endl;
    dogRoom->registerUser(bob);
    
    cout<<"\n admin announcement"<<endl;
    admin->makeAnnouncement("Welcome to our new community!", dogRoom);

    cout<<"\n alice message"<<endl;
    alice->send("Excited to be here!", dogRoom);

    cout<<"\n bob message"<<endl;
    bob->send("Hello everyone!", dogRoom);
    
    // Day 2: More activity
    cout << "\n--- DAY 2: Growing Community ---\n" << endl;
    cout<<"\n register coadmin"<<endl;
    dogRoom->registerUser(coAdmin);

    cout<<"\n register carol"<<endl;
    dogRoom->registerUser(carol);
    
    cout<<"\n carol message"<<endl;
    carol->send("Can someone help me with algorithms?", dogRoom);

    cout<<"\n  coadmin message"<<endl;
    coAdmin->send("I'm here to help!", dogRoom);
    
    // Day 3: Multi-room participation
    cout << "\n--- DAY 3: Expanding to Multiple Rooms ---\n" << endl;
    cout<<"\n register admin"<<endl;
    catRoom->registerUser(admin);

    cout<<"\n register alice"<<endl;
    catRoom->registerUser(alice);
    
    cout<<"\n  alice send message"<<endl;
    alice->send("I love both dogs and cats!", catRoom);

    cout<<"\n  admin anouncement"<<endl;
    admin->makeAnnouncement("CtrlCat room is now open!", catRoom);
    
    // Day 4: Moderation needed
    cout << "\n--- DAY 4: Moderation In Action ---\n" << endl;

    cout<<"\n bob send spam"<<endl;
    bob->send("spam spam buy now click here spam", dogRoom);

    cout<<"\n admin deal with spam"<<endl;
    admin->moderateMessage("spam spam buy now", dogRoom);
    
    // Final stats
    cout << "\n--- COMMUNITY STATISTICS ---\n" << endl;
    cout << dogRoom->getRoomStats() << endl;
    cout << "\n" << catRoom->getRoomStats() << endl;
    
    // Cleanup
    delete dogRoom;
    delete catRoom;
    delete admin;
    delete coAdmin;
    delete alice;
    delete bob;
    delete carol;
}

void runCat(){
    cout << "=== CTRLCAT 100% COVERAGE TEST ===" << endl;

    // Test 1: Constructor
    cout << "--- Test 1: Constructor ---" << endl;
    {
        CtrlCat room;
        cout << room.getRoomName() << endl;
        cout << room.getRoomTheme() << endl;
    }
    cout << endl;

    // Test 2: Destructor
    cout << "--- Test 2: Destructor ---" << endl;
    {
        CtrlCat* room = new CtrlCat();
        delete room; // Hits destructor lines 16-18
    }
    cout << endl;

    // Test 3: registerUser with null
    cout << "--- Test 3: Register Null ---" << endl;
    {
        CtrlCat room;
        room.registerUser(nullptr); // Hits early return
    }
    cout << endl;

    // Test 4: registerUser with valid user (not exists)
    cout << "--- Test 4: Register Valid User ---" << endl;
    {
        CtrlCat room;
        NormalUser user("User1");
        room.registerUser(&user); // Hits exists = false path
    }
    cout << endl;

    // Test 5: registerUser with duplicate user (exists)
    cout << "--- Test 5: Register Duplicate ---" << endl;
    {
        CtrlCat room;
        NormalUser user("User1");
        room.registerUser(&user);
        room.registerUser(&user); // Hits exists = true path
    }
    cout << endl;

    // Test 6: sendMessage with valid params
    cout << "--- Test 6: Send Valid Message ---" << endl;
    {
        CtrlCat room;
        NormalUser user("User1");
        room.registerUser(&user);
        
        string msg = "Hello CtrlCat";
        room.sendMessage(&msg, &user);
    }
    cout << endl;

    // Test 7: sendMessage with null message
    cout << "--- Test 7: Send Null Message ---" << endl;
    {
        CtrlCat room;
        NormalUser user("User1");
        room.registerUser(&user);
        
        room.sendMessage(nullptr, &user); // Doesn't enter if block
    }
    cout << endl;

    // Test 8: sendMessage with null user
    cout << "--- Test 8: Send Null User ---" << endl;
    {
        CtrlCat room;
        string msg = "test";
        room.sendMessage(&msg, nullptr); // Doesn't enter if block
    }
    cout << endl;

    // Test 9: removeUser with null
    cout << "--- Test 9: Remove Null User ---" << endl;
    {
        CtrlCat room;
        room.removeUser(nullptr);
    }
    cout << endl;

    // Test 10: removeUser with Admin
    cout << "--- Test 10: Remove Admin ---" << endl;
    {
        CtrlCat room;
        AdminUser admin("Admin");
        NormalUser other("Other");
        
        room.registerUser(&admin);
        room.registerUser(&other);
        
        room.removeUser(&admin); // Hits Admin branch
    }
    cout << endl;

    // Test 11: removeUser with CoAdmin
    cout << "--- Test 11: Remove CoAdmin ---" << endl;
    {
        CtrlCat room;
        CoAdminUser coadmin("CoAdmin");
        NormalUser other("Other");
        
        room.registerUser(&coadmin);
        room.registerUser(&other);
        
        room.removeUser(&coadmin); // Hits Co-Admin branch
    }
    cout << endl;

    // Test 12: removeUser with Normal user
    cout << "--- Test 12: Remove Normal User ---" << endl;
    {
        CtrlCat room;
        NormalUser user("Normal");
        NormalUser other("Other");
        
        room.registerUser(&user);
        room.registerUser(&other);
        
        room.removeUser(&user); // Hits else branch
    }
    cout << endl;

    // Test 13: isCatThemed with cat words
    cout << "--- Test 13: Cat Themed Messages ---" << endl;
    {
        CtrlCat room;
        
        cout << "cat: " << room.isCatThemed("I love my cat") << endl;
        cout << "kitten: " << room.isCatThemed("cute kitten") << endl;
        cout << "kitty: " << room.isCatThemed("hello kitty") << endl;
        cout << "meow: " << room.isCatThemed("meow meow") << endl;
        cout << "purr: " << room.isCatThemed("purring sound") << endl;
        cout << "claw: " << room.isCatThemed("sharp claws") << endl;
        cout << "whisker: " << room.isCatThemed("cat whiskers") << endl;
        cout << "tail: " << room.isCatThemed("fluffy tail") << endl;
        cout << "fur: " << room.isCatThemed("soft fur") << endl;
        cout << "feline: " << room.isCatThemed("feline friend") << endl;
        cout << "tabby: " << room.isCatThemed("tabby cat") << endl;
        cout << "siamese: " << room.isCatThemed("siamese breed") << endl;
        cout << "persian: " << room.isCatThemed("persian cat") << endl;
        cout << "maine coon: " << room.isCatThemed("maine coon") << endl;
        cout << "sphinx: " << room.isCatThemed("sphinx cat") << endl;
        cout << "lynx: " << room.isCatThemed("wild lynx") << endl;
        cout << "cougar: " << room.isCatThemed("mountain cougar") << endl;
        cout << "tiger: " << room.isCatThemed("tiger stripes") << endl;
        cout << "lion: " << room.isCatThemed("king lion") << endl;
        cout << "panther: " << room.isCatThemed("black panther") << endl;
        
        cout << "not cat: " << room.isCatThemed("normal message") << endl;
    }
    cout << endl;

    // Test 14: reactToCatMessage with null user
    cout << "--- Test 14: React Null User ---" << endl;
    {
        CtrlCat room;
        room.reactToCatMessage("test", nullptr); // Early return
    }
    cout << endl;

    // Test 15: reactToCatMessage with cat/kitten/meow
    cout << "--- Test 15: React Cat Messages ---" << endl;
    {
        CtrlCat room;
        NormalUser user("User1");
        room.registerUser(&user);
        
        room.reactToCatMessage("I love cats", &user);
        room.reactToCatMessage("cute kitten", &user);
        room.reactToCatMessage("meow meow", &user);
    }
    cout << endl;

    // Test 16: reactToCatMessage with dog/puppy
    cout << "--- Test 16: React Dog Messages ---" << endl;
    {
        CtrlCat room;
        NormalUser user("User1");
        room.registerUser(&user);
        
        room.reactToCatMessage("I have a dog", &user);
        room.reactToCatMessage("cute puppy", &user);
    }
    cout << endl;

    // Test 17: reactToCatMessage with purr/whisker
    cout << "--- Test 17: React Purr/Whisker ---" << endl;
    {
        CtrlCat room;
        NormalUser user("User1");
        room.registerUser(&user);
        
        room.reactToCatMessage("purring softly", &user);
        room.reactToCatMessage("long whiskers", &user);
    }
    cout << endl;

    // Test 18: reactToCatMessage with other message
    cout << "--- Test 18: React Other Message ---" << endl;
    {
        CtrlCat room;
        NormalUser user("User1");
        room.registerUser(&user);
        
        room.reactToCatMessage("just a normal message", &user); // Hits else
    }
    cout << endl;

    // Test 19: Case insensitivity in reactions
    cout << "--- Test 19: Case Insensitivity ---" << endl;
    {
        CtrlCat room;
        NormalUser user("User1");
        room.registerUser(&user);
        
        room.reactToCatMessage("CAT KITTEN MEOW", &user);
        room.reactToCatMessage("DOG PUPPY", &user);
        room.reactToCatMessage("PURR WHISKER", &user);
        
        cout << "CAT: " << room.isCatThemed("CAT") << endl;
        cout << "MeOw: " << room.isCatThemed("MeOw") << endl;
    }
    cout << endl;

    cout << "=== CTRLCAT 100% COVERAGE COMPLETE ===" << endl;
}

void runTest(){
    cout << "=== FINAL 100% COVERAGE TEST ===" << endl;
    cout << endl;

    runCat();

    // Test 1: Command constructors (for .h file coverage)
    cout << "--- Test 1: Command Constructors ---" << endl;
    {
        Dogorithm room;
        NormalUser user("User");
        room.registerUser(&user);
        
        string msg1 = "Message 1";
        string msg2 = "Message 2";
        string msg3 = "Message 3";
        
        // Create commands to hit constructors in .h files
        SaveMessageCommand save1(msg1, &room, &user);
        SaveMessageCommand save2(msg2, &room, &user);
        SaveMessageCommand save3(msg3, &room, &user);
        
        SendMessageCommand send1(msg1, &room, &user);
        SendMessageCommand send2(msg2, &room, &user);
        SendMessageCommand send3(msg3, &room, &user);
        
        // Execute them
        save1.execute();
        send1.execute();
        save2.execute();
        send2.execute();
        save3.execute();
        send3.execute();
    }
    cout << endl;

    // Test 2: CommandIterator complete coverage
    cout << "--- Test 2: CommandIterator Full Coverage ---" << endl;
    {
        Dogorithm room;
        NormalUser user("CmdUser");
        room.registerUser(&user);
        
        string m1 = "cmd1", m2 = "cmd2", m3 = "cmd3";
        SaveMessageCommand c1(m1, &room, &user);
        SaveMessageCommand c2(m2, &room, &user);
        SaveMessageCommand c3(m3, &room, &user);
        
        user.addCommand(&c1);
        user.addCommand(&c2);
        user.addCommand(&c3);
        
        // Iterate through commands
        CommandIterator it = user.createcommandIterator();
        it.first();
        cout << "Start index: " << it.getIndex() << endl;
        
        while (!it.isDone()) {
            Command* cmd = it.current();
            if (cmd) {
                cout << "Command at index " << it.getIndex() << endl;
            }
            it.next();
        }
        
        // Test at boundary (index >= size)
        cout << "At end, isDone: " << it.isDone() << endl;
        Command* nullCmd = it.current(); // Should return nullptr
        cout << "Current at end: " << (nullCmd ? "not null" : "null") << endl;
        it.next(); // Should not increment
        cout << "Final index: " << it.getIndex() << endl;
    }
    cout << endl;

    // Test 3: All iterator edge cases
    cout << "--- Test 3: All Iterators Boundary Cases ---" << endl;
    {
        Dogorithm room;
        NormalUser u1("U1"), u2("U2"), u3("U3");
        
        room.registerUser(&u1);
        room.registerUser(&u2);
        room.registerUser(&u3);
        
        u1.send("msg1", &room);
        u2.send("msg2", &room);
        u3.send("msg3", &room);
        
        // UserIterator - complete traversal
        UsersIterator uit = room.createUserIterator();
        uit.first();
        while (!uit.isDone()) {
            uit.current();
            uit.getIndex();
            uit.next();
        }
        uit.current(); // nullptr
        uit.next(); // no increment
        uit.getIndex();
        
        // ChatHistoryIterator - complete traversal
        ChatHistoryIterator hit = room.createChatHistoryIterator();
        hit.first();
        while (!hit.isDone()) {
            hit.current();
            hit.getIndex();
            hit.next();
        }
        hit.current(); // nullptr
        hit.next(); // no increment
        hit.getIndex();
        
        // ChatRoomIterator - complete traversal
        Dogorithm room2;
        u1.addChatRoom(&room2);
        ChatRoomIterator rit = u1.createIterator();
        rit.first();
        while (!rit.isDone()) {
            rit.current();
            rit.getIndex();
            rit.next();
        }
        rit.current(); // nullptr
        rit.next(); // no increment
        rit.getIndex();
    }
    cout << endl;

    // Test 4: Every AdminUser code path systematically
    cout << "--- Test 4: Complete AdminUser Coverage ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("FullAdmin");
        NormalUser u1("U1"), u2("U2"), u3("U3"), u4("U4");
        
        room.registerUser(&admin);
        room.registerUser(&u1);
        room.registerUser(&u2);
        room.registerUser(&u3);
        room.registerUser(&u4);
        
        // === MODERATION TESTS - Every branch ===
        
        // 1. Normal message (no violations)
        admin.moderateMessage("This is a perfectly normal message", &room);
        
        // 2. Length violation (>200 chars)
        admin.moderateMessage(string(201, 'x'), &room);
        
        // 3. Spam - lowercase
        admin.moderateMessage("this is spam content", &room);
        
        // 4. Buy now trigger
        admin.moderateMessage("buy now before it's too late", &room);
        
        // 5. Click here trigger
        admin.moderateMessage("click here for prizes", &room);
        
        // 6. Inappropriate content
        admin.moderateMessage("this is inappropriate content", &room);
        
        // 7. Offensive content
        admin.moderateMessage("this is offensive language", &room);
        
        // 8. Combination triggers
        admin.moderateMessage("spam buy now click here inappropriate offensive", &room);
        
        // 9. Empty message
        admin.moderateMessage("", &room);
        
        // 10. Null room
        admin.moderateMessage("test", nullptr);
        
        // === REMOVE USER TESTS - Every branch ===
        
        // 1. Valid user removal
        admin.removeOtherUser(&u1, &room);
        
        // 2. User not in room (already removed)
        admin.removeOtherUser(&u1, &room);
        
        // 3. Null user
        admin.removeOtherUser(nullptr, &room);
        
        // 4. Try to remove self
        admin.removeOtherUser(&admin, &room);
        
        // 5. Null room
        room.registerUser(&u1); // Re-add for next test
        admin.removeOtherUser(&u1, nullptr);
        room.registerUser(&u1);
        
        // === ANNOUNCEMENT TESTS - Every branch ===
        
        // 1. Valid announcement
        admin.makeAnnouncement("This is an important announcement", &room);
        
        // 2. Empty announcement
        admin.makeAnnouncement("", &room);
        
        // 3. Null room
        admin.makeAnnouncement("test announcement", nullptr);
        
        // === SEND TESTS - Every branch ===
        
        // 1. Valid message
        admin.send("Valid admin message", &room);
        
        // 2. Empty message
        admin.send("", &room);
        
        // 3. Null room
        admin.send("test", nullptr);
        
        // === RECEIVE TESTS - Every branch ===
        
        // 1. Valid receive
        admin.receive("normal message", &u2, &room);
        
        // 2. Null fromUser
        admin.receive("test", nullptr, &room);
        
        // 3. Null room
        admin.receive("test", &u2, nullptr);
        
        // === ALERT PROCESSING - Every trigger ===
        
        // 1. Help keyword
        u2.send("I need help with something", &room);
        
        // 2. Admin keyword
        u2.send("Can an admin assist me", &room);
        
        // 3. Emergency keyword
        u2.send("This is an emergency", &room);
        
        // 4. Urgent keyword
        u2.send("urgent matter needs attention", &room);
        
        // 5. Both help and admin
        u2.send("help admin please", &room);
        
        // 6. Both emergency and urgent
        u2.send("urgent emergency situation", &room);
        
        // === AUTO-WELCOME TEST ===
        u3.send("New user joined the room", &room);
        
        // === RULES REQUEST TESTS ===
        
        // 1. Rules keyword
        u2.send("What are the rules here", &room);
        
        // 2. Guidelines keyword
        u3.send("Can someone share the guidelines", &room);
        
        // 3. Both keywords
        u4.send("I need to know the rules and guidelines", &room);
        
        // === CONTENT MODERATION (>300 chars) ===
        u2.send(string(301, 'a'), &room);
        u3.send(string(350, 'b'), &room);
        
        // === MESSAGE COUNT MONITORING (every 10th message) ===
        for (int i = 0; i < 25; i++) {
            u4.send("Message number " + to_string(i), &room);
        }
        
        // === COMMAND QUEUE TESTS ===
        
        // 1. Add null command
        admin.addCommand(nullptr);
        
        // 2. Add valid commands
        string cmdMsg = "command message";
        SaveMessageCommand cmd1(cmdMsg, &room, &admin);
        SaveMessageCommand cmd2(cmdMsg, &room, &admin);
        admin.addCommand(&cmd1);
        admin.addCommand(&cmd2);
        
        // 3. Execute with commands
        admin.executeAll();
        
        // 4. Execute with empty queue
        admin.executeAll();
    }
    cout << endl;

    // Test 5: Complete ChatRoom coverage
    cout << "--- Test 5: ChatRoom Every Path ---" << endl;
    {
        Dogorithm room;
        NormalUser u1("U1"), u2("U2"), u3("U3");
        
        // === REGISTER USER - All branches ===
        room.registerUser(nullptr); // Null
        room.registerUser(&u1); // First time
        room.registerUser(&u1); // Duplicate
        room.registerUser(&u2);
        room.registerUser(&u3);
        
        // === SEND MESSAGE - All branches ===
        
        string msg = "test message";
        string empty = "";
        
        room.sendMessage(nullptr, &u1); // Null message
        room.sendMessage(&msg, nullptr); // Null user
        room.sendMessage(&empty, &u1); // Empty message
        
        NormalUser outsider("Outside");
        string outMsg = "from outside";
        room.sendMessage(&outMsg, &outsider); // User not in room
        
        // Valid message (also tests delivery loop and exception handling)
        string validMsg = "valid message";
        room.sendMessage(&validMsg, &u1);
        
        // === SAVE MESSAGE - All branches ===
        room.saveMessage("valid save", &u1);
        room.saveMessage("", &u1); // Empty
        room.saveMessage("test", nullptr); // Null user
        
        // === REMOVE USER - All branches ===
        room.removeUser(nullptr); // Null
        room.removeUser(&outsider); // Not in room
        room.removeUser(&u1); // Valid removal
        room.removeUser(&u1); // Already removed
        
        // === BROADCAST - All branches ===
        room.broadcastSystemMessage(""); // Empty with users
        room.broadcastSystemMessage("Valid broadcast"); // Valid
        
        room.removeUser(&u2);
        room.removeUser(&u3);
        room.broadcastSystemMessage("No users to broadcast to"); // Empty room
        
        // === OTHER METHODS ===
        room.clearHistory();
        cout << room.getRoomStats() << endl;
        cout << "Outsider in room: " << room.isUserInRoom(&outsider) << endl;
        
        vector<Users*> users = room.getUsers();
        vector<string*> history = room.getChatHistory();
    }
    cout << endl;

    // Test 6: NormalUser remaining paths
    cout << "--- Test 6: NormalUser Final Paths ---" << endl;
    {
        Dogorithm room;
        NormalUser u1("N1"), u2("N2");
        
        room.registerUser(&u1);
        room.registerUser(&u2);
        
        // All message type detections in receive
        u1.receive("normal message", &u2, &room);
        u1.receive("[ADMIN] admin message", &u2, &room);
        u1.receive("[CO-ADMIN] coadmin message", &u2, &room);
        u1.receive("hello world", &u2, &room);
        u1.receive("hi there", &u2, &room);
        u1.receive("hello and hi", &u2, &room);
        
        // Edge cases
        u1.receive("test", nullptr, &room);
        u1.receive("test", &u2, nullptr);
        
        u1.send("message", &room);
        u1.send("", &room);
        u1.send("test", nullptr);
        
        // Commands
        string cmdMsg = "cmd";
        SaveMessageCommand cmd(cmdMsg, &room, &u1);
        u1.addCommand(nullptr);
        u1.addCommand(&cmd);
        u1.executeAll();
        u1.executeAll();
    }
    cout << endl;

    // Test 7: CoAdminUser remaining paths
    cout << "--- Test 7: CoAdminUser Final Paths ---" << endl;
    {
        Dogorithm room;
        CoAdminUser co("CoAdmin");
        NormalUser user("User");
        
        room.registerUser(&co);
        room.registerUser(&user);
        
        // All send/receive paths
        co.send("message", &room);
        co.send("test", nullptr);
        
        co.receive("normal", &user, &room);
        co.receive("[URGENT] critical", &user, &room);
        co.receive("test", nullptr, &room);
        co.receive("test", &user, nullptr);
        
        // All assistModeration paths
        co.assistModeration("short", &room);
        co.assistModeration(string(101, 'x'), &room);
        co.assistModeration("spam alert", &room);
        co.assistModeration("SPAM ALERT", &room);
        co.assistModeration("both spam and SPAM", &room);
        co.assistModeration("test", nullptr);
        
        // Commands
        string m = "msg";
        SendMessageCommand cmd(m, &room, &co);
        co.addCommand(nullptr);
        co.addCommand(&cmd);
        co.executeAll();
        co.executeAll();
    }
    cout << endl;

    // Test 8: Dogorithm complete
    cout << "--- Test 8: Dogorithm Complete ---" << endl;
    {
        Dogorithm room;
        
        NormalUser norm("N");
        AdminUser adm("A");
        CoAdminUser coadm("C");
        
        // All registration types
        room.registerUser(&norm);
        room.registerUser(&adm);
        room.registerUser(&coadm);
        
        // Cycle all 5 welcome puns
        for (int i = 0; i < 5; i++) {
            NormalUser temp("T" + to_string(i));
            room.registerUser(&temp);
        }
        
        // Every dog word
        norm.send("dog puppy woof bark", &room);
        norm.send("tail paw bone fetch", &room);
        norm.send("treat collar leash park", &room);
        norm.send("walk good boy good girl", &room);
        norm.send("canine hound retriever", &room);
        norm.send("shepherd husky beagle", &room);
        
        // Cycle all 5 reactions
        for (int i = 0; i < 5; i++) {
            norm.send("dog " + to_string(i), &room);
        }
        
        // All message reactions
        norm.send("algorithm code programming", &room);
        norm.send("hello hi help", &room);
        norm.send("normal message", &room);
        
        string empty = "";
        room.sendMessage(&empty, &norm);
        room.sendMessage(nullptr, &norm);
        
        // All removal types
        room.removeUser(&norm);
        room.removeUser(&adm);
        room.removeUser(&coadm);
        room.removeUser(nullptr);
    }
    cout << endl;

    // Test 9: CtrlCat complete
    cout << "--- Test 9: CtrlCat Complete ---" << endl;
    {
        CtrlCat room;
        NormalUser n("N");
        AdminUser a("A");
        CoAdminUser c("C");
        
        room.registerUser(&n);
        room.registerUser(&a);
        room.registerUser(&c);
        
        string msg = "meow";
        room.sendMessage(&msg, &n);
        room.sendMessage(nullptr, &n);
        
        room.removeUser(&a);
        room.removeUser(&c);
        room.removeUser(&n);
        room.removeUser(nullptr);
    }
    cout << endl;

    // Test 10: Users base class
    cout << "--- Test 10: Users Base Paths ---" << endl;
    {
        Dogorithm r1, r2;
        NormalUser u("U");
        
        u.addChatRoom(&r1);
        u.addChatRoom(&r2);
        u.addChatRoom(nullptr);
        
        u.removeChatRoom(&r1);
        u.removeChatRoom(nullptr);
        
        Dogorithm r3;
        u.removeChatRoom(&r3);
        
        ChatRoom* rooms = u.getChatRooms();
        
        ChatRoomIterator it = u.createIterator();
        it.first();
        while (!it.isDone()) {
            it.current();
            it.next();
        }
    }
    cout << endl;

     // Test 1: AdminUser default constructor and destructor (lines 17-21, 29-32)
    cout << "--- Test 1: AdminUser Default Constructor ---" << endl;
    {
        AdminUser defaultAdmin; // Line 17-21
        cout << "Default admin created" << endl;
    } // Destructor called here (lines 29-32)
    cout << endl;

    // Test 2: Hit AdminUser line 69 - receive with valid params
    cout << "--- Test 2: AdminUser Receive Line 69 ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("Admin");
        NormalUser user("User");
        
        room.registerUser(&admin);
        room.registerUser(&user);
        
        // This triggers line 69 (the cout statement in receive)
        admin.receive("test message", &user, &room);
    }
    cout << endl;

    // Test 3: AdminUser executeAll with EMPTY queue (lines 95-96)
    cout << "--- Test 3: Empty Command Queue ---" << endl;
    {
        AdminUser admin("EmptyQueueAdmin");
        // Don't add any commands
        admin.executeAll(); // This hits lines 95-96
    }
    cout << endl;

    // Test 4: AdminUser removeOtherUser SUCCESS path (lines 210-224)
    cout << "--- Test 4: Successful User Removal ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("RemovalAdmin");
        NormalUser victim("ToBeRemoved");
        NormalUser witness("Witness");
        
        room.registerUser(&admin);
        room.registerUser(&victim);
        room.registerUser(&witness);
        
        // This should hit ALL the success path lines 210-224
        admin.removeOtherUser(&victim, &room);
    }
    cout << endl;

    // Test 5: AdminUser alert processing - help/admin keywords (lines 271-275)
    cout << "--- Test 5: Help Admin Alert ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("AlertAdmin");
        NormalUser user("Requester");
        
        room.registerUser(&admin);
        room.registerUser(&user);
        
        // Message with BOTH "help" AND "admin" to trigger line 271
        user.send("help admin please assist", &room);
    }
    cout << endl;

    // Test 6: AdminUser emergency/urgent alert (lines 279-282)
    cout << "--- Test 6: Emergency Urgent Alert ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("EmergencyAdmin");
        NormalUser user("Emergency");
        
        room.registerUser(&admin);
        room.registerUser(&user);
        
        // Message with BOTH "emergency" AND "urgent"
        user.send("emergency urgent critical situation", &room);
    }
    cout << endl;

    // Test 7: AdminUser auto-moderation >300 chars (lines 290-291)
    cout << "--- Test 7: Auto Moderation >300 ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("ModAdmin");
        NormalUser user("LongMessager");
        
        room.registerUser(&admin);
        room.registerUser(&user);
        
        // Send message >300 chars to trigger lines 290-291
        user.send(string(310, 'x'), &room);
    }
    cout << endl;

    // Test 8: AdminUser message count (line 299) - need exactly 10th message
    cout << "--- Test 8: Message Count Monitoring ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("CountAdmin");
        NormalUser user("Counter");
        
        room.registerUser(&admin);
        room.registerUser(&user);
        
        // Send exactly 10 messages to hit the modulo condition
        for (int i = 0; i < 10; i++) {
            user.send("Message " + to_string(i), &room);
        }
    }
    cout << endl;

    // Test 9: AdminUser auto-welcome (lines 311-315)
    cout << "--- Test 9: Auto Welcome ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("WelcomeAdmin");
        NormalUser user("Newcomer");
        
        room.registerUser(&admin);
        room.registerUser(&user);
        
        // Message must contain "joined the room"
        user.send("NewUser joined the room", &room);
    }
    cout << endl;

    // Test 10: AdminUser rules request (lines 320-322)
    cout << "--- Test 10: Rules Request ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("RulesAdmin");
        NormalUser user("RulesRequester");
        
        room.registerUser(&admin);
        room.registerUser(&user);
        
        // Message with "rules" or "guidelines"
        user.send("Can you tell me the rules please", &room);
        user.send("What are the guidelines here", &room);
    }
    cout << endl;

    // Test 11: ChatRoom - null user registration (lines 36-37)
    cout << "--- Test 11: ChatRoom Null Registration ---" << endl;
    {
        Dogorithm room;
        room.registerUser(nullptr); // Lines 36-37
    }
    cout << endl;

    // Test 12: ChatRoom - duplicate registration (lines 42-43)
    cout << "--- Test 12: Duplicate Registration ---" << endl;
    {
        Dogorithm room;
        NormalUser user("Duplicate");
        
        room.registerUser(&user);
        room.registerUser(&user); // Lines 42-43
    }
    cout << endl;

    // Test 13: ChatRoom sendMessage - null/empty (lines 62, 67-68)
    cout << "--- Test 13: SendMessage Edge Cases ---" << endl;
    {
        Dogorithm room;
        NormalUser user("Sender");
        room.registerUser(&user);
        
        room.sendMessage(nullptr, &user); // Line 62
        
        string empty = "";
        room.sendMessage(&empty, &user); // Lines 67-68
    }
    cout << endl;

    // Test 14: ChatRoom sendMessage - deliver to users (lines 77-94)
    cout << "--- Test 14: Message Delivery Loop ---" << endl;
    {
        Dogorithm room;
        NormalUser sender("Sender");
        NormalUser receiver1("R1");
        NormalUser receiver2("R2");
        
        room.registerUser(&sender);
        room.registerUser(&receiver1);
        room.registerUser(&receiver2);
        
        string msg = "Broadcast message";
        room.sendMessage(&msg, &sender); // Lines 77-94
    }
    cout << endl;

    // Test 15: ChatRoom removeUser - null check (line 116)
    cout << "--- Test 15: Remove Null User ---" << endl;
    {
        Dogorithm room;
        room.removeUser(nullptr); // Line 116
    }
    cout << endl;

    // Test 16: ChatRoom removeUser - success path (lines 126-151)
    cout << "--- Test 16: Successful User Removal ---" << endl;
    {
        Dogorithm room;
        NormalUser user1("U1");
        NormalUser user2("U2");
        
        room.registerUser(&user1);
        room.registerUser(&user2);
        
        room.removeUser(&user1); // Lines 126-151 (with users.size() > 0)
    }
    cout << endl;

    // Test 17: ChatRoom getRoomStats with users (lines 174-177)
    cout << "--- Test 17: Room Stats ---" << endl;
    {
        Dogorithm room;
        NormalUser u1("U1");
        NormalUser u2("U2");
        
        room.registerUser(&u1);
        room.registerUser(&u2);
        
        string stats = room.getRoomStats(); // Lines 174-177
        cout << stats << endl;
    }
    cout << endl;

    // Test 18: ChatRoom broadcastSystemMessage with users (lines 213-231)
    cout << "--- Test 18: Broadcast With Users ---" << endl;
    {
        Dogorithm room;
        NormalUser u1("U1");
        NormalUser u2("U2");
        
        room.registerUser(&u1);
        room.registerUser(&u2);
        
        room.broadcastSystemMessage("System alert"); // Lines 213-231
    }
    cout << endl;

    // Test 19: ChatRoom findUserIndex success (lines 243-245)
    cout << "--- Test 19: Find User Index ---" << endl;
    {
        Dogorithm room;
        NormalUser user("FindMe");
        
        room.registerUser(&user);
        
        // isUserInRoom calls findUserIndex
        bool found = room.isUserInRoom(&user); // Hits lines 243-245
        cout << "User found: " << found << endl;
    }
    cout << endl;

    // Test 20: Command header constructors with different types
    cout << "--- Test 20: Command Header Constructors ---" << endl;
    {
        Dogorithm room;
        NormalUser norm("N");
        AdminUser adm("A");
        CoAdminUser coadm("C");
        
        room.registerUser(&norm);
        room.registerUser(&adm);
        room.registerUser(&coadm);
        
        string m1 = "msg1", m2 = "msg2", m3 = "msg3";
        
        // SaveMessageCommand with different user types
        SaveMessageCommand save1(m1, &room, &norm);
        SaveMessageCommand save2(m2, &room, &adm);
        SaveMessageCommand save3(m3, &room, &coadm);
        
        // SendMessageCommand with different user types
        SendMessageCommand send1(m1, &room, &norm);
        SendMessageCommand send2(m2, &room, &adm);
        SendMessageCommand send3(m3, &room, &coadm);
        
        // Execute them all
        save1.execute();
        send1.execute();
        save2.execute();
        send2.execute();
        save3.execute();
        send3.execute();
    }
    cout << endl;

    // Test 21: ChatRoom destructor - scope exit
    cout << "--- Test 21: ChatRoom Destructor ---" << endl;
    {
        Dogorithm* dynamicRoom = new Dogorithm();
        NormalUser user("TempUser");
        dynamicRoom->registerUser(&user);
        
        string msg = "temp message";
        dynamicRoom->sendMessage(&msg, &user);
        
        delete dynamicRoom; // Explicitly calls destructor (lines 19-32)
    }
    cout << endl;

    // Test 22: More admin/user interactions for remaining paths
    cout << "--- Test 22: Comprehensive Integration ---" << endl;
    {
        Dogorithm room;
        AdminUser admin("FinalAdmin");
        NormalUser u1("U1"), u2("U2"), u3("U3");
        
        room.registerUser(&admin);
        room.registerUser(&u1);
        room.registerUser(&u2);
        room.registerUser(&u3);
        
        // Various message scenarios
        u1.send("help I need admin assistance", &room);
        u2.send("This is an emergency and urgent", &room);
        u3.send("Someone just joined the room", &room);
        u1.send("What are the community rules and guidelines", &room);
        
        // Long message for auto-moderation
        u2.send(string(305, 'y'), &room);
        
        // Removal scenario
        admin.removeOtherUser(&u3, &room);
        
        // More messages after removal
        u1.send("Another message", &room);
        u2.send("Final message", &room);
    }
    cout << endl;

    // Test 23: All iterators with populated collections
    cout << "--- Test 23: Iterator Full Coverage ---" << endl;
    {
        Dogorithm room;
        NormalUser u1("I1"), u2("I2"), u3("I3");
        
        room.registerUser(&u1);
        room.registerUser(&u2);
        room.registerUser(&u3);
        
        u1.send("History 1", &room);
        u2.send("History 2", &room);
        u3.send("History 3", &room);
        
        // UserIterator full traversal
        UsersIterator uit = room.createUserIterator();
        for (uit.first(); !uit.isDone(); uit.next()) {
            Users* u = uit.current();
            if (u) cout << "User: " << u->getName() << endl;
        }
        
        // ChatHistoryIterator full traversal
        ChatHistoryIterator hit = room.createChatHistoryIterator();
        for (hit.first(); !hit.isDone(); hit.next()) {
            string* msg = hit.current();
            if (msg) cout << "History entry found" << endl;
        }
        
        // CommandIterator with commands
        string cmd = "command";
        SaveMessageCommand c1(cmd, &room, &u1);
        SaveMessageCommand c2(cmd, &room, &u2);
        u1.addCommand(&c1);
        u1.addCommand(&c2);
        
        CommandIterator cit = u1.createcommandIterator();
        for (cit.first(); !cit.isDone(); cit.next()) {
            Command* c = cit.current();
            if (c) cout << "Command found" << endl;
        }
    }
    cout << endl;

    cout << "=== FINAL TEST COMPLETE - 100% COVERAGE ===" << endl;
}

void runDemo() {
    demonstrateUserCreation();
        demonstrateChatRoomCreation();
        demonstrateUserRegistration();
        demonstrateMessaging();
        demonstrateAdminFunctions();
        demonstrateCommandPattern();
        //demonstrateIteratorPattern();
        demonstrateObserverPattern();
        demonstrateRoomThemes();
        demonstrateHistoryManagement();
        demonstrateCompleteScenario();
        
        printSeparator("ALL DEMOS COMPLETED SUCCESSFULLY!");
}


int main() {
    //runDemo();
    //runTest();
    demonstrateCompleteScenario();
    return 0;
}

