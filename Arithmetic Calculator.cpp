#include <iostream>
using namespace std;
int main() 
{
    cout<<endl<<endl<<"\t\tSIMPLE ARITHMETIC CALCULATOR"<<endl<<endl;
    double num1, num2;
    char operation;
    cout << "\nEnter first number: ";
    cin >> num1;

    cout << "\nEnter second number: ";
    cin >> num2;

    cout << "\nEnter operation (+, -, *, /): ";
    cin >> operation;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "\nError: Division by zero is not allowed." << endl;
                return 1;  
            }
            break;
        default:
            cout << "\nInvalid operation." << endl;
            return 1;  
    }

    cout << "\nResult: " << result << endl<<endl;

    return 0;
}
