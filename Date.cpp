#include"test.h"
//构造函数
Date::Date()
{}
Date::Date(int year=2000,int month=1,int day=1)
{
	_year = year;
	_month = month;
	_day = day;
	if((year<2000) || 
		(month<=0) && (month>13) ||
		(day<0) && (day>Getdaysinmonth(year,month)))
	{
		cout<<"输入不合法，请重新输入："<<endl;
		//cin>>"year:">>year>>"month:">>month>>"day:">>day>>endl;
	}
	else
	{
		cout<<"year: "<<year<<"month: "<<month<<"day: "<<day<<endl;
	}
}
//让天数合法化
int Date::Getdaysinmonth(int year,int month)
{
	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if((((year%4==0) && (year%100 != 0))
		|| (year%400 == 0))&&(month == 2))
	{
		days[month] = 29;
	}
	
	return days[month];

}
//拷贝构造函数
Date::Date(const Date &d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
//赋值运算符重载
Date& Date::operator=(const Date&d)
{
	if(this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
Date::~Date()
{
	cout<<"已被析构！"<<endl;
}
//减去一个任意天数
Date Date::operator-(int days)
{
	if(days<0)
	{
		days = 0-days;
	}
	Date temp(*this);
	temp._day-=days;
	while(temp._day<0)
	{
		if(temp._month == 1)
		{
			temp._month = 12;
			temp._day += 31;
		}
		else
		{
			--temp._month;
			temp._day += Getdaysinmonth(_year,temp._month);
		}
		
	}
		return temp;
}
//两个天数相减
int Date::operator-(const Date& d)
{
	Date mindate(*this);
	Date maxdate(d);
	int count = 0;
	if(mindate>maxdate)
	{
		std::swap(mindate,maxdate);
	}
	while(mindate<maxdate)
	{
		(mindate._day)++;
		count++;
	}
	return count;
}
//天数的前置加加
Date& Date::operator++()
{
	++_day;
	return *this;

}
//天数的后置加加
Date Date::operator++(int)
{
	Date temp(*this);
	temp._day = temp._day+1;
	//temp++;
	return temp;
}
//比较日期
bool Date:: operator>(const Date& d)
{
	return ((_year>d._year)||
		((_year == d._year)&&(_month>d._month))||
		((_year == d._year)&&(_month==d._month)&&(_day>d._day)));
		
}
bool Date::operator<(const Date& d)
{
	return ((_year<d._year)||
		((_year == d._year)&&(_month<d._month))||
		((_year == d._year)&&(_month==d._month)&&(_day<d._day)));
}
bool Date::operator==(const Date& d)
{
	return ((_year == d._year) && 
		(_month == d._month) &&
		(_day == d._day));
}
bool Date::operator!=(const Date& d)
{
	//return !(bool operator==(d));
	return ((_year!=d._year)||
		((_year == d._year)&&(_month!=d._month))||
		((_year == d._year)&&(_month==d._month)&&(_day!=_day)));
}
ostream& operator<<(ostream& _cout,const Date& d)
{
	_cout<<d._year<<" "<<d._month<<" "<<d._day;
	return _cout;
}
istream& operator>>(istream& _cin,Date& d)
{
	_cin>>d._year>>d._month>>d._day;
	return _cin;
}
