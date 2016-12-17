#include"test.h"
//构造函数
CInt::CInt(int i)
{
	a = i;
	//
	cout<<"CInt(int i)"<<this<<endl;
}
//拷贝构造函数
CInt::CInt(const CInt &i)
{
	a = i.a;
	//cout<<"CInt(CInt &i)"<<this<<endl;
}
//析构函数
CInt::~CInt()
{
	//cout<<"~CInt()"<<this<<endl;
}
void CInt::Print()
{
	cout<<"a="<<a<<endl;
}
//赋值
CInt& CInt:: operator=(const CInt& I)
{
	if(this != &I)
	{
		a =I.a;  
	}
	return *this;
}
//加法
CInt CInt::operator+(const CInt& I)
{
	CInt t(*this);
	t.a = a + I.a;
	return t;
}
//减法
CInt CInt::operator-(const CInt& I)
{
	CInt t(*this);
	t.a = a - I.a;
	return t;
}
//乘法
CInt CInt:: operator*(const CInt& I)
{
	CInt t(*this);
	t.a *=I.a;
	return t;
}
//除法
CInt CInt::operator/(const CInt& I)
{
	CInt t(*this);
	if(I.a != 0)
	{
		t.a = a/I.a;
	}
	return t;

}
//前置加加
CInt& CInt:: operator++()    
{
	++a;
	return *this;
}
//后置加加
CInt CInt::operator++(int)  
{
	CInt t(*this);
	a++;
	return t;
}
//前置减减
CInt& CInt::operator--()
{
	--a;
	return *this;
}
//后置减减
CInt CInt::operator--(int)
{
	CInt t(*this);
	a--;
	return t;
}
//  == 重载
bool CInt::operator==(const CInt& I)
{
	if(a == I.a)
		return true;
	else
		return false;
}
// != 重载
bool CInt::operator!=(const CInt& I)
{
	if(a!= I.a)
		return true;
	else
		return false;
}
// > 重载
bool CInt::operator>(const CInt& I)
{
	if(a >I.a)
		return true;
	else
		return false;
}
// < 重载
bool CInt::operator<(const CInt& I)
{
	if(a <I.a)
		return true;
	else
		return false;
}
// >= 重载
bool CInt::operator>=(const CInt& I)
{
	if(a >=I.a)
		return true;
	else
		return false;
}
// <= 重载
bool CInt::operator<=(const CInt& I)
{
	if(a<=I.a)
		return true;
	else
		return false;
}
// ||重载
bool CInt::operator||(const CInt& I)
{
	if(a)
		return true;
	if(I.a)
		return true;
	else
		return false;
}
// &&重载   &&
bool CInt::operator&&(const CInt& I)
{
	if(a)
	{
		if(I.a)
			return true;	
		else
			return false;
	
	}
	else 
		return false;
}
//输出流运算符的重载
ostream& operator<<(ostream& _cout, const CInt& I)
{
	_cout << I.a;
	return _cout;
}
//输入流运算符的重载
istream& operator>>(istream& _cin, CInt& I)
{
	_cin>>I.a;
	return _cin;
}