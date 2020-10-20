#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class Equation {
	double a, b, c;
public:
	Equation();
	void set(double A, double B, double C);
	void getRoot();
};

Equation::Equation() {
	a = 1;
	b = 1;
	c = 0;
}

void Equation::set(double A, double B, double C) {
	a = A;
	b = B;
	c = C;
}

void Equation::getRoot() {
	double delta = b * b - 4 * a * c;
	if (delta == 0)
		cout << "x1=x2=" << fixed << setprecision(2) << -b / (2 * a) << endl;
	else if (delta > 0)
		cout << "x1=" << fixed << setprecision(2) << (-b + sqrt(delta)) / (2 * a) << " x2=" << (-b - sqrt(delta)) / (2 * a) << endl;
	else
		cout << "x1=" << fixed << setprecision(2) << -b / (2 * a) << "+" << sqrt(-delta) / (2 * a) << "i" << " x2=" << -b / (2 * a) << "-" << sqrt(-delta) / (2 * a) << "i" << endl;
}

int main() {
	double t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		Equation x;
		x.set(a, b, c);
		x.getRoot();
	}
	return 0;

}