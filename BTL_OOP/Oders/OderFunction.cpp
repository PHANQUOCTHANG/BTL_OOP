
#pragma once
#include "Orders.h"

//Hàm ghi thông tin của 1 object Drug vào File
void Orders::writeOrderToFile(const string &fileName) {
        ofstream outFile(fileName, ios::app); // Mở file ở chế độ append
        if (!outFile) {
            return;
        }
        outFile << getId() << ";" << getBuyerName() << ";" << getName() << ";" << getExpirationDate() << ";" << getPrice() << ";"
                << getQuantityInStock() << ";" <<getDiscount()<<";"<< total << "\n";
        outFile.close();
        
}


// Hàm đọc tất cả thông tin từ file và lưu vào vector các đối tượng Drug
vector<Orders> Orders::readOrdersFromFile(const string &fileName) {
    vector<Orders> odersList;
    ifstream inFile(fileName);
    
    if (!inFile) {
        
        return odersList;
    }
    
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string item;
        vector<string> tokens;

        // Tách từng giá trị từ dòng CSV
        while (getline(ss, item, ';')) {
            tokens.push_back(item);
        }

        if (tokens.size() == 8) {
            // Tạo đối tượng Drug từ các giá trị đã đọc
            Orders order;
            order.setId(stoi(tokens[0])),
            order.buyerName=tokens[1],
            order.setName(tokens[2]),
            order.setExpirationDate(tokens[3]),
            order.setPrice(stoi(tokens[4])),
            order.setQuantityInStock(stoi(tokens[5]));
            order.setDiscount(stoi(tokens[6]));
            order.total=stoll(tokens[7]);
            odersList.push_back(order);
        }
    }
    
    inFile.close();
    return odersList;
}


// Hàm hiển thị bảng thuốc
void Orders::printOrdersList(Orders order) {
    ostringstream out;
    out << std::fixed << std::setprecision(2) << order.total;
    // In các loại thuốc trong bảng với độ rộng cột được định nghĩa trước
        std::cout << "|" << centerText(to_string(order.getId()), 3)   // STT
                  << "|" << centerText(order.buyerName, 25)  // Tên người dùng
                  << "|" << centerText(order.getName(), 20)   // Tên thuốc
                  << "|" << centerText(order.getExpirationDate(), 50)  // Thời gian mua
                  << "|" << centerText(formatNumberWithSpaces(order.getPrice()), 18)  // Giá
                  << "|" << centerText(to_string( order.getQuantityInStock()), 20)  // Số lượng
                  << "|" << centerText(formatNumberWithSpaces(order.getTotal()), 20)  // tổng tiền
                  << "|\n";
    

    // Đường kẻ ngang kết thúc
    for(int i=1;i<=164;++i){
        if(i==1 || i==5 || i==31 || i==52 || i == 103 || i==122 || i==143 || i==164) cout<<'+';
        else{
            cout<<'-';
        }
    }
    cout<<endl;


}
// in bill
void Orders::printOrdersListBill(Orders order) {
    // In các loại thuốc trong bảng với độ rộng cột được định nghĩa trước
    cout  << centerText(to_string(order.getId()), 3)   // STT
          << centerText(order.getName(), 77)   // Tên thuốc
          << centerText(to_string( order.getQuantityInStock()), 40)  // Số lượng
          << centerText(to_string(order.getPrice()), 40)  // Giá
          << centerText(formatNumberWithSpaces(order.getTotal()), 40)  // tổng tiền
          << "\n";
    
}

//Kế thừa thuốc tính từ thuốc
void Orders::inheritDrug(Drug drug){
    this->setName(drug.getName()),
    this->setPrice(drug.getPrice());

}




// Function to analyze order history
void Orders::analyzeSales(const vector<Orders>& orders) {
    // Maps to store sales data
    map<string, int> medicineSales;  // Medicine name -> Total quantity sold
    map<string, long long> revenueByMedicine;  // Medicine name -> Total revenue

    int totalOrders = 0;
    long long totalRevenue = 0;
    int totalQuantitySold = 0;

    // Analyzing the sales data
    for (const auto& order : orders) {
        totalOrders++;
        totalRevenue += order.getTotal();
        totalQuantitySold += order.getQuantityInStock();

        // Update medicine sales
        medicineSales[order.getName()] += order.getQuantityInStock();
        revenueByMedicine[order.getName()] += order.getTotal();
    }

    // Find the best-selling and worst-selling medicine
    string bestSellingMedicine, worstSellingMedicine;
    int maxSales = 0, minSales = INT_MAX;

    for (const auto& med : medicineSales) {
        if (med.second > maxSales) {
            maxSales = med.second;
            bestSellingMedicine = med.first;
        }
        if (med.second < minSales) {
            minSales = med.second;
            worstSellingMedicine = med.first;
        }
    }

    // Display analysis
    cout <<"\033[33m"<< "\n--- Sales Analysis ---\n";
    cout << "Total Orders: " << "\033[32m"<< totalOrders << "\n"<<"\033[33m";
    cout << "Total Revenue: " << "\033[32m"<< totalRevenue <<"\033[33m"<< " VND\n";
    cout << "Total Quantity Sold: " <<"\033[32m"<< totalQuantitySold <<"\033[33m"<< " items\n";
    cout << "Best-Selling Medicine: " <<"\033[32m"<< bestSellingMedicine <<"\033[33m"<< " (Sold: " <<"\033[32m"<< maxSales <<"\033[33m"<< " units)\n";
    cout << "Worst-Selling Medicine: " <<"\033[32m"<< worstSellingMedicine << "\033[33m"<<" (Sold: " <<"\033[32m"<< minSales <<"\033[33m"<< " units)\n";

    // Subjective analysis (recommendations)
    cout << "\n--- Recommendations ---\n";
    if (maxSales > 100) {
        cout << "Consider increasing stock for " <<"\033[32m"<< bestSellingMedicine << ", as it's selling very well.\n";
    } else {
        cout <<"\033[32m"<< bestSellingMedicine << " is selling steadily. Keep an eye on stock levels.\n";
    }

    if (minSales < 10) {
        cout << "Consider reducing stock or promotions for " <<"\033[32m"<< worstSellingMedicine << ", as it's not selling well.\n";
    }

    cout << "Ensure prices are competitive and monitor inventory regularly to meet demand.\n"<<"\033[0m";
}
