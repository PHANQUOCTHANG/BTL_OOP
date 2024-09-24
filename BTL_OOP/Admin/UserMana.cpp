#pragma once
#include "Admin.h"


//Show Menu
void Admin::userManaMenu1(){
                cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. Show                                 |\n";
  cout << "|    2. Add Users                            |\n";
  cout << "|    3. Remove Users                         |\n";
  cout << "|    4. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";
}


//Menu  tổng
void Admin::userManaProcess(){
  int choice;
  while (1)
  {
    
    userManaMenu1();
    cin>>choice;
    vector<pair<string,string>> tempAdmin = Account::loadUserInfo("Account_mangement/Account/User.txt");
    switch (choice){
      
      case 1:{
        system("cls");
        Title2();
        for(auto x:tempAdmin){
          printListAccount(x);
        }
        break;
      }
      case 2:
      {
        
          system("cls");
          Account p;
          p.Register();
          delay(2000);
        break;
      }
      case 3:
      {
        string userName;
        cout<<"\033[36m"<<"Enter username which you want remove: "<<"\033[0m"; cin>>userName;
        Account::removedAccount(userName,"Account_mangement/Account/User.txt"); 
        delay(1000);
        system("cls");
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