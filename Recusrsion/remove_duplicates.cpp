#include "../myheaders.h"
using namespace std;
string remove_dul(string S,string ans,int i,int map[26]){
if(i == S.size()){
cout << "ans :" << ans ;
}
    char ch = S[i];
    int mapidx = (int)(ch-'a');
    if(map[mapidx] == false){
        map[mapidx] = true;
        remove_dul(S,ans+ch,i+1,map);
    }
    else {
        remove_dul(S,ans,i+1,map);
    }
}
int main()
{

    string S = "ShahYug";
    string ans ="";
    int map[26] = {false};

    cout << remove_dul(S,ans,0,map);

    return 0;
}