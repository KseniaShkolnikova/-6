
using namespace std;
#include <iostream>
#include <vector>;
#include <stdio.h>;
#include <string>;
vector <string> group = { "П50-1-22", "П50-2-22", "П50-3-22", "П50-4-22" };
vector <string> disciplinak = { "ОАИП","Системное программирование","Физра","Тестирование","ВЭБ" };

// ксюша
class teacher {
public:
    vector <string> group;
    string disciplina;
public:
    teacher teacher_constr(int disciplina_number, vector <string> group_number) {
        teacher teacher;
        for (int i = 0; i < group_number.size(); i++)
        {
            teacher.group.push_back(group_number[i]);
        }
        teacher.disciplina = disciplinak[disciplina_number - 1];
        return teacher;
    }
};
// ярик
bool is_number(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

class Student {
public:
    string group;
    int kolvo_sdanix_robot;
    int kolvo_dolgov;
    vector<string> disciplina;
public:
    Student stud(string group, vector<string> disciplin) {
        Student student;
        student.group = group;
        student.kolvo_dolgov = 0;
        student.kolvo_sdanix_robot = 0;
        for (int i = 0; i < disciplin.size(); i++)
        {
            student.disciplina.push_back(disciplin[i]);
        }
        return student;
    }
};

vector <teacher> vse_teacher;
vector<Student> vseStudent;
class MPT {
public:
    // ксюша
    teacher teacher_add() {
        bool result = false;
        while (result == false) {
            cout << " Выберите вашу дисциплину\n  1. ОАИП\n  2. Системное программирование\n  3. Физра\n  4. Тестирование\n  5. ВЭБ\n  6. Выйти" << endl;
            string disciplina_number;
            cin >> disciplina_number;
            vector <string> group_number;
            teacher teachers;
            teacher gg;            
            if (disciplina_number == "1" || disciplina_number == "2" || disciplina_number == "3" || disciplina_number == "4" || disciplina_number == "5") {
                while(result == false) {
                    cout << " Выберите группы в которых вы ведете\n  1. П50-1-22\n  2. П50-2-22 \n  3. П50-3-22\n  4. П50-4-22\n  5.Хватит" << endl;
                    string groupik;
                    cin >> groupik;
                    if (groupik == "1" || groupik == "2" || groupik == "3" || groupik == "4" || groupik == "5") {
                        if (groupik == "5") {
                            int disciplina_numbers = stoi(disciplina_number);
                            gg = teachers.teacher_constr(disciplina_numbers, group_number);
                            vse_teacher.push_back(gg);
                            result = true;
                        }
                        else {
                            int grupik = stoi(groupik);
                            if (group_number.size() != 0) {
                                bool res = false;
                                while (true) {
                                    for (int j = 0; j < group_number.size(); j++)
                                    {
                                        if (group_number[j] == group[grupik - 1]) {
                                            res = true;
                                            break;
                                        }
                                    }
                                    break;
                                }
                                if (res == true) {
                                    cout << "-----------------------------------------------------\n      Данная группа уже добавлена\n-----------------------------------------------------" << endl;
                                }
                                else if (res==false) {
                                    for (int i = 0; i < group.size(); i++)
                                    {
                                        if (grupik == i) {
                                            group_number.push_back(group[i - 1]);
                                            break;
                                        }
                                    }
                                    
                                }
                            }
                            else {
                                for (int i = 0; i < group.size(); i++)
                                {
                                    if (grupik == i) {
                                        group_number.push_back(group[i - 1]);
                                    }
                                }
                            }
                        }
                    }
                    else {
                        cout << "-----------------------------------------------------\n      Нужно вводить номер варианта ответа\n-----------------------------------------------------" << endl;
                    }
                }           
                return gg;
            }
            else if (disciplina_number == "6") {
                result = true;
            }
            else {
                cout << "-----------------------------------------------------\n      Нужно вводить номер варианта ответа\n-----------------------------------------------------" << endl;
            }
        }
    }
    // ксюша
    void see_teacher() {
        for (int teach = 0; teach < vse_teacher.size(); teach++) {
            cout << "\n-----------------------------------------------------\n";
            cout << "Дисциплина: " << vse_teacher[teach].disciplina << endl;
            cout << "Группы: " << endl;
            for (int i = 0; i < vse_teacher[teach].group.size(); i++) {
                cout << vse_teacher[teach].group[i] << endl;
            }           
        }
    }
    // ярик
    Student add_student() {
        cout << "Выберите группу студента: \n";
        for (int i = 0; i < group.size(); i++)
        {
            cout << i + 1 << ". " << group[i] << "\n";
        }
        string viborGroup;
        bool proberkaViborG = false;
        while (proberkaViborG == false)
        {
            cin >> viborGroup;
            bool proverka = is_number(viborGroup);
            if (proverka == true && stoi(viborGroup) <= group.size()) {
                break;
            }
            else
            {
                cout << "ЭТО НЕ ЧИСЛО или число слишком большое\n";
                cout << "Введити число: ";
            }
        }
        string groups = group[stoi(viborGroup) - 1];
        bool stop = false;
        vector<string> vibronDisciplin;
        while (stop == false)
        {
            for (int i = 0; i < disciplinak.size(); i++)
            {
                cout << i + 1 << ". " << disciplinak[i] << "\n";
            }
            cout << (disciplinak.size() + 1) << ". " << "Хватит\n";
            cout << "Введите цифру: ";
            string viborDiscip;
            bool proverkaViborD = false;
            while (proverkaViborD == false)
            {
                cin >> viborDiscip;
                bool proverka = is_number(viborDiscip);
                if (proverka == true && stoi(viborDiscip) <= disciplinak.size() + 1) {
                    break;
                }
                else
                {
                    cout << "ЭТО НЕ ЧИСЛО или число слишком большое\n";
                    cout << "Введити число: ";
                }
            }
            if (stoi(viborDiscip) != disciplinak.size() + 1)
            {
                vibronDisciplin.push_back(disciplinak[stoi(viborDiscip) - 1]);
                disciplinak.erase(disciplinak.begin() + stoi(viborDiscip) - 1);
            }
            else {
                stop = true;
            }
        }
        Student stud;
        stud = stud.stud(groups, vibronDisciplin);
        vseStudent.push_back(stud);
        return stud;
    }
    void ProsmatrivatStud() {
        for (int student = 0; student < vseStudent.size(); student++)
        {
            cout << "-----------------------------------------------------\n";
            cout << "Группа: " << vseStudent[student].group << "\n";
            cout << "Дисциплины: " << "\n";
            for (size_t i = 0; i < vseStudent[student].disciplina.size(); i++)
            {
                cout << vseStudent[student].disciplina[i] << "\n";
            }
            cout << "Количество долгов: " << vseStudent[student].kolvo_dolgov << "\n";
            cout << "Количество сданных работ: " << vseStudent[student].kolvo_sdanix_robot << "\n";
        }
    }
    void skolkoStudNaPare(string group) {
        int StudVGroup = 0;
        for (size_t i = 0; i < vseStudent.size(); i++)
        {
            if (group == vseStudent[i].group) {
                StudVGroup++;
            }
        }
        cout << "Студентов на паре: " << StudVGroup << endl;
    }
    void dobavNesdanRabot() {
        if (vseStudent.size() != 0) {
            for (int student = 0; student < vseStudent.size(); student++)
            {
                cout << "Номер студента: " << student + 1 << " " << "Группа: " << vseStudent[student].group << "\n";
            }
            cout << "Выберите номер, чтобы добавить работу: ";
            string viborStud;
            bool proverkaViborD = false;
            while (proverkaViborD == false)
            {
                cin >> viborStud;
                bool proverka = is_number(viborStud);
                if (proverka == true && stoi(viborStud) <= vseStudent.size() + 1) {
                        vseStudent[stoi(viborStud) - 1].kolvo_dolgov++;
                        break;
                }
                else
                {
                    cout << "ЭТО НЕ ЧИСЛО или число слишком большое\n";
                    cout << "Введити число: ";
                }
            }
        }
        else {
            cout << " У нас пока что никто не учиться ((((\n";
        }
    }
};

int main()
{
   // кс
    setlocale(LC_ALL, "RUS");
    cout << "------------------- 'МПТ' -------------------"<< endl;
    bool vibor = true;
    MPT mpt;
    while (vibor==true)
    {
        cout << "\n  Что вы хотите сделать?\n  1. Добавить преподавателя\n  2. Добавить студента\n  3. Посмотреть всех преподавателей\n  4. Посмотреть всех студентов\n  5. Посмотреть всех студентов на паре \n  6. Добавить работу \n  7. Выйти" << endl;
        string res;
        cin >> res;
        if (res == "1") {
            teacher teachers = mpt.teacher_add();
            cout << "-----------------------------------------------------";
        }
        else if (res == "2") {
            Student student = mpt.add_student();
            cout << "-----------------------------------------------------";
        }
        else if (res == "3") {
            mpt.see_teacher();
            cout << "-----------------------------------------------------";
        }
        else if (res == "4") {
            mpt.ProsmatrivatStud();
            cout << "-----------------------------------------------------";

        }
        else if (res == "5") {
            cout << "  Выберите группу"<< endl;
            int bb = 1;
            for (int i = 0; i < group.size(); i++) {
                cout << " " << bb << "." << " " << group[i]<< endl;
                bb++;
            }
            cin >> bb;
            mpt.skolkoStudNaPare(group[bb-1]);
            cout << "-----------------------------------------------------";
        }
        else if (res == "6") {
            mpt.dobavNesdanRabot();
            cout << "-----------------------------------------------------";
        }
        else if (res == "7") {
            cout << "\nПока\n-----------------------------------------------------";
            exit(0);
        }
        else {
            cout << "-----------------------------------------------------\n      Нужно вводить номер варианта ответа\n-----------------------------------------------------" << endl;
        }
    }

}
