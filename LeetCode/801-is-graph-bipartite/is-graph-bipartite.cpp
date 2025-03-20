class Solution {
public:
    bool checkBapartiteDFS(vector<vector<int>>& graph, vector<int> &color,int curr,int chosenColor){
        color[curr]=chosenColor;
        
        for(int &v:graph[curr]){
            if(color[v]==color[curr]) return false;
            
            if(color[v]==-1){
                int newColor = 1 - chosenColor;
                color[v]=newColor;
                if(!checkBapartiteDFS(graph,color,v,newColor)) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!checkBapartiteDFS(graph,color,i,1)) return false;
            }
        }
        return true;
    }
};