// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;
 
// function returns the index of largest element 
// smaller than equal to 'x' in 'arr'. For duplicates
// it returns the last index of occurrence of required
// element. If no such element exits then it returns -1. 
int binary_search(int arr[], int l, int h, int x);

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
void countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n);

// Driver program to test above
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif


    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        countEleLessThanOrEqual(arr1, arr2, m, n);
        cout<<endl;
    }
    return 0;
}


void countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n)
{
	sort(arr2, arr2+n);

	for (int i = 0; i < m; i++)
		cout << distance(arr2, upper_bound(arr2, arr2+n, arr1[i])) << " ";
}