#include "Header.h" 


void SortByName(std::vector<Student>& students) { //сортировка студентов по имени

    std::sort(students.begin(), students.end(), //сортируем элементы в диапазоне от начала до конца
        [](const Student& a, const Student& b) {
            return a.Name < b.Name; //если элемент a меньше элемента b, то возвращаем True и элемент a идет вперед b
        });
}


void PrintStudents(const std::vector<Student>& students) {  //вывод списка студентов на экран

    for (const auto& student : students)
    {
        std::cout << "Name: " << student.Name << ", Group: " << student.GroupId << '\n';
    }
}


float Srednee(const Student& student) {
    int k = student.Ratings.size(); //кол-во оценок студента
    float sum = 0; // сумма оценок
    for (int i = 0; i < k; ++i) {
        sum += student.Ratings[i];
    }
    return sum / k; // возвращаем среднее арифметическое 
}


void SortByRating(std::vector<Student>& students) {  //сортировка студентов по средней оценке
    std::sort(students.begin(), students.end(), //сортируем от начала до конца
        [](const Student& a, const Student& b) {
            return Srednee(a) < Srednee(b); // если средн€€ оценка a меньше средней оценки b, то студент a идет в начало списка
        });
}




bool Neyd(const Student& student) {  //есть ли у студента неуд
    int k = student.Ratings.size();//кол-во оценок
    for (int i = 0; i < k; ++i) {
        if ((student.Ratings[i] == 2) or (student.Ratings[i] == 1) or (student.Ratings[i] == 0)) {
            return true;
        }
    }
    return false;
}

size_t CountTwoness(const std::vector<Student>& students) {  //подсчет кол-ва студентов с неудовлетворительной оценкой
    int k = 0;
    for (const auto& student : students) { //рассматриваем каждого студента и если кто-то имеет неуд добавл€ем 1
        if (Neyd(student)) {
            k++;
        }
    }
    return k;
}



bool Otl(const Student& student) { //есть ли у студента все 5
    int k = student.Ratings.size(); //кол-во оценок
    int l = 0; //кол-во 5
    for (int i = 0; i < k; ++i) {
        if (student.Ratings[i] == 5) {
            l += 1;
        }
    }
    if (l == k) { // если равны, то все экзамены сданы на отлично 
        return true;
    }
    return false;
}



size_t CountExcellent(const std::vector<Student>& students) {//подсчет студентов, сдавших все экзамены на 5
    int k = 0;
    for (const auto& student : students) {
        if (Otl(student)) {
            k++;
        }
    }
    return k;
}


bool OtlMath(const Student& student) { // есть ли 5 по предмету math
    int k = student.Ratings.size(); //кол-во оценок
    int l = student.Subjects.size(); //кол-во предметов
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (student.Subjects[j] == "Math" and student.Ratings[i] == 5) {
                return true;
            }
        }
    }
    return false;
}



std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) { //создание вектора студентов, имеющих "отлично" по предмету math
    std::vector<Student> r;
    for (const auto& student : students) {
        if (OtlMath(student)) {
            r.push_back(student);
        }
    }
    return r;
}




std::vector<std::string> GroupsId(const std::vector<Student>& students) { //получение массива уникальных названий групп
    std::set<std::string> r; //создаем вектор уникальных значений

    for (const auto& student : students) {
        r.insert(student.GroupId); //добавл€ем названи€ всех групп без повторений
    }
    std::vector<std::string> v(r.begin(), r.end()); //переносим значени€ в вектор

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