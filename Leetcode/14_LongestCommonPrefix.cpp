#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

		if(strs.size()==0) return "";//Îª¿ÕÔòÊä³ö¿Õ
		int Maxlength=strs[0].size();
		for(auto iter=strs.begin();iter!=strs.end()-1;++iter)
		{			
			auto iter1=iter+1;
			int length=0;
			for(int j=0; j<(*iter).size();++j)
			{				
				if((*iter)[j]==(*iter1)[j])
				{ 
					length++;
				}
				else
				{
					break;
				}
			}
			if(length<Maxlength)
					Maxlength=length;

		}

		return strs[0].substr(0,Maxlength);
    }
};

int main()
{
	string arr[]={"my_date","my_daay","my_day","my_dmonth","my_dyear","my_dmouse"};
	//string arr[]={};
	vector<string> svec(arr,arr+6);
	//vector<string> svec;
	Solution s;
	string ret;
	ret=s.longestCommonPrefix(svec);
	cout<<ret<<endl;
	system("pause");
	return 0;
}