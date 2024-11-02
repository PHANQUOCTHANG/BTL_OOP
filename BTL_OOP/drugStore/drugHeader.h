#pragma once
#include "../extra_function/Header.h"

class Drug {
    private:
        int id;             // Mã định danh của thuốc
        string name;        // Tên thuốc
        string type;        // Loại thuốc (viên, nước, bột, v.v.)
        string ingredients; // Thành phần chính
        string uses;        // Công dụng
        string dosage;      // Liều lượng sử dụng
        string sideEffects; // Tác dụng phụ (nếu có)
        string expirationDate; // Ngày hết hạn
        int price;            // Giá của thuốc
        int quantityInStock;     // Số lượng trong kho
        int outOfStock;     //Kiểm tra hết hàng
        int discount;    //Giảm giá


    public:

        // Getter và Setter cho từng thuộc tính

        //Id
        int getId() const { return id; }
        void setId(int _id) { id = _id; }

        //Tên thuốc
        string getName() const { return name; }
        void setName(std::string _name) { name = _name; }

        //Loại thuốc
        string getType() const { return type; }
        void setType(std::string _type) { type = _type; }

        //Tác dụng phụ
        string getIngredients() const { return ingredients; }
        void setIngredients(std::string _ingredients) { ingredients = _ingredients; }

        //Công dụng
        string getUses() const { return uses; }
        void setUses(std::string _uses) { uses = _uses; }

        //Liều lượng
        string getDosage() const { return dosage; }
        void setDosage(std::string _dosage) { dosage = _dosage; }

        //Tác dụng phụ
        string getSideEffects() const { return sideEffects; }
        void setSideEffects(std::string _sideEffects) { sideEffects = _sideEffects; }

        //Hạn sử dụng
        string getExpirationDate() const { return expirationDate; }
        void setExpirationDate(std::string _expirationDate) { expirationDate = _expirationDate; }

        //Giá bán
        int getPrice() const { return price; }
        void setPrice(int _price) { price = _price; }

        //Số lượng trong kho
        int getQuantityInStock() const { return quantityInStock; }
        void setQuantityInStock(int _quantityInStock) { quantityInStock = _quantityInStock;}


        //Kiểm tra hết hàng
        int getOOT() const { return outOfStock; }
        void setOOT(int _outOfStock) { outOfStock = _outOfStock;}

        //Giảm giá
        int getDiscount()  { return discount; }
        void setDiscount(int _discount) { discount = _discount;}

        //Nạp chồng toán tử
        friend istream& operator >> (istream &in,Drug &p);

        //Hàm hiển thị
        void display() ;

        //Hàm thao tác với File kho thuốc
        static int countDrugsInFile(const string &fileName);//Đếm số lượng thuốc trong kho
        void writeToFile(const string &fileName);//Ghi thông tin thuốc vào file
        static vector<Drug> readFromFile(const string &fileName); //Đọc thông tin thuốc từ file
        static void updateDrugInFile( int drugId, const Drug updatedDrug,const string &fileName); //Cập nhật thông tin thuốc trong file
        static void deleteDrugById( int idToDelete,const string &fileName); //Xóa thông tin thuốc trong file
        static void printDrugList(Drug p); //In thông tin thuốc
        static void DecreseQuan(int id, const Drug updatedDrug, const string &fileName,int quanlity); //Giảm số lượng trong kho
        
};





