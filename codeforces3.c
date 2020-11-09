#include<stdio.h>
#define q 1000000007
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		long long int n,ans,ans1,u;
		scanf("%lld",&n);
		n=n+1;
		if(n%2==0)
		{
			u=n/2;
			ans=(n*(n+1) % q);
			ans=(ans*(2*n+1)% q);
			ans=ans/6;
			ans1=(u*(u+1) % q);
			ans1=(ans1*(2*u+1)% q);
			ans1=ans1/6;
			ans1=(ans1*4)%q;
			ans=ans+ans1;	
			
		}
		long long int ans3;
		if(n%2==1)
		{
			ans3=(n*n)% q;
			n=n-1;
			u=n/2;
			ans=(n*(n+1) % q);
			ans=(ans*(2*n+1)% q);
			ans=ans/6;
			ans1=(u*(u+1) % q);
			ans1=(ans1*(2*u+1)% q);
			ans1=ans1/6;
			ans1=(ans1*4)%q;
			ans=ans+ans1+ans3;	
			
		}

		printf("%lld",ans);
		
	}
}
