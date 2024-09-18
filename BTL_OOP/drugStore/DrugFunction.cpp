#pragma once
#include "drugHeader.h"
#include "../Design/Interaction.cpp"
//Hafm ghi thông tin của 1 object Drug vào File
void Drug::writeToFile(const string &fileName) {
        std::ofstream outFile(fileName, std::ios::app); // Mở file ở chế độ append
        if (!outFile) {
            cout << "\033[31m" << "Unable to open file to write" << "\033[0m" << endl;
            return;
        }
        outFile << id << ";" << name << ";" << type << ";" << ingredients << ";" << uses << ";"
                << dosage << ";" << sideEffects << ";" << expirationDate << ";" << price << ";" 
                << quantityInStock << "\n";
        outFile.close();
        
}
// Hàm đọc tất cả thông tin từ file và lưu vào vector các đối tượng Drug
std::vector<Drug> Drug::readFromFile(const string &fileName) {
    std::vector<Drug> drugList;
    std::ifstream inFile(fileName);
    
    if (!inFile) {
        cout << "\033[31m" << "Unable to open file to read" << "\033[0m" << endl;
        return drugList;
    }
    
    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> tokens;

        // Tách từng giá trị từ dòng CSV
        while (std::getline(ss, item, ';')) {
            tokens.push_back(item);
        }

        if (tokens.size() == 10) {
            // Tạo đối tượng Drug từ các giá trị đã đọc
            Drug drug;
            drug.id=stoi(tokens[0]),
            drug.name=tokens[1],
            drug.type=tokens[2],
            drug.ingredients=tokens[3],
            drug.uses=tokens[4],
            drug.dosage=tokens[5],
            drug.sideEffects=tokens[6],
            drug.expirationDate=tokens[7],
            drug.price=stoi(tokens[8]),
            drug.quantityInStock=stoi(tokens[9]);
            
            drugList.push_back(drug);
        }
    }
    
    inFile.close();
    return drugList;
}
// Hàm sửa thông tin của một đối tượng Drug dựa trên id
void Drug::updateDrugInFile( int drugId, const Drug updatedDrug,const string &fileName) {
    std::vector<Drug> drugList = readFromFile(fileName);
    std::ofstream outFile(fileName); // Ghi đè file cũ

    if (!outFile) {
        cout << "\033[31m" << "Unable to open file to read" << "\033[0m" << endl;
        return;
    }

    for (Drug& drug : drugList) {
        // Tìm đối tượng Drug có id khớp và cập nhật
        if (drug.getId() == drugId) {
            drug = updatedDrug;
        }
        // Ghi lại từng dòng vào file
        drug.writeToFile(fileName);
    }

    outFile.close();
}
//Hàm đếm số thuốc trong kho
int Drug::countDrugsInFile(const string &fileName) {
        int drugCount;
        std::ifstream inFile(fileName);
        if (!inFile) {
            cout << "\033[31m" << "Unable to open file to read" << "\033[0m" << endl;
            return 0;
        }
        drugCount=1;
        std::string line;
        while (std::getline(inFile, line)) {
            if (!line.empty()) {  // Nếu dòng không trống thì tính là một loại thuốc
                drugCount++;
            }
        }
        inFile.close();
        return drugCount;
}
// Hàm bạn để nhập liệu thuốc 
istream& operator >> (istream &in,Drug &p){
        
        cout<< "\033[36m" <<"Enter information of new Drug: "<< "\033[0m" <<endl;
        p.id = Drug::countDrugsInFile("drugStore/wareHouse.txt");
        cout<<"\033[36m" <<"Name: "<< "\033[0m"; std::getline(std::cin, p.name);
        cout<<"\033[36m" <<"Type: "<< "\033[0m"; std::getline(std::cin, p.type);
        cout<<"\033[36m" <<"Ingredients: "<< "\033[0m"; std::getline(std::cin, p.ingredients);
        cout<<"\033[36m" <<"Uses: "<< "\033[0m"; std::getline(std::cin, p.uses);
        cout<<"\033[36m" <<"Dosage: "<< "\033[0m"; std::getline(std::cin, p.dosage);
        cout<<"\033[36m" <<"SideEffects: "<< "\033[0m"; std::getline(std::cin, p.sideEffects);
        cout<<"\033[36m" <<"ExpirationDate: "<< "\033[0m"; std::getline(std::cin, p.expirationDate);
        cout<<"\033[36m" <<"Price: "<< "\033[0m"; cin>>p.price;
        cout<<"\033[36m" <<"QuantityInStock: "<< "\033[0m"; cin>>p.quantityInStock;
        cin.ignore();
        return in;
}
// Hàm tĩnh để xóa thuốc theo ID
void Drug::deleteDrugById( int idToDelete,const string &fileName) {
        std::ifstream inFile(fileName);
        if (!inFile) {
            cout << "\033[31m" << "Unable to open file to read" << "\033[0m" << endl;
            return;
        }

        std::vector<string> fileData;
        std::string line;
        bool found = false;

        // Đọc từng dòng trong file và tìm thuốc cần xóa
        while (std::getline(inFile, line)) {
             if (line.empty()) {
                continue;  // Bỏ qua dòng trống
            }

            std::stringstream ss(line);
            std::string token;
            int id = -1;  // Khởi tạo ID mặc định
            
            try {
                std::getline(ss, token, ';');  // Lấy ID
                id = std::stoi(token);  // Chuyển đổi sang số nguyên
            } catch (const std::invalid_argument& e) {
                std::cerr <<"\033[31m" << "Error: Unable to convert '" << token << "' to integer numbers.\n"<<"\033[0m" <<endl;
                continue;  // Bỏ qua dòng không hợp lệ
            }


            if (id == idToDelete) {
                found = true;  // Nếu tìm thấy ID, bỏ qua dòng này (không thêm vào fileData)
            } else {
                fileData.push_back(line);  // Lưu các dòng không bị xóa
            }
        }

        inFile.close();

        if (!found) {
            std::cout<<"\033[31m" << "Unable to find ID " << idToDelete << " to delete."<<"\033[0m" <<endl;
            return;
        }

        // Ghi lại các dòng còn lại vào file (ghi đè file gốc)
        std::ofstream outFile(fileName);
        if (!outFile) {
            std::cerr<<"\033[31m" << "Unable to open file to record!"<<"\033[0m" <<endl;
            return;
        }

        for (const auto& row : fileData) {
            outFile << row << "\n";
        }

        outFile.close();
        std::cout<<"\033[32m"<< "Drugs with ID of " << idToDelete << " have been removed successful."<<"\033[0m" <<endl;
}
    // Hàm hiển thị bảng thuốc
void Drug::printDrugList(Drug drug) {
    
    // In các loại thuốc trong bảng với độ rộng cột được định nghĩa trước
        std::cout << "|" << centerText(to_string(drug.id), 3)   // ID
                  << "|" << centerText(drug.name, 25)  // Tên thuốc
                  << "|" << centerText(drug.type, 20)   // Loại
                  << "|" << centerText(drug.ingredients, 40)  // Thành phần
                  << "|" << centerText(drug.expirationDate, 20)  // HSD
                  << "|" << centerText(to_string(drug.price), 18)  // Giá
                  << "|" << centerText(to_string( drug.quantityInStock), 20)  // Số lượng
                  << "|\n";
    

    // Đường kẻ ngang kết thúc
    phu1();


}


