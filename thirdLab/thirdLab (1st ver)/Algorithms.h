#pragma once
#include<random>
#include<vector>
#include <conio.h>
#include <fstream>
#include<iostream>
#include <filesystem>
#include <io.h>
#include <string>
#include <time.h>
#include "User_Interface.h"

class userMatrix {
public:
    int amountOfRows=0;
    int amountOfColumns=0;

    void new_Matrix(int rows, int columns) {
        amountOfRows = rows;
        amountOfColumns = columns;
        matrVec.resize(rows);
        for (int i = 0; i < rows; i++) {
            matrVec[i].resize(columns);
        }
    }

    std::vector <std::vector<int>>* get_Pointer() {
        std::vector<std::vector<int>>* matrPtr = &matrVec;
        return matrPtr;
    }

    void set_Element(int rows, int columns, int elem) {
        matrVec[rows][columns] = elem;
    }

    int get_Element(int rows, int columns) {
        return matrVec[rows][columns];
    }

    std::vector<int> get_Vector(int rows) {
        return matrVec[rows];
    }

    void matrix_Clear() {
        std::vector<std::vector<int>>* matrPtr = get_Pointer();
        matrPtr->clear();
    }

 private:
    std::vector <std::vector<int>> matrVec;
};


namespace checks {
    bool File_Exists(std::string fileName);
    bool Only_Read(std::string fileName);
};

namespace input {
    void input_From_Console(userMatrix* matrPtr);
    int input_From_File(userMatrix* matrPtr);
    void input_Randomly(userMatrix* matrPtr);
    int user_Int_Input();
};

namespace output {
    void output_unsorted_Matrix(userMatrix * matrPtr);
    void save_Unsorted_Matrix_To_File(userMatrix* matrPtr);
    void module_Tests();
    void save_Results_To_File(userMatrix* matrPtr, int* compareBubblePtr, int* compareSelectPtr, int* compareInsertPtr, int* compareShellPtr, int* compareQuickPtr);
}

enum choicesInFirstMenu { manually = 1, randomly, fromFile, endProgramm };
enum yesOrNo { yes = 1, no };
enum choicesInScndMenu { outputList = 1, newData, tests, exitFromProgramm };
enum fileCatcher { error = 0, allGood };