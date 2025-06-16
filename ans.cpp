#include<bits/stdc++.h>
using namespace std;

int beauty(int x){
    return __builtin_popcount(x);
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> beautyval(n);
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            beautyval[i]=beauty(a[i]);
            int gain=beauty(a[i]+1)-beauty(a[i]);
            pq.push({gain,i});
        }
        while(!pq.empty() && k>0){
            pair<int,int> ab=pq.top();
            int gain=ab.first;
            int ind=ab.second;
            pq.pop();
            if(gain==0){
                int val=a[ind]+1;
                int cost=1;
                bool improved=false;
                int currbea=beauty(a[ind]);

                while(cost<=k){
                    int nb=beauty(val);
                    if(nb>currbea){
                        beautyval[ind]=nb;
                        a[ind]=val;
                        k-=cost;
                        improved=true;

                        int ng=beauty(val+1)-nb;
                        pq.push({ng,ind});
                        break;
                    }
                    val++;
                    cost++;
                }
                if(!improved)break;
            }
            else{
                k--;
                a[ind]++;
                beautyval[ind]=beauty(a[ind]);
                int newgain=beauty(a[ind]+1)-beauty(a[ind]);
                pq.push({newgain,ind});
            }
        }
        int total=0;
        for(int i=0;i<n;i++){
            total+=beautyval[i];
        }
        cout<<total<<endl;
    }
    return 0;
}
