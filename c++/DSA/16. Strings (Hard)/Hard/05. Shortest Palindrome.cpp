/*
QUESTION:
You are given a string s. You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.

Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"

Approach:
1. We can solve this problem using the KMP (Knuth-Morris-Pratt) algorithm.
2. First, we reverse the string s and store it in the string rev.
3. We concatenate s and rev with a special character '$' in between, creating the string temp.
4. We calculate the LPS (Longest Prefix Suffix) array for the string temp using KMP.
5. The last value in the LPS array, lps.back(), represents the length of the longest prefix of temp that is also a suffix.
6. We extract the substring of s starting from index lps.back() to the end and reverse it.
7. Finally, we concatenate the reversed substring with s and return the result as the shortest palindrome.

Complexity Analysis:
- The time complexity of this solution is O(n), where n is the length of the string s.
- The space complexity is O(n) to store the LPS array.

CODE:
*/

vector<int> kmp(string& s) {
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++) {
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

string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string temp = s + "$" + rev;
    vector<int> lps = kmp(temp);
    string toAdd = s.substr(lps.back());
    reverse(toAdd.begin(), toAdd.end());
    return toAdd + s;
}
