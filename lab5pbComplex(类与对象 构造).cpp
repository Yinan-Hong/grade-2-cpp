#include <iostream>
using namespace std;

class Complex {
private:
	int a, b;
public:
	Complex(){
		a = 1;
		b = 1;
	}
	Complex(int A, int B) {
		a = A;
		b = B;
	}
	Complex add(const Complex &A) {
		Complex sum;
		sum.a = a + A.a;
		sum.b = b + A.b;
		return sum;
	}
	Complex sub(const Complex& A) {
		Complex remainder;
		remainder.a = a - A.a;
		remainder.b = b - A.b;
		return remainder;
	}
	void print() {
		if (a != 0 && b > 1)
			cout << a << "+" << b << "i" << endl;
		if (a != 0 && b == 1)
			cout << a << "+i" << endl;
		if (a != 0 && b == -1)
			cout << a << "-i" << endl;
		if (a != 0 && b < -1)
			cout << a  << b << "i" << endl;
		if (a == 0 && b !=1&&b!=-1&&b!=0)
			cout << b << "i" << endl;
		if (a != 0 && b == 0)
			cout << a << endl;
		if (a == 0 && b == 0)
			cout << a << endl;
		if (a == 0 && b == 1)
			cout << "i" << endl;
		if (a == 0 && b == -1)
			cout << "-i" << endl;
	}
};

int main() {
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		Complex aaa(a, b);
		cin >> a >> b;
		Complex bbb(a, b);
		Complex ccc=aaa.add(bbb);
		cout << "sum: ";
		ccc.print();
		ccc = aaa.sub(bbb);
		cout << "remainder: ";
		ccc.print();
	}
	return 0;
}