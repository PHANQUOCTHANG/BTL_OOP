#pragma once //Giúp gọi hàm lần 
#include<bits/stdc++.h>
using namespace std;
class User{
    private:
       string Username,Password; 
    public:
        string getUsername();
        string getPassword();
        void setUsername(string &username);
        void setPassword(string &password);

};
