/*
The solution can be further optimized by observing that while traversing the two sorted arrays parallelly, 
if we encounter the jth second array element is smaller than ith first array element, then jth element is to be 
included and replace some kth element in the first array. 
This observation helps us with the following algorithm

Algorithm

1) Initialize i,j,k as 0,0,n-1 where n is size of arr1 
2) Iterate through every element of arr1 and arr2 using two pointers i and j respectively
    if arr1[i] is less than arr2[j]
        increment i
    else
        swap the arr2[j] and arr1[k]
        increment j and decrement k

3) Sort both arr1 and arr2 

Time Complexity: The time complexity while traversing the arrays in while 
loop is O(n+m) in worst case and sorting is O(nlog(n) + mlog(m)). So overall time complexity of the 
code becomes O((n+m)log(n+m)).

Space Complexity: As the function doesn’t use any extra array for any operations, the space complexity is O(1).

DRY RUN
 
i=0
j=0
k=5             
ar1[] = { 1, 5, 9, 10, 15, 20 };
ar2[] = { 2, 3, 8, 13 };

             i
ar1[] = { 1, 5, 9, 10, 15, 20 };
ar2[] = { 2, 3, 8, 13 };
          j
          
 swap(2,20)         
ar1[] = { 1, 5, 9, 10, 15, 20 };
ar2[] = { 2, 3, 8, 13 };
               
             i          k
ar1[] = { 1, 5, 9, 10, 15, 2 };
ar2[] = { 20, 3, 8, 13 };
              j
              
 swap(3,15)         
ar1[] = { 1, 5, 9, 10, 3, 2 };
ar2[] = { 20, 15, 8, 13 };

             i      k
ar1[] = { 1, 5, 9, 10, 3, 2 };
ar2[] = { 20, 15, 8, 13 };
                  j


                 i  k
ar1[] = { 1, 5, 9, 10, 3, 2 };
ar2[] = { 20, 15, 8, 13 };
                  j

swap(8,10)                  
ar1[] = { 1, 5, 9, 8, 3, 2 };
ar2[] = { 20, 15, 10, 13 };

sort both arrays now
ar1[] = { 1,2,3,5,8,9 };  
ar2[] = { 10,13,15,20};
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

// Function to merge two arrays
void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;
   
    // Untill i less than equal to k or j is less tha m
    while (i <= k and j < m) {
        if (arr1[i] < arr2[j])
            i++;
        else {
            swap(arr2[j++], arr1[k--]);
        }
    }
   
    // Sort first array
    sort(arr1, arr1 + n);
   
    // Sort second array
    sort(arr2, arr2 + m);
}

// Driver Code
int main()
{
 
    int ar1[] = { 1, 5, 9, 10, 15, 20 };
    int ar2[] = { 2, 3, 8, 13 };
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    merge(ar1, ar2, m, n);
 
    cout << "After Merging \nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << ar1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << ar2[i] << " ";
    return 0;
}
