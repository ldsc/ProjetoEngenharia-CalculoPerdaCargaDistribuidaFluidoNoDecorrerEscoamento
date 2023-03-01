#include <cstdlib> 
#include <string>  
#include <map>
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include "CConversaoUnidades.h"
#include "CTubo.h"
#include "CFluido.h"
#include "CSimuladorPerdaCargaDistribuida.h"
#include "CGnuplot.h"

using namespace std;


int main() {
	//CCalculoEscoamento calculografico;
	CSimuladorPerdaCargaDistribuida simulador;
	char resposta = 's';
	do {
		simulador.Simular();
		cout << "Deseja continuar? (s/n)\n";
		cin >> resposta;
		cout << "\n";
	} while (resposta == 's' or resposta == 'S');
	//calculografico.Plotar();
	return 0;
}
