/**
 * Auto Generated Java Class.
 */
import java.util.Scanner;
public class Player extends Board {
public static Scanner sc=new Scanner(System.in);
public int p;
  
  public Position getPosition(Ship ship,int direction){//set's position for the player's ship
    System.out.println("Where would you like to start your " + ship.getName() + " ?");
    return Position.getPosition();
  }
  
  public int getDirection(){
    System.out.println("Select a direction for your ship.");
    System.out.println("0. right. 1. down");
    return sc.nextInt();
  }
  
  public void takeTurn(Computer computer){
    Position pos;
    do{
      pos=Position.getPosition();
      computer.check(pos);
    }while(grid[pos.x][pos.y].isHit);
  }
    
  
  public String toString() {//How the player board is printed out
    String s = "  A B C D E F G H I J\n";
    for(int x=0; x<10; x++) {
      s += String.format("%2d", (x+1));
      for(int y=0; y<10; y++) 
        s += " " + grid[x][y];
      s += "\n";
    }
    return s;
  }
  /* ADD YOUR CODE HERE */
  
}
