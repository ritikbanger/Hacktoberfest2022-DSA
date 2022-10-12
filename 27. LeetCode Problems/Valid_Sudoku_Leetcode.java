public class Valid_Sudoku_Leetcode {
	    public boolean isValidSudoku(char[][] board) {
	        int i,j;
	        HashSet<Character> hs=new HashSet();
	        HashSet<Character> col=new HashSet();
	        HashSet<Character> grid=new HashSet();
	        
	        for(i=0;i<board.length;i++)
	        {
	            for(j=0;j<board[i].length;j++)
	            {
	                if(board[i][j]!='.')
	                {
	                    if(hs.contains(board[i][j]))
	                        return false;
	                    hs.add(board[i][j]);
	                }
	            }
	            for(j=0;j<board.length;j++)
	            {
	                if(board[j][i]!='.')
	                {
	                    if(col.contains(board[j][i]))
	                        return false;
	                    col.add(board[j][i]);
	                }
	            }
	            // for(char c:hs)
	            //     System.out.print(c+" ");
	            // System.out.println();
	            // for(char c:col)
	            //     System.out.print(c+" ");
	            // System.out.println();
	            hs.clear();
	            col.clear();
	        }
	        
	        int index=0,k,l;
	        for(i=0;i<board.length;i=i+3)
	        {
	            for(l=0;l<board.length;l=l+3)
	            {
	                for(j=i;j<i+3;j++)
	                {
	                    for(k=l;k<(l+3);k++)
	                    {
	                        if(board[j][k]!='.')
	                        {
	                            if(grid.contains(board[j][k]))
	                                return false;
	                            grid.add(board[j][k]);
	                        }
	                    }
	                }
	                // for(char c:grid)
	                //     System.out.print(c+" ");
	                // System.out.println();
	                grid.clear();
	            }
	        }
	        return true;
	    }
	}
