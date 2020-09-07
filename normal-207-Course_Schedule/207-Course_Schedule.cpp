class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> coursesGraph(numCourses, vector<int>());
        vector<int> preMap(numCourses, 0);
        stack<int> availableCourse;
        int count = numCourses;

        for(auto &coursePair : prerequisites)
        {
            coursesGraph[coursePair[1]].push_back(coursePair[0]);
            preMap[coursePair[0]]++;
        }

        for(int i=0;i<numCourses;i++)
        {
            if(preMap[i] == 0)
                availableCourse.push(i);
        }

        while(!availableCourse.empty())
        {
            int course = availableCourse.top();
            availableCourse.pop();
            count--;
            for(int after : coursesGraph[course])
            {
                preMap[after]--;
                if(preMap[after] == 0)
                    availableCourse.push(after);
            }
        }
        return count == 0;
    }
};