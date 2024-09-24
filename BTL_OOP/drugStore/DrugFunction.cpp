#pragma once
#include "drugHeader.h"
#include "../Design/Interaction.cpp"


//Hafm ghi thông tin của 1 object Drug vào File
void Drug::writeToFile(const string &fileName) {
        ofstream outFile(fileName, ios::app); // Mở file ở chế độ append
        if (!outFile) {
            cout << "\033[31m" << "Unable to open file to write" << "\033[0m" << endl;
            return;
        }
        outFile << id << ";" << name << ";" << type << ";" << ingredients << ";" << uses << ";"
                << dosage << ";" << sideEffects << ";" << expirationDate << ";" << price << ";" 
                << quantityInStock <<";"<< outOfStock <<";"<< discount << "\n";
        outFile.close();
        
}


// Hàm đọc tất cả thông tin từ file và lưu vào vector các đối tượng Drug
vector<Drug> Drug::readFromFile(const string &fileName) {
    vector<Drug> drugList;
    ifstream inFile(fileName);
    
    if (!inFile) {
        cout << "\033[31m" << "Unable to open file to read" << "\033[0m" << endl;
        return drugList;
    }
    
    string line;
    while (std::getline(inFile, line)) {
        stringstream ss(line);
        string item;
        vector<std::string> tokens;

        // Tách từng giá trị từ dòng CSV
        while (getline(ss, item, ';')) {
            tokens.push_back(item);
        }

        if (tokens.size() == 12) {
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
            drug.outOfStock = stoi(tokens[10]);
            drug.discount = stoi(tokens[11]);
            drugList.push_back(drug);
        }
    }
    
    inFile.close();
    return drugList;
}


// Hàm sửa thông tin của một đối tượng Drug dựa trên id
void Drug::updateDrugInFile( int drugId, const Drug updatedDrug,const string &fileName) {
    vector<Drug> drugList = readFromFile(fileName);
    ofstream outFile(fileName); // Ghi đè file cũ

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
        ifstream inFile(fileName);
        if (!inFile) {
            cout << "\033[31m" << "Unable to open file to read" << "\033[0m" << endl;
            return 0;
        }
        drugCount=1;
        string line;
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
        cout<<"\033[36m" <<"Name: "<< "\033[0m";    getline(cin, p.name);
        cout<<"\033[36m" <<"Type: "<< "\033[0m";    getline(cin, p.type);
        cout<<"\033[36m" <<"Ingredients: "<< "\033[0m";     getline(cin, p.ingredients);
        cout<<"\033[36m" <<"Uses: "<< "\033[0m";        getline(cin, p.uses);
        cout<<"\033[36m" <<"Dosage: "<< "\033[0m";      getline(cin, p.dosage);
        cout<<"\033[36m" <<"SideEffects: "<< "\033[0m";     getline(cin, p.sideEffects);
        cout<<"\033[36m" <<"ExpirationDate: "<< "\033[0m";      getline(cin, p.expirationDate);
        cout<<"\033[36m" <<"Price: "<< "\033[0m";       cin>>p.price;
        cout<<"\033[36m" <<"QuantityInStock: "<< "\033[0m";         cin>>p.quantityInStock;
        p.outOfStock = 0;
        p.discount = 0;
        cin.ignore();
        return in;
}


// Hàm tĩnh để xóa thuốc theo ID
void Drug::deleteDrugById( int idToDelete,const string &fileName) {
        ifstream inFile(fileName);
        if (!inFile) {
            cout << "\033[31m" << "Unable to open file to read" << "\033[0m" << endl;
            return;
        }

        vector<string> fileData;
        string line;
        bool found = false;

        // Đọc từng dòng trong file và tìm thuốc cần xóa
        while (getline(inFile, line)) {
             if (line.empty()) {
                continue;  // Bỏ qua dòng trống
            }

            stringstream ss(line);
            string token;
            int id = -1;  // Khởi tạo ID mặc định
            
            try {
                getline(ss, token, ';');  // Lấy ID
                id = stoi(token);  // Chuyển đổi sang số nguyên
            } catch (const std::invalid_argument& e) {
                cerr <<"\033[31m" << "Error: Unable to convert '" << token << "' to integer numbers.\n"<<"\033[0m" <<endl;
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
            cout<<"\033[31m" << "Unable to find ID " << idToDelete << " to delete."<<"\033[0m" <<endl;
            return;
        }

        // Ghi lại các dòng còn lại vào file (ghi đè file gốc)
        ofstream outFile(fileName);
        if (!outFile) {
            cerr<<"\033[31m" << "Unable to open file to record!"<<"\033[0m" <<endl;
            return;
        }

        for (const auto& row : fileData) {
            outFile << row << "\n";
        }

        outFile.close();
        cout<<"\033[32m"<< "Drugs with ID of " << idToDelete << " have been removed successful."<<"\033[0m" <<endl;
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
void Drug::DecreseQuan(int id, const Drug updatedDrug, const string &fileName,int quanlity){
    Drug temp = updatedDrug;
    temp.setQuantityInStock(updatedDrug.getQuantityInStock()-quanlity);
    Drug::updateDrugInFile(id,temp,fileName);

}
void Drug::display() {
    cout <<"\033[32m"<< "ID: "<<"\033[34m" << id << "\n"
        <<"\033[32m"<< "Name: "<<"\033[34m" << name << "\n"
        <<"\033[32m"<< "Type: "<<"\033[34m" << type << "\n"
        <<"\033[32m"<< "Ingredients: "<<"\033[34m" << ingredients << "\n"
        <<"\033[32m"<< "Uses: "<<"\033[34m" << uses << "\n"
        <<"\033[32m"<< "Dosage: "<<"\033[34m" << dosage << "\n"
        <<"\033[32m"<< "Side Effects: "<<"\033[34m" << sideEffects << "\n"
        <<"\033[32m"<< "Expiration Date: "<<"\033[34m" << expirationDate << "\n";
        if(discount > 0){
            float sale = price - (1.0*price *(discount/100.0));
            cout<<"\033[32m"<< "Price: "<<"\033[34m" << price<<" (VND)"<<" ===> "<<sale<<" (VND)"<<"\033[38;5;206m" << "\t\t(Sale "<<discount <<"%)"<< "\n";
        }
        else{
            cout<<"\033[32m"<< "Price: "<<"\033[34m" << price<<"\n";
        }
        cout<<"\033[32m"<< "Quantity In Stock: "<<"\033[34m" << (!outOfStock?to_string(quantityInStock):"Out Of Stock") << "\n\n"<<"\033[0m";

}
