*ѧϰһ��copy�÷�
��thelinelist.m_pelement��thelinelist.m_pelement + m_nArrayListSize���ݸ��Ƶ� m_pelement�������Ǵӿ�ʼ��λ�ÿ�ʼ��
�磺
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int array[] = { 1,2,3,4,5 };
    vector<int> arraybycopyVec;
    arraybycopyVec.resize(7);//������7��Ԫ�صĿռ�
    copy(array, array + 5, arraybycopyVec.begin());
    for (size_t i = 0;i<arraybycopyVec.size();i++)
        cout << arraybycopyVec[i] << endl;
}

*ѧϰһ��find��ϵ�к����Լ�searchϵ�к���
��Ҫ��find��find_if,find_if_not,find_end,find_first_of,adjacent_find,search,serch_n
find �﷨��ʽ��
 InputIterator find (InputIterator first, InputIterator last, const T& val);
���У�first �� last Ϊ�����������[first, last) ����ָ���ú����Ĳ��ҷ�Χ��val ΪҪ���ҵ�Ŀ��Ԫ�ء��ú�����������������ʽ������
����first��last����������������������ص���һ����������
    �� find() �������ҳɹ�ʱ����ָ������� [first, last) �����ڲ��ҵ��ĵ�һ��Ŀ��Ԫ�أ��������ʧ�ܣ���õ�������ָ��� last ��ͬ��
     ֵ��һ����ǣ�find() �����ĵײ�ʵ�֣���ʵ������==������� val �� [first, last) �����ڵ�Ԫ��������бȶԡ���Ҳ����ζ�ţ�[first, last) �����ڵ�Ԫ�ر���֧��==�������
find_if�﷨��ʽ��
InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred);
���У�first �� last ��Ϊ���������������� [first, last) ����ָ��Ҫ���ҵ�����pred �����Զ�����ҹ���
ֵ��һ����ǣ����� first �� last ��Ϊ�������������ζ�Ÿú������������е�����ʽ�����������������ʵ���ν�ʺ���ʱ���ú��������������еĹ���ʽ������������ϣ��������
ͬʱ���ú����᷵��һ������������������ҳɹ�ʱ���õ�����ָ����ǵ�һ�����ϲ��ҹ����Ԫ�أ���֮����� find_if() ��������ʧ�ܣ���õ�������ָ��� last ��������ͬ��
find_if_not
find_if_not() ������ find_if() �����Ĺ���ǡ���෴��ͨ�������ѧϰ����֪����find_if() �������ڲ��ҷ���ν�ʺ�������ĵ�һ��Ԫ�أ��� find_if_not() ���������ڲ��ҵ�һ��������ν�ʺ��������Ԫ�ء�
    find_if_not() �������﷨����������ʾ��
InputIterator find_if_not (InputIterator first, InputIterator last, UnaryPredicate pred);
���У�first �� last ��Ϊ�����������[first, last) ����ָ�����ҷ�Χ��pred �����Զ�����ҹ���
�� find_if() ����һ����find_if_not() ����Ҳ���������е�������������������ʽ�����͹���ʽ������
ͬ�����ú���Ҳ�᷵��һ��������������� find_if_not() �������ҳɹ�ʱ���õ�����ָ����ǲ��ҵ����Ǹ�Ԫ�أ���֮���������ʧ�ܣ��õ�������ָ��� last ��������ͬ��
find_end() 
����������<algorithm>ͷ�ļ��У������������� A �в������� B ���һ�γ��ֵ�λ�á� 
���磬������ 2 �����У�
���� A��1,2,3,4,5,1,2,3,4,5
���� B��1,2,3
ͨ���۲첻�ѷ��֣����� B ������ A �г����� 2 �Σ������� find_end() �������������ɵĵõ����� A �����һ����Ҳ���ǵ� 2 ���� {1,2,3}��
find_end() �������﷨��ʽ�� 2 �֣�
//�������� [first1, last1) �����һ�������� [first2, last2)
ForwardIterator find_end (ForwardIterator first1, ForwardIterator last1,
                          ForwardIterator first2, ForwardIterator last2);
//�������� [first2, last2) �У��� [first2, last2) �������� pred ��������һ��������
ForwardIterator find_end (ForwardIterator first1, ForwardIterator last1,
                          ForwardIterator first2, ForwardIterator last2,
                          BinaryPredicate pred);
���У����������ĺ������£�
��1��first1��last1����Ϊ���������������� [first1, last1) ����ָ�����ҷ�Χ��Ҳ�������������е����� A����
��2��first2��last2����Ϊ���������������� [first2, last2) ����ָ��Ҫ���ҵ����У�Ҳ�������������е����� B����
��3��pred�������Զ�����ҹ��򡣸ù���ʵ������һ������ 2 �������ҷ���ֵ����Ϊ bool �ĺ�������һ���������� [first1, last1) ��Χ�ڵ�Ԫ�أ��ڶ����������� [first2, last2) ��Χ�ڵ�Ԫ�أ��������������ʽ��������ͨ������Ҳ�����Ǻ�������
ʵ���ϣ���һ���﷨��ʽҲ���Կ����ǰ���һ��Ĭ�ϵ� pred �������ò���ָ������һ����ȹ��򣬼��� [first1, last1) ��Χ�ڲ��Һ� [first2, last2) �и���Ԫ�ض�Ӧ��ȵ������У��������ڶ����﷨��ʽ�����ǿ����Զ���һ����ǰ������Ҫ��ƥ�����
ͬʱ��find_end() �����᷵��һ����������������������ҳɹ�ʱ���õ�����ָ����ҵ����������еĵ�һ��Ԫ�أ���֮���������ʧ�ܣ���õ�������ָ��� last1 ��������ͬ��
find_first_of��
���ǿ�����Ҫ�� A �����в��Һ� B ����������Ԫ����ƥ��ĵ�һ��Ԫ�أ���ʱ�Ϳ���ʹ�� find_first_of() ������
ind_first_of() ������ 2 ���﷨��ʽ���ֱ��ǣ�
//���ж����������Ϊƥ�����
InputIterator find_first_of (InputIterator first1, InputIterator last1,
                             ForwardIterator first2, ForwardIterator last2);
//�� pred ��Ϊƥ�����
InputIterator find_first_of (InputIterator first1, InputIterator last1,
                             ForwardIterator first2, ForwardIterator last2,
                             BinaryPredicate pred);
���У����������ĺ������£�
��1��first1��last1����Ϊ��������������ǵ���� [first1, last1) ����ָ���ú���Ҫ���ҵķ�Χ��
��2��first2��last2����Ϊ��������������ǵ���� [first2, last2) ����ָ��Ҫ����ƥ���Ԫ�����ڵķ�Χ��
��3��pred���ɽ���һ������ 2 ���β��ҷ���ֵ����Ϊ bool �ĺ������ú�����������ͨ�������ֳ�Ϊ��Ԫν�ʺ�������Ҳ�����Ǻ�������
�й�ν�ʺ��������߿��Ķ���C++ν�ʺ�����һ����ϸ�˽⡣
find_first_of() ���������� [first1, last1) ��Χ�ڲ��Һ� [first2, last2) ���κ�Ԫ����ƥ��ĵ�һ��Ԫ�ء����ƥ��ɹ����ú����᷵��һ��ָ���Ԫ�ص��������������֮���򷵻�һ���� last1 ������ָ����ͬ�������������
ֵ��һ����ǣ���ͬ�﷨��ʽ��ƥ�����Ҳ�ǲ�ͬ�ģ�
��1���� 1 ���﷨��ʽ�����ȡ [first1, last1) ��Χ�ڵ�Ԫ�أ�����Ϊ A������ [first2, last2) �е�ÿ��Ԫ�أ�����Ϊ B���� A==B ���㣬���������ƥ��ɹ���
��2���� 2 ���﷨��ʽ�����ȡ [first1, last1) ��Χ�ڵ�Ԫ�أ�����Ϊ A������ [first2, last2) �е�ÿ��Ԫ�أ�����Ϊ B��һ����� pred(A, B) ν�ʺ���������������� true ��ƥ��ɹ���
ע�⣬�����õ�һ���﷨��ʽʱ����� [first1, last1) ���� [first2, last2) ��Χ�ڵ�Ԫ������Ϊ�Զ�����������߽ṹ���������ʱӦ�� == ������������أ�ʹ�������ڵ�ǰ������
adjacent_find��adjacent_find() ����������ָ����Χ�ڲ��� 2 ��������ȵ�Ԫ�ء��ú������﷨��ʽΪ��
//���� 2 ��������ȵ�Ԫ��
ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last);
//���� 2 ���������� pred �����Ԫ��
ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last,
                               BinaryPredicate pred);
���У�first �� last ��Ϊ���������������� [first, last) ����ָ���ú����Ĳ��ҷ�Χ��pred ���ڽ���һ������ 2 �������ҷ���ֵ����Ϊ bool �ĺ�������ʵ���Զ�����ҹ���
ֵ��һ����ǣ�pred �������յĺ����ȿ��Զ���Ϊ��ͨ������Ҳ�����ú����������ʽ���塣�й�ν�ʺ��������߿��Ķ���C++ν�ʺ�����һ����ϸ�˽⡣
���⣬�ú����᷵��һ����������������������ҳɹ�ʱ���õ�����ָ������������Ԫ�صĵ� 1 ��Ԫ�أ����������ʧ�ܣ��õ�������ָ��� last ��������ͬ��
Search  search() ����������<algorithm>ͷ�ļ��У��书��ǡ�ú� find_end() �����෴������������ A �в������� B ��һ�γ��ֵ�λ�á�
���磬����������������Ϊ����
���� A��1,2,3,4,5,1,2,3,4,5
���� B��1,2,3
���Կ��������� B ������ A �г����� 2 �Ρ����� find_end() ���������ǿ����ҵ����� A �����һ����Ҳ���ǵ� 2 ����{1,2,3}�������� search() ���������ǿ����ҵ����� A �е� 1 �� {1,2,3}��
�� find_end() ��ͬ��search() ����Ҳ�ṩ������ 2 ���﷨��ʽ��
//���� [first1, last1) ��Χ�ڵ�һ�� [first2, last2) ������
ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
                        ForwardIterator first2, ForwardIterator last2);
//���� [first1, last1) ��Χ�ڣ��� [first2, last2) �������� pred ����ĵ�һ��������
ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
                        ForwardIterator first2, ForwardIterator last2,
                        BinaryPredicate pred);
���У����������ĺ���ֱ�Ϊ��
��1��first1��last1����Ϊ���������������� [first1, last1) ����ָ�����ҷ�Χ��Ҳ�������������е����� A����
��2��first2��last2����Ϊ���������������� [first2, last2) ����ָ��Ҫ���ҵ����У�Ҳ�������������е����� B����
��3��pred�������Զ�����ҹ��򡣸ù���ʵ������һ������ 2 �������ҷ���ֵ����Ϊ bool �ĺ�������һ���������� [first1, last1) ��Χ�ڵ�Ԫ�أ��ڶ����������� [first2, last2) ��Χ�ڵ�Ԫ�أ��������������ʽ��������ͨ������Ҳ�����Ǻ�������
ʵ���ϣ���һ���﷨��ʽҲ���Կ����ǰ���һ��Ĭ�ϵ� pred �������ò���ָ������һ����ȹ��򣬼��� [first1, last1) ��Χ�ڲ��Һ� [first2, last2) �и���Ԫ�ض�Ӧ��ȵ������У��������ڶ����﷨��ʽ�����ǿ����Զ���һ����ǰ������Ҫ��ƥ�����
ͬʱ��search() �����᷵��һ����������������������ҳɹ�ʱ���õ�����ָ����ҵ����������еĵ�һ��Ԫ�أ���֮���������ʧ�ܣ���õ�������ָ��� last1 ��������ͬ��
serch_n �� search() һ����search_n() ����Ҳ������<algorithm>ͷ�ļ��У�������ָ�������ڲ��ҵ�һ������Ҫ��������С���֮ͬ�����ڣ�ǰ�߲��ҵ��������пɰ��������ͬ��Ԫ�أ������߲��ҵ�ֻ���ǰ��������ͬԪ�ص������С�
���ӣ�
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

*ѧϰһ��copy_backward
copy_backward ��Ҫ�� copy_backward() �㷨���������󵼣���������תԪ�ص�˳����ֻ���� copy() ��������Ԫ�أ����Ǵ����һ��Ԫ�ؿ�ʼֱ����һ��Ԫ�ء�
    copy_backward() �Ḵ��ǰ��������������ָ�������С�������������Ŀ�����еĽ�����������ͨ����Դ�����е����һ��Ԫ�ظ��Ƶ�Ŀ�����еĽ���������֮ǰ��Դ���лᱻ���Ƶ�Ŀ�������У���ͼ 1 ��ʾ��copy_backward() �� 3 �������������ǿ����������Լ���˫�������������ζ������㷨ֻ��Ӧ�õ����������������ϡ�
reverse_copy() �㷨���Խ�Դ���и��Ƶ�Ŀ�������У�Ŀ�������е�Ԫ��������ġ�����Դ���е�ǰ��������������������˫���������Ŀ�������ɵ���������ָ��������Ŀ�����еĿ�ʼ��������Ҳ��һ�����������������������ص��ģ���������Ϊ��δ����ġ�����㷨�᷵��һ���������������ָ��Ŀ���������һ��Ԫ�ص���һ��λ�á�
