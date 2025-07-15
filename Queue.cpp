#include <iostream>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

// Function to load the queue from a file
void loadQueueFromFile(queue<string>& customerQueue, const string& filename) {
    ifstream infile(filename.c_str());
    if (infile.is_open()) {
        string customer;
        while (getline(infile, customer)) {
            customerQueue.push(customer);
        }
        infile.close();
    }
}

// Function to save the queue to a file
void saveQueueToFile(const queue<string>& customerQueue, const string& filename) {
    ofstream outfile(filename.c_str());
    if (outfile.is_open()) {
        queue<string> tempQueue = customerQueue; // Create a temporary copy to iterate
        while (!tempQueue.empty()) {
            outfile << tempQueue.front() << endl;
            tempQueue.pop();
        }
        outfile.close();
    }
}

// Function to add a customer to the queue
//TODO
void addCustomer(queue<string>& customerQueue) {
    string customer;
    cout << "Enter the name of the customer to add: ";
    getline(cin, customer);
    customerQueue.push(customer);
    cout << "Customer added: " << customer <<endl;
}

//TODO
// Function to serve (remove) a customer from the queue
void serveCustomer(queue<string>& customerQueue) {
    if (!customerQueue.empty()) {
        cout << "Serving customer: " << customerQueue.front() << endl;
        customerQueue.pop();
    } else {
        cout << "The queue is empty, no customer to serve." << endl;
    }
}

//TODO
// Function to view the next customer in the queue
void viewNextCustomer(const queue<string>& customerQueue) {
    if (!customerQueue.empty()) {
        cout << "Next customer to be served: " << customerQueue.front() << endl;
    } else {
        cout << "The queue is empty, no customer to view." << endl;
    }
}

//TODO
// Function to check if the queue is empty
void checkIfEmpty(const queue<string>& customerQueue) {
    if (customerQueue.empty()) {
        cout << "The queue is empty." << endl;
    } else {
        cout << "The queue is not empty." << endl;
    }
}

//TODO
// Function to display the menu options
void displayMenu() {
    cout << "\nCinema Ticket Booking System" << endl;
    cout << "1. Add a customer" << endl;
    cout << "2. Serve a customer" << endl;
    cout << "3. View the next customer" << endl;
    cout << "4. Check if the queue is empty" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    queue<string> customerQueue;
    const string filename = "customerQueue.txt";

    // Load queue from file
    loadQueueFromFile(customerQueue, filename);

    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // To ignore the newline character left by cin

        switch (choice) {
            case 1:
                addCustomer(customerQueue);
                break;
            case 2:
                serveCustomer(customerQueue);
                break;
            case 3:
                viewNextCustomer(customerQueue);
                break;
            case 4:
                checkIfEmpty(customerQueue);
                break;
            case 5:
                saveQueueToFile(customerQueue, filename);
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }
}

