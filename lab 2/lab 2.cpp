#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    double x_1, x_2, step;
    int n;
    char restart;
    bool correctInput;
    //213d
    do {
        cout << "Set the way of input 123 " << endl;

        correctInput = false;
        do {
            cout << "Enter x_1: ";
            cin >> x_1;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a numeric value for x_1." << endl;
            }
            else {
                correctInput = true;
            }
        } while (!correctInput);

        correctInput = false;
        do {
            cout << "Enter x_2 (x_2 >= x_1): ";
            cin >> x_2;
            if (cin.fail() || (x_2 < x_1)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. x_2 must be greater than or equal to x_1." << endl;
            }
            else {
                correctInput = true;
            }
        } while (!correctInput);

        correctInput = false;
        do {
            cout << "Enter step: ";
            cin >> step;
            if (cin.fail() || ((x_1 < x_2 && step <= 0) || (x_1 > x_2 && step >= 0))) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Step must move x_1 towards x_2." << endl;
            }
            else {
                correctInput = true;
            }
        } while (!correctInput);

        correctInput = false;
        do {
            cout << "Enter n (n > 3): ";
            cin >> n;
            if (cin.fail() || n <= 3 || (n != static_cast<int>(n))) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. n must be an integer greater than 3." << endl;
            }
            else {
                correctInput = true;
            }
        } while (!correctInput);

        for (double current_x = x_1; current_x <= x_2; current_x += step)
        {
            cout << "Value of x_1 is : " << current_x << ";" << endl;
            double y = 1;
            if (current_x < 3) {
                for (int i = 1; i <= n - 2; i++) {
                    y *= (i + current_x);
                }
            }
            else {
                for (int i = 1; i <= n; i++) {
                    double sum = 0;
                    for (int j = 1; j <= n + 3; j++) {
                        sum += (i + 1.0 / (4.0 * j * j));
                    }
                    y *= sum;
                }
            }
            cout << "Value of y is : " << y << endl;
        }

        cout << "Do you want to restart the program with new inputs? (y/n): ";
        cin >> restart;
        cin.ignore(10000, '\n');
    } while (restart == 'y' || restart == 'Y');

    return 0;
}
