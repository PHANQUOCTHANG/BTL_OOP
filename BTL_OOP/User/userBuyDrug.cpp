#pragma once
#include "User.h"

// Show Menu 1
void User::userBuyDrugMenu1()
{
  cout << "+-------------------" << "\033[35m" << "User" << "\033[0m" << "---------------------+\n";
  cout << "|    1. View all drug in store               |\n";
  cout << "|    2. Search Medicine by Name              |\n";
  cout << "|    3. Back                                 |\n";
  cout << "+--------------------------------------------+\n";
  cout << "Enter your choice: ";
}

// Show Menu 2
void userBuyDrugMenu2()
{
  cout << "+-------------------" << "\033[35m" << "User" << "\033[0m" << "---------------------+\n";
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
      string filename = "Account_mangement/Account/userInfor/";
      filename += this->getAccountName() + "infor.txt";
      vector<User> token = findUserByUsername(filename, this->getAccountName());
      int id;
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
        cout << "Choose your Addres: ";
        cin >> id;
        if (!(id > 0 && id <= token.size()))
        {
          cout << "Address not valid !";
          system("cls");
        }
      } while (!(id > 0 && id < 5));
      system("cls") ;
      string fileName = "Transactions/usesHistory/";
      fileName += this->getAccountName() + ".txt";
      Orders demo;
      totalMoney = quanlity * temp[id - 1].getPrice();
      demo.inheritDrug(temp[id - 1]);
      demo.setId(Drug::countDrugsInFile(fileName));
      demo.setTotal(totalMoney);
      demo.setDiscount(temp[id - 1].getDiscount());
      demo.setQuantityInStock(quanlity);
      demo.setExpirationDate(getCurrentTime());
      demo.setBuyerName(this->getAccountName());
      vector<Orders> t;
      t.push_back(demo);
      bill(token[id - 1], t, paymentMethodRes);
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
        demo.writeOrderToFile(fileName);
        demo.writeOrderToFile("Transactions/HistorySales.txt");
        system("cls");
        cout << "\033[32m" << "Successful order confirmation" << "\033[0m" << endl;
        system("cls") ;
        delay(2000);
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
      totalMoney = (temp[id - 1].getPrice() - 1.0 * (temp[id - 1].getPrice() * (1.0 * temp[id - 1].getDiscount() / 100))) * quanlity;
      cout << "\033[33m" << "Total money is: " << "\033[0m" << totalMoney << endl;
      cout << "\033[32m" << "Successful add cart" << "\033[0m" << endl;
      Drug::DecreseQuan(id, temp[id - 1], "drugStore/wareHouse.txt", quanlity);
      string fileName = "Transactions/usesHistory/";
      fileName += this->getAccountName() + "cart.txt";
      Orders demo;
      demo.inheritDrug(temp[id - 1]);
      demo.setId(Drug::countDrugsInFile(fileName));
      demo.setTotal(totalMoney);
      demo.setQuantityInStock(quanlity);
      demo.setExpirationDate(getCurrentTime());
      demo.setBuyerName(this->getAccountName());
      demo.writeOrderToFile(fileName);
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
  for (const auto &med : medicines)
  {
    if (med.getName().find(query) != string::npos)
    { // Check if query matches medicine name
      showListDrug2(med);
      found = true;
    }
  }
  if (!found)
    cout << "\033[31m" << "No medicines found.\n"
         << "\033[0m";
}

// Tìm kiếm thuốc 2
void searchDrug(string name, vector<Drug> temp)
{
  for (auto x : temp)
  {
    if (x.getName().find(name) != string::npos)
    {
      showListDrug2(x);
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
      phu3();
      for (auto x : temp)
      {
        showListDrug2(x);
      }
      cout << "\033[36m" << "Enter Drug's id you want: " << "\033[0m";
      cin >> id;
      if (id > temp.size() || id < 0)
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
      char ch;
      while (ch != '\r')
      {
        cout << "\033[36m" << "\nPlease type drug's name to search: " << "\033[0m";
        cout << query;
        ch = _getch();
        if (ch != '\r')
          system("cls");
        if (ch == '\r')
          break;
        if (ch == '\b')
        { // Handle Backspace
          if (!query.empty())
            query.pop_back();
        }
        else if (ch != '\n')
        { // Add character to query if not newline
          query += ch;
        }

        if (!query.empty())
        {
          searchMedicines(temp, query); // Search and display results
        }
      }
      system("cls");
      searchDrug(query, temp);
      cout << "\033[36m" << "Enter Drug's id you want: " << "\033[0m";
      cin >> id;
      if (id > temp.size() || id < 0)
      {
        cout << "\033[31m" << "Id not valid !" << "\033[0m" << endl;
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