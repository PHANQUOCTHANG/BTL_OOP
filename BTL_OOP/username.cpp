#pragma once
#include "header.h"
#include "function.cpp"
string User::getUsername(){
    return this->Username;
}   
string User::getPassword(){
    return this->Password;
}
void User::setUsername(string &username){
    cout << "Enter username: ";
    cin >> username;
    this->Username = username;
}
void User::setPassword(string &password){
    cout << "Enter password: ";
    cin >> password;
    this->Password = password;
}