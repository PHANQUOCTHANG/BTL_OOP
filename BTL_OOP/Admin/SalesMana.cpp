#pragma once
#include "Admin.h"
#include "../Oders/Orders.h"

//Show Menu
void Admin::salesManaMenu(){
            cout<<"+-----------------"<<"\033[35m"<<"DRUG SALE"<<"\033[0m"<<"------------------+\n";
  cout << "|    1. Record Sales                         |\n";
  cout << "|    2. Generate Sales Reports               |\n";
  cout << "|    3. Monthly Revenue                      |\n";
  cout << "|    4. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";

}
//Menu Tổng
void Admin::salesManaProcess(){
  int choice;
  while (1)
  {

    vector<Orders> temp = Orders::readOrdersFromFile("Transactions/HistorySales.txt");
    salesManaMenu();
    cin>>choice;
    switch (choice){
      
      case 1:{
        system("cls");
        if(temp.size() ==0){
           cout<<"\033[31m"<<"History is empty !"<<"\033[0m"<<endl;
           break;
        }
        else{
          Title1();
          for(auto x:temp){
            Orders::printOrdersList(x);
          }
        }
        break;
      }
      case 2:
      {
        system("cls");
        Orders::analyzeSales(temp);
        break;
      }
      case 3:
      {
        system("cls");
        calculateMonthlyRevenue(temp);
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