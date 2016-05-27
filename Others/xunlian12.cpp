#include<cstdio>
#include<string>
#include<map>
#include<vector>
using namespace std;
int elements_count,money;
int types_count=0;
const int max_n=1000+5;
map<string,int> types;
int id(string s)
{
	if(types.count(s)==0) types[s]=types_count++;
	return types[s];
}
struct Component{
	int quality;
	int price;
	Component(int a,int b)
	{price=a;quality=b;}
};
vector<Component> elements[max_n];
bool ok(int q)
{
	int sum=0;
	for(int i=0;i<types_count;i++)
	{
		int s=elements[i].size();
		int min_money=money+1;
		for(int j=0;j<s;j++)
		{
			if(elements[i][j].quality>=q){min_money=min(min_money,elements[i][j].price);}
		}
		sum=sum+min_money;
		if(sum>money)
			return false;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		types_count=0;
		scanf("%d%d",&elements_count,&money);
		for(int i=0;i<elements_count;i++)
			elements[i].clear();
		types.clear();
		int max_q=0;
		for(int i=0;i<elements_count;i++)
		{
			char type[30],name[30];
			int price,quality;
			scanf("%s%s%d%d",type,name,&price,&quality);
			elements[id(type)].push_back(Component(price,quality));
			max_q=max(max_q,quality);
		}
		int l=0,r=max_q;
		while(l<r)
		{
			int mid=l+(r-l+1)/2;
			if(ok(mid)) l=mid;else r=mid-1;

		}
		printf("%d\n",l);
	}

}
