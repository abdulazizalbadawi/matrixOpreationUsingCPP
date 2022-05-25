#include <iostream>

#include <cmath>

using namespace std;

long long determ(int arr1[10][10], int n) {
        int p, h, k, i, j, temp[10][10];
        long long det = 0,
                if (n == 1) {
                        return arr1[0][0];
                } else if (n == 2) {
                det = (arr1[0][0] * arr1[1][1] - arr1[0][1] * arr1[1][0]);
                return det;
        } else {
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
                        det = det + arr1[0][p] * pow(-1, p) * determ(temp, n - 1);
                }
                return det;
        }
}

int main() {
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
                for (j = 0; j < z; ++j)
                        cin >> arr1[i][j];
        cout << "Please enter values of Matrix B:" << endl;
        for (i = 0; i < y1; ++i)
                for (j = 0; j < z1; ++j)
                        cin >> arr2[i][j];
        // cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
        // cin >> oper;

        while (oper != 7) {
                cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
                cin >> oper;
                switch (oper) {
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

                case 5:
                        if (y != z) {
                                cout << "The operation you chose is invalid for the given matrices." << endl;
                        } else {
                                cout << determ(arr1, y) << endl;

                        }
                        break;

                case 6:
                        if (y1 != z1) {
                                cout << "The operation you chose is invalid for the given matrices." << endl;
                        } else {
                                cout << determ(arr2, y1) << endl;
                        }
                        break;

                case 7:
                        cout << "Thank you!";
                        return 0;

                }
        }
}
