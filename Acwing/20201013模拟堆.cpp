#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;

int h[N], ph[N], hp[N], sz; 

//��Ҫ��������Ľ�����������ֵ��Ҫ������
//���һ�Ҫ֪�������ĵ㣬�ǵڼ����������
//��ǰ�����ڵ���±�ֱ���a��b
//hp�����a��bλ���ϵ�Ԫ�أ��ǵڼ���������� 
//ph����ǵڼ����������Ԫ�أ��±�λ���Ƕ��� 
void heap_swap(int a, int b) 
{
	//����˳���ܱ䣬�����棬������
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int u) 
{
	int t = u; 
	if (u * 2 <= sz && h[u * 2] < h[t])  t = u * 2; 
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1; 
	if (u != t) 
	{
		heap_swap(u, t);
		down(t);  
	}
}

void up(int u) 
{

	while (u / 2 && h[u / 2] > h[u]) 
	{
		heap_swap(u/2, u);
		u /= 2;
	}
}

 

int main() 
{
	int n, m = 0; //m�ǵڼ����������������k��������� 
	scanf("%d", &n);
	while(n --)
	{
		char op[10];
		int k, x;
		
		//���������I����PM�����СֵDMɾ����СֵD K ɾ����K���������C kx�޸ĵ�k������������޸ĺ����ֵΪx 
		scanf("%s", op) ;
		if(!strcmp(op, "I")) //��str1=str2���򷵻���
		{
			scanf("%d", &x);
			sz++;
			m++;
			ph[m]  = sz, hp[sz] = m;
			h[sz] = x;
			up(sz);
			//���ǲ嵽��������up�ͺ��� 
		}
		else if(!strcmp(op, "PM")) printf("%d\n", h[1]);
		else if(!strcmp(op, "DM"))
		{
			heap_swap(1,sz);
			sz --;
			down(1); //�����һ�����滻���˵�һ���� 
		}
		else if(!strcmp(op, "D")) 
		{
			scanf("%d", &k);
			k = ph[k]; //��k����������������±���ʲô 
			heap_swap(k, sz) ;
			sz --;
			down(k), up(k);
		}
		else
		{
			scanf("%d%d", &k, &x);
			k = ph[k];
			h[k] = x;
			down(k), up(k);
		}
		
	}
	
	
	return 0;
}
