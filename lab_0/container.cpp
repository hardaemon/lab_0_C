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
    if (boxes.empty()) { throw CustomException("��������� ����"); }
    else if (in > boxes.size()) { throw CustomException("������ ������� ���"); }
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
        throw CustomException("������������ ���������� �� ����");
    }
    return Container::size(); //������ ������� = ��������� ������� = ����������� �������
}
void Container::del(size_t in) {
    if (boxes.empty()) { throw CustomException("��������� ����"); }
    else if (in > boxes.size()) { throw CustomException("������ ������� ���"); }
    else {
        boxes.erase(boxes.begin() + in);
    }
}
std::ostream& operator<<(std::ostream& o, const Container& cont) {
    o << "        �����: " << cont.getContainerLength() << " ��" <<
        ",\n        ������: " << cont.getContainerWidth() << " ��" <<
        ",\n        ������: " << cont.getContainerHeight() << " ��" <<
        ",\n        ����������� �� ����: " << cont.getWeightLimit() << " ��";
    return o;
}
std::istream& operator>>(std::istream& i, Container& cont) {
    int temp1;
    double temp2;
    std::cout << "������� ����� ���������� � ��: ";
    i >> temp1;
    cont.setContainerLength(temp1);
    std::cout << "������� ������ ���������� � ��: ";
    i >> temp1;
    cont.setContainerWidth(temp1);
    std::cout << "������� ������ ���������� � ��: ";
    i >> temp1;
    cont.setContainerHeight(temp1);
    std::cout << "������� ����������� �� ���� � ��: ";
    i >> temp2;
    cont.setWeightLimit(temp2);
    return i;
}
Box& Container::operator[](size_t in) {
    if (boxes.empty()) { throw CustomException("��������� ����"); }
    else if (in > boxes.size()) { throw CustomException("������ ������� ���"); }
    else { return boxes[in]; }
}