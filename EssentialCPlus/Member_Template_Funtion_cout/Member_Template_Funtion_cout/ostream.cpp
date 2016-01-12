#include<iostream>
#include<string>
using namespace std;

class PrintIt
{
public:
	PrintIt(ostream &os):_os(os){}
    template<typename elemtype>
    void print(const elemtype &elem,char delimiter='\n')
    {
		_os<<elem<<delimiter;
    }
private:
	ostream &_os;
};

int main()
{
	PrintIt standard_out(cout);
	standard_out.print("hello");
	standard_out.print(1024);

	string my_string("My string.");
	standard_out.print(my_string);

	system("pause");
	return 0;
}