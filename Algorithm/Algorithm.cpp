#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void QuickSort(vector<int>& vec,int min,int max)
{
    if (min>=max) return ;
    
    int pivot=vec[min];
    int i=min;
    int j=max;
    bool bIsRight=true;
    
    while (i<j)
    {
        if (bIsRight)
        {
            if (vec[j]<pivot)
            {
                vec[i++]=vec[j];
                bIsRight=false;
                continue;
            }
            j--;
        }
        else
        {
            if (vec[i]>pivot)
            {
                vec[j--]=vec[i];
                bIsRight=true;
                continue;
            }
            i++;
        }
    }
    vec[i]=pivot;

    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    QuickSort(vec,min,i-1);
    QuickSort(vec,i+1,max);
}

/*
 * 快速排序    递归实现
 * 两个指针,一个指头,一个指尾
 * 默认最左边为待比较对象,一次排序实现左边全比待比较对象小,右边全比待比较对象大
 * 然后对左右两边分别念进行快速排序
 */

int main()
{
    vector<int> vec = {9,8,7,6,5,4,3,2,1};

    QuickSort(vec,0,vec.size()-1);
    
    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;    
}

