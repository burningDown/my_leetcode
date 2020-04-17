class AnimalShelf {
private:
    list<vector<int>> animalList;
public:
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        animalList.push_back(animal);
    }
    
    vector<int> dequeueAny() {
        if(animalList.size() > 0)
        {
            auto res = animalList.front();
            animalList.pop_front();
            return res;
        }
        return {-1, -1};
    }
    
    vector<int> dequeueDog() {
        if(animalList.size() > 0)
        {
            for(auto it=animalList.begin();it!=animalList.end();++it)
            {
                if((*it)[1] == 1)
                {
                    vector<int> res = *it;
                    animalList.erase(it);
                    return res;
                }
            }
        }
        return {-1, -1};
    }
    
    vector<int> dequeueCat() {
        if(animalList.size() > 0)
        {
            for(auto it=animalList.begin();it!=animalList.end();++it)
            {
                if((*it)[1] == 0)
                {
                    vector<int> res = *it;
                    animalList.erase(it);
                    return res;
                }
            }
        }
        return {-1, -1};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */