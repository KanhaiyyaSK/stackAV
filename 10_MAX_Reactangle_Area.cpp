//https://practice.geeksforgeeks.org/problems/max-rectangle/1?page=1&category[]=Stack&sprint=94ade6723438d94ecf0c00c3937dad55&sortBy=submissions


// Time Limit Exceed

class Solution{
  public:
  
           void NSR(int arr[], int n, vector<int>&v){
        
        stack<pair<int,int>>st;
        int speudoIndex = n;
        
        for(int i=n-1; i>=0; i--){
            
            
            if(st.empty()) v.push_back(speudoIndex);
            
            else if(!st.empty() && st.top().first < arr[i]){
                v.push_back(st.top().second);
            }
            
            else if(!st.empty() && st.top().first >= arr[i]){
                while(!st.empty() && st.top().first>= arr[i]){
                    st.pop();
                }
                if(st.empty()) v.push_back(speudoIndex);
                else {
                    v.push_back(st.top().second);
                }
            }
            
            st.push({arr[i],i});
            
        }
        reverse(v.begin(), v.end());
        
    }
    
    
    void NSL(int arr[], int n, vector<int>&v){
        
        stack<pair<int,int>>st;
        
         int speudoIndex = -1;
         
        for(int i=0; i<n; i++){
            
            
            if(st.empty()) v.push_back(speudoIndex);
            
            else if(!st.empty() && st.top().first < arr[i]){
                v.push_back(st.top().second);
            }
            
            else if(!st.empty() && st.top().first >= arr[i]){
                while(!st.empty() && st.top().first>= arr[i]){
                    st.pop();
                }
                if(st.empty()) v.push_back(speudoIndex);
                else {
                    v.push_back(st.top().second);
                }
            }
            
            st.push({arr[i],i});
            
        }
        
    }
    
    
    
    int  getMaxArea(int arr[], int n)
    {
        vector<int>ans1;
        vector<int>ans2;
        
        NSL(arr,n,ans1);
        NSR(arr,n,ans2);
        

       int ans = INT_MIN;
        
        for(int i=0; i<n;i++){   
         ans = max(ans,(abs(ans1[i] - ans2[i]) - 1) * arr[i]);
         
        }
        
        return ans;
    }
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int v[m];
        
        for(int i=0; i<m; i++){
            v[i] = M[0][i];
        }
        
        int maxi = getMaxArea(v,m);
        
        
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(M[i][j] == 0) v[j] =  0;
                else v[j] +=M[i][j];
            }
            maxi = max(maxi, getMaxArea(v,m));
        }
        
        return maxi;
        
    }
};