/*
Sanjay Kaliyur

ARM Assembly Textbook
Chapter 2 Problem 22

*/

#include <iostream>

using namespace std;

// Converts the array to binary.
int binary(int a[])
{
    for (int i = 7; i >= 0; i--)
    {
        cout << a[i];
    }
}

int main(int argc, char *argv[])
{

    int num, temp, temp2;
    int a [8];

    cout << "Enter a number between -127 to 255" << endl;
    cin >> num;

    // Sets range
    if (num > 255 || num < -128)
    {
        cout << "out of range" << endl;
        return 1;
    }

    if (num < 0) // negative number
    {
        temp2 = num + -2*num;
        for (int i = 0; i < 8; i++)
        {
            temp = temp2 % 2;
            a[i] = temp;
            temp2 = temp2/2;
        }
    }
    else // positive number
    {
        temp2 = num;
        for (int i = 0; i < 8; i++)
        {
            temp = temp2 % 2;
            a[i] = temp;
            temp2 = temp2/2;
        }
    }

    // Converts all ranges to binary
    if (num < 0) // -127 - 0
    {
        cout << "2's complement: ";

        int max = 0;

        for (int i = 7; i >= 0; i--)
        {
            //cout << a[i];
            if (a[i] == 1)
                max = i;
        }

        for (int i = 7; i > max; i--)
        {
            if (a[i] == 1)
                cout << 0;
            else
                cout << 1;
        }

        for (int i = max; i >= 0; i--)
            cout << a[i];

    }
    else if (num >= 0 && num < 128) // 0 - 127
    {
        cout << "both unsigned and 2's complement: ";
        binary(a);
    }
    else // 128 - 255
    {
        cout << "unsigned: ";
        binary(a);
    }
    cout << endl;

    return 0;
}
