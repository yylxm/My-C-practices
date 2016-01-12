#include <iostream>

using namespace std;
class Temp
{
public:
	Temp(){ ++N; Sum += N; };
	static void Reset(){ N = 0; Sum = 0; }
	static unsigned int GetSum(){ return Sum; }

private:
	static unsigned int N;
	static unsigned int Sum;
};
unsigned int Temp::N = 0;//静态成员变量必须要在类外定义
unsigned int Temp::Sum = 0;
int main()
{
	int n;
	cin >> n;
	Temp::Reset();

	Temp *a = new Temp[n];
	delete[]a;
	a = NULL;
	cout << Temp::GetSum()<< endl;

	system("pause");
	return 0;
}