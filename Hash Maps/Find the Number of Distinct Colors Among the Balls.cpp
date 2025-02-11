class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // we use hash maps to store balls' colour updates from the queries
        int i,diffColourPerQuery=0,ballPrvColour,ballCurrColour;

        // create two hash maps to store ball colour update per query and frequency of each colour per query
        map<int,int> ballColour,colourFreq;

        vector<int> ans(queries.size());
        for(i=0;i<=queries.size()-1;i++){
            // for each query we update the colour of a ball
            // if the ball colour had a frequency >0, then we decrease this colour's frequency and
            // then the ball is coloured with new colour and this colour's frequency is increased
            // we update diffColourPerQuery

            ballPrvColour=ballColour[queries[i][0]];
            ballCurrColour=queries[i][1];
            
            if(colourFreq[ballPrvColour]>0){
                colourFreq[ballPrvColour]--;
                // edge case: check if prv colour frequency reduced to 0
                // NOTE: only when we decrease it below condition needs to be checked
                if(colourFreq[ballPrvColour]==0)
                    diffColourPerQuery--;
            }
            
            // now check if we are using current colour first time
            if(colourFreq[ballCurrColour]==0)
                diffColourPerQuery++;

            // updates: curr colour frequency increased, ball's current colour updated
            colourFreq[ballCurrColour]++;
            ballColour[queries[i][0]]=ballCurrColour;
            
            // udpate ans array
            ans[i]=diffColourPerQuery;
            
        }
        return ans;
    }
};
