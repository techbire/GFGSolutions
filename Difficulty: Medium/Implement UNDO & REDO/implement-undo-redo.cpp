class Solution {
  public:
    string ans = "";
    string k = "";
    
    
    void append(char x) {
        ans += x;
    }

    void undo() {
        if (!ans.empty()) {
            k.push_back(ans.back());
            ans.pop_back();
        }
    }

    void redo() {
        if (!k.empty()) {
            ans.push_back(k.back());
            k.pop_back();
        }
    }

    string read() {
        return ans;
    }
};