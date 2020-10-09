#include <iostream>
using namespace std;

struct Paper {
	int number;
	char ans_1[20];
	char ans_2[20];
	char ans_3[20];
};

bool judge(char* pa, char* pb) {
	int len = 0;
	int same = 0;
	while (*pa != '\0' && *pb != '\0') {
		if (*pa == *pb)
			same++;
		len++;
		pa++;
		pb++;
	}
	return same >= 0.9 * len;
}

int cmp(Paper A, Paper B) {
	int c = 3;
	char* pa = A.ans_1;
	char* pb = B.ans_1;
	if (judge(pa, pb))
		return 1;
	pa = A.ans_2;
	pb = B.ans_2;
	if (judge(pa, pb))
		return 2;
	pa = A.ans_3;
	pb = B.ans_3;
	if (judge(pa, pb))
		return 3;
	return 0;
}

int main() {
	int t;
	cin >> t;
	struct Paper paper[10];
	for (int i = 0; i < t; i++) 
		cin >> paper[i].number >> paper[i].ans_1 >> paper[i].ans_2 >> paper[i].ans_3;
	for (int i = 0; i < t-1 ; i++) {
		for (int j = i+1; j < t; j++) {
			if (int z=cmp(paper[i], paper[j])) {
				cout << paper[i].number << " " << paper[j].number << " " << z << endl;

			}
		}
	}

	return 0;
}


/*
题目描述
已知一群学生的考试试卷，要求对试卷内容进行对比，查找是否有抄袭。
每张试卷包含：学号（整数类型）、题目1答案（字符串类型）、题目2答案（字符串类型）、题目3答案（字符串类型）
要求：使用结构体来存储试卷的信息。定义一个函数，返回值为一个整数，参数是两个结构体指针，函数操作是比较两张试卷的每道题目的答案，如果相同题号的答案相似度超过90%，那么就认为有抄袭，函数返回抄袭题号，否则返回0。相似度是指在同一题目中，两个答案的逐个位置上的字符两两比较，相同的数量大于等于任一个答案的长度的90%，就认为抄袭。

输入
第一行输入t表示有t张试卷
第二行输入第1张试卷的学生学号
第三行输入第1张试卷的题目1答案
第四行输入第1张试卷的题目2答案
第五行输入第1张试卷的题目3答案
每张试卷对应4行输入
依次输入t张试卷的数据
输出
在一行中，把发现抄袭的两个学号和题目号，数据之间用单个空格隔开
如果发现是题目1抄袭，题目号为1，以此类推
输出顺序按照输入的学号顺序进行输出
样例输入
5
2088150555
aabcdef11
ZZ887766dd
cc33447799ZZ
2088150333
abcdef00
AABBCCDDEE
ZZ668899cc
2088150111
AABBCCDDEE
ZZ668899cc
abcdef00
2088150222
AABBCFDDeE
ZZ889966dd
abcdef000
2088150444
aabcdef00
AABBCDDDEE
cc668899ZZ
样例输出
2088150333 2088150444 2
2088150111 2088150222 3
*/