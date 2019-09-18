public interface Employee extends Comparable {//this class is the online code from blackboard

    public double getPay();

    public int getHours();

    public double calculatePay(double basePay,int hours);//parameters were added here

    public int compareTo(Object o);

    public String toString();
}