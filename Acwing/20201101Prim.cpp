#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N]; //����ͼ����һ�����еľ��� 
int dist[N]; //��㵽���ϵľ��� 
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	int res = 0; //res�������С�������У����бߵĳ���֮��
	
	for (int i = 0; i < n; i ++) //ÿһ�ζ����ҵ���ǰ�������У����뼯������ĵ� 
	{
		int t = -1;
		for (int j = 1; j <= n; j ++)
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j])) //�ڼ����⣬���ң��ǵ�һ������߾����С 
				t = j;
		}
		if ( i && dist[t] == INF) return INF; //������ǵ�һ���㣬���Ҿ��붼��INF��˵��û����ͨ
		if (i) res += dist[t]; //����ֻҪ���ǵ�һ���ߣ��Ͱ�������뼯����С�ľ��룬�ӵ�������ȥ 
		//��Ҫ�����ۼӣ�Ȼ����£���ֹ�и����Ի� 
		 
		for (int j = 1; j <= n; j ++) //���µ㵽���ϵľ��� 
		{
			dist[j]  = min(dist[j], g[t][j]); //������� Prim �� Dijkstra ������ 
		}
		
		
		st[t]  = true; //Ȼ��������ӵ���������ȥ 
	}
	return res; 
}

int main()
{
	scanf("%d%d", &n, &m);
	
	//��Ϊ�������رߣ�������̵ı߾ͺ���
	memset(g, 0x3f, sizeof g);
	//�������б�
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
