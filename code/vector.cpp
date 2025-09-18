#include <iostream>
#include <vector>
using namespace std;

// 打印vector的辅助函数
void printVector(vector<int>& v) {
    cout << "[ ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "]" << endl;
}

// 1. vector的构造函数测试
void test01() {
    cout << "\n=== 1. vector构造函数测试 ===" << endl;
    
    vector<int> v1; // 默认构造函数
    for (int i = 0; i < 5; ++i) {
        v1.push_back(i); // 向v1末尾添加数据
    }
    
    vector<int> v2(v1.begin(), v1.end()); // 区间构造
    vector<int> v3(5, 5); // n个elem构造
    vector<int> v4(v3); // 拷贝构造函数
    
    cout << "v1: ";
    printVector(v1);
    cout << "v2(区间构造): ";
    printVector(v2);
    cout << "v3(5个5): ";
    printVector(v3);
    cout << "v4(拷贝v3): ";
    printVector(v4);
}

// 2. vector的赋值操作测试
void test02() {
    cout << "\n=== 2. vector赋值操作测试 ===" << endl;
    
    vector<int> v1, v2;
    for (int i = 0; i < 5; ++i) {
        v1.push_back(i);
    }
    
    v2 = v1; // 赋值运算符重载
    
    vector<int> v3, v4;
    v3.assign(v1.begin(), v1.end()); // 区间赋值
    v4.assign(5, 9); // n个elem赋值
    
    cout << "v1: ";
    printVector(v1);
    cout << "v2(=赋值): ";
    printVector(v2);
    cout << "v3(区间赋值): ";
    printVector(v3);
    cout << "v4(5个9): ";
    printVector(v4);
}

// 3. vector的容量与大小测试
void test03() {
    cout << "\n=== 3. vector容量与大小测试 ===" << endl;
    
    vector<int> v1;
    if (v1.empty()) { // 判断容器是否为空
        for (int i = 0; i < 5; ++i) {
            v1.push_back(i);
        }
    }
    
    cout << "初始v1: ";
    printVector(v1);
    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;
    cout << "v1是否为空：" << (v1.empty() ? "是" : "否") << endl;
    
    // 重新指定容器大小使其变长
    v1.resize(10); // 增加的长度默认值为0
    cout << "\nresize(10)后，v1: ";
    printVector(v1);
    cout << "容量：" << v1.capacity() << "，大小：" << v1.size() << endl;
    
    v1.resize(15, 9); // 增加的长度赋值为9
    cout << "\nresize(15,9)后，v1: ";
    printVector(v1);
    cout << "容量：" << v1.capacity() << "，大小：" << v1.size() << endl;
    
    // 重新指定容器大小使其变短
    v1.resize(10);
    cout << "\nresize(10)缩短后，v1: ";
    printVector(v1);
    cout << "容量：" << v1.capacity() << "，大小：" << v1.size() << endl;
    
    v1.resize(5, 9);
    cout << "\nresize(5,9)缩短后，v1: ";
    printVector(v1);
    cout << "容量：" << v1.capacity() << "，大小：" << v1.size() << endl;
}

// 4. vector的插入和删除测试
void test04() {
    cout << "\n=== 4. vector插入和删除测试 ===" << endl;
    
    vector<int> v1;
    for (int i = 0; i < 5; ++i) {
        v1.push_back(6); // 尾部插入元素6
    }
    cout << "初始v1: ";
    printVector(v1);
    
    v1.pop_back(); // 删除最后一个元素
    cout << "pop_back()后，v1: ";
    printVector(v1);
    
    v1.insert(v1.begin(), 20); // 在首位插入20
    cout << "insert首位20后，v1: ";
    printVector(v1);
    
    v1.insert(v1.end(), 3, 20); // 在尾部插入3个20
    cout << "insert尾部3个20后，v1: ";
    printVector(v1);
    
    v1.erase(v1.begin()); // 在首位删除一个元素
    cout << "erase首位后，v1: ";
    printVector(v1);
    
    // 保存一些元素用于演示区间删除
    vector<int> v2 = v1;
    v2.erase(v2.begin(), v2.begin() + 2); // 删除前两个元素
    cout << "erase前两个元素后，v2: ";
    printVector(v2);
    
    v1.clear(); // 清空所有元素
    cout << "clear()后，v1大小: " << v1.size() << endl;
}

// 5. vector数据存取测试
void test05() {
    cout << "\n=== 5. vector数据存取测试 ===" << endl;
    
    vector<int> v;
    for (int i = 0; i < 5; ++i) {
        v.push_back(i * 10);
    }
    
    // 利用at访问
    cout << "利用at()访问: ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    
    // 利用[]访问
    cout << "利用[]访问: ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << "容器中第一个元素是：" << v.front() << endl;
    cout << "容器中最后一个元素是：" << v.back() << endl;
    
    // 修改数据
    v.at(0) = 100;
    v[1] = 200;
    cout << "修改前两个元素后: ";
    printVector(v);
}

// 6. vector互换容器测试
void test06_1() {
    cout << "\n=== 6.1 vector互换容器基本使用 ===" << endl;
    
    vector<int> v1, v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(9 - i);
    }
    
    cout << "交换前：" << endl;
    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);
    
    cout << "交换后：" << endl;
    v1.swap(v2); // 调用互换函数
    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);
}

void test06_2() {
    cout << "\n=== 6.2 vector互换容器实际用途(收缩内存) ===" << endl;
    
    vector<int> v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
    }
    
    cout << "初始时：" << endl;
    cout << "v的容量：" << v.capacity() << endl;
    cout << "v的大小：" << v.size() << endl;
    
    cout << "\nresize(10)后：" << endl;
    v.resize(10);
    cout << "v的容量：" << v.capacity() << endl;
    cout << "v的大小：" << v.size() << endl;
    
    // 巧用swap收缩内存
    cout << "\nswap收缩内存后：" << endl;
    vector<int>(v).swap(v); // vector<int>(v) 创建匿名对象并拷贝v的数据
    cout << "v的容量：" << v.capacity() << endl;
    cout << "v的大小：" << v.size() << endl;
}

// 7. vector预留空间测试
void test07() {
    cout << "\n=== 7. vector预留空间测试 ===" << endl;
    
    vector<int> v1, v2;
    v2.reserve(10000); // 给v2设置预留空间，v1不设置
    
    // 对比v1,v2，系统需要动态扩容多少次
    int num1 = 0; // v1扩容次数
    int num2 = 0; // v2扩容次数
    int capacity1 = 0; // v1容量大小
    int capacity2 = 0; // v2容量大小
    
    for (int i = 0; i < 10000; ++i) {
        v1.push_back(i);
        if (capacity1 != v1.capacity()) { // 计算扩容次数
            capacity1 = v1.capacity();
            ++num1;
        }
        
        v2.push_back(i);
        if (capacity2 != v2.capacity()) {
            capacity2 = v2.capacity();
            ++num2;
        }
    }
    
    cout << "插入10000个元素：" << endl;
    cout << "系统对v1(无预留)扩容 " << num1 << " 次，最终容量：" << v1.capacity() << endl;
    cout << "系统对v2(预留10000)扩容 " << num2 << " 次，最终容量：" << v2.capacity() << endl;
    cout << "\n结论：预留空间可以显著减少动态扩容次数，提高性能！" << endl;
}

// 额外演示：vector的动态扩展原理
void testDynamicExpansion() {
    cout << "\n=== 额外演示：vector动态扩展原理 ===" << endl;
    
    vector<int> v;
    cout << "观察vector动态扩展过程：" << endl;
    cout << "元素个数\t容量\t扩容情况" << endl;
    
    int lastCapacity = 0;
    for (int i = 0; i < 20; ++i) {
        v.push_back(i);
        if (v.capacity() != lastCapacity) {
            cout << v.size() << "\t\t" << v.capacity();
            if (lastCapacity != 0) {
                cout << "\t扩容了！(从" << lastCapacity << "到" << v.capacity() << ")";
            } else {
                cout << "\t初始容量";
            }
            cout << endl;
            lastCapacity = v.capacity();
        }
    }
    
    cout << "\n说明：vector动态扩展时会找到更大的内存空间，" << endl;
    cout << "将原数据拷贝到新空间，然后释放原空间。" << endl;
}

int main() {
    cout << "===========================================" << endl;
    cout << "        C++ Vector容器详解演示程序        " << endl;
    cout << "===========================================" << endl;
    cout << "博客来源：https://blog.csdn.net/qq_52324409/article/details/121000029" << endl;
    
    // 执行所有测试
    test01();           // 构造函数
    test02();           // 赋值操作
    test03();           // 容量与大小
    test04();           // 插入和删除
    test05();           // 数据存取
    test06_1();         // 互换容器基本使用
    test06_2();         // 互换容器实际用途
    test07();           // 预留空间
    testDynamicExpansion(); // 动态扩展原理演示
    
    cout << "\n===========================================" << endl;
    cout << "           所有测试完成！                  " << endl;
    cout << "===========================================" << endl;
    
    return 0;
}