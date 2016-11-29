// Fig. 8.3: MemberAccessTest.java
// Private members of class Time1 are not accessible
public class MemberAccessTest  {
   public static void main(String[] args)  {
      Time1 time = new Time1(); // create and initialize Time1 object
         
      time.hour = 7; // error: hour has private access in Time1
      time.minute = 7; // error: minute has private access in Time1
      time.second = 7; // error: second has private access in Time1
   }
}
