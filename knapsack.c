#include <stdio.h>
struct Item 
{
int value;
int weight;
};
void swap(struct Item *a, struct Item *b) 
{
struct Item temp = *a;
*a = *b;
*b = temp;
}
void sortByRatio(struct Item arr[], int n) 
{
for (int i = 0; i < n; i++) 
{
for (int j = i + 1; j < n; j++) 
{
double ratio1 = (double)arr[i].value / arr[i].weight;
double ratio2 = (double)arr[j].value / arr[j].weight;
if (ratio1 < ratio2) 
{
swap(&arr[i], &arr[j]);
}
}
}
}
int knapsackGreedy(struct Item arr[], int n, int capacity) 
{
sortByRatio(arr, n);
int totalValue = 0;
int currentWeight = 0;

for (int i = 0; i < n; i++) 
{
if (currentWeight + arr[i].weight <= capacity) 
{
currentWeight += arr[i].weight;
totalValue += arr[i].value;
}
}
return totalValue;
}
int main() 
{
int n;
printf("Enter the number of items: ");
scanf("%d", &n);
struct Item items[n];
printf("Enter the value and weight of each item:\n");
for (int i = 0; i < n; i++) 
{
scanf("%d %d", &items[i].value, &items[i].weight);
}
int capacity;
printf("Enter the capacity of the knapsack: ");
scanf("%d", &capacity);
int maxValue = knapsackGreedy(items, n, capacity);
printf("Maximum value that can be put in the knapsack: %d\n", maxValue);
return 0;
}

