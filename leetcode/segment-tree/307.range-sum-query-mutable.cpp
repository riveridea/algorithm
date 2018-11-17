/*
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (25.63%)
 * Total Accepted:    57.5K
 * Total Submissions: 224.3K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * 
 * Example:
 * 
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * Note:
 * 
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 * 
 * 
 */
class NumArray {
private:
    vector<int> tree;
    int array_size;

    void build_segtree(vector<int>& nums, int n)
    {
	//init the leaves
	for(int i = 0; i < n; i++)
	    tree[n+i] = nums[i];
	
	//calculate the parents
	for(int i = n-1; i >= 1; i--)
	{
	    // tree[i] = tree[i*2] + tree[i*2 +1 ]
	    tree[i] = tree[i<<1] + tree[i<<1 | 1];
	}

	//print
	for(auto k : tree)
	{
	    cout << k << " "; 
	}
	cout << endl;
    }
public:
    NumArray(vector<int> nums) {
	int n = nums.size(); 
	if(n > 0) tree.resize(2*n, 0);

	array_size = n;

	build_segtree(nums, n);
    }
    
    void update(int i, int val) {
	//update the leaf
	int pos = i + array_size;
	tree[pos] = val; 
	
	//move upward and update all parents
	for(int i = pos; i > 1; i >>= 1)
	{
	    //i^1 is the sibling
	    tree[i>>1] = tree[i] + tree[i^1];
	}
    }
    
    int sumRange(int i, int j) {
	// [i, j] i and j are inclusive 
	// it is important to understand left and right inclusive and exclusive
	int res = 0;

	// for even left and odd right, need to go to parent
	// for odd left, no parent included but itself, and go to its next
	// for even right, no parent included but iself, and go to its previous
	int left = i + array_size, right = j + array_size;
	while(left <= right)
	{
	    //cout << " left = " << left; 
	    //cout << " right = " << right; 
	    if(left&1)
	    {
		res += tree[left++];
	    }
	    left >>= 1;
	    if(!(right&1))
	    {
		res += tree[right--];
	    }
	    right >>= 1;
	    //cout << "then left = " << left; 
	    //cout << "then right = " << right; 
	    //cout << " res = " << res; 
	}
	//cout << " res = " << res; 
	return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
