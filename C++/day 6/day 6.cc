/*
 *  Day 6 Solution for Advent of Code 2020
 *  Author: Ethan Gingrich
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<char> unique_answers;

int
determine_unique (std::string line);

int
main(int argc, char const *argv[])
{
    
    std::ifstream answers ("input.txt");
    int group_sum = 0, total_sum = 0;
    std::string line;
    int i = 0;
    while (std::getline (answers, line))
    {
        if (!line.size ())
        {
            total_sum += group_sum;
            group_sum = 0;
            unique_answers.clear ();
            i++;
            //if (i == 5)
                //break;
            continue;
        }
        group_sum += determine_unique (line);
        //std::cout << " " << group_sum << "\n";
    }

    std::cout << "Part 1 total: " << total_sum << "\n";
    return 1;
}

int
determine_unique (std::string line)
{
    int sum = 0;
    for (unsigned int i = 0; i < line.length (); i++)
    {
        if (std::find(unique_answers.begin (), unique_answers.end (), line[i]) == unique_answers.end())
        {
            unique_answers.push_back (line[i]);
            //std::cout << line[i];
            sum++;
        }
    }
    return sum;
}
