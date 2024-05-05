#pragma once
#include <iostream>
#include <vector>
#include "box.h"
// 10
class CustomException : public std::exception {
    std::string errorMessage;
public:
    //  онструктор класса исключени€
    CustomException(const std::string& message) : errorMessage(message) {}
    // ѕереопределение метода what() дл€ возврата описани€ ошибки
    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};
class Container {
    std::vector<Box> boxes; // коробки
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
std::ostream& operator<<(std::ostream& o, const Container& cont);
std::istream& operator>>(std::istream& i, Container& cont);