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
void userPrivateInfo(){
            cout<<"+-------------------"<<"\033[35m"<<"User"<<"\033[0m"<<"----------------------+\n";
  cout << "|    1. View all                              |\n";
  cout << "|    2. Add new Address                       |\n";
  cout << "|    3. Back                                  |\n";
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
vector<User> User::findUserByUsername(const string &fileName, const string &searchUsername) {
    ifstream file(fileName);
    vector<User> res;
    if (!file.is_open()) {
        cout <<"\033[31m"  << "Cannot open file!" << "\033[0m"  <<endl;
        return res;
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
            User temp( fullName, address, phoneNumber);
            res.push_back(temp);
        }
    }

    // Nếu không tìm thấy user
    file.close();
    return res;
}

//Cập nhật thông tin người dùng
void User::update(){
    string fullName,address,phoneNumber;
    cout<<"\033[33m"  <<"Please fill new your information: "<<"\033[0m"  <<endl;
    cout<<"\033[36m"  <<"Enter your full name: "<<"\033[0m"; cin.ignore(); getline(cin,fullName) ;  this->setName(fullName);
    cout<<"\033[36m"  <<"Enter your address: "<<"\033[0m";  getline(cin,address) ; this->setAddress(address);
    cout<<"\033[36m"  <<"Enter your phone number: "<<"\033[0m";  getline(cin,phoneNumber) ; this->setPhoneNumber(phoneNumber);
    string fileName3="Account_mangement/Account/userInfor/";
    fileName3+=this->getAccountName()+"infor.txt";
    this->writeInfor(fileName3);
    this->setCheck(1);
}

void User::PrivateInfor(){
  int choice;
  int id;
  string filename = "Account_mangement/Account/userInfor/";
  filename+=this->getAccountName()+"infor.txt";
  while (1){

    vector<User> temp = findUserByUsername(filename,this->getAccountName());
    userPrivateInfo();
    cin>>choice;
    switch (choice){
      case 1:
      {
          system("cls");
          if(temp.size()){
            for(int i=0;i<temp.size();++i){
              cout<<"\033[33m"<<"Information "<<i+1<<": ";
              cout<<"\033[36m"<<"Full Name:"<<"\033[32m" <<temp[i].getName()<<"\t";
              cout<<"\033[36m"<<"Address:"<<"\033[32m" <<temp[i].getAddress()<<"\t";
              cout<<"\033[36m"<<"Hotline:"<<"\033[32m"<<temp[i].getPhoneNumber()<<"\033[0m"<<endl;
              cout<<endl;
            }
          }
          else{
            cout<<"\033[31m"<<"List is empty ! Please add your information! "<<"\033[0m" ;
          }
        break;
      }
      case 2:
      {
        system("cls");
        if(temp.size() >= 4){
          cout<<"\033[33m"<<"Number of your Information not excess 4"<<"\033[0m"<<endl;
          break;
        }
        update();
        break;
      }
      case 3:
      {
        system("cls");
        return; 
      }
      default:
      {
       cout<<"\033[31m"  <<"Invalid selection"<<"\033[0m"<<endl;
       break;
      }
    }
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
        PrivateInfor();

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


// setw(x) : quy định độ rộng của một cột (setWidth) .

void User::bill(User temp,vector<Orders> orders,string paymentMethod){
  double total = 0;
    double TotalPayouts = 0;
    double VAT = 1.75; // Thuế VAT
    double Sale = 0;

    // Vẽ đường viền đầu tiên
    Line('=', 85);
    cout << centerText("PVT Pharmacy", 85) << endl;
    Line('=', 85);
    
    // Thông tin khách hàng
    cout << left << setw(20) << "Customer Name:" << temp.getName() << endl;
    cout << left << setw(20) << "Address:" << temp.getAddress() << endl;
    cout << left << setw(20) << "Phone number:" << temp.getPhoneNumber() << endl;
    
    // Vẽ đường viền
    Line('-', 85);
    cout << centerText("Bills for the Sale of Drugs", 85) << endl;
    Line('-', 85);
    
    // Tiêu đề hoá đơn
    cout << left << setw(5) << "STT" 
         << left << setw(35) << "Drug Name" 
         << right << setw(10) << "Quantity" 
         << right << setw(12) << "Price" 
         << right << setw(15) << "Into Money" << endl;
    
    Line('-', 85);

    // Xuất danh sách đơn hàng
    for (size_t i = 0; i < orders.size(); ++i) {
        cout << left << setw(5) << (i + 1) 
             << left << setw(35) << orders[i].getName() // Tên thuốc
             << right << setw(10) << orders[i].getQuantityInStock() // Số lượng
             << right << setw(12) << fixed << setprecision(2) << orders[i].getPrice() // Giá
             << right << setw(15) << fixed << setprecision(2) << orders[i].getTotal() << endl; // Tổng tiền
        total += orders[i].getTotal();
        Sale += (1.0 * (orders[i].getPrice() * orders[i].getDiscount() / 100) * orders[i].getQuantityInStock());
    }

    Line('-', 85);

    // In ra tổng tiền
    cout << left << setw(40) << "Total:" 
         << right << setw(12) << fixed << setprecision(2) << total << endl;
    cout << left << setw(40) << "VAT Tax:" 
         << right << setw(12) << fixed << setprecision(2) << VAT << endl;
    cout << left << setw(40) << "Sale:" 
         << right << setw(12) << fixed << setprecision(2) << Sale << endl;

    TotalPayouts = total + VAT - Sale;
    cout << left << setw(40) << "Total Payouts:" 
         << right << setw(12) << fixed << setprecision(2) << TotalPayouts << endl;

    // Vẽ đường viền
    Line('=', 85);

    // Thời gian và phương thức thanh toán
    string currentTime = getCurrentTime();
    cout << left << setw(40) << "Time:" << currentTime << endl;
    cout << left << setw(40) << "Payment Method:" << paymentMethod << endl;

    // Vẽ đường viền cuối
    Line('=', 85);

}