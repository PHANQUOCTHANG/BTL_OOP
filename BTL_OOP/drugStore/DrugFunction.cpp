#pragma once
#include "drugHeader.h"
int Drug::drugCount;
//Hafm ghi thông tin của 1 object Drug vào File
void Drug::writeToFile() {
        std::ofstream outFile("drugStore/wareHouse.txt", std::ios::app); // Mở file ở chế độ append
        if (!outFile) {
            std::cerr << "Không thể mở file để ghi!\n";
            return;
        }
        outFile << id << "," << name << "," << type << "," << ingredients << "," << uses << ","
                << dosage << "," << sideEffects << "," << expirationDate << "," << price << "," 
                << quantityInStock << "\n";
        outFile.close();
        // drugCount++;
        std::cerr << "Ghi thành công!\n";        
}
// Hàm đọc tất cả thông tin từ file và lưu vào vector các đối tượng Drug
std::vector<Drug> Drug::readFromFile() {
    std::vector<Drug> drugList;
    std::ifstream inFile("drugStore/wareHouse.txt");
    
    if (!inFile) {
        std::cerr << "Không thể mở file để đọc!\n";
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
void Drug::updateDrugInFile(const std::string& fileName, int drugId, const Drug& updatedDrug) {
    std::vector<Drug> drugList = readFromFile();
    std::ofstream outFile(fileName); // Ghi đè file cũ

    if (!outFile) {
        std::cerr << "Không thể mở file để ghi!\n";
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
            std::cerr << "Không thể mở file để đọc!\n";
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
