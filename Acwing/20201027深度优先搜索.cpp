#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx;
bool st[N];

int ans = N; 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++; //e[]代表的就是编号，不是代表的值 
}

int dfs(int u) //第u个节点
{
	st[u] = true;//说明已经搜索过了，然后遍历u的所有的边DFS
	
	int sum = 1, res = 0; //sum代表当前子树的节点数量，res代表的就是这些子树中最大的节点数量 
	for (int i = h[u]; i != -1; i = ne[i]) //i= ne[i] !!!
	{
		int j = e[i]; //j存一下当前节点，对应图中的点的编号是多少 
		if (!st[j])   //如果j节点没有被搜过的话，那就继续搜 
		{
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		}
	}
	
	res = max(res, n - sum); //n - sum 代表就是删掉这个节点之后，主树的节点数量 
	
	ans = min(ans, res);
	return sum;
}

int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	
	for (int i = 0; i < n - 1; i ++) 
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	dfs(1);
	
	cout << ans << endl;
	return 0;
	
}
