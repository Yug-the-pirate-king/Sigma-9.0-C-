/*
QUESTION:
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Approach:
- We can solve this problem using the KMP (Knuth-Morris-Pratt) string matching algorithm.
- First, we calculate the LPS (Longest Prefix Suffix) array for the needle string.
- Then, we create a new string by concatenating needle, a special character (not present in either needle or haystack), and haystack.
- We iterate through the new string and compare characters using the LPS array to determine if there is a match.
- If the LPS value becomes equal to the length of the needle, it means we have found a match, and we return the starting index of the match in the haystack string.

Complexity Analysis:
- The time complexity of this solution is O(m + n), where m is the length of the needle and n is the length of the haystack.
- The space complexity is O(m + n) but can be reduced to O(n), where m is the length of the needle.

CODE:
*/

vector<int> lps(string& s){
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if(s[j] == s[i]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int strStr(string haystack, string needle) {
    if(needle.empty()) {
        return 0;
    }
    string temp = needle + '$' + haystack;
    vector<int> lpsArray = lps(temp);
    for(int i = 0; i < lpsArray.size(); i++) {
        if(lpsArray[i] == needle.size()) {
            return i - 2 * needle.size();
        }
    }
    return -1;
}
