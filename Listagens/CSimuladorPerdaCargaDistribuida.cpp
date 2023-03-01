#include "CSimuladorPerdaCargaDistribuida.h"

using namespace std;

void CSimuladorPerdaCargaDistribuida::Simular()
{
	CalcVazao();							
	CalcRe();
	Calcf();
	CalcHfQ();
	Plotar();
}

//Calculo a vazao
double CSimuladorPerdaCargaDistribuida::CalcVazao()
{
	vazao=tubo->AreaTubo()*fluido->VelocidadeFluido();
	return vazao;
}

//Calculo numero de Reynold 
double CSimuladorPerdaCargaDistribuida::CalcRe()
{
	re = ((tubo->DiametroHidraulico()* fluido->VelocidadeFluido())/ fluido->ViscosidadeCinematica());	
	return re;
}
  
//Calculo fator de atrito 
double CSimuladorPerdaCargaDistribuida::Calcf()
{	 
		std::cout<< "\nReynold vale: " << CalcRe() <<std::endl;
		
		if(re<=2000)
  {
		f= 64/re;
  }

	if(re>2000 && re<3000)
	{
		std::cout<<"\nNao e possivel calcular o fator de atrito (f), pois esta na regiao de transicao. Aproximando para Reynolds < 2000 temos:\n";
			f= 64/re;
		std::cout<<"\nO valor do fator de atrito e:  "<<f<<std::endl;
			return f;
	}
	
	if(re>=3000 && re<4000)
	{
		std::cout<<"\nNao e possivel calcular o fator de atrito (f), pois esta na regiao de transicao.  Aproximando para Reynolds >3000 temos:\n";
			f= pow((1/((0.86 * (log (re) + log (sqrt(f))))- 0.8)),(1/((0.86 * (log (re) + log (sqrt(f))))- 0.8)));
		std::cout<<"\nO valor do fator de atrito e:  "<<f<<std::endl;
			return f;
	}
  
  if( re>=4000) 
  {
  std::cout<<"\nDado o numero de Reynolds: "<< re << "e a rugosidade relativa: "<< tubo->Rdh() <<" mm, qual e o tipo de escoamento?\nDigite:\n 1-Para escoamento turbulento hidraulicamente liso.\n 2-Para escoamento turbulento, com transicao entre hidraulicamente liso e rugoso.\n 3-Para escoamento completamente turbulento e hidraulicamente rugoso.\nA escolha foi: ";
  int resposta;
  std::cin>>resposta; std::cin.get();
	// Alternativa 1
	if(resposta==1){
		f= pow((1/((0.86 * ((log(re)*2.302585093) + (log (sqrt(f))*2.302585093)))- 0.8)), 2);
	}
    // Alternativa 2
	else if(resposta==2){
		f = pow( (1.0/ ( -0.86* (log ( (tubo->Rdh()/3.7) + (2.51 / (re * sqrt(f)) ) ) *2.302585093))),2);
	}
	// Alternativa 3
	else if(resposta==3){
			f= pow(( 1.0/ ( -0.86 * (log(tubo->Rdh() / 3.7)*2.302585093) ) ), 2 );
	}}

  std::cout<<"\nO valor do fator de atrito e:  "<<f<<std::endl;
  return f;
}
//Calculo Perda de Carga Distribuida 
//Mostra na tela Perda de Carga e Vazao
double CSimuladorPerdaCargaDistribuida::CalcHfQ( )
{
	hf= (f * tubo->L() * pow(fluido->VelocidadeFluido(), 2)) / (tubo->DiametroHidraulico() * 2 * g);
	std::cout<<"\nA perda de carga no decorrer da tubulacao e de:  "<< hf <<" m.\nA vazao do fluxo do fluido e de: "<<vazao<<" m3/s"<<std::endl;
	return hf;
}


void CSimuladorPerdaCargaDistribuida::Plotar()
{
	std::vector<double> fpvct;
	std::vector<double> hfpvct;
	double x;
	for (float fi = 0.008; fi <0.1; fi+=0.0001){
		fpvct.push_back(fi);
		x = (fi * tubo->L() * pow(fluido->VelocidadeFluido(), 2)) / (tubo->DiametroHidraulico() * 2 * g);
		hfpvct.push_back(x);
	}
 
	Gnuplot g2d ("points"); // Construtor
	g2d.Legend("inside").Legend("left").Legend("bottom").Legend("box");
    g2d.Title("Perda de carga Distribuida x Fator de Atrito"); // Titulo do grafico
    g2d.XLabel("Fator de Atrito");    // Rotulo eixo x
    g2d.YLabel("Perda de carga Distribuida");    // Rotulo eixo y
    g2d.PlotVector(fpvct,hfpvct);// Plota vetores
    cout << "Pressione Enter para sair\n";
	cin.get();  
}
