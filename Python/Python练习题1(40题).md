---
title: Python练习题1(40题)
---

1. 以下选项中，不是 Python 语言保留字的是（ C ）

   A、except

   B、while

   C、do

   D、pass



2. 下列选项中不符合Python语言变量命名规则的是（ D ）

   A、TempStr

   B、_AI

   C、I

   D、3_1



3. 关于Python语言的注释，以下选项中描述错误的是（ B ）

   A、Python语言有两种注释方式：单行注释和多行注释

   B、Python语言的单行注释以单引号 ' 开头

   C、Python语言的单行注释以#开头

   D、Python语言的多行注释以'''（三个单引号）开头和结尾



4. 下面代码的输出结果是（ A ）
   ~~~python
   Print(0.1+0.2==0.3)
   ~~~

   A、False

   B、true

   C、True

   D、false



5. 关于import引用，以下选项中描述错误的是（ A ）？

   A、可以使用from turtle import setup 引入turtle库

   B、import保留字可用于导入模块或者模块中的对象

   C、使用import turtle引入turtle库

   D、使用import turtle as t 引入turtle库，取别名为t



6. 给出如下代码
   
   ~~~python
   S=‘Python is beautiful’
   ~~~
   可以输出“python”的是（ B ）
   
   A、print(s[:–14])
   
   B、print(s[0:6].lower())
   
   C、print(s[–21: –14].lower)
   
   D、print(s[0:6])



7. 给出如下代码：
   ~~~python
   x = 3.14
   eval('x + 10')
   ~~~
   上述代码的输出结果是（ C ）

   A、系统报错

   B、3.1410

   C、13.14

   D、TypeError: must be str, not int



8. 利用print()格式化输出，能够控制浮点数的小数点后两位输出的是（ C ）

   A、{:.2}

   B、{.2f}

   C、{:.2f}

   D、{.2}



9. 下面代码的输出结果是( A )
   ~~~python
   x=0b1010
   print(x)
   ~~~

   A、10

   B、256

   C、1024

   D、16



10. 下面代码的输出结果是( B )
    ~~~python
    z = 12.34 + 34j
    print(z.imag)
    ~~~

    A、12.12

    B、34.0

    C、12

    D、34



11. 给出如下代码
    ~~~python
    s = "Alice"
    print(s[::–1])
    ~~~
    上述代码的输出结果是( B )

    A、ALICE

    B、ecilA

    C、Alic

    D、Alice



12. 下面代码的输出结果是( D )
    ~~~python
    a = 2
    b = 2
    c = 2.0
    print(a == b, a is b, a is c)
    ~~~

    A、False False True

    B、True False True

    C、True False False

    D、True True False



13. 下面代码的输出结果是( D )
    ~~~python
    x = 1
    x *= 3+5**2
    print(x)
    ~~~

    A、29

    B、13

    C、14

    D、28



14. 下面代码的输出结果是( B )
    ~~~python
    a = "alex"
    b = a.capitalize()
    print(a,end=",")
    print(b)
    ~~~

    A、ALEX,alex

    B、alex,Alex

    C、alex,Alex

    D、alex,ALEX



15. 下面代码的输出结果是( D )
    ~~~python
    str1 = "mysqlsqlserverPostgresQL"
    str2 = "sql"
    ncount = str1.count(str2,10)
    print(ncount)
    ~~~

    A、4

    B、2

    C、3

    D、0



16. 关于Python的复数类型，以下选项中描述错误的是( C )

    A、复数的虚数部分通过后缀“J”或“j”来表示

    B、复数类型表示数学中的复数

    C、对于复数z，可以用z.imagl获得实数部分

    D、对于复数z，可以用z.real获得实数部



17. 关于Python循环结构，以下选项中描述错误的是（ D ）

    A、Python通过for、while等保留字构建循环结构

    B、遍历循环中的遍历结构可以是字符串、文件、组合数据类型和range()函数等

    C、continue用来结束当前当次语句，但不跳出当前的循环体

    D、continue结束整个循环过程，不再判断循环的执行条件



18. 下面代码的输出结果是（ B ）
    ~~~python
    for s in "HelloWorld":
        if s=="W":
            break
        print(s,end="")
    ~~~

    A、Helloorld

    B、Hello

    C、HelloWorld

    D、World



19. 关于Python的无限循环，以下选项中描述错误的是（ B ）

    A、无限循环也称为条件循环

    B、无限循环需要提前确定循环次数

    C、无限循环一直保持循环操作，直到循环条件不满足才结束

    D、无限循环通过while保留字构建



20. 以下选项中描述正确的是（ C ）

    A、条件35<=45<75是合法的，且输出为False

    B、条件24<=28<25是不合法的

    C、条件24<=28<25是合法的，且输出为False

    D、条件24<=28<25是合法的，且输出为True



21. 下面代码的输出结果是( D )
    ~~~python
    sum=0
    for i in range(0,100):
        if i%2==0:
            sum-=i
        else:
            sum+=i
    print(sum)
    ~~~

    A、-49

    B、-50

    C、49

    D、50



22. 下面代码的输出结果是( C )
    ~~~python
    x2 = 1
    for day in range(4,0,-1):
        x1 = (x2 + 1) * 2
        x2 = x1
    print(x1)
    ~~~

    A、94

    B、190

    C、46

    D、23



23. 下面代码的输出结果是( D )
    ~~~python
    for a in ["torch","soap","bath"]:
        print(a)
    ~~~

    A、torch,soap,bath

    B、torch,soap,bath,

    C、torch soap bath

    D、torch
          soap
          bath



24. 下面代码的输出结果是( B )
    ~~~python
    sum = 1
    for i in range(1,101):
        sum += i
    print(sum)
    ~~~

    A、5049

    B、5051

    C、5052

    D、5050



25. 以下选项中，不属于函数的作用的是（ A ）

    A、提高代码执行速度

    B、增强代码可读性

    C、降低编程复杂度

    D、复用代码



26. 在Python中，关于函数的描述，以下选项中正确的是（ D ）

    A、一个函数中只允许有一条return语句

    B、Python中，def和return是函数必须使用的保留字

    C、Python函数定义中没有对参数指定类型，这说明参数在函数中可以当作任意类型使用

    D、函数eval()可以用于数值表达式求值，例如eval("2*3+1")



27. 给出如下代码：
    ~~~python
    def func(a,b):
         c=a**2+b
         b=a
         return c
    a=10
    b=100
    c=func(a,b)+a
    ~~~
    以下选项中描述错误的是（ C ）

    A、执行该函数后，变量b的值为100

    B、该函数名称为func

    C、执行该函数后，变量c的值为200

    D、执行该函数后，变量a的值为10



28. 下面代码的运行结果是（ C ）
    ~~~python
    def func(num):
      num += 1
    a =10
    func(a)
    print(a)
    ~~~

    A、int

    B、11

    C、10

    D、出错



29. 下面代码的输出结果是（ A ）
    ~~~python
    def exchange(a, b):
        a, b = b, a
        return (a, b)
    x = 10
    y = 20
    x, y = exchange(x, y)
    print(x, y)
    ~~~

    A、20 10

    B、10 10

    C、20 20

    D、20,10



30. 下面代码的输出结果是（ C ）
    ~~~python
    f=lambda x,y:y+x
    f(10,10)
    ~~~
    
    A、10
    
    B、10,10
    
    C、20
    
    D、100



31. 下面代码的输出结果是（ A ）
    ~~~python
    def f2(a):
      if a > 33:
        return True
    li = [11, 22, 33, 44, 55]
    res = filter(f2, li)
    print(list(res))
    ~~~

    A、[44,55]

    B、[22,33,44]

    C、[11,33,55]

    D、[33,44,55]



32. 下面代码的执行结果是‪‪‪‪‪‪‫‪‪‪‪‪‪‪‪‪‪‪‪‪‫‪‪‪‪‪‪‪‪‪‪‪‫‪‪‪‪‪‪‫‫（ D ）
    ~~~python
    def greeting(args1, *tupleArgs, **dictArgs):
        print(args1)
        print(tupleArgs)
        print(dictArgs)
    names = ['HTY', 'LFF', 'ZH']
    info = {'schoolName': 'NJRU', 'City': 'Nanjing'}
    greeting('Hello,', *names, **info)
    ~~~

    A、无输出

    B、出错

    C、['HTY', 'LFF', 'ZH']

    D、Hello,
          ('HTY', 'LFF', 'ZH')
          {'schoolName': 'NJRU', 'City': 'Nanjing'}



33. 对于序列s，能够返回序列s中第i到j以k为步长的元素子序列的表达是（ D ）

    A、s[i, j, k]

    B、s(i, j, k)

    C、s[i,j:k]

    D、s[i:j:k]



34. 组变量t=("cat", "dog", "tiger", "human")，t[::-1]的结果是（ A ）

    A、('human', 'tiger', 'dog', 'cat')

    B、{'human', 'tiger', 'dog', 'cat'}

    C、运行出错

    D、['human', 'tiger', 'dog', 'cat']



35. 给定字典d，以下选项中对d.items（ B ）的描述正确的是

    A、返回一个列表类型，每个元素是一个二元元组，包括字典d中所有键值对

    B、返回一种dict_items类型，包括字典d中所有键值对

    C、返回一个元组类型，每个元素是一个二元元组，包括字典d中所有键值对

    D、返回一个集合类型，每个元素是一个二元元组，包括字典d中所有键值对



36. 给定字典d，以下选项中对d.get(x, y)的描述正确的是（ D ）

    A、返回字典d中键值对为x:y的值

    B、返回字典d中键为y的值，如果不存在，则返回y

    C、返回字典d中值为y的值，如果不存在，则返回x

    D、返回字典d中键为x的值，如果不存在，则返回y



37. 给定字典d，以下选项中对x in d的描述正确的是（ C ）

    A、x是一个二元元组，判断x是否是字典d中的键值对

    B、判断x是否是字典d中的值

    C、判断x是否是字典d中的键

    D、判断x是否是在字典d中以键或值方式存在



38. 给出如下代码：
    ~~~python
    import random as ran
    listV = []
    ran.seed(100)
    for i in range(10):
        i = ran.randint(100,999)
        listV.append(i)
    ~~~
    以下选项中能输出随机列表元素最大值的是（ C ）
    
    A、print(listV.pop(i))
    
    B、print(listV.reverse(i))
    
    C、print(max(listV))
    
    D、print(listV.max())



39. 给出如下代码：‪‪‪‪‪‪‫‪‪‪‪‪‪‪‪‪‪‪‪‪‫‪‪‪‪‪‪‪‪‪‪‪‫‫‪‪‪‪‪‪
    ~~~python
    MonthandFlower={"1月":"梅花","2月":"杏花","3月":"桃花","4月":"牡丹花","5月":"石榴花","6月":"莲花","7月":"玉簪花","8月":"桂花","9月":"菊花","10月":"芙蓉花","11月":"山茶花","12月":"水仙花"}
    n = input("请输入1—12的月份:")
    print(n + "月份之代表花：" + MonthandFlower.get(str(n)+"月"))
    ~~~
    以下选项中描述正确的是（ D ）
    
    A、*MonthandFlower是一个列表
    
    B、*MonthandFlower是一个元组
    
    C、*MonthandFlower是一个集合
    
    D、代码实现了从键盘上获取一个整数（1—12）来表示月份，输出该月份对应的代表花名



40. 下面代码的输出结果是‪‪‪‪‪‪‫‪‪‪‪‪‪‪‪‪‪‪‪‪‫‪‪‪‪‪‪‪‪‪‪‪‫‫‪‪‪‪‪‪‪‪‪‪‪‪‫‪‪‪‪‪‪‪‪‪‪‪‪‪‫‪‪‪‪‪‪‪‪‪‪‪‫‫‪‪‪‪‪‪（ B ）
    ~~~python
    list1 = [(m,n) for m in 'AB' for n in 'CD']
    print(list1)
    ~~~

    A、['AC', 'AD', 'BC', 'BD']
    
    B、[('A', 'C'), ('A', 'D'), ('B', 'C'), ('B', 'D')]
    
    C、[‘A’,’B’,’C’,’D’]
    
    D、错误