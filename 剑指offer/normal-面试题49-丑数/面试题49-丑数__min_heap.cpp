class Solution {
private:
    priority_queue<long, vector<long>, greater<long>> sortQueue;
public:
    int nthUglyNumber(int n) {
        long current, pre;
        int i;
        sortQueue.push(1);

        pre = 0;
        i = 1;
        while(i<=n)
        {
            current = sortQueue.top();
            sortQueue.pop();
            if(current == pre)
                continue;
            sortQueue.push(current * 2);
            sortQueue.push(current * 3);
            sortQueue.push(current * 5);
            pre = current;
            i++;
        }
        return (int)pre;
    }
};