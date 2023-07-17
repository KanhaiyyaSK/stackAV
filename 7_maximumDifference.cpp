//https://practice.geeksforgeeks.org/problems/maximum-difference-1587115620/1

class Solution{
    public:
    /*You are required to complete this method */
    
    void NSR(int arr[], int n, vector<int>&v){
        
        stack<int>st;
        
        
        for(int i=n-1; i>=0; i--){
            
            
            if(st.empty()) v.push_back(0);
            
            else if(!st.empty() && st.top() < arr[i]){
                v.push_back(st.top());
            }
            
            else if(!st.empty() && st.top() >= arr[i]){
                while(!st.empty() && st.top()>= arr[i]){
                    st.pop();
                }
                if(st.empty()) v.push_back(0);
                else {
                    v.push_back(st.top());
                }
            }
            
            st.push(arr[i]);
            
        }
        reverse(v.begin(), v.end());
        
    }
    
    
    void NSL(int arr[], int n, vector<int>&v){
        
        stack<int>st;
        
        
        for(int i=0; i<n; i++){
            
            
            if(st.empty()) v.push_back(0);
            
            else if(!st.empty() && st.top() < arr[i]){
                v.push_back(st.top());
            }
            
            else if(!st.empty() && st.top() >= arr[i]){
                while(!st.empty() && st.top()>= arr[i]){
                    st.pop();
                }
                if(st.empty()) v.push_back(0);
                else {
                    v.push_back(st.top());
                }
            }
            
            st.push(arr[i]);
            
        }
        
    }
    
    
    
    int findMaxDiff(int A[], int n)
    {
      //Your code here
      vector<int>ans1;
      vector<int>ans2;
      
      NSL(A,n,ans2); 
      NSR(A,n,ans1);
      
      
      int ans = INT_MIN;
      
      for(int i=0; i<ans2.size(); i++){
          ans = max(ans,abs(ans1[i]-ans2[i]));
      }
      
      
      return ans;
    }
};