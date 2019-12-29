#include<stdio.h>
int main ()
{
int x=1,n,y=1;
scanf("%d", &n);
while( x<=n )
{
	y=y*x;
	if(x==n)
	{
	printf("%d", y);
	}
	x++;
}
}
