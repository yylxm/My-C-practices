#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

template <typename elemtype>
elemtype *find(elemtype *first,elemtype *last,const elemtype &value)
{
	if(!first||!last)
		return 0;
	for(;first!=last;++first)
		if(*first==value)
		{
				cout<<"Ok!,the value is:"<<*first<<endl;
				return first;
		}
	return 0;
}

/*打印容器中的内容*/
template <typename elemtype>
void display(const vector<elemtype> &vec,ostream &os)
{
	vector<elemtype>::const_iterator iter=vec.begin();
	vector<elemtype>::const_iterator end_iter=vec.end();
	for(;iter!=end_iter;++iter)
		os<<*iter<<" ";
	os<<endl;
}

/*绑定参数，容器复制操作*/
template<typename InputIter,typename OutputIter,typename ElemType,typename Comp>
OutputIter filter(InputIter first,InputIter last,OutputIter at,ElemType &val,Comp pred)
{
	while((first=find_if(first,last,bind2nd(pred,val)))!=last)
	{
		cout<<"found value: "<<*first<<endl;
		*at++=*first++;
	}
	return at;
}

int main()
{
	int ia[8]={1,1,2,3,5,8,13,21};
	double da[6]={1.5,2.0,2.5,3.0,3.5,4.0};
	string sa[4]={"jdiosa","name","is","Lucy"};
	vector<int> ivec(ia,ia+8);

	int *pi=find(ia,ia+8,ia[3]);
	double *pd=find(da,da+6,da[3]);
	string *ps=find(sa,sa+4,sa[3]);
	
	const int elem_size=8;
	int a[elem_size]={12,8,43,0,6,21,3,7};
	vector<int> ivec1(a,a+elem_size);
	int ac[elem_size];
	vector<int> ivec2(ac,ac+elem_size);

	cout<<"filtering integer array for values less than 8\n";
	filter(a,a+elem_size,ac,elem_size,less<int>());

	cout<<"filtering integer vector for values greater than 8\n";
	filter(ivec1.begin(),ivec1.end(),ivec2.begin(),elem_size,greater<int>());

	display(ivec,cout);
	system("pause");
	return 0;
}