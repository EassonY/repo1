#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;

int h[N], ph[N], hp[N], sz; 

//需要进行特殊的交换，不仅数值需要交换，
//而且还要知道交换的点，是第几个插进来的
//当前两个节点的下标分别是a和b
//hp存的是a和b位置上的元素，是第几个插进来的 
//ph存的是第几个插进来的元素，下标位置是多少 
void heap_swap(int a, int b) 
{
	//交换顺序不能变，先外面，后里面
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int u) 
{
	int t = u; 
	if (u * 2 <= sz && h[u * 2] < h[t])  t = u * 2; 
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1; 
	if (u != t) 
	{
		heap_swap(u, t);
		down(t);  
	}
}

void up(int u) 
{

	while (u / 2 && h[u / 2] > h[u]) 
	{
		heap_swap(u/2, u);
		u /= 2;
	}
}

 

int main() 
{
	int n, m = 0; //m是第几个插入的数，即第k个插入的数 
	scanf("%d", &n);
	while(n --)
	{
		char op[10];
		int k, x;
		
		//五个操作：I插入PM输出最小值DM删掉最小值D K 删掉第K个插入的数C kx修改第k个插入的数，修改后的数值为x 
		scanf("%s", op) ;
		if(!strcmp(op, "I")) //若str1=str2，则返回零
		{
			scanf("%d", &x);
			sz++;
			m++;
			ph[m]  = sz, hp[sz] = m;
			h[sz] = x;
			up(sz);
			//就是插到了最后，你就up就好了 
		}
		else if(!strcmp(op, "PM")) printf("%d\n", h[1]);
		else if(!strcmp(op, "DM"))
		{
			heap_swap(1,sz);
			sz --;
			down(1); //把最后一个数替换掉了第一个， 
		}
		else if(!strcmp(op, "D")) 
		{
			scanf("%d", &k);
			k = ph[k]; //第k个插入的数，堆中下标是什么 
			heap_swap(k, sz) ;
			sz --;
			down(k), up(k);
		}
		else
		{
			scanf("%d%d", &k, &x);
			k = ph[k];
			h[k] = x;
			down(k), up(k);
		}
		
	}
	
	
	return 0;
}
