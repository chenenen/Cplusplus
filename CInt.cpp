#include"test.h"
//���캯��
CInt::CInt(int i)
{
	a = i;
	//
	cout<<"CInt(int i)"<<this<<endl;
}
//�������캯��
CInt::CInt(const CInt &i)
{
	a = i.a;
	//cout<<"CInt(CInt &i)"<<this<<endl;
}
//��������
CInt::~CInt()
{
	//cout<<"~CInt()"<<this<<endl;
}
void CInt::Print()
{
	cout<<"a="<<a<<endl;
}
//��ֵ
CInt& CInt:: operator=(const CInt& I)
{
	if(this != &I)
	{
		a =I.a;  
	}
	return *this;
}
//�ӷ�
CInt CInt::operator+(const CInt& I)
{
	CInt t(*this);
	t.a = a + I.a;
	return t;
}
//����
CInt CInt::operator-(const CInt& I)
{
	CInt t(*this);
	t.a = a - I.a;
	return t;
}
//�˷�
CInt CInt:: operator*(const CInt& I)
{
	CInt t(*this);
	t.a *=I.a;
	return t;
}
//����
CInt CInt::operator/(const CInt& I)
{
	CInt t(*this);
	if(I.a != 0)
	{
		t.a = a/I.a;
	}
	return t;

}
//ǰ�üӼ�
CInt& CInt:: operator++()    
{
	++a;
	return *this;
}
//���üӼ�
CInt CInt::operator++(int)  
{
	CInt t(*this);
	a++;
	return t;
}
//ǰ�ü���
CInt& CInt::operator--()
{
	--a;
	return *this;
}
//���ü���
CInt CInt::operator--(int)
{
	CInt t(*this);
	a--;
	return t;
}
//  == ����
bool CInt::operator==(const CInt& I)
{
	if(a == I.a)
		return true;
	else
		return false;
}
// != ����
bool CInt::operator!=(const CInt& I)
{
	if(a!= I.a)
		return true;
	else
		return false;
}
// > ����
bool CInt::operator>(const CInt& I)
{
	if(a >I.a)
		return true;
	else
		return false;
}
// < ����
bool CInt::operator<(const CInt& I)
{
	if(a <I.a)
		return true;
	else
		return false;
}
// >= ����
bool CInt::operator>=(const CInt& I)
{
	if(a >=I.a)
		return true;
	else
		return false;
}
// <= ����
bool CInt::operator<=(const CInt& I)
{
	if(a<=I.a)
		return true;
	else
		return false;
}
// ||����
bool CInt::operator||(const CInt& I)
{
	if(a)
		return true;
	if(I.a)
		return true;
	else
		return false;
}
// &&����   &&
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
//����������������
ostream& operator<<(ostream& _cout, const CInt& I)
{
	_cout << I.a;
	return _cout;
}
//�����������������
istream& operator>>(istream& _cin, CInt& I)
{
	_cin>>I.a;
	return _cin;
}