#include<iostream>

using namespace std;

const int N = 100010;
int n, k;
int q[N];

int quick_pick(int l, int r, int k)
{
	if(l == r) return q[l];
	
	int x = q[l], i = l - 1, j = r + 1;
	while (i < j)
	{
		while (q[++ i] < x);
		while (q[-- j] > x);
		if(i < j) swap(q[i], q[j]);
			
	}
	int sl = j - l + 1;
	if (k <= sl) return quick_pick(l, j, k);
	else return quick_pick(j + 1, r, k - sl);
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &k);
	
	for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
	
	printf("%d", quick_pick(0, n - 1, k));
	
	
	return 0;
 } 
