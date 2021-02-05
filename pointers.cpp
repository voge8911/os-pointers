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
    std::string id_string = "Please enter the student's id number: ";
    //std::string firstname_string = "Please enter the student's first name: ";
    //std::string lastname_string = "Please enter the student's last name: ";
    std::string n_assignments_string = "Please enter the how many assignments were graded: ";

    // Sequence of user input -> store in fields of `student`
    promptInt(id_string,0,9);
    std::cout << "HERE";
    std::cout << "Please enter the student's first name: ";
    scanf("%c", student.f_name);
    std::cout << "Please enter the student's last name: ";
    scanf("%c", student.l_name);
    promptInt(n_assignments_string,0,2147483646); //n_assignments is less than 2,147,483,647

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`

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
    scanf("%d", input);
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
    scanf("%f", input);
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
