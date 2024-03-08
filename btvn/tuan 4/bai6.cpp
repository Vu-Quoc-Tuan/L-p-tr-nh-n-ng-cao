#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> magicSquare(N, vector<int>(N, 0));
    int i = 0;
    int j = N / 2;

    for (int num = 1; num <= N * N; num++) {
        magicSquare[i][j] = num;
        int newi = (i - 1 + N) % N;
        int newj = (j + 1) % N;
        if (magicSquare[newi][newj] != 0) {
            i = (i + 1) % N;
        } else {
            i = newi;
            j = newj;
        }
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << magicSquare[row][col] << "\t";
        }
        cout << endl;
    }

    return 0;
}
