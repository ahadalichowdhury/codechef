#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int sum=0;
        int digit,num;
        cin>> num;
        while(num>0)
        {
            digit=num%10;
            sum=sum+digit;
            num=num/10;
            
        }
        cout<< sum << endl;
        
    }
    
    
    return 0;    
}

