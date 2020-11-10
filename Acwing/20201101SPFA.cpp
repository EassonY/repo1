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
	//���ȳ�ʼ�����е�ľ���
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	//����һ�����У��洢���д����µĵ�
	queue<int> q;
	q.push(1); //��1�ŵ�ŵ����е��� 
	st[1] = true; //st������飬����ǣ���ǰ���ǲ����ڶ��е��У���ֹ�����д洢�ظ��ĵ� 
	
	while(q.size())
	{
		int t = q.front();
		q.pop(); //�ó�����ͷԪ�� 
		
		st[t] = false;
		 
		for (int i = h[t]; i != -1; i = ne[i]) //���������ڱ� 
		{
			int j = e[i]; //��j ��ʾ��ǰ��
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


