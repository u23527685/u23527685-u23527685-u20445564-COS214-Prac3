#ifndef COMMAND_H
#define COMMAND_H

using namespace std;
#include <string>

class User;
class Command;

class ChatRoom{
    private:
        User* users;
        string* chatHistory;
    
    public:
        ChatRoom();
        void sendMessage( string message, User fromUser);
        void saveMessage( string message, User fromUser);

};

class User{
    protected:
        ChatRoom* chatRooms;
        string name;
        Command** commandQueue;
    public:
        User(string n, ChatRoom* cr);
        void receive(string message, User fromUser, ChatRoom room);
        void addCommand(Command command);
        void executeAll();
};

class Command{
    protected:
        string message;
        ChatRoom room;
        User fromUser;

    public:
        virtual void execute()=0;

};

#endif