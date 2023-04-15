#include "Algorithms.h"
#include "Sorts.h"
#include "User_Interface.h"

void greeting() {
	setlocale(LC_ALL, "Russian");
	int userChoice;
	int errorCatcher;
	bool loopMenuFirst = true;
	bool loopMenuScnd = true;
	bool loopMenuGeneral = true;
	bool loopMenuSavingData = false;
	userMatrix matrix;
	userMatrix* matrixPtr = &matrix;
	bubbleSort bubbleMatrix;
	selectionSort selectionMatrix;
	insertSort insertMatrix;
	shellsSort shellMatrix;
	quickSort quickMatrix;
	int compareBuble[2];
	int* compareBubblePtr = compareBuble;
	int compareSelect[2];
	int* compareSelectPtr = compareSelect;
	int compareInsert[2];
	int* compareInsertPtr = compareInsert;
	int compareShell[2];
	int* compareShellPtr = compareShell;
	int compareQuick[2];
	int* compareQuickPtr = compareQuick;
	std::cout << "Выполнила Науменко Юлия, 415а группа. Лабораторная работа #3, вариант #16. \nПрограмма сортирует введённую пользователем матрицу пятью сортировками: пузырьковой, быстрой, вставкой, Шелла, отбора." <<
		std::endl << "Программа выводит изначальную матрицу, после матрицу, отсортированную каждой сортировкой, а также таблицу эффективности каждой сортировки. Сортируются каждая нечётная строка матрицы по возрастанию суммы цифр каждого числа в строчке."
		<< std::endl << std::endl;

	while (loopMenuGeneral) {
		while (loopMenuFirst) {
			std::cout << "Выберите способ ввода данных:" << std::endl;
			std::cout << "1)  Вручную; \n2) Заполнить случайными числами; \n3) Загрузить из файла; \n4) Выйти из программы.\n\n";
			userChoice = input::user_Int_Input();
			switch (userChoice) {
			case manually:
				input::input_From_Console(matrixPtr);
				loopMenuFirst = false;
				break;
			case randomly:
				input::input_Randomly(matrixPtr);
				loopMenuFirst = false;
				break;
			case fromFile:
				errorCatcher = input::input_From_File(matrixPtr);
				if (errorCatcher == error)
					std::cout << "Ошибка в файле, попробуйте снова." << std::endl;
				else loopMenuFirst = false;
				break;
			case endProgramm:
				loopMenuFirst = false;
				loopMenuScnd = false;
				loopMenuGeneral = false;
				break;
			default:
				std::cout << "Такого пункта нет, попробуйте ввести существующий пункт." << std::endl;
				loopMenuFirst = true;
				break;
			}
		}

		loopMenuSavingData = true;
		while (loopMenuSavingData) {
			std::cout << "Хотите сохранить введённые данные? \n 1) Да; \n 2) Нет." << std::endl << std::endl;
			userChoice = input::user_Int_Input();
			switch (userChoice) {
			case yes: output::save_Unsorted_Matrix_To_File(matrixPtr);
				loopMenuSavingData = false;
				break;
			case no: loopMenuSavingData = false;
				break;
			default:
				std::cout << "Такого пункта нет, попробуйте ввести существующий пункт." << std::endl;
				break;
			}
		}
		loopMenuScnd = true;
		while (loopMenuScnd) {
			std::cout << "Что дальше?\n1) Вывести отсортированные матрицы и таблицу эффективности;" 
			<< std::endl << 
			"2) Начать заново; \n3) Пройти модульные тесты; \n4) Выйти отсюда." << std::endl;
			std::cout << "Ваш выбор: ";
			userChoice = input::user_Int_Input();
			std::cout << std::endl;

			switch (userChoice) {
			case outputList:

				output::output_unsorted_Matrix(matrixPtr);
				bubbleMatrix.sort(matrixPtr, compareBubblePtr);
				shellMatrix.sort(matrixPtr, compareShellPtr);
				selectionMatrix.sort(matrixPtr, compareSelectPtr);
				insertMatrix.sort(matrixPtr, compareInsertPtr);
				quickMatrix.sort(matrixPtr, compareQuickPtr);

				loopMenuScnd = true;
				loopMenuGeneral = true;

				std::cout << "Сортировка пузырьком:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "Количество сравнений: ";
				std::cout << compareBubblePtr[0] << '|';
				std::cout << "Количество перестановок: ";
				std::cout << compareBubblePtr[1] << '|';
				std::cout << std::endl;

				std::cout << "Сортировка выбором:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "Количество сравнений: ";
				std::cout << compareSelectPtr[0] << '|';
				std::cout << "Количество перестановок: ";
				std::cout << compareSelectPtr[1] << '|';
				std::cout << std::endl;

				std::cout << "Сортировка вставками:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "Количество сравнений: ";
				std::cout << compareInsertPtr[0] << '|';
				std::cout << "Количество перестановок: ";
				std::cout << compareInsertPtr[1] << '|';
				std::cout << std::endl;

				std::cout << "Сортировка Шелла:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "Количество сравнений: ";
				std::cout << compareShellPtr[0] << '|';
				std::cout << "Количество перестановок: ";
				std::cout << compareShellPtr[1] << '|';
				std::cout << std::endl;

				std::cout << "Быстрая сортировка:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "Количество сравнений: ";
				std::cout << compareQuickPtr[0] << '|';
				std::cout << "Количество перестановок: ";
				std::cout << compareQuickPtr[1] << '|';
				std::cout << std::endl;

				std::cout << "Сохранить получившуюся после сортировок матрицу и таблицу эффективности в файл?" << std::endl << " 1)Да" << std::endl << " 2)Нет" << std::endl << "Ваш выбор:";
				userChoice = input::user_Int_Input();
				loopMenuSavingData = true;
				while(loopMenuSavingData) {
					switch (userChoice) {
					case yes:
						output::save_Results_To_File(matrixPtr, compareBubblePtr, compareSelectPtr, compareInsertPtr, compareShellPtr, compareQuickPtr);
						loopMenuSavingData = false;
						break;
					case no:
						loopMenuSavingData = false;
						break;
					default:
						std::cout << "\nТакого пункта нет, попробуйте ввести существующий пункт.\n";
						break;
					}
				}
				break;
			case newData:
				loopMenuFirst = true;
				loopMenuScnd = false;
				loopMenuGeneral = true;
				break;
			case tests:
				output::module_Tests();
				loopMenuScnd = true;
				loopMenuGeneral = true;
				break;
			case exitFromProgramm:
				loopMenuScnd = false;
				loopMenuGeneral = false;
				break;
			default:
				std::cout << "\nТакого пункта нет, попробуйте ввести существующий пункт.\n";
				break;
			}
		}
	}
}