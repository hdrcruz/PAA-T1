#include "sort.hpp"


int main(int argc, char **argv){
  vector<int> teste;

  Sort ordenador;

  if(argc != 2){
    cout << "Usage: " << argv[0] << " ARQUIVO" << endl;
    return 0; //should be two arguments, exe name & file path/name
  }

  ordenador.readFile(argv[1]);


  int i;
   

  cout << "tamanho: " << ordenador.getSize() << endl;
  // ordenador.quickSortRandom(0,ordenador.getSize()-1);
  ordenador.selectionSort();

  cout << "Vetor Ordenado: " << endl;
  ordenador.printData();

  return 1;
}
