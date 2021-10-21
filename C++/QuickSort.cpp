#include <iostream>
using namespace std;

int partition(int a[],int strt,int end){
	int count=0;
	int pivot = a[strt];
	for(int i=strt;i<=end;i++){
		if(a[i]<pivot)
			count++;
	}
	int temp = a[count+strt];
	a[count+strt]=a[strt];
	a[strt] = temp;
	
	int pi = count+strt;
	
	int i=strt,j=end;
	while (i<pi and j>pi){
		if(a[i]<=a[pi]){
			i++;
		}
		else if(a[j]>= a[pi]){
			j--;
		}
		else{
			int temp = a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	return pi;
}

void QuickSort(int a[],int strt,int end){
	if(strt < end ){
		int c=partition(a,strt,end);
		QuickSort(a,strt,c-1);
		QuickSort(a,c+1,end);
	}
}

int main(){
	int n;
	cout<<"Enter the size of an array :";
	cin>>n;
	int *arr = new int [n];
	cout<<"Enter the array elements :";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Array before sorting :";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	QuickSort(arr,0,n-1);
	cout<<"Array after sorting :";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	delete []arr;
	return 0;
}