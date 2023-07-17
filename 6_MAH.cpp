//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1?page=2&category[]=Stack&sprint=94ade6723438d94ecf0c00c3937dad55&sortBy=submissions

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
        void NSR(long long arr[], int n, vector<int>&v){
        
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
    
    
    void NSL(long long arr[], int n, vector<int>&v){
        
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
    
    
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<int>ans1;
        vector<int>ans2;
        
        NSL(arr,n,ans1);
        NSR(arr,n,ans2);
        

        long long ans = LONG_MIN;
        
        for(int i=0; i<n;i++){   
         ans = max(ans,(abs(ans1[i] - ans2[i]) - 1) * arr[i]);
         
        }
        
        return ans;
    }
};