/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
/**  The idea here is to traverse the tree in Preorder Traversal 
 *   At each Level , we can only see the node if it is > maxLevel at which we saw last node .
 *   While traversing in Right, Left , Node (Preorder)  we keep a currLevel variable and if our currLevel > maxLevel 
 *   we add it to our result list ;
 *
 *                      A          <---     
 *                B          C     <---
 *            D      E    F    G   <---        
 *         H  <---
 *      I    J   <---
 *   K  <---
 */
 //  result list = [ A, C, G, H, J, K ]



class Solution {
    int maxLevel = 0;
    List<Integer> list;
    public List<Integer> rightView(TreeNode root) {
        list = new ArrayList<>();
        helper(root,0);
        return list;
    }
    public void helper(TreeNode node, int curLevel){
        if(node==null) return;
        if(curLevel>=maxLevel){
            list.add(node.val);
            l++;
       }
        helper(node.right,cl+1);
        helper(node.left,cl+1);
            
    }
}

