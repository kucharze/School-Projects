import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Lexicalanalyser {
	static Token table[] =new Token[200];
	static ArrayList<Character> program=new ArrayList<Character>();
	static int size=0;
	public static int value=0;
	
	/*datatype values*/
	final static int INT =101; //integer
	final static int INC=102;  //integer constant
	final static int INV = 103; //integer variable
	final static int CHAR= 107; //Characters
	
	/*Compound Operator Values*/
	final static int NE = 200; //!=
	final static int LE =201; //<=
	final static int GE =202; //>=
	final static int EQEQ= 203;// ==
	final static int OR =204; //||
	final static int AND =205; //&&
	final static int GT = 206; //>>
	final static int LT = 207; //<<
	final static int Incr = 208; //++
	final static int Decr = 209; //--
	final static int SCOPE = 210; //::
	
	/*Types*/
	final static int RES = 111; //Reserved Words
	final static int OPER = 112; //Operators
	final static int PUN = 113; //Punctuation
	
	final static String[] Keywords = {"break",
			"char", "class","cin", "cout", "const", "continue", 
			"delete", "do","else", "endl", "error","include", "if",
			"iostream","int", "for", "goto","main","new","namespace",
			"std","static","using", "return", "void","while"
			};
	
    public boolean isEmpty() {//checks if the table is empty
        return size == 0;
    }
    
    public static boolean contains(String key) {//checks if the table has a key
        if (key == null) throw new IllegalArgumentException("Error: Key argument is null");
        return find(key) != null;
    }

    
    private static int hash(String key) {// hash function for keys - returns value between 0 and M-1
    	int s = key.charAt(0);
    	
    	return s % 20; 
    }

    public static int getHash(String key) {
    	return hash(key);
    }
    
    public static void insert(Token val) {//put a token in the table
        if (val == null) throw new IllegalArgumentException("first argument to put() is null");
        
        int i = hash(val.getName()), pos = 0;
        String key = val.getName();
        
        if(val.getType()==111){
        	Token v=new Token(val.getName(),val.getType(),value++);
        	
            if(table[i] == null) {table[i] = v; }
            Token t = table[i];
            
            while(true) {
            	if(t.getName().equals(key)) { break; }
            	if(t.next == null) { t.next = v; break; }
            	t = t.next;    	
            }
            size++;
        }
        else{
        if(table[i] == null) {table[i] = val; }
        Token t = table[i];
        
        while(true) {
        	if(t.getName().equals(key)) {
        		break; }
        	if(t.next == null) { t.next = val; t.next.setValue(pos+1); break; }
        	t = t.next; pos++;    	
        }
        
        size++;
        }
        
    }

    public static Token find(String key) {//grabs a value from the table
        if (key == null) throw new IllegalArgumentException("argument to get() is null");

        int i = hash(key);
        Token t = table[i];
        if(t == null) {return null;}
        while(true) {
        	if(t.getName().equals(key)) { return t; }
        	if(t.next == null) { return null; }
        	t = t.next;
        }
    }
	
	
	public static void read(String code, String tokens, String st) throws IOException{
		// TODO Auto-generated method stub
		FileInputStream reader =null;
		BufferedWriter writer=null;
		BufferedWriter wr=null;
		int c=0;
		char cha='a';
		
		for(String s : Keywords) {
			insert(new Token(s, 111));
		}
		
        //these file names may be changed as needed
            reader = new FileInputStream(code);
            writer = new BufferedWriter(new FileWriter(tokens));
            wr = new BufferedWriter(new FileWriter(st));
            
            while ((c = reader.read()) != -1) {//read in from file into an arraylist
            	cha=(char)c;
            	program.add(cha);
            	//System.out.print(cha);
            }
            /* for purposes of testing
            for(int k=0; k<program.size(); k++){
            	System.out.print(program.get(k));
            }*/
            
            for(int i=0; i<program.size(); i++){
     //comments	
           	if(program.get(i)=='/'){
            		if(i<=program.size()){
            		//read from /* to */
            			if(program.get(i+1)=='*'){
            				i+=2;//
            				while(program.get(i)!=null){
            					//System.out.println(" checking for */");
            					//System.out.println("Current="+program.get(i));
            					//System.out.println("Next="+program.get(i+1));
            					if(program.get(i)=='*'){
            						i++;
            						if(program.get(i)=='/'){
            							i++;
            							break;
            						}
            					}
            					else if(i==program.size()){
            						System.out.println("Error: reached end while still parsing");
            						System.exit(0);
            					}
        						else{
        							i++;
        						}
            				}
            			}
            			
            			//line comment, skip to the end of line
            			else if(program.get(i+1)=='/'){
            				i++;
            				while(program.get(i)!='\r'){
            					if(i==program.size()){
            						System.exit(0);
            					}
            					else{
            						i++;
            					}
            				}
            			}
            			
            			else{
            				//System.out.println("found a / " +(int)'/');
            				writer.write(OPER+"\t"+ (int)'/');
                			writer.newLine();
            			}
            		}
            		
            		else{
            			writer.write(OPER+"\t"+ (int)'/'+ "\t");
            			writer.newLine();
            		}
            	}
           	 //numbers
            	else if(Character.isDigit(program.get(i))){//TODO
            		String number=Character.toString(program.get(i));
            		i++;
            		while(i < program.size() && (Character.isDigit(program.get(i)))) {
    					number += Character.toString(program.get(i));
    					i++;
    				}
            		
            		writer.write(INT + "\t" + number + "\t");
            		writer.newLine();
            		i--;
            	}
          //single quotes
            	else if(program.get(i)=='\''){//TODO
            		i++;
            		String character=Character.toString(program.get(i));
            		while(i++ < program.size() && program.get(i)!='\n') {
            			if(program.get(i)=='\'')
            				break;
            			character+=program.get(i);
            		}
            		
            		if(i==program.size()){
            			System.out.println("Error: unterminated characater");
            			System.exit(0);
            		}
            		
            		if(!contains(character)){
            			insert(new Token(character,getHash(character)));
            		}
            		Token t=find(character);
            		
            		writer.write(t.getType() + "\t" + t.getValue());
            		writer.newLine();
            	}
          //double quotes
            	else if(program.get(i)=='"'){//TODO
            		i++;
            		String letters=Character.toString(program.get(i));
            		while(i++ < program.size() && program.get(i)!='\n') {
            			if(program.get(i)=='"'){
            				i++;
            				break;
            			}
            			letters+=program.get(i);
            		}
            		//System.out.println("Letters = "+ letters);
            		//System.out.println("Current token is "+ program.get(i));
            		if(i==program.size()){
            			System.out.println("Error: unterminated string");
            			System.exit(0);
            		}
            		
            		if(!contains(letters)){
            			insert(new Token(letters,getHash(letters)));
            		}
            		Token t=find(letters);
            		writer.write(t.getType()+"\t"+t.getValue());
            		writer.newLine();
            		//i--;
            	}
         //keywords or identifiers
            	else if(Character.isLetter(program.get(i))||program.get(i)=='_'){
            		String id=Character.toString(program.get(i));
            		i++;
            		while(i < program.size() && (Character.isLetterOrDigit(program.get(i)) || 
            				program.get(i) == '_')) {
    					id += Character.toString(program.get(i));
    					i++;
    				}
            		
            		if(i==program.size()){
            			System.out.println("Error");
            			System.exit(0);
            		}
            		//System.out.println("id=" + id);
    				if(!contains(id)) {
    					insert(new Token(id, getHash(id)));
    				}
    				
    				Token t = find(id);
    				writer.write(t.getType() + "\t" + t.getValue()); 
    				writer.newLine();
    				i--;
            		}
            	
          //Operators-
            	else if(program.get(i)=='+'){//TODO
            		if(i==program.size()-1){
            			writer.write(OPER + "\t" + (int)'+');
            			writer.newLine();
            		}
            		else{
            			if(program.get(i+1)=='+'){
            				i++;
            				writer.write(OPER + "\t" + Incr);
            				writer.newLine();
            			}
            			else{
            				writer.write(OPER + "\t" + (int)'+');
            				writer.newLine();
            			}	
            		}
            	}
            	
            	else if(program.get(i)=='='){
            		if(i==program.size()-1){
            			writer.write(OPER + "\t" + (int)'=');
            			writer.newLine();
            		}
            		else{
            			if(program.get(i+1)=='='){
            				i++;
            				writer.write(OPER + "\t" + EQEQ);
            				writer.newLine();
            			}
            			else{
            				writer.write(OPER + "\t" + (int)'=');
            				writer.newLine();
            			}
            		}
            	}
            	
            	else if(program.get(i)=='!'){
            		if(i==program.size()-1){
            			writer.write(PUN + "\t" + (int)'!');
            			writer.newLine();
            		}
            		else{
            			if(program.get(i+1)=='='){
            				i++;
                			writer.write(OPER + "\t" + NE);
                			writer.newLine();
            			}
            			else{
            				writer.write(PUN + "\t" + (int)'!');
                			writer.newLine();
            			}
            		}
            	}
            	
            	else if(program.get(i)=='-'){
            		if(i==program.size()-1){
            			writer.write(OPER + "\t" + (int)'-');
            			writer.newLine();
            		}
            		else{
            			if(program.get(i+1)=='-'){
            				i++;
            				writer.write(OPER + "\t" + Decr);
            				writer.newLine();
            			}
            			else{
            				writer.write(OPER + "\t" + (int)'-');
            				writer.newLine();
            			}
            		}
            	}
            	
            	else if(program.get(i)=='|'){
            		if(i==program.size()-1){
            			writer.write(OPER + "\t" + (int)'|'); 
            			writer.newLine();
            		}
            		else{	
            			if(program.get(i+1)=='|'){
            				i++;
            				writer.write(OPER + "\t" + OR);
            				writer.newLine();
            			}
            			else{
            				writer.write(OPER + "\t" + (int)'|'); 
            				writer.newLine();
            			}
            		}
            	}
            	
            	else if(program.get(i)=='&'){
            		if(i==program.size()-1){
            			writer.write(OPER + "\t" + (int)'&'); 
            			writer.newLine();
            		}
            		else{
            			if(program.get(i+1)=='&'){
            				i++;
            				writer.write(OPER + "\t" + AND); 
            				writer.newLine();
            			}
            			else{
            				writer.write(OPER + "\t" + (int)'&'); 
            				writer.newLine();
            			}
            		}
            	}
            	
            	else if(program.get(i)=='<'){
            		if(program.get(i+1)=='<'){
            			i++;
            			writer.write(OPER + "\t" + LT); 
            			writer.newLine();
            			i++;
            		}
            		else if(program.get(i+1)=='='){
            			i++;
            			writer.write(OPER + "\t" + LE); 
            			writer.newLine();
            			i++;
            		}
            		else{
            			writer.write(OPER + "\t" + (int)'<');
            			writer.newLine();
            		}
            	}
            	
            	else if(program.get(i)=='>'){
            		if(i==program.size()-1){
            			writer.write(OPER + "\t" + (int)'>'); 
            			writer.newLine();
            		}
            		else{
            			if(program.get(i+1)=='>'){
            				i++;
            				writer.write(OPER + "\t" + GT); 
            				writer.newLine();
            				i++;
            			}
            			else if(program.get(i+1)=='='){
            				i++;
            				writer.write(OPER + "\t" + GE); 
            				writer.newLine();
            				i++;
            			}
            			else{
            				writer.write(OPER + "\t" + (int)'>'); 
            				writer.newLine();
            			}
            		}
            	}
            	
          //punctution
            	else if(program.get(i)=='.'){//TODO
            		writer.write(PUN + "\t" + (int)'.');
            		writer.newLine();
            	}
            	else if(program.get(i)=='*'){
            		writer.write(PUN + "\t" + (int)'*');
            		writer.newLine();
            	}
            	else if(program.get(i)==','){
            		writer.write(PUN + "\t" + (int)',');
            		writer.newLine();
            	}
            	else if(program.get(i)==':'){
            		if(i==program.size()-1){
            			writer.write(PUN + "\t" + (int)':');
            			writer.newLine();
            		}
            		else{
            			if(program.get(i+1)==':'){
            				writer.write(PUN + "\t" + SCOPE);
            				writer.newLine();
            				i++;
            			}
            			else{
            				writer.write(PUN + "\t" + (int)':');
            				writer.newLine();
            			}
            		}
            	}
            	else if(program.get(i)=='%'){
            		writer.write(PUN+"\t" +(int)'%');
            		writer.newLine();
            	}
            	else if(program.get(i)=='#'){
            		writer.write(PUN+"\t" +(int)'#');
            		writer.newLine();
            	}
            	else if(program.get(i)==';'){
            		//System.out.println("; is equal to " +(int)';');
            		writer.write(PUN + "\t" + (int)';');
            		writer.newLine();
            	}
            	else if(program.get(i)=='{'){
            		writer.write(PUN + "\t" + (int)'{');
            		writer.newLine();
            	}
            	else if(program.get(i)=='('){
            		writer.write(PUN + "\t" + (int)'(');
            		writer.newLine();
            	}
            	else if(program.get(i)=='}'){
            		//System.out.println((int)'}');
            		writer.write(PUN + "\t" + (int)'}');
            		writer.newLine();
            	}
            	else if(program.get(i)==')'){
            		writer.write(PUN + "\t" + (int)')');
            		writer.newLine();
            	}
            	else if(program.get(i)=='['){
            		writer.write(PUN + "\t" + (int)'[');
            		writer.newLine();
            	}
            	else if(program.get(i)==']'){
            		writer.write(PUN + "\t" + (int)']');
            		writer.newLine();
            	}
        }
    		
    		for(int i = 0; i < table.length; i++) {
    			if(table[i] != null) {
    				Token temp = table[i];
    				wr.write(i + ": ");
    				wr.newLine();
    				while(temp != null) {
    					//String formatStr = "%-20s %-15s %-15s";
    					wr.write(temp.getName()+"\t"+ temp.getType()+"\t" + temp.getValue());
    					wr.newLine();
    					temp = temp.next;
    				}
    			}
    		}
            if (reader != null) {
                reader.close();
            }
            if (writer != null) {
                writer.close();
            }
            if (wr != null) {
                wr.close();
            }
            System.out.println("Done Anaylzing");
    }
}