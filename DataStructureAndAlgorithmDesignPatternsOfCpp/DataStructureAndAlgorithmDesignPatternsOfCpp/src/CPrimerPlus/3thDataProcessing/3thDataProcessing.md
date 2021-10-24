#代表的是目录级数
*斜体
**加粗
***斜体加粗
参考网址：https://blog.csdn.net/weixin_45073036/article/details/107434191


#第三章 处理数据

##本章知识点

###一，命名规则
###二,整型
###三，浮点型
###四，算术运算符
###五，自动类型转换
###六，强制类型转换
###七，常量和const用法



###一，命名规则
###二,整型
###三，浮点型
###四，算术运算符
###五，自动类型转换
###六，强制类型转换




###七，常量和const用法

####重点：主要有以下疑惑，什么时候用，如何与*，&搭配用。
####主要有以下几个方面，
1.作为常量
2.函数输入参数
3.函数返回参数
4.在类中作为成员属性
5.在类中修饰成员函数


1.作为常量
（1）常量：分为字面常量，const/#define符号常量，枚举
（2）字面常量，1，2整型常量，'h','e','l'字符常量，”hello world“字符串常量
字面常量是保存在符号表里里面，不是在数据区，所以不能取地址，除了字符串。

char *pChar = "abcbdd";//取字符串常量地址
*(pChar+3) = 'k';//也是不行的 
int *iNum = &6;//这种是错误的 

（3）const 常量,***它的内存保存在哪里？***
注意：1）对于基本数据类型的常量，编译器将其放在符号表中
     2） 对于ADT/UDT数据类型就是保存在存储空间中

     以下例子就是区别：
    const int iNum = 1;
    const char  = 'h';
    const std::string = "hello";//有‘\0’才是字符串

    const long lngNum  = 10；
    long *pl = (long*)&lngNum;//得到常量的值,这里copy出一个lngNum对象出来了赋值给*pl
    *pl = 1000;//这样区修改
    std::cout<<lngNum<<std::endl;//10
    std::cout<<*pl<<std::endl;   //1000

    class Integer{
    public:
        Integer():m_lng(100){}
        long m_lng;

    }
    const Integer int_1;
    Integer *pInt = (Integer*)&int_1;
    pInt->m_lng = 1000;
    std::cout<<pInt->m_lng<<std::endl;//1000
    std::cout<<int_1.m_lng<<std::endl;//1000

    标准c++ 在头文件中定义const，那么在多个编译单元包含的时候，
    编译器将其认为是不同的常量之后连接的时候进行合并
（4）#define常量
    #define MAX_SIZE    1000
    #define CLASS_NAME  "chongrui.lu"

    #define 不能调试，const可以调试，有定义类型,
    带参数的宏可以省掉很多代码

(5)枚举
    typef enum {
        BOY = 0,
        GIRL
    } enSexType;
enum默认是整型

2.函数输入参数
输入参数有三种方式：值传递，引用传递，指针传递

（1）指针的话，如果只是作输入，加const更好。
const char *strSource
char * const strSoure 
**这两者的区别是什么？**

（2）对于ADT/UDT类型，复制，析构，效率比较低，所以一般使用引用传递。
（3）非ADT/UDT类型，就不需要引用
（4）担心变化就加const，多次使用输入初值，不改变。
    
3.函数输出参数

返回值 有return和输出参数两种方式。
对于ADT/UDT类型 返回指针，引用，对象
（1）如果返回值是“值传递”，那么在一般情况下由于函数会返回值拷贝到外部临时的存储单元，加const没有意义。
（2）一般返回值为引用传递的情况不多，赋值函数一般是
（3）指针添加const，左值也得加const char *str = GetString();

4.在类中修饰成员属性
  这个就是之前说的关于类中的常量问题在代码中有体现，但是那个构造函数表重视报错，得仔细研究一下
5.在类中修饰成员函数
  为了防止修改成员变量







