#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[6] = {1,3,6,4,7,2};
	int n = 6;
	// Selection Sort
	for(int i=0;i<n;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if(min != i){
			swap(arr[i],arr[min]);
		}
	}

	for(auto x:arr){
		cout<<x<<" ";
	}
	return 0;
}

// Worst / Avg / Best ==> O(n^2)
