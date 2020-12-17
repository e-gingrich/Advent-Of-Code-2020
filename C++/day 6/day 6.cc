/*
 *  Day 6 Solution for Advent of Code 2020
 *  Author: Ethan Gingrich
 *  Desc: used an array to buffer the lines and add (or subtract) answers
 *          based on which part we're in.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<char> unique_answers_1;
std::vector<char> unique_answers_2;
bool line_set = false;              // needed for part 2 so we don't double count
                                    // chars if the vector empties before the group
                                    // has been finished being counted

int
determine_unique_part_1 (std::string line);

void 
determine_unique_part_2 (std::string line);

int
main(int argc, char const *argv[])
{
    
    std::ifstream answers ("input.txt");
    int group_sum_1 = 0, total_sum_1 = 0, group_sum_2 = 0, total_sum_2 = 0;
    std::string line;

    while (std::getline (answers, line))
    {
        if (!line.size ())
        {
            group_sum_2 += unique_answers_2.size(); // for part 2

            total_sum_1 += group_sum_1;             // for part 1
            total_sum_2 += group_sum_2;             // for part 2

            group_sum_1 = group_sum_2 = 0;          // reset group totals

            unique_answers_1.clear ();              // clear both answer vectors
            unique_answers_2.clear ();              // and set line bool to false for part 2
            line_set = false;

            continue;
        }
        group_sum_1 += determine_unique_part_1 (line);
        determine_unique_part_2(line);
    }

    std::cout << "Part 1 total: " << total_sum_1 << "\n";
    std::cout << "Part 2 total: " << total_sum_2 << "\n";
    return 1;
}

// Count the number of answers that anyone in the group answered
int
determine_unique_part_1 (std::string line)
{
    int sum = 0;
    for (unsigned int i = 0; i < line.length (); i++)
    {
        if (std::find(unique_answers_1.begin (), unique_answers_1.end (), line[i]) == unique_answers_1.end())
        {
            unique_answers_1.push_back (line[i]);
            sum++;
        }
    }
    return sum;
}

// Count the number of answers that everyone in the group answered
void
determine_unique_part_2 (std::string line)
{
    if (unique_answers_2.size() == 0 && line_set == false)
    {
        for (unsigned int i = 0; i < line.length (); i++)
        {
            unique_answers_2.push_back (line[i]);
        }
        line_set = true;    
    }
    else {
        for (std::vector<char>::iterator i = unique_answers_2.begin(); i != unique_answers_2.end(); ++i)
        {
            if (std::find(line.begin (), line.end (), *i) == line.end())
            {
                unique_answers_2.erase (i--);
            }
        }
    }
}
