#include <iostream> 
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N]; //��ߣ��ڽӾ��� 
int dist[N]; //dijkstra �ľ��룬�� ��һ�����ߵ���ǰ�����̾����Ƕ��� 
bool st[N]; // ��ʾ������·�Ƿ�ȷ���� 

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist); //�����еľ����ʼ��Ϊ������
	dist[1] = 0; //��ʼ����һ����Ϊ0 
	
	for (int i = 0; i < n; i ++)  //����n�Σ�ÿһ���ҵ���Сֵ��Ȼ����� 
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
