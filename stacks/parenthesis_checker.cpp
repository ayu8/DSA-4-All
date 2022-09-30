bool ispar(string x)
{
    // Your code here
    stack<char> st;

    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '{' || x[i] == '(' || x[i] == '[')
        {
            st.push(x[i]);
        }
        else
        {
            if (x[i] == st.top())
            {
                st.pop();
            }
            else
            {
                st.push
            }
        }
    }
}