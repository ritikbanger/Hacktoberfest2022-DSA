/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."
*/


import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
    static class Pair {
        int sight;
        int id;
        Pair (int sight, int id) {
            this.sight = sight;
            this.id = id;
        }
    }
  
  
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
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Pair> list = new ArrayList<>();
        for (int i = 0; i < n * m; i++) {
            int sight = sc.nextInt();
            list.add(new Pair(sight, i));
        }
      
        // Sort by weight first and then by id
        Collections.sort(list, new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                if (p1.sight == p2.sight) {
                    return p1.id - p2.id;
                }
                return p1.sight - p2.sight;
            }
        });
      
        int inconvenience = 0;
        for (int i = 0; i < n * m; i += m) {
            List<Pair> currRowSeatedPeople = new ArrayList<>();
            for (int j = i; j < i + m; j++) {
                currRowSeatedPeople.add(new Pair(list.get(j).sight, list.get(j).id));
            }
            for (int j = 0; j < m; j++) {
                Pair currPerson = currRowSeatedPeople.get(j);
                for (int k = 0; k < j; k++) {
                    Pair alreadySeated = currRowSeatedPeople.get(k);
                    if (alreadySeated.sight == currPerson.sight) {
                        continue;
                    }
                    if (alreadySeated.id < currPerson.id) {
                        inconvenience++;
                    }
                }
            }
        }
        
        out.println(inconvenience);
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
