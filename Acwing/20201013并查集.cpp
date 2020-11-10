#include <iostream> 
using namespace std;

const int N = 100010;

int n, m; 
int p[N];//���ڵ�

int find(int x) //����x���ڼ��ϱ�ţ����ڵ㣩ͬʱ����·������ѹ�� 
{
	if(p[x] != x)  p[x] = find(p[x]);
	return p[x]; 
//·��ѹ��������Ϊ���ﷵ�ص��Ǹ��ڵ㣬����x·���ϣ�ÿ���ڵ㶼ָ����ڵ�
}

int main() 
{
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) p[i] = i;
	
	while (m --)
	{
		char op[2]; //ΪʲôҪд��op[2],����Ϊ�����ַ�����ʱ���ܹ�����һЩ�ո�ͻس� 
		int a, b;   //��scanf��ʱ�򣬶���һ���ַ������ո�ͻس������Ǳ���ַ�����ʱ��Ͳ��� 
		//���飺�������һ���ַ���ʱ�򣬾�ֱ��д���ַ�������ʽ 
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


