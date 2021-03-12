class Solution:
    def __init__(self):
        self.adjList = dict()
        self.visited = set()
        self.connected_components = dict()
        self.cc_num = 0
        self.email_name = dict()
            
    def DFS(self, email):
        self.visited.add(email)
        if not self.connected_components.get(self.cc_num):
            self.connected_components[self.cc_num] = []
        self.connected_components[self.cc_num].append(email)
        for other_email in self.adjList[email]:
            if other_email not in self.visited:
                self.DFS(other_email)
    
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        # build graph
        for account in accounts:
            if len(account) <= 1:
                continue
            name = account[0]
            self.email_name[account[1]] = name
            if not self.adjList.get(account[1]):
                self.adjList[account[1]] = [] 
            for i in range(len(account[1:]) - 1):
                i = i + 1
                email, next_email = account[i], account[i+1]
                self.email_name[email] = name
                self.email_name[next_email] = name
                if not self.adjList.get(email):
                    self.adjList[email] = [next_email]
                else:
                    self.adjList[email].append(next_email)
                if not self.adjList.get(next_email):
                    self.adjList[next_email] = [email]
                else:
                    self.adjList[next_email].append(email)
                
        # DFS
        for email in self.adjList:
            if email not in self.visited:
                self.DFS(email)
                self.cc_num += 1
                
        answer = []
        for cc_num in self.connected_components:
            answer.append([self.email_name[self.connected_components[cc_num][0]]] + sorted(self.connected_components[cc_num]))
        return answer
        
                