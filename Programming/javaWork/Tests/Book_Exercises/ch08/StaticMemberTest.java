// Testing class for StaticMember

public class StaticMemberTest  {
   public static void main(String[] args)  {
      System.out.printf("Count before instantiation %d%n", StaticMember.getCount());
      StaticMember m1 = new StaticMember();
      StaticMember m2 = new StaticMember();

      System.out.printf("Attempting to set count for m1: ");
      m1.setCount(0);
      System.out.printf("Count is %d%n", StaticMember.getCount());
   }
}
