#include <iostream>
using namespace std;
int main() {
	int h;
	cout << "Введіть висоту піраміди: ";
	cin >> h;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < h - i - 1; ++j) {
			cout << " ";
		}
		for (int j = 0; j < i + 1; ++j) {
			cout << "*";
		}
		for (int j = 0; j < i; ++j) {
			cout << j;
		}
		cout << '\n';
	}
}
