/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n*m-1;
        int mid;
        while(low <= high){
            mid = (high+low)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] < target){
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return false;
    }

    int main(){
        int target =13;
        vector<vector<int>> matrix ={{1,3,5,7},{10,11,16,20},{23,30,34,60}};

        cout<< searchMatrix(matrix,target);
    }
