#include <iostream>
#include <limits>
using namespace std;

int findMinInRow(int* row, int n, int j = 0) {
    if (j >= n) return std::numeric_limits<int>::max(); 
    return min(row[j], findMinInRow(row, n, j + 1)); 
}

int findMaxOfMinsInOddRows(int** matrix, int k, int i = 1, int maxOfMins = std::numeric_limits<int>::min()) {
    if (i >= k) return maxOfMins; 
    int minInRow = findMinInRow(matrix[i], 2); 
    if (minInRow != std::numeric_limits<int>::max()) {
        maxOfMins = max(maxOfMins, minInRow); 
    }
    return findMaxOfMinsInOddRows(matrix, k, i + 2, maxOfMins); 
}

int main() {
    int k, n;

    cout << " k = ";
    cin >> k;
    cout << " n = ";
    cin >> n;

    int** matrix = new int* [k];
    for (int i = 0; i < k; ++i) {
        matrix[i] = new int[n];
    }

    cout << "Enter the matrix elements =" << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    int result = findMaxOfMinsInOddRows(matrix, k);
    if (result != std::numeric_limits<int>::min()) {
        cout << "The largest of the minimum elements on odd lines = " << result << endl;
    }
    else {
        cout << "No item was found in odd rows." << endl;
    }

    for (int i = 0; i < k; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
