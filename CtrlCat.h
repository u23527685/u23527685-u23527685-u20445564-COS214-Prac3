
/**
 * @file [CtrlCat.h]
 * @brief [Concrete mediator for CtrlCat chat room]
 * @author [Marodi Jessica]
 * @date [2025-09-24]
 */
#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "ChatRoom.h"
class Users;
/**
 * @class CtrlCat
 * @brief Concrete mediator for the CtrlCat themed chat room
 *
 * This class implements the ChatRoom interface for a cat-themed chat room.
 */
#include <string>
using namespace std;

class CtrlCat : public ChatRoom
{
public:
    /**
     * @brief Constructor for CtrlCat room
     */
    CtrlCat();

    /**
     * @brief Deconstructor for CtrlCar
     */
    ~CtrlCat();
    /**
     * @brief Register a user with the CtrlCat room
     * @param user Pointer to the user to register
     */
    void registerUser(Users *user);

    /**
     * @brief send a message to all the other users in the room
     * @param message the message that is to be sent
     * @param fromUser the user who sent the message
     */
    void sendMessage(string *message, Users *fromUser);
    /**
     * @brief Remove a user from the CtrlCat room
     * @param user Pointer to the user to remove
     */
    void removeUser(Users *user);
    /**
     * @brief Get the name of the chat room
     * @return The name "CtrlCat"
     */
    string getRoomName() const override;
    
    /**
     * @brief [Get the theme description of the CtrlCat room]
     * @return [A string containing the room's theme description]
     */
    string getRoomTheme() const;

    /**
     * @brief [Get a daily fun cat fact]
     * @return [A string containing a cat fact]
     */
    string getDailyCatFact() const;

    /**
     * @brief [Welcome a new user with cat-themed puns]
     * @param user [Pointer to the user being welcomed]
     */
    void welcomeUserWithCatPuns(Users* user);

    /**
     * @brief [Check if a message is cat-themed]
     * @param message [The message string to check]
     * @return [true if the message contains cat-related words, false otherwise]
     */
    bool isCatThemed(const string& message);

    /**
     * @brief [React to a cat-themed message]
     * @param message [The content of the message]
     * @param fromUser [Pointer to the user who sent the message]
     */
    void reactToCatMessage(const string& message, Users* fromUser);
  
};

#endif // CTRLCAT_H

