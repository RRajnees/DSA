/*
Problem statement
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]'
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
*/
#include <bits/stdc++.h>
//long long count = 0;
long long merge(long long *arr, int low, int mid , int high){
    int l = low ,  r = mid+1;
    //int k = 0;
    long long count=0;
    vector<long long> temp;
    while(l <= mid && r <= high){
      if (arr[l] <= arr[r]) {
        temp.push_back(arr[l]);
        l++;
       }
     else {
        temp.push_back(arr[r]);
        count += mid - l + 1;
        r++;
      }
    }
    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r <= high){
        temp.push_back(arr[r]);
        r++;
    }
    for(int i= low ; i<= high; i++ ) {
        arr[i] = temp[i-low];
    }
    return count;
}
long long mergeSort(long long *arr, int low , int high){
    if(low >= high) return 0;
    long long  count =0;
    int mid = (high+low)/2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid+1, high);
    count +=merge(arr,low,mid,high);
    return count;
}

long long numberOfInversions(vector<long long>&a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

int main()
{
    vector<long long> a = {5, 4, 3, 2, 1};
    int n = 5;
    long long cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}
