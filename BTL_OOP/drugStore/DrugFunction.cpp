#pragma once
#include "drugHeader.h"
#include "../Design/Interaction.cpp"
int Drug::drugCount;
//Hafm ghi thông tin của 1 object Drug vào File
void Drug::writeToFile() {
        std::ofstream outFile("drugStore/wareHouse.txt", std::ios::app); // Mở file ở chế độ append
        if (!outFile) {
            cout << "\033[33m" << "Unable to open file to write" << "\033[0m" << endl;
            return;
        }
        outFile << id << "," << name << "," << type << "," << ingredients << "," << uses << ","
                << dosage << "," << sideEffects << "," << expirationDate << "," << price << "," 
                << quantityInStock << "\n";
        outFile.close();
        // drugCount++;
        std::cerr<< "\033[33m"  << "Successful Recording!"<< "\033[0m" <<endl;        
}
// Hàm đọc tất cả thông tin từ file và lưu vào vector các đối tượng Drug
std::vector<Drug> Drug::readFromFile() {
    std::vector<Drug> drugList;
    std::ifstream inFile("drugStore/wareHouse.txt");
    
    if (!inFile) {
        cout << "\033[33m" << "Unable to open file to read" << "\033[0m" << endl;
        return drugList;
    }
    
    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> tokens;

        // Tách từng giá trị từ dòng CSV
        while (std::getline(ss, item, ',')) {
            tokens.push_back(item);
        }

        if (tokens.size() == 10) {
            // Tạo đối tượng Drug từ các giá trị đã đọc
            Drug drug(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3], tokens[4],
                      tokens[5], tokens[6], tokens[7], std::stod(tokens[8]), std::stoi(tokens[9]));
            drugList.push_back(drug);
        }
    }
    
    inFile.close();
    return drugList;
}
// Hàm sửa thông tin của một đối tượng Drug dựa trên id
void Drug::updateDrugInFile( int drugId, const Drug& updatedDrug) {
    std::vector<Drug> drugList = readFromFile();
    std::ofstream outFile("drugStore/wareHouse.txt"); // Ghi đè file cũ

    if (!outFile) {
        cout << "\033[33m" << "Unable to open file to read" << "\033[0m" << endl;
        return;
    }

    for (Drug& drug : drugList) {
        // Tìm đối tượng Drug có id khớp và cập nhật
        if (drug.getId() == drugId) {
            drug = updatedDrug;
        }
        // Ghi lại từng dòng vào file
        drug.writeToFile();
    }

    outFile.close();
}
//Hàm đếm số thuốc trong kho
void Drug::countDrugsInFile() {
        std::ifstream inFile("drugStore/wareHouse.txt");
        if (!inFile) {
            cout << "\033[33m" << "Unable to open file to read" << "\033[0m" << endl;
            return;
        }
        drugCount=1;
        std::string line;
        while (std::getline(inFile, line)) {
            if (!line.empty()) {  // Nếu dòng không trống thì tính là một loại thuốc
                drugCount++;
            }
        }
        inFile.close();
}
// Hàm bạn để nhập liệu thuốc 
Drug createDrug(){
        int id = Drug::getDrugCount();                 // 
        std::string name;        //
        std::string type;        //
        std::string ingredients; //
        std::string uses;        //
        std::string dosage;      //
        std::string sideEffects; //
        std::string expirationDate;
        double price;            //
        int quantityInStock;     //    
        cout<<"Enter information of new Drug: "<<endl;
        cout<<"Name: "; std::getline(std::cin, name);
        cout<<"Type: "; std::getline(std::cin, type);
        cout<<"Ingredients: "; std::getline(std::cin, ingredients);
        cout<<"Uses: "; std::getline(std::cin, uses);
        cout<<"Dosage: "; std::getline(std::cin, dosage);
        cout<<"SideEffects: "; std::getline(std::cin, sideEffects);
        cout<<"ExpirationDate: "; std::getline(std::cin, expirationDate);
        cout<<"Price: "; cin>>price;
        cout<<"QuantityInStock: "; cin>>quantityInStock;
        cin.ignore();
        return Drug(id,name,type,ingredients,uses,dosage,sideEffects,expirationDate,price,quantityInStock);
}
// Hàm tĩnh để xóa thuốc theo ID
void Drug::deleteDrugById( int idToDelete) {
        std::ifstream inFile("drugStore/wareHouse.txt");
        if (!inFile) {
            cout << "\033[33m" << "Unable to open file to read" << "\033[0m" << endl;
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
                std::getline(ss, token, ',');  // Lấy ID
                id = std::stoi(token);  // Chuyển đổi sang số nguyên
            } catch (const std::invalid_argument& e) {
                std::cerr <<"\033[33m" << "Error: Unable to convert '" << token << "' to integer numbers.\n"<<"\033[0m" <<endl;
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
            std::cout<<"\033[33m" << "Unable to find ID " << idToDelete << " to delete."<<"\033[0m" <<endl;
            return;
        }

        // Ghi lại các dòng còn lại vào file (ghi đè file gốc)
        std::ofstream outFile("drugStore/wareHouse.txt");
        if (!outFile) {
            std::cerr<<"\033[33m" << "Unable to open file to record!"<<"\033[0m" <<endl;
            return;
        }

        for (const auto& row : fileData) {
            outFile << row << "\n";
        }

        outFile.close();

        drugCount--;  // Giảm biến đếm khi xóa thuốc
        std::cout<<"\033[33m"  << "Drugs with ID of " << idToDelete << " have been removed."<<"\033[0m" <<endl;
}
    // Hàm hiển thị bảng thuốc
void Drug::printDrugList() {
    vector<Drug> drugs = Drug::readFromFile();
    // In tiêu đề bảng với định dạng căn giữa
    phu1();
    std::cout << "|" << centerText("ID", 3)
              << "|" << centerText("Name", 20)
              << "|" << centerText("Type", 6)
              << "|" << centerText("Ingredients", 20)
              << "|" << centerText("Uses", 30)
              << "|" << centerText("Dosage", 10)
              << "|" << centerText("SideEffects", 30)
              << "|" << centerText("ExpirationDate", 20)
              << "|" << centerText("Price: (VND)", 18)
              << "|" << centerText("QuantityInStock", 20) 
              << "|\n";

    // In đường kẻ ngang giữa các cột
    phu1();
    // In các loại thuốc trong bảng với độ rộng cột được định nghĩa trước
    for (const auto& drug : drugs) {
        std::cout << "|" << centerText(to_string(drug.id), 3)   // ID
                  << "|" << centerText(drug.name, 20)  // Tên thuốc
                  << "|" << centerText(drug.type, 6)   // Loại
                  << "|" << centerText(drug.ingredients, 20)  // Thành phần
                  << "|" << centerText(drug.uses, 30)  // Công dụng
                  << "|" << centerText(drug.dosage, 10)   // Liều
                  << "|" << centerText(drug.sideEffects, 30)  // Tác dụng phụ
                  << "|" << centerText(drug.expirationDate, 20)  // HSD
                  << "|" << centerText(to_string(drug.price), 18)  // Giá
                  << "|" << centerText(to_string( drug.quantityInStock), 20)  // Số lượng
                  << "|\n";
    }

    // Đường kẻ ngang kết thúc
    phu1();


}


