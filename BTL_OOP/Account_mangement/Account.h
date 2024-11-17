#pragma once
#include "../extra_function/Header.h"


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
        static void removedAccount(const string &userName,const string &fileName);
        static vector<vector<string>> loadUserInfo(const std::string& filename) ;
        static void updateStatus(const string &accountName, const string &status,const string &fileName);
        static void accountProcess();
};

bool isExistUsername(const string& name); //Kiểm tra tài khoản đã tồn tại chưa