// лб 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <vector>
#define MS 200 

using namespace std;

void print(float* B, int n)
{
    cout << "Масив B: ";
    for (int i = 0; i < n; i++)cout << B[i] << " ";
    cout << endl;
}

void foo(float* A, int n)
{
    int z = 0, k = 0;

    for (int i = 0; i < n; i++)if (A[i] < 0)k++;
    float* B = new float[k];

    for (int i = 0; i < n; i++)if (A[i] < 0)
    {
        B[z] = A[i]; z++;
    }
    print(B, k);
    delete[] B;
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int V;
    cout << "Оберіть варіант вводу" << endl << "з консолі - 1" << endl << "з файлу(ів) - 2" << endl << "з використанням датчика випадкових чисел - 3" << endl <<"Введіть цифру відповідно обраного варіанту: ";
    cin >> V;
    if (V == 1)
    {
        int n;
        float A[MS];
        cout << "Введіть довжину масива: ";
        cin >> n;
        cout << "Заповніть масив" << endl;
        for (int i = 0; i < n; i++)cin >> A[i];    
        foo(A, n);
    }
    else if (V == 2)
    {
        string name;
        int m, k = 0, n = -1;
        float x;
        cout << "Введіть назву файла: ";
        cin >> name;
        ofstream fout;
        fout.open(name);

        cout << "Вкажіть кількість чисел: ";
        cin >> m;
        cout << "Заповніть файл: ";
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            fout << x << " ";
        }
        fout.close();


        ifstream fin;
        fin.open(name);  
        while (!fin.eof())
        {
            fin >> x;
            n++;
        }
        fin.close();       
        float* A = (float*)malloc(sizeof(float)*n);

        fin.open(name);
        for (int i = 0; i < n; i++)
        {
            fin >> A[i];
        }
        fin.close();
        foo(A, n);
        free(A);
    }
    else if (V == 3)
    {

        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        int n, k = 0, z = 0;
        cout << "введіть кількість чесел: "; cin >> n;
        vector<float> A;
        A.reserve(n);

        for (int i = 0; i < n; i++) A.push_back(static_cast<int>(rand() * fraction * (100 - (-100) + 1) + (-100)));
        cout << "Масив А: ";
        for (int i = 0; i < n; i++)cout << A[i] << " ";
        cout << endl;

        for (int i = 0; i < n; i++)if (A[i] < 0)k++;
        float* B = new float[k];

        for (int i = 0; i < n; i++)if (A[i] < 0)
        {
            B[z] = A[i]; z++;
        }
        print(B, k);
        delete[] B;
    }
    system("pause");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
