#include<iostream> 

using namespace std;
const int N = 100010; //�۾Ϳ�5�η��ͺ��� 


int main()
{
	for(int i = 100000;;i ++)
	{
		bool flag = true;
		for (int j = 2; i * j <= i; j ++)
		{
			if(i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}
