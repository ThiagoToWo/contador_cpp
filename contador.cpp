#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void reduce(string&);

int main() {
	ifstream in; // o leitor arquivo
	string file_name; // o nome do arquivo
	string s; // a palavra
	const int SIZE_P = 74091; // quantidade máxima de palavras
	const int SIZE_L = 91; // quantidade máxima de letras
	string palavras[SIZE_P]; // armazena as palavras
	int num_linha = 0; // conta as linhas
	int num_palavra = 0; // conta as palavras
	int n = 0; // comprimento atual do array de palavras
	int freq_p[SIZE_P] = {0}; // armazena as frequências das palavras
	int freq_l[SIZE_L] = {0}; // armazena as frequências das letras
	int i; // índice corrente das palavras
	int cmp; // comprimento das palavras
	char cb; // caractereem branco
	char c; // a letra da palavra
	
	cout << "Insira o nome do arquivo de texto: ";
	getline(cin, file_name);
	in.open(file_name);
	
	while (in >> s) {
		reduce(s); // tira os símbolos não literais	
		
		cmp = s.length();
		if (cmp == 0) continue;	// lê a próxima se não sobrou palavra	
		
		num_palavra++; // caso contário conte a palavra
		
		in.get(cb); // pegue o caractere em branco		
		if (cb == '\n') { // se for quebra de linha
			num_linha++; // conte a linha
		}
		
		for (i = 0; i < n; i++) { // verifica se a palavra já exixte
			if (palavras[i] == s) break; // e sai com o índice i dela
		}
		
		if (i == n) { // se a palavra não existir 
			palavras[n++] = s; // acrescenta ela no fim do array e incrementa n
		}
		
		freq_p[i]++; // conta a palavra de índice i;
		
		for (int i = 0; i < cmp; i++) { // percorre a última palavra acrescentada
			c = palavras[n - 1][i]; 
			if (c >= 'a' && c <= 'z') c += 'A' - 'a'; // coloca em maiúscula;
			freq_l[c]++; // conta a letra
		}
	}
	
	cout << "A entrada possui " << num_linha << " linhas, " << num_palavra << " palavras \n"
		 << "e as seguintes frequências de letras e palavras:\n";
	
	for (int i = 65; i < SIZE_L; i++) {
		cout << '\t' << char(i) << ": " << freq_l[i];
		if (i > 0 && i % 8 == 0) cout << endl;
	}
	
	cout << endl;
	
	for (int i = 0; i < n; i++) {
		if (i > 0 && i % 3 == 0) cout << endl;
		cout << setw(20) << setiosflags(ios::right) << palavras[i].c_str() 
			 << ": " << setw(2) << freq_p[i];		
	}
	
	cout << endl;
	
	system("pause");
}