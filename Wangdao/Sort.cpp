#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lessthan(const int &a,const int &b)
{
	return a<b;
}


/*冒泡排序*/
void Bubblesort(vector<int> &ivec)
{
	int tmp;
	for (int i=0;i<ivec.size()-1;++i)
	{
		for(int j=0;j<ivec.size()-i-1;++j)
		{
			if(ivec[j]>ivec[j+1])
			{
				tmp=ivec[j];
				ivec[j]=ivec[j+1];
				ivec[j+1]=tmp;
			}
		}
	}
}

/*调用STL函数排序*/
void Stlsort(vector<int> &ivec)
{
	sort(ivec.begin(),ivec.end(),lessthan);
}

/*简单直接排序*/
void Selectsort(vector<int> &ivec)
{
	int min,mark,tmp,i,j;
	for(i=0;i<ivec.size()-1;++i)
	{
		min=ivec[i];
		mark=i;
		for(j=i+1;j<ivec.size();++j)
		{
			if(ivec[j]<min)
			{
				mark=j;
				min=ivec[j];
			}
		}
		if (i!=mark)
		{
			tmp=ivec[i];
			ivec[i]=ivec[mark];
			ivec[mark]=tmp;
		}
	}
}



/*快速排序*/
void Quicksort(vector<int> &ivec,int first,int end)
{
	while(first>=end)
	{
		return ;
	}
	int low=first;
	int high=end;
	int middle=ivec[low];
	while (low<high)
	{
		while (middle<=ivec[high]&&low<high)
		{
			high--;
		}
		ivec[low]=ivec[high];
		while (middle>=ivec[low]&&low<high)
		{
			low++;
		}
		ivec[high]=ivec[low];
	}
	ivec[low]=middle;
	Quicksort(ivec,first,low-1);
	Quicksort(ivec,low+1,end);
}

int main()
{
	int n,num;
	vector<int > ivec;
	cout<<"Please enter n:"<<endl;
	cin>>n;
	cout<<"Please enter number:"<<endl;
	while(n>0)
	{
		cin>>num;
		ivec.push_back(num);
		n--;
	}

	//cout<<"Stlsort:"<<endl;
	//Stlsort(ivec);

	//cout<<"Bubblesort:"<<endl;
	//Bubblesort(ivec);

	//cout<<"Selectsort:"<<endl;
	//Selectsort(ivec);

	cout<<"Quicksort:"<<endl;
	Quicksort(ivec,0,ivec.size()-1);

	for (auto iter=ivec.begin();iter!=ivec.end();++iter)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;

	system("pause");
	return 0;

}