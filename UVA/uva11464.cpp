//UVA11464 Even Parity  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=26&page=show_problem&problem=2459
//This 

#include<cstdio>
#include<vector>
#include<algorithm>
#define INT_MAX 99999999
using namespace std;
int res = INT_MAX;
int len;
vector<vector<int> > buf(20, vector<int>(20, 0));

int digui(int cur){
	vector<vector<int> > t_buf(len, vector<int>(len, 0));
	for (int i = 0; i < len; i++)
	{
		if (cur & 1 << i) t_buf[0][i] = 1;
		else
			if (buf[0][i] == 1) return INT_MAX;
	}
	for (int i = 1; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			int pre_x = i - 1, pre_y = j,count_1=0;
			if (pre_x - 1>=0) count_1 += t_buf[pre_x - 1][pre_y];
			if (pre_y + 1<len) count_1 += t_buf[pre_x][pre_y+1];
			if (pre_y - 1>=0) count_1 += t_buf[pre_x][pre_y-1];
			if (count_1 % 2 == 0)
			{
				if (buf[i][j] == 1) return INT_MAX;
			}
			else
				t_buf[i][j] = 1;
		}
	int count=0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			if (buf[i][j] != t_buf[i][j]) count++;
		}
	return count;
}

int main()
{
	// freopen("data.in", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int c= 1; c <= t;c++){
		int n;
		scanf("%d", &n);
		len = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &buf[i][j]);
			}
		}
		int res = INT_MAX;
		for (int i = 0; i < 1 << n; i++)
			res = min(res, digui(i));
		if (res == INT_MAX) res = -1;
		printf("Case %d: %d\n", c, res);


	}
	return 0;
}
