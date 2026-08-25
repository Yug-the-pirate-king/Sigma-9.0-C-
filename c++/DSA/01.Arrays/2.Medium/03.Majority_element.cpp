#include <vector>
#include <stdexcept>

/*
QUESTION:-
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than floor(n / 2) times.
You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

/*
APPROACH:-
Boyer-Moore Voting Algorithm:
-> Initialize candidate with the first element and its vote count to 1.
-> Iterate through the array starting from the second element:
    - If the vote count drops to zero, pick the current element as the new candidate.
    - If the current element matches the candidate, increment the vote count.
    - Otherwise, decrement the vote count.
-> The remaining candidate is the majority element.
*/

// Returns the majority element from the given integer vector.
// Throws std::invalid_argument if the input vector is empty.
int majorityElement(const std::vector<int> &nums)
{
    // Input validation: an empty array cannot have a majority element.
    if (nums.empty())
    {
        throw std::invalid_argument("Input vector must not be empty.");
    }

    int candidate = nums[0];
    int vote = 1;

    // Start from the second element because the first one is already the candidate.
    for (size_t i = 1; i < nums.size(); ++i)
    {
        // When the current candidate has no votes, switch to the current element.
        if (vote <= 0)
        {
            candidate = nums[i];
        }

        // Update the vote count based on whether the current element matches the candidate.
        if (nums[i] == candidate)
        {
            ++vote;
        }
        else
        {
            --vote;
        }
    }

    return candidate;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)