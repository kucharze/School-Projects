/**
 *                               //watsond1@duq.edu
 * Auto Generated Java Class.
 */
import java.util.Random;
public abstract class Board {
  public Stuff[][] grid;//the board
  public int numShipsSunk;//how many ships have been sunk
  public Water water=new Water();
  Random ran=new Random();
  public boolean hit;
  Ship[] ship = new Ship[5];
                                    
  public Board() {//creates the board for each player
    System.out.println("creating board");
    grid = new Stuff[10][10];//makes the board a 10x10 grid
    numShipsSunk = 0;
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
        grid[i][j] = water; //each spot on the board is originally water
      }
    }
    //Each of the ships
    ship[0] = new Ship("Aircraft Carrier", 5, "A", this);
    ship[1] = new Ship("Battleship", 4, "B", this);
    ship[2] = new Ship("Crusier", 3, "C", this);
    ship[3] = new Ship("Submarine", 3, "S", this);
    ship[4] = new Ship("Minesweeper", 2, "M", this);
    
    for(int i=0; i<5; i++){//places the ships on the board
      placeShip(ship[i]);
    }
    }
  
  abstract public Position getPosition(Ship ship, int direction);//original method for starting position for a ship
    
  abstract public int getDirection();//original method for direction of a ship
  
  
  public void placeShip(Ship ship){//palces the ships for both the player and the computer
        boolean worked=false;
        int r1=0;
        int r2=0;
        int r3=0;
    while(!worked){
      worked=true;
      r3=getDirection();
      Position p =getPosition(ship,r3);
      r1=p.x;
      r2=p.y;
      
      //checks to see if the location is valid
      //If a ship collides with another ship, that player selects a new position for that ship
      if (r3==0)
        for(int i=0; i<ship.getLength(); i++){
            if(grid[r1][r2+i]!=water)
              worked=false;
      }
          else
            for(int i=0; i<ship.getLength(); i++){
            if(grid[r1+i][r2]!=water)
              worked=false;
          }
    }
          if (worked)//Places the ship if it's location is valid
            if (r3==0)
          for(int i=0; i<ship.getLength(); i++)
            grid[r1][r2+i]=ship;
          else
            for(int i=0; i<ship.getLength(); i++)
            grid[r1+i][r2]=ship;
            
        
  }

  public void check(Position pos) {//checks for a hit or a miss
    grid[pos.x][pos.y]=grid[pos.x][pos.y].hit();
  }
  
  public boolean hit(Position p){//boolean for computer, chooses again if this is true
   return grid[p.x][p.y].alreadyHit;
  }
  

  public boolean allShipsSunk() {//all the ships for the player or computer have been sunk
    return numShipsSunk == 5;
  }
  
  public void sinkShip() {//sinks a ship for the player or the computer
    numShipsSunk++;
  }
  
  
  public String toString() {//Base method for printing out the board
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