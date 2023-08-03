#include<stdio.h>
int main()
{
int i, a, n, k;
printf("Enter the range: ");
scanf("%d", &n);	
printf("The prime in between the range 1 to %d:",n);
for(a = 1;a<=n;a++)
{
k=0;
for(i=2;i<=a/2;i++)
{
if(a%i==0)
{
k++;
break;
}
}
if(k==0&&a!= 1)
printf("%d ",a);
}
}
