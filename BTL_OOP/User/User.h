#pragma once
#include "../extra_function/Header.h"
#include "../Account_mangement/Account.h"
#include "../Oders/Orders.h"
#include "../drugStore/drugHeader.h"
#include "../Design/Interaction.cpp"
#include "../extra_function/Function.cpp"


//Đối tượng thông tin
class Info
{
    private:
        string name, //tên Đầy đủ
        address,  //Địa chỉ
        phoneNumber; //Số điện thoại
        bool check; //kiểm tra đã nhập đại chỉ chưa
    public:
        //getter và setter

        //tên Đầy đủ
        std::string getName() const { return name; }
        void setName(std::string _name) { name = _name; }
       
       //Địa chỉ
        std::string getAddress() const { return address; }
        void setAddress(std::string _address) { address = _address; }
       
        //Số điện thoại
        std::string getPhoneNumber() const { return phoneNumber; }
        void setPhoneNumber(std::string _phoneNumber) { phoneNumber = _phoneNumber; }
       
        //kiểm tra đã nhập đại chỉ chưa
        bool getCheck() const { return check; }
        void setCheck(bool is) { check = is; }

};



//Đói tượng Người dùng
class User : public Info, public Account
{

    public:

        //constructer mặc định
        User(){
            this->setName("");
        }

        //constructer đầy đủ tham số
        User( string fullName, string address, string phoneNumber) {
            this->setName(fullName) ;
            this->setAddress (address);
            this->setPhoneNumber(phoneNumber);
        }

    //User Main
        void userMenu(int selection);
        void userProcess();
    //Drug

        void userBuyDrugMenu1();
        void userBuyDrugProcess();
        void payment(int id,vector<Drug> temp);
    //User Infor
        void PrivateInfor(); //Thông tin người dùng
        void userInfoMenu1();  //Show Menu
        void userInfoProcess(); //Menu tổng
        void update(); //Cập nhât
        void cartProcess(); //Menu Cart
        void writeInfor(const string &fileName); //Ghi thông tin vào file
        vector<User> findUserByUsername(const string &fileName, const string &searchUsername);  //Tìm thông tin người dùng bằng tên người dùng
    //discount

        void userDiscountMenu1(); //Show Menu
        void userDiscountProcess(); //Menu tổng
    //in bill
        void bill(User temp,vector<Orders> orders,string paymentMethod);

    // rating user 
        void ratingUser () ;

};


//Phương thức thanh toán
string paymentMethod(int choice);



//Mua thuốc
void userBuyDrugMenu2(); // Menu
void searchMedicines(const std::vector<Drug>& medicines, const std::string& query); //Tìm kiếm thuốc
void searchDrug(string name,vector<Drug> temp); //Tìm thuốc 


//Thông tin người dùng
void userInfoCart1(); //Menu
int total(vector<Orders> cart); //Tính tổng bill cart


