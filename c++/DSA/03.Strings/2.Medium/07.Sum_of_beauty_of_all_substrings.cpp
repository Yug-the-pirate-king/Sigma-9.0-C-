#include <string>
#include <array>
#include <algorithm>

static constexpr int ALPHABET_SIZE = 26;

int beautySum(std::string s) {
    if (s.empty()) return 0;

    for (char ch : s) {
        if (ch < 'a' || ch > 'z') return 0;
    }

    const int n = static_cast<int>(s.size());
    long long totalBeauty = 0;

    for (int i = 0; i < n; ++i) {
        std::array<int, ALPHABET_SIZE> freq{};
        int maxFreq = 0;
        int minFreq = n + 1;
        int charsAtMin = 0;

        for (int j = i; j < n; ++j) {
            const int idx = s[j] - 'a';
            const int oldFreq = freq[idx];
            const int newFreq = oldFreq + 1;
            freq[idx] = newFreq;

            maxFreq = std::max(maxFreq, newFreq);

            if (oldFreq == 0) {
                if (minFreq == 1) {
                    ++charsAtMin;
                } else {
                    minFreq = 1;
                    charsAtMin = 1;
                }
            } else {
                if (oldFreq == minFreq) {
                    --charsAtMin;
                }
                if (charsAtMin == 0) {
                    int bestMin = n + 1;
                    int countBest = 0;
                    for (int k = 0; k < ALPHABET_SIZE; ++k) {
                        const int c = freq[k];
                        if (c == 0) continue;
                        if (c < bestMin) {
                            bestMin = c;
                            countBest = 1;
                        } else if (c == bestMin) {
                            ++countBest;
                        }
                    }
                    minFreq = bestMin;
                    charsAtMin = countBest;
                }
            }

            totalBeauty += maxFreq - minFreq;
        }
    }

    return static_cast<int>(totalBeauty);
}