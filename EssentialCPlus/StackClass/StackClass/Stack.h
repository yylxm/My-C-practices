#include<string>
#include<vector>
using namespace std;

class Stack
{
public:
	bool push(const string &);
	bool pop(string &elem);
	bool peek(string &elem);
	bool empty();
	bool full();
	int size(){return stack.size();}
	bool find(const string &elem)const;
	int count(const string &elem)const;
private:
	vector<string> stack;
};