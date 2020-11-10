#include <iostream> 

using namespace std;

const int N = 100010, M = 1000010; //�������һ��Ҫ������ѽ 

int n, m;
char p[N], s[M];
int ne[N];

int main()
{
	cin >> n >> p + 1 >> m >> s + 1; // �±�� 1 ��ʼ��i��1 ��ʼ��j ��ͼƥ�����j + 1  
	
	//��next�Ĺ���
	for(int i = 2, j = 0; i <= n; i ++) //��Ϊnext[1] = 0 ��һ����ĸʧ���ˣ�ֻ�ܴ�0��ʼ 
	{
		while (j && p[i] != p[j + 1]) j = ne[j]; // ����˻�~ 
		if (p[i] == p[j + 1]) j ++;
		ne[i] = j; // ��һ���Ӵ���next���鵱ǰֵ�Ƕ��� 
	}
	
	//KMPƥ����� 
	for (int i = 1, j = 0; i <= m; i ++)
	{
		while (j && s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) j ++;
		if(j == n) //ƥ��ɹ�
		{
			printf("%d ", i - n);
			j = ne[j]; // ƥ��ɹ��Ļ���ƥ����һ�Σ���Ҫ���˺�һ�� 
		} 
	}
	
	return 0;
}
