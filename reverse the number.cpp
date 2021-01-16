#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int reverse=0;
		int temp;
		cin>>n;
		while(n>0)
		{
			temp=n%10;
			reverse=reverse*10+temp;
			n=n/10;
			
		}
		cout<< reverse<< endl;
	}
	return 0;
}
