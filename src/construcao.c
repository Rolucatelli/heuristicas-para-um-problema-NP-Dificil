#include "../hdr/grasp.h";
#include "../hdr/avaliacaocusto.h";

void Construcao(int *elements, int N, solution *s)
{
    int **numbers = (int **)malloc(((int)N/3) * sizeof(int *)); // Cria uma matriz de inteiros
    for (int i = 0; i < ((int)N/3); i++)
    {
        numbers[i] = (int *)malloc(3 * sizeof(int)); // Cria um vetor de 3 inteiros
    }

    for (int i = 0; i < ((int)N/3); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            numbers[i][j] = i; // Inicializa a matriz com os valores de 0 a N/3
        }
    }

    for (int i = 0; i < N; i++)
    {
        s->partition[i] = -1; // Inicializa o vetor de partições com -1
    }
    
    
    for (int i = 0; i < N; i++)
    {
        int temp = rand() % ((int)N / 3);
        do{
            for (int j = 0; j < 3; j++)
            {
                if (numbers[temp][j] != -1)
                {
                    s->partition[i] = numbers[temp][j];
                    numbers[temp][j] = -1;
                    break;
                }
                
            }
            temp = (temp + 1) % ((int)N/3);
        }while(s->partition[i] == -1);
    }
    


    f(s, N, elements);
}