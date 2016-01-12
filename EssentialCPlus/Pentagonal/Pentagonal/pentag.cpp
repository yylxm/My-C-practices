/*pentagonal数列的求值公式是P(n)=n(3n-1)/2定义一
个函数，将产生的元素放到用户传入的vector中*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int cacl_elem(vector<int>&,int);
void display_elem(const vector<int>&,const string &,ostream &os=cout);
bool check_ok(int);

int main()
{
	vector<int> vec;
	int pos;
	const string title("Pentagonal Numeric Series");
	bool more=true;
	char ch;
	while(more)
	{
        cout<<"Please enter the pos: ";
		cin>>pos;
		cacl_elem(vec,pos);
		display_elem(vec,title);
		cout<<"\nEnter again?(y/n):";
		cin>>ch;
		if(ch!='Y'&&ch!='y')
			more=false;
	}	

	system("pause");
	return 0;
}

inline bool check_ok(int pos)
{
	if(pos<=0||pos>64)
	{
		cerr<<"Sorry. Invalid position: "<<pos<<endl;
		return false;
	}
	else
		return true;
}

int cacl_elem(vector<int> &vec,int pos)
{
	
	if(check_ok(pos))
	{
		for(int ix=vec.size()+1;ix<=pos;++ix)
		{
			vec.push_back(ix*(3*ix-1)/2);
		}
		return 1;
	}
	else
		return 0;
}

void display_elem(const vector<int>&vec,const string &title,ostream &os)
{
	os<<title<<"\n\t";
	for(int ix=0;ix<vec.size();++ix)
		os<<vec[ix]<<" ";
	os<<endl;
}