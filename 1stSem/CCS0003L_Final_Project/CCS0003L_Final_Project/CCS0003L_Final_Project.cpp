#include <iostream>
using namespace std;

int main() {
    int choice, points;  // This initializes variables to store the user's chosen quiz topic and their score
    char answer, retry;  // These variables are used to capture the user's answers and whether they want to retry the quiz

    do {
        points = 0;

        // This presents the main menu, allowing the user to select a quiz topic or exit the application
        cout << "\n==================================\n";
        cout << "      KNOWLEDGE QUIZ SYSTEM      \n";
        cout << "==================================\n";
        cout << "Choose a topic:\n";
        cout << "[1] History of GOMBURZA\n";
        cout << "[2] Science and Technology Studies\n";
        cout << "[3] C++ Programming\n";
        cout << "[4] Binary Operations\n";
        cout << "[0] Exit\n";
        cout << "===========================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // This `switch` statement evaluates the user's choice and executes the corresponding quiz
        switch (choice) {
        case 1: // Quiz about History of GOMBURZA with 5 questions each
            cout << "\n===========================";
            cout << "\n--- History of GOMBURZA ---\n";
            cout << "===========================\n";
            cout << "1. Where were the GOMBURZA priests executed?\n";
            cout << "   A. Bagumbayan\n   B. Fort Santiago\n   C. Luneta\n   D. Intramuros\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++; // This checks if the answer is correct and increments the score.

            cout << "\n2. What did GOMBURZA fight for?\n";
            cout << "   A. Secularization of priests\n   B. Tax exemptions\n   C. Independence\n   D. Land reforms\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++;

            cout << "\n3. What event triggered their execution?\n";
            cout << "   A. Cavite Mutiny\n   B. Revolution\n   C. Tax Rebellion\n   D. Political Protest\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++;

            cout << "\n4. Who among the following was NOT part of GOMBURZA?\n";
            cout << "   A. Mariano Gomez\n   B. Jose Burgos\n   C. Jacinto Zamora\n   D. Andres Bonifacio\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'D' || answer == 'd') points++;

            cout << "\n5. In what year were the GOMBURZA priests executed?\n";
            cout << "   A. 1865\n   B. 1872\n   C. 1880\n   D. 1896\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'B' || answer == 'b') points++;

            // Displays the user's final score for this topic.
            cout << "\n=======================";
            cout << "\nYour total points: " << points << "/5\n";
            break;

        case 2: // Quiz about Science and Technology with 5 questions each
            cout << "\n=====================================";
            cout << "\n--- Science and Technology ---\n";
            cout << "=====================================";
            cout << "\n1. What is the smallest unit of life?\n";
            cout << "   A. Atom\n   B. Cell\n   C. Molecule\n   D. Organ\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'B' || answer == 'b') points++;

            cout << "\n2. Who proposed the Theory of Evolution?\n";
            cout << "   A. Isaac Newton\n   B. Charles Darwin\n   C. Albert Einstein\n   D. Galileo Galilei\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'B' || answer == 'b') points++;

            cout << "\n3. What does DNA stand for?\n";
            cout << "   A. Deoxyribonucleic Acid\n   B. Dynamic Nuclear Atom\n   C. Double Neuron Atom\n   D. None of the above\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++;

            cout << "\n4. What planet is known as the 'Red Planet'?\n";
            cout << "   A. Venus\n   B. Mars\n   C. Jupiter\n   D. Saturn\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'B' || answer == 'b') points++;

            cout << "\n5. What is the speed of light?\n";
            cout << "   A. 300,000 km/s\n   B. 150,000 km/s\n   C. 1,000 km/s\n   D. 30,000 km/s\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++;

            // Displays the user's final score for this topic.
            cout << "\n=======================";
            cout << "\nYour total points: " << points << "/5\n";
            break;

        case 3: // Quiz about C++ Programming with 5 questions each
            cout << "\n===========================";
            cout << "\n--- C++ Programming ---\n";
            cout << "===========================";
            cout << "\n1. What symbol is used to insert comments in C++?\n";
            cout << "   A. //\n   B. ##\n   C. /* */\n   D. Both A and C\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'D' || answer == 'd') points++;

            cout << "\n2. What does 'int' represent in C++?\n";
            cout << "   A. Integer\n   B. Input\n   C. Instruction\n   D. Interval\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++;

            cout << "\n3. Which header file is required for input/output operations?\n";
            cout << "   A. <iostream>\n   B. <string>\n   C. <math>\n   D. <iomanip>\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++;

            cout << "\n4. What is the correct syntax to print 'Hello, World!'?\n";
            cout << "   A. print(\"Hello, World!\")\n   B. cout << \"Hello, World!\";\n";
            cout << "   C. printf(\"Hello, World!\")\n   D. echo \"Hello, World!\"\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'B' || answer == 'b') points++;

            cout << "\n5. What does 'endl' do in C++?\n";
            cout << "   A. Ends the program\n   B. Creates a new line\n";
            cout << "   C. Clears the screen\n   D. None of the above\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'B' || answer == 'b') points++;

            // Displays the user's final score for this topic.
            cout << "\n=======================";
            cout << "\nYour total points: " << points << "/5\n";
            break;

        case 4: // Quiz about Binary Operations with 5 questions each
            cout << "\n===========================";
            cout << "\n--- Binary Operations ---\n";
            cout << "===========================";
            cout << "\n1. What is the binary representation of 10?\n";
            cout << "   A. 1010\n   B. 1100\n   C. 1001\n   D. 1110\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++;

            cout << "\n2. What is 1011 in decimal?\n";
            cout << "   A. 10\n   B. 11\n   C. 12\n   D. 13\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'B' || answer == 'b') points++;

            cout << "\n3. Add 101 and 111 in binary. What is the result?\n";
            cout << "   A. 1100\n   B. 1010\n   C. 1000\n   D. 1110\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++;

            cout << "\n4. Convert the decimal number 20 to binary.\n";
            cout << "   A. 10100\n   B. 11000\n   C. 11100\n   D. 10000\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'A' || answer == 'a') points++;

            cout << "\n5. What is the binary equivalent of hexadecimal 'F'?\n";
            cout << "   A. 1110\n   B. 1111\n   C. 1010\n   D. 1000\n";
            cout << "Your Answer: ";
            cin >> answer;
            if (answer == 'B' || answer == 'b') points++;

            // Displays the user's final score for this topic
            cout << "\n=======================";
            cout << "\nYour total points: " << points << "/5\n";
            break;

        case 0:
            // Exits the program when the user selects "0"
            cout << "\n~Thank you for using the quiz program!~\n";
            return 0;

        default:
            // This is triggered if the user enters an invalid choice
            cout << "\nInvalid choice! Please try again.\n";
        }
        // Ask the user if they wanna try another quiz
        cout << "\nDo you want to try another quiz? (Y/N): ";
        cin >> retry;

    } while (retry == 'Y' || retry == 'y');

    // Final message before the program ends
    cout << "\n===========================================\n";
    cout << "      Thank you for using the Quiz App!     \n";
    cout << "===========================================\n";
    return 0;
}
