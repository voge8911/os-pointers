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
    // allocate memory for student fields
    student.f_name = new char[128];
    student.l_name = new char[128];
    student.grades = new double[134217728];
    
    // Sequence of user input -> store in fields of `student`  
    student.id = promptInt("Please enter the student's id number: ",0,1000000000);
 
    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;

    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;
    std::cin.ignore();

    student.n_assignments = promptInt("Please enter how many assignments were graded: ",1,134217728); 
    std::cout << std::endl;

    student.grades = new double[student.n_assignments];
    for (int i=0; i < student.n_assignments; i++)
    {
        student.grades[i] = promptDouble("Please enter grade for assignment " + std::to_string(i) + ": ",0,1000.0);
    }
    std::cout << std::endl;
    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student, &average);

    // Output student info and `average`
    std::cout << "Student: " << student.f_name <<" "<< student.l_name <<" ["<< student.id << "]" << std::endl;
    printf("  Average grade: %0.1f", average);
    std::cout << "\n";
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int and catch data type errors
    std::string input;
    bool is_character;
    int input_to_int;
    while (1)
    {
        // print message
        std::cout << message;
        // get input as a string
        std::getline(std::cin, input);
        // if user inputs nothing, prompt again
        if (input.empty())
        {
            continue;
        }
        // go through each character of input, checking for data type errors
        for (int i = 0; i < input.length(); i++)
        {
            is_character = false;
            // try input to integer conversion
            try
            {
                std::stoi(input.substr(i, i+1));
            }
            // if conversion fails, input must be wrong data type
            catch (const std::invalid_argument e)
            {
                is_character = true;
                break;
            }
        }
        // error check if input was wrong data type
        if (is_character)
        {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            std::cin.clear();
            continue;
        }
        // can now safely convert input to double
        input_to_int = std::stoi(input);
        // error check if input is within min and max
        if (input_to_int < min || input_to_int > max)
        {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            std::cin.clear();
            continue;
        }
        break;
    }
    return input_to_int;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for an double and catch data type errors
    std::string input;
    bool is_character;
    double input_to_double;
    while (1)
    {
        // print message and get input
        std::cout << message;
        std::getline(std::cin, input);
        // if user inputs nothing, prompt again
        if (input.empty())
        {
            continue;
        }
        // go through each character of user input, checking for data type errors
        for (int i = 0; i < input.length(); i++)
        {
            is_character = false;
            // try input to double conversion
            try
            {
                // decimal point is valid character, as input should be of type double
                if (input.substr(i, i+1).compare(".") == 0)
                {
                    continue;
                }
                std::stod(input.substr(i, i+1));
            }
            // if conversion fails, input must be wrong data type
            catch (const std::invalid_argument e)
            {
                is_character = true;
                break;
            }
        }
        // error check if input was wrong data type
        if (is_character)
        {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            std::cin.clear();
            continue;
        }
        // can now safely convert input to double
        input_to_double = std::stod(input);
        // error check if input is within min and max
        if (input_to_double < min || input_to_double > max)
        {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            std::cin.clear();
            continue;
        }
        break;
    }
    return input_to_double;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    Student new_student = *((Student *)object);
    // Code to calculate and store average grade
    for (int i = 0; i < new_student.n_assignments; i++)
    {
        *avg += new_student.grades[i];
    }
    *avg = *avg / new_student.n_assignments;
}
