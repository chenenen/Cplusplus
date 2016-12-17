#include<iostream>
using namespace std;
class String
{
public:
	String(const char*ptr = "") 
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
	{
		_ptr = new char[strlen(s._ptr)+1];
		strcpy(_ptr,s._ptr);
	}
	
	String& operator=(const String&s)
	{
		/*String ptemp = new char[strlen(s._ptr)+1];
		strcpy(ptemp,s._ptr);
		delete[]_ptr;
		_ptr = ptemp;
		return *this;*/
		if(this != &s)
		{
			delete[]_ptr;
			_ptr = new char[strlen(s._ptr)+1];
			strcpy(_ptr,s._ptr);
		}
		return *this;
	}
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
	String s1("hello");
	String s2(s1);
	String s3(s1);
	s3 = s1;
}
int main()
{
	Funtest();
	return 0;
}
