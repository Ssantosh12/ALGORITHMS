class Solution {
public:
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //using simple bfs using queue
        vector<bool> visited(rooms.size(),false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            for(auto x: rooms[q.front()]){
                if(visited[x]==false){
                    q.push(x);
                    visited[x]=true;
                }
            }
            q.pop();
        }
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==false)
                return false;
        }
        return true;
    }
};
