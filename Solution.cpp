#include <bits/stdc++.h>
using namespace std;

vector<int>result;
int temp_res=0;

vector<int> add_count(vector<int>comrades) {
    int max_comrades=6;
    int start=0;
    int count;
    while(start<max_comrades) {
        cin>>count;
        comrades.push_back(count);
        start++;
    }
    
    return comrades;
}

map<vector<int>,int> set_advantages(map<pair<int,int>,int>&advantages) {
    pair<int,int>p;
    p.make_pair(0,1);
    advantages[p]=1;
    p.make_pair(0,2);
    advantages[p]=1;
    p.make_pair(1,2);
    advantages[p]=1;
    p.make_pair(1,3);
    advantages[p]=1;
    p.make_pair(2,5);
    advantages[p]=1;
    p.make_pair(2,4);
    advantages[p]=1;
    p.make_pair(3,0);
    advantages[p]=1;
    p.make_pair(3,5);
    advantages[p]=1;
    p.make_pair(3,2);
    advantages[p]=1;
    p.make_pair(4,1);
    advantages[p]=1;
    p.make_pair(4,3);
    advantages[p]=1;
    p.make_pair(5,0);
    advantages[p]=1;
    p.make_pair(5,4);
    advantages[p]=1;
}

int solve(int i,int n,vector<int>temp,map<pair<int,vector<int>>,int>&dp,
          vector<int>soldiers,vector<int>opponents,map<pair<int,int>,int>&advantages,
          vector<int>&visited
         ) {
         
         if(i==n)
         return 0;
         
         pair<int,vector<int>>p;
         p.make_pair(i,temp);
         
         if(dp[p]!=-1)
         return dp[p];
         
        int pick=0,not_pick=0;
        for(int j=0;j<n;j++) {
            pair<int,vector<int>>t;
            t.make_pair(i,j);
            if(visited[j]==0 && advantages[t] && oppenents[i]<2*soldiers[j]) {
                visited[j]=1;
                temp[i]=j;
                
                pick=1+solve(i+1,n,temp,dp,soldiers,opponents,advantages,visited);
                if(pick>res_temp) {
                    res_temp=pick;
                    res=temp;
                }
                visited[j]=0;
                temp[i]=-1;
            }
                
                not_pick=solve(i,n,temp,dp,soldiers,opponents,advantages,visited);
                if(not_pick>res_temp) {
                    res_temp=not_pick;
                    res=temp;
                }
            }
        }

int main() {
    vector<string>arsenal{"Militia","Spearmen",
                         "LightCavalry","HeavyCavalry",
                         "CavalryArcher","FootArcher"};
    
    vector<int>soldiers;
    vector<int>opponents;
    
    //adding count
    soldiers=add_count(soldiers);
    opponents=add_count(opponents);

    map<pair<int,vector<int>>,int>dp;
    map<pair<int,int>,int>advantages;
    
    //storing which soldier has advantage over other
    advantages=set_advantages(advantages);
    
    vector<int>temp(n,-1);
    //validating whether the soldier has been used
    vector<int>visited(n,0);
    int total=solve(0,6,temp,dp,soldiers,opponents,advantages,visited);
    
    string ans="";
    if(total>=3) {
        for(auto p:res) {
            string temp=arsenal[p]+'#'+to_string(soldiers[p])+";";
            ans+=temp;
        }
    }
    else {
        return "There is no chance of winning";
    }
}