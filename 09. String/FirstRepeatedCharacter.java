import java.util.*;
public class FirstRepeatedCharacter{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while(t-- >0){
      String s = sc.next();
      Solution ob = new Solution();
      System.out.println(ob.firstRepChar(s));
    }
  
  }
}
class Solution 
{ 
    String firstRepChar(String s) 
    { 
        // code here
        Map<Character , Integer> hm = new HashMap<>();
        
        for(int i = 0 ; i < s.length() ; i++){
            char ch = s.charAt(i);
            if(hm.containsKey(ch)){
                return Character.toString(ch);
            }
            hm.put(ch , hm.getOrDefault(ch , 0) + 1);
        }
        return "-1";
    }
} 
