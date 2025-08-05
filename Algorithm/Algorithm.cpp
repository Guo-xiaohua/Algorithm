#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    // 数据输入
    std::vector<int> cost(n);
    for (int i = 0; i < n; i++)
        std::cin >> cost[i];

    // 记录买卖状态的数组
    std::vector<std::vector<int>> arr(n, std::vector<int>(2, 0));
    /*
     * arr[i][0] 表示第i天不持有股票的金额
     *      1. 手头的股票已经卖掉了   arr[i][0] = arr[i-1][0];
     *      2. 今天将手头的股票卖掉   arr[i][0] = arr[i-1][1] + cost[i];
     *      arr[i][0] = max(arr[i-1][0],arr[i-1][1] + cost[i]);
     * arr[i][1] 表示第i天持有股票的金额
     *      1. 手头已经有股票        arr[i][1] = arr[i-1][1];
     *      2. 今天买入股票          arr[i][1] = arr[i-1][0] - cost[i];
     *      arr[i][1] = max(arr[i-1][1],- cost[i]);
     */

    arr[0][0] = 0;
    arr[0][1] = 0-cost[0];

    for (int i=1;i<n;i++)
    {
        arr[i][0] = std::max(arr[i-1][0],arr[i-1][1] + cost[i]);
        arr[i][1] = std::max(arr[i-1][1],arr[i-1][0] - cost[i]);
    }

    std::cout<<std::max(arr[n-1][0],arr[n-1][1])<<std::endl;
    
    return 0;
}