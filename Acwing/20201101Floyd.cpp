#include <iostream> 
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];

void floyd()
{
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}


int main()
{
	scanf("%d%d%d", &n, &m, &Q);
	
	//初始化所有的边 
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= n; j ++)
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
	
	//然后读入每条边
	while (m --) 
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		
		d[a][b] = min(d[a][b], w); //保留最小的边 
	}
	
	floyd();
	
	//处理所有询问
	while (Q --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (d[a][b] > 1e9 / 2) printf("impossible\n");
		else printf("%d\n", d[a][b]);
	}
	
	
	return 0;
}
