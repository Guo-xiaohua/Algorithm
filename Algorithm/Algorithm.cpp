#include <iostream>
#include <vector>

/*
 * 对差分数组arr2,有arr2[i][j] = arr[i][j] - arr[i-1][j] - arr[i][j-1] + arr[i-1][j-1]
 * 对差分数组做二维的前缀和可得到原始数组
 */


void insert(int x1,int y1,int x2,int y2,int q,std::vector<std::vector<long long>>& arr)
{
    arr[x1][y1] += q;
    arr[x1][y2+1] -= q;
    arr[x2+1][y1] -= q;
    arr[x2+1][y2+1] += q;
}

int main()
{
    int n,m,q;
    std::cin>>n>>m>>q;
    // 原始数组
    std::vector<std::vector<long long>> arr(n+1,std::vector<long long>(m+1,0));
    // 二维差分数组
    std::vector<std::vector<long long>> arr2(n+1,std::vector<long long>(m+1,0));
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            std::cin>>arr[i][j];
            insert(i,j,i,j,arr[i][j],arr2);
        }
    }

    while (q--)
    {
        int x1,y1,x2,y2,k;
        std::cin>>x1>>y1>>x2>>y2>>k;
        insert(x1-1,y1-1,x2-1,y2-1,k,arr2);
    }

    // 对差分数组做前缀和得到最终数组
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (i-1<0 && j-1<0)
                arr[i][j] = arr2[i][j];
            else if (i-1<0 && j-1>=0)
                arr[i][j] = arr2[i][j] + arr[i][j-1];
            else if (j-1<0 && i-1>=0)
                arr[i][j] = arr2[i][j] + arr[i-1][j];
            else if (i-1>=0 && j-1>=0)
                arr[i][j] = arr2[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];

            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    
    return 0;
}