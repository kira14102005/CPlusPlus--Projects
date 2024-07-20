#include "../HeaderFile/file.h"
#include <math.h>

using namespace std;

double calc(double a, double b, char o)
{
    switch (o)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            cout << "Division by zero error!" << endl;
            return INT_MIN;
        }
        return a / b;
    case '^':
        return pow(a, b);
    default:
        cout << "INVALID OPERATION" << endl;
        return INT_MIN;
    }
}

int main()
{
    while (true)
    {
        int i;
        cout << "Press 0 to continue entering inputs\nPress 1 to Exit from Calc\n";
        cin >> i;
        if (i == 1)
        {
            cout << "Thank you for using Calc!!" << endl;
            break;
        }
        else if (i != 0)
        {
            cout << "Sorry Wrong Input! Enter Again" << endl;
            continue;
        }
        double a, b;
        char c;
        cout << "Enter the Operand 1 : ";
        cin >> a;

        cout << "Enter the Operand 2 : ";
        cin >> b;

        cout << "Enter the Operation : ";
        cin >> c;

        double result = calc(a, b, c);
        if(result == INT_MIN)
            cout << "Error in calculation!!" << endl;
        else
            cout << "The RESULT : " << result << endl;

        cout << string(40, '-') << endl;
    }

    return 0;
}
