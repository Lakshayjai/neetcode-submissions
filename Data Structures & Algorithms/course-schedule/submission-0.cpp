class Solution {
public:
    bool f(int numCourses, vector<vector<int>>& prerequisites){
        int n = numCourses;  
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;

        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }

        if(q.empty()) return false;

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;

            for(auto it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0) q.push(it);
            } 
        }

        return cnt == numCourses;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        return f(numCourses, prerequisites);
    }
};
