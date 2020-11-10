#include <iostream> 

using namespace std;

const int N = 100010, M = 1000010; //这个数组一定要构建好呀 

int n, m;
char p[N], s[M];
int ne[N];

int main()
{
	cin >> n >> p + 1 >> m >> s + 1; // 下标从 1 开始，i从1 开始，j 试图匹配的是j + 1  
	
	//求next的过程
	for(int i = 2, j = 0; i <= n; i ++) //因为next[1] = 0 第一个字母失败了，只能从0开始 
	{
		while (j && p[i] != p[j + 1]) j = ne[j]; // 这个退回~ 
		if (p[i] == p[j + 1]) j ++;
		ne[i] = j; // 记一下子串的next数组当前值是多少 
	}
	
	//KMP匹配过程 
	for (int i = 1, j = 0; i <= m; i ++)
	{
		while (j && s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) j ++;
		if(j == n) //匹配成功
		{
			printf("%d ", i - n);
			j = ne[j]; // 匹配成功的话，匹配下一次，需要先退后一步 
		} 
	}
	
	return 0;
}
