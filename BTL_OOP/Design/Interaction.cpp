#pragma once
#include "../Header.h"
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
// Hàm căn giữa một chuỗi (có thể thêm khoảng trắng nếu chuỗi ngắn hơn chiều rộng cột)
std::string centerText(const std::string& text, int width) {
    int padding = width - text.length();
    if (padding > 0) {
        int padLeft = padding / 2;
        int padRight = padding - padLeft;
        return std::string(padLeft, ' ') + text + std::string(padRight, ' ');
    } else {
        return text.substr(0, width);  // Cắt bớt chuỗi nếu nó dài hơn chiều rộng cột
    }
}
void phu1(){
    for(int i=0;i<188;++i){
        if(i==0 || i==4 || i==25 || i==32 || i==53 || i==84 || i== 95 || i==126 || i==147 || i== 166 || i==187) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
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