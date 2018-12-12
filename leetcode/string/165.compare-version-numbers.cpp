/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (22.00%)
 * Total Accepted:    118.9K
 * Total Submissions: 540.5K
 * Testcase Example:  '"0.1"\n"1.1"'
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 < version2 return -1;otherwise
 * return 0.
 * 
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 * 
 * Example 1:
 * 
 * 
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 * 
 * Example 2:
 * 
 * 
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 * 
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
	//this is an easy but not easy to write correctly
	//from the left to right, compare each number before . 
	//until either of them reach the end of the string
	int n1 = version1.size();
	int n2 = version2.size();

	int val1 = 0;
	int val2 = 0;
	int i = 0; 
	int j = 0;
	//start scan:
	while(i < n1 || j < n2)
	{
	    while(i < n1 && version1[i] != '.')
	    {
		val1 = val1*10 + version1[i] - '0';
		i++;
	    }
	    while(j < n2 && version2[j] != '.')
	    {
		val2 = val2*10 + version2[j] - '0';
		j++;
	    }

	    //check result
	    if(val1 > val2) return 1;
	    else if(val1 < val2) return -1;

	    //reset for next 
	    val1 = 0;
	    val2 = 0;

	    //step to the next, as the '.' does not count yet
	    i++;
	    j++;
	}
	return 0;
    }
};
