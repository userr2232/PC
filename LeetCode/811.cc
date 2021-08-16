class Solution {
    int readint(string& visits_domain) {
        int i{0}, ans{0};
        for(; i < visits_domain.length(); ++i) {
            if(visits_domain[i] == ' ') break;
            else ans *= 10, ans += visits_domain[i]-'0';
        }
        visits_domain = visits_domain.substr(i+1);
        return ans;
    }
    
    vector<string> readsubdomains(string& domain) {
        vector<string> ans;
        ans.push_back(domain);
        for(int i = 0; i < domain.length(); ++i) if(domain[i] == '.') ans.push_back(domain.substr(i+1));
        return ans;
    }
    
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> counter;
        for(string& domain : cpdomains) {
            int visits = readint(domain);
            vector<string> subdomains = readsubdomains(domain);
            for(const string& subdomain : subdomains) {
                counter[subdomain] += visits;
            }
        }
        vector<string> ans;
        for(const auto& [k, v] : counter) {
            ans.push_back(to_string(v) + " " + k);
        }
        return ans;
    }
};