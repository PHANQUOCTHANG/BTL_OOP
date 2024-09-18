#pragma once
#include "Account.h"
#include "../Header.h"
#include "../Design/Interaction.cpp"
#include "../function.cpp"

//Geter
string Account::getAccountName(){
    return this->accountName;
}   
//Geter

string Account::getAccountPassword(){
    return this->accountPassword;
}

//define ADMIN account

string Account::adminName="admin";
string Account::adminPassword="admin";


//Check tên tài khoản đã tồn tại chưa
bool isExistUsername(const string& name){
        ifstream file("Account_mangement/Account/User.txt");
    if (!file.is_open()) {
        cout << "\033[31m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    string storedName;
    while (file >> storedName) {
        if (storedName == name) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
//Set Tên tài khoản
void Account::setAccountName(string accountName){
    cout <<"\033[36m"<< "Enter username: "<<"\033[0m";
    cin >> accountName;
    this->accountName = accountName;
}
//Set Mật khẩu
void Account::setAccountPassword(string accountName){
    cout <<"\033[36m"<< "Enter password: "<<"\033[0m";
    this->accountPassword = hidePassword(accountName);
}

//Set Tạo tài khoản mới
bool Account::setAccountRegister(string accountName,string accountPassword){
    char res;
    string verify;
    do
    {
        //check username
        do
        {
            cout <<"\033[36m"<< "Enter username: "<<"\033[0m";
            cin >> accountName;
            if(isExistUsername(accountName)){
                cout<< "\033[31m"<<"Username has exist !"<< "\033[0m"<<endl;
                cout<<"\033[33m"<<"Do you want continue ! (Y/N)"<<"\033[0m"<<endl;
                cin>>res;
                res=toupper(res);
                if(res!='Y') return 0;
                delay(2000);
                system("cls");
                cout<<"\033[36m"<<"Register: "<<"\033[0m"<<endl;

            }
            /* code */
        } while (isExistUsername(accountName));
        this->accountName = accountName;

        
        //check match password
        cout << "\033[36m"<<"Enter password: "<<"\033[0m";
        this->accountPassword = hidePassword(accountPassword);
        cout <<"\033[36m"<< "Confirm password: "<<"\033[0m";
        hidePassword(verify);
        if(verify != accountPassword){
            cout<<"\033[31m"<<"Password does not mactch!"<<"\033[0m"<<endl;
            cout<<"\033[33m"<<"Do you want continue ! (Y/N)"<<"\033[0m"<<endl;
            cin>>res;
            res=toupper(res);
            if(res!='Y') return 0;
            delay(2000);
            system("cls");
            cout<<"\033[36m"<<"Register: "<<"\033[0m"<<endl;
        }
    } while (verify != accountPassword);
    return 1;
}

// Tạo tài khoản mới
void Account::Register(){
    string accountName,accountPassword;
    cout<<"\033[36m"<<"Register: "<<"\033[0m"<<endl;
    if(!setAccountRegister(accountName,accountPassword)) return;
    if (registerUser("Account_mangement/Account/User.txt",accountName, accountPassword)) {
        cout << "\033[32m" << "Registration successful!" << "\033[0m" <<endl;
    } else {
        cout << "\033[31m" << "Registration failed!" << "\033[0m" <<endl;
    }
}

//Menu Login
bool Account::Login(){
    string choice;
    string accountName, accountPassword;

    while (1)
    {
        adminMode=0;
        showMenuLogin();
        cin>>choice;
        system("cls");
        if (choice == "1") {
            do{
                cout<<"\033[36m"<<"Login as a User: "<<"\033[0m"<<endl;
                setAccountName(accountName);
                setAccountPassword(accountPassword);
                if(!loginUser("Account_mangement/Account/User.txt",this->accountName,this-> accountPassword)){
                    cout << "\033[31m" << "Invalid username or password!" << "\033[0m" << endl;
                    char rep;
                    cout << "\033[33m" << "Do you want back (Y/N)?--> " << "\033[0m";
                    cin>>rep;
                    rep=toupper(rep);
                    if(rep=='Y') break;
                    system("cls");
                }
            }
            while(!loginUser("Account_mangement/Account/User.txt",this->accountName,this->accountPassword));
            if (loginUser("Account_mangement/Account/User.txt",this->accountName,this->accountPassword)) {
                cout << "\033[32m" << "Login successful!" << "\033[0m" << endl;
                cout << "\033[33m" << "Now you are a User ! Press Enter to continue !" << "\033[0m" << endl;
                std::cin.ignore();  // Bỏ qua bất kỳ ký tự nào đã có sẵn trong bộ đệm
                std::cin.get();     // Đợi người dùng nhấn Enter
                return 1;             
            }
            
        } else if (choice == "2") {
            adminMode=1;
            do{
                cout<<"\033[36m"<<"Login as a Admin: "<<"\033[0m"<<endl;
                setAccountName(accountName);
                setAccountPassword(accountPassword);
                if(this->accountName != adminName || this->accountPassword != adminPassword){
                    cout << "\033[31m" << "Invalid adminName or adminPassword!" << "\033[0m" << endl;
                    char rep;
                    cout << "\033[33m" << "Do you want back (Y/N)?--> " << "\033[0m";
                    cin>>rep;
                    rep=toupper(rep);
                    if(rep=='Y') break;
                    system("cls");
                }
            }
            while(this->accountName != this->adminName || this->accountPassword != this->adminPassword);
            if (this->accountName == this->adminName && this->accountPassword == this->adminPassword) {
                cout << "\033[32m" << "Login successful!" << "\033[0m" << endl;
                cout << "\033[33m" << "Now you are a Admin ! Press Enter to continue !" << "\033[0m" << endl;
                std::cin.ignore();  // Bỏ qua bất kỳ ký tự nào đã có sẵn trong bộ đệm
                std::cin.get();     // Đợi người dùng nhấn Enter
                return 1;
            }
        } else if(choice=="3") {
            return 0;
        } else {
            cout << "\033[31m" <<"Invalid choice!" << "\033[0m" << endl;
            delay(2000);
        }

        system("cls");
    }
    


}