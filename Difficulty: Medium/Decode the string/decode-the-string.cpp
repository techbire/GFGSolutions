class Solution {
  public:
    string decodedString(string &s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int currentCount = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                currentCount = currentCount * 10 + (c - '0');
            }
            else if (c == '[') {
                countStack.push(currentCount);
                stringStack.push(currentString);
                currentCount = 0;
                currentString = "";
            }
            else if (c == ']') {
                int repeatCount = countStack.top();
                countStack.pop();
                string prevString = stringStack.top();
                stringStack.pop();
                
                string temp = "";
                for (int i = 0; i < repeatCount; i++) {
                    temp += currentString;
                }
                currentString = prevString + temp;
            }
            else {
                currentString += c;
            }
        }
        
        return currentString;
    }
};

