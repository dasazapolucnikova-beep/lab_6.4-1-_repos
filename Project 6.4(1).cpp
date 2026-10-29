#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Рекурсивне створення динамічного масиву
void CreateRec(int* a, const int size, const int Low, const int High, int i = 0) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        CreateRec(a, size, Low, High, i + 1);
    }
}

// 2. Рекурсивне виведення масиву у рядок
void PrintRec(const int* a, const int size, int i = 0) {
    cout << setw(5) << a[i];
    if (i < size - 1) {
        PrintRec(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// 3.1. Рекурсивний пошук мінімального за модулем елемента
int MinAbsRec(const int* a, const int size, int i = 1, int minVal = 0) {
    if (i == 1) {
        minVal = a[0];
    }
    if (i >= size) {
        return minVal;
    }
    if (abs(a[i]) < abs(minVal)) {
        minVal = a[i];
    }
    return MinAbsRec(a, size, i + 1, minVal);
}

// Допоміжна рекурсивна функція: пошук першого нуля
int FindFirstZeroRec(const int* a, const int size, int i = 0) {
    if (i >= size) {
        return -1; // Нуль не знайдено
    }
    if (a[i] == 0) {
        return i;
    }
    return FindFirstZeroRec(a, size, i + 1);
}

// Допоміжна рекурсивна функція: обчислення суми модулів від заданого індексу
int SumAbsAfterIndexRec(const int* a, const int size, int i) {
    if (i >= size) {
        return 0;
    }
    return abs(a[i]) + SumAbsAfterIndexRec(a, size, i + 1);
}

// 3.2. Головна рекурсивна функція суми модулів після першого нуля
int SumAbsAfterFirstZeroRec(const int* a, const int size) {
    int zeroIdx = FindFirstZeroRec(a, size);
    if (zeroIdx == -1 || zeroIdx == size - 1) {
        return 0; // Нуля немає або він останній
    }
    return SumAbsAfterIndexRec(a, size, zeroIdx + 1);
}

// Допоміжні рекурсивні функції для перетворення масиву
void CopyEvenIndicesRec(const int* src, int* dest, const int size, int srcIdx, int& destIdx) {
    if (srcIdx >= size) return;
    dest[destIdx++] = src[srcIdx];
    CopyEvenIndicesRec(src, dest, size, srcIdx + 2, destIdx);
}

void CopyOddIndicesRec(const int* src, int* dest, const int size, int srcIdx, int& destIdx) {
    if (srcIdx >= size) return;
    dest[destIdx++] = src[srcIdx];
    CopyOddIndicesRec(src, dest, size, srcIdx + 2, destIdx);
}

void CopyArrayRec(const int* src, int* dest, const int size, int i = 0) {
    if (i >= size) return;
    dest[i] = src[i];
    CopyArrayRec(src, dest, size, i + 1);
}

// 4. Рекурсивне перетворення масиву (парні позиції 0,2,4... в першу половину, непарні 1,3,5... в другу)
void TransformRec(int* a, const int size) {
    int* temp = new int[size];
    int destIdx = 0;

    // Копіюємо елементи з парними індексами (0, 2, 4...)
    CopyEvenIndicesRec(a, temp, size, 0, destIdx);
    // Копіюємо елементи з непарними індексами (1, 3, 5...)
    CopyOddIndicesRec(a, temp, size, 1, destIdx);

    // Переносимо результати назад у вихідний масив
    CopyArrayRec(temp, a, size);

    delete[] temp;
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    // Створення динамічного масиву
    int* a = new int[n];

    // Формування масиву
    CreateRec(a, n, -10, 10);

    cout << "\nInitial array a:" << endl;
    PrintRec(a, n);

    // 1.1. Мінімальний за модулем елемент
    int minAbs = MinAbsRec(a, n);
    cout << "\nMin by absolute value = " << minAbs << endl;

    // 1.2. Сума модулів після першого нуля
    int sumAbs = SumAbsAfterFirstZeroRec(a, n);
    int zeroPos = FindFirstZeroRec(a, n);
    if (zeroPos != -1) {
        cout << "First zero found at index " << zeroPos << endl;
        cout << "Sum of absolute values after first zero = " << sumAbs << endl;
    }
    else {
        cout << "Zero element was not found in array. Sum = 0" << endl;
    }

    // 2. Перетворення масиву
    TransformRec(a, n);

    cout << "\nTransformed array a:" << endl;
    PrintRec(a, n);

    // Очищення динамічної пам'яті
    delete[] a;

    return 0;
}