#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int a;
	cout << "Введи минимальное число" << endl;
	cin >> a;
	cout << "Введи максимальное число" << endl;
	int b;
	cin >> b;
	srand(time(NULL));
	int number_hide;
	number_hide = rand() % (b - a + 1) + a;
	cout << " Якубович, крутите барабан" << endl << "Число загадно!" << endl << " ИГРА НАЧИНАЕТСЯ!" << endl;
	int number = 0;
	int gl;
	gl = 0;
	bool miss = false;
	do
	{
		if (miss == true)
		{
			cout << " Не верно!" << endl;
			if (number > number_hide) cout << " Загаданное число меньше вашего." << endl;
			else cout << "  Загаданное число больше вашего." << endl;
		}
		cin >> number;
		gl++;
		miss = true;
	} while (number != number_hide);
	cout << "Вы победили! С " << gl << " попытки." << endl;
	int sum = 0;
	int number_ost = number_hide;
	do
	{
		sum += number_ost % 10;
		number_ost /= 10;
	} while (number_ost != 0);
	cout << "  Сумма цифр угаданного числа - "<< sum << endl;
	int factorial = 1;
	for (int i = 1; i <= number_hide; i++)
	{
		factorial *= i;
	}
	cout << " Факториал угаданного числа - " << factorial << endl;
	bool trigger = false;
	for (int i = 2; i <= sqrt(number_hide); i++)
	{
		if ((number_hide % i) == 0)
		{
			cout << " Делители угаданного числа - ";
			for (int k = i; k <= (number_hide / 2); k++)
			{
				if ((number_hide % k) == 0) cout << k << " ";
			}
			trigger = true;
			cout << endl;
			break;
		}
	}
	if (trigger == false) cout << " Угаданное число - простое";
}
