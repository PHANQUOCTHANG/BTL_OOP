#pragma once
#include "Admin.h"


void Admin::adminMenu(){
        cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. Drug Management                      |\n";
  cout << "|    2. Inventory Management                 |\n";
  cout << "|    3. Sales Management                     |\n";
  cout << "|    4. User Management                      |\n";
  cout << "|    5. Generate Reports                     |\n";
  cout << "|    6. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";
}

void Admin::adminProcess(){
  int choice;
  while (1)
  {
    adminMenu();
    cin>>choice;
    switch (choice){
      
      case 1:{
        system("cls");
        drugManaProcess();
        break;
      }
      case 2:
      {
        system("cls");
        inventoryManaProcess();
        break;
      }
      case 3:
      {
        system("cls");
        break;
      }
      case 4:
      {
        system("cls");
        break;

      }
      case 5:
      {
        system("cls");
        break;

      }
      case 6:
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

