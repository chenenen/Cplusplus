#ifndef __TEST__
#define __TEST__
#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& _cout,const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date();
	Date(int year,int month,int day);
	Date& operator=(const Date& d);
	Date(const Date& d);
	~Date();
	int Getdaysinmonth(int year,int month);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	
private:
	int _year;
	int _month;
	int _day;

};
#endif



//˵�����ҽ����Ժ����������ŵ�һ��Դ�ļ����������ǲ鿴������ʵ��ִ�е�ʱ�򣬽����Ժ�����һ��Դ�ļ�

#include"test.h"
//���Ի�������;���졣�������졣��ֵ
void test1()
{
	Date d1(2013,4,5);
	Date d2(d1);
	Date d3(d1);
	d3 = d2;
	Date d4(1990,3,5);
}
//��������Ƿ�Ϸ�
void test2()
{
	Date d1;
	cout<<d1.Getdaysinmonth(2000,2)<<endl;
	cout<<d1.Getdaysinmonth(2013,2)<<endl;
}
//���Լ�ȥ����һ������
void test3()
{
	Date d1(2014,5,6);
	d1= d1-30;
	cout<<d1<<endl;
}
//���������������
void test4()
{
	Date d1(2014,3,5);
	Date d2(2014,3,30);
	cout<<d2-d1<<endl;
}
//���ԱȽ�
void test5()
{
	Date d1(2015,6,7);
	Date d2(2015,6,9);
	cout<<(d1<d2)<<endl;
	cout<<(d1>d2)<<endl;
	cout<<(d1==d2)<<endl;
	cout<<(d1!=d2)<<endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}
