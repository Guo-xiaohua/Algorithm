#include <iostream>
#include <stack>
#include <vector>

struct Position
{
    int x,y;
    int Size;
    
    Position(int a=0,int b=0,int size=0):x(a),y(b),Size(size){}
};

int main() 
{
    int n,m;
    std::cin>>n>>m;
    // 输入起点与终点坐标
    int Xs,Ys,Xe,Ye;
    std::cin>>Xs>>Ys>>Xe>>Ye;
    
    std::vector<std::vector<char>> arr(n+1,std::vector<char>(m+1,' '));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            std::cin>>arr[i][j];
        }
    }

    if (arr[Xe][Ye] == '*')
    {
        std::cout<<"-1"<<std::endl;
        return 0;
    }
    if (Xs == Xe && Ys == Ye)
    {
        std::cout<<"0"<<std::endl;
        return 0;
    }

    std::vector<std::vector<bool>> visited(n+1,std::vector<bool>(m+1,false));
    std::stack<Position> Stack;
    Stack.push(Position(Xs,Ys,0));
    int MinSize = INT_MAX;

    int NewX[4]{1,-1,0,0};
    int NewY[4]{0,0,-1,1};
    
    while (!Stack.empty())
    {
        Position p = Stack.top();
        Stack.pop();

        if (p.x == Xe && p.y == Ye)
        {
            MinSize = std::min(MinSize,p.Size);
            break;
        }
        
        // 检查4个方向能不能走
        for (int i=0;i<4;i++)
        {
            int nx = p.x + NewX[i];
            int ny = p.y + NewY[i];

            // 边界检查
            if (nx<1 || nx>n || ny<1 || ny>m)
                continue;

            if (arr[nx][ny] != '*' && arr[nx][ny] != ' ' && !visited[nx][ny])
            {
                Stack.push(Position(nx,ny,p.Size+1));
                visited[nx][ny] = true;
            }
        }
    }
    if (MinSize!=INT_MAX)
        std::cout<<MinSize<<std::endl;
    else
        std::cout<<"-1"<<std::endl;

    return 0;
}
