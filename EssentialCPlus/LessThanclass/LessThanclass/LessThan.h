class LessThan
{
public:
	LessThan(int val):_val(val){};
	int comp_val()const{return _val;};
	int comp_val(int value){_val=value;};
	bool operator()(int _value)const;
private:
	int _val;
};

