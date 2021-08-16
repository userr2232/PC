class Solution {
    typedef pair<string,string> ss;
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        priority_queue<ss, vector<ss>, greater<ss>> letterLogs;
        queue<string> digitLogs;
        for(const auto& log : logs) {
            int n = log.size();
            if(isdigit(log[n-1])) digitLogs.push(log);
            else {
                string logName, logContents;
                int i{0};
                for(; i < n; ++i) if(log[i] == ' ') break;
                logName = log.substr(0,i);
                logContents = log.substr(i);  
                letterLogs.push({logContents, logName});
            }
        }
        ss top;
        while(!letterLogs.empty()) top = letterLogs.top(), ans.push_back(top.second+top.first), letterLogs.pop();
        while(!digitLogs.empty()) ans.push_back(digitLogs.front()), digitLogs.pop();
        return ans;
    }
};