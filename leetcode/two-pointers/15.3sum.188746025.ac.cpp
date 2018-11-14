class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort the array firstly, then 
        int len = nums.size();
        vector<vector<int>> result;
        if(len < 3) return result;
        sort(nums.begin(), nums.end());
        
        const int target = 0;
        for(int i = 0; i < len - 2; i++)
        {
	    //cut the impossibles
	    if(nums[i] + nums[len-2] + nums[len-1] < target) continue;
	    if(nums[i] + nums[i+1] + nums[i+2] > target) break; 
	    //handle duplicates
	    if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1; //start from the next one
            int k = len - 1; //right staret from the last one
            
            //start scan both j and k to find all possible solutions
            //need to hanld duplicates
            while(j < k)
            {
                //1. less thank target
                if(nums[i] + nums[j] + nums[k] < target)
                {
                    //need to find  a bigger *j
                    ++j;
                    //handle possible duplicates
                    //while(*j == *(j-1) && j<k) ++j; 
                }
                else if (nums[i] + nums[j] + nums[k] > target)
                {
                    //need to find a less *k
                    --k;
                    //handle possible duplicates
                    //while(*k == *(k+1) && j<k) --k;
                }
                else
                {
                    //got an answer
                    result.push_back({nums[i], nums[j], nums[k]});
                    //update j and k, bigger and less
                    do{j++;}while((nums[j] == nums[j-1]) && j<k);
                    do{k--;}while((nums[k] == nums[k+1]) && j<k);
                }
            }
        }
        return result;
    }
};
