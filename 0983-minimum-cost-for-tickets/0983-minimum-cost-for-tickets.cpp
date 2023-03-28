class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
     
        unordered_set<int> set(begin(days),end(days));
        int last_day = days.back();
        
        vector<int> t(last_day+1,0);
        
        t[0]=0;
        
        for(int i=1;i<=last_day;i++){
            if(set.find(i)==set.end()){
                t[i]=t[i-1];
                continue;
            }
            
            t[i] = INT_MAX;
            int day1pass = costs[0]+t[max((i-1),0)];
            int day7pass = costs[1]+t[max((i-7),0)];
            int day30pass = costs[2]+t[max((i-30),0)];
            
            t[i] = min({day1pass,day7pass,day30pass});
        }
        
        return t[last_day];
    }

};