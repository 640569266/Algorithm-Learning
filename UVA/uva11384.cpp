#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int res=1;
		if(n==0) {printf("0\n");continue;}
		while(n!=1)
		{
			n=n/2;
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}
