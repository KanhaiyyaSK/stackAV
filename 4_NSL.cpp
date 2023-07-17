class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
            vector<int>ans;
            stack<int>st;
            
            // only change in directions
            for(int i=0; i<n; i++){
                
                if(st.empty()) ans.push_back(-1);
                
                else if(!st.empty() && st.top() < arr[i]){
                    ans.push_back(st.top());
                }
                else if(!st.empty() && st.top() >= arr[i]){
                    while(!st.empty() && st.top() >= arr[i]){
                        st.pop();
                    }
                    
                    if(st.empty()) ans.push_back(-1);
                    else ans.push_back(st.top());
                }
                
                
                st.push(arr[i]);
                
            }
            
            reverse(ans.begin(), ans.end());
            
            return ans;
    } 
};