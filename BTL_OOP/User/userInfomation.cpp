
#pragma once
#include "User.h"
#include "../User/userBuyDrug.cpp"
#include "../Function.cpp"

void User::userInfoMenu1(){
            cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. User information                     |\n";
  cout << "|    2. Cart                                 |\n";
  cout << "|    3. Purchase history                     |\n";
  cout << "|    4. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";

}
void userInfoMenu2(){
            cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"--------------------+\n";
  cout << "|    1. Fullname                              |\n";
  cout << "|    2. Address                               |\n";
  cout << "|    3. Hot line                              |\n";
  cout << "|    4. Back                                  |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";

}
void userInfoCart1(){
            cout<<"+-------------------"<<"\033[35m"<<"Admin"<<"\033[0m"<<"---------------------+\n";
  cout << "|    1. Buy all                               |\n";
  cout << "|    2. Remove all                            |\n";
  cout << "|    3. Choose drug's id to buy               |\n";
  cout << "|    4. Choose drug's id to remove            |\n";
  cout << "|    5. Back                                  |\n";
    cout<<"+---------------------------------------------+\n";
    cout<<"Enter your choice: ";

}
int total(vector<Drug> cart){
  int count=0;
  for(auto x:cart){
    count+=x.getPrice();
  }
  return count;

}
void User::cartProcess(){
  int choice;
  int id;
  char rep;
  while (1)
  {
    vector<Drug> cart = Drug::readFromFile("Transactions/usesHistory/phucart.txt");
    if(cart.size() == 0){
      cout<<"\033[31m"<<"Cart is empty ! Please add something to cart "<<"\033[0m"<<endl;
      return;
    }
    title();
    for(auto x:cart){
      Drug::printDrugList(x);
    }
    userInfoCart1();
    cin>>choice;
    system("cls");

    switch (choice){
      case 1:
      {
        system("cls");
        cout<<"\033[32m";
        title();
        for(auto x:cart){
          Drug::printDrugList(x);
        }
        cout<<"\033[0m";
        cout<<"\033[33m"<<"Do you want buy all ? (Y/N)  "<<"\033[0m"; cin>>rep;
        rep=toupper(rep);
        if(rep=='Y'){
          int totalMoney=total(cart);
            cout<<"Total money is "<<totalMoney<<endl;
            paymentMethod(choice);
            cout<<"Successful order confirmation"<<endl;
            string fileName="Transactions/usesHistory/";
            fileName+=this->getAccountName()+".txt";
            for(auto x:cart){
              Drug demo = x;
              demo.setId(Drug::countDrugsInFile(fileName));
              demo.writeToFile(fileName);
            }
        }
        system("cls");
        break;
      }
      case 2:
      {
        system("cls");
        cout<<"\033[31m";
        title();
        for(auto x:cart){
          Drug::printDrugList(x);
        }
        cout<<"\033[0m";
        cout<<"\033[33m"<<"Do you want remove all ? (Y/N)  "<<"\033[0m"; cin>>rep;
        rep=toupper(rep);
        if(rep=='Y'){
           clearFile("Transactions/usesHistory/phucart.txt");
           cout<<"\033[31m"<<"Cart is empty ! Please add something to cart "<<"\033[0m"<<endl;
           return;
        }
        system("cls");
        break;
      }
      case 3:
      {
        system("cls");
        vector<Drug> temp;
        unordered_set<int> s;
        while (1)
        {
          cout<<"Enter drug's id which you want to buy (Press -1 to cancel): ";
          cin>>id;
          if(id != -1){
            if(id<=0 || id >cart.size() || s.find(id) != s.end()){
              cout<<"Invalid id !"<<endl;

            }
            else{
              temp.push_back(cart[id-1]);
              system("cls");
              for(auto x:temp){
                cout<<"\033[32m";
                s.insert(id);
                title();
                Drug::printDrugList(x);
              }
              cout<<"\033[0m";

            }
          }
          else{
            break;
          }
            
        }
        if(temp.size()==0){
          cout<<"Please select drug"<<endl;
        }
        else{
          cout<<"\033[33m"<<"Do you want buy them ? (Y/N)  "<<"\033[0m"; cin>>rep;
          rep=toupper(rep);
          if(rep=='Y'){
            int totalMoney=total(temp);
              cout<<"Total money is "<<totalMoney<<endl;
              paymentMethod(choice);
              cout<<"Successful order confirmation"<<endl;
              string fileName="Transactions/usesHistory/";
              fileName+=this->getAccountName()+".txt";
              for(auto x:temp){
                Drug demo = x;
                demo.setId(Drug::countDrugsInFile(fileName));
                demo.writeToFile(fileName);
              }
          }
          system("cls");
        }
  
        
        break;
      }
      case 4:
      {
        system("cls");
        vector<Drug> temp;
        unordered_set<int> s;
        while (1)
        {
          cout<<"Enter drug's id which you want remove (Press -1 to cancel): ";
          cin>>id;
          if(id != -1){
            if(id<=0 || id >cart.size() || s.find(id) != s.end()){
              cout<<"Invalid id !"<<endl;
            }
            else{
              temp.push_back(cart[id-1]);
              system("cls");
              for(auto x:temp){
                s.insert(id);
                cout<<"\033[31m";
                title();
                Drug::printDrugList(x);
              }
              cout<<"\033[0m";

            }
          }
          else{
            break;
          }

        }
        if(temp.size()==0){
          cout<<"Please select drug to remove !"<<endl;
        }
        else{
          cout<<"\033[33m"<<"Do you want remove them ? (Y/N)  "<<"\033[0m"; cin>>rep;
          rep=toupper(rep);
          if(rep=='Y'){
              string fileName="Transactions/usesHistory/";
              fileName+=this->getAccountName()+"cart.txt";
              for(auto x:s){
                Drug::deleteDrugById(x,fileName);
              }
              delay(1000);
          }
          system("cls");
        }
        break;
      }
      case 5:
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
void User::update(){
  string fileName;
  int choice;
  char rep;
  while (1)
  {
    system("cls");
    userInfoMenu2();
    cin>>choice;
    switch (choice)
    {
    case 1:{
        if(this->getName() == ""){
            cout<<"Plese update fullname!";
            cout<<"Press Y to update or N to exit (Y/N) "; cin>>rep;
            rep=toupper(rep);
            if(rep!='Y'){
                system("cls");
                return;
            }
            else{
                string fullName;
                cout<<"Enter your fullname :";
                cin.ignore();
                getline(cin,fullName);
                this->setName(fullName);
                cout<<"Update successfully :"; 
                delay(1000); system("cls");
                
            }
        }
        if(this->getName() != ""){
            cout<<"Your fullname is: ";
            cout<<this->getName()<<endl;
        }
        break;
    }
    case 2:
    {
            if(this->getAddress() == ""){
            cout<<"Plese update address !";
            cout<<"Press Y to update or N to exit (Y/N) "; cin>>rep;
            rep=toupper(rep);
            if(rep!='Y'){
                system("cls");
                return;
            }
            else{
                string address;
                cout<<"Enter your address: ";
                cin.ignore();
                getline(cin,address);
                this->setName(address);
                cout<<"Update successfully :"; 
                delay(1000); system("cls");
                



            }
        }
        if(this->getAddress() != ""){
            cout<<"Your address is: ";
            cout<<this->getAddress()<<endl;
        }
        break;
      delay(1000);
      break;
    }
    case 3:
    {
        if(this->getHotLine() == ""){
        cout<<"Plese update hotline!";
        cout<<"Press Y to update or N to exit (Y/N) "; cin>>rep;
        rep=toupper(rep);
        if(rep!='Y'){
            system("cls");
            return;
        }
        else{
            string hotLine;
            cout<<"Enter your hotlline :";
            cin.ignore();
            getline(cin,hotLine);
            this->setName(hotLine);
            cout<<"Update successfully :"; 
            delay(1000); system("cls");
            
        }
    }
        if(this->getHotLine() != ""){
            cout<<"Your fullname is: ";
            cout<<this->getHotLine()<<endl;
        }
        break;
        system("cls");
        return;
    }
    case 4:{
        system("cls");
        return;
    }
    default:
      break;
    }
  }
}
void User::userInfoProcess(){
  int choice;
  int id;
  while (1)
  {
    cin.ignore();
    vector<Drug > temp = Drug::readFromFile("drugStore/wareHouse.txt");
    userInfoMenu1();
    cin>>choice;
    system("cls");

    switch (choice){
      case 1:
      {
        system("cls");
        update();

        break;
      }
      case 2:
      {
        system("cls");
        cartProcess();

        
        break;
      }
      case 3:
      {
        system("cls");
        vector<Drug> purcharseHistory = Drug::readFromFile("Transactions/usesHistory/phu.txt");
        if(purcharseHistory.size() == 0){
          cout<<"\033[31m"<<"Purcharse is empty ! Please buy something "<<"\033[0m"<<endl;
          break;
        }
        title();
        for(auto x:purcharseHistory){
          Drug::printDrugList(x);
        }
        break;
      }
      case 4:
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