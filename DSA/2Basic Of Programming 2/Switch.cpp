#include <iostream>
using namespace std;

int main()
{

    float a, b, ans;
    cout << "Enter any two numbers : ";
    cin >> a >> b;
    cout << "Enter the operation you want to perform : ";
    // int op;
    char op;
    cin >> op;

    switch (op)
    {
    case 65:
        cout << "First operation : ";
        ans = a + b;
        break;
    case 66:
        cout << "Second operation : ";
        ans = a - b;
        break;
    case 67:
        cout << "third operation : ";
        ans = a / b;
        break;
    case 68:
        cout << "fourth operation : ";
        ans = a * b;
        break;
    case '+': // IF 'A' instead of '+' then error as A is already used as 65 in case I
        cout << "fifth operation : ";
        ans = a + b;
        break;
        // continue; // ERROR
    case '-':
        cout << "sixth operation : ";
        ans = a - b;
        break;
    case '/':
        cout << "seventh operation : ";
        ans = a / b;
        break;
    case '*':
        cout << "eigth operation : ";
        ans = a * b;
        break;
    default:
        cout << "Invalid choice." << endl;
        return 0;
    }
    cout << ans << endl;

    // // ERROR WITH FLOATING VALUE
    // float op;
    // cin >> op;
    // float a = 4, b = 6;
    // switch (op)
    // {
    // case 3:
    //     cout << a + b << endl;
    // default:
    //     cout << "Invalid Choice" << endl;
    // }
    return 0;
}