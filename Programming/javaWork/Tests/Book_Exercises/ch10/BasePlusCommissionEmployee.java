// Fig. 9.8: BasePlusCommissionEmployee.java
// private superclass members cannot be accessed in a subclass.
package core;

public class BasePlusCommissionEmployee extends CommissionEmployee  {
   
   private double baseSalary; // base salary per week
   
   // six-argument constructor
   public BasePlusCommissionEmployee(String firstName, String lastName,
      String socialSecurityNumber, double grossSales,
      double commissionRate, double baseSalary)  {

      // explicit call to superclass CommissionEmployee constructor
      super(firstName, lastName, socialSecurityNumber,
         grossSales, commissionRate);

      // if baseSalary is invalid throw exception
      if(baseSalary <  0.0)
         throw new IllegalArgumentException(
            "Base salary must be >= 0.0");

      this.baseSalary = baseSalary;
   }

   // set base salary
   public void setBaseSalary(double baseSalary)  {
      if (baseSalary < 0.0)
         throw new IllegalArgumentException(
            "Base salary must be >= 0.0");
      
      this.baseSalary = baseSalary;
   }

   // return base salary
   public double getBaseSalary()  {
      return baseSalary;
   }

   // calculate earnings; override method eearnings in CommissionEmployee
   @Override
   public double earnings()  {
      return getBaseSalary() + super.earnings();
   }

   // return String representation of BasePlusCommissionEmployee
   @Override
   public String toString()  {
      return String.format(
         "%s %s; %s: %,.2f",
         "base-salaried", super.toString(),
         "base salary", getBaseSalary());
   }
} // end class BasePlusCommissionEmployee
