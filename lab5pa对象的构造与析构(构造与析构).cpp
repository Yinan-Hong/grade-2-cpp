#include<iostream>
using namespace std;
int number = 0;

class C {
public:
	C() {
		number++;
		cout << "Constructing object " << number << endl;
	}
	~C() {
		cout << "Destructing object " << number << endl;
		number--;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		C* pC = new C[n];
		delete[] pC;
	}
	return 0;
}