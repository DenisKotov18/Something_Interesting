#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double a;
	int b;
	cout << " ������� ����� " << endl;
	cin >> a;
	b = a;
	if (a - b == 0) cout << "����� �����";
	else cout << " ����� ������������";
}