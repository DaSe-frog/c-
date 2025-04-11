#include <iostream>

using namespace std;

double number(string text) { // проверка на то, чтобы введенные данные были числом
	int t = 0;
	double x;
	while (t == 0) {
		cout << "enter " << text << endl;
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Input error. Enter NUMBER" << endl;
		}
		else t = 1;
	}
	return x;
}

int A(int m, int n) {
	if (m == 0) return n + 1;
	else {
		if ((m > 0) && (n == 0)) return A(m - 1, 1);
		else if ((m > 0) && (n > 0)) return A(m - 1, A(m, n - 1));
	}
}

int main() {
	int m = 0, n = 0;
	m = number("m");
	n = number("n");
	if ((m >= 0) && (n >= 0)) cout << "The result: " << A(m, n) << endl;
	else cout << "One of the numbers is negative" << endl; //проверка, чтобы m и n были положительными
	return 0;
}
