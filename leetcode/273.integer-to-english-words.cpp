/*
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words
 *
 * algorithms
 * Hard (22.36%)
 * Total Accepted:    47K
 * Total Submissions: 210.3K
 * Testcase Example:  '123'
 *
 * 
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 231 - 1.
 * 
 * 
 * For example,
 * 
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 */
class Solution {
    static const string below_20[];
    static const string below_100[];
#define BILLION 1000000000
#define MILLION 1000000
    static string int_string_rec(int n){
	if(n >= BILLION) return int_string_rec(n/BILLION) + " Billion" + int_string_rec(n - BILLION*(n/BILLION));
	else if(n >= MILLION) return int_string_rec(n / MILLION) + " Million" + int_string_rec(n - MILLION*(n/MILLION));
	else if(n >= 1000) return int_string_rec(n/1000) + " Thousand" + int_string_rec(n - 1000*(n/1000));
	else if(n >= 100) return int_string_rec(n/100) + " Hundred" + int_string_rec(n - 100*(n/100));
	else if(n >= 20) return " " + below_100[n/10 - 2] + int_string_rec(n - 10*(n/10));
	else if(n >= 1) return " " + below_20[n - 1];
	else return "";
    }
public:
    string numberToWords(int num) {
       if(num == 0) return "Zero";
       else if (num > INT_MAX) return "";
       
       return int_string_rec(num).substr(1);
    }
};

const string Solution::below_20[] = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", 
                 "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
const string Solution::below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
