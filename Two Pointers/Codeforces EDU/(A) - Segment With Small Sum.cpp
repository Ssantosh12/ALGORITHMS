#include <bits/stdc++.h>
using namespace std;

int main() {
	// Similar Problems: Finding Max length Consecutive Ones/Max length Consecutive Char Subarray
	int i,n,left=0,right=0,longestSeg=0;
	long long int s,currentSum=0;

	scanf("%d%lld",&n,&s);

	int arr[n];
	for(i=0;i<=n-1;i++)
        scanf("%d",&arr[i]);

    while(right<=n-1){
        currentSum+=arr[right];

        // breaking condition: segment from (right-1) to left is a candidate
        if(currentSum>s){
            longestSeg=max(longestSeg, (right-1)-left+1);

            // we adjust the left pointer to make the sum valid (i.e <= s)
            while(currentSum>s){
                currentSum-=arr[left];
                left++;
            }
        }

        // one more edge case breaking condition: ongoing segment (from right to left) can be a candidate as well
        if(right==n-1)
            longestSeg=max(longestSeg, right-left+1);

        right++;
    }
    cout<<longestSeg;
}

// Solution from 28th Jan 2025
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,n,maxSegment=0,left,right;
    long long int s,segmentSum=0;

    scanf("%d%lld",&n,&s);

    int arr[n];
    for(i=0;i<=n-1;i++)
        scanf("%d",&arr[i]);

    // using two pointers left and right to contain a running segment between them
    // we move the right pointer to stretch the segment until it is valid
    // and when it becomes invalid we stretch left pointer towards right direction
    left=0;
    right=0;
    while(right<=n-1){
        segmentSum+=arr[right];

        if(segmentSum>s){
            // then segment from left to right-1 was longest valid segment starting at left index
            maxSegment=max(maxSegment,(right-1)-left+1);

            // move the left pointer towards right until segment becomes valid
            while(segmentSum>s){
                segmentSum-=arr[left];
                left++;
            }
        }

        // another breaking condition for updation
        if(right==n-1){
            // then segment from left to right is longest valid segment starting at left index
            maxSegment=max(maxSegment,right-left+1);
        }
        right++;
    }
    cout<<maxSegment;
}

*/

// OLD Solution: also GOOD
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int i,n,s,left=0,right=0,segmentSum=0,maxSegmentLen=0;
    cin>>n>>s;
    int a[n];
    for(i=0;i<=n-1;i++)
        cin>>a[i];

    // TODO:
    while(right<=n-1){
        // we add this TODO:
        segmentSum+=a[right];

        if(segmentSum>s){
            // then upto previous length segment was valid i.e from left to (right-1)
            if(((right-1)-left+1)>maxSegmentLen)
                maxSegmentLen=(right-1)-left+1;

            // we adjust the left pointer to make the sum valid (i.e <= s)
            while(segmentSum>s){
                segmentSum-=a[left];
                left++;
            }
        }

        // edge case we have to consider
        if(right==n-1){
            // then valid segment is left to right , it is already valid as we made it above
            if((right-left+1)>maxSegmentLen)
                maxSegmentLen=right-left+1;
        }

        right++;
    }
    cout<<maxSegmentLen;
}

*/
