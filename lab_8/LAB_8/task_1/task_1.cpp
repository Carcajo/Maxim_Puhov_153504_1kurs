/*Лабораторная работа №8, задание 1, вариант 5. Выполнил Пухов М.Ю.

На междугородной АТС информация о разговорах содержит
дату разговора, код и название города, время разговора, тариф, номер
телефона абонента.Вывести для заданного города общее время разговоров с ним
и сумму(сортировка обменом по убыванию).*/


#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;

struct converstation {
	char date[100];
	char code[100];
	char city[100];
	double duration;
	double rate;
	char number[100];
	double cost;
};

bool isDigit(char a)
{
	if (a >= '0' && a <= '9')
		return true;
	return false;
}

void read(int& a)
{
	while (true)
	{
		cin >> a;
		if (cin.fail() || cin.peek() != '\n')
		{
			cout << "Еще раз: ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			break;
	}
}

void read(double& a)
{
	while (true)
	{
		cin >> a;
		if (cin.fail() || cin.peek() != '\n')
		{
			printf ("Еще раз: ");
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			break;
	}
}

bool checkDate(char date[100])
{
	int a = (date[0] - '0') * 10 + (date[1] - '0');
	if (a < 1 || a > 31)
		return false;
	a = (date[3] - '0') * 10 + (date[4] - '0');
	if (a < 1 || a > 12)
		return false;
	a = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	if (a < 1 || a > 2021)
		return false;
	return true;
}

void readDate(char* date)
{
	while (true)
	{
		cin>>date;
		if (strlen(date) == 10 &&
			isDigit(date[0]) && isDigit(date[1]) && date[2] == '.' &&
			isDigit(date[3]) && isDigit(date[4]) && date[5] == '.' &&
			isDigit(date[6]) && isDigit(date[7]) && isDigit(date[8]) && isDigit(date[9]) && checkDate(date))
			break;
	    printf("Еще раз: ");
	}
}

void readCode(char* code)
{
	while (true)
	{
		cin >> code;
		if (strlen(code) == 5 &&
			isDigit(code[0]) && code[1] == '-' &&
			isDigit(code[2]) && isDigit(code[3]) && isDigit(code[4]))
			break;
		printf("Еще раз: ");
	}
}

void readNumber(char* number)
{
	while (true)
	{
		cin >> number;
		if (strlen(number) == 7)
		{
			bool p = 1;
			for (int i = 0; i < 7; i++)
				if (!isDigit(number[i]))
				{
					p = 0;
					break;
				}
			if (p)
				break;
		}
		printf("Еще раз: ");
	}
}

void read(converstation& a)
{
	printf( "Введите дату разговора: ");
	readDate(a.date);
	printf( "Введите код города: ");
	readCode(a.code);
	printf( "Введите название города: ");
	cin >> a.city;
	OemToCharA(a.city, a.city);
	printf( "Введите время разговора (мин): ");
	read(a.duration);
	printf("Введите тариф разговора (руб): ");
	read(a.rate);
	printf("Введите номер телефона абонента: ");
	readNumber(a.number);
	a.cost = a.rate * a.duration;
}

bool equal(char* a, char* b)
{
	int size = strlen(a);
	for (int i = 0; i < size; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

int find(converstation*& arr, int& size)
{
	system("cls");
	printf( "\n\n\n"
		 "\t\t\t\t\tНажмите\n"
		 "\t\t\t1 - Поиск по дате\n"
		 "\t\t\t2 - Поиск по коду\n"
		 "\t\t\t3 - Поиск по городу\n"
		 "\t\t\t4 - Поиск по времени разговора\n"
		 "\t\t\t5 - Поиск по тарифу\n"
		 "\t\t\t6 - Поиск по номеру\n"
		 "\t\t\tИначе - Поиск по стоимости\n");
	char a = _getch();
	char l1[100];
	double l2 = 0;
	if (a == '1')
		readDate(l1);
	else
		if (a == '2')
			readCode(l1);
		else
			if (a == '3')
			{
				cin >> l1;
				OemToCharA(l1, l1);
			}
			else
				if (a == '6')
					readNumber(l1);
				else
					read(l2);
	for (int i = 0; i < size; i++)
	{
		if ((a == '1' && equal(arr[i].date, l1)) ||
			(a == '2' && equal(arr[i].code, l1)) ||
			(a == '3' && equal(arr[i].city, l1)) ||
			(a == '4' && arr[i].duration == l2) ||
			(a == '5' && arr[i].rate == l2) ||
			(a == '6' && equal(arr[i].number, l1)) ||
			((a < '1' && a > '6') && arr[i].cost == l2))
		{
			printf("Найдена структура под номером %d", i + 1); cout << endl;
			return i;
		}
	}
	printf("Структура с таким значением не обнаружена, попробуйте еще раз\n");
	printf("Нажмите любую клавишу\n");
	_getch();
	return find(arr, size);
}

void remove(converstation*& arr, int i, int& size)
{
	if (size == 1)
	{
		arr = 0;
		return;
	}
	if (size <= i)
	{
		printf( "Ошибка, такой сруктуры нет\n");
		return;
	}
	converstation* newArr = new converstation[size - 1];
	int j;
	for (j = 0; j < i; j++)
		newArr[j] = arr[j];
	j++;
	for (j; j < size; j++)
		newArr[j - 1] = arr[j];
	delete[] arr;
	arr = newArr;
	size--;
}

void change(converstation*& arr, int& size)
{
	int i = find(arr, size);
	system("cls");
	printf( "\n\n\n"
		 "\t\t\t\t\tНажмите\n"
		 "\t\t\t1 - Для изменения структуры\n"
		 "\t\t\tИначе - Удаление структуры\n");
	char a = _getch();
	if (a != '1')
		remove(arr, i, size);
	else
	{
		system("cls");
		printf( "\n\n\n"
			 "\t\t\t\t\tНажмите\n"
			 "\t\t\t1 - Изменение даты\n"
			 "\t\t\t2 - Изменение кода\n"
			 "\t\t\t3 - Изменение города\n"
			 "\t\t\t4 - Изменение времени разговора\n"
			 "\t\t\t5 - Изменение тарифа\n"
			 "\t\t\tИначе - Изменение номера\n");
		a = _getch();
		printf( "Старое значение: ");
		if (a == '1')
			cout << arr[i].date << endl;
		else
			if (a == '2')
				cout << arr[i].code << endl;
			else
				if (a == '3')
					cout << arr[i].city << endl;
				else
					if (a == '4')
						cout << arr[i].duration << endl;
					else
						if (a == '5')
							cout << arr[i].rate << endl;
						else
							cout << arr[i].number << endl;
		char l1[100];
		double l2 = 0;
		printf( "Новое значение: ");
		if (a == '1')
			readDate(l1);
		else
			if (a == '2')
				readCode(l1);
			else
				if (a == '3')
				{
					cin >> l1;
					OemToCharA(l1, l1);
				}
				else
					if (a == '6')
						readNumber(l1);
					else
						read(l2);
		arr[i].cost = arr[i].rate * arr[i].duration;
	}
}

void add(converstation*& arr, int& size)
{
	converstation* newArr = new converstation[size + 1];
	read(newArr[size]);
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];
	size++;
	delete[]arr;
	arr = newArr;
}

void formating(converstation*& arr, int& size)
{
	system("cls");
	printf( "\n\n\n"
		 "\t\t\t\t\tНажмите\n"
		 "\t\t\t1 - Ввод определенного количества структур\n"
		 "\t\t\t2 - Ввод до появления структуры с определенным признаком\n"
		"\t\t\tИначе - Спрашивать после каждой структуры\n");
	char a = _getch();
	if (a == '1')
	{
		do
		{
			printf( "Введите количество: ");
			read(size);
		} while (size < 1);
		arr = new converstation[size];
		for (int i = 0; i < size; i++)
		{
			printf("Введите структуру %d ", i + 1); cout << endl;
			read(arr[i]);
		}
	}
	else
		if (a == '2')
		{
			system("cls");
			printf( "\n\n\n"
				 "\t\t\t\t\tНажмите\n"
				 "\t\t\t1 - Ввод по дате\n"
				 "\t\t\t2 - Ввод по коду\n"
				 "\t\t\t3 - Ввод по городу\n"
				 "\t\t\t4 - Ввод по времени разговора\n"
				 "\t\t\t5 - Ввод по тарифу\n"
				 "\t\t\t6 - Ввод по номеру\n"
				 "\t\t\tИначе - Ввод по стоимости\n");
			a = _getch();
			char l1[100];
			double l2 = 0;
			if (a == '1')
				readDate(l1);
			else
				if (a == '2')
					readCode(l1);
				else
					if (a == '3')
					{
						cin >> l1;
						OemToCharA(l1, l1);
					}
					else
						if (a == '6')
							readNumber(l1);
						else
							read(l2);
			int i = 0;
			while (true)
			{
				add(arr, size);
				if ((a == '1' && arr[i].date == l1) ||
					(a == '2' && arr[i].code == l1) ||
					(a == '3' && arr[i].city == l1) ||
					(a == '4' && arr[i].duration == l2) ||
					(a == '5' && arr[i].rate == l2) ||
					(a == '6' && arr[i].number == l1) ||
					((a < '1' && a > '6') && arr[i].cost == l2))
				{
					printf("Встречено поле с заданным значением, конец ввода\n");
					break;
				}
			}
		}
		else
		{
			while (true)
			{
				add(arr, size);
				do
				{
					printf( "Желаете продолжить?(y/n)\n");
					a = _getch();
				} while (a != 'n' && a != 'y');
				if (a == 'n')
					break;
			}
		}
}

void printStruct(converstation a)
{
	printf("Дата разговора: ");
	cout << a.date;
	printf( "\nКод города: ");
	cout << a.code;
	printf( "\nНазвание города: ");
	cout << a.city;
	printf("\nВремя разговора: ");
	cout << a.duration;
	printf( "\nТариф: ");
	cout << a.rate;
	printf( "\nНомер: ");
	cout << a.number;
	printf("\nСтоимость разговора: ");
	cout << a.cost << endl;
}

void print(converstation* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Структура %d ", i + 1); cout << ":\n";
		printStruct(arr[i]);
	}
}

bool check(double a, double b)
{
	return (a > b);
}

bool check(char* a, char* b)
{
	int size = min(strlen(a), strlen(b));
	for (int i = 0; i < size; i++)
	{
		if (a[i] > b[i])
			return true;
		if (a[i] < b[i])
			return false;
	}
	if (strlen(a) > strlen(b))
		return true;
	return false;
}

bool checkDate(char* a, char* b)
{
	int ca = (a[6] - '0') * 1000 + (a[7] - '0') * 100 + (a[8] - '0') * 10 + (a[9] - '0');
	int cb = (b[6] - '0') * 1000 + (b[7] - '0') * 100 + (b[8] - '0') * 10 + (b[9] - '0');
	if (ca > cb)
		return true;
	if (ca < cb)
		return false;
	ca = (a[3] - '0') * 10 + (a[4] - '0');
	cb = (b[3] - '0') * 10 + (b[4] - '0');
	if (ca > cb)
		return true;
	if (ca < cb)
		return false;
	ca = (a[1] - '0') * 10 + (a[0] - '0');
	cb = (b[1] - '0') * 10 + (b[0] - '0');
	if (ca > cb)
		return true;
	return false;
}

bool check(char t, converstation a, converstation b)
{
	if (t == '1')
		return checkDate(a.date, b.date);
	if (t == '2')
		return check(a.code, b.code);
	if (t == '3')
		return check(a.city, b.city);
	if (t == '4')
		return check(a.duration, b.duration);
	if (t == '5')
		return check(a.rate, b.rate);
	if (t == '6')
		return check(a.number, b.number);
	return check(a.cost, b.cost);
}

void swap(double& a, double& b)
{
	double c = a;
	a = b;
	b = c;
}

void swap(char* a, char* b)
{
	char c;
	for (int i = 0; i < 100; i++)
	{
		c = a[i];
		a[i] = b[i];
		b[i] = c;
	}
}

void swap(converstation& a, converstation& b)
{
	swap(a.date, b.date);
	swap(a.code, b.code);
	swap(a.city, b.city);
	swap(a.duration, b.duration);
	swap(a.rate, b.rate);
	swap(a.number, b.number);
	swap(a.cost, b.cost);
}

void sort(converstation*& arr, int size)
{
	system("cls");
	printf( "\n\n\n"
		 "\t\t\t\t\tНажмите\n"
		 "\t\t\t1 - Сортировка по дате\n"
		 "\t\t\t2 - Сортировка по коду\n"
		 "\t\t\t3 - Сортировка по городу\n"
		 "\t\t\t4 - Сортировка по времени разговора\n"
		 "\t\t\t5 - Сортировка по тарифу\n"
		 "\t\t\t6 - Сортировка по номеру\n"
		 "\t\t\tИначе - Сортировка по стоимости\n");
	char a = _getch();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
			if (check(a, arr[i], arr[j]))
				swap(arr[i], arr[j]);
	}
	printf("Сортировка выполнена\n");
	print(arr, size);
}

int main()
{
	cout.precision(3);
	cout << fixed;
	int size = 0;
	converstation* arr = 0;
	bool formated = 0;
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		system("cls");
		printf( "\n\n\n"
			 "\t\t\t\t\tНажмите\n"
			 "\t\t\t1 - Формирование\n"
			 "\t\t\t2 - Просмотр\n"
			 "\t\t\t3 - Дополнение\n"
			 "\t\t\t4 - Поиск\n"
			 "\t\t\t5 - Коррекция\n"
			 "\t\t\t6 - Сортировка\n"
			 "\t\t\tИначе - закрыть приложение\n");
		switch (_getch())
		{
		case '1':
			if (formated)
				printf( "Массив уже сформирован\n");
			else
			{
				formating(arr, size);
				formated = 1;
			}
			break;
		case '2':
			if (!formated)
				printf( "Массив не сформирован\n");
			else
				print(arr, size);
			break;
		case '3':
			if (!formated)
				printf( "Массив не сформирован\n");
			else
			{
				while (true)
				{
					add(arr, size);
					char a;
					do
					{
						printf("Желаете добавить еще структуры?(y/n)");
						a = _getch();
					} while (a != 'y' && a != 'n');
					if (a == 'n')
						break;
				}
			}
			break;
		case '4':
			if (!formated)
				printf("Массив не сформирован\n");
			else
				printStruct(arr[find(arr, size)]);
			break;
		case '5':
			if (!formated)
				printf( "Массив не сформирован\n");
			change(arr, size);
			break;
		case '6':
			if (!formated)
				printf( "Массив не сформирован\n");
			sort(arr, size);
			break;
		default:
			return 0;
		}
		printf("Нажмите любую клавишу");
		_getch();
	}
	delete[] arr;
}
