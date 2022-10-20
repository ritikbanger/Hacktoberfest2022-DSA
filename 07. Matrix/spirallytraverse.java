//Username: DishaKhanapurkar
class Solution
{
    //Function to return a list of integers denoting spiral traversal of matrix.
    static ArrayList<Integer> spirallyTraverse(int matrix[][], int r, int c)
    {
          ArrayList<Integer> res=new ArrayList<>();

        int top=0;

        int down=r-1;

        int right=c-1;

        int left=0;

        int dir=0;

        while(top<=down&&left<=right){

            if(dir==0){

                for(int i=left;i<=right;i++){

                    res.add(matrix[top][i]);

                }

                top+=1;

            }

            else if(dir==1){

                for(int i=top;i<=down;i++){

                    res.add(matrix[i][right]);

                }

                right-=1;

            }

            else if(dir==2){

                for(int i=right;i>=left;i--){

                    res.add(matrix[down][i]);

                }

                down-=1;

            }

            else if(dir==3){

                for(int i=down;i>=top;i--){

                    res.add(matrix[i][left]);

                }

                left+=1;

            }

             dir=(dir+1)%4;

        }

        return res;

    }

}

 
