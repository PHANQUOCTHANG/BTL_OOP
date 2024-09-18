#pragma once
#include "User.h"


void User::userMenu(){
            cout<<"+-------------------"<<"\033[35m"<<"User"<<"\033[0m"<<"---------------------+\n";
  cout << "|    1. Buy Drug                             |\n";
  cout << "|    2. User Profile Management              |\n";
  cout << "|    3. Discounts and Promotions             |\n";
  cout << "|    4. Feedback and Ratings                 |\n";
  cout << "|    5. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";


}
void User::userProcess(){
    int choice;
    while (1)
    {
        userMenu();
        cin>>choice;
        switch (choice){
        
        case 1:{
            system("cls");
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



