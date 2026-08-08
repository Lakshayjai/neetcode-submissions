class Solution {
public:
    vector<int> f(int numCourses, vector<vector<int>>& prerequisites){
        int n = numCourses;  
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;

        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;

        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            } 
        }

        if(q.empty()) return {};

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                    ans.push_back(it);
                }
            } 
        }

        return ans.size() == numCourses ? ans : vector<int>{};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        return f(numCourses, prerequisites);
    }
};
