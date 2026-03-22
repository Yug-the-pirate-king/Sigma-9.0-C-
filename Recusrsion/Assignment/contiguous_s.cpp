#include <iostream>
#include <string>

using namespace std;

// Recursive function passing the integer array of size 26
int countSubstringsRec(const string& s, int index, int seenCount[26]) {
    if (index == s.length()) {
        return 0; 
    }
    int charIdx = s[index] - 'a';
    int currentValid = 1 + seenCount[charIdx];
    seenCount[charIdx]++;
    return currentValid + countSubstringsRec(s, index + 1, seenCount);
}

int main() {
    string s1 = "abcaba";
    int tracker1[26] = {0};
    
    cout << "Output : " << countSubstringsRec(s1, 0, tracker1) << endl; // Expected: 7
    
    return 0;
}