#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
	
	int k = (x % N + N) % N;
	while (h[k] != null && h[k] != x) //��λ���˶��Ҳ���x 
	{
		k ++; //�������� 
		if (k == N) k = 0;
	}
	return k;
}


int main()
{
	int n;
	scanf("%d", &n);
	
	memset(h, 0x3f, sizeof h);//memset�ǰ����ֽ�����ֵ 
	//���������ʼ���Ļ�������0x3f3f3f3f, ����10e9 
	 
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
