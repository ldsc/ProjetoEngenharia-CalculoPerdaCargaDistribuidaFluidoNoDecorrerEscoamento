#include "CFluido.h"
using namespace std;

//Entrada e conversao de Dados 
double CFluido::VISCOSIDADEdinamica()
{	
	CConversaoUnidades conversor ;
	std :: string unidade ;
	std::cout<<"Entre com o valor da Viscosidade Dinamica e em seguida sua unidade. [Ex: 0.1 N.s/m2] \n ";
	std::cin>>viscosidadeDinamica; 
	std::cin>>unidade;
	viscosidadeDinamica=conversor.UNSI(viscosidadeDinamica,unidade);
	std::cout<<"Transformando para SI -----> "<<viscosidadeDinamica<<" ";
	std::cout<<conversor.NovaUnidade() <<std::endl;
	return viscosidadeDinamica;
}
//Entrada e conversao de Dados 
double CFluido::MASSAespecifica()
{
	CConversaoUnidades conversor ;
	std :: string unidade ;
	std::cout<<"Entre com o valor da  Massa Especifica do fluido e em seguida sua unidade [Ex: 3 g/cm3]. \n ";
	std::cin>>massaEspecifica; 
	std::cin>>unidade;
	massaEspecifica=conversor.UNSI(massaEspecifica,unidade);
	std::cout<<"Transformando para SI -----> "<<massaEspecifica<<" ";
	std::cout<<conversor.NovaUnidade() <<std::endl;
	return massaEspecifica;
}
//Entrada e conversao de Dados 
double CFluido::VELOCIDADEfluido()
{
	CConversaoUnidades conversor ;
	std :: string unidade ;
	std::cout<<"Entre com o valor da Velocidade do Fluido e em seguida sua unidade [Ex: 10 m/s].  \n ";
	std::cin>>velocidadeFluido;
	std::cin>>unidade;
	velocidadeFluido=conversor.UNSI(velocidadeFluido,unidade);
	std::cout<<"Transformando para SI -----> "<<velocidadeFluido<<" ";
	std::cout<<conversor.NovaUnidade() <<std::endl;
	return velocidadeFluido;
}
//Entrada e conversao de Dados 
double CFluido::VISCOSIDADEcinematica()
{
	CConversaoUnidades conversor ;
	std :: string unidade ;
	std::cout<<"Entre com o valor da Viscosidade Cinematica e em seguida sua unidade [Ex: 10  m2/s].\n ";
	std::cin>>viscosidadeCinematica;
	std::cin>>unidade;
	viscosidadeCinematica=conversor.UNSI(viscosidadeCinematica,unidade);
	std::cout<<"Transformando para SI -----> "<<viscosidadeCinematica<<" ";
	std::cout<<conversor.NovaUnidade() <<std::endl;
	return viscosidadeCinematica;
}
