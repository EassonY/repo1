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
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++; //e[]����ľ��Ǳ�ţ����Ǵ����ֵ 
}

int dfs(int u) //��u���ڵ�
{
	st[u] = true;//˵���Ѿ��������ˣ�Ȼ�����u�����еı�DFS
	
	int sum = 1, res = 0; //sum����ǰ�����Ľڵ�������res����ľ�����Щ���������Ľڵ����� 
	for (int i = h[u]; i != -1; i = ne[i]) //i= ne[i] !!!
	{
		int j = e[i]; //j��һ�µ�ǰ�ڵ㣬��Ӧͼ�еĵ�ı���Ƕ��� 
		if (!st[j])   //���j�ڵ�û�б��ѹ��Ļ����Ǿͼ����� 
		{
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		}
	}
	
	res = max(res, n - sum); //n - sum �������ɾ������ڵ�֮�������Ľڵ����� 
	
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
