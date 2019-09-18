/**
 * Auto Generated Java Class.
 */
public class Hit extends Stuff {
  private String symbol = "x";
  
  public Hit hit(){
    System.out.println("You already shot there and hit");
    return this;
  }
  
    public void setSymbol(String symbol) {//sets the symbol for a ship getting hit
    this.symbol = symbol;
  }
  
  public String toString(){
    return symbol;
  }
  
  /* ADD YOUR CODE HERE */
  
}
