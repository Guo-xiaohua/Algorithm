#include <iostream>

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

数据范围：
1≤n≤40
要求：
时间复杂度： O(n) ，
空间复杂度： O(1)
 */

/*
 * 从1开始,一级台阶只有1中解法
 * 二级台阶只有两种解法
 * 对于三级台阶,要么是从一级台阶上来,要么从二级台阶上来   共有 一级+二级 种解法
 * 以此类推,对于n级台阶,共有  f(n) = f(n-1) + f(n-2) 种解法
 */

int main()
{
    int n;
    std::cin >> n;

    if (n<3)
    {
        std::cout << n;
        return 0;
    }
    int i=2;
    int fn1 = 1;
    int fn2 = 2;
    while (++i <= n)
    {
        int f = fn1 + fn2;
        fn1 = fn2;
        fn2 = f;
    }

    std::cout<<fn2<<std::endl;
    return 0;
}