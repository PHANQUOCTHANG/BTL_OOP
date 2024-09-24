#pragma once
#include "Admin.h"


//Hàm show thông tin số lượng tồn kho của các loại thuốc
void Admin::viewStockLevels(vector<Drug> temp){
    phu2();
    for(auto x:temp){
        printStockLevels(x);
    }

}


//Hàm cảnh báo sắp hết sản phẩm trong kho cần phải nhập thêm
void Admin::lowStockAlerts(vector<Drug> temp){
    int count=0;
    for(auto x:temp){
        if(x.getQuantityInStock()<=25){
            count++;
        }
    }
    if(count == 0){
        cout<<"\033[33m"<<"Not found Low Stock"<<"\033[0m"<<endl;
        return;
    }
    else{
        cout<<"\033[33m"<<"Drugs have low stock alerts"<<"\033[0m"<<endl;
    }
    phu2();
    cout<<"\033[31m";
    for(auto x:temp){
        if(x.getQuantityInStock()<=25){
            printStockLevels(x);
        }
    }
    cout<<"\033[0m";

}

//Show Menu
void Admin::inventoryManaMenu(){
            cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. View Stock Levels                    |\n";
  cout << "|    2. Low Stock Alerts                     |\n";
  cout << "|    3. Update Stock Quantity                |\n";
  cout << "|    4. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";

}


//Menu tổng
void Admin::inventoryManaProcess(){
  int choice;
  while (1)
  {
    vector<Drug> temp = Drug::readFromFile("drugStore/wareHouse.txt");
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
        cout<<"\033[36m"<<"Enter Drug's id need to change quantity : "<<"\033[0m";
        cin>>id;
        if(id> temp.size() || id <0){
            cout<<"\033[31m"<<"Id not valid !"<<"\033[0m"<<endl;
        }
        else{

            cout<<"\033[33m"<<"Drug's id need to change quantity is : "<<id<<"\033[0m"<<endl;
            phu2();
            printStockLevels(temp[id-1]);
            int QuantityInStock;
            cout<<"\033[36m"  <<"Update quantityInStock: "<<"\033[0m"; cin>>QuantityInStock;
            temp[id-1].setQuantityInStock(QuantityInStock);
            char rep;
            cout<<"\033[33m"<<"Are you sure you want to change, the data will not be recoverable ! (Y/N)   "<<"\033[0m"; cin>>rep;
            rep=toupper(rep);
            if(rep=='Y'){
                Drug::updateDrugInFile(id,temp[id-1],"drugStore/wareHouse.txt");
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