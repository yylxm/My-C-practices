#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<set>

using namespace std;

void initialize_exclusion_word(set<string>&);
void display(map<string,int>);
void process_text(map<string,int>,set<string>&,ifstream &);
void user_query(const map<string,int>&);
void display(const map<string,int>&,ofstream &);

int main()
{
	ifstream input_file("input_file.txt");
	ofstream output_file("output_file.txt");
	if(!input_file||!output_file)
	{
		cerr<<"!Oop,unable to open the necessary files.\n";
		return -1;
	}

	set<string > exclude_word;
	initialize_exclusion_word(exclude_word);

	map<string,int> word_count;
	process_text(word_count,exclude_word,input_file);
	user_query(word_count);
	display(word_count,output_file);

	return 0;
}

void initialize_exclusion_word(set<string>& vec)
{
	static string exclusion_word[]={
	"the","but","or","and","a",
	"an","are","is","were","of"};
	vec.insert(exclusion_word,exclusion_word+10);
}

void process_text(map<string,int> word_count,set<string> &exclusion_word,ifstream &input_file)
{
	string word;
	while(input_file>>word)
	{
		if(exclusion_word.count(word))
			continue;
		word_count[word]++;
	}
}

void user_query(const map<string,int> &word_count)
{
	string search_word;
	cout<<"Please enter the word want to search:q to quit\n";
	cin>>search_word;
	while(search_word.size()&&search_word!="q")
	{
		map<string,int >::const_iterator iter;
		if((iter=word_count.find(search_word))!=word_count.end())
			cout<<"Found!"<<iter->first
			<<" occurs "<<iter->second<<" times.\n";
		else 
			cout<<search_word<<" was't found!\n";
		cout<<"\n Another search?(q to quit)";
		cin>>search_word;
	}
}

void display(const map<string,int>& word_count,ofstream &os)
{
	map<string,int>::const_iterator iter;
	for(iter=word_count.begin();iter!=word_count.end();++iter)
	{
		os<<iter->first<<"("
			<<iter->second<<")"<<endl;
	}
	os<<endl;
}