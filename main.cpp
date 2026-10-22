#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main()
{
    srand(time(nullptr));
    int palpite;
    int numeroSecreto;
    int tentativas = 0;
    char jogarNovamente;

    cout << "Bem-vindo ao jogo!" << endl;
    cout << "====================================" << endl;
    cout << "      JOGO DE ADIVINHACAO           " << endl;
    cout << "====================================" << endl;
    cout << "Tente adivinhar o numero secreto entre 1 e 100." << endl;
    do
    {
        numeroSecreto = rand() % 100 + 1;
        tentativas = 0;

        do
        {

            cout << "Digite o seu palpite: ";

            if (!(cin >> palpite))
            {
                if (cin.eof())
                {
                    cout << "\nEntrada encerrada. Saindo do jogo..." << endl;
                    return 0;
                }

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Entrada invalida! Digite apenas numeros." << endl;

                palpite = 0;
                continue;
            }

            if (palpite < 1 || palpite > 100)
            {
                cout << "Palpite invalido! Digite um numero entre 1 e 100." << endl;
                continue;
            }

            tentativas++;
            cout << "O seu palpite foi: " << palpite << endl;

            if (palpite == numeroSecreto)
            {
                cout << "Parabens! Voce acertou!" << endl;
                cout << "Você precisou de " << tentativas << " tentativas para acertar o número secreto." << endl;
            }
            else if (palpite < numeroSecreto)
            {
                cout << "O numero secreto é maior do que o seu palpite." << endl;
            }
            else
            {
                cout << "O numero secreto é menor do que o seu palpite." << endl;
            }

        } while (palpite != numeroSecreto);
        do
        {
            cout << "\nDeseja jogar novamente? (S/N): ";
            cin >> jogarNovamente;

            if (jogarNovamente != 'S' && jogarNovamente != 's' &&
                jogarNovamente != 'N' && jogarNovamente != 'n')
            {
                cout << "Opcao invalida! Digite S ou N." << endl;
            }

        } while (jogarNovamente != 'S' && jogarNovamente != 's' &&
                 jogarNovamente != 'N' && jogarNovamente != 'n');
    } while (jogarNovamente == 'S' || jogarNovamente == 's');

    return 0;
}