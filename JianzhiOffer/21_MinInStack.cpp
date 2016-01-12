#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class StackWithMin
{
public:
	void push(const T& value);
	void pop();
	const T&  min()const;
private:
	stack<T> m_data;
	stack<T> m_min;
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	if(m_min.size()==0 || m_min.top()>value)
	{
		m_min.push(value);
	}
	else
		m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop()
{
	assert(m_data.size()>0 &&m_min.size()>0 );

	m_data.pop();
	m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const
{
	if(m_data.size()>0 && m_min.size()>0 )
		return m_min.top();
	else
		return -1;
}

int main()
{
	StackWithMin<int> S;
	S.push(3);
	S.push(4);
	S.push(2);
	int ret;
	ret=S.min();
	cout<<ret<<endl;
	system("pause");
	return 0;
}