#include "box.h"

bool operator==(const Box& box1, const Box& box2) {
	return box1.getLength() == box2.getLength() &&
		box1.getWidth() == box2.getWidth() &&
		box1.getHeight() == box2.getHeight() &&
		box1.getWeight() == box2.getWeight() &&
		box1.getValue() == box2.getValue();
}

std::ostream& operator<<(std::ostream& o, const Box& box) {
	o << "        �����: " << box.getLength() << " ��" <<
		",\n        ������: " << box.getWidth() << " ��" <<
		",\n        ������: " << box.getHeight() << " ��" <<
		",\n        �����: " << box.getWeight() << " ��" <<
		",\n        ���������: " << box.getValue() << " ������";
	return o;
}

std::istream& operator>>(std::istream& i, Box& box) {
	int temp1;
	double temp2;
	std::cout << "������� ����� ������� � ��: ";
	i >> temp1;
	box.setLength(temp1);
	std::cout << "������� ������ ������� � ��: ";
	i >> temp1;
	box.setWidth(temp1);
	std::cout << "������� ������ ������� � ��: ";
	i >> temp1;
	box.setHeight(temp1);
	std::cout << "������� ����� ������� � ��: ";
	i >> temp2;
	box.setWeight(temp2);
	std::cout << "������� ��������� ����������� � ��������: ";
	i >> temp1;
	box.setValue(temp1);
	return i;
}