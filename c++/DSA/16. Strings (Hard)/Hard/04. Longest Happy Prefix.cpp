/*
QUESTION:
A string is called a happy prefix if it is a non-empty prefix that is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefixes excluding itself ("l", "le", "lev", "leve") and suffixes ("l", "el", "vel", "evel"). The largest prefix that is also a suffix is "l".

Approach:
- We can solve this problem using the KMP (Knuth-Morris-Pratt) algorithm.
- First, we calculate the LPS (Longest Prefix Suffix) array for the given string s.
- The last value in the LPS array, lps[n-1], represents the length of the longest prefix that is also a suffix.
- We extract the corresponding substring from s and return it as the longest happy prefix.

Complexity Analysis:
- The time complexity of this solution is O(n), where n is the length of the string s.
- The space complexity is O(n) to store the LPS array.

CODE:
*/

vector<int> kmp(string& s){
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

string longestPrefix(string s) {
    int n = s.size();
    vector<int> lps = kmp(s);
    int length = lps[n - 1]; // Length of the longest prefix that is also a suffix
    return s.substr(0, length);
}
