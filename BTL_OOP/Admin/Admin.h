#pragma once
#include "../Header.h"
#include "../drugStore/DrugFunction.cpp"
#include "../drugStore/drugHeader.h"
#include "../Design/Interaction.cpp"
class Admin:public Account{
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
        void userManaMenu();
        void userManaProcess();

};

