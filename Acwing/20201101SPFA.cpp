#include <iostream> 
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int spfa()
{
	//首先初始化所有点的距离
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	//定义一个队列，存储所有待更新的点
	queue<int> q;
	q.push(1); //把1号点放到队列当中 
	st[1] = true; //st这个数组，存的是，当前点是不是在队列当中，防止队列中存储重复的点 
	
	while(q.size())
	{
		int t = q.front();
		q.pop(); //拿出来队头元素 
		
		st[t] = false;
		 
		for (int i = h[t]; i != -1; i = ne[i]) //遍历所有邻边 
		{
			int j = e[i]; //用j 表示当前点
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	
	if (dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	
	while(m --)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}
	int t = spfa();
	if ( t == -1) printf("impossible");
	else printf("%d\n", t);
	
	return 0;
}


