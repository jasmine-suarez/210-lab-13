// COMSC-210 | Lab 13 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const int DAYS = 30;

int main() {
    vector<double> gasPrices(DAYS);

    // Read from file
    ifstream fin;
    fin.open("gas_prices.txt");
    if (fin.good()) {
        for (int i = 0; i < DAYS; i++) {
            fin >> gasPrices[i];
        }
        fin.close();
    }
    else
        cout << "File not found.\n";

    cout << "===== GAS PRICE TRACKER =====" << endl;

    cout << "1. Gas Station 1 prices from the last " << gasPrices.size() << " days:" << endl;
    for (double val : gasPrices) cout << val << " "; cout << endl;

    // stats
    cout << "2. First day price: " << gasPrices.front() << endl;
    cout << "3. Last day price: " << gasPrices.back() << endl;
    cout << "4. Day 15 price: " << gasPrices.at(14) << endl;
    cout << "5. Address: " << gasPrices.data() << endl;

    cout << "6. Highest price: " << *max_element(gasPrices.begin(), gasPrices.end()) << endl;
    cout << "7. Lowest price: " << *min_element(gasPrices.begin(), gasPrices.end()) << endl;
    double avg = accumulate(gasPrices.begin(), gasPrices.end(), 0.0) / gasPrices.size();
    cout << fixed << setprecision(2) << "8. Average price: " << avg << endl;

    // sort elements
    sort(gasPrices.begin(), gasPrices.end());
    cout << "9. Sorted: ";
    for (double val : gasPrices) cout << val << " "; cout << endl;
    sort(gasPrices.rbegin(), gasPrices.rend());
    cout << "10. Reverse sorted: ";
    for (double val : gasPrices) cout << val << " "; cout << endl;

    // find an element
    double target = 4.33;
    vector<double>::iterator it;
    it = find(gasPrices.begin(), gasPrices.end(), target);
    cout << "11. Value " << target;
     if (it != gasPrices.end())
        cout << " found in position " << it - gasPrices.begin() << endl;
     else
        cout << " was not found.\n";
    
    // Station 2 with one value
    vector<double> station2(DAYS, 4.00);
    cout << "12. Gas Station 2 first price: " << station2.front() << endl;
    gasPrices.swap(station2);
    cout << "13. After swap, Station 1 first price: " << gasPrices.front() << endl;

    return 0;
}