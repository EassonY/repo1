#include <iostream>
#include <algorithm> 

using namespace std;

const int N = 100010;

int n, m;
int h[N], sz; //h 就是heap堆，sz代表堆中有多少个元素 

void down(int u) //第 u 个节点 
{
	int t = u; //用t表示三个点中的最小值(下标) 
	if (u * 2 <= sz && h[u * 2] < h[t])  t = u * 2; //左儿子存在而且小 
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1; //t一直指向的就是那个大的值 
	if (u != t) 
	{
		swap(h[u], h[t]);//只要t变了，就表示t已经指向了那个较大的值 
		down(t); //递归，down就是把双亲节点大的值下放 
	}
}

void up(int n) 
{
//up操作当然也可像上面一样递归，但是up更加简单一些
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
	
	for (int i = n / 2; i; i --) down(i); //用O(n) 的方式插入（而不是nlogn的时间复杂度）
	 
	while (m--) 
	{
		printf("%d ", h[1]);
		h[1] = h[sz];
		sz --;
		down(1);
	}
	return 0;
}
