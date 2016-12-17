#include<iostream>
using namespace std;
class String
{
public:
	String(const char* ptr = "")
	{
		if(ptr == NULL)
		{
			_ptr = new char[1];
			_ptr = '\0';
		}
		else
		{
			_ptr = new char[strlen(ptr)+1];
			strcpy(_ptr,ptr);
		}
	}
	String(const String& s)
		:_ptr(NULL)
	{
		String temp(s._ptr);
		std::swap(_ptr,temp._ptr);
	}

	//赋值函数的三个简洁版本
	String& operator=(const String& s)
	{
		if(this != &s)
		{
			String temp(s);
			swap(_ptr,temp._ptr);
		}
		return *this;
	}/*
	String& operator=(const String& s)
	{
		if(this != &s)
		{
			String temp(s._ptr);
			swap(_ptr,temp._ptr);
		}
		return *this;
	}
	String& operator=(String temp)
	{
		swap(_ptr,temp._ptr);
		return *this;
	}*/
	~String()
	{
		if(_ptr == NULL)
		{
			return;
		}
		else
		{
			delete[]_ptr;
			_ptr = NULL;
		}
	}
private:
	char* _ptr;
};
void Funtest()
{
	String s1("avcdfg");
	String s2(s1);
	String s3(s1);
	s3 = s2;
}
int main()
{
	Funtest();
	return 0;
}