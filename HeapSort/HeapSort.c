#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp; 
}
//root:树节点的下标
//index:数组最后一个元素的下标
void AdjustHeap(int *p,int root,int index)
{
    int child;//父节点的子节点
    for(;2*root+1 <= index;root = child)
    {
        child = 2*root+1;//父节点的左子节点
        //确保父节点左右都有子节点且判断左子节点是否比右子节点小
        if((child+1 <= index) && p[child] < p[child+1])
        {
            child++;
        }
        if(p[child] > p[root])
        {
            Swap(&p[child],&p[root]);
        }
    }
}

void HeapSort(int *p,int len)
{
    //1.构建大顶堆,指向最后一个父节点
    for(int i = len/2-1;i > 0;--i)
    {
        AdjustHeap(p,i,len-1);
    }
    //2.调整大顶堆
    for(int i = len-1;i > 0;--i)
    {
        Swap(&p[0],&p[i]);
        AdjustHeap(p,0,i-1);
    }
}

void PrintfArray(int *p,int len)
{
    for(int i = 0;i <len;++i)
    {
        printf("%d ",p[i]);
    }
    putchar(10);
}

int main(int argc, char const *argv[])
{
    int  arr[1000]={0};
    srand(time(NULL));
    for(int i = 0;i < 1000;++i)
    {
        arr[i] = rand()%500;
    }
    int len = sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr,len);
    PrintfArray(arr,len);
    return 0;
}
