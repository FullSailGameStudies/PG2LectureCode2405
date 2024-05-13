// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include <iomanip>

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    //size() - # of items in a vector
    //capacity() - length of the internal array
    //these #'s are not always equal
    //size will always be <= capacity.
    //you can only access from 0->size-1 in the vector.
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

void FillGrades(std::vector<float>& course)//use & to pass by reference
{
    //srand() - seed the generator
    //rand() - C way to generate random #s
    //      0 - 32767
    //0 - 100?
    //use % to limit the range
    srand(time(NULL));//seed it with a time value
    for (size_t i = 0; i < 10; i++)
    {
        course.push_back((rand() % 10001) / 100.F);
    }
}

//use const to prevent the method from changing the parameter
void PrintGrades(const std::vector<float>& course)
{
    std::cout << "\n\nGrades for PG2 2405\n";
    for (auto& grade : course)
    {
        //setw -  sets the width of the next thing being printed
        //right - right align the next thing being printed
        std::cout << std::setw(8) << std::right << std::setprecision(3) << grade << "\n";
    }
}

void RemoveFailing(std::vector<float>& course)
{
    for (size_t i = 0; i < course.size(); )
    {
        if (course.at(i) < 59.5)
        {
            course.erase(course.begin() + i);
        }
        else i++;
    }
    
    for (int i = course.size() - 1; i >= 0; i--)
    {
        if (course.at(i) < 59.5)
            course.erase(course.begin() + i);
    }

    auto iter = course.begin();
    while (iter != course.end())
    {
        if (*iter < 59.5)
        {
            iter = course.erase(iter);
        }
        else iter++;
    }
}

int main()
{

    Menu cafePG2;
    std::string otherName = "Eggs Benedict";
    std::vector<std::string> items{ "2 Eggs", "Hollandaise sauce", "Biscuits", "Ham" };
    MenuItem item1(otherName, items);
    cafePG2.AddMenuItem(item1);


    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector
            3) in main, print the grades after calling the method

    */
    std::vector<float> grades;
    FillGrades(grades);
    PrintGrades(grades);



    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    highScores.reserve(10);
    printInfo(highScores);
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand());
        printInfo(highScores);
    }
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    for (size_t i = 0; i < highScores.size();)
    {
        if (highScores[i] < 2500)
            highScores.erase(highScores.begin() + i);
        else
            ++i;
    }


    /*
        INTERMEDIATE LEVEL...
        a way using std::remove_if and a lambda
    highScores.erase(
        std::remove_if(highScores.begin(),
            highScores.end(),
            [](int score) { return score < 2500; }),
        highScores.end());
    */


    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */

    PrintGrades(grades);
    RemoveFailing(grades);
    PrintGrades(grades);




    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}