/**********************************
* Автор: Калинин Андрей           *
* Лабораторная №7                 *
* Дата: 09.11.2023                *
* Название:Частота повторений     *
* https://onlinegdb.com/cXQEKnc-E *
**********************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void lower (string &inputString) {
  for (int index = 0; index < inputString.size (); ++index) {
      inputString[index] = tolower(inputString[index]);
  }  
}

int main() {
  string tempString;
  char firstLetter;
  string secondLetter;
  string inputFile;
  int letterCount = 0;
  
  
  cout << "Name of input file: ";
  cin >> inputFile;
  
  
  ifstream exampleFile(inputFile);
  if ( !exampleFile.is_open() ) {
    cout << "Error: file does not open\n";  
  } else {
    cout << "Enter the letter (not uppercase): ";
    cin >> firstLetter;
    cout << "Enter two letters (not uppercase): ";
    cin >> secondLetter;
    
    exampleFile.seekg(0,ios::end); //Указатель в конец файла
    tempString.reserve(exampleFile.tellg()); // reserve подготовка места под заполнение string. tellg - узнать, сколько прочитано.
    exampleFile.seekg(0,ios::beg); //Указатель в начало файла
    tempString.assign (istreambuf_iterator<char>(exampleFile), //istreambuf_iterator хранит в себе символы входного потока (те, что записаны ранее)
                       istreambuf_iterator<char>());
      
    lower(tempString);
    
    
    for (int soloLetterIndex = 0; soloLetterIndex < tempString.size (); ++soloLetterIndex) {
      if (firstLetter == tempString[soloLetterIndex]) {
        ++letterCount;  
      }
      
    }
    
    cout << "Count of letter " << firstLetter << " = " <<  letterCount << endl;
    
    letterCount = 0;
    
    for (int twoLettersIndex = 0; twoLettersIndex < tempString.size() - 1 ; ++twoLettersIndex) {
      char firstSymbol = tempString[twoLettersIndex];
      char secondSymbol = tempString[twoLettersIndex + 1];
      string tempTwoLetters = string(1,firstSymbol) + string (1,secondSymbol);
      if (secondLetter == tempTwoLetters) {
        ++letterCount;  
      }
      
    }
  
    cout << "Count of two letters " << secondLetter << " = " <<  letterCount;
  }
  
  exampleFile.close();
  return 0;
}
