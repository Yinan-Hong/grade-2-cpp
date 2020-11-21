#include <iostream>
using namespace std;

class CDate{
protected:
	int year, month, day;
public:
	CDate() {}
	CDate(int y, int m, int d);
	CDate(CDate& d) { year = d.year; month = d.month; day = d.day; }
	int getyear() {	return year;}
	int getmonth() { return month; }
	int getday() {	return day;}
	bool check(); //检验日期是否合法
	bool isLeap();
	void print();
};
CDate::CDate(int y, int m, int d) { year = y; month = m; day = d; }

bool CDate::isLeap() { return year % 4 == 0 && year % 100 != 0 || year % 400 == 0; }
bool CDate::check() {
	if (year > 0 && month > 0 && day > 0) {
		if (isLeap()) {
			if (month == 2)return day <= 29;
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)return day <= 31;
			else if (month == 4 || month == 6 || month == 9 || month == 11)return month <= 30;
			else return false;
		}
		else {
			if (month == 2)return day <= 28;
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)return day <= 31;
			else if (month == 4 || month == 6 || month == 9 || month == 11)return month <= 30;
			else return false;
		}
	}
	else return false;
}

void CDate::print() {
	cout << year << "年" << month << "月" << day << "日 ";
}
class COldID
{
protected:
	char* p_id15, * p_name; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldID() {}
	COldID(char* p_idval, char* p_nameval, CDate& day);
	bool check(); //验证15位身份证是否合法
	void print();
	~COldID();
};

COldID::COldID(char* p_idval, char* p_nameval, CDate& day) { 
	p_id15 = new char[16];
	p_name = new char[5];
	p_id15 = p_idval; p_name = p_nameval; CDate birthday(day); }
bool COldID::check() {
	for (int i = 0; i < 15; i++, p_id15++) {
		if (*p_id15 > '9' || *p_id15 < '0')return false;
	}
	p_id15 -= 15;
	return true;
}
void COldID::print() {
	cout << p_id15 ;
}
COldID::~COldID() {
	//delete[] p_id15;
	//delete[] p_name;
}

class CNewID : public COldID {
protected:
	char* p_id18;
	CDate issueday;
	int validyear;
public:
	CNewID(char* p_idval, char* p_nameval, CDate& day, CDate& iday, int v, char* pid18) : COldID(p_idval, p_nameval, day) {
		issueday=iday;
		birthday = day;
		validyear = v;
		p_id18 = pid18;
	}
	bool iflegal() {
		int a[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
		int sum = 0;
		for (int i = 0;i < 17;i++)
			sum += (p_id18[i]-'0') * a[i];
		int lastNum;
		char last[] = { 1,0,'X',9,8,7,6,5,4,3,2 };
		lastNum = last[sum % 11];
		if (lastNum != p_id18[17]-'0')
			return false;

		for (int i = 0;i < 17;i++)
			if (p_id18[i] < '0' || p_id18[i] > '9')
				return false;
		if (!(p_id18[17] >= '0' && p_id18[17] <= '9' || p_id18[17] == 'X'))
			return false;

		if ((validyear + issueday.getyear()) * 10000 + issueday.getmonth() * 100 + issueday.getday() < 20150407)
			return false;

		for (int i = 0;i < 5;i++)
			if (p_id18[i] != p_id15[i])
				return false;

		for(int i=14;i<17;i++)
			if (p_id18[i] != p_id15[i-2])
				return false;

		int bd = 0;
		for (int i = 6;i < 14;i++)
			bd = bd * 10 + (p_id18[i] - '0');
		if (bd != birthday.getyear() * 10000 + birthday.getmonth() * 100 + birthday.getday())
			return false;

		if (issueday.check());
		else return false;

		return true;
	}
	void check() {
		if (iflegal())
			print();
		else
			cout << p_name << endl << "illegal id" << endl;
	}
	void print() {
		cout << p_name << endl;
		cout << p_id18 << " ";
		issueday.print();
		if (validyear != 100)
			cout << validyear << "年" << endl;
		else
			cout << "长期" << endl;
	}
};

int main() {
	int t, v;
	int y, m, d;
	int yy, mm, dd;
	char* pn = new char[5];
	char* id15 = new char[16];
	char* id18 = new char[19];
	cin >> t;
	while (t--) {
		cin >> pn >> y >> m >> d >> id15 >> id18 >> yy >> mm >> dd >> v;
		CDate bd(y, m, d);
		CDate isd(yy, mm, dd);
		CNewID A(id15, pn, bd, isd, v, id18);
		A.check();
	}
	return 0;
}