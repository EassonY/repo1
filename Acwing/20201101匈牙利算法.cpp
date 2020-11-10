#include <iostream> 
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010; //��Ҫ��벿�ֵı߾ͺ���

int n1, n2, m;
int h[N], e[M], ne[M], idx;

int match[N]; //������ұߵĵ��Ӧ�ĵ� 
int st[N]; //���أ���Ҫ�ظ��ѵ� 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x) 
{
	//�ж��ܲ��ܳɹ�ƥ�䵽Ů��������Ҫö�������ܹ����ϵ�����
	for (int i = h[x]; i != -1; i = ne[i]) 
	{
		int j = e[i];
		if (!st[j]) //���û�п��ǹ���� 
		{
			st[j] = true;
			if (match[j] == 0 || find(match[j]) 
			//���������ӻ�û��ƥ����κ������Ļ� ,�����ܹ�����������ҵ��¼� 
			{
				match[j] = x;
				return true;
			} 
		}
		
	}
	return false;
}

int main()
{
	scanf("%d%d%d", &n1, &n2, m);
	
	memset(h, -1, sizeof h);
	while (m --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	
	int res = 0; //ƥ�������
	for (int i = 1; i <= n1; i ++) 
	{
		memset(st, false, sizeof st);
		if (find(i)) res ++;
	}
	
	printf("%d\n", res);
		
	return 0;
}
