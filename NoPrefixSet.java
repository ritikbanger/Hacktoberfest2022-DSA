import java.io.*;
import java.util.*;

public class Trie {

    private static final int ALPHABET_SIZE = 26;

	class Node {
	    
	    Node[] edges;
	    char key;
	    int wordCount = 0;
	    int prefixCount = 0;
	    
	    Node(char key) {
	        this.key = key;
	        this.edges = new Node[ALPHABET_SIZE];
	    }
	    
	    boolean has(char key) {
	        return get(key) != null;
	    }
	    
	    Node get(char key) {
    	    return edges[getKey(key)];
	    }
	    
	    void put(char key, Node node) {
	        this.edges[getKey(key)] = node;
	    }
	    
	    char getKey(char ch) {
	        return (char) (ch - 'a');
	    }
	    
	}
		
	private Node root = new Node('\0');
	
	public boolean insert(String word) {
	    return insert(word, root);
	}
	
	private boolean insert(String word, Node root) {
    	root.prefixCount++;
        if (word.length() >= 0 && root.wordCount > 0) {
            return false;
        }
	    if (word.length() == 0) {
	        if (root.prefixCount > 1) {
	            return false;
	        }
	    	root.wordCount++;	    	
	    	return true;
	    }	    
	    char ch = word.charAt(0);
	    Node next = root.get(ch);	    
	    if (next == null) {
	        next = new Node(ch);	        
	        root.put(ch, next);
	    }	    
	    return insert(word.substring(1), next);	    
	}	
	
	public static void main(String[] args) throws IOException {		
	
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));		
		
		Trie trie = new Trie();        
        int n = Integer.parseInt(in.readLine());
        
        boolean bad = false;
        while (n-- > 0) {
            String word = in.readLine();  
            bad = !trie.insert(word);            
            if (bad) {
                out.println("BAD SET\n"+word);    
                break;
            }
        }
        

        if (!bad) {
            out.println("GOOD SET");
        }        
        out.close();
		
	}	
	
}
