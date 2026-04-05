# print("Hello World")

# print("a \n b")

# print("a \n\
# b")                                     #加入 / 表示内容还未结束，可实现跨行输出长字符串，也可使用三引号



##---------------------------------------------------------------------------------------------------------#
# li = [1, 2, 3, 4, 5, 6]
# li_len = len(li)
# print(li_len)
# print(li[4:6])                         # 切片的使用
# print(li[1:7:2])
# print(li[-2:-1])
# print(li[::-1])                       # 倒序输出



# li = []
# # 增
# li.append(1)                               # 只能添加一个元素
# print(li)

# li.extend([2, 3, 4])                             # extend 后是可迭代对象
# print(li)

# li.insert(3, 4)                           # insert(位置，元素)
# print(li)

# li.insert(len(li), 8)                 # 加到末尾
# print(li)


# #改
# li[0] = 0
# print(li)

# li[2:4] = [34]
# print(li)

# li[len(li):] = [5, 6, 7]                   # 通过切片进行赋值
# print(li)


# # 查
# print(li.count(1))                        # 查找个数
# print(li.index(1))                        # 查找第一个的下标

# li[li.index(1)] = "1"
# print(li)

# print(li.index(1, 3, 5))                  # index 还有两个参数用于指定开始与结束，可以用于递归查找后续元素


# # 排
# li.sort()                            # 排序
# print(li)

# li.reverse()                         # 单纯的翻转
# print(li)

# li.sort(reverse=True)                # sort 的第二个参数，默认为 False，改为 Ture 则会在排序后翻转
# print(li)


# # 删
# li.remove(34)                        # 若存在多个，只会删除第一个，且要删除元素必须存在，否则会报错
# print(li)
# li.pop(1)                            # 传入下标
# print(li)
# li.clear()                           # 清空列表
# print(li)



##---------------------------------------------------------------------------------------------------------#
# li = [1, 2, 3, 4]
# li1 = li.copy()                        #? 两种复制手段,但都是浅拷贝,在这里体现不出来
# print(li1)

# li2 = li[:]
# print(li2)

# li[0] = 0
# print(li)
# print(li1)
# print(li2)

# li3 = li1 + li2                               # 列表支持加法
# print(li3)

# li = [[1] * 3] * 3                           #* 内层对象是浅拷贝
# li[0][0] = 2
# print(li)

# li1 = [[1], [2], [3]]
# li2 = li1.copy()                             # 浅拷贝
# li1[0][0] = 0
# print(li2)

# li1[0] = 0
# print(li2)



# import copy
# li = [[i] for i in range(4)]
# li1 = copy.copy(li)                            # 使用模块中的浅拷贝
# li2 = copy.deepcopy(li)                        # 深拷贝
# li[0][0] = 1
# print(li)
# print(li1)
# print(li2)



# li = [1, 2, 3]
# li = [i * 2 for i in li]            #通过列表推导式将列表中元素翻倍
# print(li)

# li = [i for i in range(10)]         #填充数字
# print(li)

# li = [i for i in range (10) if i % 2 == 0]         #todo 很神奇的写法,还有更复杂的
# print(li)


# a = "ASDFG"
# li = [i for i in a]                 #列表推导式作用于取出字符串中的字母
# print(li)

# li1 = [ord(i) for i in "hello"]     # ord() 获取字符编码
# print(li)


# li = [
#     [1, 2, 3],
#     [4, 5, 6],
#     [7, 8, 8]]
# print([li[i][i] for i in range(len(li))])
# a = [li[i][i] for i in range(len(li))]             #对角线输出
# print(a)


# li = [[0] * 3 for i in range(3)]                 # 使用列表推导式构建多维列表
# li[0][0] = 1
# print(li)

# li = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# li1 = [i for a in li for i in a]                    #列表多层嵌套 for 表达式，实现二维列表到一维列表
# print(li1)

# li = [i + j for i in range(3) for j in range(3)]     # 类似嵌套循环
# print(li)

# li = [i + j for i in range(3) if i % 2 == 0 for j in range(3) if j % 2 == 0]   # 每个 for 语句后面都可以跟一个 if 判断
# print(li)

# li = [i if i % 2 == 0 else -i for i in range(6)]         #todo 拓展，三元表达式，应该还有其他，先不深入了
# print(li)



##---------------------------------------------------------------------------------------------------------#
# tua1 = (1, "2", 1)                                       # 可以用小括号定义，也可以不用
# tua2 = 3, "4"                                         # 不可修改，下标、切片规则与列表相同

# print(tua1.count(1))                                  # 与列表相同，因为不允许修改，所以只剩下查
# print(tua1.index(1))

# tua = tua1, tua2                                      # 同样与列表相同
# for i in tua:
#     for j in i:
#         print(j)

# tua = (i for i in range(2))                           #todo 元组生成器，暂时没有解释
# print(tua)


# tua = (1, "a", 5, [3])                                      #* 打包与解包，同样适用于列表，左右一般来说须要一致
# x, y, z, w = tua                                          #将序列(元素， 列表， 字符串)内元素赋给多个变量
# print(f"{x}, {y}, {z}, {w}")

# x, *y, z = tua                                            # *一次只能出现一个，加上* 的元素会解包剩余所有元素
# print(f"{x}, {y}, {z}")

# x, y, z = 1, 2, 3                                        # 相当于先进行打包，等号后为临时元组，再进行解包
# print(f"{x}, {y}, {z}")

# w = ([1], [2])                                       # 元组内是列表，可修改列表的值，可通过地址理解
# w[0][0] = 0
# print(w)



##---------------------------------------------------------------------------------------------------------#
# s = "12321"
# print(1 if s == s[::-1] else 0)                    # 三元运算符解决回文数

#todo 字符串有大小写转换的函数，这里不展示了

# s = "1234567"
# print(s.center(15))                                  # 居中
# print(s.ljust(15))                                   # 左对齐
# print(s.rjust(15))                                   # 右对齐
# print(s.zfill(15))                                   # 左填充 0，以上四个函数都有第二个参数，可选定填充内容，默认为空格

# s = "12345672"
# print(s.count("2", 0, 5))                              # 计数，后两个参数可不填
# print(s.find("2"))                                     # 从左往右，可选定范围
# print(s.rfind("2"))                                    # 从右往左，可选定范围
# print(s.index("2"))                                    # 返回下标，否则报错，可选定范围

# s = "a\tb\t c  \t  s"
# s1 = s.expandtabs()                                    # 把所有 \t 换为空格
# print(s1)

# s = "1, 2, 3, 4, 3, 2, 1"
# print(s1.replace("2", "23", -1))                       # 把前者替换为后者，第三个参数为替换的个数，默认为 -1 ，指全部替换


# s = "1, 2, 3, 4, 3, 2, 1"
# table = s.maketrans("1234567", "ABCDEFG", "4")                # 本质是字典，一一对应，第三个参数是忽略一个字符串，会将该参数删除
# s1 = s.translate(table)
# print(table)
# print(s1)

# table2 = {ord("1"): ord("A")}                            # 如左式，本质是字符码的字典
# s2 = s.translate(table2)
# print(s2)


# s = "123456789"
# print(s.startswith("2", 1, 3))                  # 判断是否以第一个参数开头，是则返回 T，可选定范围
# print(s.endswith("5", 2, 5))                    # 判断是否以第一个参数结尾，是则返回 T，可选定范围
# print(s.startswith(("1", "2", "3"), 1, 3))      # 也可以传一个元组，有一个满足则返回 T

# s = "Abc De"
# print(s.istitle())                              # 判断单词首字母是否是大写，其余是否都是小写，是则返回 T
# print(s.isupper())                              # 全部大写则返回 T
# print(s.upper().isupper())                      # 链式调用，从左到右

# s = "Abc De"
# print(s.isalpha())                              # 判断是否全部是字母，记得会检测空格，空格不是字母
# print(s.isspace())                              # 判断是否全部为空白字符，空格、制表、换行

# s = "Abc De"
# print(s.isprintable())                          # 判断是否可打印
# print("\n".isprintable())                       # 转义字符不会被打印，是系统检测并添加的

# s = "123456789"
# print(s.isdecimal())        # T
# print(s.isdigit())          # T
# print(s.isnumeric())        # T

# s = "2²"                    # 中文输入法输入 平方 能打出来
# print(s.isdecimal())        # F
# print(s.isdigit())          # T
# print(s.isnumeric())        # T

# s = "Ⅰ"
# print(s.isdecimal())      # F
# print(s.isdigit())        # F
# print(s.isnumeric())      # T

# s = "一"
# print(s.isdecimal())      # F
# print(s.isdigit())        # F
# print(s.isnumeric())      # T

# print(s.isalnum())        # 前面三种方法有一种 T 了就是 T


# s1 = "a b"
# s2 = "a_b"
# print(s1.isidentifier())    # 判断是否符合命名规则
# print(s2.isidentifier())


# import keyword
# print(keyword.iskeyword("for"))             # 判断是否为关键字(保留标识符)，需导入模块


# s = "          123456789       "
# print(s.lstrip())                            # 去除左侧空白
# print(s.rstrip())                            # 去除右侧空白
# print(s.strip())                             # 去除空白

# s = "123123123"
# print(s.lstrip("123"))                       # 从左侧开始去除参数包含内的字符，直至左侧字符已在参数中
# print(s.lstrip("12"))

# s = "123123123"
# print(s.removeprefix("123"))                 # 去除前缀
# print(s.removesuffix("123"))                 # 去除后缀

# s = "123123123"
# print(s.partition("."))                        # 从左到右找到参数第一次出现的位置，将其分为左中右三部分，通过元组返回，找不到则后两项为空
# print(s.rpartition("."))                        # 从右到左

# s = "123.123.123"
# print(s.split(".", 1))                            # 切分为列表返回，第一的参数决定切分的参照，默认为空格，第二个决定切分的段数，默认为 -1
# print(s.rsplit(".", 1))                           # 从右到左

# s = "123\r123\r\n123\n123"
# print(s.splitlines(True))                         # 按行分割，解决各系统换行符不同的问题，参数填 T 则在分割后保留换行符

# print(".".join(("1", "2", "3")))                  # 字符串拼接，传入列表或元组，比 + 快得多
# print(".".join(["1", "2", "3"]))



# print("{1}{0}".format("fei", "shi"))                 # 使用下标匹配，否则按顺序填入，(参数被当作元组)
# print("{s1}, {s2}".format(s1 = "123", s2 = "456"))   # 使用关键字进行匹配，不用看关键字，可与上面混用
# print("{}, {{}}".format("{}"))                       # 输出花括号，作为参数传入字符串、嵌套

# #! 此处省略 format 的各种输出拓展，具体在字符串五到六
# name = "AC"
# print(f"{name}")                                     # 3.6 之后 format 简化为 f



##---------------------------------------------------------------------------------------------------------#
# 序列分为可变序列 : 列表，不可变序列 : 元组、字符串
# li1 = [1, 2, 3]
# li2 = [4, 5, 6]
# li = li1 + li2                                         # 序列支持的两种运算符 + *
# print(li)
# print(id(li))
# li *= 2
# print(li)
# print(id(li))                                          # 地址不变



# tua1 = (1, 2)
# tua2 = (3, 4)
# tua = tua1 + tua2
# print(tua)
# print(id(tua))
# tua *= 2
# print(tua)
# print(id(tua))                                         # 地址发生改变，实际上是建立了一个新元组进行替换



# print(1 is 2)                                            # is 、is not 实质是判断地址，涉及 python 的存储方式
# print(1 is not 2)                                        #* python 所有数值存放在固定的位置，数值的修改实质是指针指向其他的区域

# li1 = [1]
# li2 = [1]
# print(li1 is li2)                                        # F
# print(li1[0] is li2[0])                                  # T



# li = [1, 2]
# print(1 in li)                                           # 作用一目了然
# print(1 not in li)



# li = [0, 1, 2, 3, 4, 5, 6]
# del li[0]
# del li[0:1]
# li[0:1] = []                                             # 实质是先清空左边，在进行赋值
# del li[::2]                                              #* 可设置步长，这就不能用 li[::2] = [] 实现，会报错
# del li[:]                                                # 等同于 li.clear()，会保留空列表
# del li                                                   # 清空对象，彻底消失



# li_ = [1, 2, 3, 4, 5, 6, 7]
# tua_ = (1, 2, 3, 4, 5 , 6, 7)
# s_ = "ABCDEFG"

# li = list(s_)
# li = list(tua_)

# tua = tuple(s_)
# tua = tuple(li_)

# s = str(li_)                            #* 只是在 [] 或 () 外面加双引号，变为 "[]" 或 "()"
# s = str(tua_)



# li = [2, 1, 3, 4, 5, 6, 7]
# tua = (1, 2, 3, 4, 5 , 6, 7)
# s = "ABCDEFG"

# print(min(li))
# print(min(1, 2, 3, 4))

# li1 = []
# print(min(li1, default="li"))

# print(len(tua))
# print(len(range(2)))

# print(sum(li, start=1))                # 设置加法的初始值、可以不写

# li1 = sorted(li, reverse=True)                       # 接受可迭代对象，返回全新的列表，li.sort() 接受列表，修改原来的列表
# print(li1)                                           # reserve 决定是否翻转
# print(li)

# li_s = ["a", "ba", "abc"]
# li1 = sorted(li_s)
# li2 = sorted(li_s, key=len)                          # 传入 key 参数作为比较原则，默认从小到大
# print(li1)
# print(li2)

# li1 = list(reversed(li))                             # 接受可迭代对象，返回反向迭代器，可用 list、str 等转换
# print(li1)



li = [0, 2, 1, 3, 4, 5, 6, 7]
tua = (1, 2, 3, 4, 5 , 6, 7)
s = "ABCDEFG"

print(all(li))                                 # 判断是否全部为真
print(any(li))                                 # 判断是否存在真值

li1 = list(enumerate(li, 3))                   # 将元素与序号打包为二元组，返回枚举对象，可指定序号初始值
print(li1)
for i, num in li1:                             # 方便遍历时输出序号
    print(i, num)

li1 = [1, 2, 3]
li2 = [4, 5, 6, 7]
li_z = list(zip(li1, li2))                     # 打包为元组，长度与最短的对齐，输出为 [(1, 4), (2, 5), (3, 6)]
print(li_z)

import itertools
li_z = list(itertools.zip_longest(li1, li2))   # 导入包，使用函数，长度与最长的对齐，不足的补 None
print(li_z)
# 序列下 5：59