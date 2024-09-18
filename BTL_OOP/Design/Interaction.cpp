#pragma once
#include "../Header.h"
#include "../drugStore/drugHeader.h"
//Hàm set delay(độ chậm) cho giao diện
void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
//Hàm xử lý nhập mật khẩu
std::string hidePassword(std::string &password) {
    char ch;
    while ((ch = _getch()) != '\r') { // '\r' là ký tự Enter
        if (ch == '\b') { // Xóa ký tự nếu nhấn Backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b"; // Xóa dấu '*'
            }
        } else {
            password.push_back(ch);
            std::cout << '*'; // Hiển thị dấu '*'
        }
    }
    std::cout << std::endl;
    return password;
}
// Hàm căn giữa một chuỗi (có thể thêm khoảng trắng nếu chuỗi ngắn hơn chiều rộng cột)
std::string centerText(const std::string& text, int width) {
    int padding = width - text.length();
    if (padding > 0) {
        int padLeft = padding / 2;
        int padRight = padding - padLeft;
        return std::string(padLeft, ' ') + text + std::string(padRight, ' ');
    } else {
        return text.substr(0, width);  // Cắt bớt chuỗi nếu nó dài hơn chiều rộng cột
    }
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
  for(int i=1;i<=31;++i){
      if(i==1 || i==5 || i==31) cout<<'+';
      else{
          cout<<'-';
      }
  }
  cout<<endl;

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
void showMenu1(){
    cout<<"+-----------------"<<"\033[35m"<<"MENU"<<"\033[0m"<<"-----------------+\n";
  cout << "|    1. Register          2. Login     |\n";
  cout << "|                3. Exit               |\n";
    cout<<"+--------------------------------------+\n";
    cout<<"Enter your choice: ";
}
void showMenuLogin(){
    cout<<"+-----------------"<<"\033[35m"<<"LOGIN"<<"\033[0m"<<"-----------------+\n";
  cout << "|    1. User               2. Admin     |\n";
  cout << "|          3. Back to Menu              |\n";
    cout<<"+---------------------------------------+\n";
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
        std::cout << "|" << centerText(to_string(drug.getId()), 3)   // ID
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
     std::cout << "|" << centerText(to_string(drug.getId()), 3)   // ID
               << "|" << centerText(drug.getName(), 25)  // Tên thuốc
               << "|\n";
 // Đường kẻ ngang kết thúc
    for(int i=1;i<=31;++i){
        if(i==1 || i==5 || i==31) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;

}