#include<string>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string output;
        for(string &str : strs) {
            output.append(to_string(str.size()));
            output.push_back(',');
        }
        output.push_back(' ');
        for(string &str : strs) {
            output.append(str);
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<int> lengths;
        vector<string> output;
        string temp;

        int i = 0, k = 0;
        while (s[i] != ' ') {
            if (s[i] == ',') {
                lengths.push_back(stoi(temp));
                temp.clear();
                i++;
                continue;
            }

            temp.push_back(s[i]);
            i++;
        }
        i++;

        while (output.size() < lengths.size()) {
            output.push_back(s.substr(i, lengths[k]));
            i += lengths[k];
            k++;
        }

        return output;
    }
};
