#include<stdio.h>
long long fuc(int *s,int cur,int target)
{
	if(cur==0) return 0;
	if(s[cur]==target) return fuc(s,cur-1,target);
	return fuc(s,cur-1,6-s[cur]-target)+(1LL<<(cur-1));
}
int main()
{
	int n;
	int s[61],e[61],c=1;
	while(scanf("%d",&n)==1&&n!=0)
	{
		for(int i=1;i<n+1;i++)
			scanf("%d",&s[i]);
		for(int i=1;i<n+1;i++)
			scanf("%d",&e[i]);
		int k=n;
		while(s[k]==e[k]) k--;
		long long res=0;
		if(k>=1)
		res=fuc(s,k-1,6-s[k]-e[k])+fuc(e,k-1,6-s[k]-e[k])+1;
		printf("Case %d: %lld\n",c++,res);
	}


}
