class Solution {
    struct T{T* c[2]{};int ct=0;};
    T* r=new T();
    void ins(int x){
        auto t=r;
        for(int i=15;i>=0;i--){
            int b=(x>>i)&1;
            if(!t->c[b]) t->c[b]=new T();
            t=t->c[b];
            t->ct++;
        }
    }
    int get(int x,int k){
        auto t=r;int ans=0;
        for(int i=15;i>=0&&t;i--){
            int xb=(x>>i)&1,kb=(k>>i)&1;
            if(kb){ if(t->c[xb]) ans+=t->c[xb]->ct; t=t->c[1-xb]; }
            else t=t->c[xb];
        }
        return ans;
    }
  public:
    int cntPairs(vector<int>& a,int k){
        int ans=0;
        for(int x:a){ ans+=get(x,k); ins(x); }
        return ans;
    }
};