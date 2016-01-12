#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class CQueue
{
public:
	CQueue(){};
	~CQueue(){};
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
};

template<typename T>
T CQueue<T>::deleteHead()
{
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			T temp=stack1.top();
			stack2.push(temp);
			stack1.pop();
		}
	}
	if(stack2.empty())
	{
		throw new exception("queue is empty!\n");
	}

	T head=stack2.top();
	stack2.pop();
	return head;
}


int main()
{

	CQueue<int> queue;
	queue.appendTail(1);
	queue.appendTail(3);
	queue.appendTail(7);
	queue.appendTail(9);

	int ret1;
		ret1=queue.deleteHead();
	int ret2;
		ret2=queue.deleteHead();
	cout<<ret1<<" "<<ret2<<endl;

	system("pause");
	return 0;
}