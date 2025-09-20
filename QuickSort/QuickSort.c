#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void QuickSort(int *p,int start,int end)
{
    //当数组内只有一个元素，直接结束
    if(start >= end)
    {
        return;
    }
    int left = start;
    int right = end;
    int base = p[start];
    while(left < right)
    {
        //循环从后往前找比base小的数
        while(p[right] > base && right > left)
        {
            right--;
        }
        //找到比base大的元素后互换位置，且向右移一位
        if(right > left)
        {
            //p[left++] = p[right] 的写法是为了先将right位置的元素放到当前left位置，再将left指针右移一位
            p[left++] = p[right];
        }
        //循环从后往前找比base大数
        while(p[left] < base && left < right)
        {
            left++;
        }
        //找到比base小的元素后互换位置，且向左移一位
        if(left < right)
        {
            p[right--] = p[left];
        }
    }
    //此时left和right重叠，将base放置在合适的位置
    p[left] = base;
    QuickSort(p,start,left-1);
    QuickSort(p,right+1,end);
}

void PrintfArray(int *p,int len)
{
    while(len--)
    {
        printf("%d ",*p++);
    }
    putchar(10);
}
int main()
{
    int arr[1000]={0};
    //srand()是随机数种子初始化函数，用于设置rand()生成随机数的起点。
    //time(NULL)返回当前系统时间的秒数（一个不断变化的整数），用它作为种子可以保证每次程序运行时，
    //rand()生成的随机数序列都不同（否则每次运行可能生成相同的随机数）。
    srand(time(NULL));
    for(int i = 0;i<1000;++i)
    {
    //rand()生成一个 0 到RAND_MAX（通常是 32767）之间的随机整数。
    //% 500 表示对 500 取余，结果会限定在0~499之间（因为任何整数除以 5000 的余数都在 0 到 4999 范围内）。
    //最终将这个 0~499 的随机数赋值给数组的第i个元素arr[i]。
        arr[i] = rand()%500;
    }
    int len = sizeof(arr)/sizeof(arr[0]);
    //len-1:arr[0]开始，数组数-1
    QuickSort(arr,0,len-1);
    PrintfArray(arr,len);
    return 0;
}
