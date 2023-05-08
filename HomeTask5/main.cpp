#include <iostream>
#include <string>

using namespace std;

//Написать программу, которая содержит функцию Action, принимающую в качестве аргумента,
//указатели на два массива(А и В) и размеры массивов, а также указатель на функцию.
//Пользователю отображается меню, в котором он может выбрать max, min, avg.Если выбран max
//- передается указатель на функцию, которая ищет максимум,
//если выбран min - передается указатель на функцию, которая ищет минимум, если выбран avg -
//передается указатель на функцию, которая ищет среднее.
//Возвращаемое значение функции Action результат выбора пользователя max, min, avg.

double Action(int* arr, int size, double (*pAction)(int const *massiv, int const& size))
{
	return (*pAction)(arr, size);
} 
double MaxArray(int const *arr, int const &size)
{
	double max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}
double MinArray(int const *arr, int const &size)
{
	double min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min) min = arr[i];
	}

	return min;
}
double AveregArray(int const *arr, int const &size)
{
	double sum = 0;
	double avereg = 0;
	for (int i = 0; i < size; i++) sum += arr[i];
	
	avereg = sum / size;
	return avereg;
}
void   PrintArray(int const *arr, int const &size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << "\t";
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	double (*pAction) (int const* massiv, int const& size);
	int const size = 10;
	int const size2 = 15;
	int A[size] = { 1,5,8,9,2,12,56,21,99,6 };
	int B[size2]= { 2,5,8,11,76,23,56,21,81,3,90,34,21,59,0};
	int choise;
	bool flag = false;
	cout << "Массив А: ";
	PrintArray(A, size);
	cout << "Массив B: ";
	PrintArray(B, size2);
	do
	{
		cout << "Выберите действие" << endl
			<< "1 - Найти max" << endl
			<< "2 - Найти min" << endl
			<< "3 - Найти avg" << endl
			<< "4 - Выход" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			pAction = MaxArray;
			cout << "Массив А :" << Action(A, size, pAction);
			cout << endl;
			cout << "Массив B :" << Action(B, size2, pAction);
			system("pause");
			system("cls");
			break;

		case 2:
			pAction = MinArray;
			cout <<"Массив А :"<< Action(A, size, pAction);
			cout << endl;
			cout << "Массив B :" << Action(B, size2, pAction);
			system("pause");
			system("cls");
			break;

		case 3:
			pAction = AveregArray;
			cout <<"Массив А :"<< Action(A, size, pAction);
			cout << endl;
			cout << "Массив B :" << Action(B, size2, pAction);
			system("pause");
			system("cls");
			break;
		case 4:
			flag = true;
			break;
		default:
			cout << "Такого действия нет! " << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (!flag);	
}