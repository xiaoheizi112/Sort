#include<stdio.h>
//冒泡排序
void BubbleSort(int arr[],int n)
{
    int temp,swapped;
    for(int i = 0;i < n-1;++i)
    {
        temp = 0;
        for(int j = 0;j <n-i-1;++j)
        {
            if(arr[j]>arr[j+1])
            {
                swapped = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=swapped;
            }
        }
    }
}
//打印数组
void PrintSort(int arr[],int n)
{
    for(int i = 0;i < n;++i)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[5]={3,5,8,2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("初始顺序：");
    PrintSort(arr,n);
    putchar(10);
    printf("冒泡排序后的顺序：");
    BubbleSort(arr,n);
    PrintSort(arr,n);
    putchar(10);
    return 0;
}