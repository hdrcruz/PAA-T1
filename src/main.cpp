#include "sort.hpp"


int main(int argc, char **argv){
  vector<int> teste;
  Sort ordenador;
  char algoritmo;
  int tamanho;
  double tempo;
  clock_t tStart;
  

  if(argc != 3){
    cout << "UUsage: " << argv[0] << " ARQUIVO-ENTRADA ARQUIVO-SAIDA" << endl;
    return 0;
  }

  ordenador.readFile(argv[1]);
  // cout << "QTD de Elementos: ";
  // cin >> tamanho;
  // ordenador.randomPop(tamanho);
  cout << "ESCOLHA O ALGORITMO" <<  endl;
  cout << "B - BubbleSort" << endl;
  cout << "S - SelectionSort" << endl;
  cout << "I - InsertionSort" << endl;
  cout << "M - MergeSort" << endl;
  cout << "Q - QuickSort - Pivo Elemento Mediano" << endl;
  cout << "P - QuickSort - Pivo Primeiro Elemento" << endl;
  cout << "U - QuickSort - Pivo Ultimo Elemento" << endl;
  cout << "A - QuickSort - Pivo Elemento Aleatorio" << endl;
  cout << "Escolha: ";
  cin >> algoritmo;
  switch(algoritmo){
    case 'B':
    case 'b':
      tStart = clock();
      ordenador.setAlgoritmo("BubbleSort");
      ordenador.bubbleSort();
      tempo = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      cout << "Algoritmo: BubbleSort" << endl;
      break;
    case 'S':
    case 's':
      tStart = clock();
      ordenador.selectionSort();
      ordenador.setAlgoritmo("SelectionSort");
      tempo = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      cout << "Algoritmo: SelectionSort" << endl;
      break;
    case 'I':
    case 'i':
      tStart = clock();
      ordenador.setAlgoritmo("InsertionSort");
      ordenador.insertionSort();
      tempo = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      cout << "Algoritmo: InsertionSort" << endl;
      break;
    case 'M':
    case 'm':
      tStart = clock();
      ordenador.setAlgoritmo("MergeSort");
      ordenador.mergeSort(0,ordenador.getSize()-1);
      tempo = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      cout << "Algoritmo: mergeSort" << endl;
      break;
    case 'Q':
    case 'q':
      tStart = clock();
      ordenador.setAlgoritmo("QuickSort - Mediano");
      ordenador.quickSortMedium(0,ordenador.getSize()-1);
      tempo = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      cout << "Algoritmo: quickSort" << endl;
      break;
    case 'P':
    case 'p':
      tStart = clock();
      ordenador.setAlgoritmo("QuickSort - Primeiro");
      ordenador.quickSortFirst(0,ordenador.getSize()-1);
      tempo = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      cout << "Algoritmo: quickSort" << endl;
      break;
    case 'U':
    case 'u':
      tStart = clock();
      ordenador.setAlgoritmo("QuickSort - Ultimo");
      ordenador.quickSortLast(0,ordenador.getSize()-1);
      tempo = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      cout << "Algoritmo: quickSort" << endl;
      break;
    case 'A':
    case 'a':
      tStart = clock();
      ordenador.setAlgoritmo("QuickSort - Aleatorio");
      ordenador.quickSortRandom(0,ordenador.getSize()-1);
      tempo = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      cout << "Algoritmo: quickSort" << endl;
      break;
    default:
      cout << "Seleção Inválida. Tente Novamante" << endl;
  }
  ordenador.setTempo(tempo);
  ordenador.printData();
  ordenador.printStats();
  ordenador.saveStats(argv[2]);
  return 1;
}
