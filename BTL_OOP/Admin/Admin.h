#pragma once
#include "../Header.h"
#include "../Account_mangement/Account.h"
#include "../drugStore/drugHeader.h"
#include "../Design/Design.h"
#include "../Function.cpp"


class Admin : public Account
{
    public:
        //admin
        void adminMenu();
        void adminProcess();
        //

        //Drug manager
        void printDrugManaMenu();
        void drugManaUpdate(int id,Drug &origin);
        void drugManaProcess();
        //

        //Inventory
        void inventoryManaMenu();
        void inventoryManaProcess();
        void viewStockLevels(vector<Drug> temp);
        void lowStockAlerts(vector<Drug> temp);
        //Sale
        void salesManaMenu();
        void salesManaProcess();

        //User
        void userManaMenu1();
        void userManaProcess();

};


