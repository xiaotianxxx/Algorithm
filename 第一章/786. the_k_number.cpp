#include <cstdio>
#include <iostream>
using namespace std;

int  quick_sort(int *arr, int l, int r, int k)
{
    if(l>=r) return arr[l];
    int pivot = arr[l], i = l-1, j = r+1;
    while(l<r)
    {
        do i++; while(arr[i]<pivot);
        do j--; while(arr[j]>pivot);
        if(i<j) swap(arr[i],arr[j]);
        else break;
    }
    if(k<=(j-l+1))  quick_sort(arr,l,j, k);     //在pivot的左边
    else quick_sort(arr,j+1,r, k-(j-l+1));      //在pivot的右边，k需要减去当前层的右段的数量
}
int main()
{
    int n, k;
    int arr[100000];
    cin>>n; cin>>k;
    for(int i=0; i<n; i++)  cin>>arr[i];
    cout<<quick_sort(arr, 0, n-1, k)<<endl;
    return 0;
}