class Solution {
    public int strStr(String source, String target) {
        int M = source.length();
        int N = target.length();
        if (M < N)
            return -1;
        long preCompute = 1;
        // to compute the mod of remove digits, base^(N-1) % q
        long hSource = 0;
        long hTarget = 0;
        long d = 31; // base
        long q = 1000000000000000003L; // hash table size

        for (int i = 0; i < N - 1; i++) {
            preCompute = (preCompute * d) % q; // (a%n * b%n)%n
        }

        for (int j = 0; j < N; j++) {
            hSource = (hSource * d + source.charAt(j)) % q;
            hTarget = (hTarget * d + target.charAt(j)) % q;
        }
        if (hSource == hTarget)
            return 0;
        for (int j = 1; j < M - N + 1; j++) {
            hSource = (hSource - source.charAt(j - 1) * preCompute) % q;
            // remove first digit
            hSource = (hSource * d + source.charAt(j + N - 1)) % q;
            // add new last digit
            if (hSource == hTarget) {
                if (source.substring(j, j + N).equals(target))
                    return j;
            }
        }
        return -1;
    }
}
