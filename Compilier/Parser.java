import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Parser {
	static ArrayList<String> tables=new ArrayList<>();
	private static Token tokenList[]=new Token [1000];
	private static Token vars[]=new Token[30];
	private static Token Symboltable[][]=new Token[25][25];
	private static int tableIndex[]=new int[25];
	private static int asciCode[]=new int[52];
	private static String output[]= new String[30];
	private static int numOuts=0;
	private static int i=0;
	private static int size;
	private static int position=0;
	private static int numTemps=0;
	private static int numBTemps=1;
	private static int maxTemps=0;
	
	/*datatype values*/
	final static int INT =101; //integer
	final static int INC=102;  //integer constant
	final static int INV = 103; //integer variable
	final static int CHAR= 107; //characters
	final static int CHC=108;//character constant
	final static int CHV=109;//character variable
	final static int ARRAY=110;//Array
	
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
	
	public static int AsciCode(char ch){
		for(int j=0; j<asciCode.length;j++){
			if((int)ch==asciCode[j]){
				return asciCode[j];
			}
		}
		return 0;
	}
	
	public static String newTemp(){
		String temp="t" + numTemps;
		numTemps++;
		return temp;
	}
	
	public static String newLTemp(){//TODO
		String temp="L" + numBTemps;
		numBTemps++;
		return temp;
	}
	
	public static void resetTemp(){
		if((numTemps-1)>=maxTemps){
			maxTemps=(numTemps-1);
		}
		numTemps=1;
	}
	
	public static Token findInTable(int a, int b){
		if(a>25 || b>25)
			return null;
		
		Token ta=Symboltable[a][b];
		
		if(ta!=null)
			return ta;
		else
			return null;
	}
	
	public static boolean findVar(Token v){//checks to see if the variable is declared
		for(int j=0; j<vars.length; j++){
			if(vars[j]==null){
				break;
			}
			if(vars[j].getName().equals(v.getName())){
				//return true and break
				return true;
			}
		}
		return false;
	}
	
	public static void declaration(){//finds a variable
		String varType=varType();
		i++;
		boolean dec=true;
		while(dec){
		if(tokenList[i].getType()==RES){
			System.out.println("Error invalid variable decarator");
			System.exit(0);
		}
		Token t=findInTable(tokenList[i].getType(),tokenList[i].getValue());
		
		if(findVar(t)){//check to see if this variable has been declared already
			System.out.println("Error duplicate local variable");
			System.exit(0);
		}
		if(varType=="int"){
			t.setType(INV);
		}
		else{
			t.setType(CHV);
		}
		t.setValue(0);
		i++;
		if(tokenList[i].getType()==OPER && tokenList[i].getValue()==(int)'='){
			i++;
			int value=findValue(varType);
			if(varType=="int"){
				t.setType(INV);
			}
			else{
				t.setType(CHV);
			}
				t.setValue(value);
			i++;
		}
		else if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'['){
			//check for a number or an array
			i++;
			t.setType(ARRAY);
			int array=findValue("int");
			t.setSize(array);
			if(varType=="int"){
				t.setEltype(INC);
			}
			else{
				t.setEltype(CHC);
			}
			i++;
			if(tokenList[i].getType()!=PUN && tokenList[i].getValue()!=(int)']'){
				System.out.println("Error: expecting ]");
				System.exit(0);
			}
			i++;
		}
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)','){
			//another variable on this line, repeat this process
			vars[size++]=t;
			dec= true;
			i++;
		}
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)';'){
			//done with this line move to the next line
			i++;
			vars[size++]=t;
			dec = false;
		}
		
		}
		return;
	}
	
	public static void constDeclaration(){//finds a constant variable
			i++;
			String varType=varType();
			i++;
			Token t;
			boolean dec=true;
		while(dec){
			t=null;
		if(tokenList[i].getType()==RES){
			System.out.println("Error invalid variable decarator");
			System.exit(0);
		}
		t=findInTable(tokenList[i].getType(),tokenList[i].getValue());//check to see if this variable has been declared already
		
		if(findVar(t)){
			System.out.println("Error dulicate local variable");
			System.exit(0);
		}
		if(varType=="int"){
			t.setType(INC);
		}
		else{
			t.setType(CHC);
		}
		t.setValue(0);
		i++;
		if(tokenList[i].getType()==OPER && tokenList[i].getValue()==(int)'='){
			i++;
			int value=findValue(varType);
			t.setValue(value);
			i++;
		}
		else if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'['){
			//handling an array
			//check for a number or variable
			i++;
			t.setType(ARRAY);
			int array=findValue("int");
			t.setSize(array);
			if(varType=="int"){
				t.setEltype(INC);
			}
			else{
				t.setEltype(CHC);
			}i++;
			if(tokenList[i].getType()!=PUN && tokenList[i].getValue()!=(int)']'){
				System.out.println("Error: expecting ]");
				System.exit(0);
			}
			i++;
		}
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)','){
			//another varaiable to be declared in this block
			i++;
			vars[size++]=t;
			dec= true;
		}
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)';'){
			//done with this line move to the next line
			i++;
			vars[size++]=t;
			dec = false;
		}
		}
		return;
	}
	
	public static void assignment(BufferedWriter writer)throws IOException{//TODO
		Token t=findInTable(tokenList[i].getType(),tokenList[i].getValue());
		String index="";
		String result="";
		if(!findVar(t)){
			System.out.println("Error: Variable not declared");
			System.exit(0);
		}
		if(t.getType()==RES){
			System.out.println("Error: illegal usage of a reserved word");
			System.exit(0);
		}
		
		if(t.getType()==ARRAY){
			if(tokenList[i+1].getType()==PUN && tokenList[i+1].getValue()=='['){
				i+=2;
				index=exp(writer);
			}
			else{
				System.out.println("Error, Missing [");
				System.exit(0);
			}
			if(tokenList[i].getType()!=PUN && tokenList[i].getValue()!=']'){
				System.out.println("Error Missing ]");
				System.exit(0);
			}
			result=newTemp();
			writer.write("="+ "\t"+ index + "\t\t" + result);
			writer.newLine();
		}
		
		i++;
		if(!(tokenList[i].getType()==OPER && tokenList[i].getValue()==(int)'=')){
			System.out.println("Error: the assignment operator is missing an assignment statement");
			System.exit(0);
		}
		i++;
		String arg=exp(writer);
		if(t.getType()==ARRAY){
			writer.write("[]=" +"\t" + arg + "\t" + result + "\t" + t.getName());
			writer.newLine();
			
		}else{
			writer.write('=' + "\t" + arg+"\t\t"+ t.getName());
			writer.newLine();
		}
		
		//End of the line. check for a ;
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)';'){
			i++;
		}
		else{
			System.out.println("Error: Missing a ;");
			System.exit(0);
		}
	}
	
	public static void operation(BufferedWriter writer)throws IOException{
		String op="";
		Token tem=null;
		if(tokenList[i].getType()==RES && tokenList[i].getValue()==4){
			op="cout";
			i++;
			if(tokenList[i].getType()!=OPER && tokenList[i].getValue()!=LT){
				System.out.println("Error");
			}
			else{//found <<
				i++;
			}
		}
		else if(tokenList[i].getType()==RES && tokenList[i].getValue()==3){
			op="cin";
			i++;
			if(tokenList[i].getType()!=OPER && tokenList[i].getValue()!=GT){
				System.out.println("Error");
			}
			else{//found >>
				i++;
			}
		}
		while(tokenList[i]!=null){
			if((tokenList[i].getType()==INT || tokenList[i].getType()==INC && tokenList[i].getType()==INV) && 
					(tokenList[i+2].getType()==INT|| tokenList[i+2].getType()==INC || tokenList[i+2].getType()==INV)){
				String arg=exp(writer);
				tem=findInTable(tokenList[i+1].getType(),tokenList[i+1].getValue());
				writer.write(op+"\t"+arg);
				writer.newLine();
				i--;
			}
			else if(tokenList[i].getType()==INT){
				writer.write(op+"\t"+tokenList[i].getValue());
				writer.newLine();
			}
			else if(tokenList[i].getType()==RES && tokenList[i].getValue()==10){
				writer.write(op+"\t"+"'/n'");
				writer.newLine();
			}
			else{
				tem=findInTable(tokenList[i].getType(),tokenList[i].getValue());
				
				if(tem.getType()==ARRAY){
					String index="";
					String aResult="";
					String newResult="";
					if(tokenList[i+1].getType()==PUN && tokenList[i+1].getValue()==(int)'['){
						i+=2;
						index=exp(writer);
					}
					else{
						System.out.println("Error, Missing [");
						System.exit(0);
					}
					if(tokenList[i].getType()!=PUN && tokenList[i].getValue()!=(int)']'){
						System.out.println("Error Missing ]");
						System.exit(0);
					}
					aResult=newTemp();
					newResult=newTemp();
					writer.write("="+ "\t"+ index + "\t\t" + aResult);
					writer.newLine();
					writer.write("=[]"+ "\t"+ tem.getName() + "\t" + aResult+ "\t"+newResult);
					writer.newLine();
					writer.write(op+ "\t"+ newResult);
					writer.newLine();
				}
				else{
					if(tem.getType()!=INT && tem.getType()!=INC && tem.getType()!=INV){
						writer.write(op+"\t"+'"' +tem.getName()+'"');
						writer.newLine();
					}
					else{
					writer.write(op+"\t"+tem.getName());
					writer.newLine();
					}
				}
			}
			if(tokenList[i+1].getValue()==(int)';'){
				i+=2;
				break;
			}
			else{
				if(op=="cout"){
					if (tokenList[i+1].getType()==OPER && tokenList[i+1].getValue()==LT){
						i+=2;
					}
					else{
						System.out.println("Error: missing a <<");
						System.exit(0);
					}
				}
				else if(op=="cin"){
					if (tokenList[i+1].getType()==OPER && tokenList[i+1].getValue()==GT){
						i+=2;
					}
					else{
						System.out.println("Error: missing a >>");
						System.exit(0);
					}
				}
			}
			
		}
	}
	
	public static void code(BufferedWriter writer)throws IOException{//TODO
		//goes through tokens for one line of code in if else or while loops
		int j=0;
		while(tokenList[i]!=null&j<1){
				if(tokenList[i].getType()==RES){
					if((tokenList[i].getValue()==3) || (tokenList[i].getValue()==4)){
						//method for operations such as cout and cin
						operation(writer);
					}
					else if(tokenList[i].getValue()==26){
						whilee(writer);
					}
					else if(tokenList[i].getValue()==13){
						ifelse(writer);
					}
					else if(tokenList[i].getValue()==9){
						System.out.println("Error: else without an if");
					}
				}
				Token p=findInTable(tokenList[i].getType(),tokenList[i].getValue());
				if(p!=null){//method for assignment statements
					assignment(writer);
				}
				j++;
				
		}
	}
	
	public static void whilee(BufferedWriter writer)throws IOException{
		String begin=newLTemp();
		String f=newLTemp();
		i++;
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'('){
			i++;
		}
		else{
			System.out.println("Error: Missing a (");
		}
		writer.write(begin);
		writer.newLine();
		String bool= or(writer);
		writer.write("=="+ "\t"+ bool+"\t"+0+"\t"+"goto"+"\t"+f);
		writer.newLine();
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)')'){
			i++;
		}
		else{
			System.out.println("while");
			System.out.println("Error Missing )");
			System.exit(0);
		}
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'{'){
			i++;
			while(tokenList[i]!=null){
				code(writer);
				if(tokenList[i].getType()==PUN){
					if(tokenList[i].getValue()==(int)'}'){
						i++;
						break;
					}
					else{
						i++;
					}
				}
				else{
					if(tokenList[i+1]==null){
						System.out.println("Error");
					}
				}
			}
		}
		else{
			code(writer);
		}
		writer.write("goto"+"\t"+begin);
		writer.newLine();
		writer.write(f);
		writer.newLine();
	}
	
	public static void ifelse(BufferedWriter writer)throws IOException{
		String e;
		String end;
		i++;
		e=newLTemp();
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'('){
			i++;
			//System.out.println("Found (");
		}
		else{
			System.out.println("Error Missing (");
			System.exit(0);
		}
		String bool=or(writer);
		end=newLTemp();
		writer.write("=="+ "\t"+bool+"\t"+"0"+"\t"+"goto"+"\t"+ e);
		writer.newLine();
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)')'){
			i++;
		}
		else{
			System.out.println("if else");
			System.out.println("Error Missing )");
			System.exit(0);
		}
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'{'){
			i++;
			while(tokenList[i]!=null){
				code(writer);
				if(tokenList[i].getType()==PUN){
					if(tokenList[i].getValue()==(int)'}'){
						i++;
						break;
					}
					else{
						i++;
					}
				}
				else{
					if(tokenList[i+1]==null){
						System.out.println("Error");
					}
				}
			}
		}
		else{
			code(writer);
		}
		
		writer.write("goto"+"\t"+ end);
		writer.newLine();
		writer.write(e);
		writer.newLine();
		if(tokenList[i].getType()==RES && tokenList[i].getValue()==9){
			i++;
			elseE(writer);
		}
		writer.write(end);
		writer.newLine();
	}
	
	public static void elseE(BufferedWriter writer)throws IOException{
			//System.out.println("Found else");
			if(tokenList[i].getType()==RES && tokenList[i].getValue()==13){
				ifelse(writer);
			}
			else if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'{'){
				i++;
				while(tokenList[i]!=null){
					code(writer);
					if(tokenList[i].getType()==PUN){
						if(tokenList[i].getValue()==(int)'}'){
							//System.out.println(tokenList[i]);
							i++;
							return;
						}
						else{
							i++;
						}
					}
					else{
						if(tokenList[i+1]==null){
							System.out.println("Error");
						}

					}
				}
			}
			else{
				code(writer);
			}
		}
	
	
	public static String or(BufferedWriter writer)throws IOException{//TODO
		String arg1=and(writer);
		String arg2="";
		String result="";
		while(tokenList[i].getType()==OPER && tokenList[i].getValue()==OR){
			i++;
			arg2=and(writer);
			result=newTemp();
			writer.write("|"+"\t"+arg1+"\t"+arg2+"\t"+result);
			arg1=result;
			writer.newLine();
		}
		if(result==""){
			return arg1;
		}else{
			return result;
		}
	}
	
	public static String and(BufferedWriter writer)throws IOException{//TODO
		String arg1=not(writer);
		String arg2="";
		String result="";
		while(tokenList[i].getType()==OPER && tokenList[i].getValue()==AND){
			i++;
			arg2=not(writer);
			result=newTemp();
			writer.write('&'+"\t"+arg1+"\t"+arg2+"\t"+result);
			arg1=result;
			writer.newLine();
		}
		if(result==""){
			return arg1;
		}else{
			return result;
		}
	}
	
	public static String not(BufferedWriter writer)throws IOException{//TODO
		String arg1="";
		String result="";
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'!'){
			i++;
			if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'('){
				//negating a boolean expression
				i++;
				arg1=or(writer);
				result=newTemp();
				if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)')'){
					i++;
				}
				else{
					System.out.println("Error: Missing a )");
				}
				writer.write("^"+"\t"+arg1+"\t"+"1"+"\t"+result);
				writer.newLine();
				return result;
			}
			else{
				System.out.println("Error: Missing a (");
				System.exit(0);
			}
		}else{
			arg1=rel(writer);
		}
		return arg1;
	}
	
	public static String rel(BufferedWriter writer)throws IOException{//TODO
		String arg2="";
		String op="";
		String bool="";
		String resultTrue="";
		String resultFalse="";
		
		String arg1=exp(writer);
		while(tokenList[i].getType()==OPER && (tokenList[i].getValue()==LE || tokenList[i].getValue()==GE || tokenList[i].getValue()==(int)'>')
				|| tokenList[i].getValue()==(int)'<' || tokenList[i].getValue()==EQEQ || tokenList[i].getValue()==NE){
			if(tokenList[i].getType()==OPER){
				if(tokenList[i].getValue()==LE){
					op="<=";
				}
				else if(tokenList[i].getValue()==GE){
					op=">=";
				}
				else if(tokenList[i].getValue()==(int)'>'){
					op=">";
				}
				else if(tokenList[i].getValue()==(int)'<'){
					op="<";
				}
				else if(tokenList[i].getValue()==EQEQ){
					op="==";
				}
				else if(tokenList[i].getValue()==NE){
					op="!=";
				}
			}
			else{
				System.out.println("Error: Expecting a boolean operator");
				System.exit(0);
			}
			i++;
			arg2=exp(writer);
			resultTrue=newLTemp();
			resultFalse=newLTemp();
			bool=newTemp();
			writer.write(op+"\t"+arg1+"\t"+arg2+"\t"+"goto"+"\t"+resultTrue);
			writer.newLine();
			writer.write("="+"\t"+"0"+"\t\t"+bool);
			writer.newLine();
			writer.write("goto"+"\t"+resultFalse);
			writer.newLine();
			writer.write(resultTrue);
			writer.newLine();
			writer.write("="+"\t"+"1"+"\t\t"+bool);
			writer.newLine();
			writer.write(resultFalse);
			writer.newLine();
		}
		return bool;
	}
	
	public static String exp(BufferedWriter writer)throws IOException{// TODO
		String op="";
		String arg1=term(writer);
		String result="";
		
		while((tokenList[i].getType()==OPER && tokenList[i].getValue()==(int)'+') || 
				(tokenList[i].getType()==OPER && tokenList[i].getValue()==(int)'-')){
				if(tokenList[i].getValue()==(int)'+'){
					op="+";
				}
				else if(tokenList[i].getValue()==(int)'-'){
					op="-";
				}
				i++;
				String arg2=term(writer);
				result=newTemp();
				writer.write(op + "\t" + arg1 + '\t' + arg2 +'\t'+result);
				writer.newLine();
				arg1=result;
			}
		if(result==""){
			return arg1;
		}else{
			return result;
		}
		
	}
	
	public static String term(BufferedWriter writer)throws IOException{
		String arg1=factor(writer);
		String result="";
		String op="";
			
		while((tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'*') || 
				(tokenList[i].getType()==OPER && tokenList[i].getValue()==(int)'/') ||
				(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'%')){
				if(tokenList[i].getValue()==(int)'*'){
					op="*";
				}
				else if(tokenList[i].getValue()==(int)'/'){
					op="/";
				}
				else if(tokenList[i].getValue()==(int)'%'){
					op="%";
				}
				i++;
				
				String arg2=factor(writer);
				result =newTemp();
				writer.write(op+ "\t" + arg1 + '\t' + arg2 +'\t'+result);
				writer.newLine();
				arg1=result;
			}
		if(result==""){
			return arg1;
		}else{
			return result;
		}
	}
	
	public static String factor(BufferedWriter writer)throws IOException{
		Token t;
		boolean neg=false;
		if(tokenList[i].getType()==OPER && tokenList[i].getValue()==(int)'-'){
			i++;
			neg=true;
		}
		if(tokenList[i].getType()==INT){
			String in=Integer.toString(tokenList[i].getValue());
			i++;
			if(neg){//write to output for changing to a negative value
				String result=newTemp();
				writer.write('-'+ "\t"+ in+"\t\t"+result);
				writer.newLine();
				return result;
			}
			else
				return in;
		}
		else if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'('){
			i++;
			String arr=exp(writer);
			if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)')'){
				i++;
			}
			else{
				System.out.println("Error: Missing a )");
				System.exit(0);
			}
			
			if(neg){
				String result=newTemp();
				writer.write('-'+ "\t"+ arr+"\t\t"+result);
				writer.newLine();
				return result;
			}
			return arr;
		}
		else if((t=findInTable(tokenList[i].getType(),tokenList[i].getValue()))!=null){
			if(t.getType()==ARRAY){
				String index="";
				String result="";
				String newResult="";
				if(tokenList[i+1].getType()==PUN && tokenList[i+1].getValue()=='['){
					i+=2;
					index=exp(writer);
				}
				else{
					System.out.println("Error, Missing [");
					System.exit(0);
				}
				if(tokenList[i].getType()!=PUN && tokenList[i].getValue()!=']'){
					System.out.println("Error Missing ]");
					System.exit(0);
				}
				i++;
				
				result=newTemp();
				newResult=newTemp();
				if(neg){//write to output for changing to a negative value
					String arresult=newTemp();
					writer.write('-'+ "\t"+ t.getName() + "\t\t" + arresult);
					writer.newLine();
					return arresult;
				}
				writer.write("="+ "\t"+ index + "\t\t" + result);
				writer.newLine();
				writer.write("=[]"+ "\t"+ t.getName() + "\t" + result+ "\t"+newResult);
				writer.newLine();
				return newResult;
			}
			i++;
			if(neg){//write to output for changing to a negative value
				//System.out.println("Factor");
				String result=newTemp();
				writer.write('-'+ "\t"+ t.getName() + "\t\t" + result);
				writer.newLine();
				return result;
			}
			if(t.getType()==INC){
				return Integer.toString(t.getValue());
			}
			else{
			return t.getName();
			}
		}
		else{
			System.out.println("Error: Unexpected Character");
			System.exit(0);
			return null;
		}
	}
	
	public static String varType(){
		if(tokenList[i].getType()==RES && tokenList[i].getValue()==1){
			return "char";
		}
		else if(tokenList[i].getType()==RES && tokenList[i].getValue()==15){
			return "int";
		}else{
			System.out.print("Error: unknown variable declarator");
			System.exit(0);
			return null;
		}
	}
	
	public static int findValue(String varType){//find the value of a variable
		if(varType=="int"){//check for a number
		if(tokenList[i].getType()==INT){
			return tokenList[i].getValue();
		}
		else if(tokenList[i].getType()<=25){
			Token t=findInTable(tokenList[i].getType(),tokenList[i].getValue());
			if(t==null){
				System.out.println("Error expecting variable or a " + varType);
				System.exit(0);
				
			}
			if(findVar(t)){
				if(t.getName().length()==1){
					System.out.println("Error cannot convert from character to int");
					System.exit(0);
				}
				else{
					return t.getValue();
				}
			}
			else{
				System.out.println("Error variable not declared");
				System.exit(0);
			}
		}
		
		}
		else{//check for a character
			Token t=findInTable(tokenList[i].getType(),tokenList[i].getValue());
			if(t.getName().length()>1){
			if(!(t.getValue()>=65 && t.getValue()<=122)){
					System.out.println("Error, expecting a character");
					System.exit(0);
				}else{
					return t.getValue();
				}
			}
			else{
				int name=AsciCode(t.getName().charAt(0));
				return name;
			}
		}
		return 0;
		}
	
	
	public static int parse(String tokens, String stinput, String stoutput,String output) throws IOException{
		BufferedReader t=null;
		BufferedReader st=null;
		BufferedWriter stw=null;
		BufferedWriter out=null;
		String token;
		String spliter[];
		String x;
		for(int j=0; j<tableIndex.length; j++){//sets up the symbol table to be filled up
			tableIndex[j]=0;
		}
		for(int j=0; j<asciCode.length; j++){//sets up the symbol table to be filled up
			asciCode[j]=65+j;
		}
		i=0;
		try{
			//following destinations may be changed as needed
			t=new BufferedReader(new FileReader(tokens));
			st=new BufferedReader(new FileReader(stinput));
            while ((token = t.readLine()) != null) {//read in from file into an arraylist
            	spliter=token.split("\t");
        		tokenList[i]=new Token(" ",Integer.valueOf(spliter[0]),Integer.valueOf(spliter[1]));
            	i++;
            }
            
            while((x=st.readLine())!=null){
            	tables.add(x);
            }
            	for(int j=0; j<tables.size(); j++){
            		//System.out.println(tables.get(j));
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
			if(t!=null){
				t.close();
			}
			if(st!=null){
				st.close();
			}
		}
		
		i=0;
		try{
			out=new BufferedWriter(new FileWriter(output));
			
			while(tokenList[i]!=null){
				includeStatments();//found down below
				while((tokenList[i].getType()==RES && (tokenList[i].getValue()==5 || tokenList[i].getValue()==15 
						||tokenList[i].getValue()==1))){
					if(tokenList[i+1].getType()==RES && tokenList[i+1].getValue()==18){
						break;
					}
					if(tokenList[i].getType()==RES&&tokenList[i].getValue()==5){
						constDeclaration();
					}else{
						declaration();
					}
				}
				checkMain();//found down below
				while (tokenList[i].getValue()!=24){// TODO
					if(tokenList[i].getType()==RES){
						if((tokenList[i].getValue()==3) || (tokenList[i].getValue()==4)){
							//method for operations such as cout and cin
							operation(out);
						}
						else if(tokenList[i].getValue()==26){
							whilee(out);
							resetTemp();
						}
						else if(tokenList[i].getValue()==13){
							ifelse(out);
							resetTemp();
						}
						else if(tokenList[i].getValue()==9){
							System.out.println("Error: else without an if");
						}
					}
					Token p=findInTable(tokenList[i].getType(),tokenList[i].getValue());
					if(p!=null){//method for assignment statements
						assignment(out);
						resetTemp();
					}
				}
				
				checkReturn();//found down below
				break;
			}
		}
		finally{
			if(out!=null){
				out.close();
			}
		}
		
		try{
			stw = new BufferedWriter(new FileWriter(stoutput));
        	for(int j=0; j<25; j++){
        		if(Symboltable[j][0]!=null){
        			stw.write(j+":");
        			stw.newLine();
        			for(int k=0; k<25;k++){
        				if(Symboltable[j][k]!=null){
        					stw.write(Symboltable[j][k].getName()+"\t" + Symboltable[j][k].getType()+"\t"+ 
        							Symboltable[j][k].getValue()+"\t"+Symboltable[j][k].getSize()+"\t"+
        							Symboltable[j][k].getEltype());
        					stw.newLine();
        				}
        			}
        		}
        	}
		}
		finally{
			if(stw!=null){
				stw.close();
			}
		}
		System.out.println("Done Parsing");
		int tokenSize=0;// this code 
		for(int j=0; j<tokenList.length; j++){//for keeping track of number of tokens
			if(tokenList[j]!=null){
				tokenSize++;
			}
			else{
				break;
			}
		}
		System.out.println("tokenList.size = " +tokenSize+ " of " + tokenList.length);
		return maxTemps;
	}
	
	public static void includeStatments(){
		while(tokenList[i]!=null){
		if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'#'){
			i++;
			if(tokenList[i].getType()==RES && tokenList[i].getValue()==12){
				i++;
				if(tokenList[i].getType()==OPER && tokenList[i].getValue()==(int)'<'){
					i++;
					if(tokenList[i].getType()==RES && tokenList[i].getValue()==14){
						i++;
						if(tokenList[i].getType()==OPER && tokenList[i].getValue()==(int)'>'){
							i++;
							break;
						}else{
							System.out.println("Error: > is expected");
							System.exit(0);
						}
					}else{
						System.out.println("Error: unknown library name");
						System.exit(0);
					}
				}else{
					System.out.println("Error: < is exppected");
					System.exit(0);
				}
			}else{
				System.out.println("Error");
				System.exit(0);
			}
		}else{
			System.out.println("Error: # is expected");
			System.exit(0);
		}
		}
		while(tokenList[i]!=null){
			if(tokenList[i].getType()==RES && tokenList[i].getValue()==23){
				i++;
				if(tokenList[i].getType()==RES && tokenList[i].getValue()==20){
					i++;
					if(tokenList[i].getType()==RES && tokenList[i].getValue()==21){
						i++;
						if(tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)';'){
							i++;
							break;
						}else{
							System.out.println("Error missing ;");
							System.exit(0);
						}
					}else{
						System.out.println("Error missing name of namespace");
						System.exit(0);
					}
				}else{
					System.out.println("Error unknown operator");
					System.exit(0);
				}
			}else{
				System.out.println("Error missing operator expecting 'using'");
				System.exit(0);
			}
		}
	}
	
	public static void checkMain(){
		while(tokenList[i]!=null){
			if (tokenList[i].getType()==RES && tokenList[i].getValue()==15){
				i++;
				if (tokenList[i].getType()==RES && tokenList[i].getValue()==18){
					i++;
					if (tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'('){
						i++;
						if (tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)')'){
							i++;
							if (tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'{'){
								i++;
								break;
							}else{
								System.out.println("Error: Missing {");
								System.exit(0);
							}
						}else{
							System.out.println("Error: Missing )");
							System.exit(0);
						}
					}else{
						System.out.println("Error: Missing (");
						System.exit(0);
					}
				}else{
					System.out.println("Error: expecting main");
					System.exit(0);
				}
			
			}else{
				System.out.println("Error: expecting int");
				System.exit(0);
			}
		}
	}
	
	public static void checkReturn(){
		while(tokenList[i]!=null){
			if (tokenList[i].getType()==RES && tokenList[i].getValue()==24){
				i++;
				if (tokenList[i].getType()==INT && tokenList[i].getValue()==0){
					i++;
					if (tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)';'){
						i++;
						if (tokenList[i].getType()==PUN && tokenList[i].getValue()==(int)'}'){
							break;
						}else{
							System.out.println("Error: Missing }");
							System.exit(0);
						}
					}else{
						System.out.println("Error: Missing ;");
						System.exit(0);
					}
				}else{
					System.out.println("Error: Missing return value");
					System.exit(0);
				}
			}else{
				System.out.println("Error: Missing return statement");
				System.exit(0);
			}
		}
	}
	
}