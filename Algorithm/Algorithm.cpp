#include <iostream>
#include <vector>

/*
 * 连续子数组
 * 给定一个长度为 n 的数组，数组中的数为整数。
 * 请你选择一个非空连续子数组，使该子数组所有数之和尽可能大。求这个最大值。
 *
 * 从二开始,对当前的节点可以选择拿下或者从头开始(不能选择跳过,不满足连续的要求)
 * 拿与从头开始只看哪种收益最高
 */

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    int maxSum = 0;
    int curentSum = 0;

    std::cin >> curentSum;
    maxSum += curentSum;
    for (int i = 1; i < n; i++)
    {
        int cin;
        std::cin >> cin;
        curentSum = std::max(cin,curentSum+cin);
        maxSum = std::max(maxSum,curentSum);
    }
    std::cout << maxSum;
    return 0;
}