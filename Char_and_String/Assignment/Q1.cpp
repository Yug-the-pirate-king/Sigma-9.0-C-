#include <iostream>
#include <string>
using namespace std;

/*
 * Counts the number of lowercase English vowels ('a', 'e', 'i', 'o', 'u')
 * present in the provided word.
 *
 * @param word The input string to inspect.
 * @return The total number of lowercase vowel characters.
 */
int countVowels(const string& word) {
    int frequency[26] = {0};

    // Build a frequency table for each lowercase English letter.
    for (char ch : word) {
        if (ch >= 'a' && ch <= 'z') {
            frequency[ch - 'a']++;
        }
    }

    // Sum the frequencies of the five vowels.
    const char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int totalVowels = 0;
    for (char vowel : vowels) {
        totalVowels += frequency[vowel - 'a'];
    }

    return totalVowels;
}

int main() {
    string word;

    cout << "Enter a word : \n";
    getline(cin, word);

    int totalVowels = countVowels(word);
    cout << "The Total number of vowel : " << totalVowels;

    return 0;
}