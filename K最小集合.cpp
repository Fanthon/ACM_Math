#include <iostream>
#include <cstdio>
using namespace std;

#define myMax 1000010
int book[myMax];


int GCD(int a, int b)
{
	if(!b)return a;
    return GCD(b,a%b);
}

int main()
{
	int n,m=0;
	int cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(!book[temp])
		{
			cnt++;
			book[temp]=1;
			m=max(m,temp);
		}
	}
	for(int j=1;j<=m;j++)
	{
		if(book[j]) continue;
		int w=0;
		for(int k=j;k<=m;k+=j)
		{
			if(book[k])
			{
				w=GCD(w,k);
			}
			
		}
		if(w==j) cnt++;
	}
	cout<<cnt; 
	return 0;
}
