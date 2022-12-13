#include <iostream>
#include <fstream>
#include <string>
#include <omp.h>

using namespace std;

// Função que cria a sequência Fasta
string createFasta(int tam){
    string seq = "";
    string bases[4] = { "A", "T", "C", "G" };
    for (int i = 0; i < tam; i++){
        int rand_base = rand() % 4;
        seq += bases[rand_base];
    }
    return seq;
}

// Função para gravar a sequência FASTA no arquivo
void saveFasta(string fasta, string name){
    ofstream outfile(name);
    outfile << ">Sequence" << name << endl;
    outfile << fasta << endl;
    outfile.close();
}

int main(){
    int tam = 100; // tamanho da sequência

    // Inicia a contagem do tempo
    double start_time = omp_get_wtime();
    // Gera a sequência FASTA
    #pragma omp parallel
    {
        #pragma omp single
        {
            string fasta = createFasta(tam);
            saveFasta(fasta, "sequencia.fasta");
        }
    }
    // Finaliza a contagem do tempo
    double end_time = omp_get_wtime();
    double total_time = end_time - start_time;
    cout << "Tempo de execução: " << total_time << endl;

    return 0;
}