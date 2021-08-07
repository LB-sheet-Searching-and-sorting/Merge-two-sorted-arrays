#include<iostream>                       
#include<cstdlib>       //to dynamically allocate memory

using namespace std;

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void PrintArray(int a[],int n)
{
	cout<<"\n";
	cout<<" { ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<" } ";
}

void merge(int a1[],int a2[],int m,int n)
{
	int j;
	//iterate through all the elements of a2[] starting from last element.
	for(int i=n-1;i>=0;i--)
	{
		//find the smallest element which is  > a2[i] and move all elements one position ahead from that element.
		//below line of code implements these two conditions at once.
		
		//preserving last element of first array
		int last=a1[m-1];
		
		//i tracks a2[] and j tracks a1[]
		for(j=m-2;(j>=0 && (a1[j]>a2[i]));j--) //m-2 isiliye bcoz (m-2)+1 == m-1
		{
			a1[j+1]=a1[j];
		}
		//this for loop breaks at that j  when a1[j]<a2[i]
		//after shifting all the elements till j_critical,swap last element of a1[] and put a2[j] in right place
		//swap tabhi karo when any of the 2 conditions hold
		if(last>a2[i] || j!=m-2)
		{
			a1[j+1]=a2[i];  //j pe loop break hua so j+1 tak shift hua hai.
			a2[i]=last;    //last element ko leke aao 2nd array me
		} 
	}
	
}

int main()
{
	int *a1,*a2,i,j,m,n;
	
	cout<<"\n\nArray 1";
	cout<<"\t\t\nHow many elements do you want? => ";
	cin>>m;
	
	//allocating array dynamically
	a1=(int*)malloc(m*sizeof(int));
	
	cout<<"\t\nPlz start filling your elements one by one.";

	//feeding the array 1
	for(i=0;i<m;i++)
	{
		cout<<"\n\nElement no "<<i+1<<" ";
		cin>>a1[i];
	}

////////////////////////////////////////////////////////////////////////////////////
	cout<<"\n\nArray 2";
	cout<<"\t\t\nHow many elements do you want? => ";
	cin>>n;
	
	//allocating array dynamically
	a2=(int*)malloc(n*sizeof(int));
	
	cout<<"\t\nPlz start filling your elements one by one.";

	//feeding the array 2
	for(i=0;i<n;i++)
	{
		cout<<"\n\nElement no "<<i+1<<" ";
		cin>>a2[i];
	}
	
////////////////////////////////////////////////////////////////////////////////
	//corner cases ko check karnenge
	if(m<0 || n<0)
	{
		cout<<"\nSize can't be negative!";
	}
	else if(m==0 && n>0)
	{
		cout<<"\nThe merged array is => \n";
		PrintArray(a2,n);
	}
	else if(n==0 && m>0)
	{
		cout<<"\nThe merged array is => \n";
		PrintArray(a1,m);
	}
	else
	{
		cout<<"\nElse is executed!";
		merge(a1,a2,m,n);
		
		cout<<"\nThe merged array is => \n";
		PrintArray(a1,m);
		PrintArray(a2,n);
	}
	
	
return 0;
}
