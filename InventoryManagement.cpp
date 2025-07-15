#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>  // For system("CLEAR") to clear the screen (Windows)

using namespace std;

bool TEST_MODE = false;
static int testMenuChoice = 0;
static int testProductID   = 0;
static int testQuantity    = 0;

struct Supplier {
    string name;
    string contactInfo;
};

struct Product {
    int productID;
    string name;
    double price;
    int quantityInStock;
    Supplier* suppliers;
    int numSuppliers;
};

struct Node {
    Product product;
    Node* next;
};

Node* head = NULL;

struct Sale {
    int saleID;
    Product product;
    int quantitySold;
    double totalSaleAmount;
};

const int MAX_SALES = 10;
Sale salesList[MAX_SALES];
int salesCount = 0;

// Function prototypes
void addProduct();
void updateProduct();
void searchProduct();
void trackSale();
void deleteProduct();
void displayProducts();
void generateSalesReport();
void saveInventoryToFile();
void loadInventoryFromFile();
void welcome();
void mainMenu();

bool getValidInt(int &value, const string &prompt, bool allowZero = false) {
    string input;
    while (true) {
        cout << prompt;
        if (TEST_MODE) {
            if (prompt == "Enter your choice: ") {
                switch(testMenuChoice++) {
                    case 0: input = "1"; break;
                    default: input = "10"; break;
                }
            } else if (prompt == "Enter product ID: ") {
                switch(testProductID++) {
                    case 0: input = ""; break;
                    case 1: input = "-1"; break;
                    case 2: input = "abc"; break;
                    case 3: input = "123"; break;
                    default:
                        value = 123;
                        return true;
                }
            } else {
                switch(testQuantity++) {
                    case 0: input = ""; break;
                    case 1: input = "-1"; break;
                    case 2: input = "abc"; break;
                    case 3: input = "5"; break;
                    default:
                        value = 5;
                        return true;
                }
            }
        } else {
            getline(cin, input);
        }
        if (input.empty()) {
            cout << "Error: Input cannot be empty. Please try again.\n";
            continue;
        }
        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            if (allowZero && value >= 0)
                return true;
            else if (!allowZero && value > 0)
                return true;
            cout << "Error: Please enter a " << (allowZero ? "non-negative" : "positive") << " number.\n";
        } else {
            cout << "Error: Invalid number format. Please try again.\n";
        }
    }
    return false;
}

bool getValidDouble(double &value, const string &prompt) {
    string input;
    while (true) {
        cout << prompt;
        if (TEST_MODE) {
            static int testCase = 0;
            switch(testCase++) {
                case 0: input = ""; break;
                case 1: input = "-1.5"; break;
                case 2: input = "abc"; break;
                case 3: input = "99.99"; break;
                default:
                    value = 99.99;
                    return true;
            }
        } else {
            getline(cin, input);
        }
        if (input.empty()) {
            cout << "Error: Input cannot be empty. Please try again.\n";
            continue;
        }
        stringstream ss(input);
        if (ss >> value && ss.eof() && value > 0)
            return true;
        cout << "Error: Please enter a positive number.\n";
    }
    return false;
}

bool getValidString(string &value, const string &prompt) {
    while (true) {
        cout << prompt;
        if (TEST_MODE) {
            static int testCase = 0;
            switch(testCase++) {
                case 0: value = ""; break;
                case 1: value = "Test Value"; break;
                default:
                    value = "Test Value";
                    return true;
            }
        } else {
            getline(cin, value);
        }
        if (value.empty()) {
            cout << "Error: Input cannot be empty. Please try again.\n";
            continue;
        }
        return true;
    }
    return false;
}

void addProduct() {
    Node* newNode = new Node();
    newNode->product.numSuppliers = 0;
    newNode->product.suppliers = NULL;

    if (!getValidInt(newNode->product.productID, "Enter product ID: ")) {
        delete newNode;
        return;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->product.productID == newNode->product.productID) {
            cout << "Error: Product ID already exists.\n";
            delete newNode;
            return;
        }
        current = current->next;
    }

    if (!getValidString(newNode->product.name, "Enter product name: ")) {
        delete newNode;
        return;
    }

    if (!getValidDouble(newNode->product.price, "Enter product price: ")) {
        delete newNode;
        return;
    }

    if (!getValidInt(newNode->product.quantityInStock, "Enter quantity in stock: ", true)) {
        delete newNode;
        return;
    }

    int numSuppliers;
    if (!getValidInt(numSuppliers, "Enter number of suppliers: ")) {
        delete newNode;
        return;
    }

    newNode->product.numSuppliers = numSuppliers;
    newNode->product.suppliers = new Supplier[numSuppliers];

    for (int i = 0; i < numSuppliers; ++i) {
        stringstream ss;
        ss << "Enter supplier " << (i + 1) << " name: ";
        if (!getValidString(newNode->product.suppliers[i].name, ss.str())) {
            delete[] newNode->product.suppliers;
            delete newNode;
            return;
        }

        ss.str("");
        ss.clear();
        ss << "Enter supplier " << (i + 1) << " contact info: ";
        if (!getValidString(newNode->product.suppliers[i].contactInfo, ss.str())) {
            delete[] newNode->product.suppliers;
            delete newNode;
            return;
        }
    }

    newNode->next = head;
    head = newNode;
    cout << "\n=== Product Added Successfully! ===\n";
    cout << "Product '" << newNode->product.name << "' (ID: " << newNode->product.productID << ") has been added.\n";
    cout << "Price: $" << fixed << setprecision(2) << newNode->product.price << "\n";
    cout << "Quantity in stock: " << newNode->product.quantityInStock << "\n";
    cout << "Number of suppliers: " << newNode->product.numSuppliers << "\n";
    cout << "===============================\n";
}

void updateProduct() {
    int productID;
    if (!getValidInt(productID, "Enter the Product ID to update: "))
        return;

    Node* current = head;
    bool found = false;
    while (current != NULL) {
        if (current->product.productID == productID) {
            found = true;
            cout << "Product found: " << current->product.name << "\n";

            string input;
            cout << "Do you want to update the name? (y/n): ";
            getline(cin, input);
            if (input == "y" || input == "Y") {
                if (!getValidString(current->product.name, "Enter new product name: "))
                    return;
            }

            cout << "Do you want to update the price? (y/n): ";
            getline(cin, input);
            if (input == "y" || input == "Y") {
                if (!getValidDouble(current->product.price, "Enter new product price: "))
                    return;
            }

            cout << "Do you want to update the quantity? (y/n): ";
            getline(cin, input);
            if (input == "y" || input == "Y") {
                if (!getValidInt(current->product.quantityInStock, "Enter new quantity in stock: ", true))
                    return;
            }

            cout << "Do you want to update suppliers? (y/n): ";
            getline(cin, input);
            if (input == "y" || input == "Y") {
                int numSuppliers;
                if (!getValidInt(numSuppliers, "Enter number of suppliers: "))
                    return;
                delete[] current->product.suppliers;
                current->product.suppliers = new Supplier[numSuppliers];
                current->product.numSuppliers = numSuppliers;
                for (int i = 0; i < numSuppliers; ++i) {
                    stringstream ss;
                    ss << "Enter supplier " << (i + 1) << " name: ";
                    if (!getValidString(current->product.suppliers[i].name, ss.str()))
                        return;

                    ss.str("");
                    ss.clear();
                    ss << "Enter supplier " << (i + 1) << " contact info: ";
                    if (!getValidString(current->product.suppliers[i].contactInfo, ss.str()))
                        return;
                }
            }
            cout << "\n=== Product Updated Successfully! ===\n";
            cout << "Product '" << current->product.name << "' (ID: " << current->product.productID << ") has been updated.\n";
            cout << "Current price: $" << fixed << setprecision(2) << current->product.price << "\n";
            cout << "Current stock: " << current->product.quantityInStock << "\n";
            cout << "Number of suppliers: " << current->product.numSuppliers << "\n";
            cout << "===============================\n";
            break;
        }
        current = current->next;
    }
    if (!found)
        cout << "Product with ID " << productID << " not found.\n";
}

void searchProduct() {
    int choice;
    if (!getValidInt(choice, "Search by:\n1. Product ID\n2. Product Name\nEnter your choice: "))
        return;

    if (choice == 1) {
        int productID;
        if (!getValidInt(productID, "Enter the Product ID to search for: "))
            return;
        Node* current = head;
        bool found = false;
        while (current != NULL) {
            if (current->product.productID == productID) {
                found = true;
                cout << "\n=== Product Found ===\n";
                cout << "Product ID: " << current->product.productID << "\n";
                cout << "Name: " << current->product.name << "\n";
                cout << "Price: $" << fixed << setprecision(2) << current->product.price << "\n";
                cout << "Quantity in stock: " << current->product.quantityInStock << "\n";
                for (int i = 0; i < current->product.numSuppliers; ++i) {
                    cout << "Supplier: " << current->product.suppliers[i].name << "\n";
                    cout << "Contact: " << current->product.suppliers[i].contactInfo << "\n";
                }
                cout << "===============================\n";
                break;
            }
            current = current->next;
        }
        if (!found)
            cout << "Product with ID " << productID << " not found.\n";
    } else if (choice == 2) {
        string productName;
        if (!getValidString(productName, "Enter the product name to search for: "))
            return;
        Node* current = head;
        bool found = false;
        while (current != NULL) {
            if (current->product.name == productName) {
                found = true;
                cout << "\n=== Product Found ===\n";
                cout << "Product ID: " << current->product.productID << "\n";
                cout << "Name: " << current->product.name << "\n";
                cout << "Price: $" << fixed << setprecision(2) << current->product.price << "\n";
                cout << "Quantity in stock: " << current->product.quantityInStock << "\n";
                for (int i = 0; i < current->product.numSuppliers; ++i) {
                    cout << "Supplier: " << current->product.suppliers[i].name << "\n";
                    cout << "Contact: " << current->product.suppliers[i].contactInfo << "\n";
                }
                cout << "===============================\n";
            }
            current = current->next;
        }
        if (!found)
            cout << "No products found with the name " << productName << ".\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

void trackSale() {
    int productID;
    if (!getValidInt(productID, "Enter product ID for sale: "))
        return;
    Node* current = head;
    bool found = false;
    while (current != NULL) {
        if (current->product.productID == productID) {
            found = true;
            int quantity;
            if (!getValidInt(quantity, "Enter quantity sold: "))
                return;
            if (quantity > current->product.quantityInStock) {
                cout << "Error: Not enough stock available. Current stock: "
                     << current->product.quantityInStock << "\n";
                return;
            }
            if (salesCount >= MAX_SALES) {
                cout << "Error: Sales record full. Please generate report first.\n";
                return;
            }
            Sale newSale;
            newSale.saleID = salesCount + 1;
            newSale.product = current->product;
            newSale.quantitySold = quantity;
            newSale.totalSaleAmount = quantity * current->product.price;
            salesList[salesCount++] = newSale;
            current->product.quantityInStock -= quantity;
            cout << "\n=== Sale Recorded Successfully! ===\n";
            cout << "Product: " << current->product.name << " (ID: " << current->product.productID << ")\n";
            cout << "Quantity sold: " << quantity << "\n";
            cout << "Total amount: $" << fixed << setprecision(2) << newSale.totalSaleAmount << "\n";
            cout << "Remaining stock: " << current->product.quantityInStock << "\n";
            cout << "==============================\n";
            break;
        }
        current = current->next;
    }
    if (!found)
        cout << "Product not found.\n";
}

void deleteProduct() {
    if (head == NULL) {
        cout << "No products in inventory.\n";
        return;
    }
    int productID;
    if (!getValidInt(productID, "Enter product ID to delete: "))
        return;

    Node* current = head;
    Node* prev = NULL;
    bool found = false;
    while (current != NULL) {
        if (current->product.productID == productID) {
            found = true;
            string confirm;
            cout << "Are you sure you want to delete " << current->product.name << "? (y/n): ";
            getline(cin, confirm);
            if (confirm == "y" || confirm == "Y") {
                if (prev == NULL)
                    head = current->next;
                else
                    prev->next = current->next;
                cout << "\n=== Product Deleted Successfully! ===\n";
                cout << "Product '" << current->product.name << "' (ID: " << current->product.productID << ") has been deleted.\n";
                cout << "===============================\n";
                delete[] current->product.suppliers;
                delete current;
            } else {
                cout << "Deletion cancelled.\n";
            }
            break;
        }
        prev = current;
        current = current->next;
    }
    if (!found)
        cout << "Product not found.\n";
}

void displayProducts() {
    if (head == NULL) {
        cout << "No products in inventory.\n";
        return;
    }
    cout << "\n=== Current Inventory ===\n";
    cout << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price"
         << setw(10) << "Stock" << setw(20) << "Supplier" << "\n";
    cout << string(65, '-') << "\n";
    Node* current = head;
    while (current != NULL) {
        cout << setw(5) << current->product.productID
             << setw(20) << current->product.name
             << setw(10) << fixed << setprecision(2) << current->product.price
             << setw(10) << current->product.quantityInStock
             << setw(20) << (current->product.numSuppliers > 0 ? current->product.suppliers[0].name : "") << "\n";
        current = current->next;
    }
    cout << string(65, '-') << "\n";
}

void generateSalesReport() {
    if (salesCount == 0) {
        cout << "No sales to report.\n";
        return;
    }
    cout << "\n=== Sales Report ===\n";
    cout << setw(5) << "ID" << setw(20) << "Product"
         << setw(10) << "Quantity" << setw(15) << "Total" << "\n";
    cout << string(50, '-') << "\n";
    double totalRevenue = 0;
    for (int i = 0; i < salesCount; i++) {
        cout << setw(5) << salesList[i].saleID
             << setw(20) << salesList[i].product.name
             << setw(10) << salesList[i].quantitySold
             << setw(15) << fixed << setprecision(2) << salesList[i].totalSaleAmount << "\n";
        totalRevenue += salesList[i].totalSaleAmount;
    }
    cout << string(50, '-') << "\n";
    cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << "\n";
}

void saveInventoryToFile() {
    ofstream outFile("inventory.txt");
    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }
    outFile << "ProductID,Name,Price,QuantityInStock,SupplierName,SupplierContact" << "\n";
    Node* current = head;
    int productCount = 0;
    while (current != NULL) {
        for (int i = 0; i < current->product.numSuppliers; ++i) {
            outFile << current->product.productID << ","
                    << current->product.name << ","
                    << current->product.price << ","
                    << current->product.quantityInStock << ","
                    << current->product.suppliers[i].name << ","
                    << current->product.suppliers[i].contactInfo << "\n";
        }
        productCount++;
        current = current->next;
    }
    cout << "\n=== Inventory Saved Successfully! ===\n";
    cout << "Inventory has been saved to 'inventory.txt'\n";
    cout << "Total products saved: " << productCount << "\n";
    cout << "===============================\n";
    outFile.close();
}

bool isInventoryLoaded = false;  // Global flag to track whether the inventory has been loaded

void loadInventoryFromFile() {
    if (isInventoryLoaded) {  // Check if the inventory is already loaded
        cout << "Inventory is already loaded. Skipping file load.\n";
        return;  // Prevent loading the file again if already loaded
    }

    ifstream inFile("inventory.txt");
    if (!inFile) {
        cout << "No previous inventory file found. Starting with empty inventory.\n";
        return;
    }

    string line;
    getline(inFile, line);  // Skip header line
    int productCount = 0;

    while (getline(inFile, line)) {
        string productID, name, price, quantity, supplierName, supplierContact;
        stringstream ss(line);
        getline(ss, productID, ',');
        getline(ss, name, ',');
        getline(ss, price, ',');
        getline(ss, quantity, ',');
        getline(ss, supplierName, ',');
        getline(ss, supplierContact);
        Node* newNode = new Node();
        stringstream convert;
        convert << productID;
        convert >> newNode->product.productID;
        convert.clear();
        newNode->product.name = name;
        convert << price;
        convert >> newNode->product.price;
        convert.clear();
        convert << quantity;
        convert >> newNode->product.quantityInStock;
        newNode->product.suppliers = new Supplier[1];
        newNode->product.numSuppliers = 1;
        newNode->product.suppliers[0].name = supplierName;
        newNode->product.suppliers[0].contactInfo = supplierContact;
        newNode->next = head;
        head = newNode;
        productCount++;
    }

    // Set the flag to true to indicate that the inventory has been loaded
    isInventoryLoaded = true;

    cout << "\n=== Inventory Loaded Successfully! ===\n";
    cout << "Inventory has been loaded from 'inventory.txt'\n";
    cout << "Total products loaded: " << productCount << "\n";
    cout << "===============================\n";
    inFile.close();
}

void welcome() {
    cout << "========================================================" << "\n";
    cout << "Welcome to the Cutiepie's 'Inventory Management System!" << "\n";
    cout << "========================================================" << "\n";
    cout << "Press Enter to continue...\n";
    cin.get();  // Waits for the user to press Enter
    system("cls");   // Clears the screen (on Windows)
}

void mainMenu() {
    int choice;
    do {
        cout << "==============================" << "\n";
        cout << "    Inventory Main Menu" << "\n";
        cout << "==============================" << "\n";
        cout << "1. Add Product" << "\n";
        cout << "2. Update Product" << "\n";
        cout << "3. Search Product" << "\n";
        cout << "4. Track Sale" << "\n";
        cout << "5. Delete Product" << "\n";
        cout << "6. Display All Products" << "\n";
        cout << "7. Generate Sales Report" << "\n";
        cout << "8. Save Inventory to File" << "\n";
        cout << "9. Load Inventory from File" << "\n";
        cout << "10. Exit" << "\n";
        if (!getValidInt(choice, "Enter your choice: "))
            continue;
        cout << "\n";
        switch(choice) {
            case 1: addProduct(); break;
            case 2: updateProduct(); break;
            case 3: searchProduct(); break;
            case 4: trackSale(); break;
            case 5: deleteProduct(); break;
            case 6: displayProducts(); break;
            case 7: generateSalesReport(); break;
            case 8: saveInventoryToFile(); break;
            case 9: loadInventoryFromFile(); break;
            case 10: cout << "Exiting the program..." << "\n"; break;
            default: cout << "Invalid choice! Please try again.\n"; break;
        }
        if (choice != 10 && !TEST_MODE) {
        cout << "\nPress Enter to return to the menu...\n";
        cin.get();  // Wait for Enter key to return to menu
        system("cls");   // Clears the screen (on Windows)
        }
    } while (choice != 10);
}

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "--test") {
        TEST_MODE = true;
        cout << "Running in test mode" << "\n";
    }

    loadInventoryFromFile();
    welcome();
    mainMenu();

    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete[] current->product.suppliers;
        delete current;
        current = next;
    }

    return 0;
}
