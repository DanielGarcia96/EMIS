public class Solution {
   public String reverseString(String s) {
      int i;
      String hold1 = "";
      String hold2 = "";
      for(i=0; i<s.length()/2; i++) {
         hold1 += s.charAt(s.length()-(i+1));
         hold2 = s.charAt(i) + hold2;
      }
      if ( s.length() % 2 == 1 )
         hold2 = s.charAt(i) + hold2;
      return hold1+hold2;
   }
}
