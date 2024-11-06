#pragma once
#include "User.h"

// Show Menu 1
void User::userBuyDrugMenu1()
{
  cout << "+------------------" << "\033[35m" << "BUY DRUG" << "\033[0m" << "------------------+\n";
  cout << "|    1. View all drug in store               |\n";
  cout << "|    2. Search Medicine by Name              |\n";
  cout << "|    3. Back                                 |\n";
  cout << "+--------------------------------------------+\n";
  cout << "Enter your choice: ";
}

// Show Menu 2
void userBuyDrugMenu2()
{
  cout << "+---------------" << "\033[35m" << "BUY SELECTION" << "\033[0m" << "----------------+\n";
  cout << "|    1. Buy now                              |\n";
  cout << "|    2. Add cart                             |\n";
  cout << "|    3. Back                                 |\n";
  cout << "+--------------------------------------------+\n";
  cout << "Enter your choice: ";
}

// Phương thức thanh toán
string paymentMethod(int choice)
{
  cout << "\n\033[36m" << "Choose a payment method:" << "\033[0m" << endl;
  cout << "+------------------------------------------------+" << endl;
  cout << "|    1. Pay on Pickup       2. Online payment    |\n";
  cout << "+------------------------------------------------+" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  cout << "aaaA";
  while (1)
  {
    if (choice == 1)
    {
      return "Pay on Pickup";
    }
    else if (choice == 2)
    {
      return "Online payment";
    }
    else
    {
      cout << "\033[31m" << "Invalid choose" << "\033[0m" << endl;
    }
  }
  return "";
}

// Thanh Toán
void User::payment(int id, vector<Drug> temp)
{
  string fileName;
  int choice;
  char rep;
  while (1)
  {
    if (temp[id - 1].getOOT() || temp[id - 1].getQuantityInStock() <= 0)
    {
      system("cls");
      cout << "\033[33m" << "The product is currently out of stock! Please select another product !" << "\033[0m" << endl;
      return;
    }
    system("cls");
    temp[id - 1].display();
    userBuyDrugMenu2();
    cin >> choice;
    int quanlity;
    double totalMoney;
    switch (choice)
    {
    case 1:
    {
      do
      {
        cout << "\n\033[36m" << "Enter the quantity you want to buy :" << "\033[0m";
        cin >> quanlity;
        if (quanlity > temp[id - 1].getQuantityInStock())
        {
          cout << "\033[31m" << "Excess quantity!" << "\033[0m" << endl;
        }
        if (quanlity <= 0)
          cout << "Invalid" << endl;
      } while (quanlity > temp[id - 1].getQuantityInStock() || quanlity <= 0);
      string paymentMethodRes = paymentMethod(choice);
      system("cls") ;
      fileName = "Account_mangement/Account/userInfor/";
      fileName += this->getAccountName() + "infor.txt";
      vector<User> token = findUserByUsername(fileName, this->getAccountName());
      int id_infor;
      do
      {
        for (int i = 0; i < token.size(); ++i)
        {
           cout << "\033[33m" << "Information " << i + 1 << ": " << "\033[0m" << endl;
          // In thông tin khách hàng với định dạng thẳng hàng
          cout << left << setw(12) << "\033[36mFull Name:\033[32m" << setw(30) << token[i].getName();  // Cột "Full Name"
          cout << left << setw(10) << "\033[36mAddress:\033[32m" << setw(30) << token[i].getAddress(); // Cột "Address"
          cout << left << setw(10) << "\033[36mHotline:\033[32m" << setw(15) << token[i].getPhoneNumber() << "\033[0m"; // Cột "Hotline"
          cout << endl;
          cout << endl;
        }
        cout << "Choose your Address: ";
        cin >> id_infor;
        if (!(id_infor > 0 && id_infor <= token.size()))
        {
          cout << "\033[31m" << "Address not valid !"<<"\033[0m"<<endl;
          delay(1000);
          system("cls");
        }
      } while (!(id_infor > 0 && id_infor <= token.size()));
      system("cls") ;
      fileName = "Transactions/usesHistory/";
      fileName += this->getAccountName() + ".txt";
      totalMoney = quanlity * temp[id - 1].getPrice();
      Orders demo(this->getAccountName(),temp[id - 1].getName(),temp[id - 1].getPrice(),quanlity,getCurrentTime(),temp[id - 1].getDiscount(),totalMoney);
      vector<Orders> t;
      t.push_back(demo);
      bill(token[id_infor - 1], t, paymentMethodRes);
      cout << "\033[33m";
      cout << "+-------------------------+                                  +----------------------+" << endl;
      cout << "|         1. Back         |                                  |       2. Order       |" << "\n";
      cout << "+-------------------------+                                  +----------------------+" << endl;
      cout << "\033[0m";

      cout << "Enter to choice : ";
      cin >> choice;
      if (choice == 1)
        system("cls");
      else
      {
        Drug::DecreseQuan(id, temp[id - 1], "drugStore/wareHouse.txt", quanlity);
        demo.setTotal(demo.getTotal() - (1.0 * (demo.getPrice() * demo.getDiscount() / 100) *demo.getQuantityInStock()));
        demo.setId(Drug::countDrugsInFile(fileName));
        demo.writeOrderToFile(fileName);
        demo.setId(Drug::countDrugsInFile("Transactions/HistorySales.txt"));
        demo.writeOrderToFile("Transactions/HistorySales.txt");
        system("cls");
        cout << "\033[32m" << "Successful order confirmation.!" << "\033[0m" << endl;
        delay(2000);
        system("cls") ;
      }
      return;
    }
    case 2:
    {
      do
      {
        cout << "\033[36m" << "Enter the quantity you want to add cart :" << "\033[0m";
        cin >> quanlity;
        if (quanlity > temp[id - 1].getQuantityInStock())
        {
          cout << "\033[31m" << "Excess quantity!" << "\033[0m" << endl;
        }
      } while (quanlity > temp[id - 1].getQuantityInStock());


      totalMoney = (temp[id - 1].getPrice() ) * quanlity;
      cout << "\033[33m";
      cout << "+-------------------------+                                  +----------------------+" << endl;
      cout << "|         1. Back         |                                  |     2. Add cart      |" << "\n";
      cout << "+-------------------------+                                  +----------------------+" << endl;
      cout << "\033[0m";
      cout << "Enter to choice : ";
      cin >> choice;
      if (choice == 1)
        system("cls");
      else{
        fileName = "Transactions/usesHistory/";
        fileName += this->getAccountName() + "cart.txt";
        Drug::DecreseQuan(id, temp[id - 1], "drugStore/wareHouse.txt", quanlity);
        Orders demo(this->getAccountName(),temp[id - 1].getName(),temp[id - 1].getPrice(),quanlity,getCurrentTime(),temp[id - 1].getDiscount(),totalMoney);
        demo.setId(Drug::countDrugsInFile(fileName));
        demo.writeOrderToFile(fileName);
        cout << "\033[32m" << "Successful add cart" << "\033[0m" << endl; 
        delay(2000);
        system("cls");
      }
      return;
    }
    case 3:
    {
      system("cls");
      return;
    }
    default:
      cout << "\033[31m" << "Invalid selection" << "\033[0m" << endl;

      break;
    }
  }
}

// Tìm kiếm thuốc 1
void searchMedicines(const vector<Drug> &medicines, const string &query)
{
  cout << "\033[33m" << "Search results for \"" << query << "\":" << "\033[0m" << endl;
  bool found = false;
  title();
  for (const auto &med : medicines)
  {
    if (med.getName().find(query) != string::npos)
    { // Check if query matches medicine name
      Drug::printDrugList(med);
      found = true;
    }
  }
  if (!found){
    system("cls");
    cout << "\033[31m" << "No medicines found.\n"
         << "\033[0m";
  }
}

// Tìm kiếm thuốc 2
void searchDrug(string name, vector<Drug> temp)
{
  title();
  for (auto x : temp)
  {
    if (x.getName().find(name) != string::npos)
    {
      Drug::printDrugList(x);
    }
  }
}

// Menu tổng
void User::userBuyDrugProcess()
{
  int choice;
  int id;
  bool search = 0;
  while (1)
  {

    vector<Drug> temp = Drug::readFromFile("drugStore/wareHouse.txt");
    for (int i = 0; i < temp.size(); ++i)
    {
      if (temp[i].getQuantityInStock() <= 0)
      {
        Drug a = temp[i];
        a.setOOT(1);
        Drug::updateDrugInFile(i + 1, a, "drugStore/wareHouse.txt");
      }
    }
    userBuyDrugMenu1();
    cin >> choice;
    system("cls");

    switch (choice)
    {
      case 1:
      {
        system("cls");
        title();
        for (auto x : temp)
        {
          Drug::printDrugList(x);
        }
        cout<<"\033[36m"<<"Enter Drug's id you want or (-1) to Back: "<<"\033[0m";
        cin >> id;
        if(id == -1){
          system("cls");
          break;
        }
        else if (id > temp.size() || id < 0)
        {
          cout << "\033[31m" << "Id not valid !" << "\033[0m" << endl;
          delay(1000);
          system("cls");
          break;
        }
        payment(id, temp);

        break;
      }
      case 2:
      {
          system("cls");
          string query = "";
          char ch = '\0'; // Initialize ch to avoid undefined behavior
          while (true)
          {
              cout << "\033[36m" << "\nPlease type drug's name to search: " << "\033[0m";
              cout << query;
              
              ch = _getch();
      
              if (ch == '\r') // Enter key
                  break;
              else if (ch == '\b') // Backspace
              {
                  if (!query.empty())
                      query.pop_back();
              }
              else if (ch != '\n') // Add character to query if not newline
              {
                  query += ch;
              }
      
              // Clear screen only if necessary
              system("cls");
      
              // Search and display results if the query is not empty
              if (!query.empty())
              {
                  searchMedicines(temp, query);
              }
          }
      
          system("cls");
          searchDrug(query, temp);
      
          cout << "\033[36m" << "Enter Drug's id you want or (-1) to Back: " << "\033[0m";
          cin >> id;
      
          if (id == -1)
          {
              system("cls");
              break;
          }
          if (id > temp.size() || id < 0)
          {
              cout << "\033[31m" << "Id not valid!" << "\033[0m" << endl;
              delay(1000);
              system("cls");
              continue;
          }
      
          payment(id, temp);
          break;
      }

      case 3:
      {
        system("cls");
        return;
      }
      default:
      {
        cout << "\033[31m" << "Invalid selection" << "\033[0m" << endl;
        break;
      }
    }
  }
}