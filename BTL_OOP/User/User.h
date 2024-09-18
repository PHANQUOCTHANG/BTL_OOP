#pragma once
#include "../Header.h"
#include "../Account_mangement/Account.h"
#include "../drugStore/DrugFunction.cpp"
#include "../drugStore/drugHeader.h"
#include "../Design/Interaction.cpp"

class Orders:public Drug{
    

};
class Info
{
    private:
        string name,address,hotLine;
    public:
        std::string getName() const { return name; }
        void setName(std::string _name) { name = _name; }
       
        std::string getAddress() const { return address; }
        void setAddress(std::string _address) { address = _address; }
       
        std::string getHotLine() const { return hotLine; }
        void setHotLine(std::string _hotLine) { hotLine = _hotLine; }
       
   

};
class User:public Account,Info{

    public:
    //User
        void userMenu();
        void userProcess();
    //Drug
        void userBuyDrugMenu1();
        void userBuyDrugProcess();
        void payment(int id,vector<Drug> temp);

    //User
        void userInfoMenu1();
        void userInfoProcess();
        void update();
        void cartProcess();



};