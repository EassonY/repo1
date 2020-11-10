#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010, M = 2 * N;

int h[N], e[M], ne[M], idx;
bool st[N];
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
	st[u] = true;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j]) dfs(j);
	}
}

int main()
{
	
	memset(h, -1, sizeof h);
	dfs(1);
	return 0;
}