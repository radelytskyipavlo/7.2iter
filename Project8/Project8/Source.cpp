#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void FindAndSwapMinMax(int** a, const int k, const int n);
void Swap(int& a, int& b);
void DeleteMatrix(int** a, const int k);

int main() {
    int Low = 7;
    int High = 65;
    int k;
    int n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];
    Create(a, k, n, Low, High);
    Print(a, k, n);

    FindAndSwapMinMax(a, k, n);
    Print(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    srand(time(0));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
void FindAndSwapMinMax(int** a, const int k, const int n) {
    for (int i = 0; i < k; i++) {
        int minRow = i, minCol = 0;
        int maxRow = i, maxCol = 0;
        int minValue = a[i][0], maxValue = a[i][0];
        for (int j = 0; j < n; j++) {
            if (a[i][j] < minValue) {
                minValue = a[i][j];
                minCol = j;
            }
            if (a[i][j] > maxValue) {
                maxValue = a[i][j];
                maxCol = j;
            }
        }
        for (int j = 0; j < n; j++) {
            if (a[i][j] == minValue) {
                minCol = j;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (a[i][j] == maxValue) {
                maxCol = j;
                break;
            }
        }
        Swap(a[minRow][minCol], a[maxRow][maxCol]);
    }
}

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
