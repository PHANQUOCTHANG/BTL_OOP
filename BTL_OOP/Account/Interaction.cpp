#pragma once
<<<<<<<< HEAD:BTL_OOP/Design/Interaction.cpp
#include "../Header.h"
========
#include "Header.h"




>>>>>>>> ff8d405d726258de298cc80ddf25fd32b383db35:BTL_OOP/Account/Interaction.cpp
//Hàm set delay(độ chậm) cho giao diện
void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
//Hàm xử lý nhập mật khẩu
std::string hidePassword(std::string &password) {
    char ch;
    while ((ch = _getch()) != '\r') { // '\r' là ký tự Enter
        if (ch == '\b') { // Xóa ký tự nếu nhấn Backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b"; // Xóa dấu '*'
            }
        } else {
            password.push_back(ch);
            std::cout << '*'; // Hiển thị dấu '*'
        }
    }
    std::cout << std::endl;
    return password;
}
void showMenu1(){
    cout<<"+-----------------"<<"\033[35m"<<"MENU"<<"\033[0m"<<"-----------------+\n";
  cout << "|    1. Register          2. Login     |\n";
    cout<<"+--------------------------------------+\n";
    cout<<"Enter your choice: ";
}
void showMenuLogin(){
    cout<<"+-----------------"<<"\033[35m"<<"LOGIN"<<"\033[0m"<<"-----------------+\n";
  cout << "|    1. User               2. Admin     |\n";
  cout << "|          3. Back to Menu              |\n";
    cout<<"+---------------------------------------+\n";
    cout<<"Enter your choice: ";
}