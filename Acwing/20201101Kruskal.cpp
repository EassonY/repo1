#include <iostream> 
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N]; //���鼯�����p���� 

struct Edge
{
	int a, b, w;
	
	//����һ�� < �� ���������� 
	bool operator < (const Edge &W) const
	{
		return w < W.w;
	}
}edges[N];

//���鼯ģ�� 
int find(int x) 
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++) //�������еı� 
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = {a, b, w};
	}
	
	sort(edges, edges + m); // ��m�������� 
	
	// ��ʼ�����鼯 
	for (int i = 1; i <= n; i ++)  p[i] = i;
	
	int res = 0, cnt = 0;
	for (int i = 0; i < m; i ++) //��С����ö�����б�
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		
		a = find(a), b = find(b); //a = a�����ڽڵ� 
		if (a != b) // �ж������ڵ��ǲ�����ͨ�ģ�Ҳ�����ж��������ڽڵ��ǲ���һ���� 
		{
			p[a] = b; //�����ڵ㲻��ͨ���ͼӽ��� ������Ǻϲ����������ڵļ��� 
			res += w; // Ȩֵ�ӽ��� 
			cnt ++; //��ǰ����������� 
		}
	} 
	
	//������� < n - 1, ˵�� ���ͼ �ǲ���ͨ�� 
	if (cnt < n - 1) cout << "impossible" << endl;
	else printf("%d\n", res);
	
	return 0; 
}
