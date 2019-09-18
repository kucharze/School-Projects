/**
 * Auto Generated Java Class.
 */
public class Stuff {
  public boolean hit=false;
  public boolean isHit;
  public boolean alreadyHit;
  
  public Stuff hit(){
    hit=true;
    return this;
  }
  
  public boolean alreadyHit(){//boolean for if a spot has already been hit
    if(hit)
      alreadyHit=true;
    else
      alreadyHit=false;
    return alreadyHit;
  }
  
  /* ADD YOUR CODE HERE */
  
}
