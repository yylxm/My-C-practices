#include <iostream>
#include <stack>

using namespace std;

bool isPopOrder(const int*pPush,const int *pPop,int length)
{
	stack<int> stackdata;
	const int *pNextPush=pPush;
	const int *pNextPop=pPop;
	bool result=false;
	if (pPush!=NULL && pPop!=NULL && length>0)
	{
		while (pNextPop-pPop<length)
		{
			while (stackdata.empty() || stackdata.top()!= (*pNextPop))
			{
				if (pNextPush-pPush==length)
				{
					break;
				}
				else
				{
					stackdata.push(*pNextPush);
					pNextPush++;
				}				
			}
			if (stackdata.top()!= (*pNextPop))
			{
				break;
			}

			stackdata.pop();
			pNextPop++;
		}
		if(stackdata.empty() && pNextPop-pPop==length)
			result=true;
	}
	return result;

}

int main()
{
	int Push[]={1,2,3,4,5};
	int Pop[]={4,5,3,1,2};
	bool ret=isPopOrder(Push,Pop,5);
	if(ret)
		cout<<"yes!"<<endl;
	else
		cout<<"no!"<<endl;
	system("pause");
	return 0;
}