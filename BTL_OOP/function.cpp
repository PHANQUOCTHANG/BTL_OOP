#pragma once
#include "Header.h"
//Hàm set delay(độ chậm) cho giao diện
void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
//Hàm lưu thông tin người dùng đăng kí tài khoản
bool registerUser(const string& username, const string& password) {
    ofstream file("Users.txt", ios::app);
    if (!file.is_open()) {
        cout << "\033[33m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    file << username << " " << password << std::endl;
    file.close();
    return true;
}
//hàm kiểm tra thông tin đăng nhâp, logn in
//hello
bool loginUser(const string& username, const string& password) {
    ifstream file("Users.txt");
    if (!file.is_open()) {
        cout << "\033[33m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
//Hàm menu đăng nhâp / đăng kí thông tin nguòi dùng
void userProcess(){
    User s;
    int choice;
    string Username,Password;
    while(1){
        cout<<"==================MENU==================\n";
      cout << "|    1. Register          2. Login     |\n";
        cout<<"========================================\n";
        cout<<"Enter your choice: ";
        cin >> choice;
        system("cls");
        if (choice == 1) {
            cout<<"Register: "<<endl;
            s.setUsername(Username);
            s.setPassword(Password);
            if (registerUser(Username, Password)) {
                cout << "\033[33m" << "Registration successful!" << "\033[0m" <<endl;
            } else {
                cout << "\033[33m" << "Registration failed!" << "\033[0m" <<endl;
            }
        } else if (choice == 2) {
            do{
                cout<<"Login: "<<endl;
                s.setUsername(Username);
                s.setPassword(Password);
                if(!loginUser(Username, Password)){
                    cout << "\033[33m" << "Invalid username or password!" << "\033[0m" << endl;
                    char rep;
                    cout << "\033[33m" << "Do you want back NENU (Y/N)? " << "\033[0m";
                    cin>>rep;
                    rep=toupper(rep);
                    if(rep=='Y') break;
                    system("cls");
                }
            }
            while(!loginUser(Username, Password));
            if (loginUser(Username, Password)) {
                cout << "\033[33m" << "Login successful!" << "\033[0m" << endl;
                break;
            }
        } else {
            cout << "\033[33m" <<"Invalid choice!" << "\033[0m" << endl;
        }
        delay(1000);
        system("cls");
    }
    system("cls");

}
