#pragma once
#include "../Header.h"


class Drug {
private:
    int id;                 // Mã định danh của thuốc
    std::string name;        // Tên thuốc
    std::string type;        // Loại thuốc (viên, nước, bột, v.v.)
    std::string ingredients; // Thành phần chính
    std::string uses;        // Công dụng
    std::string dosage;      // Liều lượng sử dụng
    std::string sideEffects; // Tác dụng phụ (nếu có)
    std::string expirationDate; // Ngày hết hạn
    int price;            // Giá của thuốc
    int quantityInStock;     // Số lượng trong kho
    int discount;
public:
    //Nạp chồng toán tử
    friend istream& operator >> (istream &in,Drug &p);
    // Getter và Setter cho từng thuộc tính
    int getId() const { return id; }
    void setId(int _id) { id = _id; }

    std::string getName() const { return name; }
    void setName(std::string _name) { name = _name; }

    std::string getType() const { return type; }
    void setType(std::string _type) { type = _type; }

    std::string getIngredients() const { return ingredients; }
    void setIngredients(std::string _ingredients) { ingredients = _ingredients; }

    std::string getUses() const { return uses; }
    void setUses(std::string _uses) { uses = _uses; }

    std::string getDosage() const { return dosage; }
    void setDosage(std::string _dosage) { dosage = _dosage; }

    std::string getSideEffects() const { return sideEffects; }
    void setSideEffects(std::string _sideEffects) { sideEffects = _sideEffects; }

    std::string getExpirationDate() const { return expirationDate; }
    void setExpirationDate(std::string _expirationDate) { expirationDate = _expirationDate; }

    double getPrice() const { return price; }
    void setPrice(double _price) { price = _price; }

    int getQuantityInStock() const { return quantityInStock; }
    void setQuantityInStock(int _quantityInStock) { quantityInStock = _quantityInStock;}

    int getDiscount() const { return discount; }
    void setDiscount(int _discount) { discount = _discount;}
    //Hàm hiển thị
    void display() {
    std::cout <<"\033[32m"<< "ID: "<<"\033[34m" << id << "\n"
              <<"\033[32m"<< "Name: "<<"\033[34m" << name << "\n"
              <<"\033[32m"<< "Type: "<<"\033[34m" << type << "\n"
              <<"\033[32m"<< "Ingredients: "<<"\033[34m" << ingredients << "\n"
              <<"\033[32m"<< "Uses: "<<"\033[34m" << uses << "\n"
              <<"\033[32m"<< "Dosage: "<<"\033[34m" << dosage << "\n"
              <<"\033[32m"<< "Side Effects: "<<"\033[34m" << sideEffects << "\n"
              <<"\033[32m"<< "Expiration Date: "<<"\033[34m" << expirationDate << "\n"
              <<"\033[32m"<< "Price: "<<"\033[34m" << price << "\n"
              <<"\033[32m"<< "Quantity In Stock: "<<"\033[34m" << quantityInStock << "\n\n"<<"\033[0m";
    }
    //Hàm thao tác với File kho thuốc
    static int countDrugsInFile(const string &fileName);//Đếm số lượng thuốc trong kho
    void writeToFile(const string &fileName);//Ghi thông tin thuốc vào file
    static vector<Drug> readFromFile(const string &fileName); //Đọc thông tin thuốc từ file
    static void updateDrugInFile( int drugId, const Drug updatedDrug,const string &fileName); //Cập nhật thông tin thuốc trong file
    static void deleteDrugById( int idToDelete,const string &fileName);//Xóa thông tin thuốc trong file
    static void printDrugList(Drug p);
};





