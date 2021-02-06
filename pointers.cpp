// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    std::string id_message = "Please enter the student's id number: ";
    std::string n_assignments_message = "Please enter how many assignments were graded: ";

    student.f_name = new char[128];
    student.l_name = new char[128];
    
    // Sequence of user input -> store in fields of `student`
    student.id = promptInt(id_message,0,9);
    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;
    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;
    student.n_assignments = promptInt(n_assignments_message,0,2147483646); //n_assignments is less than 2,147,483,647
    std::cout << "\n";

    student.grades = new double[student.n_assignments];

    for (int i=0; i < student.n_assignments; i++)
    {
        std::string message = "Please enter grade for assignment " + std::to_string(i) + ": ";
        student.grades[i] = promptDouble(message,0,1000);
    }
    std::cout << "\n";

    //print out students name and id
    std::cout << "Student: " << student.f_name <<" "<< student.l_name <<" ["<< student.id << "]";

    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(student.grades, &average);

    // Output `average`
    std::cout << "    Average grade: " << average;
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int input;
    std::cout << message;
    scanf("%d", &input);
    //std::cin >> input;
    return input; 
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double input;
    std::cout << message;
    scanf("%lf", &input);
    return input; 
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    


}
