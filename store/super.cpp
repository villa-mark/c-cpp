#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    double price;
};

void savePurchaseToFile(const map<int, int>& purchaseMap, const vector<Product>& products) {
    ofstream outFile("storefile.txt");
    double total = 0.0;
    for (const auto& entry : purchaseMap) {
        int index = entry.first;
        int quantity = entry.second;
        outFile << products[index].name << " - $" << products[index].price << " x " << quantity << endl;
        total += products[index].price * quantity;
    }
    outFile << "Total: $" << total << endl;
    outFile.close();
}

void viewPurchaseFromFile() {
    ifstream inFile("storefile.txt");
    string line;
    while (getline(inFile, line)) {
        cout <<"\t" << line << endl;
    }
    inFile.close();
}

int main() {
    vector<Product> products = {{"Product A", 30.0}, {"Product B", 20.0}, {"Product C", 12.0}, {"Product D", 34.0}};
    map<int, int> purchaseMap; // Key: product index, Value: quantity
    cout << "***************************************\n";
    cout << "\tWELCOME TO SUPERMARKET" << endl;
    
    
    while (true) {
        cout << "***************************************\n";
        cout << "\n\t1. List products" << endl;
        cout << "\t2. Make purchase" << endl;
        cout << "\t3. View purchase" << endl;
        cout << "\t4. Exit purchase" << endl;
        cout << "\n***************************************\n";
        int choice;
        cout << "Enter Choice[1-5]: ";
        cin >> choice;
        system("cls");
        
        switch (choice) {
            case 1:
            	cout << "***************************************\n";
                cout << "             LIST OF ITEMS" << endl;
                cout << "***************************************\n\n";
                for (int i = 0; i < products.size(); ++i) {
                    cout <<"\t" << i << ". " << products[i].name << " = $" << products[i].price << endl;
                }
                cout << "\n***************************************\n";
                break;
            
            case 2:
            	cout << "***************************************\n";
                cout << "             LIST OF ITEMS" << endl;
                cout << "***************************************\n\n";
                for (int i = 0; i < products.size(); ++i) {
                    cout <<"\t" << i << ". " << products[i].name << " = $" << products[i].price << endl;
                }
                cout << "\n***************************************\n";
                cout << "Enter the item indexes to purchase (enter -1 to finish):" << endl;
                int itemIndex;
                while (cin >> itemIndex && itemIndex != -1) {
                    if (itemIndex >= 0 && itemIndex < products.size()) {
                        purchaseMap[itemIndex]++;
                    } else {
                        cout << "Invalid item index. Please enter a valid index." << endl;
                    }
                }
                savePurchaseToFile(purchaseMap, products);
                cout << "Purchase saved to storefile.txt" << endl;
                break;
            
            case 3:
            	cout << "***************************************\n";
                cout << "Purchase items:" << endl;
                cout << "***************************************\n";
                viewPurchaseFromFile();
                break;
            
            case 4:
                cout << "GOODBYE" << endl;
                return 0;
            
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
    
    return 0;
}
