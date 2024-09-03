#pragma once
#include "header.h"
//Hàm lưu thông tin người dùng đăng kí tài khoản
bool registerUser(const string& username, const string& password) {
    ofstream file("users.txt", ios::app);
    if (!file.is_open()) {
        cout << "\033[33m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    file << username << " " << password << std::endl;
    file.close();
    return true;
}
//hàm kiểm tra thông tin đăng nhâp
bool loginUser(const string& username, const string& password) {
    ifstream file("users.txt");
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
    string username,password;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;
    s.setUsername(username);
    s.setPassword(password);
    
    if (choice == 1) {
        if (registerUser(username, password)) {
            cout << "\033[33m" << "Registration successful!" << "\033[0m" <<endl;
        } else {
            cout << "\033[33m" << "Registration failed!" << "\033[0m" <<endl;
        }
    } else if (choice == 2) {
        if (loginUser(username, password)) {
            cout << "\033[33m" << "Login successful!" << "\033[0m" << endl;
        } else {
            cout << "\033[33m" << "Invalid username or password!" << "\033[0m" << endl;
        }
    } else {
        cout << "\033[33m" <<"Invalid choice!" << "\033[0m" << endl;
    }
}
