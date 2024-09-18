#pragma once
#include "Admin.h"


void Admin::salesManaMenu(){
            cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. Record Sales                         |\n";
  cout << "|    2. Generate Sales Reports               |\n";
  cout << "|    3. Manage Discounts                     |\n";
  cout << "|    4. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";

}


void Admin::inventoryManaProcess(){
  int choice;
  while (1)
  {
    vector<Drug> temp = Drug::readFromFile();
    inventoryManaMenu();
    cin>>choice;
    switch (choice){
      
      case 1:{
        if(temp.size() ==0){
           cout<<"\033[31m"<<"List is empty ! Please add more infomation "<<"\033[0m"<<endl;
           break;
       }
        system("cls");
        viewStockLevels(temp);
        break;
      }
      case 2:
      {
        if(temp.size() ==0){
           cout<<"\033[31m"<<"List is empty ! Please add more infomation "<<"\033[0m"<<endl;
           break;
       }
        system("cls");
        lowStockAlerts(temp);
        break;
      }
      case 3:
      {
        system("cls");
        if(temp.size() ==0){
            cout<<"\033[31m"<<"List is empty ! Please add more infomation "<<"\033[0m"<<endl;
            break;
        }
        system("cls");
        int id;
        cout<<"\033[36m"<<"Enter Drug's id need to add discount : "<<"\033[0m";
        cin>>id;
        if(id> temp.size() || id <0){
            cout<<"\033[31m"<<"Id not valid !"<<"\033[0m"<<endl;
        }
        else{

            cout<<"\033[33m"<<"Drug's id need to add discount is : "<<id<<"\033[0m"<<endl;
            phu2();
            printStockLevels(temp[id-1]);
            int QuantityInStock;
            cout<<"\033[36m"  <<"Update quantityInStock: "<<"\033[0m"; cin>>QuantityInStock;
            temp[id-1].setQuantityInStock(QuantityInStock);
            char rep;
            cout<<"\033[33m"<<"Are you sure you want to change, the data will not be recoverable ! (Y/N)   "<<"\033[0m"; cin>>rep;
            rep=toupper(rep);
            if(rep=='Y'){
                Drug::updateDrugInFile(id,temp[id-1]);
                std::cerr<< "\033[32m"  << "Successful update!"<< "\033[0m" <<endl;        
            }
            else{
                cout<<"\033[32m"  <<"Cancel the update successfully !"<<"\033[0m"  <<endl;
            }
            delay(2000);
            system("cls");
            break;
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