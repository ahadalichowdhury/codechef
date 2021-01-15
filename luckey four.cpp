#include<bits/stdc++.h>
using namespace std;
void solve()
{
    unsigned long long int n , temp = 0 , count  = 0 ;
    cin>>n;
    
    while(n)
    {
        temp = n%10;
        n/=10;
        if(temp== 4)
        count++;
    }
    
    cout<<count<<"\n";
}

int main()
{
    long long int t;
    cin>>t;
    
    while(t--)
    {
        solve();
    }
    return 0;
}
