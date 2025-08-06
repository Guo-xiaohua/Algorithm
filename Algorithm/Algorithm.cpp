#include <iostream>
#include <bitset>
#include <sstream>
#include <string>

int main()
{
    /*
     * 十进制转二,八,十六进制 
     */
    int a = 10;
    std::stringstream s;
    s<<std::bitset<8>(a);
    
    std::string d;
    s>>d;
    std::string o;
    s.clear();
    s<<std::oct<<a;
    s>>o;
    std::string h;
    s.clear();
    s<<std::hex<<a;
    s>>h;
    
    std::cout<<"10 :" << d <<std::endl;
    std::cout<<"8 :" << o <<std::endl;
    std::cout<<"16 :" << h << std::endl;

    /*
     * 二,八,十六进制转十进制
     */
    
    std::string bin = "1111011";       // 123
    std::string oct = "173";           // 123
    std::string hex = "7B";            // 123
    
    std::cout<<"--------------------------------------"<<std::endl;
    
    std::cout<< "2 :"<<std::stoi(bin,nullptr,2)<<std::endl;
    std::cout<< "8 :"<<std::stoi(oct,nullptr,8)<<std::endl;
    std::cout<< "16 :"<<std::stoi(hex,nullptr,16)<<std::endl;
    
    return 0;
}