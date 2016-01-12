#include"Stack.h"
#include<algorithm>

bool Stack::empty()
{
	return stack.empty();
}

bool Stack::pop(string &elem)
{
	if(empty())
	{
		return false;
	}
	elem=stack.back();
	stack.pop_back();
	return true;
}

bool Stack::push(const string &elem)
{
	if(full())
	{
		return false;
	}
	stack.push_back(elem);
	return true;
}

bool Stack::peek(string &elem)
{
	if(empty())
		return false;
	elem=stack.back();
	return true;
}

bool Stack::full()
{
	return stack.size()==stack.max_size();
}

bool Stack::find(const string &elem)const
{
	vector<string>::const_iterator end_iter=stack.end();
	return ::find(stack.begin(),end_iter,elem)!=end_iter;
}

int Stack::count(const string &elem)const
{
	return ::count(stack.begin(),stack.end(),elem);
}

