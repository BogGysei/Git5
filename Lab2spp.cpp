#include <iostream>
using namespace std;
int value;
int foo2(int n) {
	if (n == 0)
	{
		value = 0;
	}
	else if (n == 1)
	{
		value = 1;
	}
	else {
		value = 2*(n * foo2(n - 1));
	}
	return value;
}
int foo1(int n, int* result) {
	if (n == 0) {
		*result = 0;
	}
	else if (n == 1) {
		*result = 1;
	}
	else {
		*result = n * foo1(n - 1, result) + n;
	}
	return *result;
}

int main() {
	int result;
	int n1;
	cin >> n1;
	foo1(n1, &result);
	cout << result << '\n';
	cout << "-----------------------------------------------" << '\n';
	int n2;
	cin >> n2;
	foo2(n2);
	cout << value;
}