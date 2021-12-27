#include <iostream>
#include <fstream>
#include <io.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
using namespace std;

const char* fName = "data.dat";
const char* rName = "result.txt";

struct flight {
	char number[100];
	char type[100];
	char destination[100];
	char time[100];
};

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

bool isDigit(char a)
{
	if (a >= '0' && a <= '9')
		return true;
	return false;
}

bool time(char* a, int& c, int& m)
{
	c = 0; m = 0;
	if (strlen(a) != 5)
		return false;
	if (!isdigit(a[0]) ||
		!isDigit(a[1]) ||
		a[2] != ':' ||
		!isDigit(a[3]) ||
		!isDigit(a[4]))
		return false;
	c = (a[0] - '0') * 10 + (a[1] - '0');
	m = (a[3] - '0') * 10 + (a[4] - '0');
	return true;
}

bool checkTime(char* a)
{
	int c, m;
	if (!time(a, c, m))
		return false;
	if (c > 24 || m > 60)
		return false;
	return true;
}

void read(flight& a)
{
	printf( "Введите номер рейса: ");
	cin >> a.number;
	printf("Введите тип самолета: ");
	cin >> a.type;
	printf( "Введите пункт назначения: ");
	cin >> a.destination;
	OemToCharA(a.destination, a.destination);
	do
	{
		printf( "Введите время вылета: ");
		cin >> a.time;
	} while (!checkTime(a.time));
}

bool open()
{
	ofstream fout(fName, ios::binary | ios::app);
	if (!fout.is_open())
	{
		printf( "Не удалось открыть файл!\n");
		return false;
	}
	printf( "Файл успешно открыт\n");
	fout.close();
	return true;
}

int fileSize(const char* fName) {
	ifstream f;
	f.open(fName, ios_base::binary);
	f.seekg(0, ios_base::end);
	int size = f.tellg();
	f.close();
	return size;
}

void print(flight& a, int i, ostream& sout)
{
	sout << endl << "\t\t\t\t\t" << i + 1 << "-ый рейс" << endl;
	sout << "Номер рейса: " << a.number << endl;
	sout << "Тип самолета: " << a.type << endl;
	sout << "Пункт назначения: " << a.destination << endl;
	sout << "Время вылета: " << a.time << endl;
}

int findNumber()
{
	long len = fileSize(fName);
	int ret = len / sizeof(flight);
	return ret;
}

void printFlights()
{
	system("cls");
	int n = findNumber();
	printf( "В файле содержатся записи %d",  n , " рейсов\n");
	flight* st = (flight*)calloc(n, sizeof(flight));
	ifstream fin(fName, ios::binary);
	fin.read((char*)st, sizeof(flight) * n);
	fin.close();
	for (int i = 0; i < n; i++)
		print(st[i], i, cout);
	delete[] st;
}

void add()
{
	flight newFlight;
	read(newFlight);
	ofstream fout(fName, ios::binary | ios::app);
	fout.write((char*)&newFlight, sizeof(flight));
	fout.close();
}

void editFlight(flight& st)
{
	system("cls");
	printf( "\n\n\n"
		 "\t\t\t\t\tНажмите\n"
		 "\t\t\t1 - Изменить номер рейса\n"
		 "\t\t\t2 - Изменить тип самолета\n"
		 "\t\t\t3 - Изменить пункт назначения\n"
		 "\t\t\tИначе - изменить время вылета\n");
	switch (_getch())
	{
	case '1':
		cout << "Текущий номер рейса: " << st.number << endl;
		printf( "Введите новый номер рейса: ");
		cin >> st.number;
		break;
	case '2':
		cout << "Текущий тип самолета: " << st.type << endl;
		printf("Введите новый тип самолета: ");
		cin >> st.type;
		break;
	case '3':
		cout << "Текущий пункт назначения: " << st.destination << endl;
		printf( "Введите новый пункт назначения: ");
		cin >> st.destination;
		break;
	default:
		cout << "Текущее время вылета: " << st.time << endl;
		do
		{
			printf ("Введите новое время вылета: ");
			cin >> st.time;
		} while (!checkTime(st.time));
		break;
	}
}

void edit(int n)
{
	int cur;
	do
	{
		printf(  "Введите номер рейса для изменения(1- %d", n , "): ");
		read(cur);
	} while (cur < 1 || cur > n);
	cur--;
	flight st;
	ifstream fin(fName, ios::binary);
	fin.seekg(sizeof(flight) * cur);
	fin.read((char*)&st, sizeof(flight));
	fin.close();
	editFlight(st);
	ofstream fout(fName, ios::binary | ios::in | ios::out);
	fout.seekp(sizeof(flight) * cur);
	fout.write((char*)&st, sizeof(flight));
	fout.close();
}

void erase(int n)
{
	int cur;
	do
	{
		printf( "Введите номер рейса для удаления(1-%d" , n , "): ");
		read(cur);
	} while (cur < 1 || cur > n);
	cur--;
	flight* st = (flight*)calloc(n, sizeof(flight));
	ifstream fin(fName, ios::binary);
	fin.read((char*)st, sizeof(flight) * n);
	fin.close();
	ofstream fout(fName, ios::binary | ios::trunc);
	for (int i = 0; i < n; i++)
		if (i != cur)
			fout.write((char*)&st[i], sizeof(flight));
	fout.clear();
	printf ("Запись удалена\n");
	delete[] st;
}

void change()
{
	int n = findNumber();
	system("cls");
	printf( "\n\n\n"
		 "\t\t\t\t\tНажмите\n"
		 "\t\t\t1 - Добавление новых данных\n"
		 "\t\t\t2 - Редактирование старых данных\n"
		 "\t\t\t3 - Удаление данных\n");
	switch (_getch())
	{
	case '1':
		add();
		break;
	case '2':
		if (n == 0)
			printf ("Рейсы отсутствуют\n");
		else
			edit(n);
		break;
	case '3':
		if (n == 0)
			printf( "Рейсы отсутствуют\n");
		else
			erase(n);
		break;
	default:
		printf ("Неизвестная команда\n");
		break;
	}
}

bool check(char* a, char* b)
{
	for (int i = 0; i < min(strlen(a), strlen(b)); i++)
		if (a[i] > b[i])
			return true;
		else
			if (a[i] < b[i])
				return false;
	if (strlen(a) > strlen(b))
		return true;
	else
		return false;
}

bool checkTime(char* a, char* b)
{
	int ca, cb, ma, mb;
	time(a, ca, ma);
	time(b, cb, mb);
	if (ca > cb)
		return true;
	else
		if (ma > mb)
			return true;
	return false;
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

void swap(flight& a, flight& b)
{
	swap(a.number, b.number);
	swap(a.type, b.type);
	swap(a.destination, b.destination);
	swap(a.time, b.time);
}

void sort(char s)
{
	if (s == '0')
	{
		system("cls");
		printf( "\n\n\n"
			 "\t\t\t\t\tНажмите\n"
			 "\t\t\t1 - Отсортировать записи по номеру рейса\n"
			 "\t\t\t2 - Отсортировать записи по типу самолета\n"
			 "\t\t\t3 - Отсортировать записи по пункту назначения\n"
			 "\t\t\tИначе - Отсортировать записи по времени вылета\n");
		s = _getch();
	}
	int n = findNumber();
	flight* st = (flight*)calloc(n, sizeof(flight));
	ifstream fin(fName, ios::binary);
	fin.read((char*)st, sizeof(flight) * n);
	fin.close();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			switch (s)
			{
			case '1':
				if (check(st[i].number, st[j].number))
					swap(st[i], st[j]);
				break;
			case '2':
				if (check(st[i].type, st[j].type))
					swap(st[i], st[j]);
				break;
			case '3':
				if (check(st[i].destination, st[j].destination))
					swap(st[i], st[j]);
				break;
			default:
				if (checkTime(st[i].time, st[j].time))
					swap(st[i], st[j]);
				break;
			}
		}
	}
	ofstream fout(fName, ios::binary | ios::trunc);
	for (int i = 0; i < n; i++)
		fout.write((char*)&st[i], sizeof(flight));
	fout.close();
	printf ("Сортировка выполнена\n");
	delete[] st;
}

bool equal(char* a, char* b)
{
	if (strlen(a) != strlen(b))
		return false;
	int size = strlen(a);
	for (int i = 0; i < size; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

void task()
{
	char d[100];
	system("cls");
	cout << "\t\t\t\t\tЗапись результатов в файл " << rName << endl;
	printf ("Введите пункт назначения: ");
	cin >> d;
	OemToCharA(d, d);
	sort('4');
	int n = findNumber();
	flight* st = (flight*)calloc(n, sizeof(flight));
	ifstream fin(fName, ios::binary);
	fin.read((char*)st, sizeof(flight) * n);
	fin.close();
	ofstream fout(rName, ios::binary | ios::trunc);
	fout << d << ":\n\n";
	bool p = 0;
	for (int i = 0; i < n; i++)
	{
		if (equal(d, st[i].destination))
		{
			print(st[i], i, fout);
			p = 1;
		}
	}
	if (!p)
		fout << "Рейсов в этот пункт не найдено\n";
	fout.close();
}

void clear()
{
	printf( "\n\n\nВы хотите удалить файл со структурами?(y/n)");
	switch (_getch())
	{
	case 'y':
		remove(fName);
		printf("\nФайл удален\n");
		break;
	case 'n':
		printf ("\nФайл не удален\n");
		break;
	default:
		printf ("\nНеизвестная команда\n");
		clear();
		break;
	}
}

bool check()
{
	ifstream file;
	file.open(fName);
	if (!file)
		return false;
	file.close();
	return true;
}

int main()
{
	bool opened = check();
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		system("cls");
		printf( "\n\n\n"
			 "\t\t\t\t\tНажмите\n"
			 "\t\t\t1 - Создание\n"
			 "\t\t\t2 - Просмотр\n"
			 "\t\t\t3 - Коррекция\n"
			 "\t\t\t4 - Сортировка\n"
			 "\t\t\tИначе - Вывести результат в файл\n");
		switch (_getch())
		{
		case '1':
			if (opened)
				printf("Файл уже создан\n");
			else
				if (!(opened = open()))
					return 1;
			break;
		case '2':
			if (!opened)
				printf( "\nФайл не создан\n");
			else
				printFlights();
			break;
		case '3':
			if (!opened)
				printf( "\nФайл не создан\n");
			else
				change();
			break;
		case '4':
			if (!opened)
				printf( "\nФайл не создан\n");
			else
				sort('0');
			break;
		default:
			if (!opened)
				printf( "\nФайл не создан\n");
			else
			{
				task();
				clear();
			}
			return 0;
		}
		printf("Нажмите любую клавишу\n");
		_getch();
	}
}