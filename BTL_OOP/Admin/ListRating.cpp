
#include "Admin.h"

vector<vector<string>> Admin::readFromFile()
{
    vector<vector<string>> ratingList;
    ifstream inFile("Admin/ListRating.txt");

    if (!inFile)
    {
        cout << "\033[31m" << "Unable to open file to read" << "\033[0m" << endl;
        return ratingList;
    }

    string line;
    while (std::getline(inFile, line))
    {
        stringstream ss(line);
        string item;
        vector<string> token;
        while (getline(ss, item, ';'))
        {
            token.push_back(item);
        }
        ratingList.push_back(token);
    }

    inFile.close();
    return ratingList;
}

void Admin::listRating()
{
    vector<vector<string>> ratingList = Admin::readFromFile();
    cout << YELLOW << "List Rating From User: \n\n"
         << RESET;
    int id = 1;
    int cnt = 1;
    for (auto list : ratingList)
    {
        cout << YELLOW << "Comment " << id << " : " << RESET << '\n';
        id++;
        cnt = 1;
        for (auto token : list)
        {
            if (cnt == 1)
            {
                cout << BLUE << "AccountName: " << token << RESET << endl;
            }
            else if (cnt == 2)
            {
                cout << BLUE << "Comment: " << token << RESET << endl;
            }
            else
            {
                cout << BLUE << "Time: " << token << RESET << endl;
            }
            cnt++;
        }
        cout << endl;
    }
    cout << YELLOW ;
    cout << "+-----------------------+\n";
    cout << "|    1. Back            |\n";
    cout << "+-----------------------+\n";
    cout << RESET ;
    int choice  ;
    cout << "Enter choice: " ;
    cin >> choice ;
    if (choice != 1) {
        cout << RED << "Invalid!" << RESET << endl  ;
        delay(1000) ;
        system("cls") ;
        Admin::listRating() ;
    }
}