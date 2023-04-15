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
	std::cout << "��������� �������� ����, 415� ������. ������������ ������ #3, ������� #16. \n��������� ��������� �������� ������������� ������� ����� ������������: �����������, �������, ��������, �����, ������." <<
		std::endl << "��������� ������� ����������� �������, ����� �������, ��������������� ������ �����������, � ����� ������� ������������� ������ ����������. ����������� ������ �������� ������ ������� �� ����������� ����� ���� ������� ����� � �������."
		<< std::endl << std::endl;

	while (loopMenuGeneral) {
		while (loopMenuFirst) {
			std::cout << "�������� ������ ����� ������:" << std::endl;
			std::cout << "1)  �������; \n2) ��������� ���������� �������; \n3) ��������� �� �����; \n4) ����� �� ���������.\n\n";
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
					std::cout << "������ � �����, ���������� �����." << std::endl;
				else loopMenuFirst = false;
				break;
			case endProgramm:
				loopMenuFirst = false;
				loopMenuScnd = false;
				loopMenuGeneral = false;
				break;
			default:
				std::cout << "������ ������ ���, ���������� ������ ������������ �����." << std::endl;
				loopMenuFirst = true;
				break;
			}
		}

		loopMenuSavingData = true;
		while (loopMenuSavingData) {
			std::cout << "������ ��������� �������� ������? \n 1) ��; \n 2) ���." << std::endl << std::endl;
			userChoice = input::user_Int_Input();
			switch (userChoice) {
			case yes: output::save_Unsorted_Matrix_To_File(matrixPtr);
				loopMenuSavingData = false;
				break;
			case no: loopMenuSavingData = false;
				break;
			default:
				std::cout << "������ ������ ���, ���������� ������ ������������ �����." << std::endl;
				break;
			}
		}
		loopMenuScnd = true;
		while (loopMenuScnd) {
			std::cout << "��� ������?\n1) ������� ��������������� ������� � ������� �������������;" 
			<< std::endl << 
			"2) ������ ������; \n3) ������ ��������� �����; \n4) ����� ������." << std::endl;
			std::cout << "��� �����: ";
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

				std::cout << "���������� ���������:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "���������� ���������: ";
				std::cout << compareBubblePtr[0] << '|';
				std::cout << "���������� ������������: ";
				std::cout << compareBubblePtr[1] << '|';
				std::cout << std::endl;

				std::cout << "���������� �������:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "���������� ���������: ";
				std::cout << compareSelectPtr[0] << '|';
				std::cout << "���������� ������������: ";
				std::cout << compareSelectPtr[1] << '|';
				std::cout << std::endl;

				std::cout << "���������� ���������:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "���������� ���������: ";
				std::cout << compareInsertPtr[0] << '|';
				std::cout << "���������� ������������: ";
				std::cout << compareInsertPtr[1] << '|';
				std::cout << std::endl;

				std::cout << "���������� �����:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "���������� ���������: ";
				std::cout << compareShellPtr[0] << '|';
				std::cout << "���������� ������������: ";
				std::cout << compareShellPtr[1] << '|';
				std::cout << std::endl;

				std::cout << "������� ����������:";
				std::cout << std::endl;
				std::cout << '|';
				std::cout << "���������� ���������: ";
				std::cout << compareQuickPtr[0] << '|';
				std::cout << "���������� ������������: ";
				std::cout << compareQuickPtr[1] << '|';
				std::cout << std::endl;

				std::cout << "��������� ������������ ����� ���������� ������� � ������� ������������� � ����?" << std::endl << " 1)��" << std::endl << " 2)���" << std::endl << "��� �����:";
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
						std::cout << "\n������ ������ ���, ���������� ������ ������������ �����.\n";
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
				std::cout << "\n������ ������ ���, ���������� ������ ������������ �����.\n";
				break;
			}
		}
	}
}