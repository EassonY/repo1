#include<iostream>
using namespace std;

const int N = 100010;
int m;
int e[N], l[N], r[N], idx;

//��ʼ��
void init() 
{
	//0��ʾ��˵㣬1��ʾ�Ҷ˵�
	r[0] = 1, l[1] = 0;
	idx = 2;
}
//���ұ߲��� 
void add(int k, int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx;
	r[k] = idx;
	idx ++;
}

void remove(int k) 
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}

int main()
{
	
	
	
}




