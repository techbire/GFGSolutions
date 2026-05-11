class Solution {
public:
    
    bool isPal(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }

    bool palindromePair(vector<string>& arr) {
        
        unordered_map<string,int> mp;
        
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]] = i;

        for(int i = 0; i < arr.size(); i++) {

            string w = arr[i];

            for(int j = 0; j <= w.size(); j++) {

                string l = w.substr(0, j);
                string r = w.substr(j);

                if(isPal(l)) {

                    string x = r;
                    reverse(x.begin(), x.end());

                    if(mp.count(x) && mp[x] != i)
                        return 1;
                }

                if(j != w.size() && isPal(r)) {

                    string x = l;
                    reverse(x.begin(), x.end());

                    if(mp.count(x) && mp[x] != i)
                        return 1;
                }
            }
        }

        return 0;
    }
};