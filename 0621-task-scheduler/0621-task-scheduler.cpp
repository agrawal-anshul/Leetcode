class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto task:tasks){
            mp[task]++;
        }
        // stores task <count, taskname>
        priority_queue<pair<int,char>>pq;

        // Max heap to pick task with highest remaining count
        for(auto& [task, count]:mp){
            pq.push({count, task});
        }
        
        //Cooldown queue: <task, count, nextTimestamp>
        queue<tuple<char,int,int>>q;
        
        int time = 0;

        while(!pq.empty() || !q.empty()){
            if(!q.empty() && get<2>(q.front()) == time){
                // Reinsert cooled-down tasks into heap if their cooldown is over
                auto [currTask, currCount, nextTimeStamp] = q.front();
                q.pop();
                pq.push({currCount, currTask});
            }

            if(!pq.empty()){
                auto [count, currTask] = pq.top();
                pq.pop();
                
                // if there's more of the task to schedule, push it into cooldown
                if(count > 1){
                    mp[currTask]--;
                    // push the next timestamp after which task can be executed.
                    q.push({currTask, count - 1, time + n + 1});
                }
            }
            // Time always progresses regardless of task/idle
            time++;
        }
        return time;
    }
};