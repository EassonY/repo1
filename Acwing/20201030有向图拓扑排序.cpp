#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool topsort()
{
	int hh = 0, tt = -1; 
	for (int i = 1; i <= n; i ++)
	{
		if ( !d[i]) //只要这个节点的入度为0，就把它放到队列中 
			q[ ++ tt] = i; //枚举所有的入度=0点，放到队列里面 
	}
	while (hh <= tt) // while 队列不空 
	{
		int t = q[hh ++];
		
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j] --;
			if (d[j] ==0) q[++tt] = j;
		}
	}
	return tt == n - 1;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	
	for (int i = 0; i < m; i ++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b); //把m条边输入进来 
		d[b] ++; //有了一条 a->b 的边，就把b的入度 + 1 
	}
	
	if (topsort())
	{
		for (int i = 0; i < n; i ++) printf("%d ", q[i]);
		puts("");
	}
	else puts("-1");
	
	return 0; 
}
