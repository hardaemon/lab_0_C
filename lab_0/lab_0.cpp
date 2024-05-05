#include <iostream>
#include "container.h"

//2
int Sum(Box* box, const int size) {
	int count = 0;
	for (int i = 0; i < size; ++i) {
		count += box[i].getValue();
	}
	return count;
};
//3
bool NoMore(Box* box, const int size, int& max) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += box[i].getLength() + box[i].getWidth() + box[i].getHeight();
	}
	if (sum <= max) { return true; }
	else { return false; }
}
//4
double MaxWeight(Box* box, const int size, int& maxV) {
	double weightAll = 0;
	for (int i = 0; i < size; ++i) {
		if (box[i].getLength() * box[i].getWidth() * box[i].getHeight() <= maxV) {
			if (box[i].getWeight() > weightAll) {
				weightAll = box[i].getWeight();
			}
		}
	}
	return weightAll;
}
//5
bool Sort(Box* box, const int size) {
	int* temp = new int[3]; //создаем временный массив для сортировки
	Box* copyBox = new Box[size]; //создаем пустой массив-копию
	int boxLength;
	int boxWidth;
	int boxHeight;
	for (int i = 0; i < size; ++i) { //копируем массив, чтобы работать с ним
		boxLength = box[i].getLength();
		copyBox[i].setLength(boxLength);
		boxWidth = box[i].getWidth();
		copyBox[i].setWidth(boxWidth);
		boxHeight = box[i].getHeight();
		copyBox[i].setHeight(boxHeight);
	}
	//bubble sort
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (copyBox[j].getLength() > copyBox[j + 1].getLength() &&
				copyBox[j].getWidth() > copyBox[j + 1].getWidth() &&
				copyBox[j].getHeight() > copyBox[j + 1].getHeight()) {
				temp[0] = copyBox[j].getLength();
				temp[1] = copyBox[j].getWidth();
				temp[2] = copyBox[j].getHeight();
				boxLength = copyBox[j + 1].getLength();
				copyBox[j].setLength(boxLength);
				boxWidth = copyBox[j + 1].getWidth();
				copyBox[j].setWidth(boxWidth);
				boxHeight = copyBox[j + 1].getHeight();
				copyBox[j].setHeight(boxHeight);
				copyBox[j + 1].setLength(temp[0]);
				copyBox[j + 1].setWidth(temp[1]);
				copyBox[j + 1].setHeight(temp[2]);
			}
		}
	}
	delete[] temp;
	//проверяем на вместимость
	for (int i = 0; i < size - 1; ++i) {
		if (copyBox[i].getLength() >= copyBox[i + 1].getLength() ||
			copyBox[i].getWidth() >= copyBox[i + 1].getWidth() ||
			copyBox[i].getHeight() >= copyBox[i + 1].getHeight()) {
			delete[] copyBox;
			return false;
		}
	}
	delete[] copyBox;
	return true;
}

int main() {
	setlocale(LC_ALL, "RUS");
	//2
	int length1 = 20;
	int width1 = 25;
	int height1 = 55;
	//volume = 27500
	double weight1 = 200.7;
	int value1 = 2500;
	Box box1(length1, width1, height1, weight1, value1);
	int length2 = 44;
	int width2 = 26;
	int height2 = 30;
	//volume = 34320
	double weight2 = 437.1;
	int value2 = 5000;
	Box box2(length2, width2, height2, weight2, value2);
	const int size_2 = 2;
	Box* arr1 = new Box[size_2];
	arr1[0] = box1;
	arr1[1] = box2;
	int result2 = Sum(arr1, size_2);
	if (result2 == 7500) {
		std::cout << "Test 2 - true" << std::endl << std::endl;
	}
	else {
		std::cout << "Test 2 - false" << std::endl << std::endl;
	}
	//3
	int max = 200;
	bool result3 = NoMore(arr1, size_2, max);
	if (result3) {
		std::cout << "Test 3 - true" << std::endl << std::endl;
	}
	else {
		std::cout << "Test 3 - false" << std::endl << std::endl;
	}
	//4
	int maxV = 35000;
	double result4 = MaxWeight(arr1, size_2, maxV);
	if (abs(result4 - 437.1) < 0.0000001) {
		std::cout << "Test 4 - true" << std::endl << std::endl;
	}
	else {
		std::cout << "Test 4 - false" << std::endl << std::endl;
	}
	delete[] arr1;
	//5
	int length3 = 58;
	int width3 = 84;
	int height3 = 63;
	double weight3 = 234.7;
	int value3 = 10000;
	Box box3(length3, width3, height3, weight3, value3);
	const int size_3 = 3;
	Box* arr2_1 = new Box[size_3];
	arr2_1[0] = box1;
	arr2_1[1] = box2;
	arr2_1[2] = box3;
	bool result5_1 = Sort(arr2_1, size_3);
	if (!result5_1) {
		std::cout << "Test 5.1 - true (проверка на невозможность)" << std::endl;
	}
	else {
		std::cout << "Test 5.1 - false (проверка на невозможность)" << std::endl;
	}
	Box* arr2_2 = new Box[size_2];
	arr2_2[0] = box1;
	arr2_2[1] = box3;
	bool result5_2 = Sort(arr2_2, size_2);
	if (result5_2) {
		std::cout << "Test 5.2 - true (проверка на возможность)" << std::endl << std::endl;
	}
	else {
		std::cout << "Test 5.2 - false (проверка на возможность)" << std::endl << std::endl;
	}
	delete[] arr2_1;
	delete[] arr2_2;
	//6
	int length4 = 20;
	int width4 = 25;
	int height4 = 55;
	double weight4 = 200.7;
	int value4 = 2500;
	Box box4(length4, width4, height4, weight4, value4);
	Box* arr3 = new Box[size_2];
	arr3[0] = box1;
	arr3[1] = box4;
	bool result6 = box1 == box4;
	if (result6) {
		std::cout << "Test 6 - true" << std::endl << std::endl;
	}
	else {
		std::cout << "Test 6 - false" << std::endl << std::endl;
	}
	delete[] arr3;
	//7
	//Box b;
	//std::cout << "Test 7.2 (ввод)" << std::endl;
	//std::cin >> b;
	//std::cout << "Успешный ввод" << std::endl << std::endl;
	//std::cout << "Test 7.1 (вывод)" << std::endl;
	//std::cout << b << std::endl;
	//std::cout << "Успешный вывод" << std::endl << std::endl;
	//Box box12;
	//std::cin >> box12;
	//std::cout << box12 << std::endl;
	//11
	Container cont(3, 3, 3, 1000);
	Box box11(1, 1, 1, 100, 50);
	try {
		//добавление коробки
		cont.add(box11);
		cont.add(box11);
		std::cout << "11. Коробки добавлены" << std::endl; //в векторе 2 коробки
		Box box11_1(1, 2, 3, 1000, 50);
		std::cout << "11. Проверка на переполнение по весу, должно быть исключение" << std::endl;
		cont.add(box11_1);
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	try {
		//удаление коробки
		cont.del(1);
		std::cout << "11. Коробка удалена" << std::endl; //в векторе 1 коробка
		std::cout << "11. Проверка на индекс, должно быть исключение" << std::endl;
		cont.del(3);
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	try {
		cont.del(0); //теперь вектор пустой
		std::cout << "11. Проверка на пустоту, должно быть исключение" << std::endl;
		cont.del(1);
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	try {
		//получение коробки по индексу
		std::cout << "11. Проверка на пустоту, должно быть исключение" << std::endl;
		std::cout << cont.index(0).getWeight() << " - масса коробки (проверка на получение коробки по индексу)" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	try {
		cont.add(box11); // в векторе 1 коробка
		std::cout << "11. Проверка на индекс, должно быть исключение" << std::endl;
		std::cout << cont.index(4).getWeight() << " - масса коробки (проверка на получение коробки по индексу)" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	try {
		cont.add(box11); //в векторе 2 коробки
		std::cout << cont.index(0).getWeight() << " - масса коробки (проверка на получение коробки по индексу)" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	//количество коробок
	if (cont.size() == 2) {
		std::cout << "11. Тест на кол-во коробок пройден" << std::endl;
	}
	else {
		std::cout << "11. Тест на кол-во коробок не пройден" << std::endl;
	}
	//суммарная стоимость
	if (cont.sumValue() == 100) {
		std::cout << "11. Тест на суммарную стоимость коробок пройден" << std::endl;
	}
	else {
		std::cout << "11. Тест на суммарную стоимость коробок не пройден" << std::endl;
	}
	//суммарный вес
	if (abs(cont.sumWeight() - 200) < 0.0000001) {

		std::cout << "11. Тест на суммарный вес коробок пройден" << std::endl;
	}
	else {
		std::cout << "11. Тест на суммарный вес коробок не пройден" << std::endl;
	}
	//12
	std::cout << std::endl;
	std::cin >> cont;
	std::cout << "12. Успешный ввод" << std::endl;
	std::cout << cont << std::endl;
	std::cout << "12. Успешный вывод" << std::endl;
	std::cout << cont << std::endl;
	try {
		cont.del(1);
		cont.del(0); //теперь нет коробок
		std::cout << "13. Проверка на пустоту, должно быть исключение" << std::endl;
		std::cout << cont[0].getWeight() << " - масса коробки (проверка на получение коробки по индексу)" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	try {
		cont.add(box11);
		std::cout << "13. Проверка на индекс, должно быть исключение" << std::endl;
		std::cout << cont[5].getWeight() << " - масса коробки (проверка на получение коробки по индексу)" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	std::cout << cont[0].getWeight() << " - масса коробки (проверка на получение коробки по индексу)" << std::endl;
};