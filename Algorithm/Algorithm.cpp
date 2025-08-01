#include <iostream>

struct Test
{
    int x,y;
    Test(int X,int Y) :x(X),y(Y){}

    friend std::ostream& operator << (std::ostream& os ,const Test& t)
    {
        os<<t.x<<" "<<t.y;
        return os;
    }

    Test(const Test& t) :x(t.x),y(t.y)
    {
        std::cout<<"构造"<<std::endl;
    }

    Test operator++() // ++Test
    {
        x++;
        y++;
        return *this;
    }
    Test operator++(int) // Test++
    {
        Test temp = *this;
        x++;
        y++;
        return temp;
    }
    
    Test operator/(const Test& other) const
    {
        return Test{x/other.x,y/other.y};
    }
    Test operator*(const Test& other) const
    {
        return Test{x*other.x,y*other.y};
    }
    
    Test operator-(const Test& other) const
    {
        return Test{x-other.x,y-other.y};
    }
    Test operator+(const Test& other) const
    {
        return Test{x+other.x,y+other.y};
    }

    bool operator == (const Test &t) const
    {
        return x == t.x && y == t.y;
    }
    bool operator != (const Test &t) const
    {
        return !(*this == t);
    }
    
    bool operator < (const Test &t) const
    {
        return (this->x+this->y) < (t.x+t.y);
    }
    bool operator > (const Test &t) const
    {
        return (this->x+this->y) > (t.x+t.y);
    }
};

int main()
{
    /*
     * Test a{}与Test a()的区别
     1. double dx = 1.5, dy = 2.5;
       Test t1(dx, dy);  // 允许：double→int 窄化转换（警告）
       Test t2{dx, dy};  // 错误：禁止窄化转换（编译失败）
       
                        特性	Test(x, y) (圆括号)	    Test{x, y} (花括号)
        窄化转换检查	    允许窄化转换（可能警告）	    禁止窄化转换（编译错误）
        初始化列表优先级	调用普通构造函数	            优先匹配 initializer_list 构造函数
        聚合初始化	    不能用于聚合类型	            可以用于聚合类型
        语法歧义	        可能有函数声明歧义	            无歧义

        窄化转换就是指隐式的 大数(空间)变小数
        比如 double->int long->int int->unsigned int

        聚合类型就是当不存在构造函数时,
        Test a{1,1}仍然能构造出对象但是Test a(1,1)不行
        顺序是严格遵守成员变量的声明顺序
     */
    Test a{1,2};
    Test b{3,4};
    Test c{5,6};
    Test d{5,6};
    
    if (c>b)
        std::cout<<"c :" << c << "  >  " << "b :" << b <<std::endl;
    if (a<b)
        std::cout<<"a :" << a << "  <  " << "b :" << b <<std::endl;
    if (c==d)
        std::cout<<"c :" << c << "  =  " << "d :" << d <<std::endl;
    if (a!=b)    
        std::cout<<"a :" << a << "  !=  " << "b :" << b <<std::endl;

    Test e = a+b;
        std::cout<<"e :" << e << "  =  " << "a :" << a.x  << " " << a.y << " + " << "b :" << b <<std::endl;
    Test f = a-b;
        std::cout<<"f :" << f << "  =  " << "a :" << a.x  << " " << a.y << " - " << "b :" << b <<std::endl;
    Test g = a*b;
        std::cout<<"g :" << g << "  =  " << "a :" << a.x  << " " << a.y << " * " << "b :" << b <<std::endl;
    Test h = a/b;
        std::cout<<"h :" << h << "  =  " << "a :" << a.x  << " " << a.y << " / " << "b :" << b <<std::endl;

    Test t{0,0};
    std::cout<<"t :" << t <<std::endl;
    t++;
    std::cout<<"t++ :" << t <<std::endl;
    ++t;
    std::cout<<"++t :" << t <<std::endl;
    
    return 0;
}