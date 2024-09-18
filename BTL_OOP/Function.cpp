#pragma once
#include "Header.h"
#include "Design/Interaction.cpp"


//Hàm đăng kí thông tin nguòi dùng
bool registerUser(const string& fileName,const string& name, const string& password) {
    ofstream file(fileName, ios::app);
    if (!file.is_open()) {
        cout << "\033[31m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    file << name << " " << password << std::endl;
    file.close();
    return true;
}
//hàm kiểm tra thông tin đăng nhâp, logn in
bool loginUser(const string& fileName,const string& name, const string& password) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "\033[31m" << "Unable to open file" << "\033[0m" << endl;
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
#include <fstream>
#include <iostream>
#include <string>

// Hàm xóa dữ liệu trong file
void clearFile(const std::string& fileName) {
    // Mở file ở chế độ ghi và xóa toàn bộ dữ liệu
    std::ofstream file(fileName, std::ofstream::trunc);

    // Kiểm tra nếu file mở thành công
    if (file.is_open()) {
        file.close();
        std::cout << "Đã xóa dữ liệu trong file: " << fileName << std::endl;
    } else {
        std::cerr << "Không thể mở file: " << fileName << std::endl;
    }
}
