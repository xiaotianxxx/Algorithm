#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxlen = 100005;
int nums[maxlen];

void quick_sort(int *nums, int l,int r)
{
    if(l>=r)    return;
    int pivot = nums[l+r>>1];
    int i=l-1; int j = r+1;
    while(i<j)
    {
        do i++; while(nums[i]<pivot);
        do j--; while(nums[j]>pivot);
        if(i<j) swap(nums[i], nums[j]);
    }
    quick_sort(nums, l, j); quick_sort(nums, j+1, r);
}

int main()
{
   int n;
   scanf("%d ", &n);
   for(int i=0; i<n; i++)
   {
       scanf("%d ", &nums[i]);
   }
   quick_sort(nums, 0 ,n-1);
   for(int i=0; i<n; i++)
   {
       printf("%d ", nums[i]);
   }
   return 0;
}