#ifndef _STUDENT_H_
#define _STUDENT_H_
#include<iostream>
#include<string>
using namespace std;
class student
{
private:	
	string stuname;
	int sex;
	double chinese;
	double math;
	double english;
public:
	student();
	student(string name,int s,double c,double m,double e);
	student operator+(student S);
	void sName(string name);
	void sSex(int s);
	void sGrades(double c,double m,double e);
	int getSex();
	double getChinese();
	double getMath();
	double getEnglish();
	double getTotal();
	string getName();
	friend ostream & operator<<(ostream&out,student S);
	~student(){}
};
class teacher
{	
	string teaname;
	int sex;
	string teach;//任课内容
public:
	teacher();
	teacher(string name,int s,string t);
	void sName(string name);
	void sSex(int s);
	void sTeach(string);
	int getSex();
	string getName();
	string getTeach();
	~teacher(){}
};
class topstu:public student//优等生
{
	int money;//奖学金等级
public:
	topstu(){}
	int getMoney();
	~topstu(){}
};
class stea:public student,public teacher
{
public:
	stea(){}
	~stea(){}
};
#endif
