class Solution {
    vector<vector<int>> pre; // course -> precourses
    set<int> could_take; // record courses that could be taken
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        pre = vector<vector<int>>(numCourses);
        
        // construct vector pre
        for (vector<int> v : prerequisites) {
            pre[v[0]].push_back(v[1]);
        }
        
        set<int> post;
        for (int id = 0; id < numCourses; id++) {
            post.insert(id);
            //bool res = dfs(id, post);
            if (dfs(id, post) == false)
                return false;
            else {
                post.erase(id);
            }
        }
        
        return true;
        
        
    }
    
    bool dfs(int course_id, set<int> post) {
        
        if (could_take.find(course_id) != could_take.end())
            return true;
        
        if (pre[course_id].empty()) {
            could_take.insert(course_id);
            return true;
        } else {
            for (int crs : pre[course_id]) {
                if (post.find(crs) != post.end())   // has loop in the graph
                    return false;
                else {
                    post.insert(crs);
                    bool new_res = dfs(crs, post);
                    if (new_res == false)
                        return false;
                    else {
                        post.erase(crs);
                    }
                }
            }
        }
        
        could_take.insert(course_id);
        return true;
        
        
    }
    
};