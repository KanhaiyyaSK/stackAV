class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>ans;
        stack<long long>st;
        
        // change in for loop only
        for(int j=0; j<n; j++){
            
            if(st.empty()) ans.push_back(-1);
            
            else if(!st.empty() && st.top() > arr[j]){
                ans.push_back(st.top());
            }
            else if(!st.empty() && st.top() <= arr[j]){
                
                while(!st.empty() && st.top() <= arr[j]){
                    st.pop();
                }
                
                if(st.empty()) ans.push_back(-1);
                else{
                    ans.push_back(st.top());
                }
                
            }
                
            st.push(arr[j]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
        
    }
};