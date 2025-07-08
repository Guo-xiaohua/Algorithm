#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {9,8,7,6,5,4,3,2,1};


    for (int i=0;i<vec.size()-1;i++)
    {
        for (int j=i+1;j>0;j--)
        {
            if (vec[j-1]>vec[j])
            {
                int temp = vec[j-1];
                vec[j-1] = vec[j];
                vec[j] = temp;
            }
        }
    }
    
    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;    
}

