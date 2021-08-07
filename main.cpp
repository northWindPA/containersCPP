#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define END "\x1B[0m"

#include "list.hpp"
#include <list>
#include <iostream>
#include <memory>
#include <ctime>
#include <cmath>
#include <vector>
#include "vector.hpp"
#include <queue>
#include <stack>
#include "stack.hpp"
#include <map>
#include "map.hpp"
#include <set>
#include "set.hpp"

template<typename T>
void testVector(std::vector<T> &stdV, ft::vector<T> &myV) {
    std::cout << YELLOW<< "St-vector: " << MAGENTA;
    for (size_t i = 0; i < stdV.size(); i++)
        std::cout << stdV[i] << " ";
    std::cout << std::endl;
    std::cout << YELLOW<< "Ft-vector: " << MAGENTA;
    for (size_t i = 0; i < myV.size(); i++)
        std::cout << myV[i] << " ";
    std::cout << std::endl;
    std::cout << YELLOW << "St-vector.size(): " << MAGENTA << stdV.size() << std::endl;
    std::cout << YELLOW << "Ft-vector.size(): " << MAGENTA << myV.size() << END << std::endl;
    std::cout << YELLOW << "St-vector.capacity(): " << MAGENTA << stdV.capacity() << std::endl;
    std::cout << YELLOW << "Ft-vector.capacity(): " << MAGENTA << myV.capacity() << END << std::endl;
}

int main() {
    int vectorFlag = 0;
    int mapFlag = 0;
    int stackFlag = 0;
    int setFlag = 0;
    std::string input;
    std::cout << YELLOW <<"Welcome to container tester" << RED << " C++: " << END << std::endl;
    std::cout << GREEN << "1. " << MAGENTA << "Vector" << END << std::endl;
    std::cout << GREEN << "2. " << MAGENTA << "Map" << END << std::endl;
    std::cout << GREEN << "3. " << MAGENTA << "Stack" << END << std::endl;
    std::cout << GREEN << "4. " << MAGENTA << "Set" << END << std::endl;
    while(true) {
        srand((unsigned int)time(0));
        std::cout << BLUE "Please choose and enter container's name to test it: " << END;
        std::getline(std::cin, input);
        if ( (input == "vector" || input == "Vector") && vectorFlag == 0 ) {
            vectorFlag = 1;
            std::cout << YELLOW <<"<==============================================================>" << END << std::endl;
            std::cout << MAGENTA << "Vector-test" << END << std::endl;
            std::cout << YELLOW <<"<==============================================================>" << std::endl;
            std::cout << YELLOW << "Create two integers vectors using " << MAGENTA << "default constructor" << END << std::endl;
            ft::vector<int> myV;
            std::vector<int> stdV;
            std::cout << YELLOW << "St-vector.size(): " << MAGENTA << stdV.size() << std::endl;
            std::cout << YELLOW << "Ft-vector.size(): " << MAGENTA << myV.size() << END << std::endl;
            std::cout << YELLOW << "St-vector.capacity(): " << MAGENTA << stdV.capacity() << std::endl;
            std::cout << YELLOW << "Ft-vector.capacity(): " << MAGENTA << myV.capacity() << END << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << YELLOW << "Create two integers vectors using " << MAGENTA << "filling constructor" << END << std::endl;
            ft::vector<int> myVe(5, 3);
            std::vector<int> stdVe(5, 3);
            testVector(stdVe, myVe);
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << YELLOW << "Create two integers vectors using " << MAGENTA << "range constructor" << END << std::endl;
            std::vector<int> ayV(++stdVe.begin(), --stdVe.end());
            ft::vector<int> amyV(++myVe.begin(), --myVe.end());
            testVector(ayV, amyV);
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << YELLOW << "Create two integers vectors using " << MAGENTA << "copy constructor" << END << std::endl;
            std::vector<int> copyV(stdVe);
            ft::vector<int> myCopyV(myVe);
            testVector(copyV, myCopyV);
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".max_size() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-vector: " << MAGENTA << stdV.max_size() << std::endl;
            std::cout << YELLOW << "Ft-vector: " << MAGENTA << myV.max_size() << END << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".resize(size_type n) " << RED << "function: " << std::endl;
            for (size_t i = 0; i < 10; i++) {
                int g = rand() % 10;
                stdV.push_back(g);
                myV.push_back(g);
            }
            std::cout << std::endl;
            testVector(stdV, myV);
            std::cout << CYAN << "  RESIZE  " << END << std::endl;
            stdV.resize(10);
            myV.resize(10);
            testVector(stdV, myV);
            std::cout << CYAN << "  RESIZE  " << END << std::endl;
            stdV.resize(5);
            myV.resize(5);
            testVector(stdV, myV);
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".reserve(size_type n) " << RED << "function: " << std::endl;
            testVector(stdV, myV);
            stdV.reserve(100);
            myV.reserve(100);
            std::cout << CYAN << "  RESERVE  " << END << std::endl;
            std::cout << YELLOW << "St-vector.size(): " << MAGENTA << stdV.size() << std::endl;
            std::cout << YELLOW << "Ft-vector.size(): " << MAGENTA << myV.size() << END << std::endl;
            std::cout << YELLOW << "St-vector.capacity(): " << MAGENTA << stdV.capacity() << std::endl;
            std::cout << YELLOW << "Ft-vector.capacity(): " << MAGENTA << myV.capacity() << END << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".front() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-vector front: " << MAGENTA << stdV.front() << std::endl;
            std::cout << YELLOW << "Ft-vector front: " << MAGENTA << myV.front() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".back() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-vector back: " << MAGENTA << stdV.back() << std::endl;
            std::cout << YELLOW << "Ft-vector back: " << MAGENTA << myV.back() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".at(size_type n) " << RED << "function: " << std::endl;
            try {
                std::cout << YELLOW << "St-vector back: " << MAGENTA << stdV.at(3) << std::endl;
            std::cout << YELLOW << "Ft-vector back: " << MAGENTA << myV.at(3) << std::endl;
            } catch (std::exception &e) {std::cerr << e.what() << std::endl;}
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".assign(InputIterator first, InputIterator last) " << RED << "function: " << std::endl;
            std::vector<int> assignV(5, 1);
            ft::vector<int> myAssignV(5, 1);
            myV.assign(++myAssignV.begin(), --myAssignV.end());
            stdV.assign(++assignV.begin(), --assignV.end());
            std::cout << YELLOW<< "St-vector: " << MAGENTA;
            testVector(stdV, myV);
            std::cout << RED << "Testing " << MAGENTA << ".assign(size_type n, const value_type& val) " << RED << "function: " << std::endl;
            myV.assign(6, 1);
            stdV.assign(6, 1);
            testVector(stdV, myV);
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".pop_back() " << RED << "function: " << std::endl;
            stdV.pop_back();
            myV.pop_back();
            testVector(stdV, myV);
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".push_back(const value_type& val) " << RED << "function: " << std::endl;
            stdV.push_back(7);
            myV.push_back(7);
            testVector(stdV, myV);
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".erase(iterator position) " << RED << "function: " << std::endl;
            stdV.erase(--stdV.end());
            myV.erase(--myV.end());
            testVector(stdV, myV);
            std::cout << RED << "Testing " << MAGENTA << ".erase(iterator first, iterator last) " << RED << "function: " << std::endl;
            stdV.erase(++stdV.begin(), --stdV.end());
            myV.erase(++myV.begin(), --myV.end());
            testVector(stdV, myV);
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".swap(vector& x) " << RED << "function: " << std::endl;
            std::vector<int> swapV;
            ft::vector<int> mswapV;
            for (int i = 0; i < 5; i++) {
                int g = rand() % 10;
                swapV.push_back(g);
                mswapV.push_back(g);
            }
            std::cout << CYAN << "Vector for swap" << std::endl;
            testVector(swapV, mswapV);
            std::cout << CYAN << "              SWAP!" << std::endl;
            myV.swap(mswapV);
            stdV.swap(swapV);
            std::cout << CYAN << "Vector after swap" << std::endl;
            testVector(stdV, myV);
        }
        else if ((input == "stack" || input == "Stack") && stackFlag == 0) {
            stackFlag = 1;
            std::cout << YELLOW <<"<==============================================================>" << END << std::endl;
            std::cout << MAGENTA << "Stack-test" << END << std::endl;
            std::cout << YELLOW <<"<==============================================================>" << END << std::endl;
            std::cout << YELLOW << "Create two integers Stacks using " << MAGENTA << "default constructor" << END << std::endl;
            std::stack<int, std::list<int> > stdS;
            ft::stack<int, ft::list<int> > myS;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".empty() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-stack.empty(): " << MAGENTA << (stdS.empty() ? "true" : "false") << std::endl;
            std::cout << YELLOW << "Ft-stack.empty(): " << MAGENTA << (myS.empty() ? "true" : "false") << END << std::endl;
            for (int i = 0; i < 10; i++) {
                int g = rand() % 10;
                stdS.push(g);
                myS.push(g);
            }
            std::cout << YELLOW << "St-stack.empty(): " << MAGENTA << (stdS.empty() ? "true" : "false") << std::endl;
            std::cout << YELLOW << "Ft-stack.empty(): " << MAGENTA << (myS.empty() ? "true" : "false") << END << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".size() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-stack size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-stack size: " << MAGENTA << myS.size() << END << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".top() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-stack top: " << MAGENTA << stdS.top() << std::endl;
            std::cout << YELLOW << "Ft-stack top: " << MAGENTA << myS.top() << END << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".push(124) " << RED << "function: " << std::endl;
            stdS.push(124);
            myS.push(124);
            std::cout << YELLOW << "St-stack top: " << MAGENTA << stdS.top() << std::endl;
            std::cout << YELLOW << "Ft-stack top: " << MAGENTA << myS.top() << END << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".pop() " << RED << "function: " << std::endl;
            std::cout << GREEN << "Before .pop():" << std::endl;
            std::cout << YELLOW << "St-stack front: " << MAGENTA << stdS.top() << std::endl;
            std::cout << YELLOW << "Ft-stack front: " << MAGENTA << myS.top() << END << std::endl;
            stdS.pop();
            myS.pop();
            std::cout << GREEN << "after .pop():" << std::endl;
            std::cout << YELLOW << "St-stack top: " << MAGENTA << stdS.top() << std::endl;
            std::cout << YELLOW << "Ft-stack top: " << MAGENTA << myS.top() << END << std::endl;
        }
        else if((input == "map" || input == "Map") && mapFlag == 0) {
            mapFlag = 1;
            std::cout << YELLOW <<"<==============================================================>" << END << std::endl;
            std::cout << MAGENTA << "Map-test" << END << std::endl;
            std::cout << YELLOW <<"<==============================================================>" << END << std::endl;
            std::cout << YELLOW << "Create two integers, string maps using " << MAGENTA << "default constructor" << END
                      << std::endl;
            std::map<int, std::string> stdM;
            ft::map<int, std::string> myM;
            std::map<int, std::string>::iterator itm = stdM.begin();
            ft::map<int, std::string>::iterator mitm = myM.begin();
            std::cout << YELLOW << "St First: " << MAGENTA << itm->first << RED << ", st Second: " << MAGENTA << itm->second
                      << std::endl;
            std::cout << YELLOW << "Ft-First: " << MAGENTA << mitm->first << RED << ", my Second: " << MAGENTA << mitm->second
                      << std::endl;
            std::cout << YELLOW << "St size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << GREEN << "Create two integers, string maps using " << MAGENTA << "range constructor" << END
                      << std::endl;
            for (int i = 1; i < 10; i++) {
                int r = rand() % 15;
                stdM.insert(std::pair<int, std::string>(r, "l"));
                myM.insert(std::pair<int, std::string>(r, "l"));
            }
            std::map<int, std::string> stdM2(stdM.begin(), stdM.end());
            ft::map<int, std::string> myM2(myM.begin(), myM.end());
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            std::cout << YELLOW << "St2-size: " << MAGENTA << stdM2.size() << std::endl;
            std::cout << YELLOW << "Ft2--size: " << MAGENTA << myM2.size() << std::endl;

            std::cout << RED << " stdM: " << " " << MAGENTA;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << RED << " stdM2: " << " " << MAGENTA;
            for (std::map<int, std::string>::iterator it = stdM2.begin(), ite = stdM2.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << RED << " myM: " << " " << MAGENTA;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << RED << " myM2: " << " " << MAGENTA;
            for (ft::map<int, std::string>::iterator mit = myM2.begin(), ite = myM2.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
           std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".insert(const value_type &val) " << RED << "function: " << std::endl;
            for (int i = 1; i < 10; i++) {
                int r = rand() % 15;
                stdM.insert(std::pair<int, std::string>(r, "l"));
                myM.insert(std::pair<int, std::string>(r, "l"));
            }
            std::cout << std::endl;
            std::cout << YELLOW << "Std insert: " << " " << MAGENTA;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-insert: " << " " << MAGENTA;
            for (ft::map<int, std::string>::iterator it = myM.begin(), ite = myM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".max_size() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-max size: " << MAGENTA << stdM.max_size() << std::endl;
            std::cout << YELLOW << "Ft-max size: " << MAGENTA << myM.max_size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".empty() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-map .empty(): " << MAGENTA << (stdM.empty() ? "true" : "false") << std::endl;
            std::cout << YELLOW << "Ft-map .empty(): " << MAGENTA << (myM.empty() ? "true" : "false") << END << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".erase(iterator position) " << RED << "function: " << std::endl;
            std::cout << YELLOW << "Std map: " << " " << MAGENTA;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-map: " << " " << MAGENTA;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            stdM.erase(++(stdM.begin()));
            myM.erase(++(myM.begin()));
            std::cout << YELLOW << "Std map: " << " " << MAGENTA;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-map: " << " " << MAGENTA;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            std::cout << "CHeck: " << stdM.erase(1) << std::endl;
            std::cout << "CHeck2: " << myM.erase(1) << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << "operator[key]" << RED << ": " << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            stdM[66] = "gg";
            myM[66] = "gg";
            std::cout << YELLOW << "stdM[66]: " << MAGENTA << stdM[66] << std::endl;
            std::cout << YELLOW << "myM[66]: " << MAGENTA << myM[66] << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".clear()" << RED << " function: " << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            stdM.clear();
            myM.clear();
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".swap(map &x)" << RED << " function: " << std::endl;
            myM2.clear();
            stdM2.clear();
            for (int i = 0; i < 10; i++) {
                myM.insert(std::pair<int, std::string>(i, "k"));
                stdM.insert(std::pair<int, std::string>(i, "k"));

            }
            for (int i = 100; i < 105; i++) {
                myM2.insert(std::pair<int, std::string>(i, "k"));
                stdM2.insert(std::pair<int, std::string>(i, "k"));
            }
            std::cout << YELLOW << "Std map: " << " " << MAGENTA;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Std map2: " << " " << MAGENTA;
            for (std::map<int, std::string>::iterator it = stdM2.begin(), ite = stdM2.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-map: " << " " << MAGENTA;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-map2: " << " " << MAGENTA;
            for (ft::map<int, std::string>::iterator mit = myM2.begin(), ite = myM2.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            std::cout << YELLOW << "St2-size: " << MAGENTA << stdM2.size() << std::endl;
            std::cout << YELLOW << "Ft2-size: " << MAGENTA << myM2.size() << std::endl;
            std::cout << CYAN << "                 SWAP" << std::endl;
            myM.swap(myM2);
            stdM.swap(stdM2);
            std::cout << YELLOW << "Std map: " << " " << MAGENTA;
            for (std::map<int, std::string>::iterator it = stdM.begin(), ite = stdM.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Std map2: " << " " << MAGENTA;
            for (std::map<int, std::string>::iterator it = stdM2.begin(), ite = stdM2.end(); it != ite; it++)
                std::cout << it->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-map: " << " " << MAGENTA;
            for (ft::map<int, std::string>::iterator mit = myM.begin(), ite = myM.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-map2: " << " " << MAGENTA;
            for (ft::map<int, std::string>::iterator mit = myM2.begin(), ite = myM2.end(); mit != ite; mit++)
                std::cout << mit->first << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdM.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myM.size() << std::endl;
            std::cout << YELLOW << "St2-size: " << MAGENTA << stdM2.size() << std::endl;
            std::cout << YELLOW << "Ft2-size: " << MAGENTA << myM2.size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".lower_bound(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << YELLOW << "Std: " << MAGENTA << stdM.lower_bound(101)->first << std::endl;
            std::cout << YELLOW << "Ft-" << MAGENTA << myM.lower_bound(101)->first << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".upper_bound(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << YELLOW << "Std: " << MAGENTA << stdM.upper_bound(101)->first << std::endl;
            std::cout << YELLOW << "Ft-" << MAGENTA << myM.upper_bound(101)->first << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".equal_range (const key_type& k)" << RED << " function: " << std::endl;
            std::pair <std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> tst = stdM.equal_range(102);
            std::pair <ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> mtst = myM.equal_range(102);
            std::cout << YELLOW << "Std map: " << " " << MAGENTA;
            for(; tst.first != tst.second; tst.first++) {
                std::cout << tst.first->first << " ";
            }
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-map: " << " " << MAGENTA;
            for(; mtst.first != mtst.second; mtst.first++) {
                std::cout << mtst.first->first << " ";
            }
            std::cout << std::endl;
            std::cout << YELLOW << "Std: " << MAGENTA << stdM.upper_bound(101)->first << std::endl;
            std::cout << YELLOW << "Ft-" << MAGENTA << myM.upper_bound(101)->first << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".find(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << YELLOW << "Std: " << MAGENTA << stdM.find(103)->first << std::endl;
            std::cout << YELLOW << "Ft- " << MAGENTA << myM.find(103)->first << std::endl;
            std::cout << YELLOW << "Std: " << MAGENTA << stdM.find(108)->first << std::endl;
            std::cout << YELLOW << "Ft-" << MAGENTA << myM.find(108)->first << std::endl;
        }
        else if ((input == "set" || input == "Set") && setFlag == 0) {
            setFlag = 1;
            std::cout << YELLOW <<"<==============================================================>" << END << std::endl;
            std::cout << MAGENTA << "Set-test" << END << std::endl;
            std::cout << YELLOW <<"<==============================================================>" << END << std::endl;
            std::cout << YELLOW << "Create two integers, string sets using " << MAGENTA << "default constructor" << END
                      << std::endl;
            std::set<int> stdS;
            ft::set<int> myS;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myS.size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << GREEN << "Create two integers, string sets using " << MAGENTA << "range constructor" << END
                      << std::endl;
            for (int i = 1; i < 10; i++) {
                int r = rand() % 15;
                stdS.insert(r);
                myS.insert(r);
            }
            std::set<int> stdS2(stdS.begin(), stdS.end());
            ft::set<int> myS2(myS.begin(), myS.end());
            std::cout << YELLOW << "St size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myS.size() << std::endl;
            std::cout << YELLOW << "St2 size: " << MAGENTA << stdS2.size() << std::endl;
            std::cout << YELLOW << "Ft- size: " << MAGENTA << myS2.size() << std::endl;

            std::cout << RED << " stdS: " << " " << MAGENTA;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << RED << " stdS2: " << " " << MAGENTA;
            for (std::set<int>::iterator it = stdS2.begin(), ite = stdS2.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << RED << " myS: " << " " << MAGENTA;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << RED << " myS2: " << " " << MAGENTA;
            for (ft::set<int>::iterator mit = myS2.begin(), ite = myS2.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".insert(const value_type &val) " << RED << "function: " << std::endl;
            for (int i = 1; i < 10; i++) {
                int r = rand() % 15;
                stdS.insert(r);
                myS.insert(r);
            }
            std::cout << std::endl;
            std::cout << YELLOW << "Std-insert: " << " " << MAGENTA;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-insert: " << " " << MAGENTA;
            for (ft::set<int>::iterator it = myS.begin(), ite = myS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "St size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myS.size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".max_size() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-max size: " << MAGENTA << stdS.max_size() << std::endl;
            std::cout << YELLOW << "Ft-max size: " << MAGENTA << myS.max_size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".empty() " << RED << "function: " << std::endl;
            std::cout << YELLOW << "St-set.empty(): " << MAGENTA << (stdS.empty() ? "true" : "false") << std::endl;
            std::cout << YELLOW << "Ft-set.empty(): " << MAGENTA << (myS.empty() ? "true" : "false") << END << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".erase(iterator position) " << RED << "function: " << std::endl;
            std::cout << YELLOW << "Std set: " << " " << MAGENTA;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-set: " << " " << MAGENTA;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            stdS.erase(++(stdS.begin()));
            myS.erase(++(myS.begin()));
            std::cout << YELLOW << "Std-set: " << " " << MAGENTA;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-set: " << " " << MAGENTA;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myS.size() << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myS.size() << std::endl;
            std::cout << "CHeck: " << stdS.erase(1) << std::endl;
            std::cout << "CHeck2: " << myS.erase(1) << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".clear()" << RED << " function: " << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myS.size() << std::endl;
            stdS.clear();
            myS.clear();
            std::cout << YELLOW << "St-size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myS.size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".swap(set &x)" << RED << " function: " << std::endl;
            myS2.clear();
            stdS2.clear();
            for (int i = 0; i < 10; i++) {
                myS.insert(i);
                stdS.insert(i);

            }
            for (int i = 100; i < 105; i++) {
                myS2.insert(i);
                stdS2.insert(i);
            }
            std::cout << YELLOW << "Std-set: " << " " << MAGENTA;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Std-set2: " << " " << MAGENTA;
            for (std::set<int>::iterator it = stdS2.begin(), ite = stdS2.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-set: " << " " << MAGENTA;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-set2: " << " " << MAGENTA;
            for (ft::set<int>::iterator mit = myS2.begin(), ite = myS2.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myS.size() << std::endl;
            std::cout << YELLOW << "St2-size: " << MAGENTA << stdS2.size() << std::endl;
            std::cout << YELLOW << "Ft2-size: " << MAGENTA << myS2.size() << std::endl;
            std::cout << CYAN << "                 SWAP" << std::endl;
            myS.swap(myS2);
            stdS.swap(stdS2);
            std::cout << YELLOW << "Std set: " << " " << MAGENTA;
            for (std::set<int>::iterator it = stdS.begin(), ite = stdS.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Std set2: " << " " << MAGENTA;
            for (std::set<int>::iterator it = stdS2.begin(), ite = stdS2.end(); it != ite; it++)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-set: " << " " << MAGENTA;
            for (ft::set<int>::iterator mit = myS.begin(), ite = myS.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-set2: " << " " << MAGENTA;
            for (ft::set<int>::iterator mit = myS2.begin(), ite = myS2.end(); mit != ite; mit++)
                std::cout << *mit << " ";
            std::cout << std::endl;
            std::cout << YELLOW << "St-size: " << MAGENTA << stdS.size() << std::endl;
            std::cout << YELLOW << "Ft-size: " << MAGENTA << myS.size() << std::endl;
            std::cout << YELLOW << "St2-size: " << MAGENTA << stdS2.size() << std::endl;
            std::cout << YELLOW << "Ft2-size: " << MAGENTA << myS2.size() << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".lower_bound(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << YELLOW << "Std: " << MAGENTA << *(stdS.lower_bound(101)) << std::endl;
            std::cout << YELLOW << "Ft-" << MAGENTA << *(myS.lower_bound(101)) << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".upper_bound(const value_type& val)" << RED << " function: " << std::endl;
            std::cout << YELLOW << "Std: " << MAGENTA << *(stdS.upper_bound(101)) << std::endl;
            std::cout << YELLOW << "Ft-" << MAGENTA << *(myS.upper_bound(101)) << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".equal_range (const value_type& val)" << RED << " function: " << std::endl;
            std::pair <std::set<int>::iterator, std::set<int>::iterator> tst = stdS.equal_range(102);
            std::pair <ft::set<int>::iterator, ft::set<int>::iterator> mtst = myS.equal_range(102);
            std::cout << YELLOW << "Std-set: " << " " << MAGENTA;
            for(; tst.first != tst.second; tst.first++) {
                std::cout << *(tst.first) << " ";
            }
            std::cout << std::endl;
            std::cout << YELLOW << "Ft-set: " << " " << MAGENTA;
            for(; mtst.first != mtst.second; mtst.first++) {
                std::cout << *(mtst.first) << " ";
            }
            std::cout << std::endl;
            std::cout << YELLOW << "Std: " << MAGENTA << *(stdS.upper_bound(101)) << std::endl;
            std::cout << YELLOW << "Ft-" << MAGENTA << *(myS.upper_bound(101)) << std::endl;
            std::cout << CYAN << "\n<------------------------------------------------------------->\n" << END
                      << std::endl;
            std::cout << RED << "Testing " << MAGENTA << ".find(const key_type& k)" << RED << " function: " << std::endl;
            std::cout << YELLOW << "Std: " << MAGENTA << *(stdS.find(103)) << std::endl;
            std::cout << YELLOW << "Ft-" << MAGENTA << *(myS.find(103)) << std::endl;
        }
        else if (input == "exit" || input == "Exit")
            return 0;
        else
            std::cout << RED << "Wrong input" << END << std::endl;
        if (setFlag)
            std::cout << RED << "Set has been tested!" << END << std::endl;
        if (vectorFlag)
            std::cout << RED << "Vector has been tested!" << END << std::endl;
        if (stackFlag)
            std::cout << RED << "Stack has been tested!" << END << std::endl;
        if (mapFlag)
            std::cout << RED << "Map has been tested!" << END << std::endl;
    }
    return 0;
}
