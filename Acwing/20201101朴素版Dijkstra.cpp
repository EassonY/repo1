#include <iostream> 
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N]; //存边，邻接矩阵 
int dist[N]; //dijkstra 的距离，从 第一个点走到当前点的最短距离是多少 
bool st[N]; // 表示点的最短路是否确定了 

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist); //把所有的距离初始化为正无穷
	dist[1] = 0; //初始化第一个点为0 
	
	for (int i = 0; i < n; i ++)  //迭代n次，每一次找到最小值，然后更新 
	{
		int t = -1; 
		for (int j = 1; j <= n; j ++)
		{
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		}
	}
	
	if (dist[n] == 0x3f3f3f3f) return -1;
	
	return dist[n];
	 
}

int main() 
{
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);
	
	while (m --)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = min(g[a][b], c);
	}
	
	int t = dijkstra();
	
	printf("%d\n", t);
	
	return 0;
}
