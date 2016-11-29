// Fig. 8.11: EnumTest.java
// Testing enum type Book.
import java.util.EnumSet;

public class EnumTest  {
   public static void main(String[] args)  {
      System.out.println("All books:");

      // print all books in enum Book
      for (Book book : Book.values())
         System.out.printf("%-10s%-45s%s%n", book,
             book.getTitle(), book.getCopyrightYear());

      System.out.printf("%nDisplay a range of enum constants:%n");
     
      // my attempt at optimization
      EnumSet<Book> books = EnumSet.range(Book.JHTP, Book.CPPHTP);

      // print first four books
      for (Book book : books)
         System.out.printf("%-10s%-45s%s%n", book,
             book.getTitle(), book.getCopyrightYear());
   }
} // end class EnumTest
