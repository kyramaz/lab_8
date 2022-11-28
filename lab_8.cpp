#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // 1st
    /*int mas[10000];
    int n;
    int element;
    bool result = false;

    cout << "введите длину последовательности."<< endl;
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        cout << "введите " << i+1 << " элемент последовательности." << endl;
        cin >> mas[i];
    }
    for (int i = 0; i < n; i++)
    {
        element = mas[i];
        while (element > 9) 
        {
            element /= 10;
        }
        if (element == 1) 
        {
            result = true;
            break;
        }
    }
    if (result = true) {
        for (int i = 0; i < n-1; i++){
            for (int j = i + 1; j < n; j++) {
                if (mas[i] > mas[j]) {
                    swap(mas[i], mas[j]);
                }
            }
        }
    }
    else {
        cout << "ни одно число не подошло по условию." << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }*/


    // 2nd
    /*int n;
    int element;
    int sum{0};
    int mas[1000];
    int mas_sum[1000];
    int mas_numeral[1000];
    
    cout << "Введите длину последовательности натуральных чисел" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "Введите " << i + 1 << " элемент последовательности" << endl;
        cin >> mas[i];
    }

    for (int i = 0; i < n; i++)
    {
        element = mas[i];
        sum = 0;

        while (element > 9)
        {
            sum += (element % 10);
            element /= 10;
        }
        mas_numeral[i] = element;
        sum += element;
        mas_sum[i] = sum;
    }

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (mas_numeral[i] > mas_numeral[j])
            {
                swap(mas[i], mas[j]);
                swap(mas_numeral[i], mas_numeral[j]);
                swap(mas_sum[i], mas_sum[j]);
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mas_numeral[i] == mas_numeral[j])
            {
                if (mas_sum[i] > mas_sum[j])
                {
                    swap(mas[i], mas[j]);
                    swap(mas_numeral[i], mas_numeral[j]);
                    swap(mas_sum[i], mas_sum[j]);
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((mas_numeral[i] == mas_numeral[j]) && (mas_sum[i] == mas_sum[j]))
            {
                if (mas[i] > mas[j])
                {
                    swap(mas[i], mas[j]);
                    swap(mas_numeral[i], mas_numeral[j]);
                    swap(mas_sum[i], mas_sum[j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        cout << mas[i] << " ";
    }*/

    // 3rd
    int mas[100][100];
    int minimum = 999999;
    int lines;
    int columns;
    int sum_lines = 0;
    int mas_sum[100];
    int need_line{};
    
    cout << "Введите количество строк матрицы" << endl;
    cin >> lines;
    cout << "Введите количество столбцов матрицы" << endl;
    cin >> columns;
    
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Введите элемент " << i+1 << " строки " << j+1 << " столбца." << endl;
            cin >> (mas[i][j]);
        }
    }
    for (int i = 0; i < lines; i++)
    {
        sum_lines = 0;
        for (int j = 0; j < columns; j++)
        {
            sum_lines += mas[i][j];
        }
        mas_sum[i] = sum_lines;
    }

    for (int i = 0; i < lines; i++)
    {
        if (abs((mas_sum)[i]) < minimum)
        {
            minimum = abs(mas_sum[i]);
            need_line = i;
        }
    }

    for (int j = 0; j < columns; j++)
    {
        mas[need_line][j] = 0;
    }

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}