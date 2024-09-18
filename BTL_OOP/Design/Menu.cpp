#pragma once
#include "../Header.h"
#include "../Account_mangement/Account.h"
#include "../Admin/Admin.h"
#include "Interaction.cpp"
#include "../Function.cpp"
#include "../Account_mangement/accountName.cpp"
#include "../User/User.h"
// #include "Admin\Admin.h"

//Hàm menu đăng nhâp / đăng kí thông tin nguòi dùng

void accountProcess(){
    string choice;
    while(1){
        Account p;
        showMenu1();
        cin >> choice;
        system("cls");
        if (choice == "1") {
            p.Register();
            delay(2000);
            
        } else if (choice == "2") {
            if(p.Login()){
                system("cls");
                if(adminMode){
                    Admin p1;
                    p1.adminProcess();
                }
                else{
                    User p2;
                    p2.setUserName(p.getAccountName());
                    p2.userProcess();
                }
            } 

        }
        else if(choice == "3"){
            cout<<"\033[32m"<<"AMSR Programming thank you very much"<< "\033[0m"<<endl;
            return;
        }   
        else {
            cout << "\033[31m" <<"Invalid choice!" << "\033[0m" << endl;
            delay(2000);
        }
        system("cls");
    }
    system("cls");

}