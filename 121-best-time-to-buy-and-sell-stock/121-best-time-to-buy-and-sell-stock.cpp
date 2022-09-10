class Solution {
public:
    int find(vector<int> &prices,int st,int k,bool buy,vector<vector<int>> &v){
        if(st>=prices.size() || k<=0){
            return 0;
        }
        if(v[st][buy]!=-1)return v[st][buy];
        if(buy){
            int notbuy=find(prices,st+1,k,buy,v);
            int bbuy=-prices[st]+find(prices,st+1,k,!buy,v);
            return v[st][buy]=max(notbuy,bbuy);
        }
        else {
            int notsell=find(prices,st+1,k,buy,v);
            int sell=prices[st]+find(prices,st+1,k-1,!buy,v);
            return v[st][buy]=max(notsell,sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> v(n,vector<int>(2,-1));
        return find(prices,0,1,1,v);
    }
};