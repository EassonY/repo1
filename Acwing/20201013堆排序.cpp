#include <iostream>
#include <algorithm> 

using namespace std;

const int N = 100010;

int n, m;
int h[N], sz; //h ����heap�ѣ�sz��������ж��ٸ�Ԫ�� 

void down(int u) //�� u ���ڵ� 
{
	int t = u; //��t��ʾ�������е���Сֵ(�±�) 
	if (u * 2 <= sz && h[u * 2] < h[t])  t = u * 2; //����Ӵ��ڶ���С 
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1; //tһֱָ��ľ����Ǹ����ֵ 
	if (u != t) 
	{
		swap(h[u], h[t]);//ֻҪt���ˣ��ͱ�ʾt�Ѿ�ָ�����Ǹ��ϴ��ֵ 
		down(t); //�ݹ飬down���ǰ�˫�׽ڵ���ֵ�·� 
	}
}

void up(int n) 
{
//up������ȻҲ��������һ���ݹ飬����up���Ӽ�һЩ
	while (u / 2 && h[u / 2] > h[u]) 
	{
		swap(h[u/2], h[u]);
		u /= 2;
	}
}

int main() 
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
	sz = n;
	
	for (int i = n / 2; i; i --) down(i); //��O(n) �ķ�ʽ���루������nlogn��ʱ�临�Ӷȣ�
	 
	while (m--) 
	{
		printf("%d ", h[1]);
		h[1] = h[sz];
		sz --;
		down(1);
	}
	return 0;
}
