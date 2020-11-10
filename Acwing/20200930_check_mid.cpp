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
	
	while (m --) //有m个询问，一个一个来 
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
			cout << l << " "; // 首先输出的是起始位置 
			int l = 0, r = n - 1;
			while (l < r)
			{
				int mid = l + r + 1>> 1;
				if( q[mid] <= x ) l = mid;
				else r = mid - 1;
			}
			cout << l << endl; // 然后输出的是终止位置
		}
		 
	}
	
	return 0;
}
