#include<cstdio>
#define PI 3.14159
const int PIES_NUM=10000+5;
double pies_size[PIES_NUM];
int main()
{
	int cases;
	scanf("%d",cases);
	while(cases--)
	{
		int n,f;
		scanf("%d%d",&n,&f);
		double max_size=-1;
		for(int i=1;i<=n;i++)
		{
			int trs;
			scanf("%d",&trs);
			pies_size[i]=trs*trs*PI;
			if(max_size<pies_size[i]) max_size=pies_size[i];
		}	
		double l=0,r=max_size;
		while(r-l>0.00001)
		{
			double mid=(l+r)/2;
			int count=0;
			for(int i=1;i<=n;i++)
			{
				count=count+(int)(pies_size[i]/mid);
			}
			if(count==f+1) break;
			if(count>f+1) l=mid;
			else
				r=mid;
		}
		printf("%lf\n",(l+r)/2);
	}

}

