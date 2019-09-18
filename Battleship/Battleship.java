/**
 * Auto Generated Java Class.
 */
public class Battleship {
  
  
  public static void main(String[] args) { 
    Player player=new Player();
    Computer computer=new Computer();
    
    while(!computer.allShipsSunk()&&player.allShipsSunk()){
      System.out.println(player);
      System.out.println(computer);
      player.takeTurn(computer);
      computer.takeTurn(player);
    }
      
  }
  
  
  /* ADD YOUR CODE HERE */
  
}
