#pragma once
#include "Oders/Orders.h"


//Hàm lấy thời gian hiện tại từ hệ thống
string getCurrentTime() {
    // Lấy thời gian hiện tại từ hệ thống
    auto now = chrono::system_clock::now();

    // Chuyển đổi thời gian thành time_t
    time_t currentTime = chrono::system_clock::to_time_t(now);

    // Chuyển đổi thành chuỗi định dạng chuẩn (ngày tháng giờ)
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

    return string(buffer); // Trả về chuỗi thời gian cụ thể
}



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



// Hàm xóa dữ liệu trong file
void clearFile(const std::string& fileName) {
    // Mở file ở chế độ ghi và xóa toàn bộ dữ liệu
    ofstream file(fileName, ofstream::trunc);

    // Kiểm tra nếu file mở thành công
    if (file.is_open()) {
        file.close();
        cout << "\033[33m" << "Clear successfully: " << fileName <<  "\033[0m" <<endl;
    } else {
        cerr << "\033[31m" << "Unable to open file: " << fileName <<  "\033[0m" <<endl;
    }
}



void createFileIfNotExists(const std::string& filename) {
    // Kiểm tra nếu file đã tồn tại
    ifstream infile(filename);
    if (infile.good()) {
        // File đã tồn tại
        infile.close();
        return ; // Trả về 0 nếu file đã tồn tại
    }

    // Nếu file chưa tồn tại, tạo file mới
    ofstream outfile(filename);
    if (outfile.is_open()) {
        // outfile << "This file was created because it did not exist before." << std::endl;
        outfile.close();
        return; // Trả về 1 nếu file được tạo thành công
    } else {
        // Không thể tạo file
        return; // Trả về -1 nếu có lỗi khi tạo file
    }
}




string extractMonth(const string& dateTime) {
    // The month is in the format "YYYY-MM-DD", we need substr from position 5 to 7
    return dateTime.substr(5, 2);
}



// Function to calculate revenue by month
void calculateMonthlyRevenue(const vector<Orders>& orders) {
    map<std::string, int> revenueByMonth;  // Key: month, Value: total revenue

    for (const auto& order : orders) {
        string month = extractMonth(order.getExpirationDate());
        revenueByMonth[month] += order.getTotal();  // Add revenue for that month
    }

    // Print the revenue for each month
    cout << "\033[33m" << "\n--- Monthly Revenue ---\n";
    for (const auto& entry : revenueByMonth) {
        cout << "Month: " << entry.first << " - Total Revenue: " << "\033[32m" << entry.second << "\033[33m" << " VND\n";
    }
    cout<< "\033[0m";
}