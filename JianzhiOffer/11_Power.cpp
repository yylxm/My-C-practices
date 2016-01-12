#include <iostream>

using namespace std;

bool InvalidInput = false;

bool equal(double a,double b)//判断两个小数是否相等，由于存在精度问题，故不能直接采用“==”判断
{
	if((a-b)<-0.0000001 && (a-b)>0.0000001)
		return true;
	else
		return false;
}

double PowerWithUnsignedExponent(double base,double exponent)
{
	double ret=0.0;
	for(int i =1 ; i<= exponent ;++i)
	{
		ret=base*base;
	}
	return ret;
}



double Power(double base,int exponent)
{
	InvalidInput = false;

	if(equal(base,0.0)&&exponent<0)
	{
		InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int )exponent;
	if(exponent<0) 
		absExponent=(unsigned int )(-exponent);

	double ret = PowerWithUnsignedExponent(base,absExponent);
	if(exponent<0)
		ret=1.0/ret;
	return ret;

}


 
int main()
{
	double base;
	int exp;
	cin>>base>>exp;
	double ret = Power(base,exp);
	cout<<ret<<endl;
	system("pause");
	return 0;
}