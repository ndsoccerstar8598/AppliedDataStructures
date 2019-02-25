#include <iostream>
#include <chrono>
#include <utility>
#include <algorithm>

using namespace std;

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

template<typename F, typename... Args>
double funcTime(F func, Args&&... args){
    TimeVar t1=timeNow();
    func(std::forward<Args>(args)...);
    return duration(timeNow()-t1);
}

typedef std::string String;

//first test function doing something
int countCharInString(String s, char delim){
    int count=0;
    String::size_type pos = s.find_first_of(delim);
    while ((pos = s.find_first_of(delim, pos)) != String::npos){
        count++;pos++;
    }
    return count;
}

//second test function doing the same thing in different way
int countWithAlgorithm(String s, char delim){
    return std::count(s.begin(),s.end(),delim);
}


int main(){
    std::cout<<"norm: "<<funcTime(countCharInString,"precision=10",'=')<<"\n";
    std::cout<<"algo: "<<funcTime(countWithAlgorithm,"precision=10",'=');
    return 0;
}
