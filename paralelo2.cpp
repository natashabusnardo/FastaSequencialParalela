#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <ctime> 
#include <omp.h> 

using namespace std; 

int main() 
{ 
    int i, len; 
    // Variáveis usadas para gerar um número aleatório
    srand(time(NULL)); 
    int random_no = rand(); 

    // Variáveis usadas para imprimir o tempo de execução
    double start, end; 

    // Tamanho da sequência 
    len = 100; 

    // Iniciando o programa para o paralelismo 
    start = omp_get_wtime(); 

    // Cria um arquivo FASTA
    ofstream fasta; 
    fasta.open ("Sequencia.fasta"); 

    // Insere o cabeçalho do arquivo FASTA 
    fasta << ">" << random_no << "Aleatorio"<<endl; 

    // Gera a sequência randômica 
    char seq[len]; 
    for (i=0; i<len; i++) 
    { 
        // Gera uma letra aleatória de A a T
        int random_letter = rand() % 4; 
        if (random_letter == 0) 
            seq[i] = 'A'; 
        else if (random_letter == 1) 
            seq[i] = 'C'; 
        else if (random_letter == 2) 
            seq[i] = 'G'; 
        else
            seq[i] = 'T'; 
    } 

    // Insere a sequência no arquivo FASTA
    fasta << seq; 

    // Finaliza o programa para o paralelismo 
    end = omp_get_wtime(); 

    // Imprime o tempo de execução
    cout<<"Tempo de execução: "<<(end-start)<<endl; 

    // Fecha o arquivo FASTA
    fasta.close(); 

    return 0; 
}