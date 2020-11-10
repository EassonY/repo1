//�鲢����
#include <iostream> 
using namespace std;

int n;
const int N = 100010;
int q[N], tem[N];

void merge_sort(int q[], int l, int r)
{
	if(l >= r) return;
	int mid = l + r >> 1;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j]) tem[k++] = q[i++];
		else tem[k++] = q[j++];
	}
	while (i <= mid) tem[k++] = q[i++]; 
	//��Ϊһֱ�� i++���������ƶ�������һ���ˣ������ֱ�� i<=mid 
	while (j <= r)   tem[k++] = q[j++];
	//�����нӣ�ֻҪ��û�зŵ�tem��ʱ��������ģ�������while���Ž����� 
	
	for(i = l, j = 0; i <= r; i++, j++)	 q[i] = tem[j];
}

int main()
{
	
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
	
	merge_sort(q, 0, n - 1);
	
	for(int i = 0; i < n; i ++) printf("%d", q[i]);
	
	return 0;
}
