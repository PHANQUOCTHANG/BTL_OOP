#pragma once
#include "User.h"


//Show menu
void User::userDiscountMenu1(){
            cout<<"+-------------------"<<"\033[35m"<<"User"<<"\033[0m"<<"---------------------+\n";
  cout << "|    1. Buy now                              |\n";
  cout << "|    2. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";


}

//Menu Tổng
void User::userDiscountProcess(){
    int choice;
    char rep;
    int id;
    while (1)
    {
        vector<Drug > temp = Drug::readFromFile("drugStore/wareHouse.txt");
        vector<Drug> res;
        for(auto x:temp){
            if(x.getDiscount()>0){
                res.push_back(x);
            }
        }
            if(res.size()== 0){
                cout<<"\033[33m"<<"There is currently no discount "<<"\033[0m"<<endl;
                return;
            }
        userDiscountMenu1();
        cin>>choice;
        switch (choice){
            case 1:{
                system("cls");
                phu3();
                for(auto x:res){
                    showListDrug2(x);
                }
                cout<<"\033[36m"<<"Enter Drug's id you want or (-1) to Back: "<<"\033[0m";
                cin>>id;
                if(id==-1){
                    system("cls"); 
                    break;
                }
                if(id> temp.size() || id <0){
                    cout<<"\033[31m"<<"Id not valid !"<<"\033[0m"<<endl;
                    delay(1000); 
                    system("cls");
                    break;
                }
                payment(id,temp);
                break;
            }
            case 2:
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



