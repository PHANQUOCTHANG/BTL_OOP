#include "declareFunc.h"
// Ham main
int main()
{
    printPharmacyLogo();
    while (true)
    {
        if (_getch() == 13)
            break;
    }
    system("cls");
    Account::accountProcess();
    // Admin p ;
    // p.listRating() ;
}
