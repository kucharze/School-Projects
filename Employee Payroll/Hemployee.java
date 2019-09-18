/**
 * Auto Generated Java Class.
 */
public class Hemployee extends Bemployee implements Employee {
  public double pay;
  public int hours;
  public int id;
  public int basePay;
  public static int numHemployees;
  
  public Hemployee(int id, int hours, double basePay){
    super(id, "H", hours,basePay);
    numHemployees++;
  }
  
  public double getPay(){
  return basePay; 
  }

  public int getHours(){
  return hours;
  }
  
  public double calculatePay(double basePay,int hours){//calculates pay
    int ot=0;
    if (hours>40){
      pay=(basePay*40);
      ot=hours-40;
      pay+=((basePay*1.5)*ot);
    }
    else
      pay=(basePay*hours);
    
    pay+=(pay*.2);
    return pay;
  }
  
  /* ADD YOUR CODE HERE */
  
}
