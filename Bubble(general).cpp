#include<iostream>
using namespace std;
template<typename T>
class Less
{
public:
	bool operator()(T left, T right)
	{
		return left<right;
	}
};
template<typename T>
class More
{
public:
	bool operator()(T left, T right)
	{
		return left>right;
	}
};
template<typename T,class com/* = More*/>//
void BubbleSort(T array[],size_t size)
{
	for(size_t i = 0; i<size-1; i++)
	{
		for(size_t j = 0; j<size-i-1; j++)
		{
			if(com()(array[j],array[j+1]))
			{
				std::swap(array[j],array[j+1]);
			}
		}
	}
}
void Funtest()
{
	int array[5] = {1,4,2,0,6};
	
	BubbleSort<int,More<int>>(array,sizeof(array)/sizeof(array[0]));
	
}
int main()
{
	Funtest();
	return 0;
}