#pragma once
#include "header.h"
#include "function.cpp"
string User::getUsername(){
    return this->username;
}   
string User::getPassword(){
    return this->password;
}
void User::setUsername(string &username){
    cout << "Enter username: ";
    cin >> username;
    this->username = username;
}
void User::setPassword(string &password){
    cout << "Enter password: ";
    cin >> password;
    this->password = password;
}