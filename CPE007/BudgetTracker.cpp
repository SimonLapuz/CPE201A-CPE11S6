#include <iostream>
#include <string>
using namespace std;

// function to calculate total expenses for the month
double addtotal (double a, double b, double c, double d, double e) {
    return (a + b + c + d + e);
}

int main () {
    // declare struct to include information and expenses
    struct budget {
        string name;
        string month;
        double income;
        double limit;
        double expenses [5];
    };

    budget user;
    string categories [5] = {"food", "transportation", "bills", "recreation", "others"}; // declare string array for the different categories of expenses
    double totalexp; // declare variable that displays the total amount of expenses

    bool keepRunning = true;
    while (keepRunning) {
        // ====== INPUT SECTION ======
        cout << "==MONTHLY BUDGET TRACKER AND CALCULATOR==" << endl;

        // Use >> ws to consume any leftover whitespace so getline works reliably
        cout << "Enter your name: ";
        getline(cin >> ws, user.name);

        cout << "Enter the month for your budget: ";
        cin >> user.month;
        cout << "Enter your monthly income: ";
        cin >> user.income;
        cout << "Enter your monthly spending limit: ";
        cin >> user.limit;

        cout << "Enter your monthly expenses for the following categories: " << endl;
        for (int i = 0; i < 5; i++) { // for loop to input the expenses for each category
            cout << categories[i] << " : ";
            cin >> user.expenses[i];
        }

        // ====== OUTPUT / CALCULATION ======
        cout << "\n==BUDGET CALCULATION REPORT===" << endl;
        totalexp = addtotal(user.expenses[0], user.expenses[1], user.expenses[2], user.expenses[3], user.expenses[4]);
        cout << "Total Expenses for the month of " << user.month << ": " << totalexp << endl;

        double savings = user.income - totalexp;
        cout << "Your total savings: " << savings << endl;

        // Check spending against limit
        if (totalexp > user.limit) {
            cout << "You have exceeded your spending limit by " << totalexp - user.limit << endl;
        } 
        else if (totalexp == user.limit) {
            cout << "Perfect budgeting! You've exactly met your spending limit." << endl;
        } 
        else {
            cout << "Great job! You saved " << user.limit - totalexp << " under your spending limit." << endl;
        }

        // ====== OPTIONS MENU ======
        int choice;
        bool backToInput = false;
        do {
            cout << "\n=== OPTIONS MENU ===" << endl;
            cout << "1. Simulate reduced spendings" << endl;
            cout << "2. Reset information" << endl;
            cout << "3. Exit app" << endl;
            cout << "Enter your choice (1-3): ";
            cin >> choice;

            if (choice == 1) {
                double reducePercent;
                cout << "\nEnter percentage to reduce each spending (e.g., enter 10 for 10%): ";
                cin >> reducePercent;

                double newTotal = 0;
                for (int i = 0; i < 5; i++) {
                    newTotal += user.expenses[i] * (1 - (reducePercent / 100.0));
                }

                double newSavings = user.income - newTotal;
                cout << "\nIf you reduce your expenses by " << reducePercent << "%, your new total expenses will be: " << newTotal << endl;
                cout << "Your new savings will be: " << newSavings << endl;
            }
            else if (choice == 2) {
                cout << "\nResetting information...\n" << endl;
                backToInput = true;
            }
            else if (choice == 3) {
                cout << "\nThank you for using the Budget Tracker. Keep it up and be financially smart, " << user.name << "!" << endl;
                keepRunning = false;
                break;
            }
            else {
                cout << "\nInvalid choice. Please try again." << endl;
            }
        } 
        while (!backToInput && keepRunning);

        // loop will either restart for new input (reset), or exit if keepRunning==false
        if (!keepRunning) break;
        cout << "-------------------------------------\n";
    } // end while keepRunning

    return 0;
}
