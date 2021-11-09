*学习一下copy用法
将thelinelist.m_pelement到thelinelist.m_pelement + m_nArrayListSize内容复制到 m_pelement，并且是从开始的位置开始。
如：
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int array[] = { 1,2,3,4,5 };
    vector<int> arraybycopyVec;
    arraybycopyVec.resize(7);//开辟了7个元素的空间
    copy(array, array + 5, arraybycopyVec.begin());
    for (size_t i = 0;i<arraybycopyVec.size();i++)
        cout << arraybycopyVec[i] << endl;
}

*学习一下find的系列函数以及search系列函数
主要是find，find_if,find_if_not,find_end,find_first_of,adjacent_find,search,serch_n
find 语法格式：
 InputIterator find (InputIterator first, InputIterator last, const T& val);
其中，first 和 last 为输入迭代器，[first, last) 用于指定该函数的查找范围；val 为要查找的目标元素。该函数适用于所有序列式容器。
这里first和last的类型是输入迭代器，返回的是一个迭代器。
    当 find() 函数查找成功时，其指向的是在 [first, last) 区域内查找到的第一个目标元素；如果查找失败，则该迭代器的指向和 last 相同。
     值得一提的是，find() 函数的底层实现，其实就是用==运算符将 val 和 [first, last) 区域内的元素逐个进行比对。这也就意味着，[first, last) 区域内的元素必须支持==运算符。
find_if语法格式：
InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred);
其中，first 和 last 都为输入迭代器，其组合 [first, last) 用于指定要查找的区域；pred 用于自定义查找规则。
值得一提的是，由于 first 和 last 都为输入迭代器，意味着该函数适用于所有的序列式容器。甚至当采用适当的谓词函数时，该函数还适用于所有的关联式容器（包括哈希容器）。
同时，该函数会返回一个输入迭代器，当查找成功时，该迭代器指向的是第一个符合查找规则的元素；反之，如果 find_if() 函数查找失败，则该迭代器的指向和 last 迭代器相同。
find_if_not
find_if_not() 函数和 find_if() 函数的功能恰好相反，通过上面的学习我们知道，find_if() 函数用于查找符合谓词函数规则的第一个元素，而 find_if_not() 函数则用于查找第一个不符合谓词函数规则的元素。
    find_if_not() 函数的语法规则如下所示：
InputIterator find_if_not (InputIterator first, InputIterator last, UnaryPredicate pred);
其中，first 和 last 都为输入迭代器，[first, last) 用于指定查找范围；pred 用于自定义查找规则。
和 find_if() 函数一样，find_if_not() 函数也适用于所有的容器，包括所有序列式容器和关联式容器。
同样，该函数也会返回一个输入迭代器，当 find_if_not() 函数查找成功时，该迭代器指向的是查找到的那个元素；反之，如果查找失败，该迭代器的指向和 last 迭代器相同。
find_end() 
函数定义在<algorithm>头文件中，常用于在序列 A 中查找序列 B 最后一次出现的位置。 
例如，有如下 2 个序列：
序列 A：1,2,3,4,5,1,2,3,4,5
序列 B：1,2,3
通过观察不难发现，序列 B 在序列 A 中出现了 2 次，而借助 find_end() 函数，可以轻松的得到序列 A 中最后一个（也就是第 2 个） {1,2,3}。
find_end() 函数的语法格式有 2 种：
//查找序列 [first1, last1) 中最后一个子序列 [first2, last2)
ForwardIterator find_end (ForwardIterator first1, ForwardIterator last1,
                          ForwardIterator first2, ForwardIterator last2);
//查找序列 [first2, last2) 中，和 [first2, last2) 序列满足 pred 规则的最后一个子序列
ForwardIterator find_end (ForwardIterator first1, ForwardIterator last1,
                          ForwardIterator first2, ForwardIterator last2,
                          BinaryPredicate pred);
其中，各个参数的含义如下：
（1）first1、last1：都为正向迭代器，其组合 [first1, last1) 用于指定查找范围（也就是上面例子中的序列 A）；
（2）first2、last2：都为正向迭代器，其组合 [first2, last2) 用于指定要查找的序列（也就是上面例子中的序列 B）；
（3）pred：用于自定义查找规则。该规则实际上是一个包含 2 个参数且返回值类型为 bool 的函数（第一个参数接收 [first1, last1) 范围内的元素，第二个参数接收 [first2, last2) 范围内的元素）。函数定义的形式可以是普通函数，也可以是函数对象。
实际上，第一种语法格式也可以看做是包含一个默认的 pred 参数，该参数指定的是一种相等规则，即在 [first1, last1) 范围内查找和 [first2, last2) 中各个元素对应相等的子序列；而借助第二种语法格式，我们可以自定义一个当前场景需要的匹配规则。
同时，find_end() 函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向查找到的子序列中的第一个元素；反之，如果查找失败，则该迭代器的指向和 last1 迭代器相同。
find_first_of：
我们可能需要在 A 序列中查找和 B 序列中任意元素相匹配的第一个元素，这时就可以使用 find_first_of() 函数。
ind_first_of() 函数有 2 种语法格式，分别是：
//以判断两者相等作为匹配规则
InputIterator find_first_of (InputIterator first1, InputIterator last1,
                             ForwardIterator first2, ForwardIterator last2);
//以 pred 作为匹配规则
InputIterator find_first_of (InputIterator first1, InputIterator last1,
                             ForwardIterator first2, ForwardIterator last2,
                             BinaryPredicate pred);
其中，各个参数的含义如下：
（1）first1、last1：都为输入迭代器，它们的组合 [first1, last1) 用于指定该函数要查找的范围；
（2）first2、last2：都为正向迭代器，它们的组合 [first2, last2) 用于指定要进行匹配的元素所在的范围；
（3）pred：可接收一个包含 2 个形参且返回值类型为 bool 的函数，该函数可以是普通函数（又称为二元谓词函数），也可以是函数对象。
有关谓词函数，读者可阅读《C++谓词函数》一节详细了解。
find_first_of() 函数用于在 [first1, last1) 范围内查找和 [first2, last2) 中任何元素相匹配的第一个元素。如果匹配成功，该函数会返回一个指向该元素的输入迭代器；反之，则返回一个和 last1 迭代器指向相同的输入迭代器。
值得一提的是，不同语法格式的匹配规则也是不同的：
（1）第 1 种语法格式：逐个取 [first1, last1) 范围内的元素（假设为 A），和 [first2, last2) 中的每个元素（假设为 B）做 A==B 运算，如果成立则匹配成功；
（2）第 2 种语法格式：逐个取 [first1, last1) 范围内的元素（假设为 A），和 [first2, last2) 中的每个元素（假设为 B）一起带入 pred(A, B) 谓词函数，如果函数返回 true 则匹配成功。
注意，当采用第一种语法格式时，如果 [first1, last1) 或者 [first2, last2) 范围内的元素类型为自定义的类对象或者结构体变量，此时应对 == 运算符进行重载，使其适用于当前场景。
adjacent_find：adjacent_find() 函数用于在指定范围内查找 2 个连续相等的元素。该函数的语法格式为：
//查找 2 个连续相等的元素
ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last);
//查找 2 个连续满足 pred 规则的元素
ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last,
                               BinaryPredicate pred);
其中，first 和 last 都为正向迭代器，其组合 [first, last) 用于指定该函数的查找范围；pred 用于接收一个包含 2 个参数且返回值类型为 bool 的函数，以实现自定义查找规则。
值得一提的是，pred 参数接收的函数既可以定义为普通函数，也可以用函数对象的形式定义。有关谓词函数，读者可阅读《C++谓词函数》一节详细了解。
另外，该函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向的是连续相等元素的第 1 个元素；而如果查找失败，该迭代器的指向和 last 迭代器相同。
Search  search() 函数定义在<algorithm>头文件中，其功能恰好和 find_end() 函数相反，用于在序列 A 中查找序列 B 第一次出现的位置。
例如，仍以如下两个序列为例：
序列 A：1,2,3,4,5,1,2,3,4,5
序列 B：1,2,3
可以看到，序列 B 在序列 A 中出现了 2 次。借助 find_end() 函数，我们可以找到序列 A 中最后一个（也就是第 2 个）{1,2,3}；而借助 search() 函数，我们可以找到序列 A 中第 1 个 {1,2,3}。
和 find_end() 相同，search() 函数也提供有以下 2 种语法格式：
//查找 [first1, last1) 范围内第一个 [first2, last2) 子序列
ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
                        ForwardIterator first2, ForwardIterator last2);
//查找 [first1, last1) 范围内，和 [first2, last2) 序列满足 pred 规则的第一个子序列
ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
                        ForwardIterator first2, ForwardIterator last2,
                        BinaryPredicate pred);
其中，各个参数的含义分别为：
（1）first1、last1：都为正向迭代器，其组合 [first1, last1) 用于指定查找范围（也就是上面例子中的序列 A）；
（2）first2、last2：都为正向迭代器，其组合 [first2, last2) 用于指定要查找的序列（也就是上面例子中的序列 B）；
（3）pred：用于自定义查找规则。该规则实际上是一个包含 2 个参数且返回值类型为 bool 的函数（第一个参数接收 [first1, last1) 范围内的元素，第二个参数接收 [first2, last2) 范围内的元素）。函数定义的形式可以是普通函数，也可以是函数对象。
实际上，第一种语法格式也可以看做是包含一个默认的 pred 参数，该参数指定的是一种相等规则，即在 [first1, last1) 范围内查找和 [first2, last2) 中各个元素对应相等的子序列；而借助第二种语法格式，我们可以自定义一个当前场景需要的匹配规则。
同时，search() 函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向查找到的子序列中的第一个元素；反之，如果查找失败，则该迭代器的指向和 last1 迭代器相同。
serch_n 和 search() 一样，search_n() 函数也定义在<algorithm>头文件中，用于在指定区域内查找第一个符合要求的子序列。不同之处在于，前者查找的子序列中可包含多个不同的元素，而后者查找的只能是包含多个相同元素的子序列。
例子：
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> A{ 1,2,3,4,5,1,2,3,4 ,15,10,1,1,1};
    vector<int> B{ 1,2,3 };
    vector<int> C{ 1,1,1 };
    vector<int>::iterator iter;
    iter = find(A.begin(), A.end(), 15);
    cout << *iter << endl;
    /*iter = find(A.begin(), A.end(),mycompare(19));
	cout << *iter << endl;*/
  /*  iter = find_if_not(A.begin(), A.end(), A[2] != 10);
	cout << *iter << endl;*/
	iter = find_end(A.begin(), A.end(), B.begin(), B.end());
	cout << *iter << endl;

	iter = find_first_of(A.begin(), A.end(), B.begin(), B.end());
	cout << *iter << endl;
	iter = search(A.begin(), A.end(), B.begin(), B.end());
	cout << *iter << endl;
	iter = search_n(A.begin(), A.end(), 3, 1);
	cout << *iter << endl;
}

*学习一下copy_backward
copy_backward 不要被 copy_backward() 算法的名称所误导，它不会逆转元素的顺序。它只会像 copy() 那样复制元素，但是从最后一个元素开始直到第一个元素。
    copy_backward() 会复制前两个迭代器参数指定的序列。第三个参数是目的序列的结束迭代器，通过将源序列中的最后一个元素复制到目的序列的结束迭代器之前，源序列会被复制到目的序列中，如图 1 所示。copy_backward() 的 3 个参数都必须是可以自增或自减的双向迭代器，这意味着这个算法只能应用到序列容器的序列上。
reverse_copy() 算法可以将源序列复制到目的序列中，目的序列中的元素是逆序的。定义源序列的前两个迭代器参数必须是双向迭代器。目的序列由第三个参数指定，它是目的序列的开始迭代器，也是一个输出迭代器。如果序列是重叠的，函数的行为是未定义的。这个算法会返回一个输出迭代器，它指向目的序列最后一个元素的下一个位置。
