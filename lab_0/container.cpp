#include "container.h"
//11
int Container::size() const { return boxes.size(); }
double Container::sumWeight() {
    double sum = 0;
    for (const Box& i : boxes) {
        sum += i.getWeight();
    }
    return sum;
}
int Container::sumValue() {
    double sum = 0;
    for (const Box& i : boxes) {
        sum += i.getValue();
    }
    return sum;
}
Box Container::index(size_t in) {
    if (boxes.empty()) { throw CustomException("Контейнер пуст"); }
    else if (in > boxes.size()) { throw CustomException("Такого индекса нет"); }
    else {
        Box result = boxes[in];
        return result;
    }
}
int Container::add(Box& box) {
    if (sumWeight() + box.getWeight() < weightLimit) {
        boxes.push_back(box);
    }
    else {
        throw CustomException("Переполнение контейнера по весу");
    }
    return Container::size(); //размер массива = последняя коробка = добавленная коробка
}
void Container::del(size_t in) {
    if (boxes.empty()) { throw CustomException("Контейнер пуст"); }
    else if (in > boxes.size()) { throw CustomException("Такого индекса нет"); }
    else {
        boxes.erase(boxes.begin() + in);
    }
}
std::ostream& operator<<(std::ostream& o, const Container& cont) {
    o << "        Длина: " << cont.getContainerLength() << " см" <<
        ",\n        Ширина: " << cont.getContainerWidth() << " см" <<
        ",\n        Высота: " << cont.getContainerHeight() << " см" <<
        ",\n        Ограничение по весу: " << cont.getWeightLimit() << " кг";
    return o;
}
std::istream& operator>>(std::istream& i, Container& cont) {
    int temp1;
    double temp2;
    std::cout << "Введите длину контейнера в см: ";
    i >> temp1;
    cont.setContainerLength(temp1);
    std::cout << "Введите ширину контейнера в см: ";
    i >> temp1;
    cont.setContainerWidth(temp1);
    std::cout << "Введите высоту контейнера в см: ";
    i >> temp1;
    cont.setContainerHeight(temp1);
    std::cout << "Введите ограничение по весу в кг: ";
    i >> temp2;
    cont.setWeightLimit(temp2);
    return i;
}
Box& Container::operator[](size_t in) {
    if (boxes.empty()) { throw CustomException("Контейнер пуст"); }
    else if (in > boxes.size()) { throw CustomException("Такого индекса нет"); }
    else { return boxes[in]; }
}