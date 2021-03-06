#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct pair0
{
	pair0() {}
	pair0(int i0, int j0) { i = i0; j = j0; }
	int i;
	int j;
};
class Solution
{
private:
	vector<vector<int> > flagMap;
	queue<pair0> que;
	stack<pair0> sta;
	int l, sb;

	void separate(vector<vector<int> > &A)
	{
		int i, j;
		bool flag = false;
		for (i = 0; i<l; i++)
			for (j = 0; j<l; j++)
			{
				if (A[i][j] == 1 && flagMap[i][j] == 0)
				{
					dfsForSeparate(A, i, j, flag);
					if (!flag)
						flag = true;
					else
						return;
				}
			}
	}

	void dfsForSeparate(vector<vector<int> > &A, int i0, int j0, bool id)
	{
		pair0 p;
		sta.push(pair0(i0, j0));
		while (!sta.empty())
		{
			p = sta.top();
			sta.pop();
			if (p.i >= 0 && p.i < l&&p.j >= 0 && p.j < l&&flagMap[p.i][p.j] == 0 && A[p.i][p.j] == 1)
			{
				if ((p.i - 1 >= 0 && A[p.i - 1][p.j] == 0) || (p.i + 1 < l&&A[p.i + 1][p.j] == 0) || (p.j - 1 >= 0 && A[p.i][p.j - 1] == 0) || (p.j + 1 < l&&A[p.i][p.j + 1] == 0))
					flagMap[p.i][p.j] = id ? -1 : (que.push(pair0(p.i, p.j)), 1);
				else
					flagMap[p.i][p.j] = id ? -2 : -3;
				sta.push(pair0(p.i-1, p.j));
				sta.push(pair0(p.i+1, p.j));
				sta.push(pair0(p.i, p.j-1));
				sta.push(pair0(p.i, p.j+1));
				/*dfsForSeparate(A, i - 1, j, id);
				dfsForSeparate(A, i + 1, j, id);
				dfsForSeparate(A, i, j - 1, id);
				dfsForSeparate(A, i, j + 1, id);*/
			}
		}
	}

	void dpForBridge()
	{
		while (!que.empty())
		{
			pair0 &p = que.front();
			que.pop();
			if (p.i - 1 >= 0)
			{
				if (flagMap[p.i - 1][p.j] == 0)
				{
					flagMap[p.i - 1][p.j] = flagMap[p.i][p.j] + 1;
					que.push(pair0(p.i - 1, p.j));
				}
				else if (flagMap[p.i - 1][p.j] == -1)
				{
					sb = flagMap[p.i][p.j];
					break;
				}
			}
			if (p.i + 1 < l)
			{
				if (flagMap[p.i + 1][p.j] == 0)
				{
					flagMap[p.i + 1][p.j] = flagMap[p.i][p.j] + 1;
					que.push(pair0(p.i + 1, p.j));
				}
				else if (flagMap[p.i + 1][p.j] == -1)
				{
					sb = flagMap[p.i][p.j];
					break;
				}
			}
			if (p.j - 1 >= 0)
			{
				if (flagMap[p.i][p.j - 1] == 0)
				{
					flagMap[p.i][p.j - 1] = flagMap[p.i][p.j] + 1;
					que.push(pair0(p.i, p.j - 1));
				}
				else if (flagMap[p.i][p.j - 1] == -1)
				{
					sb = flagMap[p.i][p.j];
					break;
				}
			}
			if (p.j + 1 < l)
			{
				if (flagMap[p.i][p.j + 1] == 0)
				{
					flagMap[p.i][p.j + 1] = flagMap[p.i][p.j] + 1;
					que.push(pair0(p.i, p.j + 1));
				}
				else if (flagMap[p.i][p.j + 1] == -1)
				{
					sb = flagMap[p.i][p.j];
					break;
				}
			}
		}
	}

public:
	Solution()
	{
		sb = 10000;
	}
	int shortestBridge(vector<vector<int> >& A)
	{
		this->l = A.size();
		flagMap.assign(l, vector<int>(l, 0));

		this->separate(A);

		this->dpForBridge();
		return sb - 1;
	}
};


/***************************test****************************/
#include<iostream>
#include<cstdlib>
int main()
{
	Solution s;
	int i, j;
	/*int tempA[10][10] = {
	1,1,1,1,1,0,0,0,1,1,
	1,0,1,0,0,0,0,1,1,1,
	1,1,1,0,0,0,0,0,1,0,
	1,0,1,0,0,0,0,0,1,1,
	1,1,1,1,1,0,0,0,0,1,
	1,1,1,1,1,0,0,0,1,1,
	1,0,1,0,0,0,0,1,1,1,
	1,1,1,0,0,0,0,1,0,0,
	1,0,1,0,0,0,0,0,0,0,
	1,1,1,1,1,1,0,0,0,0,
	};*/
	/*int tempA[20][20] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };*/
	int tempA[30][30] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,
		0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,
		0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,
		0,1,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,
		0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,
		1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
		0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	};
	vector<vector<int> > A(30, vector<int>(30, 0));
	for (i = 0; i<30; i++)
		for (j = 0; j<30; j++)
		{
			A[i][j] = tempA[i][j];
		}
	cout << s.shortestBridge(A) << endl;
	system("pause");
	return 0;
}
