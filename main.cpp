#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

void clean_data(std::string &data)
{
    for(int i = 0; i < data.length(); i++)
    {
        if(data[i] == ' ' || data[i] == '\n')
        {
            data.erase(i, 1);
            --i;
        }
    }
}

int score(std::string test, std::string key)
{
    int score = 0;
    for(size_t i = 0; i < test.length(); i++)
    {
        if(test[i] == key[i])
            score++;
    }
    return score;
}

int main() {
    
    std::ifstream in_file("text.txt");
    
    if(!in_file.is_open())
    {
        std::cout << "Problem Encountered Opening File" << std::endl;
    }
    
    int lineNumber = 1;
    std::vector<std::string> names {};
    std::vector<std::string> answers {};
    std::string line;
    std::string answer_key;
    
    while(std::getline(in_file, line))
    {
        if(lineNumber == 1)
            {
                clean_data(line);
                answer_key = line;
                lineNumber++;
            }
        
        else if(lineNumber % 2 == 0) 
            {
                std::string name = line;
                clean_data(name);
                names.push_back(name);
                lineNumber++;
            }
            
        else if(lineNumber % 2 != 0)
            {
                std::string answer = line;
                clean_data(answer);
                answers.push_back(answer);
                lineNumber++;
            }
    }
    
    in_file.close();
    
    std::string equals(20, '=');
    std::string space(11, ' ');
    std::cout << "\n\nName" << space << "Score" << std::endl;
    std::cout << equals << std::endl;
    
    for(size_t i = 0; i < names.size(); i++)
        std::cout << std::setw(10) << std::left << names[i] 
                  << std::setw(10) << std::right << score(answers[i], answer_key) << std::endl;
        
    return 0;
}
