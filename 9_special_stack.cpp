//https://practice.geeksforgeeks.org/problems/special-stack/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
stack<int>ss;

void push(stack<int>& s, int a){
    
    s.push(a);
    
    if(ss.size() == 0 || ss.top() >= a) ss.push(a);
}

bool isFull(stack<int>& s,int n){
	return s.size() == n;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
	if(s.size() == 0) return -1;
	
	int ans = s.top();
	s.pop();
	
	if(ans == ss.top()) ss.pop();
	
	return ans;
}

int getMin(stack<int>& s){
	if(ss.size() == 0) return -1;
	
	return ss.top();
}