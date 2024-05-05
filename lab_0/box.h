#pragma once
#include <iostream>
//1
class Box {
	int length; //длина коробки в см
	int width; //ширина коробки в см
	int height; //высота коробки в см
	double weight; //масса коробки в кг
	int value; //стоимость содержимого в копейках

public:
	Box() = default;
	Box(int length, int width, int height, double weight, int value) { //конструктор
		this->length = length;
		this->width = width;
		this->height = height;
		this->weight = weight;
		this->value = value;
	}
	int getLength() const { return length; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	double getWeight() const { return weight; }
	int getValue() const { return value; }
	void setLength(int length) { this->length = length; }
	void setWidth(int width) { this->width = width; }
	void setHeight(int height) { this->height = height; }
	void setWeight(double weight) { this->weight = weight; }
	void setValue(int value) { this->value = value; }
};

bool operator==(const Box& box1, const Box& box2);
std::ostream& operator<<(std::ostream& o, const Box& box);
std::istream& operator>>(std::istream& i, Box& box);