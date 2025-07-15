#include <iostream>
#include <cstdlib>  // For system("CLEAR") to clear the screen (Windows)
#include <fstream>  // For file handling
#include <sstream>  // For stringstream to parse txt
#include <iomanip>  // For setw() and right alignment
#include <string>   // For string manipulations
#include <cctype>  // For isalpha, isdigit, etc.
#include <limits>  // For numeric_limits

using namespace std;  // Allows us to omit 'std::'

#define MAX_PRODUCTS 100  // Limit the array size for temporary storage

// Declare the Supplier structure before the Product structure
struct Supplier {
    string supplierName;
    string supplierContact;
};

struct Product {
    int productID; // Product ID
    string productName;
    double productPrice;
    int productQuantity;
    Supplier supplier;
};

// Node structure for linked list (Product)
struct ProductNode {
    Product product;
    ProductNode* next; // Pointer to the next node in the list
};

// Temporary array to hold product data
Product tempProductArray[MAX_PRODUCTS];
int productCount = 0;  // Counter to track the number of products in the array

struct Sales {
    int salesID;
    Product product;
    int salesSold;
    double salesTotal;
};

// Node structure for linked list (Sales)
struct SalesNode {
    Sales sales;
    SalesNode* next; // Pointer to the next node in the list
};

// Pointers to the head of the linked lists
ProductNode* productHead = NULL;  // Head pointer for products linked list
SalesNode* salesHead = NULL;      // Head pointer for sales linked list

void border() {
    cout << string(95, '-') << endl;
}

// Function to get a valid integer input
int getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < 0) {
            cout << "Invalid input. Please enter a non-negative integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');  // Clear newline character
            return value;
        }
    }
}

// Function to get a valid double input
double getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < 0) {
            cout << "Invalid input. Please enter a non-negative number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');  // Clear newline character
            return value;
        }
    }
}

bool isValidString(const string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        char c = str[i];
        if (!isalnum(c) && c != ' ' && c != '-' && c != '_') {
            return false;
        }
    }
    return true;
}

double getValidPrice() {
    double price;
    while (true) {
        cout << "Enter product price: ";
        cin >> price;

        if (cin.fail() || price < 0) {
            cout << "Invalid input. Please enter a non-negative number.\n";
            cin.clear();  // Clear the error state
            cin.ignore(1000, '\n');  // Discard invalid input
        } else {
            cin.ignore(1000, '\n');  // Clear newline character
            return price;
        }
    }
}

int getValidQuantity() {
    int quantity;
    while (true) {
        cout << "Enter product quantity: ";
        cin >> quantity;

        if (cin.fail() || quantity < 0) {
            cout << "Invalid input. Please enter a non-negative integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');  // Clear newline
            return quantity;
        }
    }
}

bool isProductIDUsed(int productID) {
    ProductNode* temp = productHead;
    while (temp != NULL) {
        if (temp->product.productID == productID) {
            return true;  // Product ID already exists
        }
        temp = temp->next;
    }
    return false;  // Product ID is unique
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Product array is full! Cannot add more products.\n";
        return;
    }

    Product newProduct;

    // Validate unique Product ID
    while (true) {
        cout << "Enter product ID: ";
        while (!(cin >> newProduct.productID)) {
            cout << "Invalid input. Enter a valid product ID: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (isProductIDUsed(newProduct.productID)) {
            cout << "Product ID already exists! Enter a different Product ID.\n";
        } else {
            break;  // Unique ID, proceed
        }
    }
    cin.ignore(1000, '\n'); // Clear newline

    cout << "Enter product name: ";
    getline(cin, newProduct.productName);
    while (!isValidString(newProduct.productName)) {
        cout << "Invalid name. Enter again: ";
        getline(cin, newProduct.productName);
    }

    newProduct.productPrice = getValidPrice();
    newProduct.productQuantity = getValidQuantity();

    cout << "Enter supplier name: ";
    getline(cin, newProduct.supplier.supplierName);
    while (!isValidString(newProduct.supplier.supplierName)) {
        cout << "Invalid name. Enter again: ";
        getline(cin, newProduct.supplier.supplierName);
    }

    cout << "Enter supplier contact: ";
    getline(cin, newProduct.supplier.supplierContact);
    while (!isValidString(newProduct.supplier.supplierContact)) {
        cout << "Invalid contact. Enter again: ";
        getline(cin, newProduct.supplier.supplierContact);
    }

    // Store the product in the array
    tempProductArray[productCount] = newProduct;

    // Move the product to the linked list
    ProductNode* newProductNode = new ProductNode;
    newProductNode->product = newProduct;
    newProductNode->next = productHead;
    productHead = newProductNode;

    productCount++;

    cout << "Product added successfully!\n";
}
// Update product information in the linked list
void updateProduct() {
    int productID = getValidInt("Enter the Product ID to update: ");
    cin.ignore();  // ?? FIX: Clear newline before using getline()

    ProductNode* temp = productHead;
    bool found = false;

    while (temp != NULL) {
        if (temp->product.productID == productID) {
            found = true;
            cout << "Product found: " << temp->product.productName << endl;

            // Update Product Name
            cout << "Enter new product name (or press Enter to keep it the same): ";
            string newName;
            getline(cin, newName);
            while (!newName.empty() && !isValidString(newName)) {
                cout << "Invalid name. Enter again: ";
                getline(cin, newName);
            }
            if (!newName.empty()) {
                temp->product.productName = newName;
            }

            // Update Product Price
            double newPrice = getValidDouble("Enter new product price (or 0 to keep it the same): ");
            if (newPrice > 0) {
                temp->product.productPrice = newPrice;
            }

            // Update Product Quantity
            int newQuantity;
            while (true) {
                cout << "Enter new product quantity (or -1 to keep it the same): ";
                cin >> newQuantity;

                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid non-negative integer or -1.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else if (newQuantity >= 0) {
                    temp->product.productQuantity = newQuantity;
                    break;
                } else if (newQuantity == -1) {
                    break;  // Keep the existing quantity
                } else {
                    cout << "Invalid input. Please enter a valid quantity.\n";
                }
            }

            cout << "Product updated successfully!\n";
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Product with ID " << productID << " not found.\n";
    }

    cout << "Press Enter to continue...";
    cin.ignore(); 
    cin.get();
}

// Delete product from the linked list
void deleteProduct() {
    int productID = getValidInt("Enter the Product ID to delete: ");

    ProductNode* temp = productHead;
    ProductNode* prev = NULL;
    bool found = false;

    while (temp != NULL) {
        if (temp->product.productID == productID) {
            found = true;
            if (prev == NULL) {
                productHead = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Product with ID " << productID << " deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        cout << "Product with ID " << productID << " not found.\n";
    }
}

// Function to search for a product by ID or name
void searchProduct() {
    int choice;
    while (true) {
        cout << "Search Product by:\n";
        cout << "1. Product ID\n";
        cout << "2. Product Name\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1 || choice == 2) break;
        cout << "Invalid choice! Please enter 1 or 2.\n";
    }

    if (choice == 1) {
        // Search by Product ID
        int productID = getValidInt("Enter the Product ID to search: ");

        ProductNode* temp = productHead;
        bool found = false;

        while (temp != NULL) {
            if (temp->product.productID == productID) {
                found = true;
                cout << "Product found: \n";
                cout << "Product ID: " << temp->product.productID << endl;
                cout << "Product Name: " << temp->product.productName << endl;
                cout << "Product Price: $" << temp->product.productPrice << endl;
                cout << "Product Quantity: " << temp->product.productQuantity << endl;
                cout << "Supplier Name: " << temp->product.supplier.supplierName << endl;
                cout << "Supplier Contact: " << temp->product.supplier.supplierContact << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Product with ID " << productID << " not found.\n";
    } else {
        // Search by Product Name
        cout << "Enter the Product Name to search: ";
        string productName;
        getline(cin, productName);

        while (!isValidString(productName)) {
            cout << "Invalid product name. Enter again: ";
            getline(cin, productName);
        }

        ProductNode* temp = productHead;
        bool found = false;

        while (temp != NULL) {
            if (temp->product.productName == productName) {
                found = true;
                cout << "Product found: \n";
                cout << "Product ID: " << temp->product.productID << endl;
                cout << "Product Name: " << temp->product.productName << endl;
                cout << "Product Price: $" << temp->product.productPrice << endl;
                cout << "Product Quantity: " << temp->product.productQuantity << endl;
                cout << "Supplier Name: " << temp->product.supplier.supplierName << endl;
                cout << "Supplier Contact: " << temp->product.supplier.supplierContact << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Product with Name \"" << productName << "\" not found.\n";
    }
}
// Display all products in the linked list
void displayProducts() {
    if (productHead == NULL) {
        cout << "No products to display.\n";
        return;
    }

    // Print table headers
    cout << left
         << setw(12) << "Product ID" 
         << setw(20) << "Product Name" 
         << setw(20) << "Product Price"  // Increased width for Price column
         << setw(20) << "Product Quantity" // Adjusted width for Quantity column
         << setw(20) << "Supplier Name" 
         << setw(20) << "Supplier Contact" 
         << endl;

    border();
    // Print the product details in a formatted table
    ProductNode* temp = productHead;
    while (temp != NULL) {
        cout << setw(12) << temp->product.productID
             << setw(20) << temp->product.productName
             << "$" << setw(20) << fixed << setprecision(2) << temp->product.productPrice
             << setw(20) << temp->product.productQuantity
             << setw(20) << temp->product.supplier.supplierName
             << setw(20) << temp->product.supplier.supplierContact
             << endl;
        temp = temp->next;
    }
    border();
}

// Track sales and update the inventory in the linked list
void trackSale() {
    int productID, salesSold;
    cout << "Enter product ID for the sale: ";
    cin >> productID;
    cin.ignore();  // Clear the newline left by the previous cin

    ProductNode* temp = productHead;
    bool found = false;

    while (temp != NULL) {
        if (temp->product.productID == productID) {
            found = true;

            cout << "Enter Sales Sold: ";
            cin >> salesSold;
            cin.ignore();  // Clear the newline left by the previous cin

            // Check if enough quantity is available in stock
            if (temp->product.productQuantity >= salesSold) {
                double salesTotal = temp->product.productPrice * salesSold;
                temp->product.productQuantity -= salesSold;  // Update inventory

                // Create a new sales node
                SalesNode* newSalesNode = new SalesNode;
                newSalesNode->sales.salesID = 1;
                SalesNode* salesTemp = salesHead;
                while (salesTemp != NULL) {
                    newSalesNode->sales.salesID++;
                    salesTemp = salesTemp->next;
                }
                newSalesNode->sales.product = temp->product;
                newSalesNode->sales.salesSold = salesSold;
                newSalesNode->sales.salesTotal = salesTotal;
                newSalesNode->next = salesHead; // Add to the beginning of the list
                salesHead = newSalesNode;

                cout << "Sales tracked successfully!\n";
                cout << "Sales Total amount: $" << salesTotal << "\n";
            } else {
                cout << "Not enough product quantity in stock.\n";
            }
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Product with ID " << productID << " not found.\n";
    }
}

// Display all sales in the linked list
void generateSalesReport() {
    if (salesHead == NULL) {
        cout << "No sales to display.\n";
        return;
    }

    // Print sales headers
    cout << left
         << setw(12) << "Sales ID"
         << setw(12) << "Product ID" 
         << setw(20) << "Product Name"
         << setw(15) << "Sales Sold" 
         << setw(20) << "Sales Total" << endl;

    border();
    // Print the sales details in a formatted table
    SalesNode* temp = salesHead;
    while (temp != NULL) {
        cout << setw(12) << temp->sales.salesID
             << setw(12) << temp->sales.product.productID
             << setw(20) << temp->sales.product.productName
             << setw(20) << temp->sales.salesSold
             << "$" << setw(20) << fixed << setprecision(2) << temp->sales.salesTotal
             << endl;
        temp = temp->next;
    }
    border();
}

// Function to save inventory to a txt file and reset the inventory
void saveInventoryToFile() {
    ofstream outFile("inventory.txt");  // Open the file for writing

    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }

    ProductNode* temp = productHead;

    // Write the header
    outFile << "ProductID,ProductName,ProductPrice,ProductQuantity,SupplierName,SupplierContact\n";

    // Loop through linked list and write product data to file
    while (temp != NULL) {
        outFile << temp->product.productID << ","
                << temp->product.productName << ","
                << temp->product.productPrice << ","
                << temp->product.productQuantity << ","
                << temp->product.supplier.supplierName << ","
                << temp->product.supplier.supplierContact << "\n";
        temp = temp->next;  // Move to next node in the list
    }

    cout << "Inventory saved to file successfully.\n";
    
    outFile.close();  // Close the file after writing
    cout << "Inventory successfully saved to file: inventory.txt" << endl;
}

bool isInventoryLoaded = false;  // Global flag to track if inventory is already loaded

// Function to load inventory from a txt file
void loadInventoryFromFile() {
    if (isInventoryLoaded) {  
        cout << "Inventory is already loaded. Skipping file load.\n";
        return;  // Prevent duplicate loading
    }

    ifstream inFile("inventory.txt");
    if (!inFile) {
        cout << "No previous inventory file found. Starting with empty inventory.\n";
        return;
    }

    string line;
    getline(inFile, line);  // Skip the header line

    // Read each line of the txt file
    while (getline(inFile, line)) {
        stringstream ss(line);
        string productID, productName, productPrice, productQuantity, supplierName, supplierContact;

        // Split the line by commas
        getline(ss, productID, ',');
        getline(ss, productName, ',');
        getline(ss, productPrice, ',');
        getline(ss, productQuantity, ',');
        getline(ss, supplierName, ',');
        getline(ss, supplierContact, ',');

        // Declare and initialize newProduct object here
        Product newProduct;
        newProduct.productName = productName;
        newProduct.supplier.supplierName = supplierName;
        newProduct.supplier.supplierContact = supplierContact;

        // Convert productID and productQuantity to integers using stringstream
        stringstream(productID) >> newProduct.productID;
        stringstream(productQuantity) >> newProduct.productQuantity;
        // Convert productPrice to double using stringstream
        stringstream(productPrice) >> newProduct.productPrice;

        // Create a new ProductNode
        ProductNode* newNode = new ProductNode;
        newNode->product = newProduct;
        newNode->next = NULL;

        // Add newNode to the linked list
        if (productHead == NULL) {
            productHead = newNode;  // First node in the list
        } else {
            ProductNode* temp = productHead;
            while (temp->next != NULL) {
                temp = temp->next;  // Traverse to the end of the list
            }
            temp->next = newNode;  // Add newNode at the end of the list
        }
    }

    inFile.close();  // Close the file after reading
    isInventoryLoaded = true;  // Mark inventory as loaded

    cout << "Inventory successfully loaded from file: inventory.txt" << endl;
}

// Function to save inventory to a txt file and reset the inventory
void saveSalesToFile() {
    ofstream outFile("sales.txt");  // Open the file for writing

    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }

    // Write the header
    outFile << "SalesID,ProductID,ProductName,SalesSold,SalesTotal\n";

    SalesNode* temp = salesHead; 

    // Traverse the linked list and write each sale to the file
    while (temp != NULL) {
        // Write sale data to file in txt format
        outFile << temp->sales.salesID << ","
                << temp->sales.product.productID << ","
                << temp->sales.product.productName << ","
                << temp->sales.salesSold << ","
                << temp->sales.salesTotal << "\n";

        temp = temp->next;  // Move to the next sale
    }

    outFile.close();
    cout << "Sales successfully saved from file: sales.txt" << endl;
}


// Function to load sales from a txt file
bool isSalesLoaded = false;  // Global flag to track if sales data is already loaded

void loadSalesFromFile() {
    if (isSalesLoaded) {  
        cout << "Sales data is already loaded. Skipping file load.\n";
        return;  // Prevent duplicate loading
    }

    ifstream inFile("sales.txt");  // Open the file for reading

    if (!inFile) {
        cout << "No new sales loaded!\n";
        return;
    }

    string line;
    getline(inFile, line);  // Skip the header line

    // Read each line of the txt file
    while (getline(inFile, line)) {
        stringstream ss(line);
        string salesID, productID, productName, salesSold, salesTotal;

        // Split the line by commas
        getline(ss, salesID, ',');
        getline(ss, productID, ',');
        getline(ss, productName, ',');
        getline(ss, salesSold, ',');
        getline(ss, salesTotal, ',');

        Sales newSales;
        newSales.product.productName = productName;

        stringstream(salesID) >> newSales.salesID;
        stringstream(productID) >> newSales.product.productID;
        stringstream(salesSold) >> newSales.salesSold;
        stringstream(salesTotal) >> newSales.salesTotal;

        SalesNode* newNode = new SalesNode;
        newNode->sales = newSales;
        newNode->next = NULL;

        // Add newNode to the linked list
        if (salesHead == NULL) {
            salesHead = newNode;  // First node in the list
        } else {
            SalesNode* temp = salesHead;
            while (temp->next != NULL) {
                temp = temp->next;  // Traverse to the end of the list
            }
            temp->next = newNode;  // Add newNode at the end of the list
        }
    }

    inFile.close();
    isSalesLoaded = true;  // Mark sales data as loaded

    cout << "Sales data successfully loaded from file: sales.txt" << endl;
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
        cout << "==============================\n";
        cout << "       Inventory System       \n";
        cout << "==============================\n";
        cout << "1. Add a new product\n";
        cout << "2. Update product information\n";
        cout << "3. Delete a product\n";
        cout << "4. Search for a product\n";
        cout << "5. Display all products\n";
        cout << "6. Track sales and update inventory\n";
        cout << "7. Generate sales report\n";
        cout << "8. Save inventory to a file\n";
        cout << "9. Load inventory from a file\n";
        cout << "0. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline left by the previous cin
        
        switch (choice) {
            case 1:
                addProduct();
                saveInventoryToFile();  // Save inventory after addition
                break;
            case 2:
                updateProduct();
                saveInventoryToFile();  // Save inventory after addition
                break;
            case 3:
                deleteProduct();
                saveInventoryToFile();  // Save inventory after addition
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                displayProducts();
                break;
            case 6:
               	trackSale();
                break;
            case 7:
                generateSalesReport();
                break;
            case 8:
                saveInventoryToFile();
                saveSalesToFile();
                break;
            case 9:
                loadInventoryFromFile();
                loadSalesFromFile();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 9.\n";
        }
        
        cout << "\nPress Enter to return to the menu...\n";
        cin.get();  // Wait for Enter key to return to menu
        system("cls");   // Clears the screen (on Windows)
        
    } while (choice != 0);
}

int main() {
    welcome();
    loadInventoryFromFile(); // Load inventory data on startup
    mainMenu();
    return 0;
}

