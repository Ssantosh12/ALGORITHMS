#include <bits/stdc++.h>

using namespace std;

void permu(int pos,string s){  //it will work for smaller inputs
    if(pos==s.size()){
        cout<<s<<endl;
        return;
    }
    for(int i=pos;i<s.size();i++){
        swap(s[pos],s[i]);
        permu(pos+1,s);
    }
}

int main()
{
    string s;
    cin>>s;   // if we want to have permutations in lexicographical manner than first sort the input string
    permu(0,s);
}
