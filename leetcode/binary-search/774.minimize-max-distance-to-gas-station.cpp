/*
 * @lc app=leetcode id=774 lang=cpp
 *
 * [774] Minimize Max Distance to Gas Station
 *
 * https://leetcode.com/problems/minimize-max-distance-to-gas-station/description/
 *
 * algorithms
 * Hard (43.15%)
 * Total Accepted:    11.3K
 * Total Submissions: 26K
 * Testcase Example:  '[1,2,3,4,5,6,7,8,9,10]\n9'
 *
 * On a horizontal number line, we have gas stations at positions stations[0],
 * stations[1], ..., stations[N-1], where N = stations.length.
 * 
 * Now, we add K more gas stations so that D, the maximum distance between
 * adjacent gas stations, is minimized.
 * 
 * Return the smallest possible value of D.
 * 
 * Example:
 * 
 * 
 * Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
 * Output: 0.500000
 * 
 * 
 * Note:
 * 
 * 
 * stations.length will be an integer in range [10, 2000].
 * stations[i] will be an integer in range [0, 10^8].
 * K will be an integer in range [1, 10^6].
 * Answers within 10^-6 of the true value will be accepted as correct.
 * 
 * 
 */
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
	//this is very hard problem
	//please refer to the explanation online
	//use binary search to try candidated D
	//each D we should check if there are more than K intervals 
	//than are greater than D, thus we cannot insert K Gas Station
	//to make the maximum adjacent distance as D, we need to try bigger D
	//if less than K, this D is a possible candidate, we need to try less D
	double l = 0, h = 1e8;
	while(l + 1e-6 < h){
	    double mid = (h + l)/2;
	    int need = 0;
	    for(int i = 0; i < stations.size()-1; i++){
		need += (stations[i+1]-stations[i])/mid;
	    }
	    if(need > K) l = mid;
	    else h = mid;
	}
	return l;
    }
};



































