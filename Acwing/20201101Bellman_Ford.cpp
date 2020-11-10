#include <iostream> 
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N]; //backup存的是上一次迭代的结果 

struct Edge
{
	int a, b, w;
}edges[M]; //表示存所有边的结构体

int bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for (int i = 0; i < k; i ++) 
	{
		memcpy(backup, dist, sizeof dist); //把上一次迭代的结果备份到backup里面
		for (int j = 0; j < m; j ++)
		{
		    int a = edges[j].a, b = edges[j].b, w = edges[j].w;
		    dist[b] = min(dist[b], backup[a] + w);//只用上一次迭代的结果，来更新当前迭代的距离 
		}
		
	}
	if (dist[n] > 0x3f3f3f3f / 2) return -1;
	return dist[n];
}


int main() 
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i ++) //读入m条边
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w) ;
		edges[i] = {a, b, w}; //然后把这条边存下来 
	} 
	
	//然后调用Bellman-Ford算法
	int t = bellman_ford();
	if(t == -1) printf("impossible");
	else printf("%d\n", t);
	
	return 0;
}
