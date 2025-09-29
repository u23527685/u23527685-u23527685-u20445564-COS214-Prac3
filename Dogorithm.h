/**
 * @file [Dogorithm.h]
 * @brief [Concrete mediator header file for Dogorithm chat room]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */

#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"
#include <string>

using namespace std;

// Forward declaration
class Users;

/**
 * @class Dogorithm
 * @brief Concrete mediator for the Dogorithm themed chat room
 * 
 * This class implements the ChatRoom interface for a dog-themed programming chat room.
 * It provides a fun environment for users to discuss algorithms and programming 
 * with a canine twist! 🐶
 */
class Dogorithm : public ChatRoom {
    public:
        /**
         * @brief Constructor for Dogorithm room
         */
        Dogorithm();
        
        /**
         * @brief Destructor for Dogorithm room
         */
        ~Dogorithm();
        
        /**
         * @brief Register a user with the Dogorithm room
         * @param user Pointer to the user to register
         */
        void registerUser(Users* user) override;
        
        /**
         * @brief Send a message in the Dogorithm room
         * @param message Pointer to the message to send
         * @param fromUser Pointer to the user sending the message
         */
        void sendMessage(string* message, Users* fromUser) override;
        
        /**
         * @brief Remove a user from the Dogorithm room
         * @param user Pointer to the user to remove
         */
        void removeUser(Users* user) override;
        
        /**
         * @brief Get the name of the chat room
         * @return The name "Dogorithm"
         */
        string getRoomName() const override;
        
        /**
         * @brief Get Dogorithm-specific room theme message
         * @return Fun dog-themed welcome message
         */
        string getRoomTheme() const;
        
        /**
         * @brief Show daily dog fact (fun feature)
         * @return Random dog programming fact
         */
        string getDailyDogFact() const;
        
        /**
         * @brief Dogorithm-specific user welcome with dog puns
         * @param user The user to welcome
         */
        void welcomeUserWithDogPuns(Users* user);
        
        /**
         * @brief Check if message contains dog-related keywords
         * @param message The message to check
         * @return True if message is dog-themed
         */
        bool isDogThemed(const string& message) const;
        
        /**
         * @brief React to dog-themed messages with enthusiasm
         * @param message The dog-themed message
         * @param fromUser User who sent the message
         */
        void reactToDogMessage(const string& message, Users* fromUser);
};

#endif //DOGORITHM_H