#include <stdio.h>
int main() 
{
int n, k;
printf("Enter the values of n and k (n choose k): ");
scanf("%d %d", &n, &k);
int dp[n + 1][k + 1];
for (int i = 0; i <= n; i++) 
{
for (int j = 0; j <= k && j <= i; j++) 
{
if (j == 0 || j == i)
dp[i][j] = 1;
else
dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
}
}
int result = dp[n][k];
printf("C(%d, %d) = %d\n", n, k, result);
return 0;
}

