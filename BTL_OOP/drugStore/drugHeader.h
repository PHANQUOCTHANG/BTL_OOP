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
    static int drugCount;
public:
    // Constructor
    
    Drug(int _id, std::string _name, std::string _type, std::string _ingredients, std::string _uses,
         std::string _dosage, std::string _sideEffects, std::string _expirationDate, double _price, int _quantityInStock)
        : id(_id), name(_name), type(_type), ingredients(_ingredients), uses(_uses), dosage(_dosage),
          sideEffects(_sideEffects), expirationDate(_expirationDate), price(_price), quantityInStock(_quantityInStock) {drugCount++;
        }
          

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
    void setQuantityInStock(int _quantityInStock) { quantityInStock = _quantityInStock; }

    static int getDrugCount() {
        return drugCount;
    }
    //Hàm hiển thị
    void display() {
    std::cout << "ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Type: " << type << "\n"
              << "Ingredients: " << ingredients << "\n"
              << "Uses: " << uses << "\n"
              << "Dosage: " << dosage << "\n"
              << "Side Effects: " << sideEffects << "\n"
              << "Expiration Date: " << expirationDate << "\n"
              << "Price: " << price << "\n"
              << "Quantity In Stock: " << quantityInStock << "\n\n";
}

    //Hàm thêm loại thuốc mới
    friend Drug createDrug();

    //Hàm thao tác với File kho thuốc
    static void countDrugsInFile();//Đếm số lượng thuốc trong kho
    void writeToFile();//Ghi thông tin thuốc vào file
    static vector<Drug> readFromFile(); //Đọc thông tin thuốc từ file
    void updateDrugInFile( int drugId, const Drug& updatedDrug); //Cập nhật thông tin thuốc trong file
    static void deleteDrugById( int idToDelete);//Xóa thông tin thuốc trong file
    static void printDrugList();
};





