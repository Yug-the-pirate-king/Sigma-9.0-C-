#include <cstddef>
#include <stdexcept>
#include <vector>

using std::vector;

namespace {
    // Returns true for values treated as the "positive" half of the array.
    // The original implementation places zeros in the positive slots, so
    // this predicate preserves that exact behavior.
    constexpr bool isNonNegative(int value) noexcept {
        return value >= 0;
    }

    // Returns true for strictly negative values.
    constexpr bool isNegative(int value) noexcept {
        return value < 0;
    }

    // Fills destination[startIndex, startIndex + 2, ...] with elements from
    // source whose sign matches shouldSelect, preserving their original order.
    template <typename Predicate>
    void fillBySign(const vector<int>& source,
                    vector<int>& destination,
                    std::size_t startIndex,
                    Predicate shouldSelect)
    {
        std::size_t destIndex = startIndex;

        for (std::size_t srcIndex = 0; srcIndex < source.size(); ++srcIndex) {
            if (shouldSelect(source[srcIndex])) {
                // Guard against writing past the output buffer if the input
                // does not satisfy the problem's balancing constraint.
                if (destIndex >= destination.size()) {
                    throw std::invalid_argument("Sign counts are not balanced.");
                }

                destination[destIndex] = source[srcIndex];
                destIndex += 2; // next slot of the same parity
            }
        }
    }
}

/*
 * Question:
 * Given an even-length integer array containing an equal number of positive
 * and negative integers, rearrange it so that every consecutive pair of
 * integers has opposite signs, the relative order of same-sign integers is
 * preserved, and the result begins with a positive integer.
 *
 * Approach:
 * Place non-negative integers at even indices (0, 2, 4, ...) and negative
 * integers at odd indices (1, 3, 5, ...). A single reusable helper handles
 * both passes while keeping the relative order of each group.
 */
vector<int> rearrangeArray(vector<int>& nums)
{
    const std::size_t n = nums.size();

    // The input must be even-length; otherwise the alternating placement
    // would be impossible.
    if (n % 2 != 0) {
        throw std::invalid_argument("Input array length must be even.");
    }

    vector<int> ans(n);

    // Positive (and zero) values occupy even indices.
    fillBySign(nums, ans, 0, isNonNegative);

    // Negative values occupy odd indices.
    fillBySign(nums, ans, 1, isNegative);

    return ans;
}

/*
 * Time Complexity:  O(N), where N = nums.size()
 * Space Complexity: O(N) for the output array
 */