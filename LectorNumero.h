#ifndef _LECTORNUMERO
#define _LECTORNUMERO
#include<iostream>
#include<vector>
#include<cctype>
class LectorNumero{
	private:
		std::vector<std::vector<int>> tabla;
	public:
		LectorNumero(){
			tabla = std::vector<std::vector<int>>(7,std::vector<int>(4,1));
			tabla[0][0] = 1;
       		tabla[0][1] = 4;
        	tabla[0][2] = 6;
        	tabla[0][3] = -1;
        	tabla[1][0] = 1;
        	tabla[1][1] = -1;
        	tabla[1][2] = 2;
        	tabla[1][3] = 5;
	        tabla[2][0] = 2;
	        tabla[2][1] = -1;
	        tabla[2][2] = -1;
	        tabla[2][3] = 5;
	        tabla[3][0] = 3;
	        tabla[3][1] = -1;
	        tabla[3][2] = 3;
	        tabla[3][3] = -1;
	        tabla[4][0] = 1;
	        tabla[4][1] = -1;
	        tabla[4][2] = 6;
	        tabla[4][3] = -1;
	        tabla[5][0] = 3;
	        tabla[5][1] = 3;
	        tabla[5][2] = -1;
	        tabla[5][3] = -1;
	        tabla[6][0] = 2;
	        tabla[6][1] = -1;
	        tabla[6][2] = -1;
	        tabla[6][3] = -1;
		}
	int simbolo(char a) {
        if (isdigit(a)) return 0;  
        switch (a) {
            case '+':
            case '-':
                return 1;
            case 'E':
                return 3;
            case '.':
                return 2;
            default:
                return -1;
        }
    }

    std::vector<int> parseToInt(const std::string &s) {
        std::vector<int> numeros(s.length());
        for (size_t i = 0; i < s.length(); i++) {
            numeros[i] = simbolo(s[i]);
        }
        return numeros;
    }

    bool isFloat(const std::string &s) {
        std::vector<int> numeros = parseToInt(s);
        int i = 0;
        for (size_t j = 0; j < numeros.size(); j++) {
            if (numeros[j] < 0) return false;
            if (tabla[i][numeros[j]] < 0) return false;
            i = tabla[i][numeros[j]];
        }
        return true;
    }
};
#endif