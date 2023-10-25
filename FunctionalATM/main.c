#include <stdio.h>
#include <stdbool.h>

bool start();

int options();

int withdrawal();

bool withdrawContinue();

int noteAmount();

bool depositConfirm();

int depositValueF();

int main() {
    int balance = 1500;
    int note200 = 10;
    int note100 = 10;
    int note50 = 10;
    int note20 = 10;
    int note10 = 10;

    if (start()) {
        int action = options();
        int withdrawAmount;

        while (action != 4) {
            while (action == 1) {
                withdrawAmount = withdrawal();
                //Checks if withdrawal amount is valid.
                if (withdrawAmount % 10 == 0 && withdrawAmount <= balance && withdrawAmount > 0) {
                    int remainingAmount = withdrawAmount;
                    int deductedAmount = 0; // deduct will keep increasing
                    // while remaining will decrease at an equal rate

                    //Declares variables to output number of notes before + after transaction
                    int note200old = note200;
                    int note100old = note100;
                    int note50old = note50;
                    int note20old = note20;
                    int note10old = note10;

                    while (remainingAmount > 0) {
                        if (remainingAmount >= 200 && note200 > 0) {
                            remainingAmount -= 200;
                            deductedAmount += 200;
                            note200--;
                        } else if (remainingAmount >= 100 && note100 > 0) {
                            remainingAmount -= 100;
                            deductedAmount += 100;
                            note100--;
                        } else if (remainingAmount >= 50 && note50 > 0) {
                            remainingAmount -= 50;
                            deductedAmount += 50;
                            note50--;
                        } else if (remainingAmount >= 20 && note20 > 0) {
                            remainingAmount -= 20;
                            deductedAmount += 20;
                            note20--;
                        } else if (remainingAmount >= 10 && note10 > 0) {
                            remainingAmount -= 10;
                            deductedAmount += 10;
                            note10--;
                        } else {
                            // Not enough available banknotes to fulfill the remaining amount
                            break;
                        }
                    }

                    if (remainingAmount == 0) { //Money has been successfully deployed
                        balance -= deductedAmount; // new balance
                        printf("Your current balance is %i\n", balance);
                        printf("---------------------------\n");
                        printf("Number of 200 notes before: %i\n", note200old);
                        printf("Number of 100 notes before: %i\n", note100old);
                        printf("Number of 50 notes before: %i\n", note50old);
                        printf("Number of 20 notes before: %i\n", note20old);
                        printf("Number of 10 notes before: %i\n", note10old);
                        printf("---------------------------\n");
                        printf("Number of 200 notes now: %i\n", note200);
                        printf("Number of 100 notes now: %i\n", note100);
                        printf("Number of 50 notes now: %i\n", note50);
                        printf("Number of 20 notes now: %i\n", note20);
                        printf("Number of 10 notes now: %i\n", note10);
                        action = options(); // Withdrawal complete, return to main menu.

                    } else { // In case remainingAmount is still not subtracted to 0 by the available notes.
                        printf("Sorry, we don't have enough bank notes for this amount.\n");
                        if (!withdrawContinue()) {
                            action = options();
                            break; // Exit the withdrawal loop
                        } else {
                            withdrawAmount = remainingAmount + deductedAmount;
                        }
                    }
                } else {
                    printf("The input amount has to be divisible by 10, be a positive integer, and be less than the current balance.\n");
                    if (!withdrawContinue()) { // calling withdrawContinue() function again to see
                        // if user wants to re-enter withdrawal amount

                        action = options();
                        break; // Prompt user to the main menu and exit the withdrawal loop
                    }
                }
            }
            while (action == 2) {
                int depositValue = depositValueF();
                int notes = noteAmount();
                bool depositDecision = depositConfirm();

                switch (depositValue) {
                    case 10:
                        if (depositDecision) {
                            balance = balance + notes * 10;
                            note10 += notes;
                            printf("Your balance is %i\n", balance);
                            printf("Number of 10 notes now: %i\n", note10);
                            printf("---------------------------\n");
                        }
                        break;
                    case 20:
                        if (depositDecision) {
                            balance = balance + notes * 20;
                            note20 += notes;
                            printf("Your balance is %i\n", balance);
                            printf("Number of 20 notes now: %i\n", note20);
                            printf("---------------------------\n");
                        }
                        break;
                    case 50:
                        if (depositDecision) {
                            balance = balance + notes * 50;
                            note50 += notes;
                            printf("Your balance is %i\n", balance);
                            printf("Number of 50 notes now: %i\n", note50);
                            printf("---------------------------\n");
                        }
                        break;
                    case 100:
                        if (depositDecision) {
                            balance = balance + notes * 100;
                            note100 += notes;
                            printf("Your balance is %i\n", balance);
                            printf("Number of 100 notes now: %i\n", note100);
                            printf("---------------------------\n");
                        }
                        break;
                    case 200:
                        if (depositDecision) {
                            balance = balance + notes * 200;
                            note200 += notes;
                            printf("Your balance is %i\n", balance);
                            printf("Number of 200 notes now: %i\n", note200);
                            printf("---------------------------\n");
                        }
                        break;
                    default:
                        printf("Incorrect money format.\n");
                }
                action = options(); // kicks user to main menu if they fail to enter correct amount.
            }
            if (action == 3) {
                printf("Your balance is: %i\n", balance);
                action = options();
            }

        }
        printf("Transaction complete.\n");
    }
    return 0;
}
bool start() {
    //Password checker, 3 tries
    int input;
    const int password = 75;
    printf("Please enter your password: \n");
    for (int i = 0; i <= 2; i++) {
        scanf("%i", &input);
        if (input == password) {
            printf("You have entered the correct password\n");
            return true;
        } else {
            printf("Please try again, you have %i tries left\n", 2 - i);
        }
    }
    printf("Your card has been locked.\n");
    return false;
}

int options() {
    //Main menu of ATM
    int input = 0;
    int i = 0;
    printf("Please enter an action: \n");
    printf("1: Withdrawal, 2: Deposit, 3: Account Information, 4: Exit\n");
    while ((input != 1 && input != 2 && input != 3 && input != 4) && (i <= 4)) {
        scanf("%i", &input);
        switch (input) {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 4;
            default:
                printf("Incorrect argument, you have %i tries left\n", 4 - i);
        }
        printf("Incorrect action, please enter 1, 2, 3 or 4. You have %i tries left\n", 4 - i);
        i++; // User only has 5 tries to enter "1, 2, 3 or 4" otherwise the ATM just closes.
    }
    return 4;
}

int withdrawal() {
    //Money withdrawal prompt
    int withdrawAmount;
    printf("Please enter a withdrawal amount\n");
    scanf("%i", &withdrawAmount);
    return withdrawAmount;
}

bool withdrawContinue() {
    //Asks if user wants to continue withdrawing or proceed to a different action.
    int a = 0;
    printf("Type 1 if you want to continue, any other number if you want to stop withdrawing.\n");
    scanf("%i", &a);
    if (a == 1) return true;
    return false;
}
int depositValueF() { // asks which banknote the user wants to use
    int depositValue, i = 0;
    printf("Please choose which bank note you are depositing: \n");
    printf("Accepting 10, 20, 50, 100 and 200 \n");
    while (i != 1) {
        scanf("%i", &depositValue);
        switch (depositValue) {
            case 10:
            case 20:
            case 50:
            case 100:
            case 200:
                i = 1;
                break;
            default:
                printf("Incorrect banknote. Please enter 10, 20, 50, 100 or 200.\n");
        }
    }
    return depositValue;
}
int noteAmount() { // asks how many notes the user wants to add
    int notes, i = 0;
    while (i != 1) {
        printf("Please enter the amount of notes you are depositing: \n");
        scanf("%i", &notes);
        if (notes > 0) { // user stuck in a loop to type in an amount greater than 0
            i = 1;
        } else printf("Incorrect number of notes. Please type a number greater than 0\n");
    }
    return notes;
}

bool depositConfirm() {
    int i = 2;
    int j = 0;
    printf("Please type 1 to confirm money deposit, 0 to cancel.\n");
    while (i != 1 && i != 0 && j < 3) { // user has 3 tries to type 1 or 0
        scanf("%i", &i);
        if (i != 1 && i != 0) printf("Incorrect input. Please enter 1 or 0. You have %i tries left\n", 2 - i);
        j++;
    }
    if (i == 1) return true;
    return false;
}
