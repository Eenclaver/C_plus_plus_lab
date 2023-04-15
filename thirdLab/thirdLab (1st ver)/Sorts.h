#pragma once
#include "Algorithms.h"

class iSort {
public:
	virtual void sort(userMatrix* matrPtr, int* comparisons) = 0;
};

class bubbleSort : public iSort {
public: void sort(userMatrix* matrPtr, int* comparisons) override;
};

class quickSort : public iSort {
public: 
	void sort(userMatrix* matrPtr, int* comparisons) override;
	void quick_Rows_Sort(std::vector<std::vector <int>> &array, size_t first, size_t last, int &comparisonsCounter, int &shiftsCounter);
};

class insertSort : public iSort {
public: void sort(userMatrix* matrPtr, int* comparisons) override;
};

class selectionSort : public iSort {
public: void sort(userMatrix* matrPtr, int* comparisons) override;
};

class shellsSort : public iSort {
public: void sort(userMatrix* matrPtr, int* comparisons) override;
};