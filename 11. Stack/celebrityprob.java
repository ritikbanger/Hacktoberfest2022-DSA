//username :DishaKhanapurkar
class Solution
{ 
    //Function to find if there is a celebrity in the party or not.
    int celebrity(int M[][], int n)
    {
    	// code here 
    	 Stack<Integer> st=new Stack<>();

        for(int i=0; i<n; i++)

        {

            st.push(i);

        }

        while(st.size()>=2)

        {

            int v1=st.pop();

            int v2=st.pop();

            if(M[v1][v2]==1)

            {

                st.push(v2);

            }

            else

            {

                st.push(v1);

            }

        }

        int last=st.pop();

        for(int i=0; i<n; i++)

        {

            if(i!=last)

            {

                if(M[last][i]==1|| M[i][last]==0)

                {

                    return -1;

                }

            }

        }

        return last;

        

    }
    }
