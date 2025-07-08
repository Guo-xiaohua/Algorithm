#include <iostream>
#include <stack>
#include <vector>
using namespace std;


/// 
/// @param vec 要维护的数组
/// @param n 数组大小 // 排序使用 
/// @param i 要维护的父节点
void Heapify(vector<int>& vec,int n,int i)
{
    int parent = i;
    int lson = i*2+1;
    int rson = i*2+2;

    if (lson<n && vec[parent]<vec[lson])
        parent=lson;
    if (rson<n && vec[parent]<vec[rson])
        parent=rson;
    if (parent!=i)
    {
        swap(vec[i],vec[parent]);
        Heapify(vec,n-1,parent);
    }
    
}

void HeapSort(vector<int>& vec, int n)
{
    // 建堆 先从数组的最后一个节点开始
    // 下标为i的节点,他的父节点下标为(i-1)/2  // 整数取整
    // 下标为0的点最后一个维护能保证堆顶是最大的,然后递归对其孩子节点进行维护保证大顶堆
    for (int i=n/2-1; i>=0; i--)
        Heapify(vec,n,i);
    
    // 排序
    for (int i=n-1; i>0; i--)
    {
        swap(vec[i],vec[0]);// 将最大的堆顶移到末尾,对剩下的维护大顶堆,保证剩下元素最大的为堆顶
        Heapify(vec,i,0);
    }

    
}

/*
 * 堆排序
 *
 * 父节点下标为 i
 * 左孩子下标 i*2+1
 * 右孩子下标 i*2+2
 *
 * 升序采用大顶堆,及任意一个父节点满足父节点大于连个孩子节点
 */

int main()
{
    vector<int> vec = {9,8,7,6,5,4,3,2,1};

    HeapSort(vec,vec.size());
    
    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;    
}

