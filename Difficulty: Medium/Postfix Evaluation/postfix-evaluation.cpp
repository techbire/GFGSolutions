class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
             int n = arr.size();
             stack<int>st;
        
             for(int i=0;i<n;i++){

         if (arr[i]=="*" || arr[i]=="/" || arr[i]=="-" || arr[i]=="^" || arr[i]=="+"){
                  
                   int top1 = st.top();
                   st.pop();
                   int top2 = st.top();
                   st.pop();
                //  cout<<top1<<" "<<top2<<endl;
                   if (arr[i]=="*")st.push(top1*top2);
                   else if (arr[i]=="^")st.push(pow(top2,top1));
                   else if (arr[i]=="/")st.push(floor((double)top2/top1));
                   else if (arr[i]=="+")st.push(top1+top2);
                   else if (arr[i]=="-")st.push(top2-top1);
                
         }
         else{
              int t =stoi(arr[i]);
               st.push(t);
         }
                 
      
                  
             }
             
             
           return st.top();
    }
};