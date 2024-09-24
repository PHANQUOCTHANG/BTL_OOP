#pragma once
#include "User.h"

//Show Menu
void User::userMenu(){
            cout<<"+-------------------"<<"\033[35m"<<"User"<<"\033[0m"<<"---------------------+\n";
  cout << "|    1. Buy Drug                             |\n";
  cout << "|    2. User Profile Management              |\n";
  cout << "|    3. Discounts                            |\n";
  cout << "|    4. Log out                              |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";


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
    User tokens=findUserByUsername("Account_mangement/Account/Information",this->getAccountName());
    if(tokens.getName() != ""){
        this->setCheck(1);
    }
    else{
        this->setCheck(0);
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
        userMenu();
        cin>>choice;
        switch (choice){
        
        case 1:{
            system("cls");
            if(!this->getCheck()){
                cout<<"\033[33m"  <<"Please update your infomation to buy!"<<endl;
                cout<<"Do you want update your information now ? (Y/N)"<<"\033[0m"; cin>>rep;
                rep=toupper(rep);
                if(rep=='Y'){
                    system("cls");
                    this->update();
                    break;
                }
                else{
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
        delay(1000);

    }




}



