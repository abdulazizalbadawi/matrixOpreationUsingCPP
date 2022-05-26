#include <iostream>

#include <cmath>

using namespace std;

// "smldet" is a function to solve 2x2 determant  
long double smldet(int val1, int val2, int val3, int val4) {
    long double det1 = (val1 * val4 - val2 * val3);
    return det1;
}

// "determ" is a function to solve nxn determant  
long long determ(int arr1[10][10], int n) {
    int p, h, k, i, j, temp[10][10];
    long long det = 0;
    // 1x1 determant
    if (n == 1) {
        return arr1[0][0];
    } 
    // 2x2 determant 
    else if (n == 2) {
        det = (arr1[0][0] * arr1[1][1] - arr1[0][1] * arr1[1][0]);
        return det;
    }
    // nxn determant
    else {
        for (p = 0; p < n; p++) {
            h = 0;
            k = 0;
            for (i = 1; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (j == p) {
                        continue;
                    }
                    temp[h][k] = arr1[i][j];
                    k++;
                    if (k == n - 1) {
                        h++;
                        k = 0;
                    }
                }
            }
            // apply sign roles 
            det = det + arr1[0][p] * pow(-1, p) * determ(temp, n - 1);
        }
        return det;
    }
}

int main() {
    // y,z is size of mat1 y1,z1 size of mat2 i,j,k counters
    int y, y1, z, z1, i, j, k, l;
    // oper is input by the user 
    int oper = 0;
    // declare matrices 
    int arr1[10][10], arr2[10][10], sum[10][10], sub[10][10], mul[10][10];
    double inv[10][10], adj[10][10], div[10][10], invAdj[10][10];
    cout << "Please enter dimensions of Matrix A:" << endl;
    // matrix A size
    cin >> y >> z;
    cout << "Please enter dimensions of Matrix B:" << endl;
    // matrix A size
    cin >> y1 >> z1;
    cout << "Please enter values of Matrix A:" << endl;
    // Matrix A values
    for (i = 0; i < y; ++i)
        for (j = 0; j < z; ++j)
            cin >> arr1[i][j];
    cout << "Please enter values of Matrix B:" << endl;
    // Matrix B values
    for (i = 0; i < y1; ++i)
        for (j = 0; j < z1; ++j)
            cin >> arr2[i][j];

    while (oper != 7) {
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
        cin >> oper;
        switch (oper) {
        // case 1 is adding case 
        case 1:
            if (y != y1 || z != z1) {
                cout << "The operation you chose is invalid for the given matrices." << endl;
            } else {
                for (i = 0; i < y; ++i)
                    for (j = 0; j < z; ++j)
                        sum[i][j] = arr1[i][j] + arr2[i][j];
                for (i = 0; i < y; ++i)
                    for (j = 0; j < z; ++j) {
                        cout << sum[i][j] << " ";
                        if (j == z - 1)
                            cout << endl;
                    }
            }
            break;

        case 2:
        // case 2 is subtraction case
            if (y != y1 || z != z1) {
                cout << "The operation you chose is invalid for the given matrices." << endl;
            } else {
                for (i = 0; i < y; ++i)
                    for (j = 0; j < z; ++j)
                        sub[i][j] = arr1[i][j] - arr2[i][j];
                for (i = 0; i < y; ++i)
                    for (j = 0; j < z; ++j) {
                        cout << sub[i][j] << " ";
                        if (j == z - 1)
                            cout << endl;
                    }
            }
            break;
        case 3:
        // case 3 is multiply case
            if (z != y1) {
                cout << "The operation you chose is invalid for the given matrices." << endl;
            } else {
                for (int k = 0; k < y; k++) {
                    for (int j = 0; j < z1; j++) {
                        mul[k][j] = 0;
                        for (int i = 0; i < y1; i++) {
                            mul[k][j] += arr1[k][i] * arr2[i][j];
                        }
                    }

                }
                for (k = 0; k < y; k++) {
                    for (j = 0; j < z1; j++) {
                        cout << mul[k][j] << " ";
                    }
                    cout << endl;
                }
            }
            break;

        case 4:
        // case 4 is division case
            if (determ(arr2, y1) == 0) {
                cout << "The operation you chose is invalid for the given matrices." << endl;
            } else {
                // define adjoint matrix
                adj[0][0] = smldet(arr2[1][1], arr2[1][2], arr2[2][1], arr2[2][2]);
                adj[0][1] = -smldet(arr2[1][0], arr2[1][2], arr2[2][0], arr2[2][2]);
                adj[0][2] = smldet(arr2[1][0], arr2[1][1], arr2[2][0], arr2[2][1]);
                adj[1][0] = -smldet(arr2[0][1], arr2[0][2], arr2[2][1], arr2[2][2]);
                adj[1][1] = smldet(arr2[0][0], arr2[0][2], arr2[2][0], arr2[2][2]);
                adj[1][2] = -smldet(arr2[0][0], arr2[0][1], arr2[2][0], arr2[2][1]);
                adj[2][0] = smldet(arr2[0][1], arr2[0][2], arr2[1][1], arr2[1][2]);
                adj[2][1] = -smldet(arr2[0][0], arr2[0][2], arr2[1][0], arr2[1][2]);
                adj[2][2] = smldet(arr2[0][0], arr2[0][1], arr2[1][0], arr2[1][1]);

                //apply Transpose on adjoint matrix
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        invAdj[i][j] = adj[j][i];
                    }
                }
                // define inverse of Matrix B
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        inv[i][j] = invAdj[i][j] / determ(arr2, y1);
                    }
                }
                // Division of A,B is equal (A*B^-1) 
                for (int k = 0; k < y; k++) {
                    for (int j = 0; j < z1; j++) {
                        div[k][j] = 0;
                        for (int i = 0; i < y1; i++) {
                            div[k][j] += arr1[k][i] * inv[i][j];
                        }
                    }

                }
                // printing divsion matrix
                for (k = 0; k < 3; k++) {
                    for (l = 0; l < 3; l++) {
                        int af = round(div[k][l]);
                        cout << af << " ";
                    }
                    cout << endl;
                }

            }
            break;

        case 5:
        // case 5 is determant of Matrix A
            if (y != z) {
                cout << "The operation you chose is invalid for the given matrices." << endl;
            } else {
                cout << determ(arr1, y) << endl;

            }
            break;

        case 6:
        // case 6 is determant of Matrix B
            if (y1 != z1) {
                cout << "The operation you chose is invalid for the given matrices." << endl;
            } else {
                cout << determ(arr2, y1) << endl;
            }
            break;
        // Quit case
        case 7:
            cout << "Thank you!";
            return 0;

        }
    }
}