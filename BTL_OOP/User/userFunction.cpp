#pragma once
#include "User.h"

//Show Menu
void User::userMenu(int selection)
{
    system("cls");
    tab();
    cout << "+-------------" << "\033[35m" << "USER SELECTION" << "\033[0m" << "-----------+\n";
    // Mục 1: User
    tab();
    cout << "|" << (selection == 1 ? "\033[38;5;214m ->         1. Buy Drug               \033[0m|\n" 
                                    : "             1. Buy Drug              |\n");
    // Mục 2: Admin
    tab();
    cout << "|" << (selection == 2 ? "\033[38;5;214m ->         2. User Profile           \033[0m|\n" 
                                    : "             2. User Profile          |\n");
    // Mục 3: Back
    tab();
    cout << "|" << (selection == 3 ? "\033[38;5;214m ->         3. Discounts              \033[0m|\n" 
                                    : "             3. Discounts             |\n");
    tab();
    cout << "|" << (selection == 4 ? "\033[38;5;214m ->         4. Log out                \033[0m|\n"
                                    : "             4. Log out               |\n");
    tab();
    cout << "+--------------------------------------+\n";
    tab();
    cout << "\t  \033[32mUSE \033[1;35mUP\033[0m" 
     << "\033[32m/\033[1;35mDOWN\033[0m" 
     << "\033[32m TO SELECT\033[0m" << endl;
}

//Menu tổng
void User::userProcess(){
    vector<Drug > temp = Drug::readFromFile("drugStore/wareHouse.txt");
    for(int i=0;i<temp.size();++i){
        if(temp[i].getQuantityInStock() <= 0){
            Drug a=temp[i];
            a.setOOT(1);
            Drug::updateDrugInFile(i+1,a,"drugStore/wareHouse.txt");
        }
    }
    int choice;
    string fileName3="Account_mangement/Account/userInfor/";
    fileName3+=this->getAccountName()+"infor.txt";
    createFileIfNotExists(fileName3);
    vector<User> tokens=findUserByUsername(fileName3,this->getAccountName());
    if(!tokens.size()){
        this->setCheck(0);
    }
    else{
        this->setCheck(1);
    }
    string fileName1="Transactions/usesHistory/";
    fileName1+=this->getAccountName()+".txt";
    string fileName2="Transactions/usesHistory/";
    fileName2+=this->getAccountName()+"cart.txt";
    createFileIfNotExists(fileName1);
    createFileIfNotExists(fileName2);
    char rep;
    while (1)
    {
        int selection = 1;  // Start with the first option selected
        char key;
        do {
            userMenu(selection);
            key = _getch();  // Get a single character input
            if (key == 72) {  // Up arrow key code
                selection--;
                if (selection < 1) selection = 4;
            } else if (key == 80) {  // Down arrow key code
                selection++;
                if (selection > 4) selection = 1;
            }
        } while (key != '\r');  // Continue until the Enter key is pressed
        choice = selection;
        switch (choice){
        
            case 1:{
                system("cls");
                if(!this->getCheck()){
                    cout<<"\033[33m"  <<"Please update your infomation to buy!"<<endl;
                    cout<<"Do you want update your information now ? [Y/N] : "<<"\033[0m"; cin>>rep;
                    rep=toupper(rep);
                    if(rep=='Y'){
                        system("cls");
                        this->update();
                        break;
                    }
                    else{
                        system("cls");
                        continue;;
                    }
                }
                userBuyDrugProcess();
                break;
            }
            case 2:
            {
                system("cls");
                userInfoProcess();
                break;
            }
            case 3:
            {
                system("cls");
                userDiscountProcess();
                break;
            }
            case 4:
            {
                system("cls");
                return;
            }
            default:{
                cout<<"\033[31m"  <<"Invalid selection"<<"\033[0m"<<endl;
                break;
            }
        }

    }

}



