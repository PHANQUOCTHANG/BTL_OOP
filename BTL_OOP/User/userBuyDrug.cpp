#pragma once
#include "User.h"


void User::userBuyDrugMenu1(){
            cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. View all drug in store               |\n";
  cout << "|    2. Search Medicine by Name              |\n";
  cout << "|    3. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";

}
void userBuyDrugMenu2(){
            cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. Buy now                              |\n";
  cout << "|    2. Add cart                             |\n";
  cout << "|    3. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";

}
string paymentMethod(int choice){
    cout<<"Choose a payment method"<<endl;
    cout<<"+------------------------------------------------+"<<endl;
    cout<<"|    1. Pay on Pickup       2. Online payment    |\n";
    cout<<"+------------------------------------------------+"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    while(1){
      if(choice==1){
        return "Pay on Pickup";
      }
      else if(choice == 2){
        return "Online payment";
      }
      else{
        cout<<"Invalid choose"<<endl;
      }
    }
    return "";
}
void User::payment(int id,vector<Drug> temp){
  string fileName;
  int choice;
  char rep;
  while (1)
  {
    system("cls");
    temp[id-1].display();
    userBuyDrugMenu2();
    cin>>choice;
    int quanlity,totalMoney;
    switch (choice)
    {
    case 1:{
      cout<<"Enter the quantity you want to buy :"; cin>>quanlity;
      totalMoney = temp[id-1].getPrice()*quanlity;
      cout<<"Total money is "<<totalMoney<<endl;
      paymentMethod(choice);
      cout<<"Successful order confirmation"<<endl;
      string fileName="Transactions/usesHistory/";
      fileName+=this->getAccountName()+".txt";
      Drug demo = temp[id-1];
      demo.setId(Drug::countDrugsInFile(fileName));
      demo.setPrice(totalMoney);
      demo.setQuantityInStock(quanlity);
      demo.writeToFile(fileName);
      cout<<"Do you want continue ? (Y/N) "; cin>>rep;
      rep=toupper(rep);
      if(rep!='Y'){
        system("cls");
        return;
      } 
      delay(1000);
      break;
    }
    case 2:
    {
      cout<<"Enter the quantity you want to add cart :"; cin>>quanlity;
      totalMoney = temp[id-1].getPrice()*quanlity;
      cout<<"Total money is "<<totalMoney<<endl;
      cout<<"Successful add cart"<<endl;
      Drug demo = temp[id-1];
      demo.setId(Drug::countDrugsInFile("Transactions/usesHistory/phucart.txt"));
      demo.setPrice(totalMoney);
      demo.setQuantityInStock(quanlity);
      string fileName="Transactions/usesHistory/";
      fileName+=this->getAccountName()+"cart.txt";
      demo.writeToFile(fileName);
      cout<<"Do you want continue ? (Y/N) "; cin>>rep;
      rep=toupper(rep);
      if(rep!='Y'){
        system("cls");
        return;
      }
      delay(1000);
      break;
    }
    case 3:
    {
      system("cls");
      return;
    }
    default:
      break;
    }
  }
}
void searchMedicines(const std::vector<Drug>& medicines, const std::string& query) {
    std::cout << "\nSearch results for \"" << query << "\":" << std::endl;
    bool found = false;
    for (const auto& med : medicines) {
        if (med.getName().find(query) != std::string::npos) {  // Check if query matches medicine name
             showListDrug2(med);
            found = true;
        }
    }
    if (!found) std::cout << "No medicines found.\n";
}
void searchDrug(string name,vector<Drug> temp){
    for(auto x:temp){
      if(x.getName().find(name) != string::npos){
        showListDrug2(x);
      }
    }

}
void User::userBuyDrugProcess(){
  int choice;
  int id;
  bool search=0;
  while (1)
  {
    cin.ignore();
    vector<Drug > temp = Drug::readFromFile("drugStore/wareHouse.txt");
    userBuyDrugMenu1();
    cin>>choice;
    system("cls");

    switch (choice){
      case 1:
      {
        system("cls");
          phu3();
          for(auto x:temp){
            showListDrug2(x);
          }
          cout<<"\033[36m"<<"Enter Drug's id you want oce "<<"\033[0m";
          cin>>id;
          if(id> temp.size() || id <0){
            cout<<"\033[31m"<<"Id not valid !"<<"\033[0m"<<endl;
            delay(1000); 
            system("cls");
            break;
          }
          payment(id,temp);

        break;
      }
      case 2:
      {
        system("cls");
        string query="";
        char ch;
        while (ch != '\r'){
          std::cout << "\nPlease type drug's name to search: "; cout<<query; ch = _getch();
          if(ch != '\r') system("cls");
          if(ch == '\r') break;
          if (ch == '\b') {  // Handle Backspace
              if (!query.empty()) query.pop_back();
          }
          else if (ch != '\n') {  // Add character to query if not newline
              query += ch;
          }

          if (!query.empty()) {
              searchMedicines(temp, query);  // Search and display results
          }
          
          
        }
        system("cls");
        searchDrug(query,temp);
        cout<<"\033[36m"<<"Enter Drug's id you want: "<<"\033[0m";
        cin>>id;
        if(id> temp.size() || id <0){
          cout<<"\033[31m"<<"Id not valid !"<<"\033[0m"<<endl;
          delay(1000); 
          system("cls");
          continue;
        }
        payment(id,temp);
        break;
      }
      case 3:
      {
        system("cls");
        return;
      }
      default:{
        cout<<"\033[31m"  <<"Invalid selection"<<"\033[0m"<<endl;
        break;
      }
    }
    delay(1000);

  }
}