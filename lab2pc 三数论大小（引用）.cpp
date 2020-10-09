#include <iostream>
using namespace std;

void sort(int& a, int& b, int& c) {
	if (c > b) {
		int temp = b;
		b = c;
		c = temp;
	}
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (c > b) {
		int temp = b;
		b = c;
		c = temp;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int& d = a;
		int& e = b;
		int& f = c;
		sort(d, e, f);
		cout << a <<" "<< b << " " << c << endl;
	}
	return 0;
}

/*
题目描述
输入三个整数，然后按照从大到小的顺序输出数值。

要求：定义一个函数，无返回值，函数参数是三个整数参数的引用，例如int &a, int &b, int &c。在函数内通过引用方法来对三个参数进行排序。主函数调用这个函数进行排序。

要求：不能直接对三个整数进行排序，必须通过函数而且是引用的方法。

输入
第一行输入t表示有t个测试实例

第二行起，每行输入三个整数

输入t行

输出
每行按照从大到小的顺序输出每个实例，三个整数之间用单个空格隔开

样例输入
3
2 4 6
88 99 77
111 333 222
样例输出
6 4 2
99 88 77
333 222 111
*/