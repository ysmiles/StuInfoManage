#include "student.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void input(vector<student> &vec); //������Ϣ

int find(vector<student> &vec, vector<student>::iterator &it,
         string str);            //����������

void sort(vector<student> &vec); //���ܳɼ��Ӵ�С����

void del(vector<student> &vec, vector<student>::iterator &it,
         string str); //������ɾ��

void gai(vector<student> &vec, vector<student>::iterator &it,
         string str); //�޸�ѧ����Ϣ����

void cun(vector<student> &vec,
         vector<student>::iterator &it); //�����ļ������Ϊ�������ʱ�Զ�����

void qu(vector<student> &vec); //���ļ����ؽ���Ķ������Ϊ�ڳ�����ʱ�Զ�����

void jiang(vector<topstu> &vec1,
           vector<student> &vec2); //��vec2���ܵĽ�ѧ���ͬѧ��Ϣд��vec1

int main() {
    vector<student> class1;
    vector<student>::iterator it;
    vector<topstu> top;
    vector<topstu>::iterator it1;

    int b = 1, i;
    string c;
    qu(class1); //ȡ���ѱ�������
    cout << "ѧ����Ϣ����ϵͳ��ӭ��" << endl;
    while (b) {
        cout << "********************" << endl
             << "(^o^)/���˵�" << endl
             << "1.����ѧ����Ϣ" << endl
             << "2.����������" << endl
             << "3.�������ȫ����Ϣ" << endl
             << "4.������ɾ��" << endl
             << "5.�����ѧ����Ϣ" << endl
             << "6.�޸�ĳͬѧ����Ϣ" << endl
             << "0.����" << endl
             << "********************" << endl;
        cin >> b;
        switch (b) {
        case 1:
            input(class1);
            break;
        case 2:
            cout << "��������Ҫ���ҵ�����:";
            cin >> c;
            if (find(class1, it, c)) {
                cout << "����"
                     << "\t"
                     << "�Ա�"
                     << "\t"
                     << "����"
                     << "\t"
                     << "��ѧ"
                     << "\t"
                     << "Ӣ��"
                     << "\t"
                     << "�ܷ�" << endl;
                cout << *it;
            } else
                cout << "No found" << endl;
            break;
        case 3:
            sort(class1);
            cout << "����" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "����"
                 << '\t' << "��ѧ" << '\t' << "Ӣ��" << '\t' << "�ܷ�" << endl;
            for (it = class1.begin(), i = 1; it != class1.end(); it++, i++) {
                cout << i << '\t' << *it;
            }
            break;
        case 4:
            cout << "��������Ҫɾ��������:";
            cin >> c;
            del(class1, it, c);
            cout << "��ɾ��" << c << "����Ϣ" << endl;
            break;
        case 5:
            jiang(top, class1);
            cout << "����" << '\t' << "��ѧ��" << endl;
            for (it1 = top.begin(); it1 < top.end(); it1++) {
                cout << (*it1).getName() << '\t' << (*it1).getMoney() << endl;
            }
            break;
        case 6:
            cout
                << "��������Ҫ�޸���Ϣͬѧ������"
                   ":";
            cin >> c;
            gai(class1, it, c);
            break;
        }
    }
    cun(class1, it); //�������ǰ�Զ���������
    return 0;
}

void input(vector<student> &vec) {
    int a = 1, s;
    student temp;
    double x, y, z;
    string c;
    cout << "������:\n1.����һ��ѧ������Ϣ\n0.����\n";
    while (a) {
        cin >> a;
        if (a == 1) {
            cout << "����������:";
            cin >> c;
            temp.sName(c);
            cout << "�������Ա�(0ΪŮ,1Ϊ��):";
            cin >> s;
            temp.sSex(s);
            cout << "��������������,��ѧ,Ӣ��ɼ�:\n";
            cin >> x >> y >> z;
            temp.sGrades(x, y, z);
            vec.push_back(temp);
        } else
            continue;
        cout << "������:\n1.����һ��ѧ������Ϣ\n0.����\n";
    }
}

int find(vector<student> &vec, vector<student>::iterator &it, string str) {
    for (it = vec.begin(); it != vec.end(); it++) {
        if (str == (*it).getName()) {
            return 1;
            break;
        }
    }
    it = NULL;
    return 0;
}

void sort(vector<student> &vec) {
    student temp;
    int i, j, k;
    for (k = 0; k < vec.size(); k++) {
        for (i = 0; i < vec.size(); i++) {
            if (vec[i].getTotal() < vec[i + 1].getTotal()) {
                temp = vec[i];
                for (j = i + 1; temp.getTotal() < vec[j].getTotal(); ++j) {
                    vec[j - 1] = vec[j];
                }
                vec[j - 1] = temp;
            }
        }
    }
}

void del(vector<student> &vec, vector<student>::iterator &it, string str) {
    for (it = vec.begin(); it <= vec.end(); it++) {
        if ((*it).getName() == str)
            vec.erase(it);
    }
}

void gai(vector<student> &vec, vector<student>::iterator &it, string str) {
    if (find(vec, it, str)) {
        del(vec, it, str);
        student temp;
        int s, x, y, z;
        temp.sName(str);
        cout << "�������Ա�(0ΪŮ,1Ϊ��):";
        cin >> s;
        temp.sSex(s);
        cout << "��������������,��ѧ,Ӣ��ɼ�:\n";
        cin >> x >> y >> z;
        temp.sGrades(x, y, z);
        vec.push_back(temp);
    } else
        cout << "no found!" << endl;
}

void jiang(vector<topstu> &vec1, vector<student> &vec2) {
    int i;
    topstu temp;
    for (i = 0; i < vec2.size(); i++) {
        if (vec2[i].getTotal() >= 200) {
            temp.sName(vec2[i].getName());
            temp.sSex(vec2[i].getSex());
            temp.sGrades(vec2[i].getChinese(), vec2[i].getMath(),
                         vec2[i].getEnglish());
            vec1.push_back(temp);
        }
    }
}

void cun(vector<student> &vec, vector<student>::iterator &it) {
    int i;
    ofstream ofile("e:\\ѧ����Ϣ.txt");
    for (it = vec.begin(), i = 1; it != vec.end(); it++, i++) {
        ofile << i << '\t' << *it;
    }
    ofile.close();
}

void qu(vector<student> &vec) {
    ifstream ifile("e:\\ѧ����Ϣ.txt");
    int a = 1, s;
    student temp;
    double x, y, z;
    string c;
    string sex1;
    while (a) {
        ifile >> a; //��������
        ifile >> c;
        if (c == "\0")
            break;
        temp.sName(c);
        ifile >> sex1;
        s = (sex1 == "Ů" ? 0 : 1);
        temp.sSex(s);
        ifile >> x >> y >> z;
        ifile >> a; //�����ܷ�
        temp.sGrades(x, y, z);
        vec.push_back(temp);
    }
    ifile.close();
}