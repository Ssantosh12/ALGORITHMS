#include <bits/stdc++.h>
using namespace std;

int minCoins(int ind, vector<int> &vc, int nor, int mas){
    if(ind==vc.size())
        return 0;

    // main algorithmic thinking part of the problem
    return min(vc[ind]*nor+minCoins(ind+1,vc,nor,mas), mas+minCoins(ind+1,vc,nor,mas));
}


int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,i,ele,nor,mas,coins;
	    scanf("%d%d%d",&n,&nor,&mas);
	    vector<int> vc;
	    for(i=0;i<=n-1;i++){
            scanf("%d",&ele);
            vc.push_back(ele);
	    }

        // for each pokemon we have two choices, either use normal or master coin to generate minimum coins spend, dp question
        coins = minCoins(0,vc,nor,mas);
        cout<<coins<<endl;
	}
	return 0;
}
