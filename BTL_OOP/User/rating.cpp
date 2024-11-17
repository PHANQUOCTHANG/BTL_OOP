#pragma once
#include "User.h"

void User::ratingUser()
{
    cout << YELLOW << "Please enter your review: " << RESET;
    string userRating;
    getline(cin, userRating); // Lấy đánh giá từ người dùng

    string filePath = "Admin/ListRating.txt";
    ifstream inputFile(filePath); // Mở tệp để kiểm tra sự tồn tại

    if (inputFile)
    {
        // Nếu tệp tồn tại, đọc và hiển thị nội dung
        string fileContent;
        while (getline(inputFile, fileContent))
        {
            cout << fileContent << '\n';
        }
        inputFile.close();

        // Mở lại tệp ở chế độ ghi thêm để lưu đánh giá mới
        ofstream outputFile(filePath, ios::app);
        if (outputFile && userRating != "")
        {
            outputFile << this->getAccountName() << ';' ;
            outputFile << userRating << ';'; // Ghi đánh giá mới vào tệp
            outputFile << getCurrentTime() << '\n' ;
            outputFile.close();
            cout << YELLOW << "Your review has been added.Thank You\n"
                 << RESET;
        }
        else
        {
            cerr << RED << "Cannot open the file to append your review.\n"
                 << RESET;
        }
    }
}