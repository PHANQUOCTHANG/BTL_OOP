#pragma once
#include "Account.h"
#include "../Design/Design.h"
#include "../Function.cpp"
#include "../Admin/Admin.h"
#include "../User/User.h"


//Geter
string Account::getAccountName(){
    return this->accountName;
}   
//Geter

string Account::getAccountPassword(){
    return this->accountPassword;
}


//define ADMIN account
string Account::adminName="admin";
string Account::adminPassword="admin";


//Check tên tài khoản đã tồn tại chưa
bool isExistUsername(const string& name){
        ifstream file("Account_mangement/Account/User.txt");
    if (!file.is_open()) {
        cout << "\033[31m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    string storedName;
    while (file >> storedName) {
        if (storedName == name) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


//Set Tên tài khoản
void Account::setAccountName(string accountName){
    cout <<"\033[36m"<< "Enter username: "<<"\033[0m";
    cin >> accountName;
    this->accountName = accountName;
}


//Set Mật khẩu
void Account::setAccountPassword(string accountName){
    cout <<"\033[36m"<< "Enter password: "<<"\033[0m";
    this->accountPassword = hidePassword(accountName);
}


//Set Tạo tài khoản mới
bool Account::setAccountRegister(string accountName,string accountPassword){
    char res;
    string verify;
    do
    {
        //check username
        do
        {
            cout <<"\033[36m"<< "Enter username: "<<"\033[0m";
            cin >> accountName;
            if(isExistUsername(accountName)){
                cout<< "\033[31m"<<"Username has exist !"<< "\033[0m"<<endl;
                cout<<"\033[33m"<<"Do you want continue ! (Y/N)"<<"\033[0m"<<endl;
                cin>>res;
                res=toupper(res);
                if(res!='Y') return 0;
                delay(2000);
                system("cls");
                cout<<"\033[36m"<<"Register: "<<"\033[0m"<<endl;

            }
            /* code */
        } while (isExistUsername(accountName));
        this->accountName = accountName;

        
        //check match password
        cout << "\033[36m"<<"Enter password: "<<"\033[0m";
        this->accountPassword = hidePassword(accountPassword);
        cout <<"\033[36m"<< "Confirm password: "<<"\033[0m";
        hidePassword(verify);
        if(verify != accountPassword){
            cout<<"\033[31m"<<"Password does not mactch!"<<"\033[0m"<<endl;
            cout<<"\033[33m"<<"Do you want continue ! (Y/N)"<<"\033[0m"<<endl;
            cin>>res;
            res=toupper(res);
            if(res!='Y') return 0;
            delay(2000);
            system("cls");
            cout<<"\033[36m"<<"Register: "<<"\033[0m"<<endl;
        }
    } while (verify != accountPassword);
    return 1;
}


// Tạo tài khoản mới
void Account::Register(){
    string accountName,accountPassword;
    cout<<"\033[36m"<<"Register: "<<"\033[0m"<<endl;
    if(!setAccountRegister(accountName,accountPassword)) return;
    if (registerUser("Account_mangement/Account/User.txt",this->accountName, this->accountPassword)) {
        cout << "\033[32m" << "Registration successful!" << "\033[0m" <<endl;
    } else {
        cout << "\033[31m" << "Registration failed!" << "\033[0m" <<endl;
    }
}


//Menu Login
bool Account::Login(){
    string choice;
    string accountName, accountPassword;

    while (1)
    {
        adminMode=0;
        showMenuLogin();
        cin>>choice;
        system("cls");
        if (choice == "1") {
            do{
                cout<<"\033[36m"<<"Login as a User: "<<"\033[0m"<<endl;
                setAccountName(accountName);
                setAccountPassword(accountPassword);
                if(!loginUser("Account_mangement/Account/User.txt",this->accountName,this-> accountPassword)){
                    cout << "\033[31m" << "Invalid username or password!" << "\033[0m" << endl;
                    char rep;
                    cout << "\033[33m" << "Do you want back (Y/N)?--> " << "\033[0m";
                    cin>>rep;
                    rep=toupper(rep);
                    if(rep=='Y') break;
                    system("cls");
                }
            }
            while(!loginUser("Account_mangement/Account/User.txt",this->accountName,this->accountPassword));
            if (loginUser("Account_mangement/Account/User.txt",this->accountName,this->accountPassword)) {
                cout << "\033[32m" << "Login successful!" << "\033[0m" << endl;
                cout << "\033[33m" << "Now you are a User ! Press Enter to continue !" << "\033[0m" << endl;
                cin.ignore();  // Bỏ qua bất kỳ ký tự nào đã có sẵn trong bộ đệm
                cin.get();     // Đợi người dùng nhấn Enter
                return 1;             
            }
            
        } else if (choice == "2") {
            adminMode=1;
            do{
                cout<<"\033[36m"<<"Login as a Admin: "<<"\033[0m"<<endl;
                setAccountName(accountName);
                setAccountPassword(accountPassword);
                if(this->accountName != adminName || this->accountPassword != adminPassword){
                    cout << "\033[31m" << "Invalid adminName or adminPassword!" << "\033[0m" << endl;
                    char rep;
                    cout << "\033[33m" << "Do you want back (Y/N)?--> " << "\033[0m";
                    cin>>rep;
                    rep=toupper(rep);
                    if(rep=='Y') break;
                    system("cls");
                }
            }
            while(this->accountName != this->adminName || this->accountPassword != this->adminPassword);
            if (this->accountName == this->adminName && this->accountPassword == this->adminPassword) {
                cout << "\033[32m" << "Login successful!" << "\033[0m" << endl;
                cout << "\033[33m" << "Now you are a Admin ! Press Enter to continue !" << "\033[0m" << endl;
                cin.ignore();  // Bỏ qua bất kỳ ký tự nào đã có sẵn trong bộ đệm
                cin.get();     // Đợi người dùng nhấn Enter
                return 1;
            }
        } else if(choice=="3") {
            return 0;
        } else {
            cout << "\033[31m" <<"Invalid choice!" << "\033[0m" << endl;
            delay(2000);
        }

        system("cls");
    }
    


}


//Xóa tài khoản
void Account::removedAccount(const string &userName,const string &fileName){
        ifstream inFile(fileName);
        if (!inFile) {
            cout << "\033[31m" << "Unable to open file to read" << "\033[0m" << endl;
            return;
        }

        vector<pair<string,string>> fileData;
        string line;
        bool found = false;

        // Đọc từng dòng trong file và tìm thuốc cần xóa
        while (std::getline(inFile, line)) {
             if (line.empty()) {
                continue;  // Bỏ qua dòng trống
            }

            stringstream ss(line);
            string accountName,accountPassword;
            getline(ss,accountName,' '); 
            getline(ss,accountPassword,' '); 


            if (accountName == userName) {
                found = true;  // Nếu tìm thấy ID, bỏ qua dòng này (không thêm vào fileData)
            } else {
                fileData.push_back({accountName,accountPassword});  // Lưu các dòng không bị xóa
            }
        }

        inFile.close();

        if (!found) {
            cout<<"\033[31m" << "Unable to find username " << userName << " to delete."<<"\033[0m" <<endl;
            return;
        }
        char rep;
        cout<<"\033[33m"<<"Are you sure you want to delete, the data will not be recoverable ! (Y/N)   "<<"\033[0m"; cin>>rep;
        rep=toupper(rep);
        if(rep!='Y'){
            system("cls");
            return;
        }
        // Ghi lại các dòng còn lại vào file (ghi đè file gốc)
        ofstream outFile(fileName);
        if (!outFile) {
            cerr<<"\033[31m" << "Unable to open file to record!"<<"\033[0m" <<endl;
            return;
        }

        for (const auto& row : fileData) {
            outFile << row.first<<" "<<row.second << "\n";
        }

        outFile.close();
        cout<<"\033[32m"<< "Account with username is " << userName << " have been removed successful."<<"\033[0m" <<endl;


}



// Hàm đọc file để lấy thông tin username và password
vector<pair<string,string>> Account::loadUserInfo(const string& filename) {
    ifstream file(filename);
    vector<pair<string,string>> users;
    string line;

    // Kiểm tra nếu không mở được file
    if (!file.is_open()) {
        cerr << "Could not open the file: " << filename << endl;
        return users;
    }

    // Đọc từng dòng trong file
    string storedName, storedPassword;
    while (file >> storedName >> storedPassword) {
        users.push_back({storedName, storedPassword});      
    }
    

    file.close();
    return users;
}
//Hàm menu đăng nhâp / đăng kí thông tin nguòi dùng

void Account::accountProcess(){
    string choice;
    while(1){
        Account p;
        showMenu1();
        cin >> choice;
        system("cls");
        if (choice == "1") {
            p.Register();
            delay(2000);
            
        } else if (choice == "2") {
            if(p.Login()){
                system("cls");
                if(adminMode){
                    Admin p1;
                    p1.adminProcess();
                }
                else{
                    User p2;
                    p2.setUserName(p.getAccountName());
                    p2.userProcess();
                }
            } 

        }
        else if(choice == "3"){
            cout<<"\033[32m"<<"AMSR Programming thank you very much"<< "\033[0m"<<endl;
            return;
        }   
        else {
            cout << "\033[31m" <<"Invalid choice!" << "\033[0m" << endl;
            delay(2000);
        }
        system("cls");
    }
    system("cls");

}