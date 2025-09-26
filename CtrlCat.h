/**
 * @file [CtrlCat.h]
 * @brief [Concrete mediator for CtrlCat chat room]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */
#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "Users.h"
#include "ChatRoom.h"
/**
 * @class CtrlCat
 * @brief Concrete mediator for the CtrlCat themed chat room
 * 
 * This class implements the ChatRoom interface for a cat-themed chat room.
 */
#include <string>
using namespace std;

class CtrlCat : public ChatRoom {
    public:
        /**
         * @brief Constructor for CtrlCat room
         */
        CtrlCat();
        ~CtrlCat();
        /**
         * @brief Register a user with the CtrlCat room
         * @param user Pointer to the user to register
         */
        void registerUser(Users* user);
        void sendMessage(string* message, Users* fromUser);
        /**
         * @brief Remove a user from the CtrlCat room
         * @param user Pointer to the user to remove
         */
        void removeUser(Users* user);
        /**
         * @brief Get the name of the chat room
         * @return The name "CtrlCat"
         */
        string getRoomName() const override;
        void saveMessage(const string& message, Users* fromUser);
};


#endif //CTRLCAT_H