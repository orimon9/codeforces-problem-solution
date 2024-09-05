#include<bits/stdc++.h>
using namespace std;

int main() {
    std::string sellerName;
    double fixedSalary, totalSales;


    std::cin >> sellerName >> fixedSalary >> totalSales;


    double commission = totalSales * 0.15;
    double finalSalary = fixedSalary + commission;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "TOTAL = R$ " << finalSalary << std::endl;

    return 0;
}
