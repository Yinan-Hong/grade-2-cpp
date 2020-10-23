#include <iostream>
using namespace std;

class Bank {
	int number, tel, pass, money;
public:
	Bank() {}
	void getBank(int a,int b,int c,int d) {
		number = a;
		tel = b;
		pass = c;
		money = d;
	}
	int getNumber() {
		return number;
	}
	int getTel() {
		return tel;
	}
	int getPass() {
		return pass;
	}
	int getMoney() {
		return money;
	}
	bool check(int a) {
		return a == pass;
	}
	void withdraw(int a) {
		if (a > money)
			cout << "¿¨ºÅ" << number << "--" << "Óà¶î²»×ã" << endl;
		else {
			money -= a;
			cout << "¿¨ºÅ" << number << "--" << "Óà¶î" << money << endl;
		}
	}
};

int main() {
	int n, num, tel, pass, money, k;
	cin >> n;
	Bank* p = new Bank[n];
	for (int i = 0; i < n;i++) {
		cin >> num >> tel >> pass >> money;
		p[i].getBank(num, tel, pass, money);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> tel >> pass >> money;
		int flag = 0;
		int j = 0;
		for (; j < n; j++) {
			if (tel == p[j].getTel()) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			if (p[j].getPass() == pass)
				p[j].withdraw(money);
			else
				cout << "ÃÜÂë´íÎó" << endl;
		}
		else
			cout << "ÊÖ»úºÅ²»´æÔÚ" << endl;
	}
	return 0;
}