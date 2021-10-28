#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int check();
void showArray(int*, int);
void searchForMinMax(int*, int);
void sortToMax(int*, int);
void sortToMin(int*, int);
void deleteEvenNum(int*, int);
void deleteRecurringNum(int*,int);
void findMax(int*, int);
void countNumRepeat(int*, int);
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(NULL));
	cout << " ����� ������ �� ������ �������?" << endl << "1) �����������  2) ������������" << endl;
	const int type = check();
	if (type == 1)
	{
		int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < 10; i++)
		{
			cout << " ������� " << (i + 1) << "-� ������� �������." << endl;
			arr[i] = check();
		}
		cout << " ��� ������: " << endl;
		showArray(arr, 10);
		searchForMinMax(arr, 10);
		sortToMax(arr, 10);
		sortToMin(arr, 10);
		deleteEvenNum(arr, 10);
		findMax(arr, 10);
		deleteRecurringNum(arr, 10);
		countNumRepeat(arr, 10);
	}
	else
	{
		cout << " ������� ������ �������." << endl;
		int n = check();
		while (n < 1)
		{
			cout << " ������ ������� ������ ���� ������ 0." << endl;
			n = check();
		}
		int* arr = new int[n];
		cout << " ������� ����������� �����" << endl;
		int a = check();
		cout << " ������� ������������ �����" << endl;
		int b = check();
		cout << " ��� ��������� �������..." << endl;
		for (int i = 0; i <= (n - 1); i++) arr[i] = rand() % (b - a + 1) + a;
		showArray(arr, n);
		searchForMinMax(arr, n);
		sortToMax(arr, n);
		sortToMin(arr, n);
		deleteEvenNum(arr, n);
		findMax(arr, n);
		deleteRecurringNum(arr, n);
		countNumRepeat(arr, n);
		cout << endl << "����������� ������" << endl;
		showArray(arr, n);
		delete[]arr;
	}
}
int check()
{
	while (true)
	{
		int z;
		cin >> z;
		if (std::cin.fail() == 1)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			std::cout << " �� ����� ������������ �����, ���������� ��� ���." << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			return z;
		}
	}
}
void showArray(int* arr,int n)
{
	for (int i = 0; i < n; i++)	cout << arr[i] << " ";
	cout << endl << endl;
}
void searchForMinMax(int* arr, int n)
{
	cout << " ����� ����������� � ����������� ��������� �������..." << endl;
	int max = arr[0], min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	cout << " �������� ������������ �������� ������� = " << min << endl << " �������� ������������� �������� ������� = " << max << endl << endl;
}
void sortToMax(int* arr, int n) 
{
	cout << " ���������� ������� �� �����������..." << endl;
	int* backup = new int[n];
	for (int i = 0; i < n; i++)
	{
		backup[i] = arr[i];
	}
	for (int i = 0; i < (n-1); i++)
	{
		for (int k = (i + 1); k < n; k++)
		{
			if (arr[k] < arr[i])
			{
				swap(arr[k], arr[i]);
			}
		}
	}
	showArray(arr, n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = backup[i];
	}
	delete[]backup;
}
void sortToMin(int* arr, int n)
{
	cout << " ���������� ������� �� ��������..." << endl;
	int* backup = new int[n];
	for (int i = 0; i < n; i++) backup[i] = arr[i];
	for (int i = 0; i < (n - 1); i++)
	{
		for (int k = (i + 1); k < n; k++)
		{
			if (arr[k] > arr[i])
			{
				swap(arr[k], arr[i]);
			}
		}
	}
	showArray(arr, n);
	for (int i = 0; i < n; i++) arr[i] = backup[i];
	delete[]backup;
}
void deleteEvenNum(int*arr, int n)
{
	cout << " �������� ������ ��������� �� �������..." << endl;
	int* backup = new int[n];
	int backup_n = n;
	for (int i = 0; i < n; i++) backup[i] = arr[i];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			if (arr[i] % 2 == 0)
			{
				for (int k = i; k < (n - 1); k++)
				{
					swap(arr[k], arr[(k + 1)]);
				}
				n--;
				i--;
			}
		}
	}
	showArray(arr, n);
	for (int i = 0; i < backup_n; i++) arr[i] = backup[i];
	delete[]backup;
}
void findMax(int* arr, int n)
{
	int min = arr[0], max_first = arr[0], max_second = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
    max_first = max_second = min;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max_first)
		{
			max_second = max_first;
			max_first = arr[i];
		}
		else
		{
			if ((arr[i]>max_second)&&(arr[i]<max_first)) max_second = arr[i];
		}
	}
	cout << " ������ �������� ������� = " << max_first << endl << " ������ �������� ������� = " << max_second << endl << endl;
}
void deleteRecurringNum(int*arr, int n)
{
	cout << " �������� ������������� ��������� �� �������..." << endl;
	int* backup = new int[n];
	int backup_n = n;
	for (int i = 0; i < n; i++) backup[i] = arr[i];
	for (int i = 0; i < (n-1); i++)
	{
		for (int k = (i+1); k < n; k++)
		{
			if (arr[i] == arr[k])
			{
				for (int p = (k + 1); p < n; p++)
				{
					int bufer = arr[p];
					arr[p] = arr[p - 1];
					arr[(p - 1)] = bufer;
				}
				
					n--;
					k--;
			}
		}
		
	}
	showArray(arr, n);
	for (int i = 0; i < backup_n; i++) arr[i] = backup[i];
	delete[]backup;
}
void countNumRepeat(int* arr, int n)
{
	int* backup = new int[n];
	int backup_n = n;
	for (int i = 0; i < n; i++) backup[i] = arr[i];
	int mostrepeat = 0, max = 0;
	for (int i = 0, total_max = 1; i < (n - 1); i++)
	{
		int total = 1;
		for (int k = (i + 1); k < n; k++)
		{
			if (arr[i] == arr[k])
			{
				for (int p = (k + 1); p < n; p++)
				{
					int bufer = arr[p];
					arr[p] = arr[p - 1];
					arr[(p - 1)] = bufer;
				}
				total++;
				n--;
				k--;
			}
		}
		cout << " ����� " << arr[i] << " ����������� � ������� " << total << " ���(�)." << endl;
		if (total > total_max)
		{
			mostrepeat = arr[i];
			total_max = total;
			max = total_max;
		}
	}
	cout << endl << endl;
	cout << " ����� " << mostrepeat << " ����� ��������������� ����� � �������. ��� ����������� " << max << " ���(�)." << endl;
	for (int i = 0; i < backup_n; i++) arr[i] = backup[i];
	delete[]backup;
}
