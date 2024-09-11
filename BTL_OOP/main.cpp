
#include "Header.h"
#include "Design/Menu.cpp"
#include "drugStore/drugHeader.h"
#include "drugStore/DrugFunction.cpp"
//Ham main
int main() {
    // accountProcess();
    // Drug::countDrugsInFile();
    // for(int i=0;i<2;++i){
        // Drug p=createDrug();
        // p.writeToFile();
    // }
    vector <Drug> temp = Drug::readFromFile();
    for(auto x:temp){
        x.display();
    }
}