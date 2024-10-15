#pragma once
#include "../Header.h"
#include "../drugStore/drugHeader.h"
#include "../Design/Interaction.cpp"


class Orders:public Drug{
    private:
        string buyerName; //Tên người mua
        double total; //Tổng tiền
    public:
        //getter và setter

        //Tên người mua
        string getBuyerName() const { return buyerName; }
        void setBuyerName(string _buyerName) { buyerName = _buyerName; }

        //Tổng tiền
        double getTotal() const { return total; }
        void setTotal(double _total) { total = _total; }

        //xử lý file
        void writeOrderToFile(const string &fileName); //Ghi sản phẩm vào file
        static vector<Orders> readOrdersFromFile(const string &fileName); //Đọc sản phẩm từ file
        static void printOrdersList(Orders orders) ; //In ra danh sách sản phẩm
        
        static void printOrdersListBill(Orders order); //hàm in bill
        void inheritDrug(Drug drug); //Kế thừa đặc tính từ thuốc

        //Phân tích bán hàng 
        static void analyzeSales(const vector<Orders>& orders) ; 
};
