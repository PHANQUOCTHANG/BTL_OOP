#pragma once
#include "Header.h"
#include "Interaction.cpp"


//Hàm đăng kí thông tin nguòi dùng
bool registerUser(const string& name, const string& password) {
    ofstream file("Account.txt", ios::app);
    if (!file.is_open()) {
        cout << "\033[33m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    file << name << " " << password << std::endl;
    file.close();
    return true;
}
//hàm kiểm tra thông tin đăng nhâp, logn in
bool loginUser(const string& name, const string& password) {
    ifstream file("Account.txt");
    if (!file.is_open()) {
        cout << "\033[33m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    string storedName, storedPassword;
    while (file >> storedName >> storedPassword) {
        if (storedName == name && storedPassword == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}