#include <iostream>
using namespace std;

struct Birthday {
	int day, month, year;
};

void swap(Birthday& a, Birthday& b) {
	Birthday temp = a;
	a = b;
	b = temp;
}

bool DateABiggerThanDateB(Birthday A, Birthday B) {
	if (A.year > B.year)
		return true;
	else if (A.year < B.year)
		return false;
	else {
		if (A.month > B.month)
			return true;
		else if (A.month < B.month)
			return false;
		else {
			return A.day > B.day;
		}
	}
}

Birthday sort(Birthday* birthday, int t) {
	for (int i = t-1; i > 0 ; i--) {
		for (int j = 0; j < i; j++) {
			if (DateABiggerThanDateB(birthday[j], birthday[j + 1]))
				swap(birthday[j], birthday[j + 1]);
		}
	}
	return birthday[1];
}

int main() {
	int t;
	cin >> t;
	struct Birthday birthday[10];
	for (int i = 0; i < t; i++) 
		cin >> birthday[i].year >> birthday[i].month >> birthday[i].day;
	struct Birthday sec = sort(birthday, t);
	cout << sec.year << "-" << sec.month << "-" << sec.day << endl;
	
	return 0;
}


/*
题目描述
定义一个结构体，包含年月日，表示一个学生的出生日期。然后在一群学生的出生日期中找出谁的出生日期排行第二
要求：出生日期的存储必须使用结构体，不能使用其他类型的数据结构。
要求程序全过程对出生日期的输入、访问、输出都必须使用结构。

输入
第一行输入t表示有t个出生日期
每行输入三个整数，分别表示年、月、日
依次输入t个实例

输出
输出排行第二老的出生日期，按照年-月-日的格式输出

样例输入
6
1980 5 6
1981 8 3
1980 3 19
1980 5 3
1983 9 12
1981 11 23
样例输出
1980-5-3
*/