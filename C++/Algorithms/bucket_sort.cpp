// C++ program to sort an array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
void bucketSort(float arr[], int n)
{
     
    //Create n empty buckets
    vector<float> b[n];
 
    //Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];			 // Index in bucket
        b[bi].push_back(arr[i]);
    }
 
    //Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 
    //Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
 
int main()
{
	//You can change the numbers or the quantity
    float arr[]
        = {0.586, 0.999, 0.145, 0.6532, 0.1243, 0.475};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
