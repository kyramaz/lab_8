#include <iostream>
using namespace std;

void First_Sort(int n, int* mas, int* mas_sum, int* mas_numeral)
{
    int element{};
    int sum{};

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
}

void Second_Sort(int lines, int columns, int** mas, int* mas_sum)
{
    int need_line{};
    int sum_lines{};
    int minimum = INT_MAX;

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
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

int main()
{
    setlocale(LC_ALL, "rus");

    // 2nd
    /*
    int n{};
    cout << "Введите количество элементов последовательности" << endl;
    cin >> n;

    int* mas = new int[n];
    int* mas_numeral = new int[n];
    int* mas_sum = new int[n];

    cout << "Введите элементы последовательности" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
    }

    First_Sort(n, mas, mas_sum, mas_numeral);

    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;

    int nn{};
    cout << "add nn" << endl;
    cin >> nn;
    mas = (int*)realloc(mas, nn * sizeof(int));
    mas_sum = (int*)realloc(mas_sum, nn * sizeof(int));
    mas_numeral = (int*)realloc(mas_numeral, nn * sizeof(int));

    cout << "add elements" << endl;
    for (int i = n; i < nn; i++)
    {
        cin >> mas[i];
    }
    
    First_Sort(nn, mas, mas_sum, mas_numeral);
    for (int i = 0; i < nn; i++)
    {
        cout << mas[i] << " ";
    }
    for (int i = 0; i < nn; i++)
    {
        delete[] mas[i];
        delete[] mas_sum[i];
        delete[] mas_numeral[i];
    }
    delete[] mas; delete[] mas_sum; delete[] mas_numeral;
    */

    // 3rd
    int lines, columns;
    cout << "Введите количество строк матрицы" << endl;
    cin >> lines;
    cout << "Введите количество столбцов матрицы" << endl;
    cin >> columns;
    
    int** matrix = new int* [lines];
    for (int i = 0; i < lines; i++)
    {
        matrix[i] = new int[columns];
    }
    int* mas_sum = new int[lines];

    Second_Sort(lines, columns, matrix, mas_sum);
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}