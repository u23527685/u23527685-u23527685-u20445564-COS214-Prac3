
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

void runTest(){
    cout << "=== FINAL 100% COVERAGE TEST ===" << endl;
    cout << endl;

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
    cout << "=== Automated Demo: Chat System Showcase ===" << endl;

    // 1) Create two themed chat rooms
    CtrlCat catRoom;
    Dogorithm dogRoom;
    cout << "Created rooms: " << catRoom.getRoomName() << " and " << dogRoom.getRoomName() << endl;

    // 2) Create users (stack objects, as requested)
    AdminUser    admin("Alice");
    CoAdminUser  coadmin("Bob");
    NormalUser   user1("Charlie");
    NormalUser   user2("Dana");

    // 3) Register users to rooms
    catRoom.registerUser(&admin);
    catRoom.registerUser(&coadmin);
    catRoom.registerUser(&user1);
    catRoom.registerUser(&user2);

    dogRoom.registerUser(&admin);
    dogRoom.registerUser(&coadmin);
    dogRoom.registerUser(&user1);
    dogRoom.registerUser(&user2);

    // Also link rooms to users (so their room iterators have content)
    admin.addChatRoom(&catRoom);
    admin.addChatRoom(&dogRoom);
    coadmin.addChatRoom(&catRoom);
    coadmin.addChatRoom(&dogRoom);
    user1.addChatRoom(&catRoom);
    user1.addChatRoom(&dogRoom);
    user2.addChatRoom(&catRoom);
    user2.addChatRoom(&dogRoom);

    // 4) Iterate users in catRoom (UsersIterator)
    {
        cout << "\n-- Users in " << catRoom.getRoomName() << " --" << endl;
        UsersIterator uit = catRoom.createUserIterator();
        for (uit.first(); !uit.isDone(); uit.next()) {
            Users* u = uit.current();
            if (u) {
                cout << "User[" << uit.getIndex() << "]: " << u->getName() << " (" << u->getUserType() << ")" << endl;
            }
        }
    }

    // 5) Queue commands (Send + Save) and then execute them for each user
    //    We'll demonstrate both rooms to show command execution and room-specific behavior.
    {
        cout << "\n-- Queue and execute commands in " << catRoom.getRoomName() << " --" << endl;

        // Prepare messages
        string m1 = "hello cats!";
        string m2 = "this will be saved to history";
        string m3 = "[ADMIN] system notice for everyone";
        string m4 = "[CO-ADMIN] reminder: be nice";

        // Create command objects (stack) and add to each user's command queue
        SendMessageCommand u1_send_cat(m1, &catRoom, &user1);
        SaveMessageCommand u1_save_cat(m2, &catRoom, &user1);
        user1.addCommand(&u1_send_cat);
        user1.addCommand(&u1_save_cat);

        SendMessageCommand u2_send_cat(m1, &catRoom, &user2);
        SaveMessageCommand u2_save_cat(m2, &catRoom, &user2);
        user2.addCommand(&u2_send_cat);
        user2.addCommand(&u2_save_cat);

        SendMessageCommand admin_send_cat(m3, &catRoom, &admin);
        SaveMessageCommand admin_save_cat(m2, &catRoom, &admin);
        admin.addCommand(&admin_send_cat);
        admin.addCommand(&admin_save_cat);

        SendMessageCommand co_send_cat(m4, &catRoom, &coadmin);
        SaveMessageCommand co_save_cat(m2, &catRoom, &coadmin);
        coadmin.addCommand(&co_send_cat);
        coadmin.addCommand(&co_save_cat);

        // Show commands queued for one user via CommandIterator (before execution)
        {
            cout << "Commands queued for " << user1.getName() << ":" << endl;
            CommandIterator cit = user1.createcommandIterator();
            for (cit.first(); !cit.isDone(); cit.next()) {
                Command* c = cit.current();
                cout << "  Command index " << cit.getIndex() << (c ? "" : " (null)") << endl;
            }
        }

        // Execute all commands per user
        admin.executeAll();
        coadmin.executeAll();
        user1.executeAll();
        user2.executeAll();
    }

    // 6) Iterate chat history in catRoom (ChatHistoryIterator)
    {
        cout << "\n-- Chat history in " << catRoom.getRoomName() << " --" << endl;
        ChatHistoryIterator hit = catRoom.createChatHistoryIterator();
        for (hit.first(); !hit.isDone(); hit.next()) {
            string* msg = hit.current();
            cout << "History[" << hit.getIndex() << "]: " << (msg ? *msg : string("<null>")) << endl;
        }
        cout << "\nRoom stats:\n" << catRoom.getRoomStats() << endl;
    }

    // 7) Demonstrate direct sending on dogRoom using Users::send (bypassing command queue)
    {
        cout << "\n-- Direct sends in " << dogRoom.getRoomName() << " --" << endl;
        admin.send("[ADMIN] please welcome new members", &dogRoom);
        coadmin.send("[CO-ADMIN] enjoy dog memes!", &dogRoom);
        user1.send("woof woof hello dog lovers", &dogRoom);
        user2.send("dogs > cats? discuss!", &dogRoom);

        // Iterate users in dogRoom
        cout << "\nUsers in " << dogRoom.getRoomName() << ":" << endl;
        UsersIterator uit2 = dogRoom.createUserIterator();
        for (uit2.first(); !uit2.isDone(); uit2.next()) {
            Users* u = uit2.current();
            if (u) {
                cout << "User[" << uit2.getIndex() << "]: " << u->getName() << " (" << u->getUserType() << ")" << endl;
            }
        }

        // Iterate chat history of dogRoom
        cout << "\nHistory of " << dogRoom.getRoomName() << ":" << endl;
        ChatHistoryIterator hit2 = dogRoom.createChatHistoryIterator();
        for (hit2.first(); !hit2.isDone(); hit2.next()) {
            string* msg = hit2.current();
            cout << "History[" << hit2.getIndex() << "]: " << (msg ? *msg : string("<null>")) << endl;
        }
    }

    // 8) For a user, iterate their joined rooms (ChatRoomIterator)
    {
        cout << "\n-- Rooms joined by " << admin.getName() << " --" << endl;
        ChatRoomIterator rit = admin.createIterator();
        for (rit.first(); !rit.isDone(); rit.next()) {
            ChatRoom* r = rit.current();
            cout << "Room[" << rit.getIndex() << "]: " << (r ? r->getRoomName() : string("<null>")) << endl;
        }
    }

    cout << "\n=== Demo complete ===" << endl;
}


int main() {
    runDemo();
    runTest();
    return 0;
}

