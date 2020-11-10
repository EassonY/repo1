#include <iostream> 
#include <cstring> 
#include <algrithm>

using namespace std;

const int N = 110;
typedef pair<int, int> PII;

int n, m;
int g[N][N]; //存的是图 
int d[N][N]; //存的是距离 
PII q[N * N]; //这就是模拟的队列 

int bfs()
{
	int hh = 0, tt = 0; //队头hh， 队尾tt 
	q[0] = {0, 0};
	memset(d, -1, sizeof d); // 先全部初始化为 -1 ，代表没有走过 
	d[0][0] = 0; // =0代表走过了 
	
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//x、y可以上右下左走 
	
	while(hh <= tt) //队列不空 
	{
		auto t =  q[hh ++]; //每次取出来队头元素，再把hh++ 
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
			{
				d[x][y] = d[t.first][t.second] + 1;
				q[ ++ tt] = {x, y}; //只要这种满足条件的xy的值，就放到队列（肯定会有） 
			}
		}
	}
	return d[n - 1][m - 1];
}

int main() 
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j ++)
			cin >> g[i][j];
	
	cout  << bfs() << endl;
	
	return 0;
}






