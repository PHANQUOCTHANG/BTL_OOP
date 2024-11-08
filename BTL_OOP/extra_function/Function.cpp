#pragma once
#include "../Oders/Orders.h"


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
// Check tên tài khoản đã tồn tại chưa
bool isExistUsername(const string &name)
{
    ifstream file("Account_mangement/Account/User.txt");
    if (!file.is_open())
    {
        cout << "\033[31m" << " Unable to open file" << "\033[0m" << endl;
        return false;
    }

    string storedName;
    while (file >> storedName)
    {
        if (storedName == name)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
//Hàm kiểm tra tên đăng nhập
bool validateUsername(const string& username) {
    // Check username length
    if (username.length() < 6) {
        tab() ;cout <<"\033[31m" << " Error: Username must be at least 6 characters long." << "\033[0m" <<endl;
        return false;
    }
    if (username.length() > 20) {
        tab() ;cout <<"\033[31m" << " Error: Username must not exceed 20 characters." <<  "\033[0m" <<endl;
        return false;
    }

    // Check valid characters
    std::regex validPattern("^[a-zA-Z0-9_]+$");
    if (!std::regex_match(username, validPattern)) {
        tab() ;cout <<"\033[31m" << " Error: Username can only contain letters, digits, and underscores (_)." << "\033[0m" << endl;
        return false;
    }

    // Check for underscore at the start or end
    if (username.front() == '_' || username.back() == '_') {
        tab() ;cout <<"\033[31m" << " Error: Username cannot start or end with an underscore (_)." << "\033[0m" <<endl;
        return false;
    }

    // Check for spaces
    if (username.find(' ') != string::npos) {
        tab() ;cout <<"\033[31m" << " Error: Username cannot contain spaces." << "\033[0m" << endl;
        return false;
    }
    if (isExistUsername(username)){
        tab() ;cout << "\033[31m" << " Username has exist !" << "\033[0m" << endl;
        return false;
    }

    // If no errors were found
    return true;
}



// Hàm kiểm tra mật khẩu
bool validatePassword(const string& password) {
    // Kiểm tra độ dài mật khẩu
    if (password.length() < 8) {
        tab() ;cout <<"\033[31m" << " Error: Password must be at least 8 characters long." << "\033[0m" <<endl;
        return false;
    }
    if (password.length() > 20) {
        tab() ;cout <<"\033[31m"<< " Error: Password must not exceed 20 characters." << "\033[0m" <<endl;
        return false;
    }

    // Kiểm tra có ít nhất một chữ cái in hoa
    if (!regex_search(password, regex("[A-Z]"))) {
        tab() ;cout <<"\033[31m" << " Error: Password must contain at least one uppercase letter." <<  "\033[0m" <<endl;
        return false;
    }

    // Kiểm tra có ít nhất một chữ cái in thường
    if (!regex_search(password, regex("[a-z]"))) {
        tab() ;cout <<"\033[31m"<< " Error: Password must contain at least one lowercase letter." <<  "\033[0m" <<endl;
        return false;
    }

    // Kiểm tra có ít nhất một chữ số
    if (!regex_search(password, regex("[0-9]"))) {
        tab() ;cout <<"\033[31m"<< " Error: Password must contain at least one digit." <<  "\033[0m" <<endl;
        return false;
    }

    // Kiểm tra có ít nhất một ký tự đặc biệt
    if (!regex_search(password, regex("[@#$%!^&*]"))) {
        tab() ;cout <<"\033[31m"<< " Error: Password must contain at least one special character (@, #, $, %, !, ^, & or *)." <<  "\033[0m" <<endl;
        return false;
    }

    // Nếu mật khẩu hợp lệ
    return true;
}
// kiểm tra SDT 
bool isValidVietnamesePhoneNumber(const std::string& phoneNumber) {
    // Regex cho số điện thoại Việt Nam
    std::regex vietnamPhonePattern(R"(^(0[35789])\d{8,9}$)");

    // Kiểm tra khớp với regex
    return std::regex_match(phoneNumber, vietnamPhonePattern);
}
// kiểm tra tên 
bool validateName(const std::string& name) {
    // Check if the name is not empty
    if (name.empty()) {
        cout<< "\033[31m"<<"Name cannot be empty."<< "\033[0m"<<endl;
        return false; 
    }

    // Check for leading, trailing, or extra spaces
    if (name.front() == ' ' || name.back() == ' ' || name.find("  ") != std::string::npos) {
        cout<< "\033[31m"<<"Name cannot contain leading, trailing, or extra spaces."<< "\033[0m"<<endl;
        return false;
    }

    // Regex pattern for valid name
    std::regex namePattern(R"(^([A-Z][a-z]+)( [A-Z][a-z]+)*$)");

    // Check if the name matches the regex pattern
    if (!std::regex_match(name, namePattern)) {
        // If not, identify specific errors
        for (size_t i = 0; i < name.size(); ++i) {
            // Check if the first character of each word is uppercase
            if (i == 0 || (name[i - 1] == ' ' && std::isalpha(name[i]))) {
                if (!(name[i] >= 65 && name[i] <= 90 )) {
                    cout<< "\033[31m"<<"Each word must start with an uppercase letter."<< "\033[0m"<<endl;
                    return false;
                }
            }
            // Check if the subsequent characters are lowercase letters
            else if (!std::islower(name[i]) && name[i] != ' ') {
                cout<< "\033[31m"<<"Name cannot contain special characters or numbers."<< "\033[0m"<<endl;
                return false;
            }
        }
        cout<< "\033[31m"<<"Name is invalid due to incorrect format."<< "\033[0m"<<endl;
        return false;
    }
    return true;
}
