#include<iostream>
#include<time.h>

using namespace std;

class test
{
	friend test foo(double);
public:
	test(){memset(arr,0,100*sizeof(double));}
private:
	double arr[100];
};

test foo(double val)
{
	test local;

	local.arr[0]=val;
	local.arr[99]=val;

	return local;
}

void printlocaltime(void)
{
	struct tm *timeptr;
	time_t secsnow;

	time(&secsnow);
	timeptr=localtime(&secsnow);
	cout<<"The date is "<<(timeptr->tm_mon)+1<<"-"<<(timeptr->tm_mday)<<"-"<<(timeptr->tm_year)<<endl;
	cout<<"local time is "<<(timeptr->tm_hour)<<"-"<<(timeptr->tm_min)<<"-"<<(timeptr->tm_sec)<<endl;
}

int main()
{
	printlocaltime();
	for(int cnt=0;cnt<10000000;++cnt)
	{test t=foo(double(cnt));}
	printlocaltime();
	system("pause");
	return 0;
}