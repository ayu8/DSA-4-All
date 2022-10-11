class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
       int m=matrix.size();
         vector<int>res;
          if(m==0)
          return res;
        int n=matrix[0].size();
        
        int rowstart=0;
        int rowend=m;
        int colstart=0;
        int colend=n;
        
        int k;
        
        while(rowstart<rowend && colstart<colend)
        {
          
            for(k=colstart;k<colend;k++)
            res.push_back(matrix[rowstart][k]);
            rowstart+=1;
            
            for(k=rowstart;k<rowend;k++)
            res.push_back(matrix[k][colend-1]);
            colend-=1;
            
            if(rowstart<rowend)
            {
                for(k=colend-1;k>=colstart;k--)
                res.push_back(matrix[rowend-1][k]);
                rowend-=1;
            }
            
            if(colstart<colend)
            {
                for(k=rowend-1;k>=rowstart;k--)
                res.push_back(matrix[k][colstart]);
                colstart+=1;
            }
            
        }
        return res;       
    }
};

// leetcode
// https://leetcode.com/problems/spiral-matrix/
