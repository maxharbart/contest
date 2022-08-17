#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//function to split string into vector
void split_applicant (std::string const &str, const char delim, std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

// function to compare number of solved tasks and penalty points
static bool comp_tasks(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2){
    
    if (vec1[1] == vec2[1]) {
        if (std::stoi(vec1[2]) == std::stoi(vec2[2])) {
            return std::stoi(vec1[3]) < std::stoi(vec2[3]);
        }
        else {
            return std::stoi(vec1[2]) > std::stoi(vec2[2]);
        }
    }
    
}

// function to compare strings for alphabetical sorting
bool compareFunction (std::string a, std::string b) {return a<b;};

int main() {

    std::string line;
    std::ifstream myfile ("second_example.txt");
    std::vector <std::string> data;

    int amount;
    std::vector <std::string> vacancies;
    int num_of_applicants;
    std::vector <std::string> applicants;

// getting data from input file and wrapping it up in vector
    while ( std::getline (myfile, line)) 
    {
        data.push_back(line);
    }

// assigning data from vector to variables
    amount = std::stoi(data[0]);
    
    for (int i = 1; i <= amount; i++) {
        vacancies.push_back(data[i]);
    }

    num_of_applicants = std::stoi(data[amount + 1]); 

// starting point for applicants in file and array
    int start = amount + 2;

// putting applicants into vector
    for (int i = 0; i < num_of_applicants; i++) {
        applicants.push_back(data[start]);
        start+=1;
    }

// vector of vectors of applicants
    std::vector <std::vector <std::string> > splitted_applicants; 
// splitting applicants
    for (auto i: applicants) {
        std::vector <std::string> out;
        const char delim = ',';
        split_applicant(i, delim, out);
        splitted_applicants.push_back(out);
    }

//vector of vacancy names
    std::vector <std::vector <std::string> > splitted_vacancies;
// splitting vacancies and making vector of vacancy names
    for (auto i: vacancies) {
        std::vector <std::string> out;
        const char delim = ',';
        split_applicant(i, delim, out);
        splitted_vacancies.push_back(out);
    }

// make vectors of applicants for each vacancy
    std::vector <std::vector <std::string> > sorted_applicants;

    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < num_of_applicants; j++) {
            if (splitted_vacancies[i][0] == splitted_applicants[j][1]) {
                sorted_applicants.push_back(splitted_applicants[j]);
            }
        }
    }

// sort applicants by number of solved tasks
std::sort(sorted_applicants.begin(), sorted_applicants.end(), comp_tasks);

//vector for final result
std::vector<std::string> result;

//push result to vector
for (auto i: splitted_vacancies) {
    int j = 0;
    int n = 0;
    while (j < std::stoi(i[1])) {
        if (i[0] == sorted_applicants[n][1]) {   
            
                result.push_back(sorted_applicants[n][0]);
                j+=1;
            
        }
        n += 1;
    }
}

std::sort(result.begin(), result.end(), compareFunction);

// print result
    for (auto i: result) {
        std::cout << i << std::endl;
    }
}