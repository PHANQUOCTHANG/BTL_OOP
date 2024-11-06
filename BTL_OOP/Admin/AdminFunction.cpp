
#include "Admin.h"

//Show Menu
void Admin::adminMenu(int selection)
{
    system("cls");
    tab();
    cout << "+-----------------" << "\033[35m" << "Admin" << "\033[0m" << "-----------------+\n";
    // Mục 1: User
    tab();
    cout << "|" << (selection == 1 ? "\033[38;5;214m ->      1. Drug Management            \033[0m|\n" 
                                    : "          1. Drug Management           |\n");
    // Mục 2: Admin
    tab();
    cout << "|" << (selection == 2 ? "\033[38;5;214m ->      2. Inventory Management       \033[0m|\n" 
                                    : "          2. Inventory Management      |\n");
    // Mục 3: Back
    tab();
    cout << "|" << (selection == 3 ? "\033[38;5;214m ->      3. Sales Management           \033[0m|\n" 
                                    : "          3. Sales Management          |\n");
    tab();
    cout << "|" << (selection == 4 ? "\033[38;5;214m ->      4. User Management            \033[0m|\n"
                                    : "          4. User Management           |\n");
    tab();
    cout << "|" << (selection == 5 ? "\033[38;5;214m ->      5. Log out                    \033[0m|\n"
                                : "          5. Log out                   |\n");                                
    tab();
    cout << "+---------------------------------------+\n";
    tab();
    cout << "\t  \033[32mUSE \033[1;35mUP\033[0m" 
     << "\033[32m/\033[1;35mDOWN\033[0m" 
     << "\033[32m TO SELECT\033[0m" << endl;
}



//Hàm Admin Menu tổng
void Admin::adminProcess(){
  int choice;
  while (1)
  {
    
    int selection = 1;  // Start with the first option selected
    char key;
    do {
        adminMenu(selection);
        key = _getch();  // Get a single character input
        if (key == 72) {  // Up arrow key code
            selection--;
            if (selection < 1) selection = 5;
        } else if (key == 80) {  // Down arrow key code
            selection++;
            if (selection > 5) selection = 1;
        }
    } while (key != '\r');  // Continue until the Enter key is pressed
    choice = selection;
    switch (choice){
      
      case 1:{
        system("cls");
        drugManaProcess();
        break;
      }
      case 2:
      {
        system("cls");
        inventoryManaProcess();
        break;
      }
      case 3:
      {
        system("cls");
        salesManaProcess();
        break;
      }
      case 4:
      {
        system("cls");
        userManaProcess();
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

  }
}

