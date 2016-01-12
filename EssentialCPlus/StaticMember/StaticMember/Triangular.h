#include<vector>
using namespace std;

class Triangular
{
public:
	//Triangular(int len){len=length;};
	friend class Triangular_iterator;
	static bool is_elem(int);
	static void gen_elements(int length);
	static void gen_elems_to_value(int value);
	//static void display(int length,int beg);
	//friend int Triangular_iterator::operator*();
	//friend void Triangular_iterator::check_integrity();
private:
	static const int _max_elems;
	static vector<int> _elems;
	//int length;
};