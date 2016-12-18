#include<iostream>
#include<assert.h>
using namespace std;
template<typename T>
class Vector
{
public:
	Vector();
	Vector(T arr[],size_t size);
	Vector(const Vector& v);
	Vector<T>& operator=(const Vector& v);
	~Vector();

	void CheckCapacity();
	void PushBack(const T& data);
	void PopBack();
	void Insert(size_t pos,const T& data);

	void Erase(size_t pos);
	int Find(const T& data)const;
	size_t size()const;
	size_t Cacapity()const;

	T&operator[](size_t size);
	const T&operator[](size_t size)const;

	T& Front();
	const T&Front()const;
	T& Back();
	const T&Back()const;

	void Clear();
	void Resize(size_t size,const T& data);

	void Print();

private:
	T *_data;
	size_t _capacity;
	size_t _size;
};


//构造函数
template<typename T>
Vector<T>::Vector()
:_data(new T[3])
,_capacity(3)
,_size(0)
{}
template<typename T>
Vector<T>::Vector(T arr[],size_t size)
:_size(size)
,_capacity (size)
,_data(new T[size])
{
	//memcpy(_data,arr,sizeof(T)*size);
	for(size_t i = 0; i<size;i++)
	{
		_data[i] = arr[i];
	}
}
//拷贝构造函数
template<typename T>
Vector<T>::Vector(const Vector& v)
:_data(new T[v._size])
,_size(v._size)
,_capacity(v._size)
{
	for(size_t i = 0;i<_size;i++)
	{
		_data[i] = v._data[i];
	}
}
//赋值运算符重载函数
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& v)
{
	if(this != &v)
	{
		T* temp = new T[v._capacity];
		for(size_t i= 0; i<_size; i++)
		{
			temp[i]= v._data[i];  //注意
		}
		delete _data;
		_data = temp;
		_capacity = v._capacity;
		_size = v._size;
		
	}
	return *this;
}

//析构函数
template<typename T>
Vector<T>::~Vector()
{
	if(_data != NULL)
	{
		delete[]_data;
	}
}
//检查是否有空间（扩容）
template<typename T>
void Vector<T>::CheckCapacity()
{
	if(_size>=_capacity)
	{
		T* temp = new T[_capacity*2];
		for(size_t i = 0; i<_size; i++)
		{
			temp[i] = _data[i];
		}
		delete _data;
		_data = temp;
		_capacity = _capacity*2;
		
	}
}
//尾插
template<typename T>
void Vector<T>::PushBack(const T &data)
{
	CheckCapacity();
	_data[_size] = data;
	++_size;
}
//尾删
template<typename T>
void Vector<T>::PopBack()
{
	if(_size != 0)
	--_size;
}
//在特定位置插入数据
template<typename T>
void Vector<T>::Insert(size_t pos,const T& data)
{
	CheckCapacity();
	for(size_t i = _size-1; i >=pos; i--) //记得要加=
	{
		_data[i+1] = _data[i];
	}
	_data[pos] = data;
	++_size;
}
//擦出特定位置的元素
template<typename T>
void Vector<T>::Erase(size_t pos)
{
	assert(pos);
	for(size_t i = pos; i<_size; i++)
	{
		_data[i] = _data[i+1];
	}
	--_size;
}
//查找特定位置的元素
template<typename T>
int Vector<T>::Find(const T& data)const
{
	for(size_t i = 0; i<_size; i++)
	{
		if(_data[i] == data)
		{
			return 1;
		}
	}
	return -1;
}

//求有效元素的个数	
template<typename T>
size_t Vector<T>::size()const
{
	return _size;
}
//求总容量的大小
template<typename T>
size_t Vector<T>::Cacapity()const
{
	return _capacity;
}
//重载下标运算符
template<typename T>
T&Vector<T>::operator[](size_t size)
{
	return _data[size];
}
template<typename T>
const T&Vector<T>::operator[](size_t size)const
{
	return _data[size];
}
//返回第一个元素
template<typename T>
T& Vector<T>::Front()
{
	return _data[0];
}
template<typename T>
const T& Vector<T>::Front()const
{
	return _data[0];
}
//返回最后一个元素
template<typename T>
T& Vector<T>::Back()
{
	return _data[_size-1];
}
template<typename T>
const T&Vector<T>::Back()const
{
	return _data[_size-1];
}
//清空顺序表
template<typename T>
void Vector<T>::Clear()
{
	_size = 0;
}
//重置容器类的大小
template<typename T>
void Vector<T>::Resize(size_t size,const T& data)
{
	if(_size>size)
	{
		_size = size;
	}
	else
	{
		T temp = _size;
		_size = size;
		CheckCapacity();
		for(size_t i = temp; i<size; i++)
		{
			_data[i] = data;
		}
	}
}
//打印函数
template<typename T>
void Vector<T>::Print()
{
	for(size_t i=0; i<_size; i++)
	{
		cout<<_data[i]<<endl;
	}
}
/****************************测试函数****************************/
//基本函数的测试
//template<typename T>
void Funtest1()
{
	int arr[5] = {1,2,3,4,5};
	Vector<int> v1(arr,3);
	v1.Print();

	Vector<int> v2(v1);
	v2.Print();

	Vector<int> v3(arr,4); 
	Vector<int> v4(v1);
	v4 = v3;
	v3.Print();
	v4.Print();
}
//尾插，尾删
void Funtest2()
{
	int arr[5] = {0};
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.Print();

	v.PopBack();
	v.PopBack();
	v.PopBack();
	v.Print();
}

//测试在特定位置插入元素
void Funtest3()
{
	int arr[5] = {1,2,3,4,5};
	Vector<int>v1(arr,4);
	v1.Insert(2,8);
	v1.Print();
}
//在特定位置擦出元素
void Funtest4()
{
	int arr[5] = {1,2,3,4,5};
	Vector<int> v1(arr,5);
	v1.Erase(1);
	v1.Print();
}

//查找特定位置的元素
void Funtest5()
{
	int arr[5] = {1,2,3,4,5};
	Vector<int> v1(arr,5);
	cout<<v1.Find(2)<<endl;
}
//测试容器类的有效元素的个数
void Funtest6()
{
	int arr[5] = {1,2,3,4,5};
	Vector<int> v1(arr,5);
	cout<<v1.size()<<endl;
}
//测试容器类的总容量
void Funtest7()
{
	int arr[5] = {1,2,3,4,5};
	Vector<int> v1(arr,3);
	cout<<v1.Cacapity()<<endl;
}
//测试返回第一个元素和返回最后一个元素
void Funtest8()
{
	int arr[5] = {1,2,3,4,5};
	Vector<int> v1(arr,4);
	cout<<v1.Front()<<endl;
	cout<<v1.Back()<<endl;
}
//测试重置容器类大小的函数
void Funtest9()
{
	int arr[5] = {1,2,3,4,5};
	Vector<int> v1(arr,4);
	v1.Resize(2,3);
	v1.Print();
	cout<<endl;
	v1.Resize(8,9);
	v1.Print();
	
}
int main()
{
	//Funtest1();	
	//Funtest2();
	//Funtest3();
	//Funtest4();
	//Funtest5();
	//Funtest6();
	//Funtest7();
	//Funtest8();
	Funtest9();
	return 0;
}