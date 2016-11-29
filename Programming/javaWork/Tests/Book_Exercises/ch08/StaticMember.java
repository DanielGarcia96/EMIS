// My own little test for static variables

public class StaticMember  {
   private static int count = 0;
   
   public StaticMember()  {
      count++;
      System.out.printf("Count is now %d%n", count);
   }

   // accessor method for count
   public static int getCount()  {
      return count;
   }

   // setter method for count
   public void setCount(int count)  {
      this.count = count;
   }
}
