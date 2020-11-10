#include <iostream> 
using namespace std;

const int N = 100010;

int n, m; 
int p[N];//父节点

int find(int x) //返回x所在集合编号（根节点）同时，对路径进行压缩 
{
	if(p[x] != x)  p[x] = find(p[x]);
	return p[x]; 
//路径压缩，是因为这里返回的是根节点，所以x路径上，每个节点都指向根节点
}

int main() 
{
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) p[i] = i;
	
	while (m --)
	{
		char op[2]; //为什么要写成op[2],是因为读入字符串的时候，能够忽略一些空格和回车 
		int a, b;   //用scanf的时候，读入一个字符会读入空格和回车，但是变成字符串的时候就不会 
		//建议：如果读入一个字符的时候，就直接写成字符串的形式 
		scanf("%s%d%d", op, &a, &b);
		
		if (op[0] == 'M') p[find(a)] = find(b);
		else
	{
		if (find(a) == find(b)) puts("Yes");
		else puts("No");
	}
	}
	
	return 0;
}


