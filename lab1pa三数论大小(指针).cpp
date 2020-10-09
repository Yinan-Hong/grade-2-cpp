#include <iostream>
using namespace std;

void sort(int **p1, int **p2) {
		int temp;
		int* ptemp=&temp;
	if (**p2 > **p1) {

		*ptemp = **p2;
		**p2 = **p1;
		**p1 = *ptemp;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int* pointer_a = &a;
		int* pointer_b = &b;
		int* pointer_c = &c;
		sort(&pointer_a, &pointer_b);
		sort(&pointer_b, &pointer_c);
		sort(&pointer_a, &pointer_b);
		cout << *pointer_a << ' ' << *pointer_b << ' ' << *pointer_c << ' ' << endl;

	}
	return 0;
}

/*
题目描述
输入三个整数，然后按照从大到小的顺序输出数值。
要求：用三个指针分别指向这三个整数，排序过程必须通过这三个指针来操作，不能直接访问这三个整数
输出时，必须使用这三个指针，不能使用存储三个整数的变量

输入
第一行输入t表示有t个测试实例
第二行起，每行输入三个整数
输入t行

输出
每行按照从大到小的顺序输出每个实例
在每行中，每个数据输出后都带有一个空格，即使该行最后一个数据输出后也要再输出一个空格

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