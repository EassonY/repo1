#include <iostream> 
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N]; //并查集里面的p数组 

struct Edge
{
	int a, b, w;
	
	//重载一下 < 号 ，方便排序 
	bool operator < (const Edge &W) const
	{
		return w < W.w;
	}
}edges[N];

//并查集模板 
int find(int x) 
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++) //读入所有的边 
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = {a, b, w};
	}
	
	sort(edges, edges + m); // 给m条边排序 
	
	// 初始化并查集 
	for (int i = 1; i <= n; i ++)  p[i] = i;
	
	int res = 0, cnt = 0;
	for (int i = 0; i < m; i ++) //从小到大枚举所有边
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		
		a = find(a), b = find(b); //a = a的祖宗节点 
		if (a != b) // 判断两个节点是不是连通的，也就是判断两个祖宗节点是不是一样的 
		{
			p[a] = b; //两个节点不连通，就加进来 ，这个是合并两个点所在的集合 
			res += w; // 权值加进来 
			cnt ++; //当前加入多少条边 
		}
	} 
	
	//如果边数 < n - 1, 说明 这个图 是不连通的 
	if (cnt < n - 1) cout << "impossible" << endl;
	else printf("%d\n", res);
	
	return 0; 
}
