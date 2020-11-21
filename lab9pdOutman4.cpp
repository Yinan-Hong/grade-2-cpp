//用了还没学的，别抄=.=

#include <iostream>
using namespace std;

class Outman {
protected:
	int hp; int rank; int damage; int exp; int money;
public:
	friend class Boss;
	Outman() {}
	Outman(int r) :rank(r) {
		hp = 10 * rank;
		damage = 3 * rank;
		money = 10 * rank;
		exp = 0;
	}
	void excape() {
			money = 0;
			cout << "lose" << endl;
	}
	void attacked(int d) { hp -= d / 2; }
	void restore() {
		if (hp < rank * 10 / 2 && hp>10)
			while (money > 0)
				if (hp < rank * 10) {
					hp++;
					money -= 10;
				}
	}
	void win(int e, int m) {
		exp += e;
		money += m;
	}
	void upgrade() {
		while (exp >= rank * 10) {
			exp -= rank * 10;
			rank++;
			hp = rank * 10;
			damage = rank * 3;
		}
	}
	void display() {
		cout << "奥特曼状态(" << "rank=" << rank << " hp=" << hp << " damage=" <<
			damage << " exp=" << exp << " money=" << money << ")" << endl;
	}
	int gethp() { return hp; }
	int getrank() { return rank; }
	int getdamage() { return damage; }
	int getexp() { return exp; }
	int getmoney() { return money; }
};

class Monster :public Outman {
public:
	Monster(){}
	Monster(int r){
		rank = r;
		hp = 20 * rank;
		damage = 2 * rank;
		money = 10 * rank;
		exp = 10 * rank;
	}
	virtual void attacked(int d) {
		hp -= d;
	}
	void next(int r) {
		rank = r;
		hp = 20 * rank;
		damage = 2 * rank;
		money = 10 * rank;
		exp = 10 * rank;
	}
};

class Boss :public Monster {
private:
	int count;
public:
	Boss() {rank = 10;hp = 300;exp = 1000;damage = 50;money = 1001;count = 0;}
	void XP(Outman& o) {
		count = 0;
		o.attacked(damage * 3);
	}
	void attack(Outman& o) {
		if (count == 4)
			XP(o);
		else {
			o.attacked(damage);
			count++;
		}
	}
};

int main() {
	int t, r, n, k;
	cin >> t;
	while (t--) {
		cin >> r;
		Outman outman(r);
		cin >> n >> k;
		Monster monster(k);
		outman.display();
		//monster.display();

		bool flag = true;
		while (n--) {
			while (1) {
				monster.attacked(outman.getdamage());//outman attack
				if (monster.gethp() > 0) {
					outman.attacked(monster.getdamage());//monster fightback
					if (outman.gethp() < 10) {
						outman.excape();
						flag = false;
						break;
					}
					else 
						outman.restore();
				}
				else {
					cout << "win" << endl;
					outman.win(monster.getexp(), monster.getmoney());
					outman.upgrade();
					break;
				}
			}
			if (!flag) {
				outman.display();
				break;
			}
			monster.next(k);
		}
		if (flag) {
			outman.display();
			Boss boss;
			while (1) {
				boss.attacked(outman.getdamage());//outman attack
				if (boss.gethp() > 0) {
					boss.attack(outman);
					if (outman.gethp() < 10) {
						outman.excape();
						flag = false;
						break;
					}
					else
						outman.restore();
				}
				else {
					cout << "win Boss" << endl;
					outman.win(boss.getexp(), boss.getmoney());
					outman.upgrade();
					break;
				}
			}
			outman.display();
		}
	}
	return 0;
}

/*
题目描述
重新组织和修改前面“类的实现”的代码，利用继承实现以下内容。

奥特曼在与多个小怪兽过招的过程中，不断提升自己的等级。在一切就绪的时候，就可以挑战小怪兽的头Boss了。打败Boss就可以获得最终的胜利。

在怪兽类的基础上，定义和实现一个子类Boss类。如有必要，请对奥特曼和怪兽类做出相应的修改。

Boss类对怪兽类进行了扩充和修改：

l  Boss属性的初始值与一般怪兽不同，等级为10，生命值为300，经验值是1000，攻击力是50，钱数是1001。

l  Boss有一个新的方法，即绝招(XP)。该方法将连续攻击奥特曼3次。

l  Boss的反击方法(fightback)也与一般怪兽不同，一般情况下受到奥特曼的攻击就会反击一次，但每当Boss受到奥特曼攻击的次数(count)累计5次，就会使用绝招(XP)。



*******************************************************************************

Outman（奥特曼类对象）在打败所有的小怪兽后，将挑战怪兽之王。

请在main函数中实现如下架构

int main(){

	//输入测试次数



	while(t--){

//输入奥特曼的等级值，利用等级值，声明一个奥特曼对象并显示奥特曼对象初始状态。

//输入怪兽个数和等级



	while(？？？？)//只要奥特曼没死也没逃跑，就继续与n个怪兽的战斗

	{

		 利用怪兽等级值生成怪兽对象



		 //设置战斗标志flag为true，启动战斗循环，具体如下：

		 while(flag) //当战斗未结束就继续

		 {

			 //奥特曼攻击1次

			 if (？？？？)  //怪兽没死

			 {   //怪兽反击1次



				  if (？？？)       //奥特曼没死也不逃跑

					  //奥特曼回血，在方法中判断是否需要加血



				  else

				  {   //奥特曼逃跑，并输出"lose"并回车



					  //输出奥特曼状态，调用display方法



					  //设置flag为false，停止战斗



				  }

			 }

			 else //怪兽死了

			 {

				  //奥特曼胜利，并输出"win"并回车



				  //奥特曼升级



				  //设置flag为false，停止战斗



			 }

		 }

	}



	if(？？？？)//如果打完n个小怪兽奥特曼还没死也没逃跑，就挑战Boss

	{

		 //输出奥特曼当前状态



		 //生成Boss对象初始化





		 //设置战斗标志flag为true，启动战斗循环，具体如下：



		 while(flag) //当战斗未结束就继续

		 {

			 //奥特曼攻击1次



			 if (？？？？)  //Boss没死

			 {   //Boss反击1次



				  if (？？？)       //奥特曼没死也不逃跑

					  //奥特曼回血，在方法中判断是否需要加血



				  else

				  {   //奥特曼逃跑，并输出"lose"并回车



					  //输出奥特曼状态，调用display方法



					  //设置flag为false，停止战斗



				  }

			 }



			 else //怪兽死了

			 {

				  //奥特曼胜利，并输出"win Boss"并回车



				  //奥特曼升级



				  //输出奥特曼状态，调用display方法



				  //设置flag为false，停止战斗



			 }

		 }

	}

	}

	return 0;

}


输入
第1行输入t表示有t个测试实例

对于每个测试实例，首行先输入奥特曼等级

接着下一行输入n和k，表示怪兽数量和等级

输出
 输出每个测试实例的战斗结果。

对于每一个实例的输出如下：

第一行奥特曼的状态

第二行~第n+1行依次输出奥特曼打每个怪兽的结果。

如果奥特曼把n个怪兽都打败了，

	 第n+2行输出此时奥特曼的状态

	 第n+3行输出奥特曼打怪兽首领的结果

	 第n+4行输出奥特曼打怪兽首领后的状态



如果奥特曼被某个怪兽打败，则输出战斗结果，下一行输出战斗后奥特曼的状态，不再与怪兽首领进行战斗。

样例输入
2
5
5 5
20
5 10
样例输出
奥特曼状态(rank=5 hp=50 damage=15 exp=0 money=50)
win
win
win
win
win
奥特曼状态(rank=8 hp=60 damage=24 exp=70 money=150)
lose
奥特曼状态(rank=8 hp=0 damage=24 exp=70 money=0)
奥特曼状态(rank=20 hp=200 damage=60 exp=0 money=200)
win
win
win
win
win
奥特曼状态(rank=22 hp=220 damage=66 exp=90 money=700)
win Boss
奥特曼状态(rank=26 hp=260 damage=78 exp=150 money=1701)
*/