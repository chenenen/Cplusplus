//˵�����˴���ʵ�ֵ�������˫������

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

	T _data;            //�����е�����
	Node<T>* _pNext;    //��һ���ڵ�
	Node<T>* _pPre;    //ǰһ���ڵ�
};
template<typename T>
class List
{
public:
	friend ostream& operator<<(ostream& _cout, const List<T>& l);  //���������
	List();              //�޲ι��캯��            
	List(const T arr[], size_t size);   //�вι��캯��
	List(const List<T>& l);             //�������캯��
	List<T>& operator=(const List<T>& l);   //��ֵ���غ���
	~List;                   //��������
public:
	bool Empty()const;          //�ж������Ƿ�Ϊ��         
	void PushBack(const T& data);   //β��
	void PopBack();                 //βɾ
	void PushFront(const T& data);   //ͷ��
	void PopFront();                 //ͷɾ
	Node<T>* Find(const T& data);   //�����ض�Ԫ��
	void Insert(Node<T>* pos, const T& data);        //���ض���λ�ò���һ��Ԫ��
	void Erase(Node<T>* pos);                   //ɾ���ض�λ�õ�Ԫ��
	Node<T>& Front();                           //���������е�һ��Ԫ��
	const Node<T>& Front()const;       
	Node<T>& Back();                            //�������������һ��Ԫ��
	const Node<T>& Back()const;
	void Clear();        //�������
	size_t Size()const;   //���������ЧԪ�ظ���

	void Print();     //˳���ӡ
	void Print_L();    //�����ӡ  
private:
	Node<T>* BuyNewNode(const T& data);

private:
	Node<T>* _pHead;
	Node<T>* _pTail;
	size_t _size;
};
template<typename T>
ostream& operator<<(ostream& _cout, const List<T>& l);
//���캯��
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
//�������캯��
template<typename T>
List<T>::List(const List<T>& l)
:_pHead(NULL)
,_pTail(NULL)
,_size(0)
{
	Node<T>* pRet = l._pHead;
	while(pRet)       //ע�ⲻҪ��*����ΪNode���Զ�������ͣ�*Ҫ��������
	{
		PushBack(pRet->_data);
		pRet = pRet->_pNext;
	}
}
//��ֵ���������
template<typename T>
List<T>&List<T>:: operator=(const List<T>& l)
{
	//���������Ϊ�յ�ʱ��
	if(Empty())
	{
		Node<T>* pCur = l._pHead;
		for(size_t i = 0; i<l._size; i++)
		{
			PushBack(pCur->_data);
			pCur = pCur->_pNext;
		}
	}
	//��ǰ����������ȴ���Ҫ��������������
	else if(_size>l._size)
	{
		Node<T>* pCur = _pHead;
		Node<T>* pRet = l._pHead;
		//��l._size���ȵ�ֵ��������
		for(size_t i = 0; i<l._size; i++)
		{
			pCur->_data = pRet->_data;
			pCur = pCur->_pNext;
			pRet = pRet->_pNext;
		}

		//��l._size��_size֮���ʣ��ĳ���ɾ��
		for(size_t i = l._size; i<_size; i++)
		{
			PopBack();
		}
	}
	else
	{
		//��ǰ����ĳ���С�ڻ���ڱ���������������
		Node<T>* pCur = _pHead;
		Node<T>* pRet = l._pHead;
		//������Ϊ_size �ĸ�ֵ����������
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
//�ж������Ƿ�Ϊ��
template<typename T>
bool List<T>::Empty()const
{
	return (_size == 0);
}
//�����½ڵ�
template<typename T>
Node<T>* List<T>::BuyNewNode(const T& data)
{
	Node<T>* pNew = new Node<T>(data);
	return pNew;
}
//β��
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
//βɾ
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
//ͷ��
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
//ͷɾ
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
//���ض���Ԫ��
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
//���ض���λ�ò���Ԫ��
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
//�����ض�λ�õ�Ԫ��
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
//���ص�һ��Ԫ��
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
//�������һ��Ԫ��
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
//������ĳ���
template<typename T>
size_t List<T>::Size()const
{
	return _size;

}
//�������
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
//������������
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
//˳���ӡ
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
//�����ӡ 
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

/*********************���Ժ���***********************/
//���������Ĳ���
void Funtest1()
{
	int arr[5] = {1,2,3,4,5};
	List<int> l1(arr,3);
	l1.Print();
	List<int> l2(arr,2);
	l2.Print();
	//��ֵ����������صĲ���
	List<int> l3(l1);
	l3 = l2;
	l3.Print();

}
//β��βɾ�����Ĳ���
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
//ͷ��ͷɾ
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
//���ض�λ�ò���Ԫ��
void Funtest4()
{
	int arr[5] = {1,2,3,4,5};
	List<int> l1(arr,5);
	l1.Insert(l1.Find(2),8);
	l1.Print();
}
//���ض�λ�ò���Ԫ��
void Funtest5()
{
	int arr[5] = {1,2,3,4,5};
	List<int> l1(arr,5);
	l1.Erase(l1.Find(3));
	l1.Erase(l1.Find(4));
	l1.Erase(l1.Find(5));
	l1.Print();
}
//�������
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

