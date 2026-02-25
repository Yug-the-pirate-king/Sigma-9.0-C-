/*
QUESTION:-
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Approach:
1. We use a disjoint-set data structure to group accounts that belong to the same person based on their common emails.
2. Create a disjoint-set and an unordered map to store email to account index mapping.
3. Iterate through the list of accounts, for each account, iterate through its emails, and add them to the unordered map with the corresponding account index as the value.
4. Iterate through the unordered map and union accounts that share common emails using the disjoint-set.
5. Create a set for each group of accounts and add the emails of each account to the corresponding set.
6. Iterate through the disjoint-set and create the final merged accounts list by grouping emails for each account based on their root in the disjoint-set.

Complexity Analysis:
- Let n be the number of accounts and m be the average number of emails per account.
- The time complexity of this approach is O(n*m*α(n)), where α(n) is the inverse Ackermann function, which grows very slowly and is nearly constant.
- The space complexity is O(n*m) to store the emails and their corresponding account indices in the unordered map, and O(n*m) to store the merged accounts in the final result.
*/

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionSize(int u, int v) {
        int uP = findUPar(u), vP = findUPar(v);
        int uS = size[uP], vS = size[vP];
        if (uS > vS) {
            parent[vP] = uP;
            size[uP] += vS;
        } else {
            parent[uP] = vP;
            size[vP] += uS;
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, vector<int>> emailToAccountIndex;
    int n = accounts.size();
    DisjointSet djs(n);

    for (int u = 0; u < n; u++) {
        for (int i = 1; i < accounts[u].size(); i++) {
            emailToAccountIndex[accounts[u][i]].push_back(u);
        }
    }

    for (auto [email, users] : emailToAccountIndex) {
        for (int i = 1; i < users.size(); i++) {
            if (djs.findUPar(users[i - 1]) != djs.findUPar(users[i]))
                djs.unionSize(users[i - 1], users[i]);
        }
    }

    set<string> userMail[n];
    for (int i = 0; i < n; i++) {
        for (int m = 1; m < accounts[i].size(); m++) {
            userMail[djs.findUPar(i)].insert(accounts[i][m]);
        }
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++) {
        if (userMail[i].empty()) continue;
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for (auto m : userMail[i])
            temp.push_back(m);
        ans.push_back(temp);
    }

    return ans;
}
