#include <iostream>
#include <string>

using namespace std;

const int N = 100010;
int n, m;
int q[N];


int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
	
	while (m --) //��m��ѯ�ʣ�һ��һ���� 
	{
		int x;
		scanf("%d", &x);
		
		int l = 0, r = n - 1; 
		while (l < r)
		{
			int mid = l + r >> 1;
			if(q[mid] >= x) r = mid;
			else l = mid + 1;
		}
		if(q[l] != x) cout << "-1 -1" << endl;
		else
		{
			cout << l << " "; // �������������ʼλ�� 
			int l = 0, r = n - 1;
			while (l < r)
			{
				int mid = l + r + 1>> 1;
				if( q[mid] <= x ) l = mid;
				else r = mid - 1;
			}
			cout << l << endl; // Ȼ�����������ֹλ��
		}
		 
	}
	
	return 0;
}
