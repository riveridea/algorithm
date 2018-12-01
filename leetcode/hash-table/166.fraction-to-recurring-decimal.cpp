/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (18.78%)
 * Total Accepted:    77.2K
 * Total Submissions: 411K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * Example 1:
 * 
 * 
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * Example 3:
 * 
 * 
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * 
 * 
 */
class Solution {
public:
    string fractionToDecimal(int nn, int dd) {
	//this problem has several corner cases:
	//1. deterine the sign
	//2. determin if there is no fractinoal part
	//3. most important, determine if the fractional is repeating, using map
	//4. don't forget if d is zero.
	string res;

	if(nn == 0) return "0"; 

	if(nn < 0 ^ dd < 0)  res += '-';

	//remove the sign
	int64_t n = abs(nn), d = abs(dd);
	//cout << n << "," << d << endl;
	if(n < 0)  n *= -1;
	if(d < 0)  d *= -1;
	res += to_string(n/d);
	if(n % d == 0) return res;

	unordered_map<int, int> m;
	
	res += '.';
	for(int64_t r = n%d; r > 0; r = r%d)
	{
	    //check if the r is already in the map, determine we met a repeating fractional 
	    if(m.count(r) > 0)
	    {
		res.insert(m[r], 1, '(');
		res += ')';
		break;
	    }
	   
	    //rember the position of the r in the res
	    m[r] = res.size();
	    
	    //every time use a new 10*r to get the fractional part
	    r *= 10;

	    //append the r to res
	    //cout << "[r:" << r << "/" << "d:" << d << "]";
	    res += to_string(r/d);
	    //cout << res << "|";
	}
	return res;
    }
};
