#include "Algorithms.h"

using namespace std;
using namespace filesystem;

namespace checks {
    bool File_Exists(std::string fileName) {
        const char* path = fileName.c_str();
        if (!_access(path, 0))
            return true;
        else
            return false;
    }
    bool Only_Read(std::string fileName) {
        const char* path = fileName.c_str();
        if (_access(path, 2))
            return true;
        else
            return false;
    }

    int is_Positive_Number(int num) {
        while (num < 1) {
            std::cout << "����� ������ ���� ������ ����. ���������� �����: ";
            num = input::user_Int_Input();
        }
        return num;
    }

    bool is_Number_Check(std::string inputData) {
        bool tmp = true;
        for (int i = 0; i < inputData.length(); i++) {
            tmp = isdigit(inputData[i]);
        }
        return tmp;
    }
    bool is_Digit_Check(char inputData) {
        return isdigit(inputData);
    }

}

namespace input {

    int user_Int_Input() {
        int userInput;
        std::cin >> userInput;
        while (std::cin.fail()) {
            std::cout << "������������ ����." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cin >> userInput;
        }
        std::cin.ignore(INT_MAX, '\n');
        return userInput;
    }

    void input_From_Console(userMatrix *matrPtr) {
        int amountOfRows;
        int amountOfColumns;
        int tmp;
        std::cout << "\n������� ���������� �����: ";
        amountOfRows = user_Int_Input();
        checks::is_Positive_Number(amountOfRows);

        std::cout << "\n������� ���������� ��������: ";
        amountOfColumns = user_Int_Input();
        checks::is_Positive_Number(amountOfColumns);
        

        matrPtr->new_Matrix(amountOfRows, amountOfColumns);
        for (int i = 0; i < amountOfRows; i++) {
            for (int j = 0; j < amountOfColumns; j++) {
                std::cout << "\n������� �������� � [" << i+1 << "][" << j+1 << "] ��������: ";
                tmp = user_Int_Input();
                while (tmp < 0) {
                    std::cout << "\n����� �� ����� ���� ������ ����. ���������� �����: ";
                    tmp = user_Int_Input();
                }

                matrPtr->set_Element(i, j, tmp);
            }
        }
    }

    void input_Randomly(userMatrix* matrPtr) {
        int amountOfRows;
        int amountOfColumns;
        int randomNum;
        srand((unsigned)time(0));
        std::cout << "\n������� ���������� �����: ";
        amountOfRows = user_Int_Input();
        checks::is_Positive_Number(amountOfRows);

        std::cout << "\n������� ���������� ��������: ";
        amountOfColumns = user_Int_Input();
        checks::is_Positive_Number(amountOfColumns);

        matrPtr->new_Matrix(amountOfRows, amountOfColumns);

        for (int i = 0; i < amountOfRows; i++) {
            for (int j = 0; j < amountOfColumns; j++) {
                randomNum = 1 + rand() % 20;
                matrPtr->set_Element(i, j, randomNum);
            }
        }
    }

    int input_From_File(userMatrix *matrPtr) {
        string filePath = "";
        string tmp = "";
        int amountOfRows = 0;
        int amountOfColumns = 0;
        int elem = 0;
        bool isDataLoaded = false;

        do {

            cout << "������� ����: ";
            getline(cin, filePath);

            if (!ifstream(filePath)) {
                cout << "\n������ ����� �� ����������, ���������� �����.\n\n";
                continue;
            }

            error_code ec1;
            if (!is_regular_file(filePath, ec1)) {
                cout << "\n����� �������� ������������ ��������, ���������� �����.\n\n";
                continue;
            }

            ifstream newFileMatrix(filePath);
            if (!newFileMatrix) {
                cout << "\n���� ���� ��������� ������, ���������� �����.\n\n";
                newFileMatrix.close();
                continue;
            }

            newFileMatrix >> amountOfRows;
            newFileMatrix >> amountOfColumns;

            /*try {
                matrPtr->new_Matrix(amountOfRows, amountOfColumns);
            }

            catch (...) {
                return error;
            }*/

            matrPtr->new_Matrix(amountOfRows, amountOfColumns);
            for (int i = 0; i < amountOfRows; i++) {
                for (int j = 0; j < amountOfColumns; j++) {
                    if (!(newFileMatrix >> elem)) {
                        cout << "������ �����������, ���������� �����.\n\n";
                        newFileMatrix.close();
                        break;
                    }
                    matrPtr->set_Element(i, j, elem);
                    /*tmp.clear();
                    newFileMatrix >> tmp;
                    if (tmp.length() == 0) {
                        return error;
                    }
                    if (!checks::is_Number_Check(tmp)) {
                        return error;
                    }
                    elem = stoi(tmp);
                    matrPtr->set_Element(i, j, elem);*/
                }
            }
            newFileMatrix.close();
            isDataLoaded = true;
        } while (!isDataLoaded);
        return allGood;
    }
}


namespace output {
   void module_Tests() {
       int testNum = 0;
       int tmp;
       userMatrix moduleMass;
       moduleMass.new_Matrix(5, 5);
       try {

           for (int i = 0; i < 5; ++i)
           {
               for (int j = 0; j < 5; ++j) {
                   tmp = rand() % 10;
                   moduleMass.set_Element(i, j, tmp);
               }
           }
           std::cout << "\n\n������������ ������ �������. ";
       }
       catch (...) {
           std::cout << "���� ����� " << testNum << std::endl;
           std::cout << "����� ������ - " << std::endl;
           for (int i = 0; i < 5; i++)
           {
               std::cout << std::endl;
               for (int j = 0; j < 5; j++) {
                   std::cout << moduleMass.get_Element(i, j) << std::endl;
               }
           }
           std::cout << "��������� ��������� - ���������� ������� �������� � ������ �������." << std::endl;
           std::cout << "���������� ��������� - ����������� ������. " << std::endl;
       }
   }
   
   void save_Unsorted_Matrix_To_File(userMatrix* matrPtr) {
       int userChoice = 0;
       string filePath = "";
       bool isDataSaved = false;
       do {
           cout << "������� ���� ����������: ";
           getline(cin, filePath);
           while (checks::File_Exists(filePath)) {
               cout << "���� ��� ����������." << endl << "1) ������������ ����." << endl << "2) ������ ������ ����." << endl;
               if (checks::Only_Read(filePath)) {
                   cout << "���� �������� ������ ��� ������, �������������� ������� � ������ 2." << endl;
                   userChoice = no;
               }
               else userChoice = input::user_Int_Input();

               if (userChoice == yes) {
                   cout << "���� ������� �����������." << endl;
                   break;
               }

               if (userChoice == no) {
                   cout << "������� ���� ����������: ";
                   cin >> filePath;
               }
           }
           ofstream userFile(filePath, ofstream::app);
           error_code ec;
           if (!is_regular_file(filePath, ec)) {
               cout << "� ����� ���� ���� ������������ ��������, ���������� �����.\n\n";
               continue;
           }
           if (!userFile) {
               cout << "������ ���������, ���������� �����.\n\n";
               userFile.close();
               continue;
           }

           userFile.close();
           userFile.open(filePath, ofstream::trunc);
           userFile << matrPtr->amountOfRows << " ";
           userFile << matrPtr->amountOfColumns << " ";
           for (int i = 0; i < matrPtr->amountOfRows; i++) {
               for (int j = 0; j < matrPtr->amountOfColumns; j++) {
                   userFile << matrPtr->get_Element(i, j) << " ";
               }
           }
           userFile.close();
           isDataSaved = true;

       } while (!isDataSaved);
   }

   void output_unsorted_Matrix(userMatrix* matrPtr) {
        std::cout << "���� �������:\n\n";
        for (int i = 0; i < matrPtr->amountOfRows; i++) {
            for (int j = 0; j < matrPtr->amountOfColumns; j++) {
                std::cout << matrPtr->get_Element(i, j) << " ";
            }
            std::cout << std::endl << std::endl;
        }
    }

   void save_Results_To_File(userMatrix* matrPtr, int* compareBubblePtr, int* compareSelectPtr, int* compareInsertPtr, int* compareShellPtr, int* compareQuickPtr) {
       int amountOfRows = matrPtr->amountOfRows;
       int amountOfColumns = matrPtr->amountOfColumns;
       int digitsSumInRow = 0;
       vector<vector<int>> bubbleMatrix;
       vector <vector<int>> sumAndNumRows;
       vector<int> tmpVec;
       tmpVec.push_back(0);
       tmpVec.push_back(0);

       bubbleMatrix.resize(amountOfRows);
       for (int i = 0; i < amountOfRows; ++i)
       {
           bubbleMatrix[i].resize(amountOfColumns);
       }
       for (int i = 0; i < matrPtr->amountOfRows; i++) {
           for (int j = 0; j < matrPtr->amountOfColumns; j++) {
               bubbleMatrix[i][j] = matrPtr->get_Element(i, j);
           }
       }

       for (int i = 0; i < matrPtr->amountOfRows; i++) {
           if (i % 2 == 0) {
               digitsSumInRow = 0;
               for (int j = 0; j < matrPtr->amountOfColumns; j++) {
                   int digitsSumInNum = 0;
                   int matrElem = matrPtr->get_Element(i, j);

                   while (matrElem != 0) {
                       digitsSumInNum += matrElem % 10;
                       matrElem /= 10;
                   }
                   digitsSumInRow += digitsSumInNum;
               }
               tmpVec[0] = digitsSumInRow;
               tmpVec[1] = i;
               sumAndNumRows.push_back(tmpVec);
           }
       }

       for (int i = 0; i < sumAndNumRows.size(); i++) {
           for (unsigned int j = 0; j < sumAndNumRows.size() - 1; j++) {
               if (sumAndNumRows[j].at(0) > sumAndNumRows[j + 1].at(0)) {
                   swap(sumAndNumRows[j], sumAndNumRows[j + 1]);
               }
           }
       }

       int row = 0;
       int col = 0;
       while (row < bubbleMatrix.size()) {
           bubbleMatrix[row] = matrPtr->get_Vector(sumAndNumRows[col].at(1));
           row += 2;
           col += 1;
       }

       int userChoice = 0;
       string filePath = "";
       bool isDataSaved = false;
       do {
           cout << "������� ���� ����������: ";
           getline(cin, filePath);
           while (checks::File_Exists(filePath)) {
               cout << "���� ��� ����������." << endl << "1) ������������ ����." << endl << "2) ������ ������ ����." << endl;
               if (checks::Only_Read(filePath)) {
                   cout << "���� �������� ������ ��� ������, �������������� ������� � ������ 2." << endl;
                   userChoice = no;
               }
               else userChoice = input::user_Int_Input();

               if (userChoice == yes) {
                   cout << "���� ������� �����������." << endl;
                   break;
               }

               if (userChoice == no) {
                   cout << "������� ���� ����������: ";
                   cin >> filePath;
               }
           }

           ofstream userFile(filePath, ofstream::app);
           error_code ec;
           if (!is_regular_file(filePath, ec)) {
               cout << "� ����� ���� ���� ������������ ��������, ���������� �����.\n\n";
               continue;
           }
           if (!userFile) {
               cout << "������ ���������, ���������� �����.\n\n";
               userFile.close();
               continue;
           }


           userFile.close();
           userFile.open(filePath, ofstream::trunc);


           userFile << matrPtr->amountOfRows << " ";
           userFile << matrPtr->amountOfColumns << " ";
           for (int i = 0; i < matrPtr->amountOfRows; i++) {
               for (int j = 0; j < matrPtr->amountOfColumns; j++) {
                   userFile << bubbleMatrix[i][j] << " ";
               }
           }
           userFile << '\n';
           userFile << '|';
           for (int i = 0; i < 2; i++) {
               userFile << compareBubblePtr[i] << '|';
           }
           userFile << '\n';
           userFile << '|';
           for (int i = 0; i < 2; i++) {
               userFile << compareSelectPtr[i] << '|';
           }
           userFile << '\n';
           userFile << '|';
           for (int i = 0; i < 2; i++) {
               userFile << compareInsertPtr[i] << '|';
           }
           userFile << '\n';
           userFile << '|';
           for (int i = 0; i < 2; i++) {
               userFile << compareShellPtr[i] << '|';
           }
           userFile << '\n';
           userFile << '|';
           for (int i = 0; i < 2; i++) {
               userFile << compareQuickPtr[i] << '|';
           }
           userFile << '\n';
           //userFile.close();
           isDataSaved = true;
       } while (!isDataSaved);
   }
}