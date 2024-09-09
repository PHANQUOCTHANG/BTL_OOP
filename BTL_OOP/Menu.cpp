#pragma once
#include "Header.h"
#include "Interaction.cpp"
#include "Function.cpp"
#include "accountName.cpp"



//Hàm menu đăng nhâp / đăng kí thông tin nguòi dùng
void accountProcess(){
    Account p;
    string choice;
    string accountName, accountPassword;
    while(1){
        showMenu1();
        cin >> choice;
        system("cls");
        if (choice == "1") {
            p.Register();
        } else if (choice == "2") {
            if(p.Login()){
                system("cls");
                return;
            } 
            
        } else {
            cout << "\033[33m" <<"Invalid choice!" << "\033[0m" << endl;
            delay(2000);
        }
        system("cls");
    }
    system("cls");

}
