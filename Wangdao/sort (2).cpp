#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct student
{
	char name[50];
	int age;
	float grade;
}buf[100];

bool cmp(student a,student b)
{
	if(a.grade!=b.grade) return a.grade<b.grade;
	int str=strcmp(a.name,b.name);
	if(!str) return str<0;
	else return a.age<b.age;	
}

int main()
{
	cout<<"Please enter number of the student."<<endl;
	int num;
	cin>>num;
	cout<<"Please enter the massage of the student:"<<endl;
	for(int i=0;i<num;++i)
	{
		cout<<"student"<<i<<endl;
		cout<<"name:";
		cin>>buf[i].name;
		cout<<"age:";
		cin>>buf[i].age;
		cout<<"grade:";
		cin>>buf[i].grade;
	}
	sort(buf,buf+num,cmp);

	for(int i=0;i<num;++i)
	{
		cout<<"student1"<<i<<endl;
		cout<<"name:"<<buf[i].name<<' ';
		cout<<"age:"<<buf[i].age<<' ';
		cout<<"grade:"<<buf[i].grade;
		cout<<endl;
	}
	
	system("pause");
	return 0;
}