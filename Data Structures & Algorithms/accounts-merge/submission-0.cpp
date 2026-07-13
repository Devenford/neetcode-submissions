#include <unordered_map>
#include <vector>
#include<string>
using namespace std;

class Solution {
    unordered_map<string, string> par;
    unordered_map<string, int> rank;
    unordered_map<string, string> emailToAcc; // email to account

    string find(string n) {
        string p = par[n];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    void Union(string n1, string n2) {
        string p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {   // already a part of the same set
            return;
        }

        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
        }
        else if (rank[p1] < rank[p2]) {
            par[p1] = p2;
        }
        else {
            par[p2] = p1;
            rank[p1]++;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (vector<string> account : accounts) {
            for(int i = 1; i<account.size(); i++) {
                if (par.count(account[i])==0) {   // every unique email is a node
                    par[account[i]] = account[i];
                    rank[account[i]] = 0;
                    emailToAcc[account[i]] = account[0];
                }
            }
            /* emails belonging to the same account are grouped into a 
            single set, where the root is the first email account[1].
            This also combines accounts with the same email:
            */
            for (int i = 1; i<account.size()-1; i++) {
                Union(account[1], account[i+1]);
            }
        }

        unordered_map<string, vector<string>> groups; // <root email, [emails of the same set as the root email, including the root]>
        for (auto it = emailToAcc.begin(); it != emailToAcc.end(); it++) {
            groups[find(it->first)].push_back(it->first);
        }

        vector<vector<string>> solution;
        for (auto it = groups.begin(); it != groups.end(); it++) {
            vector<string> temp;
            temp.push_back(emailToAcc[it->first]);
            temp.insert(temp.end(), it->second.begin(), it->second.end());
            solution.push_back(temp);
        }

        return solution;
    }
};