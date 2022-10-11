//recusive approach........//

// #include <bits/stdc++.h>
// using namespace std;
// int frogJumpk(int currentindex,vector<int> &v,int k){
// //  base case.....//
//     if(currentindex==v.size()-1){
//         return 0;
//     }
//     if(currentindex>v.size()-1){
//         return INT_MAX;
//     }

//     int ans = INT_MAX;
//   //here using for loop we can jum 1,2,3, upto k jump//
//     for(int i=1;i<=k;i++){
//         if(currentindex+i <= v.size()-1){
//             int jump = frogJumpk(currentindex+i,v,k,mp) + abs(v[currentindex]-v[currentindex+i]);
//             ans = min(ans,jump);

//         }

//     }

//     return ans;
// }


//memoizartion approach..........//


#include <bits/stdc++.h>
using namespace std;
int frogJumpk(int currentindex,vector<int> &v,int k,unordered_map<int,int> &mp){
    if(currentindex==v.size()-1){
        return 0;
    }
    if(currentindex>v.size()-1){
        return INT_MAX;
    }

  //using a map to store every state......//
    int currentkey = currentindex;
    if(mp.find(currentkey)!=mp.end()){
        return mp[currentkey];
    }
    int ans = INT_MAX;
    for(int i=1;i<=k;i++){
        if(currentindex+i <= v.size()-1){
            int jump = frogJumpk(currentindex+i,v,k,mp) + abs(v[currentindex]-v[currentindex+i]);
            ans = min(ans,jump);

        }

    }
    mp[currentkey] = ans;
    return mp[currentkey];
}



//problem link:https://atcoder.jp/contests/dp/tasks/dp_b
