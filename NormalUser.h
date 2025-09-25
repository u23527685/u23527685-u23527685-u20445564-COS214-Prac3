/**
 * @file [NormalUser.h]
 * @brief [Normal user class header implementation with standard privileges]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#ifndef NORMALUSER_H
#define NORMALUSER_H

#include <string>
#include "Users.h"
#include "ChatRoom.h"  // Forward declaration needed
#include "Command.h"   // Forward declaration needed

using namespace std;

/**
 * @class NormalUser
 * @brief Concrete user class with standard user privileges
 * 
 * NormalUsers have basic chat functionality without special privileges.
 */
class NormalUser : public Users {
private:
    // Note: These should be inherited from Users base class
    // Remove if they're already in Users class
    ChatRoom* chatRooms;
    string name;
    Command* commandQueue;

public:
    /**
     * @brief Default constructor for NormalUser
     */
    NormalUser();
    
    /**
     * @brief Constructor with name parameter
     * @param userName The name of the normal user
     */
    NormalUser(const string& userName);
    
    /**
     * @brief Destructor
     */
    ~NormalUser();
    
    /**
     * @brief Send a message to a chat room
     * @param message The message to send
     * @param room Pointer to the chat room (should be pointer)
     */
    void send(const string& message, ChatRoom* room);
    
    /**
     * @brief Receive a message from a chat room
     * @param message The received message
     * @param fromUser Pointer to the user who sent the message (should be pointer)
     * @param room Pointer to the chat room the message came from (should be pointer)
     */
    void receive(const string& message, Users* fromUser, ChatRoom* room);
    
    /**
     * @brief Add a command to the queue
     * @param command Pointer to the command to add (should be pointer)
     */
    void addCommand(Command* command);
    
    /**
     * @brief Execute all queued commands
     */
    void executeAll();
    
    /**
     * @brief Get user type as string
     * @return "Normal"
     */
    string getUserType() const override;
    
    /**
     * @brief Get the user's name
     * @return The user's name
     */
    string getName() const ;
};

#endif // NORMALUSER_H