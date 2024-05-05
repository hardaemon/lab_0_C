#include <iostream>
#include <vector>
//15
namespace bc {
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
	class Container {
		std::vector<Box> boxs; // коробки
		int containerLength;  // длина контейнера в см
		int containerWidth;   // ширина контейнера в см
		int containerHeight;  // высота контейнера в см
		double weightLimit;   // ограничение на максимальный вес

	public:
		Container(int containerLength, int containerWidth, int containerHeight, double weightLimit) {
			this->containerLength = containerLength;
			this->containerWidth = containerWidth;
			this->containerHeight = containerHeight;
			this->weightLimit = weightLimit;
		}
		int getContainerLength() const { return containerLength; }
		int getContainerWidth() const { return containerWidth; }
		int getContainerHeight() const { return containerHeight; }
		double getWeightLimit() const { return weightLimit; }
		void setContainerLength(int containerLength) { this->containerLength = containerLength; }
		void setContainerWidth(int containerWidth) { this->containerWidth = containerWidth; }
		void setContainerHeight(int containerHeight) { this->containerHeight = containerHeight; }
		void setWeightLimit(double weightLimit) { this->weightLimit = weightLimit; }
		int size() const;
		double sumWeight();
		int sumValue();
		Box index(size_t in);
		int add(Box& box);
		void del(size_t in);
		Box& operator[](size_t in);
	};
}