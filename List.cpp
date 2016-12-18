//说明：此代码实现的链表是双向链表

#include<iostream>
#include<assert.h>
using namespace std;
//typedef Node<T> Node;
template<typename T>
struct Node
{
	Node(const T& data)
		: _data(data)
		, _pNext(NULL)
		, _pPre(NULL)
	{}

	T _data;            //链表中的数据
	Node<T>* _pNext;    //下一个节点
	Node<T>* _pPre;    //前一个节点
};
template<typename T>
class List
{
public:
	friend ostream& operator<<(ostream& _cout, const List<T>& l);  //重载输出流
	List();              //无参构造函数            
	List(const T arr[], size_t size);   //有参构造函数
	List(const List<T>& l);             //拷贝构造函数
	List<T>& operator=(const List<T>& l);   //赋值重载函数
	~List;                   //析构函数
public:
	bool Empty()const;          //判断链表是否为空         
	void PushBack(const T& data);   //尾插
	void PopBack();                 //尾删
	void PushFront(const T& data);   //头插
	void PopFront();                 //头删
	Node<T>* Find(const T& data);   //查找特定元素
	void Insert(Node<T>* pos, const T& data);        //在特定的位置插入一个元素
	void Erase(Node<T>* pos);                   //删除特定位置的元素
	Node<T>& Front();                           //返回链表中第一个元素
	const Node<T>& Front()const;       
	Node<T>& Back();                            //返回链表中最后一个元素
	const Node<T>& Back()const;
	void Clear();        //清空链表
	size_t Size()const;   //求链表的有效元素个数

	void Print();     //顺序打印
	void Print_L();    //逆序打印  
private:
	Node<T>* BuyNewNode(const T& data);

private:
	Node<T>* _pHead;
	Node<T>* _pTail;
	size_t _size;
};
template<typename T>
ostream& operator<<(ostream& _cout, const List<T>& l);
//构造函数
template<typename T>
List<T>::List()
:_pHead(NULL)
,_pTail(NULL)
,_size(0)
{}
template<typename T>
List<T>::List(const T arr[], size_t size)
:_pHead(NULL)
,_pTail(NULL)
,_size(0)
{
	for(size_t i = 0; i<size; i++)
	{
		PushBack(arr[i]);
	}
}
//拷贝构造函数
template<typename T>
List<T>::List(const List<T>& l)
:_pHead(NULL)
,_pTail(NULL)
,_size(0)
{
	Node<T>* pRet = l._pHead;
	while(pRet)       //注意不要加*，因为Node是自定义的类型，*要进行重载
	{
		PushBack(pRet->_data);
		pRet = pRet->_pNext;
	}
}
//赋值运算符重载
template<typename T>
List<T>&List<T>:: operator=(const List<T>& l)
{
	//对象的链表为空的时候
	if(Empty())
	{
		Node<T>* pCur = l._pHead;
		for(size_t i = 0; i<l._size; i++)
		{
			PushBack(pCur->_data);
			pCur = pCur->_pNext;
		}
	}
	//当前对象的链表长度大于要赋给它的链表长度
	else if(_size>l._size)
	{
		Node<T>* pCur = _pHead;
		Node<T>* pRet = l._pHead;
		//将l._size长度的值赋给对象
		for(size_t i = 0; i<l._size; i++)
		{
			pCur->_data = pRet->_data;
			pCur = pCur->_pNext;
			pRet = pRet->_pNext;
		}

		//将l._size到_size之间的剩余的长度删掉
		for(size_t i = l._size; i<_size; i++)
		{
			PopBack();
		}
	}
	else
	{
		//当前对象的长度小于或等于被赋给它的链表长度
		Node<T>* pCur = _pHead;
		Node<T>* pRet = l._pHead;
		//将长度为_size 的赋值过来就行了
		for(size_t i = 0; i<_size; i++)
		{
			pCur->_data = pRet->_data;
			pCur = pCur->_pNext;
			pRet = pRet->_pNext;
		}
	}
	return *this;
}
template<typename T>
List<T>::~List()
{
	Clear();
}
//判断链表是否为空
template<typename T>
bool List<T>::Empty()const
{
	return (_size == 0);
}
//申请新节点
template<typename T>
Node<T>* List<T>::BuyNewNode(const T& data)
{
	Node<T>* pNew = new Node<T>(data);
	return pNew;
}
//尾插
template<typename T>
void List<T>::PushBack(const T &data)
{
	if(Empty())
	{
		Node<T>* pCur = BuyNewNode(data);
		_pHead = _pTail = pCur;
	}
	else
	{
		Node<T>* pCur = BuyNewNode(data);
		pCur->_pPre = _pTail;
		_pTail->_pNext = pCur;
		_pTail = pCur;
	}
	++_size;
}
//尾删
template<typename T>
void List<T>::PopBack()
{
	if(Empty())
	{
		return;
	}
	else if(_pHead->_pNext == NULL)
	{
		Node<T>* pDel(_pHead);
		_pHead = _pTail = NULL;
		delete pDel;	
	}
	else
	{
		Node<T>* pDel(_pTail);
		_pTail = _pTail->_pPre;
		_pTail->_pNext = NULL;
		delete pDel;
	}
	--_size;
}
//头插
template<typename T>
void List<T>::PushFront(const T& data)
{
	if(Empty())
	{
		Node<T>* pRet = BuyNewNode(data);
		PushBack(pRet->_data);
	}
	else 
	{
		Node<T>* pRet = BuyNewNode(data);
		_pHead->_pPre = pRet;
		pRet->_pNext = _pHead;
		_pHead = pRet;
		
	}
	++_size;
}
//头删
template<typename T>
void List<T>::PopFront()
{
	if(Empty())
	{
		return;
	}
	else if(_pHead->_pNext == NULL)
	{
		Node<T>* pDel = _pHead;
		delete pDel;
		_pHead = _pTail = NULL;
	}
	else if(_pHead->_pNext == NULL)
	{
		delete _pHead;
		_pHead = NULL;
	}
	else
	{
		Node<T>* pDel = _pHead;
		_pHead = _pHead->_pNext;
		delete pDel;
		_pHead->_pPre = NULL;
	}
	--_size;
}
//找特定的元素
template<typename T>
Node<T>*List<T>::Find(const T& data)
{
	if(Empty())
	{
		return NULL;
	}
	else
	{
		Node<T>* pCur = _pHead;
		while(pCur)
		{
			if(pCur->_data == data)
			{
				return pCur;
			}
			pCur = pCur->_pNext;
		}	
	}
	return NULL;
}
//在特定的位置插入元素
template<typename T>
void List<T>::Insert(Node<T>* pos, const T& data)
{
	if(pos == NULL)
	{
		assert(false);
		return;
	}
	else if(pos->_pNext == NULL)
	{
		PushBack(data);
	}
	else
	{
		Node<T>* pCur = BuyNewNode(data);
		pCur->_pPre = pos;
		pCur->_pNext = pos->_pNext;
		pos->_pNext->_pPre = pCur;


		pos->_pNext = pCur;
	}
	++_size;
}
//擦出特定位置的元素
template<typename T>
void List<T>::Erase(Node<T>* pos)
{
	if(Empty())
	{
		return;
	}
	else if(pos->_pNext == NULL)
	{
		pos->_pPre->_pNext = NULL;
	}
	else
	{
		pos->_pPre->_pNext = pos->_pNext;
		pos->_pNext->_pPre = pos->_pPre->_pNext;
	}
	--_size;
}
//返回第一个元素
template<typename T>
Node<T>&List<T>:: Front()
{
	return _pHead;
}
template<typename T>
const Node<T>& List<T>::Front()const
{
	return _pHead;
}
//返回最后一个元素
template<typename T>
Node<T>& List<T>::Back()
{
	return _pTail;
}
template<typename T>
const Node<T>& List<T>::Back()const
{
	return _pTail;
}
//求链表的长度
template<typename T>
size_t List<T>::Size()const
{
	return _size;

}
//清空链表
template<typename T>
void List<T>::Clear()
{
	cout<<"Clear()"<<endl;
	if(Empty())
	{
		return;
	}
	else
	{
		Node<T>* pCur = _pHead;
		while(pCur->_pNext != NULL)
		{
			size_t count = 0;
			Node<T>* pDel = _pTail;
			_pTail = _pTail->_pPre;
			_pTail->_pNext = NULL;
			delete pDel;
			pCur = pCur->_pNext;
			--count;
		}
	}
}
//重载输出运算符
template<typename T>
ostream& operator<<(ostream& _cout, const List<T>& l)
{
	Node<T>* pCur = l._pHead;
	while(pCur)
	{
		cout<<pCur->_data<<endl;
		pCur = pCur->_pNext;
	}
	return _cout;
}
//顺序打印
template<typename T>
void List<T>::Print()
{
	if(Empty())
	{
		return;
	}
	Node<T>* pRet = _pHead;
	while(pRet)
	{
		cout<<pRet->_data<<" ";
		pRet = pRet->_pNext;
	}
}
//逆序打印 
template<typename T>
void List<T>::Print_L()
{
	if(Empty())
	{
		return;
	}
	Node<T>* pRet = _pTail;
	while(pRet)
	{
		cout<<pRet->_data<<" ";
		pRet = pRet->_pPre;
	}
}

//int CheckPODtype(typeid name)
//{
//	int i = 0;
//	int arr[i] = {"int","char","double"};
//	for(size_t i = 0;i<strlen(a)+1; i++)
//	{
//		if(arr[i] == name)
//		{
//			return 1;
//		}
//	}
//	return -1;
//}

/*********************测试函数***********************/
//基本函数的测试
void Funtest1()
{
	int arr[5] = {1,2,3,4,5};
	List<int> l1(arr,3);
	l1.Print();
	List<int> l2(arr,2);
	l2.Print();
	//赋值运算符的重载的测试
	List<int> l3(l1);
	l3 = l2;
	l3.Print();

}
//尾插尾删函数的测试
void Funtest2()
{
	int arr[5] = {1,2,3,4,5};
	List<int> l1(arr,3);
	l1.PushBack(7);
	l1.PushBack(8);
	l1.PushBack(9);
	l1.PushBack(0);
	l1.PushBack(6);
	l1.PushBack(5);

	l1.Print();
	cout<<endl;
	l1.Print_L();
	cout<<endl;
	l1.PopBack();
	l1.PopBack();
	l1.PopBack();

	l1.Print();
}
//头插头删
void Funtest3()
{
	int arr[5] = {1,2,3,4,5};
	List<int> l1(arr,5);
	l1.PushFront(8);
	l1.PushFront(9);
	l1.PushFront(0);
	l1.Print();
	cout<<endl;
	l1.PopFront();
	l1.PopFront();
	l1.Print();
}
//在特定位置插入元素
void Funtest4()
{
	int arr[5] = {1,2,3,4,5};
	List<int> l1(arr,5);
	l1.Insert(l1.Find(2),8);
	l1.Print();
}
//在特定位置擦出元素
void Funtest5()
{
	int arr[5] = {1,2,3,4,5};
	List<int> l1(arr,5);
	l1.Erase(l1.Find(3));
	l1.Erase(l1.Find(4));
	l1.Erase(l1.Find(5));
	l1.Print();
}
//清空链表
void Funtest6()
{
	int arr[5] = {1,2,3,4,5};
	List<int> l1(arr,5);
	l1.Print();
	l1.Clear();
}
int main()
{
	//Funtest1();
	//Funtest2();
	//Funtest3();
	//Funtest4();
	//Funtest5();
	Funtest6();
	/*Funtest7();
	Funtest8();*/
	return 0;
}

