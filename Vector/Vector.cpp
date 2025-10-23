#include "../myheaders.h"

int main()
{
    vector<int> vec1;
    vector<int> vec2 = {1, 2, 3, 4, 5};
    vector<int> vec3(5, -1);         //{-1,-1,-1,-1,-1}
    cout << vec1.size() << "\n";     // size = number of present element. which is zero
    cout << vec2.size() << "\n";     // 5
    cout << vec3.size() << "\n";     // 5
    cout << vec1.capacity() << "\n"; // capacity = max number of element which can be added. which is zero

    // expamle for size vs capacity
    vec2.push_back(6);               // to add
    cout << vec2.size() << "\n";     // 5+1 = 6
    cout << vec2.capacity() << "\n"; // 5*2 = 10
    vec2.pop_back();                 // to remove
    cout << vec2.size() << "\n";     // 5
    cout << vec2.capacity() << "\n"; // 10

    // 2D vertor

    vector<vector<int>>martix;
    return 0;
}