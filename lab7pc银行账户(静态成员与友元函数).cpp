#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Account {
public:
	Account(){}
	Account(string accno, string name, float balance);
	~Account();
	void Deposit(float amount);
	void Withdraw(float amount);
	float GetBalance();
	void Show();
	static int GetCount();
	static float GetInterestRate();
	friend float Update(Account& a);
	static void setInterest(float i);
	void setbalance(float b);
	static void setcount(float b);

private:
	static int count;
	static float InterestRate;
	string _accno, _accname;
	float _balance;
};

int Account::count = 0;
float Account::InterestRate = 0;

Account::Account(string accno, string name, float balance) {
	_accno = accno;		//strcpy(_accno, accno);
	_accname = name;	//strcpy(_accname, name);
	_balance = balance;
}

Account::~Account(){}

void Account::Deposit(float amount) {
	_balance += amount;
}

void Account::Withdraw(float amount) {
	_balance -= amount;
}

float Account::GetBalance() { return _balance; }

void Account::Show() {
	cout << _accno << ' ' << _accname << ' ';
}

int Account::GetCount() { return count; }

float Account::GetInterestRate() { return InterestRate; }

float Update(Account& a) {
	return a._balance +a._balance * a.InterestRate;
}

void Account::setInterest(float i) {
	InterestRate = i;
}

void Account::setbalance(float b) {
	_balance = b;
}

void Account::setcount(float b) {
	count += b;
}

int main() {
	int n;
	string acc, name;
	float i, b, d, w;
	cin >> i >> n;
	int j = n;
	Account::setInterest(i);
	while (j--) {
		cin >> acc >> name >> b >> d >> w;
		Account a(acc, name, b);
		a.Show();
		a.Deposit(d);
		cout << a.GetBalance() << ' ';
		a.setbalance(Update(a));
		cout << a.GetBalance() << ' ';
		a.Withdraw(w);
		cout << a.GetBalance() << endl;
		a.setcount(a.GetBalance());
 	}
	cout << Account::GetCount() << endl;


	return 0;
}

/*
题目描述
银行账户类的基本描述如下：


要求如下：
实现该银行账户类
为账户类Account增加一个友元函数，实现账户结息，要求输出结息后的余额（结息余额=账户余额+账户余额*利率）。友元函数声明形式为 friend void Update(Account& a);
在main函数中，定义一个Account类型的指针数组，让每个指针指向动态分配的Account对象，并调用成员函数测试存款、取款、显示等函数，再调用友元函数测试进行结息。
大家可以根据实际需求在类内添加其他方法，也可以修改成员函数的参数设置



输入
第1行：利率
第2行：账户数目n
第3行开始，每行依次输入一个账户的“账号”、“姓名”、“余额”、存款数，取款数。
输出
第1行开始，每行输出一个账户的相关信息，包括账号、姓名、存款后的余额、存款后结息余额、取款后余额。
最后一行输出所有账户的余额。

样例输入
0.01
3
201501 张三 10000 1000 2000
201502 李四 20000 2000 4000
201503 王二 80000 4000 6000
样例输出
201501 张三 11000 11110 9110
201502 李四 22000 22220 18220
201503 王二 84000 84840 78840
106170
*/