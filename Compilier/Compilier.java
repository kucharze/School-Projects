import java.io.IOException;

public class Compilier {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		//the files in this section may be changed as needed
		Lexicalanalyser.read("C:\\Users\\Zacha\\Desktop\\Code 4.txt","C:\\Users\\Zacha\\Desktop\\Tokens.txt",
				"C:\\Users\\Zacha\\Desktop\\SymbolTable.txt");
		
		int max=Parser.parse("C:\\Users\\Zacha\\Desktop\\Tokens.txt","C:\\Users\\Zacha\\Desktop\\SymbolTable.txt",
				"C:\\Users\\Zacha\\Desktop\\ParserSymbolTable.txt","C:\\Users\\Zacha\\Desktop\\ParserOutput.txt");
		
		Codegenerator.generate("C:\\Users\\Zacha\\Desktop\\ParserOutput.txt","C:\\Users\\Zacha\\Desktop\\ParserSymbolTable.txt",
				"C:\\Users\\Zacha\\Desktop\\CodegenOutput.cpp",max);
		
		System.out.println("All Steps done, the Program is good to go" );
	}

}