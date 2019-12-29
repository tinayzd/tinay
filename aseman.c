#include<stdio.h>
int main ()
{
int x,y,i,j,count=0;
char n;
scanf("%d %d", &x, &y);
for(i=1; i<=x ; i++)
{
	for(j=1; j<=y ; j++)
	{
		scanf(" %c", &n );
		if(n=='*')
			count++;
	}
	
}
		printf("%d", count);
}
