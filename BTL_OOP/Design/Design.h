#pragma once
#include "../extra_function/Header.h"
#include "../drugStore/drugHeader.h"
#include "../extra_function/Function.cpp"

//Interaction
void delay(int milliseconds);
string hidePassword(std::string &password);
string centerText(const string& text, int width);
void phu1();
void phu2();
void phu3();
void title();
void Title1();
void Title2();
void showMenu1();
void showMenuLogin();
void drugManaMenuUpdateMenu();
void printStockLevels(Drug drug);
void printListAccount(pair<string,string> a);
void showListDrug2(Drug drug);
void printPharmacyLogo() ;
