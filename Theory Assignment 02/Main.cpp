#include "Functions.h"

int PolynomialCounter;

int main() {
    cout << endl << endl;
    PolynomialCounter = 0;
    bool isRunning = true;
    vector<LinkedList> Polynomials;

    while (isRunning) {
        MainMenu();
        int choice = getValidChoice();

        if (choice == 7) {
            cout << "\nGoodbye!\n";
            isRunning = false;
        } else if (choice == 1) {
            LinkedList newPolynomial;
            newPolynomial.setListID("Poly" + to_string(PolynomialCounter + 1));
            
            int nterms = getValidInput("\nHow many terms will the polynomial have: ");
            for (int i = 0; i < nterms; i++) {
                int c = getValidInput("\nEnter coefficient for term " + to_string(i + 1) + ": ");
                int e = getValidInput("\nEnter exponent for term " + to_string(i + 1) + ": ");
                newPolynomial.InsertTerm(c, e);
            }
            Polynomials.push_back(newPolynomial);
            PolynomialCounter++;
            cout << "\nPolynomial inserted successfully!\n";
        } else if (choice == 2 || choice == 3 || choice == 4) {
            if (PolynomialCounter < 2) {
                cout << "\nPlease insert at least 2 polynomials first!\n";
            } else {
                cout << "\nAvailable polynomials:\n";
                for (int i = 0; i < PolynomialCounter; i++) {
                    cout << i + 1 << ". " << Polynomials[i].getListID() << endl;
                }
                
                int select1 = getValidChoice("\nSelect the first polynomial: ", 1, PolynomialCounter) - 1;
                int select2 = getValidChoice("\nSelect the second polynomial: ", 1, PolynomialCounter) - 1;
                while (select2 == select1) {
                    cout << "\nPolynomial already selected. Choose a different polynomial.\n";
                    select2 = getValidChoice("\nSelect another polynomial: ", 1, PolynomialCounter) - 1;
                }

                LinkedList result;
                if (choice == 2) {
                    result = Polynomials[select1] + Polynomials[select2];
                    cout << "\nSUM: ";
                } else if (choice == 3) {
                    result = Polynomials[select1] - Polynomials[select2];
                    cout << "\nDIFFERENCE: ";
                } else {
                    result = Polynomials[select1] * Polynomials[select2];
                    cout << "\nPRODUCT: ";
                }
                result.Display();
            }
        } else if (choice == 5) {
            if (PolynomialCounter > 0) {
                double x = getValidInput("\nEnter the value of x: ");
                cout << "\nAvailable polynomials:\n";
                for (int i = 0; i < PolynomialCounter; i++) {
                    cout << i + 1 << ". " << Polynomials[i].getListID() << endl;
                }
                
                int select = getValidChoice("\nSelect a polynomial: ", 1, PolynomialCounter) - 1;
                cout << "\n" << Polynomials[select].getListID() << " at x = " << x << " is: " << Polynomials[select].evaluate(x) << endl;
            } else {
                cout << "\nPlease insert at least 1 polynomial first.\n";
            }
        }else if(choice == 6){
            cout << "\n-------- All Polynomials ---------\n";
            for(int i = 0; i < PolynomialCounter ; i++){
                cout << endl;
                cout << Polynomials[i].getListID() << ": ";
                Polynomials[i].Display();
                cout << endl;
            }
        }
    }

    cout << endl << endl;
    return 0;
}
