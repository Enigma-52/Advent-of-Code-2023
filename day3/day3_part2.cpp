#include <iostream>
using namespace std;

int main() {
    int ROWS=140;
    int COLS=140;
    int sum = 0;

    char schematic[ROWS][COLS + 1];

    int gearCount[ROWS][COLS];
    int gearRatio[ROWS][COLS];

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            gearCount[r][c] = 0;
            gearRatio[r][c] = 1;
        }
    }


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> schematic[i][j];
        }
    }

for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            int number = 0;
            int numDigits = 0;
            while (schematic[r][c] >= '0' && schematic[r][c] <= '9' && c < COLS) {
                number *= 10;
                number += schematic[r][c] - '0';
                numDigits ++;
                c ++;
            }
            if (number) {
                for (int r2 = r - 1; r2 <= r + 1; r2++) {
                    for (int c2 = c - numDigits - 1; c2 <= c; c2++) {
                        if (r2 >= 0 && r2 < ROWS && c2 >= 0 && c2 < COLS) {
                            if (schematic[r2][c2] == '*') {
                                gearCount[r2][c2] ++;
                                gearRatio[r2][c2] *= number;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (gearCount[r][c] == 2) {
                sum += gearRatio[r][c];
            }
        }
    }

    cout << sum << endl;
}
