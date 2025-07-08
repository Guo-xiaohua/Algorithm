#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {9,8,7,6,5,4,3,2,1};


    for (int i=0;i<vec.size();i++)
    {
        int min = i;
        for (int j=i+1;j<vec.size();j++)
        {
            if (vec[j] < vec[min])
                min = j;
        }
        int temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
    }
    
    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;    
}

