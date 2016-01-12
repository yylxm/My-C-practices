#include<vector>

using namespace std;

bool is_size_ok(int size);

const vector<int>* fibon_seq(int size);
const vector<int>* lucas_seq(int size);
const vector<int>* pell_seq(int size);
const vector<int>* triang_seq(int size);
const vector<int>* square_seq(int size);
const vector<int>* pentagonal_seq(int size);


bool seq_elem(int pos,int &elem);

const int seq_cnt=6;
extern const vector<int>* (*seq_array[seq_cnt])(int);