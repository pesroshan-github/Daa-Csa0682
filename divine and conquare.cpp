#include <stdio.h>
struct MaxMin 
{
int max_val;
int min_val;
};
struct MaxMin find_max_min(int arr[],int k,int l){
struct MaxMin result, left, right, temp;
int mid;
if(k==l)
{
result.max_val=result.min_val=arr[k];
return result;
}
if(l==k+1)
{
result.max_val=(arr[k]>arr[l])?arr[k]:arr[l];
result.min_val=(arr[k]<arr[l])?arr[k]:arr[l];
return result;
}
mid=(k+l)/2;
left=find_max_min(arr,k,mid);
right=find_max_min(arr,mid+1,l);
result.max_val=(left.max_val>right.max_val)?left.max_val:right.max_val;
result.min_val=(left.min_val<right.min_val)?left.min_val:right.min_val;
return result;
}
int main() 
{
int arr[]={3,8,1,6,2,7,4,5};
int n=sizeof(arr)/sizeof(arr[0]);
struct MaxMin result=find_max_min(arr,0,n-1);
printf("Max value: %d\n",result.max_val);
printf("Min value: %d\n",result.min_val);
return 0;
}

