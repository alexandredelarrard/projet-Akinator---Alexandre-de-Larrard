#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <string>
#include <iostream>

using namespace std;

class Questions
{
private:
    std::string variable;
    std::string restriction;

public:
    Questions();// constructor
    Questions(std::string variable, std::string restriction);// constructor
    ~Questions();// destructor

    // getters and setters
    std::string getVariable();
    std::string getRestriction();

    void setVariable(std::string variable);
    void setRestriction(std::string restriction);

    std::string poserQuestion(std::string variable, std::string restriction);// give the question (output) from the choosen variable(input) and modality(input)
};

#endif // QUESTIONS_H
