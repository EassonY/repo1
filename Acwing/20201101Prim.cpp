#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N]; //稠密图，存一下所有的距离 
int dist[N]; //存点到集合的距离 
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	int res = 0; //res存的是最小生成树中，所有边的长度之和
	
	for (int i = 0; i < n; i ++) //每一次都是找到当前集合外中，距离集合最近的点 
	{
		int t = -1;
		for (int j = 1; j <= n; j ++)
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j])) //在集合外，而且，是第一个点或者距离更小 
				t = j;
		}
		if ( i && dist[t] == INF) return INF; //如果不是第一个点，而且距离都是INF，说明没有连通
		if (i) res += dist[t]; //否则只要不是第一条边，就把这个距离集合最小的距离，加到答案里面去 
		//先要进行累加，然后更新，防止有负的自环 
		 
		for (int j = 1; j <= n; j ++) //更新点到集合的距离 
		{
			dist[j]  = min(dist[j], g[t][j]); //这里就是 Prim 和 Dijkstra 的区别 
		}
		
		
		st[t]  = true; //然后把这个点加到集合里面去 
	}
	return res; 
}

int main()
{
	scanf("%d%d", &n, &m);
	
	//因为可能有重边，保留最短的边就好了
	memset(g, 0x3f, sizeof g);
	//读入所有边
	while (m --) 
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
		
	}
	
	int t = prim();
	
	if (t == INF) printf("impossible");
	else printf("%d\n", t);
	
	return 0;
}
