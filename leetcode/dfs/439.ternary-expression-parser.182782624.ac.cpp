/*
 * [439] Ternary Expression Parser
 *
 * https://leetcode.com/problems/ternary-expression-parser/description/
 *
 * algorithms
 * Medium (52.06%)
 * Total Accepted:    12.3K
 * Total Submissions: 23.6K
 * Testcase Example:  '"T?2:3"'
 *
 * Given a string representing arbitrarily nested ternary expressions,
 * calculate the result of the expression. You can always assume that the given
 * expression is valid and only consists of digits 0-9, ?, :, T and F (T and F
 * represent True and False respectively).
 * 
 * Note:
 * 
 * The length of the given string is ≤ 10000.
 * Each number will contain only one digit.
 * The conditional expressions group right-to-left (as usual in most
 * languages).
 * The condition will always be either T or F. That is, the condition will
 * never be a digit.
 * The result of the expression will always evaluate to either a digit 0-9, T
 * or F.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "T?2:3"
 * 
 * Output: "2"
 * 
 * Explanation: If true, then result is 2; otherwise result is 3.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "F?1:T?4:5"
 * 
 * Output: "4"
 * 
 * Explanation: The conditional expressions group right-to-left. Using
 * parenthesis, it is read/evaluated as:
 * 
 * ⁠            "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 :
 * 5))"
 * ⁠         -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
 * ⁠         -> "4"                                    -> "4"
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "T?T?F:5:3"
 * 
 * Output: "F"
 * 
 * Explanation: The conditional expressions group right-to-left. Using
 * parenthesis, it is read/evaluated as:
 * 
 * ⁠            "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) :
 * 3)"
 * ⁠         -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
 * ⁠         -> "F"                                    -> "F"
 * 
 * 
 */
/*
 * [439] Ternary Expression Parser
 *
 * https://leetcode.com/problems/ternary-expression-parser/description/
 *
 * algorithms
 * Medium (52.06%)
 * Total Accepted:    12.3K
 * Total Submissions: 23.6K
 * Testcase Example:  '"T?2:3"'
 *
 * Given a string representing arbitrarily nested ternary expressions,
 * calculate the result of the expression. You can always assume that the given
 * expression is valid and only consists of digits 0-9, ?, :, T and F (T and F
 * represent True and False respectively).
 * 
 * Note:
 * 
 * The length of the given string is ≤ 10000.
 * Each number will contain only one digit.
 * The conditional expressions group right-to-left (as usual in most
 * languages).
 * The condition will always be either T or F. That is, the condition will
 * never be a digit.
 * The result of the expression will always evaluate to either a digit 0-9, T
 * or F.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "T?2:3"
 * 
 * Output: "2"
 * 
 * Explanation: If true, then result is 2; otherwise result is 3.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "F?1:T?4:5"
 * 
 * Output: "4"
 * 
 * Explanation: The conditional expressions group right-to-left. Using
 * parenthesis, it is read/evaluated as:
 * 
 * ⁠            "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 :
 * 5))"
 * ⁠         -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
 * ⁠         -> "4"                                    -> "4"
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "T?T?F:5:3"
 * 
 * Output: "F"
 * 
 * Explanation: The conditional expressions group right-to-left. Using
 * parenthesis, it is read/evaluated as:
 * 
 * ⁠            "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) :
 * 3)"
 * ⁠         -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
 * ⁠         -> "F"                                    -> "F"
 * 
 * 
 */
class Solution {
public:
    string parseTernary(string expression) {
	//recursion [i]?a:b 
	//if not this format then reach the final digit or char 
	int curr = 0;
	return parse(expression, curr);
    }
private:
    string parse(string& e, int& curr) //must pass reference of curr
    {
	int curr_i = curr;
	if (curr + 1 < e.size() && e[curr+1] == '?')
	{
	    curr += 2;
	    string a = parse(e, curr);
	    string b = parse(e, ++curr);
	    return (e[curr_i] == 'T') ? a : b;
	}
	
	return e.substr(curr++, 1); //actual curr go ahead

    }
};

