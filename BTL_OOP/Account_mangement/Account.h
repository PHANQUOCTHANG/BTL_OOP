#pragma once
#include "../Header.h"
class Account{
    private:
       string accountName,accountPassword; 
       static string adminName,adminPassword;
    public:   
        string getAccountName();
        string getAccountPassword();
        void setAccountName(string accountName);
        void setAccountPassword(string accountPassword);
        void setUserName(string accountName){
            this->accountName = accountName;
        }
        void setUserPassword(string accountPassword){
            this->accountPassword = accountPassword;
        }
        bool setAccountRegister(string accountName,string accountPassword);
        void Register();
        bool Login();
        string getAdminName();
        string getadminPassword();
        friend void accountProcess();
};