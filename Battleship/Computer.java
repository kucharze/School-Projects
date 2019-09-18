/**
 * Auto Generated Java Class.
 */
import java.util.Random;
public class Computer extends Board {
  public Random ran=new Random();
  public int r1;
  public int r2;
  
  public Position getPosition(Ship ship, int direction){
    r1=ran.nextInt(10);
    r2=ran.nextInt(10);
    if(direction==0){
      return new Position(r1, r2-ship.getLength());  
  }
    else
      return new Position(r1-ship.getLength(),r2);
  }
  
  public int getDirection(){
    return ran.nextInt(2);
  }
  
  public void takeTurn(Player player){
       int r1;
    int r2;
    Position pos;
      do{
        //The computer randomly chooses a postion
        r1=ran.nextInt(10);
        r2=ran.nextInt(10);
        pos=new Position(r1,r2);
        player.check(pos);
        
        while(player.hit(pos)){//If the spot is already hit the computer picks a new position
          r1=ran.nextInt(10);
          r2=ran.nextInt(10);
          pos=new Position(r1,r2);
          check(pos);
        }
      }while(grid[pos.x][pos.y].isHit);//If the computer hit a player ship they go again
      
  } 
  
  
  public String toString() {//how the computer board is printed out
    String s = "  A B C D E F G H I J\n";
    for(int x=0; x<10; x++) {
      s += String.format("%2d", (x+1));
      for(int y=0; y<10; y++){
        if(grid[x][y]==ship[0]|| grid[x][y]==ship[1]|| grid[x][y]==ship[2] || grid[x][y]==ship[3] || 
           grid[x][y]==ship[4])
          s+=" " + water;
        else
          s += " " + grid[x][y];
      }
      s += "\n";
    }
    return s;
  }
   
  
  //public void takeTurn()
  
  /* ADD YOUR CODE HERE */
  
}
