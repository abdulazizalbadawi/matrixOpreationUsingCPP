#include <iostream>
using namespace std;


int main()
{
    // y,z is size of mat1 y1,z1 size of mat2 i,j counters
    int y, y1, z, z1, i, j, k;
    int oper = 0;
    int arr1[10][10], arr2[10][10], sum[10][10], sub[10][10], mul[10][10];
    cout << "Please enter dimensions of Matrix A:" << endl;
    cin >> y >> z;
    cout << "Please enter dimensions of Matrix B:" << endl;
    cin >> y1 >> z1;
    cout << "Please enter values of Matrix A:" << endl;
    for (i = 0; i < y; ++i)
        for (j = 0; j < y; ++j)
            cin >> arr1[i][j];
    cout << "Please enter values of Matrix B:" << endl;
    for (i = 0; i < y1; ++i)
        for (j = 0; j < z1; ++j)
            cin >> arr2[i][j];
    // cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
    // cin >> oper;

    while (oper != 7)
    {
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
        cin >> oper;
        switch (oper)
        {
        case 1:
            if (y != y1 || z != z1)
            {
                cout << "The operation you chose is invalid for the given matrices." << endl;
            }
            else
            {
                for (i = 0; i < y; ++i)
                    for (j = 0; j < z; ++j)
                        sum[i][j] = arr1[i][j] + arr2[i][j];
                for (i = 0; i < y; ++i)
                    for (j = 0; j < z; ++j)
                    {
                        cout << sum[i][j] << " ";
                        if (j == z - 1)
                            cout << endl;
                    }
            }
            break;

        case 2:
            if (y != y1 || z != z1)
            {
                cout << "The operation you chose is invalid for the given matrices." << endl;
            }
            else
            {
                for (i = 0; i < y; ++i)
                    for (j = 0; j < z; ++j)
                        sub[i][j] = arr1[i][j] - arr2[i][j];
                for (i = 0; i < y; ++i)
                    for (j = 0; j < z; ++j)
                    {
                        cout << sub[i][j] << " ";
                        if (j == z - 1)
                            cout << endl;
                    }
            }
            break;

        case 3:
            if (z != y1)
            {
                cout << "The operation you chose is invalid for the given matrices." << endl;
            }
            else
            {
                for (int k = 0; k < y; k++) {
                    for (int j = 0; j < z1; j++)
                    {
                        mul[k][j] = 0;
                        for (int i = 0; i < y1; i++)
                        {
                            mul[k][j] += arr1[k][i] * arr2[i][j];
                        }
                    }

                }
                for (k = 0; k < y; k++)
                {
                    for (j = 0; j < z1; j++)
                    {
                        cout << mul[k][j] << " ";
                    }
                    cout << endl;
                }
            }
            break;

        case 7:
            cout << "Thank you!";
            return 0;


        }
    }
}