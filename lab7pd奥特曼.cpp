#include <iostream>
using namespace std;

class Angel {
private:
    int rank, damage, exp, money;
public:
    Angel(){}

    void set(int r) {
        rank = r;
        damage = rank / 2;
        money = rank * 5;
        exp = rank * 5;
    }

    int getRank() { return rank; }
    int getDamage() { return damage; }
    int getExp() { return exp; }
    int getMoney() { return money; }
};

class Ultraman {
private:
    int rank, hp, damage, exp, money;
    Angel A;
public:
    Ultraman(int r) {   //初始化属性
        rank = r;
        hp = r * 10;    //生命是等级10倍
        damage = r * 3; //攻击是等级3倍
        money = r * 10; //金钱是等级的10倍
        exp = 0;        //经验开始为0
        A.set(rank);
    }
    int getRank() { return rank; }
    int getHp() { return hp; }
    int getDamage() { return damage; }
    int getExp() { return exp; }
    int getMoney() { return money; }

    void attacked(int d) {
        hp -= d / 2;    //生命损失=怪兽攻击力值/2
    }


    void restore() {        //回血
        if (hp > 10 && hp < 10 * rank / 2) {
            while (hp < rank * 10) {
                if (money >= 10) {
                    hp++;
                    money -= 10;
                }
                else
                    break;
            }
        }
    }

    void win(int h, int m, int e) {
        if (h <= 0) {
            money += m;
            exp += e;
        }
    }

    void upgrade() {
        while(exp >= rank * 10) {
            exp -= rank * 10;
            rank++;
            hp = rank * 10;
            damage = rank * 3;
            A.set(rank);
        }
    }

    bool ifRun() {
        return hp <= 10;
    }

    void run() {
        money = 0;
    }

    void display() {
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money << endl;
    }
};

class Monster {
private:
    int rank, hp, damage, exp, money;
    Angel A;
public:
    Monster(int r) {
        rank = r;
        hp = r * 20;    //生命是等级20倍
        damage = r * 2; //攻击是等级2倍
        money = r * 10; //金钱是等级的10倍
        exp = r * 10;   //经验值是等级的10倍
        A.set(rank);
    }
    int getRank() { return rank; }
    int getHp() { return hp; }
    int getDamage() { return damage; }
    int getExp() { return exp+A.getExp(); }
    int getMoney() { return money+A.getMoney(); }

    void attacked(Ultraman& U) {
        hp -= U.getDamage();
    }
    //void fightback(){}
    bool isAlive() {
        return hp > 0;
    }
    void display() {
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money << endl;
    }
};

class NMonster {
private:
    int rank, hp, damage, exp, money;
public:
    NMonster(int r) {
        rank = r;
        hp = r * 10;    //生命是等级10倍
        damage = r * 2; //攻击是等级2倍
        money = r * 10; //金钱是等级的10倍
        exp = r * 10;   //经验值是等级的10倍
    }
    int getRank() { return rank; }
    int getHp() { return hp; }
    int getDamage() { return damage; }
    int getExp() { return exp; }
    int getMoney() { return money; }

    void attacked(Ultraman& U) {
        hp -= U.getDamage();
    }
    //void fightback(){}
    bool isAlive() {
        return hp > 0;
    }
    void display() {
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money << endl;
    }
};

class AMonster {
private:
    int rank, hp, damage, exp, money;
    Angel A;
public:
    AMonster(int r) {
        rank = r;
        hp = r * 5;    //生命是等级5倍
        damage = r * 4; //攻击是等级4倍
        money = r * 10; //金钱是等级的10倍
        exp = r * 10;   //经验值是等级的10倍
        A.set(rank);
    }
    int getRank() { return rank; }
    int getHp() { return hp; }
    int getDamage() { return damage+A.getDamage(); }//加上守护神伤害
    int getExp() { return exp+A.getExp(); }
    int getMoney() { return money+A.getMoney(); }

    void attacked(Ultraman& U) {
        hp -= (U.getDamage()+1);      //守护神加成+1
    }
    //void fightback(){}
    bool isAlive() {
        return hp > 0;
    }
    void display() {
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money << endl;
    }
};

class DMonster {
private:
    int rank, hp, damage, exp, money;
    Angel A;
public:
    DMonster(int r) {
        rank = r;
        hp = r * 20;    //生命是等级20倍
        damage = r; //攻击是等级1倍
        money = r * 10; //金钱是等级的10倍
        exp = r * 10;   //经验值是等级的10倍
        A.set(rank);
    }
    int getRank() { return rank; }
    int getHp() { return hp; }
    int getDamage() { return damage; }
    int getExp() { return exp + A.getExp(); }
    int getMoney() { return money+A.getMoney(); }

    void attacked(Ultraman& U) {
        hp -= (U.getDamage()/2);      //守护神加成/2
    }
    //void fightback(){}
    bool isAlive() {
        return hp > 0;
    }
    void display() {
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money << endl;
    }
};

class SMonster {
private:
    int rank, hp, damage, exp, money;
public:
    SMonster(int r) {
        rank = r;
        hp = r * 10;    //生命是等级20倍
        damage = r ; //攻击是等级1倍
        money = r * 20; //金钱是等级的20倍
        exp = r * 20;   //经验值是等级的20倍
    }
    int getRank() { return rank; }
    int getHp() { return hp; }
    int getDamage() { return damage; }
    int getExp() { return 2*exp; }          //守护神加成
    int getMoney() { return 2*money; }      //守护神加成

    void attacked(Ultraman& U) {
        hp -= U.getDamage();
    }
    //void fightback(){}
    bool isAlive() {
        return hp > 0;
    }
    void display() {
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money << endl;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int rankU, rankNM, rankAM, rankDM, rankSM;
        cin >> rankU >> rankNM >> rankSM >> rankDM >> rankAM;
        Ultraman U(rankU);
        NMonster NM(rankNM);
        SMonster SM(rankSM);
        DMonster DM(rankDM);
        AMonster AM(rankAM);
        U.display();
        NM.display();
        SM.display();
        DM.display();
        AM.display();
        bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
        bool flag11 = true, flag22 = true, flag33 = true, flag44 = true;

        while (flag1 || flag2 || flag3 || flag4) {
            if (flag1)NM.attacked(U);  //Ultraman attacks
            if (flag4)SM.attacked(U);
            if (flag3)DM.attacked(U);
            if (flag2)AM.attacked(U);

            if (NM.isAlive()) {
                U.attacked(NM.getDamage());  //Monster attacks
                if (U.ifRun()) {    //run away
                    U.run();
                    cout << "lose" << endl;
                    U.display();
                    break;
                }
                else
                    U.restore();
            }
            else
                flag1 = false;

            if (!flag1&&flag11) {
                U.win(NM.getHp(), NM.getMoney(), NM.getExp());
                U.upgrade();
                cout << "win" << endl;
                U.display();
                flag11 = false;
            }

            if (SM.isAlive()) {
                U.attacked(SM.getDamage());  //Monster attacks
                if (U.ifRun()) {    //run away
                    U.run();
                    cout << "lose" << endl;
                    U.display();
                    break;
                }
                else
                    U.restore();
            }
            else 
                flag4 = false;
            if (!flag4&&flag44) {
                U.win(SM.getHp(), SM.getMoney(), SM.getExp());
                U.upgrade();
                cout << "win" << endl;
                U.display();
                flag44 = false;
            }

            if (DM.isAlive()) {
                U.attacked(DM.getDamage());  //Monster attacks
                if (U.ifRun()) {    //run away
                    U.run();
                    cout << "lose" << endl;
                    U.display();
                    break;
                }
                else
                    U.restore();
            }
            else
                flag3 = false;
            if (!flag3&flag33) {
                U.win(DM.getHp(), DM.getMoney(), DM.getExp());
                U.upgrade();
                cout << "win" << endl;
                U.display();
                flag33 = false;
            }

            if (AM.isAlive()) {
                U.attacked(AM.getDamage());  //Monster attacks
                if (U.ifRun()) {    //run away
                    U.run();
                    cout << "lose" << endl;
                    U.display();
                    break;
                }
                else
                    U.restore();
            }
            else
                flag2 = false;
            if (!flag2&&flag22) {
                U.win(AM.getHp(), AM.getMoney(), AM.getExp());
                U.upgrade();
                cout << "win" << endl;
                U.display();
                flag22 = false;
            }

        }

        //if monster dies
        if (!flag1 && !flag2 && !flag3 && !flag4)
            cout << "win all" << endl;
    }
    return 0;
    }
    