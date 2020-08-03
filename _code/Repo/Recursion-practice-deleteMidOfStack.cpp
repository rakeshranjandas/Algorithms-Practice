stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
   // cout << "->" << current << endl;
    
    int mid = sizeOfStack/2;
    
    if (current > mid)
        return s;
    
    int top_el = s.top();
    s.pop();
    
    stack<int> st = deleteMid(s, sizeOfStack, current+1);
    
    if (current < mid)
        st.push(top_el);
    
    return st;
}