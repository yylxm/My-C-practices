#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
bool is_leap(int);

int date[30001][13][32];
int dayofmonth[13][2]={
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};

struct Date{
public:
	int year;
	int month;
	int day;
	void nextday()
	{
		day++;
		if(day>dayofmonth[month][is_leap(year)])
		{
			day=1;
			month++;
			if(month>12)
			{
				month=1;
				year++;
			}
		}
	}	
};

bool is_leap(int year)
{
	if (year%100!=0&&year%4==0||year%400==0)
	{
		return true;
	}
	return false;

}

int abs(int x)
{
	return x>0? x : -x;
}

int main()
{
	Date date1;
	date1.day=1;
	date1.month=1;
	date1.year=0;
	int cnt=0;
	while (date1.year!=3001)
	{
		date[date1.year][date1.month][date1.day]=cnt;
		date1.nextday();
		cnt++;
	}
	int y1,m1,d1;
	int y2,m2,d2;
	cout<<"please enter two date:"<<endl;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		cout<<"The result is ";
		cout<<abs(date[y2][m2][d2]-date[y1][m1][d1]+1)<<endl;
	}
    
	system("pause");
	return 0;
}