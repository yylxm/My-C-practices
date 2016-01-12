#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct program 
{
	int begin;
	int end;
	bool operator<(const program&a)const{
		return end<a.end;
	}
}buf[100];

int main()
{
	int num;
	vector<program> svec;
	cout<<"Please enter the total number:"<<endl;
	cin>>num;
	cout<<"Please enter the begin time and the end time:"<<endl;
	for(int i=0;i<num;++i)
	{
		scanf("%d%d",&buf[i].begin,&buf[i].end);
	}
	
	sort(buf,buf+num);
	int e;
	for(int i=0;i<num;++i)
	{
		if(i==0)
		{
			svec.push_back(buf[i]);
			e=buf[0].end;
		}
		if(buf[i].begin>=e)
		{
			svec.push_back(buf[i]);
			e=buf[i].end;
		}
	}

	cout<<"Program can see:"<<svec.size()<<endl;;
	system("pause");
	return 0;
}