class Vector2D {
private:
    vector<int> point;
    vector<vector<int>> memberList;
public:
    Vector2D(vector<vector<int>>& v): point({0, 0}) {
        memberList = v;
    }
    
    int next() {
        if(memberList.size() > 0)
        {
            if(point[0] < memberList.size())
            {
                if(point[1] < memberList[point[0]].size())
                {
                    point[1]++;
                    return memberList[point[0]][point[1]-1];
                }
                else
                {
                    point[1] = 0;
                    point[0] += 1;
                    return this->next();
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    
    bool hasNext() {
        vector<int> localPoint = point;
        while(true)
        {
            if(memberList.size() > 0)
            {
                if(localPoint[0] < memberList.size())
                {
                    if(localPoint[1] < memberList[localPoint[0]].size())
                    {
                        return true;
                    }
                    else
                    {
                        localPoint[1] = 0;
                        localPoint[0]++;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */