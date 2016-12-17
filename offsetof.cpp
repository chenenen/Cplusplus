#include<iostream>
using namespace std;
#define offsetof(s,m) (size_t) &(((s*)0)->m)
struct N
{
	int i;
	char j;
	double k; 
};
int main()
{
	cout<<offsetof(N,j)<<endl;
	return 0;
}