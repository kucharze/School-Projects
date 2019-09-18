public class Token {
	private String name;
	private int type;
	private int value;
	private int size;
	private int eltype;
	public Token next;
	
	public Token(String name, int type, int value){
		this.name=name;
		this.type=type;
		this.value=value;
		this.size=0;
		this.eltype=0;
	}
	
	public Token(String name, int type){
		this.name=name;
		this.type=type;
	}
	
	public String getName(){
		return this.name;
	}
	
	public void setName(String name){
		this.name=name;
	}
	
	public int getValue(){
		return this.value;
	}
	
	public void setValue(int value){
		this.value=value;
	}
	
	public void setType(int type){
		this.type=type;
	}
	
	public int getType(){
		return this.type;
	}
	
	public int getSize(){
		return this.size;
	}
	
	public void setSize(int size){
		this.size=size;
	}
	
	public int getEltype(){
		return this.eltype;
	}
	
	public void setEltype(int eltype){
		this.eltype=eltype;
	}
	
	public String toString(){
		return name+ " " + type+" "+value + " " + size + " " + eltype;
	}

}