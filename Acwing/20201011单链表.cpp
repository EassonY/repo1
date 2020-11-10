#include <iostream> 

using namespace std;

const int N = 100010;
//head 表示头结点下标 
//e[i]  表示节点i的值
//ne[i] 表示节点i的next指针是多少
//idx 存储当前已经用到了多少个点
int head, e[N], ne[N], idx;

//初始化
void init() 
{
	head = -1;
	idx = 0;
}
//将x插入到头结点中
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx ++;
}
//将x插到k个节点后面 
void add(int k, int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx ++;
}
//将下标是k的点后一个点删掉 
void remove(int k) 
{
	ne[k] = ne[ne[k]]; //这个是逻辑上的下一个，不是具体的k + 1 
	
}

int main()
{
	init();
	int m;
	cin >> m;
	while(m --) 
	{
		int k, x;
		char op;
		cin >> op;
		if(op == 'H')
		{
			cin >> x;
			add_to_head(x);
		}
		else if(op == 'D')
		{
			cin >> k;
			if(!k) head = ne[head];
			remove(k - 1);
		}
		else
		{
			cin >> k >> x;
			add(k - 1, x);
		}
		
	}
	for (int i = head; i != -1; i = ne[i]) cout << e[i] << " " ;
	
	return 0;
}



