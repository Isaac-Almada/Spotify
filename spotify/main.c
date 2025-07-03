/******************************************************************************

Atividade: SPOTIFY

*******************************************************************************/
#include <stdio.h>
#include <string.h>

struct artista{
    char nome[30];
    char genero[20];
    float reproducoes;
    float ouvintes;
};
typedef struct artista tipoArtista;

struct generos{
    char genero[20];
    int totalArtistas;
    float reproducoes;
    float ouvintes;
};

typedef struct generos tipoGenero;

void imprimeArtista(tipoArtista vet[], int tam);

//recebe um vetor de generos vazio e retorna o total de elementos inseridos
int buscaGeneros(tipoArtista vetArtista[], int tam, tipoGenero vetGenero[]);

int main() {
    //DECLARAÇÃO DE VARIÁVEIS
    tipoArtista vetArtista[100];
    int qtdade = 0; //total de linhas do vetor
    float maiorReproducao = 0;
    int indiceMaiorReproducao = 0;
    FILE *arq;
    tipoArtista artista;
    tipoGenero vetGenero[100];


    //ABERTURA DO ARQUIVO
    arq = fopen("spotify.txt", "r");
    if (!arq)
        return 1;

    //LEITURA DO ARQUIVO
    int i = 0;
    while (!feof(arq))
    {
        fscanf(arq, "%[^,],%[^,],%f,%f", artista.nome, artista.genero,
                                    &artista.reproducoes, &artista.ouvintes);
        vetArtista[i] = artista;


        //BUSCAR PELO ARTISTA MAIS OUVIDO
        if (artista.reproducoes > vetArtista[indiceMaiorReproducao].reproducoes)
        {
            indiceMaiorReproducao = i;
        }

        i++;


    }
    qtdade = i;

    //a)Lista de todos os artistas, formatada em colunas:
    imprimeArtista(vetArtista, qtdade);

    //b) Nome do artista mais ouvido (maior número de reproduções).
    printf("O artista mais ouvido é o %s, com %0.f reproduções\n",
           vetArtista[indiceMaiorReproducao].nome,
           vetArtista[indiceMaiorReproducao].reproducoes);

    //c
    int totalGeneros = buscaGeneros(vetArtista, qtdade, vetGenero);
    printf("%d\n", totalGeneros);

    return 0;


}

void imprimeArtista(tipoArtista vet[], int tam)
{
    for (int i=0; i< tam; i++)
    {
        printf("%s\t%s\t%0.f\t%0.f\n", vet[i].nome, vet[i].genero,
                                vet[i].reproducoes, vet[i].ouvintes);
    }
}

int buscaGeneros(tipoArtista vetArtista[], int tam, tipoGenero vetGenero[])
{
    int totalGeneros = 0; //contador do vetor de generos
    int j = 0;
    int encontrou = 0;

    for (int i = 0; i < tam; i++) //iterando sobre o vetor de artistas
    {
        //vai ler uma posição do vetor, pegar o genero
        //verifica se o genero já está no vetor de generos
        //se estiver, atualiza as variáveis
        //senão, inclui no vetor de generos e atualiza as variáveis
        encontrou = 0;
        j = 0;
        while (j < totalGeneros && encontrou == 0)
        {
            //printf("%s\t%s\n", vetArtista[i].genero, vetGenero[j].genero);
            if (strcmp(vetArtista[i].genero, vetGenero[j].genero) == 0)
                encontrou = 1;
            j++;
        }
        if (encontrou == 1) // o genero já existe no vetor de generos
        {
            vetGenero[j].totalArtistas = vetGenero[j].totalArtistas + 1;
            vetGenero[j].reproducoes = vetGenero[j].reproducoes + vetArtista[i].reproducoes;
            vetGenero[j].ouvintes = vetGenero[j].ouvintes + vetArtista[i].ouvintes;
        }
        else // o genero não existe no vetor de generos
        {
            strcpy(vetGenero[totalGeneros].genero, vetArtista[i].genero);
            vetGenero[totalGeneros].totalArtistas = 1;
            vetGenero[totalGeneros].ouvintes = vetArtista[i].ouvintes;
            vetGenero[totalGeneros].reproducoes = vetArtista[i].reproducoes;
            totalGeneros++;
        }

    }
    return totalGeneros;
}
