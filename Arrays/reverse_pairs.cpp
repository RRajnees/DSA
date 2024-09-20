/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].


Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
*/
int countFunc(vector<int> &nums, int low ,int mid, int high){
    // int j = mid+1;
    // int count=0;
    // for(int i=0;i<=mid ;i++){
    //     while(j <= high && long (nums[i]) > long (2*nums[j])){
    //         j++;
    //     }
    //     count = count + j-(mid+1);
    // }
    // return count;
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high &&long(nums[i]) > 2 * (long long)nums[right]) right++;
        cnt += (right - (mid + 1));
    }
return cnt;
}

void merge(vector<int> &nums, int low ,int mid, int high){
    vector<int> temp;
    int l = low, r = mid+1;
    //int count =0;
    while(l <= mid && r <= high){
        if(nums[l] > nums[r]){
            temp.push_back(nums[r]);
            r++;
        }
        else{
            temp.push_back(nums[l]);
            l++;
        }
    }
    while(l <= mid){
        temp.push_back(nums[l]);
        l++;
    }
    while(r <= high){
        temp.push_back(nums[r]);
        r++;
    }
    for(int i=low;i<=high;i++){
        nums[i] = temp[i-low];
    }
    //return count;
}
int mergeSort(vector<int> &nums, int low , int high){
    if(low >= high)
        return 0;
    int count = 0;
    int mid = (high+low)/2;
    count+=mergeSort(nums,low,mid);
    count+=mergeSort(nums,mid+1,high);
    count += countFunc(nums,low, mid , high);
    merge(nums,low, mid , high);
    return count;
}
int reversePairs(vector<int>& nums) {
    return mergeSort(nums,0,nums.size()-1);
}
int main(){
    vector<int> nums = {2,4,3,5,1};
    cout << reversePairs(nums)<< " ";
    return 0;
}
