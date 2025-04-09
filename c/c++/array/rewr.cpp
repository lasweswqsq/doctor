#include<iostream>
using namespace std;
int main(){
    class DArray
{
private:
	double *m_Data;  // 存放数组的动态内存指针
	int m_Size;      // 数组的元素个数
	int m_Max;       // 预留给动态数组的内存大小
private:
	void Init();     // 初始化
	void Free();     // 释放动态内存
	inline bool InvalidateIndex(int nIndex);  // 判断下标的合法性
public:
	DArray();        // 默认构造函数
	DArray(int nSize, double dValue = 0);  // 构造函数，设置数组大小，默认值为dValue
	DArray(const DArray& arr);  // 拷贝构造函数
	DArray& operator=(const DArray& arr);  // 拷贝赋值运算符
	~DArray();       // 析构函数

	void Print();    // 输出显式所有数组元素的值
	int GetSize(){
        return m_Size;
    };   // 获取数组的大小（元素个数）
	void SetSize(int nSize){};  // 重新设置数组的大小，若nSize小于原大小，截断；否则，新元素置0
	double GetAt(int nIndex);  // 获取指定位置元素
	void SetAt(int nIndex,double dValue); // 重置指定元素的值
	void PushBack(double dValue);  // 追加一个新元素到数组末尾
	void DeleteAt(int nIndex);     // 删除指定位置地元素
	void InsertAt(int nIndex, double dValue);  // 插入一个新的元素到数组中
	double operator[](int nIndex) const;      // 重载下标运算符[]
};
}