#include <stdio.h>

void turn(int x);
int main()
{
	int x;
	printf("please input a decimal number:\n");
	scanf("%d",&x);
	if(x<0)
	{
		printf("Please input a number >=0");
		return 0; 
	}
	turn(x);
	return 0; 
}

void turn(int x)
{
	int a[100]={0};
	int b[100]={0};
	int c[100]={0};
	int al=0,bl=0,cl=0;
	
	int n=x;
	int i=0;
	while(n!=0)
	{
		a[i++]=n%2;
		n/=2;
	}
	al=i-1;//this is important!because a[i++] makes i more than the real length!
	printf("binary:\n");
	for(i=al;i>=0;i--)//>=0 because al from 0 to a.length
	{
		printf("%d",a[i]);
	}
	printf("\n");
	
	
	i=0;
	while(al>=i){
		if(al-i>=2)
		{
			b[bl++]+=a[i]*1+a[i+1]*2+a[i+2]*4;
			i+=3;
		}
		else if (al-i>=1)
		{
			b[bl++]+=a[i]*1+a[i+1]*2;
			i+=2;
		}
		else if (al-i>=0)
		{
			b[bl++]+=a[i]*1;
			i+=1;
		}
	}
	bl-=1;//bl-1 due to b[bl++] makes bl more than the real b.length
	printf("octal:\n");
	for(i=bl;i>=0;i--)
	{
		printf("%d",b[i]);
	}
	printf("\n");
	
	i=0;
	while(al>=i){
		if(al-i>=3)
		{
			c[cl++]+=a[i]*1+a[i+1]*2+a[i+2]*4+a[i+3]*8;
			i+=4;
		}
		else if(al-i>=2)
		{
			c[cl++]+=a[i]*1+a[i+1]*2+a[i+2]*4;
			i+=3;
		}
		else if (al-i>=1)
		{
			c[cl++]+=a[i]*1+a[i+1]*2;
			i+=2;
		}
		else if (al-i>=0)
		{
			c[cl++]+=a[i]*1;
			i+=1;
		}
	}
	cl-=1;
	printf("hexadecimal:\n");
	for(i=cl;i>=0;i--)
	{
		if(c[i]>=10)
		{
			printf("%c",(char)c[i]-10+'A');
		}
		else printf("%d",c[i]);
	}
	printf("\n");
}
