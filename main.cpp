#include<iostream>
#include<vector>
#include<fstream>
#include "student.h"
using namespace std;
void input(vector<student>& vec);//输入信息
int find(vector<student>& vec,vector<student>::iterator& it,string str);//按姓名查找
void sort(vector<student>& vec);//按总成绩从大到小排序
void del(vector<student>& vec,vector<student>::iterator& it,string str);//按姓名删除
void gai(vector<student>& vec,vector<student>::iterator& it,string str);//修改学生信息函数
void cun(vector<student>& vec,vector<student>::iterator& it);//存入文件，设计为程序结束时自动运行
void qu(vector<student>& vec);//从文件中重建类的对象，设计为在程序启动时自动进行
void jiang(vector<topstu>& vec1,vector<student>& vec2);//将vec2中能的奖学金的同学信息写入vec1
int main(){
	vector<student> class1;
	vector<student>::iterator it;
	vector<topstu> top;
	vector<topstu>::iterator it1;
	int b=1,i;
	string c;
	qu(class1);//取得已保存数据
	cout<<"学生信息管理系统欢迎你"<<endl;
	while(b){
	cout<<"********************"<<endl
		<<"(^o^)/主菜单"<<endl
		<<"1.输入学生信息"<<endl
		<<"2.按姓名查找"<<endl
		<<"3.排序并输出全部信息"<<endl
		<<"4.按姓名删除"<<endl
		<<"5.输出奖学金信息"<<endl
		<<"6.修改某同学的信息"<<endl
		<<"0.结束"<<endl
		<<"********************"<<endl;
	cin>>b;
		switch(b)
		{
		case 1:
			input(class1);
			break;
		case 2:
			cout<<"请输入需要查找的姓名:";
			cin>>c;
			if(find(class1,it,c))
			{
			cout<<"姓名"<<"\t"<<"性别"<<"\t"<<"语文"<<"\t"<<"数学"<<"\t"<<"英语"<<"\t"<<"总分"<<endl;
			cout<<*it;
			}
			else cout<<"No found"<<endl;
			break;
		case 3:
			sort(class1);
			cout<<"名次"<<'\t'<<"姓名"<<'\t'<<"性别"<<'\t'<<"语文"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"总分"<<endl;
			for(it=class1.begin(),i=1;it!=class1.end();it++,i++)
			{
				cout<<i<<'\t'<<*it;
			}
			break;
		case 4:
			cout<<"请输入需要删除的姓名:";
			cin>>c;
			del(class1,it,c);
			cout<<"已删除"<<c<<"的信息"<<endl;
			break;
		case 5:
			jiang(top,class1);
			cout<<"姓名"<<'\t'<<"奖学金"<<endl;
			for(it1=top.begin();it1<top.end();it1++)
			{
				cout<<(*it1).getName()<<'\t'<<(*it1).getMoney()<<endl;
			}
			break;
		case 6:
			cout<<"请输入需要修改信息同学的姓名:";
			cin>>c;
			gai(class1,it,c);
			break;
		}
	}
	cun(class1,it);//程序结束前自动保存数据
	return 0;
}


void input(vector<student>& vec)
{
	int a=1,s;
	student temp;
	double x,y,z;
	string c;
	cout<<"请输入:\n1.输入一个学生的信息\n0.结束\n";
	while(a){
		cin>>a;
		if(a==1)
		{
			cout<<"请输入姓名:";
			cin>>c;
			temp.sName(c);
			cout<<"请输入性别(0为女,1为男):";
			cin>>s;
			temp.sSex(s);
			cout<<"请依次输入语文,数学,英语成绩:\n";
			cin>>x>>y>>z;
			temp.sGrades(x,y,z);
			vec.push_back(temp);
		}
		else continue;
		cout<<"请输入:\n1.输入一个学生的信息\n0.结束\n";
	}
}
int find(vector<student>& vec,vector<student>::iterator& it,string str)
{
	for(it=vec.begin();it!=vec.end();it++){
		if(str==(*it).getName()){
			return 1;
			break;
		}
	}
	it=NULL;
	return 0;
}
void sort(vector<student>& vec)
{
	student temp;
	int i,j,k;
	for(k=0;k<vec.size();k++)
	{
		for(i=0;i<vec.size();i++)
		{
			if(vec[i].getTotal()<vec[i+1].getTotal())
			{
				temp=vec[i];
				for(j=i+1;temp.getTotal()<vec[j].getTotal();++j)
				{
					vec[j-1]=vec[j];
				}
				vec[j-1]=temp;
			}
		}
		
	}
}
void del(vector<student>& vec,vector<student>::iterator& it,string str)
{
	for(it=vec.begin();it<=vec.end();it++)
	{
		if ((*it).getName()==str) vec.erase(it);
	}
}
void gai(vector<student>& vec,vector<student>::iterator& it,string str)
{
	if(find(vec,it,str))
	{
		del(vec,it,str);
		student temp;
		int s,x,y,z;
		temp.sName(str);
		cout<<"请输入性别(0为女,1为男):";
		cin>>s;
		temp.sSex(s);
		cout<<"请依次输入语文,数学,英语成绩:\n";
		cin>>x>>y>>z;
		temp.sGrades(x,y,z);
		vec.push_back(temp);
	}
	else cout<<"no found!"<<endl;
}
void jiang(vector<topstu>& vec1,vector<student>& vec2)
{
	int i;
	topstu temp;
	for(i=0;i<vec2.size();i++)
	{
		if(vec2[i].getTotal()>=200)
		{
			temp.sName(vec2[i].getName());
			temp.sSex(vec2[i].getSex());
			temp.sGrades(vec2[i].getChinese(),vec2[i].getMath(),vec2[i].getEnglish());
			vec1.push_back(temp);
		}
	}
}
void cun(vector<student>& vec,vector<student>::iterator& it)
{
	int i;
	ofstream ofile("e:\\学生信息.txt");
	for(it=vec.begin(),i=1;it!=vec.end();it++,i++)
	{
		ofile<<i<<'\t'<<*it;
	}
	ofile.close();
}
void qu(vector<student>& vec)
{
	ifstream ifile("e:\\学生信息.txt");
	int a=1,s;
	student temp;
	double x,y,z;
	string c;
	string sex1;
	while(a)
	{
		ifile>>a;//跳过名次
		ifile>>c;
		if(c=="\0") break;
		temp.sName(c);
		ifile>>sex1;
		s=(sex1=="女"?0:1);
		temp.sSex(s);
		ifile>>x>>y>>z;
		ifile>>a;//跳过总分
		temp.sGrades(x,y,z);
		vec.push_back(temp);
	}
	ifile.close();
}
