#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include "counter.h"

using namespace std;

// Task 4, 5
// int main() {
//     char text[MAXTEXTLENGTH];
//     cout << "Enter text: ";
//     cin.getline(text, MAXTEXTLENGTH - 1, '*');
//     cout << "Sourse text:" << endl << text << endl;

//     Counter counts;
//     cout << "The number of punctuation marks is: " << counts.countPunctuationMarks(text) << endl;

// 	return 0;
// }


// Task 6


void printMatrix(double** a, int n, int m);
void transpose(double** a, int n, int m);
double** inputMatrix(char* fileName, int& n, int& m);
void outputMatrix(char* fileName, double** matr, int n, int m);
void del(double** matr, int n);

void maxSumRow(double** matr, int row, int col);

int main() {
    char fileName[40];
    cout << "Input the name of file: ";
    cin >> fileName;

    double** matr;
    int n = 0, m = 0;

    matr = inputMatrix(fileName, n, m);
    printMatrix(matr, n, m);
    //transpose(matr, n, m);
    //cout << endl << endl << "Transpose matrix" << endl << endl;
    maxSumRow(matr, n, m);

    printMatrix(matr, n, m);

    char nameOutputFile[40];
    cout << "Input the name of output file: ";
    cin >> nameOutputFile;
    outputMatrix(nameOutputFile, matr, n, m);
    del(matr, n);

    return 0;
}


double** inputMatrix(char* fileName, int& n, int& m) {
    ifstream fin(fileName);

    if (!fin) {
        cout << "Cannot open file.\n";
        exit(1);
    }

    double** matr;
    fin >> n;
    fin >> m;
    matr = new double*[n];

    if (!matr) {
        cout << "Error memory allocation.\n";
        exit(2);
    }

    for (int i = 0; i < n; i++) {
        matr[i] = new double[m];
        if (!matr[i]) {
            cout << "Error memory allocation.\n";
            exit(2);
        }
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            fin >> matr[i][j];
        }
    }
    fin.close();

    return matr;
}


void printMatrix(double** a, int n, int m) {
    cout.setf(ios::fixed);
    cout.precision(2);

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cout.width(7);
            cout << a[i][j];
        }
        cout << endl;
    }
}


void transpose(double** a, int n, int m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<i; j++) {
            double t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }
}


void outputMatrix(char* fileName, double** matr, int n, int m) {
    ofstream fout(fileName);

    if (!fout) {
        cout << "Cannot open output file.\n";
        exit(1);
    }

    int i, j;
    fout << n << " " << m << endl;

    for (i = 0; i<n; i++) {
        for (j = 0; j<m; j++) {
            fout.width(8);
            fout << matr[i][j];
        }
        fout << endl;
    }
    fout.close();
}


void del(double** matr, int n) {

    for (int i = 0; i < n; i++) {
        delete[] matr[i];
    }
    delete[] matr;
}

void maxSumRow(double** matr, int row, int col) {
    int maxSum = 0;
    int currSum = 0;
    int rowWithMaxSum = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            currSum += abs(matr[i][j]);
        }
        if (currSum > maxSum) {
            maxSum = currSum;
            rowWithMaxSum = i;
        }
        currSum = 0;
    }

    cout << "Row with max sum of elements is " << rowWithMaxSum << " max sum is " << maxSum << endl;
}
