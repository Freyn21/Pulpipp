#include <cmath>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

double fibonacci(double num)
{
	if (num < 0)
	{
		wcout << L"Невозможно использовать Фибоначчи, если изначальное число меньше 0";
		return num;
	}
	if (num == 0)
	{
		return 0;
	}
	if (num == 1)
	{
		return 1;
	}
	return (fibonacci(num - 1) + fibonacci(num - 2));
}

double factorial(double num)
{
	if (num <= 0)
	{
		wcout << L"Невозможно найти факториал отрицательного числа или 0";
		return num;
	}
	if (num == 1)
	{
		return 1;
	}
	return (num * factorial(num-1));
}

double group1(double num) //первая группа операций (+ - / *)
{
	int ans; //
	double num2; // число измены
	wcout << L"Какую операцию вы хотите произвести?\n1 - Прибавить число к нынешнему числу\n2 - Вычесть из нынешнего числа другое число\n3 - Умножить нынешнее число на другое число\n4 - Поделить нынешнее число на другое число\nВведите номер нужной операции: ";
	cin >> ans;
	std::system("cls");
	if (ans > 4 || ans < 1)
	{
		wcout << L"Операции с таким номером не существует\n";
		return group1(num);
	}
	switch (ans)
	{
	case 1:
		wcout << L"Введите число, которое хотите прибавить: ";
		cin >> num2;
		return (num + num2);
	case 2:
		wcout << L"Введите число, которое хотите вычесть: ";
		cin >> num2;
		return (num - num2);
	case 3:
		wcout << L"Введите число, на которое хотите умножить: ";
		cin >> num2;
		return (num * num2);
	case 4:
		wcout << L"Введите делитель: ";
		cin >> num2;
		if (num2 == 0)
		{
			wcout << L"На 0 делить нельзя";
			return num;
		}
		return (num / num2);
	}
	return 0;
}

double group2(double num) // вторая группа операций (тригонометрия)
{
	int ans;
	wcout << L"Какую операцию хотите произвести?\n1 - Найти синус от нынешнего числа\n2 - Найти косинус от ныншнего числа\n3 - Найти тангенс от ныншнего числа\n4 - Найти котангенс от ныншнего числа\nВведите номер нужной операции: ";
	cin >> ans;
	std::system("cls");
	if (ans > 4 || ans < 1)
	{
		wcout << L"Операции с таким номером не существует\n";
		return group2(num);
	}
	switch (ans)
	{
	case 1:
		return sin(num);
	case 2:
		return cos(num);
	case 3:
		return tan(num);
	case 4:
		return (1 / tan(num));
	}
	return 0;
}

double group3(double num) // третья группа операций (фибоначчи, факториал и логарифм)
{
	int ans;
	wcout << L"Какую операцию хотите произвести?\n1 - Найти число Фибоначчи из ныншнего числа\n2 - Найти факториал нынешнего числа\n3 - Найти логарифм нынешнего числа\nВведите номер нужной операции: ";
	cin >> ans;
	std::system("cls");
	if (ans > 3 || ans < 1)
	{
		wcout << L"Операции с таким номером не существует\n";
		return group3(num);
	}
	switch (ans)
	{
	case 1:
		return fibonacci(num);
	case 2:
		return factorial(num);
	case 3:
		if (num <= 0)
		{
			wcout << L"Число в логарифме не может быть меньше или равно 0";
			return num;
		}
		else
		{
			double log_base;
			wcout << L"Введите основание логарифма: ";
			cin >> log_base;
			if (log_base == 1 || log_base <= 0)
			{
				wcout << L"Основание логарифма не может быть отрицательным или 1";
				return num;
			}
			return (log(num) / log(log_base));
		}
	}

}

int main()
{
	SetConsoleOutputCP(CP_UTF8); //включение кириллицы
	setlocale(LC_ALL, "Russian_Russia.1251");
	bool finishing = 0; //захотел ли пользователь закончить
	bool dolg = 0; //ввел ли пользователь легитимный номер группы операций или еще нет
	string fin; //ответ пользователя на продолжение или конец проги
	int lap = 0; //количество повторений проги
	int ans; //выбор пользователя
	double num, pr_num; //нынешнее и предыдущее число соответственно

	while (finishing == 0) //проверка на окончание проги
	{
		if (lap == 0 && dolg==0)
		{
			wcout << L"Добро пожаловать в CalcuPrime Deluxe!\n";
			wcout << L"Введите стартовое число: "; //вступление и запрос начального числа
			cin >> num;
		}
		dolg = 0;
		wcout << L"Сейчас ваше число равно ";
		cout << num << endl; //выбор пользователем группы операций
		wcout << L"Что хотите сделать дальше?\n0 - сменить нынешнее число на другое\n1 - Обычные математические операции (+ - * /)\n2 - Тригонометрические операции (sin, cos, tg, ctg)\n3 - Специфические операции (Фибоначчи, факториал, логарифм)\n4 - отменить прошлую операцию и вернуть прошлое число\nВведите номер нужного действия: ";
		cin >> ans;
		std::system("cls");
		if (ans > 4 || ans < 0)
		{
			wcout << L"Действия с таким номером не существует\n";
			dolg = 1;
		}
		switch (ans)
		{
		case 0:
			pr_num = num;
			wcout << L"Введите новое число: ";
			cin >> num;
			lap++;
			break;
		case 1:
			pr_num = num;
			num = group1(num);
			lap++;
			break;
		case 2:
			pr_num = num;
			num = group2(num); //выполнение запроса
			lap++;
			break;
		case 3:
			pr_num = num;
			num = group3(num);
			lap++;
			break;
		case 4:
			if (lap == 0)
			{
				wcout << L"Невозможно вернуть прошлое значение числа, так как это ваша первая операция" << endl;
				dolg = 1;
				break;
			}
			num = pr_num;
			lap++;
			break;
		}
		if (dolg == 0)
		{
			wcout << L"\nСейчас ваше число равно ";
			cout << num;
			wcout << L"\nВведите Y или y, если хотите закончить, или любой другой символ, если хотите продолжить: "; //выбор пользователем продолжения или окончания проги
			cin >> fin;
			if (fin == "y" || fin == "Y")
			{
				finishing = 1;
			}
		}
	}
	wcout << L"\nВаше финальное число: ";
	cout << num;
	wcout << L"\nБыло произведено операций: "; //итог
	cout << lap << endl;
	system("pause");
	return 0;
}