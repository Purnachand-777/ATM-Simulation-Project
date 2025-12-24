#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Enum for menu options as described
typedef enum {
    CHECKBALANCE = 1,
    DEPOSIT,
    WITHDRAW,
    EXIT
} MenuOption;

// Account structure (simulating class)
typedef struct {
    char accountNumber[20];
    char name[50];
    double balance;
} Account;

// Constructor-like function for account initialization
Account createAccount(const char* accNum, const char* name, double initialBalance) {
    Account acc;
    strcpy(acc.accountNumber, accNum);
    strcpy(acc.name, name);
    acc.balance = initialBalance;
    
    // Log account creation
    FILE* log = fopen("transactions.txt", "a");
    if (log) {
        fprintf(log, "Account Created: %s - %s - Initial: %.2f\n", accNum, name, initialBalance);
        fclose(log);
    }
    return acc;
}

// Function to display menu
MenuOption showMenu() {
    int choice;
    printf("\n=== ATM Menu ===\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return (MenuOption)choice;
}

// Transaction logging
void logTransaction(const char* accNum, const char* type, double amount) {
    FILE* log = fopen("transactions.txt", "a");
    if (log) {
        fprintf(log, "%s - %s: %.2f\n", accNum, type, amount);
        fclose(log);
    }
}

// Main ATM operations
void processTransaction(Account* acc, MenuOption option) {
    double amount;
    switch (option) {
        case CHECKBALANCE:
            printf("Balance: %.2f\n", acc->balance);
            logTransaction(acc->accountNumber, "CHECK_BALANCE", acc->balance);
            break;
        case DEPOSIT:
            printf("Enter deposit amount: ");
            scanf("%lf", &amount);
            acc->balance += amount;
            printf("New balance: %.2f\n", acc->balance);
            logTransaction(acc->accountNumber, "DEPOSIT", amount);
            break;
        case WITHDRAW:
            printf("Enter withdrawal amount: ");
            scanf("%lf", &amount);
            if (amount <= acc->balance) {
                acc->balance -= amount;
                printf("New balance: %.2f\n", acc->balance);
                logTransaction(acc->accountNumber, "WITHDRAW", amount);
            } else {
                printf("Insufficient funds!\n");
            }
            break;
        default:
            printf("Invalid option!\n");
    }
}

int main() {
    Account userAcc = createAccount("123456789", "Purnachand Y", 1000.0);  // Sample from PPT
    printf("Welcome to ATM Simulation!\n");
    printf("Account: %s - %s\n", userAcc.accountNumber, userAcc.name);
    
    MenuOption choice;
    while ((choice = showMenu()) != EXIT) {
        processTransaction(&userAcc, choice);
    }
    printf("Thank you for using ATM!\n");
    return 0;
}
