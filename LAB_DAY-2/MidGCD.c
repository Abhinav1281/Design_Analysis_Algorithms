#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b;
	printf("Enter numbers=");
	scanf("%d%d",&a,&b);
	int size= a>=b ? b : a;
	size++;
	int ara[size];
	int arb[size];
	for(int i=0;i<size;i++)
	{
		ara[i]=0;
		arb[i]=0;
	}
	for(int i=2;i<size;)
	{
		if(a%i==0)
		{
			ara[i]+=1;
			a/=i;
			//printf("%dx",i);
			continue;
		}
		else
			i++;
	}
	for(int i=2;i<size;)
	{
		if(b%i==0)
		{
			arb[i]+=1;
		 	//printf("%dx",i);
			b/=i;
			continue;
			
		}
		else
			i++;
	}
	int gcd=1;
	for(int i=2;i<size;i++)
		if(ara[i]!=0 && arb[i]!=0)
			gcd*= (ara[i]<=arb[i] ? ara[i] :arb[i]) * i;
	
	printf("\nGCD=%d\n",gcd);
}
