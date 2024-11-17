#pragma once
#include "../extra_function/Header.h"
#include "../drugStore/drugHeader.h"
#include "../Design/Interaction.cpp"


class Orders:public Drug{
    private:
        string buyerName; //Tên người mua
        long long total; //Tổng tiền
    public:
        //constructer
        Orders(){};
        Orders(string Buyer_name,string oder_name,int price,int quanlity,string real_time,int disount,long long total){
            this->setBuyerName(Buyer_name);
            this->setName(oder_name);
            this->setPrice(price);
            this->setQuantityInStock(quanlity);
            this->setExpirationDate(real_time);
            this->setDiscount(disount);
            this->setTotal(total);
            
        }
        //getter và setter

        //Tên người mua
        string getBuyerName() const { return buyerName; }
        void setBuyerName(string _buyerName) { buyerName = _buyerName; }

        //Tổng tiền
        long long getTotal() const { return total; }
        void setTotal(long long _total) { total = _total; }

        //xử lý file
        void writeOrderToFile(const string &fileName); //Ghi sản phẩm vào file
        static vector<Orders> readOrdersFromFile(const string &fileName); //Đọc sản phẩm từ file
        static void printOrdersList(Orders orders) ; //In ra danh sách sản phẩm
        
        static void printOrdersListBill(Orders order); //hàm in bill
        void inheritDrug(Drug drug); //Kế thừa đặc tính từ thuốc

        //Phân tích bán hàng 
        static void analyzeSales(const vector<Orders>& orders) ; 
};
