#pragma once
#include "../Header.h"
#include "../Design/Interaction.cpp"
#include "../function.cpp"
string Account::getAccountName(){
    return this->accountName;
}   
string Account::getAccountPassword(){
    return this->accountPassword;
}
void Account::setAccountName(string &accountName){
    cout << "Enter username: ";
    cin >> accountName;
    this->accountName = accountName;
}
void Account::setAccountPassword(string &accountPassword){
    cout << "Enter password: ";
    this->accountPassword = hidePassword(accountPassword);
}
void Account::Register(){
    string accountName,accountPassword;
    cout<<"\033[32m"<<"Register: "<<"\033[0m"<<endl;
    setAccountName(accountName);
    setAccountPassword(accountPassword);
    if (registerUser(accountName, accountPassword)) {
        cout << "\033[33m" << "Registration successful!" << "\033[0m" <<endl;
    } else {
        cout << "\033[33m" << "Registration failed!" << "\033[0m" <<endl;
    }
}
bool Account::Login(){
    string choice;
    string accountName, accountPassword;

    while (1)
    {
        showMenuLogin();
        cin>>choice;
        system("cls");
        if (choice == "1") {
            do{
                cout<<"\033[32m"<<"Login as a User: "<<"\033[0m"<<endl;
                setAccountName(accountName);
                setAccountPassword(accountPassword);
                if(!loginUser(accountName, accountPassword)){
                    cout << "\033[33m" << "Invalid username or password!" << "\033[0m" << endl;
                    char rep;
                    cout << "\033[33m" << "Do you want back (Y/N)?--> " << "\033[0m";
                    cin>>rep;
                    rep=toupper(rep);
                    if(rep=='Y') break;
                    system("cls");
                }
            }
            while(!loginUser(accountName, accountPassword));
            if (loginUser(accountName, accountPassword)) {
                cout << "\033[33m" << "Login successful!" << "\033[0m" << endl;
                cout << "\033[33m" << "Now you are a User ! Press Enter to continue !" << "\033[0m" << endl;
                std::cin.ignore();  // Bỏ qua bất kỳ ký tự nào đã có sẵn trong bộ đệm
                std::cin.get();     // Đợi người dùng nhấn Enter
                return 1;             
            }
            
        } else if (choice == "2") {
            Admin temp;
            do{
                cout<<"\033[32m"<<"Login as a Admin: "<<"\033[0m"<<endl;
                setAccountName(accountName);
                setAccountPassword(accountPassword);
                if(this->accountName != temp.getAdminName() || this->accountPassword != temp.getadminPassword()){
                    cout << "\033[33m" << "Invalid adminName or adminPassword!" << "\033[0m" << endl;
                    char rep;
                    cout << "\033[33m" << "Do you want back (Y/N)?--> " << "\033[0m";
                    cin>>rep;
                    rep=toupper(rep);
                    if(rep=='Y') break;
                    system("cls");
                }
            }
            while(this->accountName != temp.getAdminName() || this->accountPassword != temp.getadminPassword());
            if (accountName == temp.getAdminName() && accountPassword == temp.getadminPassword()) {
                cout << "\033[33m" << "Login successful!" << "\033[0m" << endl;
                cout << "\033[33m" << "Now you are a Admin ! Press Enter to continue !" << "\033[0m" << endl;
                std::cin.ignore();  // Bỏ qua bất kỳ ký tự nào đã có sẵn trong bộ đệm
                std::cin.get();     // Đợi người dùng nhấn Enter
                return 1;
            }
        } else if(choice=="3") {
            return 0;
        } else {
            cout << "\033[33m" <<"Invalid choice!" << "\033[0m" << endl;
            delay(2000);
        }

        system("cls");
    }
    


}