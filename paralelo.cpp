#include <iostream>
#include <ctime>
#include <omp.h>
using namespace std;

int main() {
  int n = 100; // quantidade de sequências que serão geradas
  int t = 0;
  clock_t begin = clock();

  #pragma omp parallel for
  for (int i = 0; i < n; i++) {
    cout << ">Sequence" << i << endl;
    for (int j = 0; j < 80; j++) {
      t = rand() % 4; // gera um número aleatório entre 0 e 3
      if (t == 0)
        cout << 'A';
      else if (t == 1)
        cout << 'C';
      else if (t == 2)
        cout << 'G';
      else
        cout << 'T';
    }
    cout << endl;
  }

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << "Tempo de execução paralelo: " << elapsed_secs << " segundos" << endl;

  return 0;
}