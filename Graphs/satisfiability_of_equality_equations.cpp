// TC:O(4α)
// SC:O(n)+O(n)≈O(n)

class Solution {
public:
    void Union(int x, int y,vector<int> &rank, vector<int> &parent)
    {
        int xset = find(x,parent);     
        int yset = find(y,parent);
 
        if (rank[xset] < rank[yset]) {    //if rank of y is greater
            parent[xset] = yset;          //make y parent of x
        }
        else if (rank[xset] > rank[yset]) {  //if rank of x is greater
            parent[yset] = xset;             //make x parent of y
        }
        else {      // if parent of x and y are same
            parent[yset] = xset;   //make x parent of y
            rank[xset] = rank[xset] + 1;   // inrement rank of x since x is leader now
        }
    }
    int find(int x,vector<int> &parent)
    {
        if (parent[x] != x) {                   //if parent of x !=x -->
        parent[x] = find(parent[x],parent); //find parent of x along with path compression
        }
 
        return parent[x];
    }
    static bool comp(const string &a, const string &b){
        if(a[1]=='=' && b[1]=='!'){
            return 1;
        }
        return 0;
    }
    bool equationsPossible(vector<string>& equations) {
        
        vector<int> rank(26,0);
        vector<int> parent(26,0);
        
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        
        sort(equations.begin(),equations.end(),comp);
        
        for(int i=0;i<equations.size();i++){
            int u=equations[i][0]-'a';       //extract char a
            int v=equations[i][3]-'a';       // extract char b
            
            if(equations[i][1]=='='){        // if a==b put a & b in same set
                Union(u,v,rank,parent);
            }   
            else{                 //it checks if a!=b  we check if their parents are same
                if(find(u,parent)==find(v,parent)){ // if parent of a & b are same we return false since they must not be equal according to the current else condition
                    return 0;
                }
            }
        }
        
        return 1;
    }
};

// Question Link:
// https://leetcode.com/problems/satisfiability-of-equality-equations/
