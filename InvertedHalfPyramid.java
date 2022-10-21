class InvertedHalfPyramid{
    public static void main(String args[]){
        
        int n=4;
        for(int i =1;i<=n;i++)
        {
            for(int j =n-i+1;j>=1;j--)
            {
                System.out.print(i);
            }
            System.out.println();
        }
    }
}
