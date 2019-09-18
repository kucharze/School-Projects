/**
 * Auto Generated Java Class.
 */
public abstract class Bemployee implements Employee {
  public int id;
  public double pay;
  public int hours;
  public String type;
  public double basePay;
  public static int totHours=0;
  public static double totPay=0;
  
  public Bemployee (int id, String type, int hours,double basePay){
    this.id=id;
    this.type=type;
    this.hours=hours;
    pay=calculatePay(basePay,hours);
    totPay+=pay;
    totHours+=hours;
  } 
  
  public double getPay(){//returns the pay
    return pay;
  }

  public int getHours(){//returns the hours
    return hours;
  }

  public abstract double calculatePay(double basepay,int hours);
  //base method that calculates the pay for each type of employee
  

  public int compareTo(Object o){//compares the pay of two seperate employees
    Bemployee e=(Bemployee)o;
    if(pay<e.pay){
      return -1;
    }
    else if (pay>e.pay){
      return 1;
    }
    else
      return 0;
  }

    public String toString(){
      return "Employee " + id;
    }
  
  /* ADD YOUR CODE HERE */
  
}
