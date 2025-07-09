#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int n, m, x, y;
int main()
{
    cin>>n>>m;
    // 记录所有节点的入度
    vector<int> inds(n + 1, 0);
    // 图
    vector<vector<int>> tu(n+1);
    // 图的读取
    while (m--)
    {
        cin>>x>>y;
        // 记录节点的入度
        inds[y]++;
        tu[x].push_back(y);
    }

    // 排序用的辅助队列,仅将入度为0的点放入
    queue<int> que;

    // 遍历图,将入度为0的点入队
    for (int i=1;i<=n;i++)
    {
        if (inds[i] == 0)
            que.push(i);
    }

    // 处理队列,将入度为0的点出队,并将其指向的点入度-1,
    // 若该点入度为0,则入队
    vector<int> ans;
    while (!que.empty())
    {
        int i = que.front();
        que.pop();
        ans.push_back(i);
        for (int j=0;j<tu[i].size();j++)
        {
            if (tu[i][j]>0)
            {
                inds[tu[i][j]]--;
                if (inds[tu[i][j]] == 0)
                    que.push(tu[i][j]);
            }
        }
    }

    // 输出
    if (ans.size()!=n)
        cout<<-1<<endl;
    else
    {
        for (int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
            if (i+1<ans.size())
                cout<<" ";
        }
    }
    
    return 0;
}