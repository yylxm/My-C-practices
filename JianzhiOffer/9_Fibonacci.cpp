#include <iostream>

using namespace std;

/* µÝ¹éÐ§ÂÊµÍ
int Fibonacci(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	return Fibonacci(n-1)+Fibonacci(n-2);
}*/

long long Fibonacci(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	long long one=0;
	long long two=1;
	long long N=0;
	for(int i=2 ;i<=n ;++i)
	{
		N=one + two;
		one=two;
		two=N;
	}
	return N;
}

int main()
{
	int n;
	cin>>n;
	long long ret=Fibonacci(n);
	cout<<ret<<endl;
	system ("pause");
	return 0;
}
