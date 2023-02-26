#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Class for transactions
class Transaction {
public:
    string name;
    double amount;
    bool is_income;
    string category;

    Transaction(string n, double a, bool i, string c) : name(n), amount(a), is_income(i), category(c) {}
};

// Class for budget
class Budget {
public:
    double income;
    double expenses;
    double savings;

    Budget() : income(0), expenses(0), savings(0) {}

    void calculateSavings() {
        savings = income - expenses;
    }
};

// Function to add a transaction to the vector
void addTransaction(vector<Transaction>& transactions) {
    string name, category;
    double amount;
    bool is_income;

    cout << "Enter transaction name: ";
    getline(cin, name);

    cout << "Enter transaction amount: ";
    cin >> amount;

    cout << "Is this an income transaction? (y/n): ";
    char yn;
    cin >> yn;
    is_income = (yn == 'y' || yn == 'Y');

    cout << "Enter transaction category: ";
    cin.ignore();
    getline(cin, category);

    Transaction t(name, amount, is_income, category);
    transactions.push_back(t);
}

// Function to display a summary of the budget
void displaySummary(Budget budget) {
    cout << "INCOME: " << budget.income << endl;
    cout << "EXPENSES: " << budget.expenses << endl;
    cout << "SAVINGS: " << budget.savings << endl;
}

// Function to display all transactions
void displayTransactions(vector<Transaction> transactions) {
    cout << "TRANSACTION NAME\tAMOUNT\tINCOME/EXPENSE\tCATEGORY" << endl;
    for (Transaction t : transactions) {
        cout << t.name << "\t" << t.amount << "\t" << (t.is_income ? "INCOME" : "EXPENSE") << "\t\t" << t.category << endl;
    }
}

// Function to display transactions by category
void displayTransactionsByCategory(vector<Transaction> transactions) {
    cout << "CATEGORY\tAMOUNT" << endl;

    // Create a map to store the total amount for each category
    map<string, double> categories;

    for (Transaction t : transactions) {
        if (t.is_income) continue; // Ignore income transactions
        categories[t.category] += t.amount;
    }

    // Display the total amount for each category
    for (auto const& category : categories) {
        cout << category.first << "\t\t" << category.second << endl;
    }
}

// Main function
int main() {
    vector<Transaction> transactions;
    Budget budget;

    while (true) {
        // Display menu
        cout << "BUDGET PLANNER MENU" << endl;
        cout << "1. Add transaction" << endl;
        cout << "2. Display summary" << endl;
        cout << "3. Display all transactions" << endl;
        cout << "4. Display transactions by category" << endl;
        cout << "5. Exit" << endl;

        // Get user choice
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTransaction(transactions);
                if (transactions.back().is_income) {
                    budget.income += transactions.back().amount;
                } else {
                    budget.expenses += transactions.back().amount;
                }
                budget.calculateSavings();
                break;
            case 2:
                displaySummary(budget);
                break;
            case 3:
                displayTransactions(transactions);
                break;
            case 4:
                displayTransactionsByCategory(transactions);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    }

    return 0;
}
