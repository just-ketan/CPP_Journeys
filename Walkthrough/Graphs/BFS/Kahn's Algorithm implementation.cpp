class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        // Build graph and calculate in-degrees
        for(auto& prereq : prerequisites) {
            int course = prereq;
            int prerequisite = prereq[1];
            graph[prerequisite].push_back(course);
            inDegree[course]++;
        }
        
        // Find all courses with no prerequisites
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int processedCourses = 0;
        
        // Process courses level by level
        while(!q.empty()) {
            int currentCourse = q.front();
            q.pop();
            processedCourses++;
            
            // For each dependent course
            for(int dependentCourse : graph[currentCourse]) {
                inDegree[dependentCourse]--;
                if(inDegree[dependentCourse] == 0) {
                    q.push(dependentCourse);
                }
            }
        }
        
        // If all courses processed, no cycle exists
        return processedCourses == numCourses;
    }
};
