#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<ctype.h>
#include "LectorNumero.h"

using namespace std;

//función que verifica si un caracter es un numero
bool esDigito(char d){
	if(d>='0'&&d<='9'){
		return true;
	}
	return false;
}

//función que verifica si un caracter es una letra
bool esLetra(char l){
	if((l>='A'&&l<='Z')||l>='a'&&l<='z'||l=='_'){
		return true;
	}
	return false;
}

//función que verifica si un string es un int
bool esInt(string i){
	for(char d: i){
		if(esDigito(d)==false){
			return false;
		}
	}
	return true;
}

//función que verifica si un string es un float
bool esFloat(string f){
	LectorNumero lector;
	return lector.isFloat(f);
}

//función que verifica si una string es un ID
bool esId(const string &id) {
    if (id.empty() || !esLetra(id[0])) return false;
    for (size_t i = 1; i < id.size(); i++) {
        if (!esDigito(id[i]) && !esLetra(id[i])) return false;
    }
    return true;
}

//funcion que lee el documento escrito en C
string lectorDocumento(){
	ifstream archivo("Documento.txt");
	ostringstream buffer;
	buffer<< archivo.rdbuf();
	return buffer.str();
}

//función que segun un string retorna el nombre del token (Automata)
string nombreToken(string t){
	if (t == "auto") return "AUTO";
	else if (t == "using") return "USING";
	else if (t == "namespace") return "NAMESPACE";
    else if (t == "double") return "DOUBLE";
    else if (t == "main") return "MAIN";
    else if (t == "int") return "INT";
    else if (t == "struct") return "STRUCT";
    else if (t == "break") return "BREAK";
    else if (t == "else") return "ELSE";
    else if (t == "long") return "LONG";			
    else if (t == "switch") return "SWITCH";
    else if (t == "case") return "CASE";
    else if (t == "enum") return "ENUM";
    else if (t == "register") return "REGISTER";
    else if (t == "typedef") return "TYPEDEF";
    else if (t == "char") return "CHAR";
    else if (t == "extern") return "EXTERN";
    else if (t == "return") return "RETURN";
    else if (t == "union") return "UNION";
    else if (t == "const") return "CONST";
    else if (t == "float") return "FLOAT";
    else if (t == "short") return "SHORT";
    else if (t == "unsigned") return "UNSIGNED";
    else if (t == "continue") return "CONTINUE";
    else if (t == "for") return "FOR";
    else if (t == "signed") return "SIGNED";
    else if (t == "void") return "VOID";
    else if (t == "default") return "DEFAULT";
    else if (t == "goto") return "GOTO";
    else if (t == "sizeof") return "SIZEOF";
    else if (t == "volatile") return "VOLATILE";
    else if (t == "do") return "DO";
    else if (t == "if") return "IF";
    else if (t == "static") return "STATIC";
    else if (t == "while") return "WHILE";
    else if (t == "#define") return "DEFINE";
    else if (t == "#elif") return "ELIF";
    else if (t == "#else") return "#ELSE";
    else if (t == "#endif") return "ENDIF";
    else if (t == "#error") return "ERROR";
    else if (t == "#if") return "#IF";
    else if (t == "#ifdef") return "IFDEF";
    else if (t == "#ifndef") return "IFNDEF";
    else if (t == "#include") return "INCLUDE";
    else if (t == "#message") return "MESSAGE";
    else if (t == "#undef") return "UNDEF";
    else if (t == "{") return "LBRACE";
    else if (t == "}") return "RBRACE";
    else if (t == "[") return "LSQUARE";
    else if (t == "]") return "RSQUARE";
    else if (t == "(") return "LPAR";
    else if (t == ")") return "RPAR";
    else if (t == ";") return "SEMI";
    else if (t == "+") return "PLUS";
    else if (t == "-") return "MINUS";
    else if (t == "*") return "MUL_OP";
    else if (t == "/") return "DIV_OP";
    else if (t == "&") return "AND_OP";
    else if (t == "|") return "OR_OP";
    else if (t == "!") return "NOT_OP";
    else if (t == "=") return "ASSIGN";
    else if (t == "<") return "LT";
    else if (t == ">") return "GT";
    else if (t == "<<") return "SHL_OP";	
    else if (t == ">>") return "SHR_OP";
    else if (t == "==") return "EQ";
    else if (t == "!=") return "NOTEQ";
    else if (t == "<=") return "LTEQ";
    else if (t == ">=") return "GTEQ";
    else if (t == "&&") return "ANDAND";
    else if (t == "||") return "OROR";
    else if (t == ",") return "COMMA";
    else if (t == ".") return "DOT";
    else if (t == "->") return "ARROW";
    else if (t[0] == '"' && t[t.size()-1]=='"') return "STRING";
    else if (t == "\n" || t == "\r" || t == "\t") return "ESCAPECHAR";
    else if (esInt(t)) return "INT_NUM";
    else if (esFloat(t)) return "FLOAT_NUM";
    else if (esId(t)) return "ID";
    else if (t == ":") return "DOTS";
    else if (t == "'") return "QUOTER";
    return "NOTOKEN";
}

//función que crea un mensaje con respecto al nombre del token
string mensaje(string t){
	string token = nombreToken(t);
	if(t=="\n" || t=="\\n") return "Token: "+token+" "+string(1,'"')+"\\n"+string(1,'"');
	if(t=="\r" || t=="\\r") return "Token: "+token+" "+string(1,'"')+"\\r"+string(1,'"');
	if(t=="\t" || t=="\\t") return "Token: "+token+" "+string(1,'"')+"\\t"+string(1,'"');
	if(token!="NOTOKEN"){
		return "Token: "+token+" "+string(1,'"')+t+string(1,'"');
	}
	return "ERROR: "+t;
}

//función para delimitar la toma de los string(Tokens)
bool esDelimitador(char c) {
    return isspace(c) || c == ';' || c == ',' || c == '(' || c == ')' ||
           c == '{' || c == '}' || c == '[' || c == ']' || c == '=' ||
           c == '+' || c == '-' || c == '*' || c == '/' || c == '<' ||
           c == '>' || c == '&' || c == '|' || c == '!' || c== ':' ||
		   c == '.' || c == '\'' ;
}

//función principal, donde se encuentra toda la logica de seperacion de los token
int main(){
	string documento = lectorDocumento();
	string token;
	char c;
	for(int i=0; i<documento.size();i++){
		c=documento[i];
		if(c=='"'){
			token+=c;
			c=documento[++i];
			while(c!='"'){
				token+=c;
				c=documento[++i];
			}
			token+=c;
			cout<<mensaje(token)<<endl;
			token="";
		}else{
			if(esDelimitador(c)){
				if(c=='<'||c=='>'||c=='!'||c=='='){
					if(documento[i+1]=='='){
						if(token!=""){
							cout<<mensaje(token)<<endl;
							token="";
						}
						cout<<mensaje(string(1,c)+string(1,documento[i+1]))<<endl;
						c=' ';
						i++;
					}
				}
				if(c=='<'){
					if(documento[i+1]=='<'){
						if(token!=""){
							cout<<mensaje(token)<<endl;
							token="";
						}
						cout<<mensaje(string(1,c)+string(1,documento[i+1]))<<endl;
						c=' ';
						i++;
					}
				}
				if(c=='>'){
					if(documento[i+1]=='>'){
						if(token!=""){
							cout<<mensaje(token)<<endl;
							token="";
						}
						cout<<mensaje(string(1,c)+string(1,documento[i+1]))<<endl;
						c=' ';
						i++;
					}
				}
				if(token.size()>0){
					cout << mensaje(token) << endl;
					token="";
				}
				if(c!=' '){
					cout << mensaje(string(1,c)) << endl;
				}
			}else{
				token+=c;
			}
		}	
	}
	if(token.size()>0){
		cout << mensaje(token) << endl;
	}
	return 0;
}