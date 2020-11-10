#include <iostream> 
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010; //主要存半部分的边就好了

int n1, n2, m;
int h[N], e[M], ne[M], idx;

int match[N]; //存的是右边的点对应的点 
int st[N]; //判重，不要重复搜点 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x) 
{
	//判断能不能成功匹配到女生，首先要枚举所有能够看上的妹子
	for (int i = h[x]; i != -1; i = ne[i]) 
	{
		int j = e[i];
		if (!st[j]) //如果没有考虑过这个 
		{
			st[j] = true;
			if (match[j] == 0 || find(match[j]) 
			//如果这个妹子还没有匹配过任何男生的话 ,或者能够给这个男生找到下家 
			{
				match[j] = x;
				return true;
			} 
		}
		
	}
	return false;
}

int main()
{
	scanf("%d%d%d", &n1, &n2, m);
	
	memset(h, -1, sizeof h);
	while (m --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	
	int res = 0; //匹配的数量
	for (int i = 1; i <= n1; i ++) 
	{
		memset(st, false, sizeof st);
		if (find(i)) res ++;
	}
	
	printf("%d\n", res);
		
	return 0;
}
