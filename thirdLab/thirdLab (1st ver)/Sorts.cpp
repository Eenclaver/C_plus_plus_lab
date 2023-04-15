#include "Sorts.h"

using namespace std;

void bubbleSort::sort(userMatrix *matrPtr, int* comparisons) {
	int comparisonsCounter = 0;
	int shiftsCounter = 0;
	
	int amountOfRows = matrPtr->amountOfRows;
	int amountOfColumns = matrPtr->amountOfColumns;
	vector<vector<int>> bubbleMatrix;
	vector<int> tmpVec; tmpVec.push_back(0); tmpVec.push_back(0);

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
	bool isWorking = true;
	while (isWorking) {
		for (int i = 0; i < bubbleMatrix.size(); i+=2)
		{
			for (int j = 0; j < bubbleMatrix[i].size() - 1; j++)
			{
				isWorking = false;
				comparisonsCounter += 1;
				if (bubbleMatrix[i][j] > bubbleMatrix[i][static_cast<_int64>(j) + static_cast<_int64>(1)]) {
					isWorking = true;
					shiftsCounter += 1;
					char copy = static_cast<char>(bubbleMatrix[i][j]);
					bubbleMatrix[i][j] = bubbleMatrix[i][static_cast<_int64>(j) + static_cast<_int64>(1)];
					bubbleMatrix[i][static_cast<_int64>(j) + static_cast<_int64>(1)] = copy;
				}
			}
		}
	}
	
	std::cout << "Матрица после пузырьковой сортировки:\n\n";
	for (int i = 0; i < amountOfRows; i++) {
		for (int j = 0; j < amountOfColumns; j++) {
			std::cout << bubbleMatrix[i][j] << " ";
		}
		std::cout << endl << endl;
	}
	comparisons[0] = comparisonsCounter;
	comparisons[1] = shiftsCounter;
}

std::vector<int> QuickRowSort(std::vector<int> vct, int first, int last, int* numOfComparsion, int* numOfPermutation) {
	int mid;
	int f = first, l = last;
	mid = vct[(f + l) / 2];
	while (f < l) {
		if (vct[f] < mid) {
			*numOfComparsion += 1;
			while (vct[f] < mid) {
				f++;
			}
		}
		else {
			*numOfComparsion += 1;
		}
		if (vct[l] > mid) {
			*numOfComparsion += 1;
			while (vct[l] > mid) {
				l--;
			}
		}
		else {
			*numOfComparsion += 1;
		}
		if (f <= l) {
			*numOfPermutation += 1;
			int tmp = vct[f];
			vct[f] = vct[l];
			vct[l] = tmp;
			f++;
			l--;
		}
	}
	if (first < l)QuickRowSort(vct, first, l, numOfComparsion, numOfPermutation);
	if (f > last) QuickRowSort(vct, f, last, numOfComparsion, numOfPermutation);
	return vct;
}

void quickSort::sort(userMatrix* matrPtr, int* comparisons) {
	int comparisonsCounter = 0;
	int shiftsCounter = 0;
	
	int rows = matrPtr->amountOfRows;
	int columns = matrPtr->amountOfColumns;
	vector<vector <int>> quickMatrix;
	vector<int> tmpVec; tmpVec.push_back(0); tmpVec.push_back(0);

	quickMatrix.resize(rows);
	for (int i = 0; i < rows; i++) {
		quickMatrix[i].resize(columns);
	}

	for (int i = 0; i < matrPtr->amountOfRows; i++) {
		for (int j = 0; j < matrPtr->amountOfColumns; j++) {
			quickMatrix[i][j] = matrPtr->get_Element(i, j);
		}
	}

	for (int i = 0; i < matrPtr->amountOfRows; i += 2) {
		quickMatrix[i] = QuickRowSort(quickMatrix[i], 0, static_cast<unsigned int>(quickMatrix[i].size() - 1), &comparisonsCounter, &shiftsCounter); }

	std::cout << "Матрица после быстрой сортировки:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << quickMatrix[i][j] << " ";
		}
		std::cout << endl << endl;
	}
	comparisons[0] = comparisonsCounter;
	comparisons[1] = shiftsCounter;

};

void insertSort::sort(userMatrix* matrPtr, int* comparisons) {
	int comparisonsCounter = 0;
	int shiftsCounter = 0;
	int rows = matrPtr->amountOfRows;
	int columns = matrPtr->amountOfColumns;
	vector <vector <int>> insertMatrix;
	vector <int> tmpVec; tmpVec.push_back(0); tmpVec.push_back(0);

	insertMatrix.resize(rows);
	for (int i = 0; i < rows; i++) {
		insertMatrix[i].resize(columns);
	}

	for (int i = 0; i < matrPtr->amountOfRows; i++) {
		for (int j = 0; j < matrPtr->amountOfColumns; j++) {
			insertMatrix[i][j] = matrPtr->get_Element(i, j);
		}
	}

	for (int i = 0; i < matrPtr->amountOfRows; i+=2)
	{
		for (int k = 0; k < matrPtr->amountOfColumns; k++)
		{
			for (unsigned int j = k; j > 0; j--) {
				comparisonsCounter += 1;
				if (insertMatrix[i][static_cast<unsigned int>(j) - static_cast<unsigned int>(1)] > insertMatrix[i][j]) {
					shiftsCounter += 1;
					swap(insertMatrix[i][static_cast<unsigned int>(j) - static_cast<unsigned int>(1)], insertMatrix[i][j]);
				}
			}
		}
	}

	std::cout << "Матрица после сортировки вставками:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << insertMatrix[i][j] << " ";
		}
		std::cout << endl << endl;
	}
	comparisons[0] = comparisonsCounter;
	comparisons[1] = shiftsCounter;
}

void selectionSort::sort(userMatrix* matrPtr, int* comparisons) {
	
	int comparisonsCounter = 0;
	int shiftsCounter = 0;
	int rows = matrPtr->amountOfRows;
	int columns = matrPtr->amountOfColumns;
	vector <vector <int>> selectionMatrix;
	vector <int> tmpVec; tmpVec.push_back(0); tmpVec.push_back(0);

	selectionMatrix.resize(rows);
	for (int i = 0; i < rows; i++) {
		selectionMatrix[i].resize(columns);
	}

	for (int i = 0; i < matrPtr->amountOfRows; i++) {
		for (int j = 0; j < matrPtr->amountOfColumns; j++) {
			selectionMatrix[i][j] = matrPtr->get_Element(i, j);
		}
	}

	for (int i = 0; i < matrPtr->amountOfRows; i+=2)
	{
		for (unsigned int k = 0; k < static_cast<unsigned int>(matrPtr->amountOfColumns); k++)
		{
			int pos = k;
			int min = selectionMatrix[i][pos];
			for (unsigned int j = k + 1; j <= static_cast<unsigned int>( matrPtr->amountOfColumns - 1); j++)
			{
				if (min > selectionMatrix[i][j])
				{
					comparisonsCounter += 1;
					min = selectionMatrix[i][j];
					pos = j;
				}
				else {
					comparisonsCounter += 1;
				}
			}
			if (static_cast<unsigned int>(pos) != k)
			{
				shiftsCounter += 1;
				swap(selectionMatrix[i][k], selectionMatrix[i][pos]);
			}
		}
	}

	std::cout << "Матрица после сортировки отбором:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << selectionMatrix[i][j] << " ";
		}
		std::cout << endl << endl;
	}
	comparisons[0] = comparisonsCounter;
	comparisons[1] = shiftsCounter;
}

void shellsSort::sort(userMatrix* matrPtr, int* comparisons) {
	
	int comparisonsCounter = 0;
	int shiftsCounter = 0;
	int rows = matrPtr->amountOfRows;
	int columns = matrPtr->amountOfColumns;
	vector <vector <int>> shellsMatrix;
	vector <int> tmpVec; tmpVec.push_back(0); tmpVec.push_back(0);

	shellsMatrix.resize(rows);
	for (int i = 0; i < rows; i++) {
		shellsMatrix[i].resize(columns);
	}

	for (int i = 0; i < matrPtr->amountOfRows; i++) {
		for (int j = 0; j < matrPtr->amountOfColumns; j++) {
			shellsMatrix[i][j] = matrPtr->get_Element(i, j);
		}
	}


	for (int k = 0; k < rows; k+=2)
	{
		int step = columns / 2;
		while (step > 0) {
			for (int i = 0; i < columns - step; i++) {
				int j = i;
				while (j >= 0)
				{
					if (shellsMatrix[k][j] > shellsMatrix[k][static_cast<_int64>(j) + static_cast<_int64>(step)]) {
						swap(shellsMatrix[k][j], shellsMatrix[k][static_cast<_int64>(j) + static_cast<_int64>(step)]);
						shiftsCounter += 1;
					}
					j--;
				}
				comparisonsCounter += 1;
			}
			step /= 2;
		}
	}

	std::cout << "Матрица после сортировки методом Шелла:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << shellsMatrix[i][j] << " ";
		}
		std::cout << endl << endl;
	}
	comparisons[0] = comparisonsCounter;
	comparisons[1] = shiftsCounter;
}

