#pragma once //Giúp gọi hàm lần 
#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
class Account{
    private:
       string accountName,accountPassword; 
       static string adminName,adminPassword;
    public:   
        string getAccountName();
        string getAccountPassword();
        void setAccountName(string &accountName);
        void setAccountPassword(string &accountPassword);
        bool setAccountRegister(string &accountName,string &accountPassword);
        void Register();
        bool Login();
        string getAdminName();
        string getadminPassword();
        friend void accountProcess();
};
struct Date
{
    int Day,Month,Year;
};
