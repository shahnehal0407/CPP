class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,double>> cars;

        // store {position, time}
        for(int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // sort by position descending
        sort(cars.begin(), cars.end(), greater<>());

        stack<double> st;

        for(auto &car : cars) {
            double currTime = car.second;

            if(st.empty() || currTime > st.top()) {
                // new fleet
                st.push(currTime);
            }
            // else: merges → do nothing
        }

        return st.size();
    }
};