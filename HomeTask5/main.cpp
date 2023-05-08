#include <iostream>
#include <string>

using namespace std;

//�������� ���������, ������� �������� ������� Action, ����������� � �������� ���������,
//��������� �� ��� �������(� � �) � ������� ��������, � ����� ��������� �� �������.
//������������ ������������ ����, � ������� �� ����� ������� max, min, avg.���� ������ max
//- ���������� ��������� �� �������, ������� ���� ��������,
//���� ������ min - ���������� ��������� �� �������, ������� ���� �������, ���� ������ avg -
//���������� ��������� �� �������, ������� ���� �������.
//������������ �������� ������� Action ��������� ������ ������������ max, min, avg.

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
	cout << "������ �: ";
	PrintArray(A, size);
	cout << "������ B: ";
	PrintArray(B, size2);
	do
	{
		cout << "�������� ��������" << endl
			<< "1 - ����� max" << endl
			<< "2 - ����� min" << endl
			<< "3 - ����� avg" << endl
			<< "4 - �����" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			pAction = MaxArray;
			cout << "������ � :" << Action(A, size, pAction);
			cout << endl;
			cout << "������ B :" << Action(B, size2, pAction);
			system("pause");
			system("cls");
			break;

		case 2:
			pAction = MinArray;
			cout <<"������ � :"<< Action(A, size, pAction);
			cout << endl;
			cout << "������ B :" << Action(B, size2, pAction);
			system("pause");
			system("cls");
			break;

		case 3:
			pAction = AveregArray;
			cout <<"������ � :"<< Action(A, size, pAction);
			cout << endl;
			cout << "������ B :" << Action(B, size2, pAction);
			system("pause");
			system("cls");
			break;
		case 4:
			flag = true;
			break;
		default:
			cout << "������ �������� ���! " << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (!flag);	
}