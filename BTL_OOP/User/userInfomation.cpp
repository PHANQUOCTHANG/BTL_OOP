#pragma once
#include "User.h"

//Menu 1
void User::userInfoMenu1(){
            cout<<"+-------------------"<<"\033[35m"<<"User"<<"\033[0m"<<"---------------------+\n";
  cout << "|    1. User information                     |\n";
  cout << "|    2. Cart                                 |\n";
  cout << "|    3. Purchase history                     |\n";
  cout << "|    4. Back                                 |\n";
    cout<<"+--------------------------------------------+\n";
    cout<<"Enter your choice: ";

}

//Menu Cart
void userInfoCart1(){
            cout<<"+-------------------"<<"\033[35m"<<"User"<<"\033[0m"<<"----------------------+\n";
  cout << "|    1. Buy all                               |\n";
  cout << "|    2. Remove all                            |\n";
  cout << "|    3. Choose drug's id to buy               |\n";
  cout << "|    4. Choose drug's id to remove            |\n";
  cout << "|    5. Back                                  |\n";
    cout<<"+---------------------------------------------+\n";
    cout<<"Enter your choice: ";

}

//Tính tổng tiền
int total(vector<Orders> cart){
  int count=0;
  for(auto x:cart){
    count+=x.getTotal();
  }
  return count;

}

//Menu Cart
void User::cartProcess(){
  int choice;
  int id;
  char rep;
  string fileName="Transactions/usesHistory/";
  fileName+=this->getAccountName()+"cart.txt";
  while (1)
  {

    vector<Orders> cart = Orders::readOrdersFromFile(fileName);
    if(cart.size() == 0){
      cout<<"\033[31m"<<"Cart is empty ! Please add something to cart "<<"\033[0m"<<endl;
      return;
    }
    Title1();
    for(auto x:cart){
      Orders::printOrdersList(x);
    }
    userInfoCart1();
    cin>>choice;
    system("cls");
    switch (choice){
      case 1:
      {
        system("cls");
        cout<<"\033[32m";
        Title1();
        for(auto x:cart){
          Orders::printOrdersList(x);
        }
        cout<<"\033[0m";
        cout<<"\033[33m"<<"Do you want buy all ? (Y/N)  "<<"\033[0m"; cin>>rep;
        rep=toupper(rep);
        if(rep=='Y'){
            int totalMoney=total(cart);
            cout<<"\033[33m"  <<"Total money is "<<"\033[0m"<<totalMoney<<endl;
            paymentMethod(choice);
            cout<<"\033[32m"  <<"Successful order confirmation"<<"\033[0m"  <<endl;
            string fileName="Transactions/usesHistory/";
            fileName+=this->getAccountName()+".txt";
            for(auto x:cart){
              Orders demo = x;
              demo.setId(Drug::countDrugsInFile(fileName));
              demo.writeOrderToFile(fileName);
              demo.writeOrderToFile("Transactions/HistorySales.txt");


            }
        }
        break;
      }
      case 2:
      {
        system("cls");
        cout<<"\033[31m";
        Title1();
        for(auto x:cart){
          Orders::printOrdersList(x);
        }
        cout<<"\033[0m";
        cout<<"\033[33m"<<"Do you want remove all ? (Y/N)  "<<"\033[0m"; cin>>rep;
        rep=toupper(rep);
        if(rep=='Y'){
           clearFile("Transactions/usesHistory/phucart.txt");
           cout<<"\033[31m"<<"Cart is empty ! Please add something to cart "<<"\033[0m"<<endl;
           return;
        }
        break;
      }
      case 3:
      {
        system("cls");
        vector<Orders> temp;
        unordered_set<int> s;
        while (1)
        {
          cout<<"\033[36m"  <<"Enter drug's id which you want to buy (Press -1 to cancel): "<<"\033[0m";
          cin>>id;
          if(id != -1){
            if(id<=0 || id >cart.size() || s.find(id) != s.end()){
              cout<<"\033[31m"  <<"Invalid id !"<<"\033[0m"  <<endl;

            }
            else{
              temp.push_back(cart[id-1]);
              system("cls");
              for(auto x:temp){
                cout<<"\033[32m";
                s.insert(id);
                Title1();
                Orders::printOrdersList(x);
                cout<<endl;

              }
              cout<<"\033[0m";

            }
          }
          else{
            break;
          }
            
        }
        if(temp.size()==0){
          cout<<"\033[33m"  <<"Please select drug"<<"\033[0m"  <<endl;
        }
        else{
          cout<<"\033[33m"<<"Do you want buy them ? (Y/N)  "<<"\033[0m"; cin>>rep;
          rep=toupper(rep);
          if(rep=='Y'){
              int totalMoney=total(temp);
              cout<<"\033[33m"  <<"Total money is "<<"\033[0m"<<totalMoney<<endl;
              paymentMethod(choice);
              cout<<"\033[32m"  <<"Successful order confirmation"<<"\033[0m"  <<endl;
              string fileName="Transactions/usesHistory/";
              fileName+=this->getAccountName()+".txt";
              for(auto x:temp){
                Orders demo = x;
                demo.setId(Drug::countDrugsInFile(fileName));
                demo.writeOrderToFile(fileName);
                demo.writeOrderToFile("Transactions/HistorySales.txt");

              }
          }
          system("cls");
        }
  
        
        break;
      }
      case 4:
      {
        system("cls");
        vector<Orders> temp;
        unordered_set<int> s;
        while (1)
        {
          cout<<"\033[36m"  <<"Enter drug's id which you want remove (Press -1 to cancel): "<<"\033[0m";
          cin>>id;
          if(id != -1){
            if(id<=0 || id >cart.size() || s.find(id) != s.end()){
              cout<<"\033[31m"  <<"Invalid id !"<<"\033[0m"  <<endl;
            }
            else{
              temp.push_back(cart[id-1]);
              system("cls");
              for(auto x:temp){
                s.insert(id);
                cout<<"\033[31m";
                Title1();
                Orders::printOrdersList(x);
                
              }
              cout<<"\033[0m";

            }
          }
          else{
            break;
          }

        }
        if(temp.size()==0){
          cout<<"\033[33m"  <<"Please select drug to remove !"<<"\033[0m"  <<endl;
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


//Ghi thông tin vào file
void User::writeInfor(const string &fileName){
   ofstream outFile(fileName,ios::app);
   if (!outFile) {
           cout << "\033[31m" << "Unable to open file to write" << "\033[0m" << endl;
           return;
       }
       outFile << this->getAccountName() << ";" << this->getName() << ";" << this->getAddress() << ";" << this-> getPhoneNumber() << "\n";
       cout<<"\033[32m"  <<"Update information successfull"<<"\033[0m"  <<endl;
       outFile.close();
}

//Tìm thông tin người dùng bằng tên người dùng
User User::findUserByUsername(const string &fileName, const string &searchUsername) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout <<"\033[31m"  << "Cannot open file!" << "\033[0m"  <<endl;
        return User();
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, fullName, address, phoneNumber;

        // Đọc từng trường từ dòng hiện tại, ngăn cách bởi dấu chấm phẩy (;)
        getline(ss, username, ';');
        getline(ss, fullName, ';');
        getline(ss, address, ';');
        getline(ss, phoneNumber, ';');

        // Kiểm tra nếu username khớp
        if (username == searchUsername) {
            file.close();
            return User( fullName, address, phoneNumber);
        }
    }

    // Nếu không tìm thấy user
    file.close();
    return User();
}

//Cập nhật thông tin người dùng
void User::update(){
  if(!this->getCheck()){
    string fullName,address,phoneNumber;
    cout<<"\033[33m"  <<"Please update your information: "<<"\033[0m"  <<endl;
    cout<<"\033[36m"  <<"Enter your full name: "<<"\033[0m"; cin.ignore(); getline(cin,fullName) ;  this->setName(fullName);
    cout<<"\033[36m"  <<"Enter your address: "<<"\033[0m";  getline(cin,address) ; this->setAddress(address);
    cout<<"\033[36m"  <<"Enter your phone number: "<<"\033[0m";  getline(cin,phoneNumber) ; this->setPhoneNumber(phoneNumber);
    this->writeInfor("Account_mangement/Account/Information");
    this->setCheck(1);
    
  }
  else{
    User tokens=findUserByUsername("Account_mangement/Account/Information",this->getAccountName());
    this->setName(tokens.getName()),
    this->setAddress(tokens.getAddress());
    this->setPhoneNumber(tokens.getPhoneNumber());
    cout<<"\033[32m"<<"Full name : "<<"\033[0m"<<this->getName()<<endl;
    cout<<"\033[32m"<<"Address : "<<"\033[0m"<<this->getAddress()<<endl;
    cout<<"\033[32m"<<"Phone number : "<<"\033[0m"<<this->getPhoneNumber()<<endl;

  }


}

//Menu tổng
void User::userInfoProcess(){
  int choice;
  int id;
  while (1)
  {
    
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
          string fileName="Transactions/usesHistory/";
          fileName+=this->getAccountName()+".txt";
        vector<Orders> purcharseHistory = Orders::readOrdersFromFile(fileName);
        if(purcharseHistory.size() == 0){
          cout<<"\033[31m"<<"Purcharse is empty ! Please buy something "<<"\033[0m"<<endl;
          break;
        }
        Title1();
        for(auto x:purcharseHistory){
          Orders::printOrdersList(x);
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