#include <iostream> 

#include <stack> 

#include <string> 

 

using namespace std; 



void addBook(stack<string>& bookStack) { 

    string book; 

    cout << "Enter the name of the book to add: "; 

    getline(cin, book); 

    bookStack.push(book); 

    cout << "Book added: " << book << endl<<endl; 

} 

 

void removeBook(stack<string>& bookStack) { 

//TODO 

	if(bookStack.empty()){
		cout<<"The stack is empty, no book to remove."<<endl;
	}else{
		cout <<"Removing book: "<<bookStack.top()<<
		endl<<endl;
		bookStack.pop();
		}
}

void viewTopBook(const stack<string>& bookStack) { 

//TODO 

if (bookStack.empty()){
	cout<<"The stack is empty. No book to view."<<endl<<endl;
}else{
	cout <<"Top book: " <<bookStack.top()<<endl<<endl;
}

} 

 

void checkIfEmpty(const stack<string>& bookStack) { 

//TODO 

if (bookStack.empty()){
	cout<<"The stack is empty."<<endl<<endl;
}else{
	cout<<"The stack is not empty."<<endl<<endl;
}

} 

 

void displayMenu() { 

//TODO 
cout<<"Library Book Stack Manager"<<endl;
cout<<"1. Add a book"<<endl;
cout<<"2. Remove a book"<<endl;
cout<<"3. View the top book"<<endl;
cout<<"4. Check if the stack is empty"<<endl;
cout<<"5. Exit"<<endl;
cout<<"Enter your choice: ";
 

} 

 

int main() { 

    stack<string> bookStack; 

    int choice; 

 

    while (true) { 

        displayMenu(); 

        cin >> choice; 

        cin.ignore();  

 

        switch (choice) { 

            case 1: 

                addBook(bookStack); 

                break; 

            case 2: 

                removeBook(bookStack); 

                break; 

            case 3: 

                viewTopBook(bookStack); 

                break; 

            case 4: 

                checkIfEmpty(bookStack); 

                break; 

            case 5: 

                cout << "Exiting the program. Goodbye!" << endl; 

                return 0; 

            default: 

                cout << "Invalid choice, please try again." << endl; 

                break; 

        } 

    } 

} 
