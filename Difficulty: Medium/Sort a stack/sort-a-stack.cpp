class Solution {
  public:
  void ans(stack<int>&st,int x){
      if(st.empty()||st.top()<=x){
          st.push(x);
          return;
      }
      int temp=st.top();
      st.pop();
      ans(st,x);
      st.push(temp);
  }
    void sortStack(stack<int> &st) {
        if(st.empty()){
            return;
        }
        int x=st.top();
        st.pop();
        sortStack(st);
        ans(st,x);
    }
};