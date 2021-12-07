# C++入門

### 一、ポインターの使い方

１．定義

``` c++  
int *p;

p = &a;
```

2．使い方

```c++
*p =  1000;
```

### 二、Pointerのメモリ使用

4Bits　→　32Bits Sys、8Bits　→　64Bits Sys

### 三、空PointerとWild Pointer(野指針)

★ 空Pointer: Initiate a pointer, Can't be accessed.

(0-255のメモリはシステムで利用されるので、アクセスは許可されない)

```C++
int * p = NULL;
```

★ Wild Pointer

```c++
int * p = (int *)0X1100; // The memory here is not legal.
```

The memory is not registered yet, You just can't use it. You should avoid use wild pointers.

### 四、Const指針

```C++
const int * p = &a;
p = &b;   //〇
*p = 123; //×

int * const p = &a;
p = &b;   //×
*p = 123; //〇

const int * const p = &a;
p = &b;   //×
*p = 123; //×
```

Const Pionter:

The address p pointed is mutable, **But the value in that address is immutable.**

### 五、Struct

```C++
struct student stu = {"zhang", 15. 100};
struct student * p = &stu;
p->score = 80; // 指针通过 -> 操作符来访问成员
stu.name = "wang"; // 普通的结构体通过.来访问
```

### 六，内存四区

- 代码区（程序运行前即存在）

  存放二进制代码， 由操作系统进行管理

  ※： 存放CPU执行机器指令， 共享/只读

- 全局区（程序运行前即存在）

  全局变量， 静态变量（static）， 常量（字符串常量和全局常量）

  ※：程序结束后由系统释放，局部常量不在此

- 栈区

  由编译器自动分配释放， 存放参数， 局部变量等

  ※不要返回局部变量的地址，因为栈区在函数结束后被系统自动释放（清空）。

- 堆区

  有程序员分配和释放， 若程序员不不释放，程序结束时由操作系统回收

  在C++中主要由new在堆区开辟内存

~~~c++
int main(){
    int a;                // local variable -> stack
    int *p = new int(10); // local variable -> heap 
                          // p本身是局部变量-> stack, 
    					  // 但存储的数据在heap上
}
~~~

※堆区开辟的数据，由程序员管理开辟， 由程序员管理释放（delete）。

~~~C++
int * func(){
    // new返回的是该数据类型的指针
    int *p = new int(10);
    return p;
}

void test(){
    int *p = func();
    
    cout<< *p << endl; // OK
    delete p;
    cout<< *p << endl; // NG
}

// 数组
int * arr = new int[10];
delete[] arr; 
~~~



### 七，引用







### 八，类和对象





