#include<iostream> 
#include<cstring>
using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx ++;
}

bool find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
	{
		if(e[i] == x)
			return true;
	}
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	memset(h, -1, sizeof h);
	while (n --)
	{
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		
		if(*op == 'I') insert(x);
		else
		{
			if(find(x)) puts("Yes");
			else puts("No");
		}
	}
	
	return 0;
}

////首先要看比数组长度大的最小的数是多少，就开多少数组
//int main() 
//{
//	for (int i = 10000; ; i ++)
//	{
//		bool flag = true;
//		
//		for (int j = 2; j * j <= i; j ++)
//		{
//			if ( i % j == 0)
//			{
//				flag = true;
//				break;
//			}
//		}
//		if (flag)
//		{
//			cout << i << endl;
//			break;
//		}
//	}
//}



