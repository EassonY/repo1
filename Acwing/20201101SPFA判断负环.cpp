#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N], cnt[N];
bool dt[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
	//如果只是判断负环，就不用初始化了 
	//也不是判断从1开始的负环，因为可能从1开始到不了那个负环 
	//所以，一开始，就把所有的点都放进去。
	//所以，只要存在负环，就一定可以找到 
//	queue<int> q;
//	q.push(1);
//	st[1] = true;
	
	queue<int> q;
	for (int i = 1; i <= n; i ++)
	{
		st[i] = true;
		q.push(i);
	}
	
	while (q.size())
	{
		int t = q.front() ;
		q.pop();
		
		st[t] = false;
		
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				
				if (cnt[j] >= n) return true;
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	
	memset(h, -1, sizeof h);
	
	while (m --)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}
	
	if (spfa()) printf("Yes");
	else printf("No");
	
	return 0;
}
