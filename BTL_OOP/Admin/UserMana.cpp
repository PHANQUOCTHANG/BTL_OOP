#pragma once
#include "Admin.h"


//Show Menu
void Admin::userManaMenu1(){
                cout<<"+----------------"<<"\033[35m"<<"USER MANAGER"<<"\033[0m"<<"----------------+\n";
  cout << "|    1. Show                                 |\n";
  cout << "|    2. Add Users                            |\n";
  cout << "|    3. Black List                           |\n";
  cout << "|    4. Remove Users                         |\n";
  cout << "|    5. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";
}
void BlackListMenu(){
                  cout<<"+-----------------"<<"\033[35m"<<"BLACK LIST"<<"\033[0m"<<"-----------------+\n";
  cout << "|    1. Show                                 |\n";
  cout << "|    2. Add                                  |\n";
  cout << "|    3. Remove                               |\n";
  cout << "|    4. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";



}

void BlackListProcess(){
  int choice;
  while (1)
  {
    
    BlackListMenu();
    cin>>choice;
    vector<vector<string>> tempAdmin = Account::loadUserInfo("Account_mangement/Account/User.txt");
    switch (choice){
      
      case 1:{
        system("cls");
        Title2();
        for(auto x:tempAdmin){
          if(x[2] == "0"){
            printListAccount(x);
          }
        }
        
        break;
      }
      case 2:
      {
        system("cls");
          string AccountName;
          cout<<"\033[36m"<<"Enter username which you want add to Black List: "<<"\033[0m"; cin>>AccountName;
          if(!isExistUsername(AccountName,"Account_mangement/Account/User.txt")){
            cout<<RED<<"Account not Exist !"<<RESET<<endl;
            delay(1000);
            system("cls");
            continue;
          }
          else{
            bool flag = 0;
            for(auto x:tempAdmin){
              if(x[0] == AccountName){
                if(x[2] == "0"){
                  flag = 1;
                  cout<<RED<<"Account has been added in Black List !"<<RESET<<endl;
                  delay(1000);
                  system("cls");
                }
              }
            }
            if(!flag){
              Account::updateStatus(AccountName,"0","Account_mangement/Account/User.txt");
              cout<<GREEN<<"ADD succesfully !"<<RESET<<endl;
              delay(1000);
              system("cls");
            }
          }
        break;
      }
      case 3:
      {
        system("cls");
        string userName;
        cout<<"\033[36m"<<"Enter username which you want remove from Black List: "<<"\033[0m"; cin>>userName;
        if(!isExistUsername(userName,"Account_mangement/Account/User.txt")){
            cout<<RED<<"Account not Exist !"<<RESET<<endl;
            delay(1000);
            system("cls");
            continue;
        }
        else{
            bool flag = 0;
            for(auto x:tempAdmin){
               if(x[0] == userName){
                 if(x[2] != "0"){
                   flag = 1 ;
                   cout<<RED<<"Account not exist in Black List !"<<RESET<<endl;
                   delay(1000);
                   system("cls");
                   continue;
                 }
               }
             }
             if(!flag){
                Account::updateStatus(userName,"-1","Account_mangement/Account/User.txt");
                cout<<GREEN<<"REMOVE succesfully !"<<RESET<<endl;
                delay(1000);
                system("cls");
             }
        }
        
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
//Menu  tổng
void Admin::userManaProcess(){
  int choice;
  while (1)
  {
    
    userManaMenu1();
    cin>>choice;
    vector<vector<string>> tempAdmin = Account::loadUserInfo("Account_mangement/Account/User.txt");
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

        system("cls");
        BlackListProcess();
        break;
      }
      case 4:
      {
        string userName;
        cout<<"\033[36m"<<"Enter username which you want remove: "<<"\033[0m"; cin>>userName;
        Account::removedAccount(userName,"Account_mangement/Account/User.txt"); 
        delay(1000);
        system("cls");
        break;
      }
      case 5:
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