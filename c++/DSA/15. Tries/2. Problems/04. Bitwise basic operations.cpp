/*
QUESTION:
You are given six positive integers: 'a', 'b', 'c', 'd', 'e', and 'f'.
You will be given three functions: 'getXOR', 'getBit', and 'setBit'.
Your task is to do the following:
1. In the function 'getXOR', you will be given two parameters, 'a', and 'b'. Your task is to return the XOR of 'a' and 'b'.
2. In the function 'getBit', you will be given two parameters, 'c' and 'd'. Your task is to return 1 if the 'c'th bit of 'd' is set. Otherwise, return 0.
3. In the function 'setBit', you will be given two parameters, 'e' and 'f'. Your task is to set the 'e'th bit in 'f' if it is not set. At last, return the integer 'f'. The expected time complexity is 'O(1)', and the expected space complexity is 'O(1').

CODE:

Approach:
1. For the 'getXOR' function, simply use the XOR (^) operator to get the XOR of 'a' and 'b'.
2. For the 'getBit' function, use the right shift (>>) and bitwise AND (&) operators to check if the 'c'th bit of 'd' is set or not.
3. For the 'setBit' function, use the bitwise OR (|) operator and left shift (<<) to set the 'e'th bit in 'f'.

Complexity Analysis:
- All three functions have a time complexity of O(1) as they involve simple bitwise operations.
- All three functions have a space complexity of O(1) as they do not require additional memory allocation.
*/

int getXOR(int a, int b) {
    return a ^ b;
}

int getBit(int c, int d) {
    return (d >> c) & 1;
}

int setBit(int e, int f) {
    return f | (1 << e);
}
