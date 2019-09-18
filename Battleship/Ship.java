/**
 * Auto Generated Java Class.
 */
public class Ship extends Stuff {
  public String name;
  public int size;
  public String symbol;
  public Hit hit;
  public int numHits;
  Board board;
  
  
  public Ship(String name, int size, String symbol, Board board){
    this.name=name; this.size=size; this.symbol=symbol; this.board=board;
  }
  
  public int getLength(){
    return size;
  }
  
  public String getName(){
    return name;
  }
  
  public Stuff hit() {//What happens if a ship is hit
    isHit=true;
    if(++numHits == size) {//If the ship sinks
      System.out.println("You sunk my " + name + "!");
      board.sinkShip();
      hit.setSymbol(symbol);
    }
    else //If only part of the ship was hit
      System.out.println("You hit my ship.");
    return hit; 
  }
  
  public String toString(){return symbol;}
    
  
  /* ADD YOUR CODE HERE */
  
}
