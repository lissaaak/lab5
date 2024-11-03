#include "Header.h" 


void SortByName(std::vector<Student>& students) { //���������� ��������� �� �����

    std::sort(students.begin(), students.end(), //��������� �������� � ��������� �� ������ �� �����
        [](const Student& a, const Student& b) {
            return a.Name < b.Name; //���� ������� a ������ �������� b, �� ���������� True � ������� a ���� ������ b
        });
}


void PrintStudents(const std::vector<Student>& students) {  //����� ������ ��������� �� �����

    for (const auto& student : students)
    {
        std::cout << "Name: " << student.Name << ", Group: " << student.GroupId << '\n';
    }
}


float Srednee(const Student& student) {
    int k = student.Ratings.size(); //���-�� ������ ��������
    float sum = 0; // ����� ������
    for (int i = 0; i < k; ++i) {
        sum += student.Ratings[i];
    }
    return sum / k; // ���������� ������� �������������� 
}


void SortByRating(std::vector<Student>& students) {  //���������� ��������� �� ������� ������
    std::sort(students.begin(), students.end(), //��������� �� ������ �� �����
        [](const Student& a, const Student& b) {
            return Srednee(a) < Srednee(b); // ���� ������� ������ a ������ ������� ������ b, �� ������� a ���� � ������ ������
        });
}




bool Neyd(const Student& student) {  //���� �� � �������� ����
    int k = student.Ratings.size();//���-�� ������
    for (int i = 0; i < k; ++i) {
        if ((student.Ratings[i] == 2) or (student.Ratings[i] == 1) or (student.Ratings[i] == 0)) {
            return true;
        }
    }
    return false;
}

size_t CountTwoness(const std::vector<Student>& students) {  //������� ���-�� ��������� � �������������������� �������
    int k = 0;
    for (const auto& student : students) { //������������� ������� �������� � ���� ���-�� ����� ���� ��������� 1
        if (Neyd(student)) {
            k++;
        }
    }
    return k;
}



bool Otl(const Student& student) { //���� �� � �������� ��� 5
    int k = student.Ratings.size(); //���-�� ������
    int l = 0; //���-�� 5
    for (int i = 0; i < k; ++i) {
        if (student.Ratings[i] == 5) {
            l += 1;
        }
    }
    if (l == k) { // ���� �����, �� ��� �������� ����� �� ������� 
        return true;
    }
    return false;
}



size_t CountExcellent(const std::vector<Student>& students) {//������� ���������, ������� ��� �������� �� 5
    int k = 0;
    for (const auto& student : students) {
        if (Otl(student)) {
            k++;
        }
    }
    return k;
}


bool OtlMath(const Student& student) { // ���� �� 5 �� �������� math
    int k = student.Ratings.size(); //���-�� ������
    int l = student.Subjects.size(); //���-�� ���������
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (student.Subjects[j] == "Math" and student.Ratings[i] == 5) {
                return true;
            }
        }
    }
    return false;
}



std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) { //�������� ������� ���������, ������� "�������" �� �������� math
    std::vector<Student> r;
    for (const auto& student : students) {
        if (OtlMath(student)) {
            r.push_back(student);
        }
    }
    return r;
}




std::vector<std::string> GroupsId(const std::vector<Student>& students) { //��������� ������� ���������� �������� �����
    std::set<std::string> r; //������� ������ ���������� ��������

    for (const auto& student : students) {
        r.insert(student.GroupId); //��������� �������� ���� ����� ��� ����������
    }
    std::vector<std::string> v(r.begin(), r.end()); //��������� �������� � ������

    return v;
}




int main() {
    std::vector<Student> students = {
        {"Charlie", "Group1", {4, 5, 5}, {"Physics", "Math", "Chemistry"}},
        {"Bob", "Group2", {2, 3, 4}, {"Math", "Biology", "Chemistry"}},
        {"Alice", "Group1", { 5, 5, 5 }, { "Math", "Physics", "Chemistry"}},
        {"Dave", "Group3", {2, 3, 4}, {"Math", "Chemistry", "Biology"}}
    };


    PrintStudents(students);

    SortByName(students);

    PrintStudents(students);

    SortByRating(students);

    PrintStudents(students);

    std:: cout << CountTwoness(students) << std:: endl;

    std::cout << CountExcellent(students);




    return 0;
}