#pragma once
#include "Admin.h"


void Admin::userManaMenu(){
            cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. Add/Remove Users                     |\n";
  cout << "|    2. Set Permissions:                     |\n";
  cout << "|    3. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";

}
void addRemoveUsersMenu(){
                cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. Add Users                            |\n";
  cout << "|    2. Remove Users                         |\n";
  cout << "|    3. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";
}
void AddRemoveUserProcess(){
  int choice;
    while (1)
    {
    
      addRemoveUsersMenu();
      cin>>choice;
      switch (choice){
    
        case 1:{
          system("cls");
          Account p;
          p.Register();
          delay(2000);
          break;
        }
        case 2:
        {
          
          system("cls");
          break;
        }
    
        case 3:
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
void Admin::userManaProcess(){
  int choice;
  while (1)
  {
    
    userManaMenu();
    cin>>choice;
    switch (choice){
      
      case 1:{

        system("cls");
        break;
      }
      case 2:
      {

        system("cls");
        break;
      }
    
      case 3:
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