#include <iostream>
#include "../src/FloatMatrix/FloatMatrix.h"
#include "../src/AbstractMatrix/AbstractMatrix.h"

using namespace std;

int main(int argc, const char* argv[])
{
  int choose = 0;
  // объявляем матрицы для операций
  FloatMatrix firstMatrix;
  FloatMatrix secondMatrix;
  FloatMatrix sumMatrix;

  do
  {
    cout << "1. Console input (Write 1 by 1)" << endl;
    cout << "2. File input  (input1.txt input2.txt)" << endl;
    cout << "3. Console output" << endl;
    cout << "4. File output" << endl;
    cout << "5. Sum of matrix" << endl;
    cout << "6. Equality operators" << endl;
    cout << "7. Multiply matrix" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose something" << endl;

    cin >> choose;

    switch (choose)
    {
      case 1:
      {
        size_t sizeOfMatrix = 0;

        cout << "Enter the size of matrix: ";
        cin >> sizeOfMatrix;
        // устанавливаем размер матрицы
        FloatMatrix a(sizeOfMatrix, sizeof(float));

        firstMatrix = a;
        secondMatrix = a;
        // считываем две матрицы
        cout << "First matrix: " << endl;
        cin >> firstMatrix;
        cout << "Second matrix: " << endl;
        cin >> secondMatrix;

        break;
      }
      case 2:
      {
        size_t sizeOfMatrix = 0;

        ifstream fin;
        fin.open("test/input1.txt");
        if (!fin.fail())
        {
          fin >> sizeOfMatrix;
          // устанавливаем размер матрицы
          FloatMatrix a(sizeOfMatrix, sizeof(float));
          firstMatrix = a;

          // считываем матрицу
          fin >> firstMatrix;
        }
        fin.close();

        fin.open("test/input2.txt");
        if (!fin.fail())
        {
          fin >> sizeOfMatrix;
          // устанавливаем размер марицы
          FloatMatrix a(sizeOfMatrix, sizeof(float));
          secondMatrix = a;

          // считываем матрицу
          fin >> secondMatrix;
        }

        fin.close();
        break;
      }
      case 3:
      {
        // выводим матрицы
        cout << "First matrix: " << endl;
        cout << firstMatrix << endl;

        cout << "Second matrix: " << endl;
        cout << secondMatrix << endl;
        break;
      }
      case 4:
      {
        // выводим матрицы в файл
        ofstream fout;
        fout.open("test/output1.txt");
        fout << firstMatrix;

        fout.open("test/output2.txt");
        fout << secondMatrix;
        fout.close();
        break;
      }
      case 5:
      {
        // складываем матрицы
        sumMatrix = (firstMatrix + secondMatrix);

        // выводим сумму
        cout << "sum of matrix: " << endl;
        cout << sumMatrix;
        cout << endl;

        ofstream fout;
        fout.open("test/output_sum.txt");
        // выводим сумму в файл
        fout << sumMatrix;
        fout.close();
        break;
      }
      case 6:
      {
        // проверяем на равенство
        firstMatrix == secondMatrix
        ? cout << "first matrix equal second matrix"
        : cout << "first matrix not equal second matrix";
        cout << endl;

        break;
      }
      case 7:
      {
        // умножаем матрицы
        FloatMatrix mnMatrix;
        mnMatrix = firstMatrix*secondMatrix;
        // выводим умноженную матрицу
        cout << mnMatrix;
        cout << endl;

        break;
      }
      case 0:
      {
        exit(EXIT_SUCCESS);
      }
      default:
      {
        cout << "Ne popal;(" << endl;
      }
    }
  }
  while(true);
}
