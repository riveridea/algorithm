/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 *
 * https://leetcode.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (33.35%)
 * Total Accepted:    33.9K
 * Total Submissions: 101.6K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * Given an integer array nums, return the number of range sums that lie in
 * [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between
 * indices i and j (i ≤ j), inclusive.
 * 
 * Note:
 * A naive algorithm of O(n2) is trivial. You MUST do better than that.
 * 
 * Example:
 * 
 * 
 * Input: nums = [-2,5,-1], lower = -2, upper = 2,
 * Output: 3 
 * Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective
 * sums are: -2, -1, 2.
 * 
 */
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
	//lets try binary index tree, this is very hard problem
	int n = nums.size();
	if(n == 0) return 0;
	
	vector<long> prefixsum(n, 0);
	prefixsum[0] = nums[0];
	for(int i = 1; i < n; i++){
	    prefixsum[i] = prefixsum[i-1] + nums[i];
	}

	vector<long> osum;
	set<long> st;
	for(int i = 0; i < n; i++)
	{
	    if(st.find(prefixsum[i]) != st.end()) continue;
	    st.insert(prefixsum[i]);
	    osum.push_back(prefixsum[i]);
	}
	sort(osum.begin(), osum.end());
	int m = osum.size();
	//binary index tree
	vector<long> bitree(m+1, 0);
	int ans = 0;
	for(int i = 0; i < n; i++){
	    int l = lower_bound(osum.begin(), osum.end(), prefixsum[i] - upper) - osum.begin();
	    int r = upper_bound(osum.begin(), osum.end(), prefixsum[i] - lower) - osum.begin();
	    //cout << "pfix[" << i << "]=" << prefixsum[i] << " l=" << l << " r=" << r;
	    ans += query(bitree, r) - query(bitree, l);
	    if(prefixsum[i] >= lower && prefixsum[i] <= upper) ans++;
	    update(bitree, upper_bound(osum.begin(), osum.end(), prefixsum[i]) - osum.begin(), m, 1);
	    //cout << "ans=" << ans;
	    //cout <<"\n";
	}
	return ans;
    }

    //binary tree implementation
    void update(vector<long>& btree, int k, int n, int val)
    {
	while(k <= n){
	    btree[k] += val;
	    k += k&(-k);
	}
    }

    int query(vector<long>& btree, int k)
    {
	int sum = 0;
	while(k > 0){
	    sum += btree[k];
	    k -= k&(-k);
	}
	return sum;
    }
};
