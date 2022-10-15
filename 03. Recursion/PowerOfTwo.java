package RECURSION;

public class PowerOfTwo {
    static int anspow(int n){
        if(n == 0){
            return 1;
        }
        return 2*anspow(n-1);
    }
    public static void main(String[] args) {
        int n = 5;
        System.out.println(anspow(n));
    }
}
