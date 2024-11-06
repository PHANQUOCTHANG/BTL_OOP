
#include "Admin.h"


//Show Menu
void Admin::printDrugManaMenu(){
       cout<<"+---------------"<<"\033[35m"<<"DRUG MANAGER"<<"\033[0m"<<"-----------------+\n";
 cout << "|    1.Show Drug List                        |\n";
 cout << "|    2.Add more medicine to the warehouse    |\n";
 cout << "|    3.Remove medicine                       |\n";
 cout << "|    4.Modify drug information               |\n";
 cout << "|    5.Add discount                          |\n";
 cout << "|    6.Back                                  |\n";
   cout<<"+--------------------------------------------+\n";
   cout<<"Enter your choice: ";
}


//Hàm Quản lý cập nhật thông tin về thuốc
void Admin::drugManaUpdate(int id,Drug &origin){
    system("cls");
    int choice;
    while (1)
    {
      
      Drug temp=origin;
      cout<<"\033[33m"<<"Drug's id need to update: "<<id<<"\033[0m"<<endl;
      
      temp.display();
      drugManaMenuUpdateMenu();
      cin>>choice;  
      switch (choice)
      {
        case 1:
        {
          cin.ignore();
          string Name;
          cout<<"\033[36m"<<"Update name: "<<"\033[0m"; getline(cin,Name);
          temp.setName(Name);
          break;
    
        }
        case 2:
        {
          cin.ignore();
          string Type;
          cout<<"\033[36m"  <<"Update type: "<<"\033[0m"; getline(cin,Type);
          temp.setType(Type);
          break;
    
        }
        case 3:
        {
          cin.ignore();
          string Ingredients;
          cout<<"\033[36m"  <<"Update ingredients: "<<"\033[0m" ; getline(cin,Ingredients);
          temp.setIngredients(Ingredients);
          break;
    
        }
        case 4:
        {
          cin.ignore();
          string Uses;
          cout<<"\033[36m"  <<"Update uses: "<<"\033[0m"; getline(cin,Uses);
          temp.setUses(Uses);
          break;
    
        }
        case 5:
        {
          cin.ignore();
          string Dosage;
          cout<<"\033[36m"  <<"Update dosage: "<<"\033[0m"; getline(cin,Dosage);
          temp.setDosage(Dosage);
          break;
    
        }
        case 6:
        {
          cin.ignore();
          string SideEffects;
          cout<<"\033[36m"  <<"Update sideEffects: "<<"\033[0m" ; getline(cin,SideEffects);
          temp.setSideEffects(SideEffects);
          break;
    
        }
        case 7:
        {
          cin.ignore();
          string ExpirationDate;
          cout<<"\033[36m"  <<"Update expirationDate: "<<"\033[0m"; getline(cin,ExpirationDate);
          temp.setExpirationDate(ExpirationDate);
          break;
    
        }
        case 8:
        {
          int Price;
          cout<<"\033[36m"  <<"Update price: "<<"\033[0m"; cin>>Price;
          temp.setPrice(Price);
          break;
    
        }
        case 9:
        {
          int QuantityInStock;
          cout<<"\033[36m"  <<"Update quantityInStock: "<<"\033[0m"; cin>>QuantityInStock;
          temp.setQuantityInStock(QuantityInStock);
          break;
        }
        case 10:
        {
          system("cls");
          return;
        }
        default:{
          cout<<"\033[31m"  <<"Invalid selection"<<"\033[0m"<<endl;
          break;
        }
      }
        char rep;
        cout<<"\033[33m"<<"Are you sure you want to update, the data will not be recoverable ! (Y/N)   "<<"\033[0m"; cin>>rep;
        rep=toupper(rep);
        if(rep=='Y'){
          Drug::updateDrugInFile(id,temp,"drugStore/wareHouse.txt");
          origin = temp;
          std::cerr<< "\033[32m"  << "Successful update!"<< "\033[0m" <<endl;        
        }
        else{
          cout<<"\033[32m"  <<"Cancel the update successfully !"<<"\033[0m"  <<endl;
        }
        delay(2000);
        system("cls");
    }

}


//Hàm menu tổng
void Admin::drugManaProcess(){
    int choice;
    int id;
    while (1)
    {
      vector<Drug> temp = Drug::readFromFile("drugStore/wareHouse.txt");
      printDrugManaMenu();
      cin>>choice;
      switch (choice){
        
        case 1:{
          system("cls");
          if(temp.size() ==0){
            cout<<"\033[31m"<<"List is empty ! Please add more infomation "<<"\033[0m"<<endl;
            break;
          }
          title();
          for(auto x:temp){
            Drug::printDrugList(x);
          }
          break;
        }
        case 2:
        {
          system("cls");
          cin.ignore();
          Drug p; cin>>p;
          p.writeToFile("drugStore/wareHouse.txt");
          cout<<"\033[32m"<<"Add new drug successful"<<"\033[0m"<<endl;
          break;
        }
        case 3:
        {
          system("cls");
          if(temp.size() ==0){
            cout<<"\033[31m"<<"List is empty ! Please add more infomation "<<"\033[0m"<<endl;
            break;
          }
          cout<<"\033[36m"<<"Enter Drug's id need to delete: "<<"\033[0m";
          cin>>id;
          if(id> temp.size() || id <0){
            cout<<"\033[31m"<<"Id not valid !"<<"\033[0m"<<endl;
          }
          else{
            system("cls");
            title();
            Drug::printDrugList(temp[id-1]);
              char rep;
              cout<<"\033[33m"<<"Are you sure you want to delete, the data will not be recoverable ! (Y/N)  "<<"\033[0m"; cin>>rep;
              rep=toupper(rep);
              if(rep=='Y'){
                Drug::deleteDrugById(id,"drugStore/wareHouse.txt");
              }
              else{
                cout<<"\033[32m"<<"Cancel the delete successfully !"<<"\033[0m"<<endl;
              }

          }
          break;
        }
        case 4:
        {
          system("cls");
          if(temp.size() ==0){
            cout<<"\033[31m"<<"List is empty ! Please add more infomation "<<"\033[0m"<<endl;
            break;
          }
          system("cls");
          cout<<"\033[36m"<<"Enter Drug's id need to update: "<<"\033[0m";
          cin>>id;
          if(id> temp.size() || id <0){
            cout<<"\033[31m"<<"Id not valid !"<<"\033[0m"<<endl;
          }
          else{
            Admin::drugManaUpdate(id,temp[id-1]);
          }
          break;
        }
        case 5:
        {
          system("cls");
          if(temp.size() ==0){
            cout<<"\033[31m"<<"List is empty ! Please add more infomation "<<"\033[0m"<<endl;
            break;
          }
          system("cls");
          int id;
          cout<<"\033[36m"<<"Enter Drug's id need to update: "<<"\033[0m";
          cin>>id;
          if(id> temp.size() || id <0){
            cout<<"\033[31m"<<"Id not valid !"<<"\033[0m"<<endl;
          }
          else{
            title();
            Drug::printDrugList(temp[id-1]);
            int sale;
            cout<<"Enter the discount you want: " ; cin>>sale;
            Drug DisCount = temp[id-1];
            DisCount.setDiscount(sale);
            Drug::updateDrugInFile(id,DisCount,"drugStore/wareHouse.txt");
            cout<<"\033[32m"<<"Add discount successfully"<<"\033[0m"<<endl;
          }
          break;
        }
        case 6:
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



