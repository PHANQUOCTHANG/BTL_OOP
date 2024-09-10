#pragma once //Giúp gọi hàm lần 
#include<bits/stdc++.h>
#include <conio.h>
using namespace std;


class Account{
    private:
       string accountName,accountPassword; 
    public:
        string getAccountName();
        string getAccountPassword();
        void setAccountName(string &accountName);
        void setAccountPassword(string &accountPassword);
        void Register();
        bool Login();
        friend void accountProcess();
};
class Admin:public Account{
    private:
        bool key;
        
    public:
        Admin(){
            this->key = 0;
        }
        void setKey(){
            this->key = 1;
        }
        string getAdminName(){
            return this->adminName;
        }
        string getadminPassword(){
            return this->adminPassword;
        }
    protected:
       const string adminName="admin",
                    adminPassword="admin";

};
class User:public Account{
    
};
