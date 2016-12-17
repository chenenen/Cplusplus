//操作符重载的实现
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


//说明：读者将下面的测试代码放在另一个文件中会比较好，我这里是为了读者方便查看

//创建对象的测试
void Creat()
{
	CInt t1(10);
	CInt t2(t1);
	t1.Print();
	t2.Print();
}
//赋值的测试
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
//四则运算的测试：+ - * /
void Arithmetic()
{
	CInt t1(8);
	CInt t2(4);

	cout<<"运算前："<<endl;
	cout<<"t1:"<<t1<<endl;
	cout<<"t2:"<<t2<<endl;

	cout<<"运算后："<<endl;

	cout<<"t1+t2"<<" "<<t1+t2<<endl;
	cout<<"t1-t2"<<" "<<t1-t2<<endl;
	cout<<"t1*t2"<<" "<<t1*t2<<endl;
	cout<<"t1/t2"<<" "<<t1/t2<<endl;

}
//前置加加，后置加加，前置减减，后置减减
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
//测试输出流和输入流
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
