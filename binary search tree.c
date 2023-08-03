#include <stdio.h>
#include <limits.h>
int main() 
{
int n;
printf("Enter the number of keys: ");
scanf("%d", &n);
double keys[n], freq[n];
printf("Enter the keys and their corresponding frequencies:\n");
for (int i = 0; i < n; i++)
scanf("%lf %lf", &keys[i], &freq[i]);
double dp[n][n];
for (int i = 0; i < n; i++)
dp[i][i] = freq[i];
for (int length = 2; length <= n; length++) 
{
for (int i = 0; i <= n - length + 1; i++) 
{
int j = i + length - 1;
dp[i][j] = INT_MAX;
for (int r = i; r <= j; r++) 
{
double cost = ((r > i) ? dp[i][r - 1] : 0) + ((r < j) ? dp[r + 1][j] : 0);
for (int k = i; k <= j; k++) 
{
cost += freq[k];
}
if (cost < dp[i][j])
dp[i][j] = cost;
}
}
}
double cost = dp[0][n - 1];
printf("The cost of the optimal binary search tree is: %lf\n", cost);
return 0;
}

