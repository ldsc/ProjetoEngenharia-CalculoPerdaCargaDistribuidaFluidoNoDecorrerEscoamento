#include "CTubo.h"

//Entrada e conversao de Dados 
void CTubo::Entrada(){
	Comprimento();
	Diametrohidraulico();
	tabela();
	CRdh();
}

double CTubo::Comprimento ()		
{
  CConversaoUnidades conversor;
  std::string unidade;
  std::cout << "Entre com o comprimento do tubo e em seguida sua unidade [Ex: 35 m].\n ";
  std::cin >> l;
  std::cin >> unidade;
  l = conversor.UNSI (l, unidade);
  std::cout << "Transformando para SI -----> " << l << " ";
  std::cout << conversor.NovaUnidade () << std::endl;
  return l;
}
//Entrada e conversao de Dados 
double CTubo::Diametrohidraulico ()	
{
  CConversaoUnidades conversor;
  std::string unidade;
  std::cout << "Entre com o valor do  Diametro Hidraulico e em seguida sua unidade [Ex: 2  m]. \n ";
  std::cin >> diametroHidraulico;
  std::cin >> unidade;
  diametroHidraulico = conversor.UNSI (diametroHidraulico, unidade);
  std::cout << "Transformando para SI -----> " << diametroHidraulico << " ";
  std::cout << conversor.NovaUnidade () << std::endl;
  return diametroHidraulico;
}

//Salva tabela nos maps 
std::ifstream & operator>> (std::ifstream& in, CTubo& tabela)
{
  CTubo graficorug;
  tabela.tabelamaterial.clear ();
  tabela.tabelarugosidade.clear ();
  std::string material;
  double rugosidadeabsoluta;
  while (true)			// le linhas e adiciona ao map
    {
      in >> material;
      if (in.good ())
	in >> rugosidadeabsoluta;
      else
	{
	  in.clear ();
	  return in;
	}
      if (in.good ())
	{
	  tabela.tabelamaterial.
	    insert (make_pair (material, rugosidadeabsoluta));
	  tabela.tabelarugosidade.
	    insert (make_pair (rugosidadeabsoluta, material));
	}
      else
	{
	  in.clear ();
	  return in;
	}
    }
  return in;
}

//Constroi e Le a tabela do disco   MATERIAL - RUGOSIDADE
void CTubo::tabela ()
{
  std::ifstream in;
  std::cout <<"\nSe deseja criar uma nova tabela digite 1. \nCaso deseje utilizar o banco de dados digite 2.\n";
  int alternativa;
  std::cin >> alternativa; std::cin.get();
  
 // Criacao de nova tabela pelo usuario 
  if (alternativa == 1)
 	{
		std::cout <<"\nEntre com o nome para nomear o novo banco de dados.\nObs: Sem espacos ou caracteres especiais.\n";
		std::cin >> nomeArquivo;
		std::cout<<"\nQuantos dados de cada elemento deseja preencher a tabela?\n";
		int d;
		std::cin>>d;
		std::cout << "\nEntre os dados da Tabela  Material x Rugosidade no seguinte formato: \nMaterial enter Rugosidade enter.\n";
		//limpa vetores
		vectmaterial.clear();
		vecrugosidade.clear();	
		//Recebe dados do teclado do usuario
		for(int i=0;i<d;i++)
		{	
			std::cin >> materialaux;
			vectmaterial.push_back(materialaux);
			std::cin >> rugosidade;
			vecrugosidade.push_back(rugosidade);
		}
		//Apaga ultimo dado do vetor
		vectmaterial.pop_back () ;
		vecrugosidade.pop_back () ;
		//Mostra tabela criada pelo usuario na tela
		std::cout<<"\nA tabela criada e: \n\n";
		for(int i=0; i<d;i++)
		{
			std::cout<<vectmaterial[i]<<std::setw(30)<<vecrugosidade[i]<<std::endl;
		}
//salva tabela em disco
	std::ofstream fout (nomeArquivo.c_str ()) ;
		for( int i = 0; i < d; i ++)	
		{
			fout << vectmaterial[i] << std::setw(15) << vecrugosidade[i] << std::endl;
		}
	}


//Le tabela do banco de dados ja criada
  if (alternativa == 2) 
	{
		std::ifstream in;
		//Verificacao nome do arquivo do banco de dados
		do
		{
		    std::cout <<"\nEntre com nome do arquivo com dados padroes dos materiais e rugosidades: ";
		    std::cin >> nomeArquivo;
		    std::cin.get ();
		    in.open (nomeArquivo.c_str ());
		    if (!in)
			std::cout << "\nNome invalido, tente novamente.\n";
		} while (!in);
	    
		//Limpa vetores
		vectmaterial.clear();
		vecrugosidade.clear();	
		//Enquanto nao chegou ao final da tabela continua recebendo dados e salvando nos vetores
		while (!in.eof()) 
		{	
			in>> materialaux;
			vectmaterial.push_back(materialaux);
			in>> rugosidade;
			vecrugosidade.push_back(rugosidade);
		}
		in.close () ;
		
		vectmaterial.pop_back () ; vecrugosidade. pop_back () ;
		
		//Mostra tabela carregada do disco na tela
		std::cout<<"\nA tabela carregada do disco e: \n\n";
		for(int i=0; i<vectmaterial.size(); i++) //ok
		{
			std::cout<<vectmaterial[i]<<std::setw(30)<<vecrugosidade[i]<<std::endl;
		}
		vectmaterial.pop_back () ; vecrugosidade.pop_back () ;
	}
	for (int i=0; i<vectmaterial.size(); i++){
		tabelamaterial.insert(std::make_pair(vectmaterial[i], vecrugosidade[i]));
		tabelarugosidade.insert(std::make_pair(vecrugosidade[i], vectmaterial[i]));
		tabelarugosidaderelativa.insert(std::make_pair(vectmaterial[i],vecrugosidade[i]/diametroHidraulico));
	}
}

