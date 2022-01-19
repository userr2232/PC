enum Type { undefined=-1, start=0, end=1};

class Solution {
    tuple<int,Type,int> parse(string& log) {
        int function_id{0}, timestamp{0};
        string type;
        for(int i = 0; i < log.size(); ++i) {
            char c = log[i];
            if(c == ':') continue;
            if(isdigit(c)) {
                if(type == "") {
                    function_id *= 10;
                    function_id += c-'0';
                }
                else {
                    timestamp *= 10;
                    timestamp += c-'0';
                }
            }
            else {
                type += c;
            }
        }
        return {function_id, static_cast<Type>(type == "start" ? 0 : 1), timestamp};
    }
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        map<int,int> m;
        stack<pair<int,int>> st;
        for(auto& log : logs) {
            int function_id, timestamp;
            Type type;
            tie(function_id, type, timestamp) = parse(log);
            int prev_id = -1, prev_timestamp = -1;
            if(!st.empty()) {
                auto& [p_id, p_t] = st.top();
                prev_id = p_id, prev_timestamp = p_t;
            }
            if(type == Type::start) {
                if(prev_id == -1) {
                    // do nothing
                }
                else {
                    auto& [_, p_t] = st.top();
                    m[prev_id] += timestamp-p_t;
                    p_t = timestamp;
                }
                st.emplace(function_id, timestamp);
            }
            else {
                st.pop(); // impossible to be empty
                if(prev_id == -1) {
                    // impossible
                }
                else {
                    m[prev_id] += timestamp-prev_timestamp+1;
                    if(!st.empty()) {
                        auto& [p_id, p_t] = st.top();
                        p_t = timestamp+1;
                    }
                }
            }
        }
        vector<int> ans(m.size());
        for(const auto& [id, duration] : m) ans[id] = duration;
        return ans;
    }
};