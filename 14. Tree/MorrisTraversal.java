import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}


class MorrisTraversal {
    static List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<>();
        TreeNode curr = root;

        while (curr != null) {
            // Left subtree empty
            if (curr.left == null) {
                result.add(curr.val);
                curr = curr.right;
            }
            // Left subtree exists
            else {
                // Find curr's predecessor(go 1 left and right until null)
                TreeNode prev = curr.left;
                while (prev.right != null && prev.right != curr) {
                    prev = prev.right;
                }
                // Make thread and move curr
                if (prev.right == null) {
                    prev.right = curr;
                    curr = curr.left;
                }
                // Break thread
                else {
                    prev.right = null;
                    result.add(curr.val);
                    curr = curr.right;
                }
            }
        
        }
        return result;
    }
    
    public static void main(String[] args)
    {
        //     1
        //   2    3
        //     5    4

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.right = new TreeNode(5);
        root.right = new TreeNode(3);
        root.right.right = new TreeNode(4);

        List<Integer> result = inorderTraversal(root);
        System.out.println(result);
    }
}
