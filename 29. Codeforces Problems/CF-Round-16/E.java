/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."
*/



import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
    static Map<Integer, List<Integer>> graph = new HashMap<>();
    static int minLeaves;
  
    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = sc.nextInt();
        for (int t = 0; t < test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        graph.clear();
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            graph.put(i, new ArrayList<>());
        }
      
        for (int i = 1; i < n; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
      
        minLeaves = 1;
        dfs(1, 0);
      
        out.println(minLeaves);
    }

  
    private static int dfs(int currNode, int parent) {
        int count = 0;
        for (int adjacent : graph.get(currNode)) {
            if (adjacent != parent) {
                count += dfs(adjacent, currNode);
            }
        }
        minLeaves += Math.max(0, count - 1);
        return count == 0 ? 1 : 0;
    }
  

    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}
