---
title: Python练习题2(60题)
---

1. python语言属于（ C ）

   A、机器语言

   B、汇编销言

   C、高级语言

   D、科学计算语言



2. Python程序文件的扩展名是（ D ）

   A、.python

   B、.pyt

   C、.pt

   D、.py



3. 以下叙述中正确的是（ C ）

   A、Python 3.x与 Python 2.x兼容

   B、Python语句只能以程序方式执行

   C、Python是解释型语言

   D、Python语言出现得晚,具有其他高级语言的一切优点



4. 下列选项中合法的标识符是（ A ）

   A、_7a_b

   B、break

   C、_a$b

   D、7ab



5. Python不支持的数据类型有（ A ）

   A、char

   B、int

   C、float

   D、list



6. 字符串s="a\nb\tc",则len(s)的值是（ C ）

   A、7

   B、6

   C、5

   D、4



7. 下列属于math库中的数学函数的是（ C ）

   A、time()

   B、round()

   C、sqrt()

   D、random()



8. 下列表达式中,值不是1的是（ D ）

   A、4 // 3

   B、15 % 2

   C、2 \*\* 0

   D、-1



9. 语句eval("2+4/5")执行后的输出结果是（ A ）

   A、2.8

   B、2

   C、2+4/5

   D、“2+4/5”



10. 整型变量x中存放了一个两位数,要将这个两位数的个位数字和十位数字交换位置,例如13变成31,正确的python表达式是（ A ）

    A、(x % 10) * 10 + x // 10

    B、(x % 10) // 10 + x // 10

    C、(x / 10) % 10 + x // 10

    D、(x % 10) * 10 + x % 10



11. 流程图中表示判断框的是（ B ）

    A、矩形框

    B、菱形框

    C、平行四边形

    D、椭圆形框



12. 下面不属于程序的基本控制结构的是（ D ）

    A、顺序结构

    B、选择结构

    C、循环结构

    D、输入输出结构



13. 已知x=2,语句x*=x+1执行后, x的值是（ D ）

    A、2

    B、3

    C、5

    D、6



14. 在Python中,正确的赋值语句为（ C ）

    A、x + y = 10

    B、x = 2y

    C、x = y = 30

    D、3y = x + 1



15. 在算术运算符中使用%求余，如果除数是负数，那么取得的结果一定是（ C ）

    A、正数

    B、整数

    C、负数

    D、0



16. 在Python中，所有的对象都都可以进行真值测试。那么print(not 0)的输出结果为（ A ）

    A、True

    B、False

    C、None

    D、1



17. 在内存中储存的数据可以有多种类型，下面哪个不是Python语言中提供的基本数据类型（ A ）

    A、矩形

    B、字符型

    C、数值型

    D、布尔型



18. Python中以下哪项表示空值（ B ）

    A、Null

    B、None

    C、0

    D、False



19. 请判断1 > 2 or 1 >= 0的运算结果（ A ）

    A、Ture

    B、False

    C、Not

    D、False or False



20. 下列哪个语句在Python中是非法的（ B ）

    A、x=y=z=1

    B、x=(y=z+1)

    C、x,y=y,x

    D、x+=y



21. 小明每当遇到计算题的时候，都是一问三不知，快来帮他看看下面的正确选项（ D ）
    print(9%3*2+4)

    A、10

    B、3

    C、6

    D、4



22. 1<2<3 and 4>5 or 6<7运算结果为（ D ）

    A、False

    B、False True

    C、True False

    D、True



23. X、Y都小于Z用Python表达式如何表示（ C ）

    A、X<Y<Z

    B、X<Z or Y<Z

    C、X<Z and Y<Z

    D、X<Z & Y<Z



24. Python不支持的数据类型有（ A ）

    A、char

    B、int

    C、float

    D、list



25. 数学表达式2a/(bc),在Python中可以表示为（ A ）

    A、(2\*a)/(b\*c)

    B、2\*(a/b)\*c

    C、2/(b*a/c)

    D、2a/bc



26. 小托马斯因为没有球队签约，不打球了，自己在学编程，他想把-3，-5,10几个数字求和，看看他的代码有没有错误吧：（ B ）
    ~~~python
    a = -3
    b = -5
    c = 10
    d = 0
    d = a + b + c
    print(c)
    ~~~

    A、a = -3改成a == -3

    B、print(c)改成print(d)

    C、d=0改成d=1

    D、没有错误



27. 实现多路分支的最佳控制结构是（ C ）

    A、if

    B、if-else

    C、if-elif-else

    D、try



28. 与if (x==0)等价的语句是（ B ）

    A、if (x=0)

    B、if (not x)

    C、if(x)

    D、if (x!=1)



29. 下面语句统计“成绩(mark)优秀的男生以及不及格的男生”的人数，正确的语句为（ C ）

    A、if gender=='男' and mark<60 or mark>=90:
                  n+=1

    B、if gender=='男' and mark<60 and mark>=90:
                  n+=1

    C、if gender=='男' and (mark<60 or mark>=90): 
                  n+=1

    D、if gender=='男' or mark<60 or mark>=90:
                  n+=1



30. 以下if语句语法正确的是（ D ）

    A、if a>0: x=20
                  else:x=200

    B、if a>0:x=20
                  else:
                  x=200

    C、if a>0:
                  x=20
          else:x=200

    D、if a>0:
                  x=20
           else:
                  x=200



31. 下列语句执行后的输出结果是（ C ）
    ~~~python
    if 2:
        print(5)
    else:
        print(6)
    ~~~

    A、2

    B、6

    C、5

    D、程序报错



32. 下列Python程序的运行结果是（ B ）
    ~~~python
    x = 0
    y = True
    print(x > y and 'A' < 'B')
    ~~~

    A、True

    B、False

    C、true

    D、false



33. 关于Python的分支结构，以下选项中描述错误的是（ D ）

    A、分支结构使用if保留字

    B、Python中if-else语句用来形成二分支结构

    C、Python中if-elif-else语句描述多分支结构

    D、分支结构可以向已经执行过的语句部分跳转



34. 下列Python保留字中，不用于表示分支结构的是（ B ）

    A、elif

    B、in

    C、if

    D、else



35. 下面程序段求x和y中的较大数，不正确的是（ D ）

    A、maxNum=x if x>y else y

    B、if x>y:
                 maxNum=x
          else:
                 maxNum=y

    C、maxNum=y
                  if x>y:
                          maxNum=x

    D、if y>=x:
                  maxNum=y
           maxNum=x



36. 有如下程序:
    ~~~python
    x = 2.0
    if (x < 0.0):
        y = 0.0
    elif (x < 10.0):
        y = 1.0 / x
    else:
        y = 1.0
    print(y)
    ~~~
    程序的输出结果为（ C ）

    A、0.0

    B、0.25

    C、0.5

    D、1.0



37. 有如下程序：
    ~~~python
    a = 2
    b = -1
    c = 2
    if (a < b):
        if (b < 0):
            c = 0
        else:
            c += 1
    print(c)
    ~~~
    程序的输出结果为（ C ）

    A、0

    B、1

    C、2

    D、3



38. 下列程序运行后，x的值为（ A ）
    ~~~python
    a = 0
    b = 0
    c = 0
    x = 35
    if (not a):
        x -= 1
    elif (b):
        x = 3
    else:
        x = 4
    ~~~

    A、34

    B、4

    C、35

    D、3



39. 下列程序运行后，c的值为（ B ）
    ~~~python
    a = 1
    b = 2
    c = 3
    if (a > c):
        b = a
    a = c
    c = b
    ~~~

    A、1

    B、2

    C、3

    D、程序错误



40. 下列程序运行后，c和d的值分别为（ D ）
    ~~~python
    a = 1
    b = 2
    if (a == b):
        c = d = a
    else:
        c = b
    d = b
    ~~~

    A、c=1,d=1

    B、c=1,d=2

    C、c=2,d=1

    D、c=2,d=2



41. 求比10小且大于或等于0的偶数，例题如下（ B ）
    ~~~python
    x = 10
    while x:
        x = x - 1
        if x % 2 != 0:
            ____
        print(x)
    ~~~

    A、break

    B、continue

    C、yield

    D、flag



42. 以下程序的输出结果是（ D ）
    ~~~python
    dat = ['1', '2', '3', '0', '0', '0']
    for item in dat:
        if item == '0':
            dat.remove(item)
    print(dat)
    ~~~

    A、['1', '2', '3']

    B、['1', '2', '3', '0', '0']

    C、['1', '2', '3', '0', '0', '0']

    D、['1', '2', '3', '0']



43. 以下关于循环结构的描述，错误的是（ D ）

    A、遍历循环的循环次数由遍历结构中的元素个数来体现

    B、非确定次数的循环的次数是根据条件判断来决定的

    C、非确定次数的循环用 while 语句来实现，确定次数的循环用 for 语句来实现

    D、遍历循环对循环的次数是不确定的



44. ls = [1,2,3,4,5,6]，以下关于循环结构的描述，错误的是（ D ）

    A、表达式 for i in range(len(ls)) 的循环次数跟 for i in ls 的循环次数是一样的

    B、表达式 for i in range(len(ls)) 的循环次数跟 for i in range(0,len(ls)) 的循环次数是一样的

    C、表达式 for i in range(len(ls)) 的循环次数跟 for i in range(1,len(ls)+1) 的循环次数是一样的

    D、表达式 for i in range(len(ls)) 跟 for i in ls 的循环中，i 的值是一样的



45. 以下关于循环结构的描述，错误的是（ A ）

    A、遍历循环使用for <循环变量> in <循环结构>语句，其中循环结构不能是文件

    B、使用range()函数可以指定for循环的次数

    C、for i in range(5)表示循环5次，i的值是从0到4

    D、用字符串做循环结构的时候，循环的次数是字符串的长度



46. 给出如下代码
    ~~~python
    import random
    num = random.randint(1, 10)
    while True:
        if num >= 9:
            break
        else:
            num = random.randint(1, 10)
    ~~~
    以下选项中描述错误的是（ B ）

    A、这段代码的功能是程序自动猜数字

    B、import random代码是可以省略的

    C、while True: 创建了一个永远执行的循环

    D、random.randint(1,10) 生成[1,10]之间的整数



47. 以下代码段，不会输出A,B,C,的选项是（ D ）

    A、for i in range(3):
                  print(chr(65+i),end=",")

    B、for i in [0,1,2]:
                  print(chr(65+i),end=",")

    C、i = 0
          while i<3:
                  print(chr(i+65),end=",")
                  i+=1
                  continue

    D、i = 0
          while i<3:
                  print(chr(i+65),end=",")
                  break
                  i+=1



48. 以下程序的输出结果是（ D ）
    ~~~python
    for i in reversed(range(10, 0, -2)):
        print(i, end=" ")
    ~~~

    A、0 2 4 6 8 10

    B、12345678910

    C、9 8 7 6 5 4 3 2 1 0

    D、2 4 6 8 10



49. 以下程序的输出结果是（ D ）
    ~~~python
    x = 10
    while x:
        x -= 1
        if not x % 2:
            print(x, end="")
    else:
        print(x)
    ~~~

    A、86420

    B、975311

    C、97531

    D、864200



50. 以下程序的输出结果是（ D ）
    ~~~python
    s = ''
    ls = [1, 2, 3, 4]
    for l in ls:
        s += str(l)
    print(s)
    ~~~

    A、1,2,3,4

    B、4321

    C、4,3,2,1

    D、1234



51. 以下程序的输出结果是（ D ）
    ~~~python
    j = ''
    for i in "12345":
        j += i + ','
    print(j)
    ~~~

    A、1,2,3,4,5

    B、12345

    C、1,2,3,4,5,’

    D、1,2,3,4,5,



52. 以下程序的输出结果是（ D ）
    ~~~python
    ls1 = [1, 2, 3, 4, 5]
    ls2 = [3, 4, 5, 6, 7, 8]
    cha1 = []
    for i in ls2:
        if i not in ls1:
            cha1.append(i)
    print(cha1)
    ~~~

    A、(6, 7, 8)

    B、(1, 2, 6, 7, 8)

    C、[1,2,6,7,8]

    D、[6, 7, 8]



53. 下面代码的输出结果是（ A ）
    ~~~python
    for n in range(400, 500):
        i = n // 100
        j = n // 10 % 10
        k = n % 10
        if n == i ** 3 + j ** 3 + k ** 3:
            print(n)
    ~~~

    A、407

    B、408

    C、153

    D、159



54. 给出下面代码：
    ~~~python
    a = input("").split(",")
    x = 0
    while x < len(a):
        print(a[x], end="")
        x += 1
    ~~~
    代码执行时，从键盘获得“Python语言,是,脚本,语言”
    则代码的输出结果是（ C ）

    A、执行代码出错

    B、Python语言,是,脚本,语言

    C、Python语言是脚本语言

    D、无输出



55. 执行以下程序，输入qp，输出结果是（ A ）
    ~~~python
    k = 0
    while True:
        s = input('请输入q退出：')
        if s == 'q':
            k += 1
            continue
        else:
            k += 2
            break
    print(k)
    ~~~

    A、2

    B、请输入q退出：

    C、3

    D、1



56. 以下程序的输出结果是（ D ）
    ~~~python
    s = ''
    try:
        for i in range(1, 10, 2):
            s.append(i)
    except:
        print('error')
    print(s)
    ~~~~

    A、1 3 5 7 9

    B、[1, 3, 5, 7, 9]

    C、2, 4, 6, 8, 10

    D、error



57. 关于Python的lambda函数，以下选项中描述错误的是（ C ）

    A、lambda函数将函数名作为函数结果返回

    B、可以使用lambda函数定义列表的排序原则

    C、f = lambda x,y:x+y 执行后，f的类型为数字类型

    D、lambda用于定义简单的、能够在一行内表示的函数



58. pandas里下列选项可以进行缺失值替换的是（ B ）

    A、notnull()

    B、fillna()

    C、isnull()

    D、dropna()



59. 用numpy创建数组：c=np.arange(24).reshape(2,-1,2,2),c.shape返回的是（ A ）

    A、(2,  3, 2, 2)

    B、(2, 4, 2, 2)

    C、(2, 2, 2, 2)

    D、(2, 6, 2, 2)



60. Matplotlib中大部分图形样式的绘制方法都存在pypot模块中，下面那个函数是绘制散点图的（ B ）

    A、plt.plot

    B、plt.scatter

    C、plt.bar

    D、plt.pie