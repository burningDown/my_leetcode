class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> coursesCount(numCourses, 0);
        vector<bool> visited(numCourses, false);
        vector<vector<bool>> coursesMap(numCourses, vector<bool>(numCourses, false));
        queue<int> coursesQueue;
        vector<int> result;

        for(auto &p : prerequisites)
        {
            coursesMap[p[1]][p[0]] = true;
            coursesCount[p[0]]++;
        }

        for(int i=0;i<numCourses;i++)
            if(coursesCount[i] == 0)
                coursesQueue.push(i);
        
        while(!coursesQueue.empty())
        {
            int course = coursesQueue.front();
            coursesQueue.pop();

            visited[course] = true;
            result.push_back(course);

            for(int i=0;i<numCourses;i++)
            {
                if(coursesMap[course][i])
                {
                    if(visited[i])
                        return {};
                    
                    coursesMap[course][i] = false;
                    coursesCount[i]--;
                    if(coursesCount[i] == 0)
                        coursesQueue.push(i);
                }
            }
        }

        return result.size() < numCourses ? vector<int>() : result;
    }
};