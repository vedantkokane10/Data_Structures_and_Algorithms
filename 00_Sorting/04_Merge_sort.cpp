#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high){
	vector<int> left,right;
	for(int i=low;i<=mid;i++){
		left.push_back(arr[i]);
	}
	for(int i=mid+1;i<=high;i++){
		right.push_back(arr[i]);
	}
	int i = 0;
	int j = 0;
	int k = low;
	while(i < left.size() && j < right.size()){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while(i < left.size()){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j < right.size()){
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &arr,int low,int high){
	if(low >= high){
		return;
	}
	int mid = (low+high)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
}


int main(){
	vector<int> arr= {1,3,6,4,7,2};
	int n = 6;
	// vector<int> arr = {6,2,1,4,3,4,7};
	// int n = 7;

	mergeSort(arr,0,n-1);

	for(auto x:arr){
		cout<<x<<" ";
	}
	return 0;
}

// Worst / Avg  ==> O(nlogn)
// Best ==> O(N) + O(N) (Recursion Stack space)
