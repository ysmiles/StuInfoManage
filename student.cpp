#include "student.h"
#include <iostream>

using namespace std;

//////////////////student//////////////////
student::student() {
    stuname = "��ͨѧ��";
    sex = 0;
    chinese = 0;
    math = 0;
    english = 0;
}

student::student(string name, int s, double c, double m, double e) {
    stuname = name;
    sex = s;
    chinese = c;
    math = m;
    english = e;
}

student student::operator+(student S) {
    student temp;
    temp.stuname = "���˵��ܳɼ�";
    temp.chinese = this->chinese + S.chinese;
    temp.math = this->math + S.math;
    temp.english = this->english + S.english;
    return temp;
}

void student::sName(string name) { stuname = name; }

void student::sSex(int s) { sex = s; }

void student::sGrades(double c, double m, double e) {
    chinese = c;
    math = m;
    english = e;
}

int student::getSex() { return sex; }

double student::getChinese() { return chinese; }

double student::getMath() { return math; }

double student::getEnglish() { return english; }

double student::getTotal() { return chinese + math + english; }

string student::getName() { return stuname; }

ostream &operator<<(ostream &out, student S) {
    out << S.getName() << "\t" << (S.getSex() == 0 ? "Ů" : "��") << "\t"
        << S.getChinese() << "\t" << S.getMath() << "\t" << S.getEnglish()
        << '\t' << S.getTotal() << endl;
    return out;
}

////////////////teacher///////////////
teacher::teacher() {
    teaname = "ְҵ��ʦ";
    sex = 0;
    teach = " ";
}

teacher::teacher(string name, int s, string t) {
    teaname = name;
    sex = s;
    teach = t;
}

void teacher::sName(string name) { teaname = name; }

void teacher::sSex(int s) { sex = s; }

void teacher::sTeach(string t) { teach = t; }

string teacher::getName() { return teaname; }

string teacher::getTeach() { return teach; }

////////////////topstu////////////////
int topstu::getMoney() {
    if (getTotal() <= 250)
        money = 1000;
    else if (getTotal() > 279)
        money = 3000;
    else
        money = 2000;
    return money;
}
