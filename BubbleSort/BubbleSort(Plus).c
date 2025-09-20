#include<stdio.h>
#include<stdbool.h>

void Swap(int *x,int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
//升序
bool Greater(int x,int y)
{
    return x > y;
}
//降序
bool Less(int x,int y)
{
    return x < y;
}

//冒泡排序,利用回调函数
void BubbleSort(int *p,int n,bool(*q)(int,int))
{
    for(int i = 0;i < n-1;++i)
    {
        bool swapped = false;
        for(int j = 0;j < n-i-1;++j)
        {
            if(q(p[j],p[j+1]))
            {
                Swap(&p[j],&p[j+1]);
                swapped = true;//发生交换
            }
        }
        if(!swapped)//未交换
        {
            break;
        }
    }
}
//打印数组
void PrintArray(int arr[],int n)
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
    printf("升序排列：");
    BubbleSort(arr,n,Greater);
    PrintArray(arr,n);
    putchar(10);
    printf("降序排列：");
    BubbleSort(arr,n,Less);
    PrintArray(arr,n);
    putchar(10);
    return 0;
}
