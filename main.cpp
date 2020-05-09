#include <iostream>

using namespace std;

struct Pessoa
{
	int idade  = 0;
	string cpf = "0";
	int sexo = 0;
	bool gravida = false;

	Pessoa* proximo = NULL;
	Pessoa* anterior = NULL;
};

void printPessoa(Pessoa pessoa);
int lerInteiro(string campo);
string lerString(string campo);

int main()
{
	Pessoa* inicioLista = NULL;
	Pessoa* fimLista = NULL;
	Pessoa* aux = NULL;

	cout << "AV1 ESTRUTURA DE DADOS\n";
	int opcao = 0;
	while (opcao != 4)
	{
		cout << "\n1-Adicionar nova pessoa";
		cout << "\n2-Listar todas as pessoas";
		cout << "\n3-Proximo atendimento";
		cout << "\n4-Sair";
		cout << "\n\nEscolha Opcao: ";
		cin >> opcao;

		switch (opcao)
		{
			//Adicionar pessoa na fila.
			case 1:
			{
				Pessoa* novo = new Pessoa;
				novo->idade = lerInteiro("idade");
				novo->cpf = lerString("cpf");
				novo->sexo = lerInteiro("sexo (1-Feminino 2-Masculino)");
				if (novo->sexo == 1)
				{
					int gravida;
					cout << "\nVoce esta gravida? (1-SIM 2-NAO): ";
					cin >> gravida;
					if (gravida == 1)
					{
						novo->gravida = true;
					}
					else
					{
						novo->gravida = false;
					}
				}

				if (novo->idade > 65 || novo->gravida == true)
				{
					//Adicionando no inicio caso a pessoa tenha prioridade.
					if (inicioLista == NULL)
					{
						inicioLista = novo;
						fimLista = novo;
						novo->proximo = NULL;
						novo->anterior = NULL;
					}
					else
					{
						novo->proximo = inicioLista;
						inicioLista->anterior = novo;
						novo->anterior = NULL;
						inicioLista = novo;
					}
				}
				else
				{
					//Caso contrario adiciono no fim.
					if (inicioLista == NULL)
					{
						inicioLista = novo;
						fimLista = novo;
						novo->proximo = NULL;
						novo->anterior = NULL;
					}
					else
					{
						fimLista->proximo = novo;
						novo->anterior = fimLista;
						novo->proximo = NULL;
						fimLista = novo;
					}
				}
			} break;

			//Listagem de pessoas.
			case 2:
			{
				if (inicioLista == NULL)
				{
					cout << "\nLista Vazia" << endl;
				}
				else
				{
					aux = inicioLista;
					while (aux != NULL)
					{
						printPessoa(*aux);
						aux = aux->proximo;
					}
				}
			} break;

			//Proximo atendimento.
			case 3:
			{
				if (inicioLista == NULL)
				{
					cout << "\nLista Vazia" << endl;
				}
				else
				{
					aux = inicioLista;

					printPessoa(*aux);

					aux = aux->proximo;

					//Deletando quem ja foi atendido.
					aux = inicioLista;

					inicioLista = inicioLista->proximo;
					delete(aux);
					aux = inicioLista;
				}
			} break;
		}
	}

	return 0;
}

//Lê um numero inteiro do teclado.
//A string é apenas para especificar ao usuario o campo que ele precisa digitar.
int lerInteiro(string campo)
{
	int valor;
	cout << "\nDigite " << campo << ": ";
	cin >> valor;

	return valor;
}

//Lê uma string do teclado.
//A string é apenas para especificar ao usuario o campo que ele precisa digitar.
string lerString(string campo)
{
	string valor;
	cout << "\nDigite " << campo << ": ";
	cin >> valor;

	return valor;
}

//Imprimirá os dados da pessoa que foi passada.
void printPessoa(Pessoa pessoa)
{
	cout << "----------------------------------------\n";
	cout << "\nIDADE: " << pessoa.idade << endl;
	cout << "CPF: " << pessoa.cpf << endl;
	if (pessoa.sexo == 1)
	{
		cout << "SEXO: FEMININO\n";
		if (pessoa.gravida == true)
		{
			cout << "GRAVIDA: SIM\n";
		}
		else
		{
			cout << "GRAVIDA: NAO\n";
		}
	}
	else
	{
		cout << "SEXO: MASCULINO\n";
	}
}
