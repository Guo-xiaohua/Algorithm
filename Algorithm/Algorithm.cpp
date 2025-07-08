#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void ShellSort(vector<int>& vec,int n)
{
    int gap = n;

    while (gap>1)
    {
        gap = gap/2;

        for (int i=gap;i<n;i++)
        {
            if (vec[i] < vec[i - gap])
            {
                int tmp = vec[i];
                int j;
                for (j = i - gap; j >= 0 && vec[j] > tmp; j-=gap)//这里是j-=gap
                {
                    vec[j + gap] = vec[j];
                }
                vec[j + gap] = tmp;
            }
        }
    }
    
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

    ShellSort(vec,vec.size());
    
    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;    
}

