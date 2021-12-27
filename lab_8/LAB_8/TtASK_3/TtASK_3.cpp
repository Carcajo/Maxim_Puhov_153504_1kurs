//Лабораторная 8, задача 3. Выполнена: Климкович Н. В.

/*Реализовать любой из 30 вариантов (кроме уже реализованных вами)
заданий используя классы. Реализовать корректировку записей внутри файла без
полной перезаписи файла. Все методы класса должны иметь модификатор public,
а остальные поля – private;

Вариант 8: Различные цеха завода выпускают продукцию нескольких
наименований. Сведения о выпущенной продукции включают: наименование,
количество, номер цеха. Для заданного цеха необходимо вывести
количество выпущенных изделий по каждому наименованию в порядке
убывания количества.*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#pragma warning(disable : 4996)
using namespace std;



void clear_m() {
	cin.clear();
	cin.ignore(9999, '\n');
}
void error(int a) {
	clear_m();
	printf("\nВведите корректное значение: ");
	scanf("%d", &a);

}
class Cex {
private:
	char name[100];
	int amount;
	int number;
	int amount_min;
	int amount_max;
public:
	void cout_sss(Cex* ceh, int m) {
		ofstream file;
		file.open("txt.txt");
		file.is_open();
		for (int y = 0; y < m; y++)
			file << ceh[y].name << " , " << ceh[y].amount << " шт.;" << ceh[y].number << '\n';
		file.close();
	}
	void max_s(Cex*& ceh, int m) {
		int buf = ceh[0].amount;
		for (int a = 0; a < m; a++)
			if (buf < ceh[a].amount)
				buf = ceh[a].amount;
		for (int a = 0; a < m; a++) ceh[a].amount_max = buf;
	}
	void min_s(Cex*& ceh, int m) {
		int buf = ceh[0].amount;
		for (int a = 0; a < m; a++)
			if (buf > ceh[a].amount)
				buf = ceh[a].amount;
		for (int a = 0; a < m; a++) ceh[a].amount_min = buf;
	}
	void cout_s(Cex* ceh, int m) {
		min_s(ceh, m);
		max_s(ceh, m);
		printf("\n");
		for (int y = 0; y < m; y++)
			printf("%s, %d шт.; Цех %d\n", ceh[y].name, ceh[y].amount, ceh[y].number);
		cout_sss(ceh, m);
	}
	void shekerSort(Cex* mass, int count) {
		Cex t;
		int left = 0, right = count - 1;
		int flag = 1;
		while ((left < right) && flag > 0)
		{
			flag = 0;
			for (int i = left; i < right; i++)
			{
				if (mass[i].amount < mass[i + 1].amount)
				{
					t = mass[i];
					mass[i] = mass[i + 1];
					mass[i + 1] = t;
					flag = 1;
				}
			}
			right--;
			for (int i = right; i > left; i--)
			{
				if (mass[i - 1].amount < mass[i].amount)
				{
					t = mass[i];
					mass[i] = mass[i - 1];
					mass[i - 1] = t;
					flag = 1;
				}
			}
			left++;
		}
		cout_s(mass, count);
	}
	void cin_s(Cex* ceh, int zero, int m) {
		bool k;
		int p;
		for (int y = zero; y < m + zero;) {
			clear_m();
			printf("\nКоличество продукций, который выпускает цех: ");
			scanf("%d", &p);
			while (cin.fail() || p<1 || p>m) {
				clear_m();
				printf("Введите корректное значение: ");
				scanf("%d", &p);
			}
			for (int x = 0; x < p; x++, y++) {
				clear_m();
				printf("\nНаименование изделия (100 символов): ");
				cin.get(ceh[y].name, 100);
				while (ceh[y].name[0] == '\0') {
					clear_m();
					printf("Введите корректное значение: ");
					cin.get(ceh[y].name, 100);
				}
				clear_m();
				printf("Количество: ");
				scanf("%d", &ceh[y].amount);

				while (cin.fail() || ceh[y].amount < 1) {
					clear_m();
					printf("Введите корректное значение: ");
					scanf("%d", &ceh[y].amount);
				}
				if (x > 0) {
					ceh[y].number = ceh[y - 1].number;
					continue;
				}
				clear_m();
				printf("Номер цеха: ");
				scanf("%d", &ceh[y].number);
				k = 0;
				for (int g = 0; g < y; g++) {
					if (ceh[y].number == ceh[g].number) {
						k++;
						break;
					}
				}
				while (cin.fail() || ceh[y].number < 1 || k) {
					clear_m();
					printf("Введите корректное значение: ");
					scanf("%d", &ceh[y].number);
					k = 0;
					for (int g = 0; g < y; g++) {
						if (ceh[y].number == ceh[g].number) {
							k++;
							break;
						}
					}
				}
			}
		}
		cout_s(ceh, m);
	}
	void dop(Cex*& ceh, int& m) {
		int y = m;
		printf("Сколько продукции добавить (0=назад): ");
		scanf("%d", &y);
		while (cin.fail() || y < 0) {
			clear_m();
			printf("\nВведите корректное значение (0=назад): ");
			scanf("%d", &y);
		}
		if (y == 0) return;
		Cex* buf = new Cex[m];
		for (int u = 0; u < m; u++) {
			buf[u] = ceh[u];
		}
		delete[] ceh;
		ceh = new Cex[m + y];
		for (int u = 0; u < m; u++) {
			ceh[u] = buf[u];
		}
		delete[] buf;
		cin_s(ceh, m, y);
		m += y;
	}
	void delete_s(Cex*& ceh, int& m) {
		int d;
		char da[100];
		bool r = 0;
		clear_m();
		printf("\nНаименование продукции для удаления (0=назад): ");
		cin.get(da, 100);
		while (da[0] == '\0') {
			clear_m();
			printf("Введите корректное значение: ");
			cin.get(da, 100);
		}
		if (da[0] == '0' && da[1] == '\0') {
			return;
		}
		int h;
		for (h = 0; h < m; h++) {
			if (ceh[h].name[0] == da[0]) {
				r = 1;
				d = h;
				break;
			}
		}
		if (!r) {
			printf("В списке нет такой продукции");
			return;
		}
		for (int j = 0; j < 100; j++) {
			if (ceh[h].name[j] == '\0' && da[j] == '\0') break;
			if (ceh[h].name[j] == da[j]) continue;
			else {
				printf("В списке нет такой продукции");
				return;
			}
		}
		for (int u = d; u < m - 1; u++)
			ceh[u] = ceh[u + 1];
		Cex* buf = new Cex[--m];
		for (int u = 0; u < m; u++) {
			buf[u] = ceh[u];
		}
		delete[] ceh;
		ceh = new Cex[m];
		for (int u = 0; u < m; u++) {
			ceh[u] = buf[u];
		}
		delete[] buf;
		cout_s(ceh, m);
	}
	void detail(Cex* ceh1, int m) {
		Cex* ceh = new Cex[m];
		for (int u = 0; u < m; u++) {
			ceh[u] = ceh1[u];
		}
		int d, da;
		bool r = 0;
		clear_m();
		printf("\nЦех (0=назад): ");
		scanf("%d", &da);
		while (cin.fail() || da < 0) {
			clear_m();
			printf("Введите корректное значение: ");
			scanf("%d", &da);
		}
		if (!da) return;
		int h;
		for (h = 0; h < m; h++) {
			if (ceh[h].number == da) {
				r = 1;
				d = h;
				break;
			}
		}
		if (!r) {
			printf("В списке нет такого цеха");
			return;
		}
		double k = 0;
		for (;;) {
			r = 0;
			k += ceh[d].amount;
			for (int u = d; u < m - 1; u++)
				ceh[u] = ceh[u + 1];
			Cex* buf = new Cex[--m];
			for (int u = 0; u < m; u++) {
				buf[u] = ceh[u];
			}
			delete[] ceh;
			ceh = new Cex[m];
			for (int u = 0; u < m; u++) {
				ceh[u] = buf[u];
			}
			delete[] buf;
			for (h = 0; h < m; h++) {
				if (ceh[h].number == da) {
					r = 1;
					d = h;
					break;
				}
			}
			if (!r) {
				delete[] ceh;
				printf("%lf шт.", k);
				return;
			}
		}
	}
	void minn() {
		cout << amount_min;
	}
	void maxx() {
		cout << amount_max;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int m;
	printf("Количество продукции: ");
	scanf("%d", &m);
	while (cin.fail() || m < 1) {
		clear_m();
		printf("\nВведите корректное значение: ");
		scanf("%d", &m);
	}
	Cex* ceh = new Cex[m];
	ceh[0].cin_s(ceh, 0, m);
	for (;;) {
		printf("\n\n		Выберите пункт:"
			"\n		1 - просмотр полного списка"
			"\n		2 - отсортировать список"
			"\n		3 - дополнить список"
			"\n		4 - удаление одного элемента из списка"
			"\n		5 - количество выпущенных изделий определённого цеха"
			"\n		6 - максимальное кол-во"
			"\n		7 - минимальное кол-во"
			"\n		8 - выход\n");
		int l;
		scanf("%d", &l);
		while (cin.fail() || l < 1 || l>8) {
			clear_m();
			printf("\nВведите корректное значение: ");
			scanf("%d", &l);
		}
		switch (l)
		{
		case 1: ceh[0].cout_s(ceh, m); break;
		case 2: ceh[0].shekerSort(ceh, m); break;
		case 3: ceh[0].dop(ceh, m); break;
		case 4: ceh[0].delete_s(ceh, m); break;
		case 5: ceh[0].detail(ceh, m); break;
		case 6: if (!m)break;
			ceh[0].maxx(); break;
		case 7: if (!m) break;
			ceh[0].minn(); break;
		case 8: return 0; break;
		}
	}
}