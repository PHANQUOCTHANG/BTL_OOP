#pragma once
#include "Design.h"


//Hàm set delay(độ chậm) cho giao diện
void delay(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}


//Hàm xử lý nhập mật khẩu
string hidePassword(std::string &password) {
    char ch;
    while ((ch = _getch()) != '\r') { // '\r' là ký tự Enter
        if (ch == '\b') { // Xóa ký tự nếu nhấn Backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; // Xóa dấu '*'
            }
        } else {
            password.push_back(ch);
            cout << '*'; // Hiển thị dấu '*'
        }
    }
    cout << std::endl;
    return password;
}


// Hàm căn giữa một chuỗi (có thể thêm khoảng trắng nếu chuỗi ngắn hơn chiều rộng cột)
string centerText(const string& text, int width) {
    int padding = width - text.length();
    if (padding > 0) {
        int padLeft = padding / 2;
        int padRight = padding - padLeft;
        return std::string(padLeft, ' ') + text + std::string(padRight, ' ');
    } else {
        return text.substr(0, width);  // Cắt bớt chuỗi nếu nó dài hơn chiều rộng cột
    }
}

// viền .
void Line(char c, int length) {
    cout << string(length, c) << endl;
}


void phu1(){
    for(int i=1;i<=154;++i){
        if(i==1 || i==5 || i==31 || i==52 || i==93 || i== 114 || i==133 || i==154) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
}


void phu2(){
    for(int i=1;i<=52;++i){
        if(i==1 || i==5 || i==31 || i==52) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
    std::cout << "|" << centerText("ID", 3)
    << "|" << centerText("Name", 25)
    << "|" << centerText("QuantityInStock", 20) 
    << "|\n";
    for(int i=1;i<=52;++i){
        if(i==1 || i==5 || i==31 || i==52) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
}



void phu3(){
  for(int i=1;i<=31;++i){
      if(i==1 || i==5 || i==31) cout<<'+';
      else{
          cout<<'-';
      }
  }
  cout<<endl;
  std::cout << "|" << centerText("ID", 3)
  << "|" << centerText("Name", 25)
  << "|\n";

}
// In tiêu đề
void title(){
    phu1();
    std::cout << "|" << centerText("ID", 3)
          << "|" << centerText("Name", 25)
          << "|" << centerText("Type", 20)
          << "|" << centerText("Ingredients", 40)
          << "|" << centerText("ExpirationDate", 20)
          << "|" << centerText("Price: (VND)", 18)
          << "|" << centerText("QuantityInStock", 20) 
          << "|\n";
    phu1();
}
void Title1(){
    for(int i=1;i<=164;++i){
        if(i==1 || i==5 || i==31 || i==52 || i==103 ||i == 122 || i==143 || i== 164) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
    std::cout << "|" << centerText("ID", 3)
    << "|" << centerText("UserName", 25)
    << "|" << centerText("Drug name", 20) 
    << "|" << centerText("Time", 50) 
    << "|" << centerText("price", 18) 
    << "|" << centerText("Quantity", 20) 
    << "|" << centerText("Total", 20)
    << "|\n";
    for(int i=1;i<=164;++i){
        if(i==1 || i==5 || i==31 || i==52) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
}

void tab() {
    for (int i = 1 ; i <= 7 ; i++) cout << "\t" ;
}

void showMenu1(){
    tab() ;
    cout<<"+-----------------"<<"\033[35m"<<"MENU"<<"\033[0m"<<"-----------------+\n";
    tab() ;
    cout << "|    1. Register          2. Login     |\n";
    tab() ;
    cout << "|                3. Exit               |\n";
    tab() ;
    cout<<"+--------------------------------------+\n";
    tab() ;
    cout<<"Enter your choice: ";
}


void showMenuLogin(){
    tab() ;
    cout<<"+-----------------"<<"\033[35m"<<"LOGIN"<<"\033[0m"<<"-----------------+\n";
    tab() ;
    cout << "|    1. User               2. Admin     |\n";
    tab() ;
    cout << "|          3. Back to Menu              |\n";
    tab() ;
    cout<<"+---------------------------------------+\n";
    tab() ;
    cout<<"Enter your choice: ";
}


void drugManaMenuUpdateMenu(){
       cout<<"+-----------------"<<"\033[35m"<<"MENU"<<"\033[0m"<<"------------------+\n";
  cout << "|    1.Name                              |\n";
  cout << "|    2.Type                              |\n";
  cout << "|    3.Ingredients                       |\n";
  cout << "|    4.Uses                              |\n";
  cout << "|    5.Dosage                            |\n";
  cout << "|    6.SideEffects                       |\n";
  cout << "|    7.ExpirationDate                    |\n";
  cout << "|    8.Price                             |\n";
  cout << "|    9.QuantityInStock                   |\n";
  cout << "|    10.Back                             |\n";
    cout<<"+----------------------------------------+\n";
    cout<<"Enter your choice: ";
}


void printStockLevels(Drug drug) {
    
    // In các loại thuốc trong bảng với độ rộng cột được định nghĩa trước
        cout << "|" << centerText(to_string(drug.getId()), 3)   // ID
                  << "|" << centerText(drug.getName(), 25)  // Tên thuốc
                  << "|" << centerText(to_string( drug.getQuantityInStock()), 20)  // Số lượng
                  << "|\n";
    // Đường kẻ ngang kết thúc
    for(int i=1;i<=52;++i){
        if(i==1 || i==5 || i==31 || i==52) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
}


void showListDrug2(Drug drug){
     for(int i=1;i<=31;++i){
        if(i==1 || i==5 || i==31) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
 // In các loại thuốc trong bảng với độ rộng cột được định nghĩa trước
    if(drug.getOOT()){
        cout<<"\033[31m";
    }
    else if(drug.getDiscount()){
        cout<<"\033[38;5;206m";
    }
        for(int i=1;i<=31;++i){
        if(i==1 || i==5 || i==31) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
    cout << "|" << centerText(to_string(drug.getId()), 3)   // ID
               << "|" << centerText(drug.getName(), 25)  // Tên thuốc
               << "|";
                   if(drug.getOOT()){
                        cout<<"\tOut of stock";
                    }
                    else if(drug.getDiscount()){
                        cout<<"\tSale "<<drug.getDiscount()<<"%";
                    }

               
               cout<<"\n";
 // Đường kẻ ngang kết thúc
    for(int i=1;i<=31;++i){
        if(i==1 || i==5 || i==31) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
    cout<<"\033[0m";


}


void Title2(){
    for(int i=1;i<=83;++i){
        if(i==1 || i==42 || i==83) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
    std::cout
    << "|" << centerText("Username", 40)
    << "|" << centerText("Password", 40) 
    << "|\n";
    for(int i=1;i<=83;++i){
        if(i==1 || i==42 || i==83) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
}
void printListAccount(pair<string,string> a){
     std::cout
    << "|" << centerText(a.first, 40)
    << "|" << centerText(string(a.second.size(),'*'), 40) 
    << "|\n";
    for(int i=1;i<=83;++i){
        if(i==1 || i==42 || i==83) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;
}

void printPharmacyLogo() {
    // Logo hình chiếc lá và dấu cộng với mã màu ANSI đơn giản
    cout << "\033[32m";  // Màu xanh lá cây
    tab() ;
    cout << "              ***              " << endl;
    tab() ;
    cout << "           **     **           " << endl;
    tab() ;
    cout << "         **         **         " << endl;
    tab() ;
    cout << "       **\033[37m   +++++   \033[32m**       " << endl;
    tab() ;
    cout << "      **\033[37m   +     +   \033[32m**      " << endl;
    tab() ;
    cout << "      **\033[37m   +     +   \033[32m**      " << endl;
    tab() ;
    cout << "       **\033[37m   +++++   \033[32m**       " << endl;
    tab() ;
    cout << "         **         **         " << endl;
    tab() ;
    cout << "           **     **           " << endl;
    tab() ;
    cout << "              ***              " << endl;
    // Chuyển sang màu đỏ để in tên thương hiệu
    cout << "\033[32m";  // Màu đỏ
    tab() ;
    cout << "       ~~~~~ OS PHARMACY ~~~~~       " << endl;

    // Đặt lại màu sắc về mặc định
    cout << "\033[0m";  // Reset màu về mặc định
    cout << "\n\n" ;
}




