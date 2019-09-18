import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Codegenerator {
	public static String Codelist[]=new String[1000];
	public static ArrayList<String> tables=new ArrayList<String>();
	public static Token Symboltable[][]=new Token[30][30];
	public static int tableIndex[]=new int[25];
	public static Token intVars[]= new Token[50];
	public static Token charVars[]= new Token[50];
	public static Token constCharVars[]= new Token[50];
	public static Token constIntVars[]= new Token[50];
	public static Token ResWords[]= new Token[30];
	public static int i=0;
	
	final static int INT =101; //integer
	final static int INC=102;  //integer constant
	final static int INV = 103; //integer variable
	final static int CHAR= 107; //Characters
	final static int CHC=108;//character constant
	final static int CHV=109;//character variable
	final static int ARRAY=110;//Array
	
	final static int RES = 111; //Reserved Words
	final static int OPER = 112; //Operators
	final static int PUN = 113; //Punctuation
	
	public static void genAssignment(BufferedWriter writer)throws IOException{//TODO
		String value=Codelist[i];
		i+=2;
		String var=Codelist[i];
		writer.write("\t"+var+"="+value+";");
	}
	
	public static void genBool(BufferedWriter writer)throws IOException{//TODO
		String bool=Codelist[i];
		i++;
		String val1=Codelist[i];
		i++;
		String val2=Codelist[i];
		i++;
		if(Codelist[i].equals("goto")){
			i++;
			if(Codelist[i].charAt(0)=='L'){
				String label=Codelist[i];
				writer.write("\t"+"if("+val1+bool+val2+") goto " + label+";");
			}
		}
	}
	
	public static void genMath(BufferedWriter writer)throws IOException{//TODO
		String op=Codelist[i];
		i++;
		String val1=Codelist[i];
		i++;
		String val2=Codelist[i];
		i++;
		String var=Codelist[i];
		writer.write("\t"+var+"="+val1+op+val2+";");
	}
	
	public static void genVars(BufferedWriter writer)throws IOException{
		int Ic=0,Iv=0,chV=0,chC=0;
		int r=0;
		for(int j=0; j<25; j++){//reads through symbol table
			if(Symboltable[j][0]!=null){
				for(int k=0; k<25; k++){
					if(Symboltable[j][k]!=null){
						if(Symboltable[j][k].getType()==INC){
							constIntVars[Ic]=Symboltable[j][k];
							Ic++;
						}
						else if(Symboltable[j][k].getType()==RES){
							ResWords[r]=Symboltable[j][k];
							r++;
						}
						else if(Symboltable[j][k].getType()==INV){
							intVars[Iv]=Symboltable[j][k];
							Iv++;
						}
						else if(Symboltable[j][k].getType()==CHV){
							charVars[chV]=Symboltable[j][k];
							chV++;
						}
						else if(Symboltable[j][k].getType()==CHV){
							constCharVars[chC]=Symboltable[j][k];
							chV++;
						}
					}
				}
			}
		}
		if(intVars[0]!=null){
			writer.write("int ");
			for(int j=0; j<intVars.length; j++){
				if(intVars[j]!=null){
					writer.write(intVars[j].getName());
					if(intVars[j].getValue()!=0){
						writer.write("="+intVars[j].getValue());
					}
					if(intVars[j+1]==null){
						writer.write(";");
					}
					else{
						writer.write(", ");
					}
				}
				else
					break;
			}
			writer.newLine();
		}
		
		if(constIntVars[0]!=null){
			writer.write("const int ");
			for(int j=0; j<constIntVars.length; j++){
				if(constIntVars[j]!=null){
					writer.write(constIntVars[j].getName());
					if(constIntVars[j].getValue()!=0){
						writer.write("="+constIntVars[j].getValue());
					}
					if(constIntVars[j+1]==null){
						writer.write(";");
					}
					else{
						writer.write(", ");
					}
				}
				else
					break;
			}
			writer.newLine();
		}
		if(charVars[0]!=null){
			System.out.print("char ");
			for(int j=0; j<charVars.length; j++){
				if(constIntVars[j]!=null){
					writer.write(charVars[j].getName());
					if(charVars[j].getValue()!=0){
						writer.write("="+(char)charVars[j].getValue());
					}
					if(charVars[j+1]==null){
						writer.write(";");
					}
					else{
						writer.write(", ");
					}
				}
				else
					break;
			}
			System.out.println();
		}
		if(constCharVars[0]!=null){
			System.out.println("const char ");
			for(int j=0; j<constCharVars.length; j++){
				if(constCharVars[j]!=null){
					writer.write(constCharVars[j].getName());
					if(charVars[j].getValue()!=0){
						writer.write("="+(char)constCharVars[j].getValue());
					}
					if(constCharVars[j+1]==null){
						writer.write(";");
					}
					else{
						writer.write(", ");
					}
				}
				else
					break;
			}
			System.out.println();
		}
		
	}

	public static void generate(String c, String table, String asCode, int temps) throws IOException{<br>
		// TODO Auto-generated method stub
		BufferedReader reader=null;
		BufferedWriter writer=null;
		BufferedReader st=null;
		String spliter[];
		String code;
		String x;
		int position=0;
		
		try{
			//following destinations may be changed as needed
			reader=new BufferedReader(new FileReader(c));
			st=new BufferedReader(new FileReader(table));
            while ((code = reader.readLine()) != null) {//read in from file into an arraylist
            	spliter=code.split("\t");
            	for(int j=0; j<spliter.length; j++){
            		Codelist[i]=spliter[j];
            		i++;
            	}
            }
            
            while((x=st.readLine())!=null){
            	tables.add(x);
            }
            	for(int j=0; j<tables.size(); j++){
            		if(tables.get(j).charAt(1)==':'||tables.get(j).charAt(2)==':'){
            			if(tables.get(j).charAt(1)==':'){
            			position=Integer.parseInt(Character.toString(tables.get(j).charAt(0)));
            			
            			}
            			else{	
            				String number=" ";
            				number+=tables.get(j).charAt(0);
            				number+=tables.get(j).charAt(1);
            				StringBuilder sb = new StringBuilder(number);
            				sb.deleteCharAt(0);
            				
                			position=Integer.valueOf(Integer.parseInt(sb.toString()));
            			}
            		}   		
            		else{
            			spliter=tables.get(j).split("\t");
            			Symboltable[position][tableIndex[position]++]=new Token(spliter[0],Integer.valueOf(spliter[1]),Integer.valueOf(spliter[2]));
            		}
            	}
			
		}
		finally{
			if(reader!=null){
				reader.close();
			}
			if(st!=null){
				st.close();
			}
		}
		
		try{
			writer=new BufferedWriter(new FileWriter(asCode));
			writer.write("#include <iostream>");
			writer.newLine();
			writer.write("using namespace std;");
			writer.newLine();
			writer.newLine();
			writer.write("int ");
			for(int j=0; j<(temps+1); j++){
				if(j==temps){
					writer.write("t"+j + ";");
				}
				else{
					writer.write("t"+j + ", ");
				}
			}
			writer.newLine();
			genVars(writer);
			writer.newLine();
			writer.write("int main(){");
			writer.newLine();
			i=0;
			//writer.write(Codelist[i]);
			
			while(Codelist[i]!=null){//TODO
				 
				if(Codelist[i].equals("cout")){
					writer.write("\t"+Codelist[i]+" << ");
					i++;
					writer.write(Codelist[i]+";");
					writer.newLine();
					i++;
				}
				else if(Codelist[i].equals("cin")){
					writer.write("\t"+Codelist[i]+" >> ");
					i++;
					writer.write(Codelist[i]+";");
					writer.newLine();
					i++;
				}
				else if(Codelist[i].equals(">") || Codelist[i].equals("<") || Codelist[i].equals(">=") || 
						Codelist[i].equals("<=") || Codelist[i].equals("==")){
					//for boolean expressions
					genBool(writer);
					writer.newLine();
					i++;
				}
				else if(Codelist[i].equals("^") || Codelist[i].equals("&") || Codelist[i].equals("|")){
					genMath(writer);
					i++;
					writer.newLine();
				}
				else if(Codelist[i].equals("+") || Codelist[i].equals("-")|| Codelist[i].equals("*")){
					//setting a variable equal to a math expression
					genMath(writer);
					i++;
					writer.newLine();
				}
				else if(Codelist[i].equals("=")){
					//for setting a variable equal to a value
					i++;
					genAssignment(writer);
					i++;
					writer.newLine();
				}
				else if(Codelist[i].equals("goto")){
					//generating a goto statement
					writer.write("\t"+"goto");
					i++;
					writer.write(" "+Codelist[i]+";");
					writer.newLine();
					i++;
				}
				else if(Codelist[i].charAt(0)=='L'){
					//generating a label
					writer.write("\t"+Codelist[i]+":");
					i++;
					writer.newLine();
				}
			}/**/
			writer.write("\t"+"return 0;");
			writer.newLine();
			writer.write("}");
		}
		finally{
			if(writer!=null){
				writer.close();
			}
		}
		
		int CodeSize=0;
		for(int j=0; j<Codelist.length; j++){//for keeping track of number of tokens
			if(Codelist[j]!=null){
				CodeSize++;
			}
			else{
				break;
			}
		}
		System.out.println("Codelist.size = " + CodeSize + " of " + Codelist.length);
		System.out.println("Code generated");
	}

}
</body>
</html>