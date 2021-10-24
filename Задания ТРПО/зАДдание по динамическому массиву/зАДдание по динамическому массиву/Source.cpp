#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
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
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(NULL));
	cout << " ����� ������ �� ������ �������?" << endl << "1) �����������  2) ������������" << endl;
	const int type = check();
	if (type == 1)
	{
		int arr[10] = {0,0,0,0,0,0,0,0,0,0};
		for (int i = 0; i < 10; i++)
		{
			cout << " ������� " << (i+1) << "-� ������� �������." << endl;
			arr[i] = check();
		}
		int backup[10];
		for (int i = 0; i < 10; i++) backup[i] = arr[i];
		int max = arr[0];
		int min = arr[0];
		for (int i = 1; i < 10; i++)
		{
			if (arr[i] > max) max = arr[i];
			if (arr[i] < min) min = arr[i];
		}
		cout << " �������� ������������ �������� ������� = " << min << endl << " �������� ������������� �������� ������� = " << max << endl << endl;
		cout << " ���������� ������� �� �����������..." << endl;
		for (int i = 0; i < 9; i++)
		{
			for (int k = (i + 1); k < 10; k++)
			{
				if (arr[k] < arr[i])
				{
					swap(arr[k], arr[i]);
				}
			}
			cout << arr[i] <<" ";
		}
		cout << arr[9] << endl << endl;
		cout << " ���������� ������� �� ��������..." << endl;
		for (int k = 9, i = 0; i < 5; i++)
		{
			swap(arr[i], arr[k]);
			k--;
		}
		for (int i = 0; i < 10; i++) cout << arr[i]<<" ";
		cout << endl << endl;
		cout << " �������� ������ ��������� �� �������..." << endl;
		int n = 10;
		for (int i = 0; i < n; i++)
		{
			if (backup[i] % 2 == 0)
			{
				for (int k = i; k < (n-1); k++)
				{
						swap(backup[k], backup[(k+1)]);
				}
				n--;
				i--;
			}
		}
		for (int i = 0; i < n; i++) cout << backup[i] << " ";
		cout << endl << endl;
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
		for (int i = 0; i <= (n - 1); i++)
		{
			arr[i] = rand() % (b - a + 1) + a;
			cout << arr[i] << " ";
		}
		cout << endl << endl;
		int *backup = new int[n];
		for (int i = 0; i < n; i++) backup[i] = arr[i];
		int max = arr[0];
		int min = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (arr[i] > max) max = arr[i];
			if (arr[i] < min) min = arr[i];
		}
		cout << " �������� ������������ �������� ������� = " << min << endl << " �������� ������������� �������� ������� = " << max << endl << endl;
		cout << " ���������� ������� �� �����������..." << endl;
		for (int i = 0; i < (n-1); i++)
		{
			for (int k = (i + 1); k < n; k++)
			{
				if (arr[k] < arr[i])
				{
					swap(arr[k], arr[i]);
				}
			}
			cout << arr[i] <<" ";
		}
		cout << arr[(n-1)] << endl << endl;
		cout << " ���������� ������� �� ��������..." << endl;
		for (int i = 0; i < (n - 1); i++)
		{
			for (int k = (i + 1); k < n; k++)
			{
				if (arr[k] > arr[i])
				{
					swap(arr[k], arr[i]);
				}
			}
			cout << arr[i] << " ";
		}
		cout << arr[(n - 1)] << endl << endl;
		cout << " �������� ������ ��������� �� �������..." << endl;
		int num = n;
		for (int i = 0; i < num; i++)
		{
			if (backup[i] % 2 == 0)
			{
				for (int k = i; k < (num-1); k++)
				{
						swap(backup[k], backup[(k+1)]);
				}
				num--;
				i--;
			}
		}
		for (int i = 0; i < num; i++) cout << backup[i] << " ";
		cout << endl << endl;
		delete[]backup;
		delete[]arr;
	}
}