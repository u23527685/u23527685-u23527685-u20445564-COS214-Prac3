
/**
 * @file [AdminUser.h]
 * @brief [Admin user class with elevated privileges]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#ifndef ADMINUSER_H
#define ADMINUSER_H

#include <string>
#include "Users.h"

using namespace std;

// Forward declarations
class ChatRoom;
class Command;

/**
 * @class AdminUser
 * @brief Concrete user class with administrative privileges
 * 
 * AdminUsers have special capabilities like moderating messages and managing users.
 */
class AdminUser : public Users {
    // Remove private members - they're inherited from Users base class
    // private:
    //     ChatRoom* chatRooms;     // Already in Users base class
    //     string name;             // Already in Users base class  
    //     Command* commandQueue;   // Already in Users base class

public:
    /**
     * @brief Default constructor for AdminUser
     */
    AdminUser();
    
    /**
     * @brief Constructor with name parameter
     * @param userName The name of the admin user
     */
    AdminUser(const string& userName);
    
    /**
     * @brief Destructor
     */
    ~AdminUser();
    
    /**
     * @brief Send a message to a chat room (with admin prefix)
     * @param message The message to send
     * @param room Pointer to the chat room (corrected to pointer)
     */
    void send(const string& message, ChatRoom* room) override;
    
    /**
     * @brief Receive a message from a chat room
     * @param message The received message
     * @param fromUser Pointer to the user who sent the message (corrected to pointer)
     * @param room Pointer to the chat room (corrected to pointer)
     */
    void receive(const string& message, Users* fromUser, ChatRoom* room) override;
    
    /**
     * @brief Add a command to the queue
     * @param command Pointer to the command to add (corrected to pointer)
     */
    void addCommand(Command* command) override;
    
    /**
     * @brief Execute all queued commands
     */
    void executeAll() override;
    
    /**
     * @brief Get user type as string
     * @return "Admin"
     */
    string getUserType() const override;
    
    /**
     * @brief Moderate a message (admin-specific function)
     * @param message The message to moderate
     * @param room The room where moderation occurs
     */
    void moderateMessage(const string& message, ChatRoom* room);
    
    /**
     * @brief Remove a user from a room (admin privilege)
     * @param user The user to remove
     * @param room The room to remove them from
     */
    void removeOtherUser(Users* user, ChatRoom* room);
    
    /**
     * @brief Announce a message to all users in room (admin privilege)
     * @param announcement The announcement to make
     * @param room The room to announce in
     */
    void makeAnnouncement(const string& announcement, ChatRoom* room);

private:
    /**
     * @brief Process admin alerts and priority messages
     * @param message The message to process
     * @param fromUser User who sent the message
     * @param room The chat room
     */
    void processAdminAlerts(const string& message, Users* fromUser, ChatRoom* room);
    
    /**
     * @brief Perform automatic content moderation
     * @param message The message to check
     * @param fromUser User who sent the message
     * @param room The chat room
     */
    void performContentModeration(const string& message, Users* fromUser, ChatRoom* room);
    
    /**
     * @brief Handle user requests and auto-responses
     * @param message The message to analyze
     * @param fromUser User who sent the message
     * @param room The chat room
     */
    void handleUserRequests(const string& message, Users* fromUser, ChatRoom* room);
    
    /**
     * @brief Get current timestamp (simulation)
     * @return Simple timestamp string
     */
    string getCurrentTime() const;
};

#endif //ADMINUSER_H