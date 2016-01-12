#include<iostream>

#include"Stack.h"

using namespace std;

int main()
{
	Stack st;
	string str;

	while(cin>>str&&!st.full())
		st.push(str);

	if(st.empty())
	{
		cout<<"\nOop: no strings were read -- bailing out\n";
		return 0;
	}

	st.peek(str);

	if(st.size()==1&&str.empty())
	{
		cout<<"\nOop: no strings were read -- bailing out\n";
		return 0;
	}

	/*cout<<"\nRead in "<<st.size()<<" strings!\n"
		<<"The strings,in reserve order:\n";
	while(st.size())
		if(st.pop(str))
			cout<<str<<" ";*/

	cout<<"\nThere are now "<<st.size()
		<<" elements in the stack!\n";

	cin.clear();
	cout<<"what word to search for?";
	cin>>str;

	bool found=st.find(str);
	int count=found?st.count(str):0;

	cout<<str<<(found?" is ":" isn't ")<<"in the stack. ";
	if(found)
		cout<<"It occurs "<<count<<" times\n";


	system("pause");
	return 0;
}