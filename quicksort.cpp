#include<bits/stdc++.h>
using namespace std;

int pertition(int a[], int low, int high)
{
	int pivot, i, j, temp;
	pivot=a[high];
	for(i=low-1, j=low; j<high; j++)
	{
		if(a[j]<pivot)
		{
			i+=1;
			
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	temp=a[high];
	a[high]=a[i+1];
	a[i+1]=temp;
	
	return i+1;
	
}

void quick(int a[], int low, int high)
{
	if(low>=high)
	{
		return;
	}
	int p;
	p=pertition(a, low, high);
	
	quick(a, low, p-1);
	
	quick(a, p+1, high);
}


int main()
{
	int a[]={1, 2, 5, 6, 8, 9, 4, 50};
	quick(a, 0, 7);
	
	for(int i=0; i<=7; i++)
	{
		cout<< a[i];
	}
	cout<<endl;
}
