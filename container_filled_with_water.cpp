#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int maxArea(vector<int>& height) {
    int max_plostina=0;
    int s=height.size();
    for (int i=0; i<s-1; i++)
    {
        for (int j=i+1; j<s; j++)
        {
            if (min(height[i], height[j])*(abs(i-j))>max_plostina)
            {
                max_plostina=min(height[i], height[j])*(abs(i-j));
            }
        }
    }
    return max_plostina;
}

int main(){
    int n;
    cin>>n;
    vector<int> visini (n);
    for (int i=0; i<n; i++)
    {
        cin>>visini[i];
    }
    cout<<maxArea(visini);
}