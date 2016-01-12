#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
/*text�ı��洢�����棬ע��򿪺͹ر��ļ���ʱ�����簴�տα�����ᵼ���޷�����*/
int main()
{
	ifstream in_file("C:\\Users\\yanyan\\Desktop\\text.txt");
	if (!in_file)
	{
		cerr<<"oops! unable to open output file\n";
		system("pause");
		return -1;
	}
	
	string word;
	vector<string> text;
	while(in_file>>word)
		 text.push_back(word);

	int ix;
	cout<<"unsorted text:\n";
	for(ix=0;ix<text.size();++ix)
		cout<<text[ix]<<' ';
	cout<<endl;

	sort(text.begin(),text.end());

    ofstream out_file("C:\\Users\\yanyan\\Desktop\\text.txt");
	if (!out_file)
	{
		cerr<<"oops! unable to open output file\n";
		system("pause");
		return -2;
	}
	out_file<<"sorted text:\n";
	for(ix=0;ix<text.size();++ix)
		out_file<<text[ix]<<' ';
	cout<<endl;

    system("pause");
	return 0;
}