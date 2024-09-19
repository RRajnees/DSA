/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]


*/
vector<int> majorityElement(vector<int>& nums) {
    int count1=0 , count2 =0;
    int element1 = INT_MIN , element2 =INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(count1 == 0 && element2 != nums[i]){
            element1 = nums[i];
            count1++;
        }
        else if(count2 ==0 && element1 != nums[i]){
            element2 = nums[i];
            count2++;
        }
        else if(element1 == nums[i]) {
            count1++;
        }
        else if(element2 == nums[i]){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    for(int i=0;i<nums.size();i++){
        if(element1 == nums[i]) count1++;
        if(element2 == nums[i]) count2++;
    }
    vector<int> res;
    if(count1 > nums.size()/3){
        res.push_back(element1);
    }
    if(count2 > nums.size()/3){
        res.push_back(element2);
    }
    return res;
}

int main(){
    vector<int> nums = {3,2,3};
    vecotor<int> res = majorityElement(nums);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}

