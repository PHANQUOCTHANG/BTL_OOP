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
bool registerUser(const string& fileName,const string& name, const string& password,const string& status) {
    ofstream file(fileName, ios::app);
    if (!file.is_open()) {
        cout << "\033[31m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    file << name << " " << password << " "<< status << std::endl;
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
    map<string, long long> revenueByMonth;  // Key: month, Value: total revenue

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
bool isExistUsername(const string &name,const string &fileName)
{
    ifstream file(fileName);
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
bool isBanUsername(const string &name,const string &fileName)
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "\033[31m" << " Unable to open file" << "\033[0m" << endl;
        return false;
    }

    string storedName,storePass,storeStatus;
    while (file >> storedName>>storePass>>storeStatus)
    {
        if (storedName == name)
        {
            if(storeStatus == "0"){
                return false;
            }
        }
    }
    file.close();
    return true;
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
    if (isExistUsername(username,"Account_mangement/Account/User.txt")){
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
// in sô với định dạng dễ nhìn
string formatNumberWithSpaces(long long number) {
    string numStr = to_string(number);
    int n = numStr.size();

    // Bắt đầu từ vị trí thứ 3 tính từ cuối, chèn khoảng trắng
    for (int i = n - 3; i > 0; i -= 3) {
        numStr.insert(i, " ");
    }
    return numStr;
}
string numberToWords(long long number) {
    if (number == 0) return "không";

    vector<string> units = {"", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"};
    vector<string> levels = {"", "nghìn", "triệu", "tỷ"};

    string result = "";

    // Đảm bảo số là dương trong khi xử lý
    bool isNegative = number < 0;
    number = abs(number);

    int level = 0;

    while (number > 0) {
        int part = number % 1000; // Lấy 3 chữ số cuối
        number /= 1000;

        if (part > 0) {
            string partWords = "";
            int hundred = part / 100;      // Hàng trăm
            int ten = (part / 10) % 10;   // Hàng chục
            int unit = part % 10;         // Hàng đơn vị

            // Đọc hàng trăm
            if (hundred > 0) {
                partWords += units[hundred] + " trăm ";
            } else if (number > 0) {
                partWords += "không trăm ";
            }

            // Đọc hàng chục
            if (ten > 1) {
                partWords += units[ten] + " mươi ";
            } else if (ten == 1) {
                partWords += "mười ";
            } else if (ten == 0 && unit > 0 && hundred > 0) {
                partWords += "lẻ ";
            }

            // Đọc hàng đơn vị
            if (unit > 0) {
                if (ten > 1 && unit == 1) {
                    partWords += "mốt ";
                } else if (ten > 0 && unit == 5) {
                    partWords += "lăm ";
                } else {
                    partWords += units[unit] + " ";
                }
            }

            // Thêm đơn vị nghìn, triệu, tỷ
            if (!partWords.empty()) {
                partWords += levels[level] + " ";
            }

            // Gắn phần đọc của nhóm 3 chữ số vào kết quả cuối
            result = partWords + result;
        }

        level++;
    }

    // Xử lý số âm
    if (isNegative) {
        result = "âm " + result;
    }

    // Loại bỏ khoảng trắng thừa
    while (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    result[0]-=32;
    result+=" Việt Nam Đồng";
    return result;
}
void printVietnamese(const string& text) {
    // Thiết lập mã UTF-8 cho console
    SetConsoleOutputCP(CP_UTF8);

    // In chuỗi
    cout << text << endl;

    // Khôi phục mã mặc định (nếu cần dùng lại mã khác sau này)
    SetConsoleOutputCP(CP_ACP); // Chỉ cần nếu bạn không muốn giữ UTF-8 mãi
}