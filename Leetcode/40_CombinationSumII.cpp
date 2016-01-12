#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > ret;
		vector<int > combination;
		sort(candidates.begin(), candidates.end());
		combinationSum(candidates, target, ret, combination, 0);
		return ret;
	}

private:
	void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &ret, vector<int> &combination, int begin)
	{
		if (!target)//�Ѿ�������һ����
		{
			ret.push_back(combination);
			return;
		}

		for (int i = begin; i < candidates.size() && target >= candidates[i]; i++)
		{
			if (i == begin || candidates[i] != candidates[i - 1]){//����ı����ˣ���i=0ʱ��i-1��������������
				combination.push_back(candidates[i]);
				combinationSum(candidates, target - candidates[i], ret, combination, i+1);//�ݹ�����
				combination.pop_back();//���ü��ϲ������������򵯳�
			}
			
		}
	}
};

int main()
{

	system("pause");
	return 0;
}