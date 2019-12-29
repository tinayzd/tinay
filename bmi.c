#include<stdio.h>
int main ()
{
	int x;
	float y,sum;
	scanf("%d%f", &x, &y);
	sum=x/(y*y);
	printf("%.2f\n", sum);
	if(sum < 18.5)
	{
		printf("Underweight");
	}
	if(18.5 <= sum &&  sum < 25)
	{
		printf("Normal");
	}
	if(25 <= sum  && sum < 30)
	{
		printf("Overweight");
	}
	if(30 <= sum )
	{
		printf("Obese");
	}
}
