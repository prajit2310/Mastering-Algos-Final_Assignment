class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();

        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({courses[i][1],courses[i][0]});
        }

        sort(v.begin(),v.end());

        priority_queue<int>pq;
        int days = 0;

        for(int i=0;i<n;i++){
            if(days+v[i].second <= v[i].first){
                days += v[i].second;
                pq.push(v[i].second);
            }
            else{
                if(!pq.empty() && v[i].second < pq.top()){
                    days -= pq.top();
                    days += v[i].second;
                    pq.pop();
                    pq.push(v[i].second);
                    
                }
            }
        }

        return pq.size();

    }
};