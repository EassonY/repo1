#include <iostream> 
#include <cstring> 
#include <algrithm>

using namespace std;

const int N = 110;
typedef pair<int, int> PII;

int n, m;
int g[N][N]; //�����ͼ 
int d[N][N]; //����Ǿ��� 
PII q[N * N]; //�����ģ��Ķ��� 

int bfs()
{
	int hh = 0, tt = 0; //��ͷhh�� ��βtt 
	q[0] = {0, 0};
	memset(d, -1, sizeof d); // ��ȫ����ʼ��Ϊ -1 ������û���߹� 
	d[0][0] = 0; // =0�����߹��� 
	
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//x��y�������������� 
	
	while(hh <= tt) //���в��� 
	{
		auto t =  q[hh ++]; //ÿ��ȡ������ͷԪ�أ��ٰ�hh++ 
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
			{
				d[x][y] = d[t.first][t.second] + 1;
				q[ ++ tt] = {x, y}; //ֻҪ��������������xy��ֵ���ͷŵ����У��϶����У� 
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






