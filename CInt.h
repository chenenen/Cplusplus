//���������ص�ʵ��
#ifndef __TEST__
#define __TEST__
#include<iostream>
using namespace std;
class CInt
{
	friend ostream& operator<<(ostream& _cout, const CInt& I);
	friend istream& operator>>(istream& _cin, CInt& I);
public:
	CInt(int i);
	CInt(const CInt &i);
	~CInt();
	void Print();
	CInt& operator=(const CInt& I);
	CInt operator+(const CInt& I);
	CInt operator-(const CInt& I);
	CInt operator*(const CInt& I);
	CInt operator/(const CInt& I);
	bool operator==(const CInt& I);
	bool operator!=(const CInt& I);
	bool operator>(const CInt& I);
	bool operator<(const CInt& I);
	bool operator>=(const CInt& I);
	bool operator<=(const CInt& I);
	bool operator||(const CInt& I);
	bool operator&&(const CInt& I);
	CInt& operator++();
	CInt operator++(int);
	CInt& operator--();
	CInt operator--(int);
private:
	int a;
};
#endif


//˵�������߽�����Ĳ��Դ��������һ���ļ��л�ȽϺã���������Ϊ�˶��߷���鿴

//��������Ĳ���
void Creat()
{
	CInt t1(10);
	CInt t2(t1);
	t1.Print();
	t2.Print();
}
//��ֵ�Ĳ���
void Asign()
{
	CInt t1(5);
	CInt t2(6);
	CInt t3(7);
	t1 = t2;
	t2 = t3;
	t1.Print();
	t2.Print();
	t3.Print();
}
//��������Ĳ��ԣ�+ - * /
void Arithmetic()
{
	CInt t1(8);
	CInt t2(4);

	cout<<"����ǰ��"<<endl;
	cout<<"t1:"<<t1<<endl;
	cout<<"t2:"<<t2<<endl;

	cout<<"�����"<<endl;

	cout<<"t1+t2"<<" "<<t1+t2<<endl;
	cout<<"t1-t2"<<" "<<t1-t2<<endl;
	cout<<"t1*t2"<<" "<<t1*t2<<endl;
	cout<<"t1/t2"<<" "<<t1/t2<<endl;

}
//ǰ�üӼӣ����üӼӣ�ǰ�ü��������ü���
void Test()
{
	CInt t1(4);
	cout<<"t1:"<<t1<<endl;
	t1++;
	cout<<"t1:"<<t1<<endl;
	t1--;
	cout<<"t1:"<<t1<<endl;
	--t1;
	cout<<"t1:"<<t1<<endl;
	++t1;
	cout<<"t1:"<<t1<<endl;
}
//�����������������
void Test1()
{
	CInt t1(5);
	cin>>t1;
	cout<<t1;
}
int main()
{
	//Creat();
	//Asign();
	//Arithmetic();
	//Test();
	Test1();
	return 0;
}
