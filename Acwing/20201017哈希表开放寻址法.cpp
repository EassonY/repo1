#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
	
	int k = (x % N + N) % N;
	while (h[k] != null && h[k] != x) //坑位有人而且不是x 
	{
		k ++; //就往后找 
		if (k == N) k = 0;
	}
	return k;
}


int main()
{
	int n;
	scanf("%d", &n);
	
	memset(h, 0x3f, sizeof h);//memset是按照字节来赋值 
	//所以这里初始化的话，就是0x3f3f3f3f, 大于10e9 
	 
	while(n --)
	{
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		
		int k = find(x);
		if(*op == 'I') h[k] = x;
		else
		{
			if (h[k] != null ) puts("Yes");
			else puts("No");
		}
	}

	return 0;
}
