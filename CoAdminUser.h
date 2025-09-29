/**
 * @file [CoAdminUser.h]
 * @brief [Co-admin user class with partial administrative privileges]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#ifndef COADMINUSER_H
#define COADMINUSER_H

#include <string>
#include "Users.h"
#include "ChatRoom.h"  // Forward declaration needed
#include "Command.h"   // Forward declaration needed

using namespace std;

/**
 * @class CoAdminUser
 * @brief Concrete user class with co-administrative privileges
 * 
 * CoAdminUsers have some elevated capabilities but less than full admins.
 */
class CoAdminUser : public Users {
    public:
        /**
         * @brief Default constructor for CoAdminUser
         */
        CoAdminUser();
        
        /**
         * @brief Constructor with name parameter
         * @param userName The name of the co-admin user
         */
        CoAdminUser(const string& userName);
        
        /**
         * @brief Destructor
         */
        ~CoAdminUser();
        
        /**
         * @brief Send a message to a chat room
         * @param message The message to send
         * @param room Pointer to the chat room (should be pointer)
         */
        void send(const string& message, ChatRoom* room) override;
        
        /**
         * @brief Receive a message from a chat room
         * @param message The received message
         * @param fromUser Pointer to the user who sent the message (should be pointer)
         * @param room Pointer to the chat room the message came from (should be pointer)
         */
        void receive(const string& message, Users* fromUser, ChatRoom* room) override;
        
        /**
         * @brief Add a command to the queue
         * @param command Pointer to the command to add (should be pointer)
         */
        void addCommand(Command* command) override;
        
        /**
         * @brief Execute all queued commands
         */
        void executeAll() override;
        
        /**
         * @brief Get user type as string
         * @return "Co-Admin"
         */
        string getUserType() const override;
        
        /**
         * @brief Get the user's name
         * @return The user's name
         */
        string getName() const override;
        
        /**
         * @brief Assist with moderation (co-admin specific function)
         * @param message The message to assist with
         * @param room The room where assistance occurs
         */
        void assistModeration(const string& message, ChatRoom* room);
};

#endif //COADMINUSER_H