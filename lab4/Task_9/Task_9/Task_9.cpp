#include <iostream>

using namespace std;

int main() {


	int n;
	while (true) {
		cout << "Enter N: ";
		cin >> n;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.\n";
			continue;
		}

		if (n <= 0) {
			cout << "Incorrect input. Try again.\n";
			continue;
		}
		else {
			break;
		}

	}

	int m;
	while (true) {
		cout << "Enter M: ";
		cin >> m;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect input. Try again.\n";
			continue;
		}

		if (m <= 0) {
			cout << "Incorrect input. Try again.\n";
			continue;
		}
		else {
			break;
		}
	}

	if (n != m) {
		cout << "Multiplication is impossible!";
		return 0;
	}

	int** array1 = new int* [n];

	for (int i = 0; i < n; i++) {
		array1[i] = new int[n];
	}

	cout << "Matrix1: " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array1[i][j];
		}
		cout << "-----" << endl;
	}

	cout << "\\\\\\\\\\" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << array1[i][j] << "\t";
		}
		cout << endl;
	}


	int** array2 = new int* [m];

	for (int i = 0; i < n; i++) {
		array2[i] = new int[m];
	}

	cout << "Matrix2: " << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> array2[i][j];
		}
		cout << "-----" << endl;
	}

	cout << "\\\\\\\\\\" << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << array2[i][j] << "\t";
		}
		cout << endl;
	}


	int** newArray = new int* [n];
	for (int i = 0; i < n; i++) {
		newArray[i] = new int[n];
		for (int j = 0; j < n; j++) {
			newArray[i][j] = 0;
			for (int k = 0; k < n; k++) {
				newArray[i][j] += array1[i][k] * array2[k][j];
			}
		}
	}

	cout << endl << "New matrix: " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << newArray[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] array1[i];
	}
	delete[] array1;

	for (int i = 0; i < n; i++) {
		delete[] array2[i];
	}
	delete[] array2;

	for (int i = 0; i < n; i++) {
		delete[] newArray[i];
	}
	delete[] newArray;

	return 0;
}