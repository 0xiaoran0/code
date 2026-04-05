# print("Hello World")

# name="潇然"
# age=17
# print("我的名字是:%s,我的年龄是:%d"%(name,age))

# a=123
# print("%06d" %a)

# a=1.23
# print("%f" %a)

# a=1.23456
# print("%.3f" %a)

# print("woshi%%de1%%" % ())                                   //%%的作用：输出一个 % 

# a=1
# print(f"欸嘿{a}")

# a=2
# b=6
# print(a**b)

# a=8
# a += a
# a += a
# print(a)                           赋值运算符针对变量，纯数字不可用

# Ctrl+D连续复制

# print("123\t456")                     必须有引号

# print(end="\t")                        以四个空格结尾
# print("潇然")

# print("123\r456")                      \r 将后面的内容移到开头

# print("123\\456")                      \\ 打出一个斜杠

# print(r"123\t456") 加r不转义

# score = input("请输入成绩：")      #input默认输出字符串，所以下面的数字要用引号
# if score>="150":
#     print("厉害")
# else:
#     print("菜就多练")

# print(not 3>9) #and or not

# a=5
# b=6
# print("a小于等于b") if a <= b else print("a大于b")     #真结果 if 条件 else 假结果

# score = input("请输入分数：")
# if "120"<=score<="150":
#     print("特优")
# elif "96"<=score<"120":
#     print("优秀")
# else:
#     print("菜")

# tem = input("体温：")
# if tem >="38":
#     print("嘎了")
#     if tem <="41":
#         print("还能救")
#     else:
#         print("没救了")
# else:
#     print("没事")

# i=1
# while i<=3:
#     print("欸嘿")
#     i += 1

# while True:                       #死循环，除False和0外单独的值替换True都是死循环
#     print(True)

# i=1
# s=0
# while i<=10:
#     s += i                           #位置很关键
#     i += 1
#     #print(s)
# print(s)

# i=1
# s=0
# while i<=10:
#     i += 1
#     s += i
#     #print(s)技巧
# # print("计算结果",s)                   #print                     逗号连接会有空格，加号连接字符串

# i = 1
# while i <= 3:
#     print(f"这是第{i}次")
#     j = 1
#     while j <= 3:
#         print(j)
#         j += 1
#     i += 1

# i = 1
# while i <= 9:
#     j = 1
#     while j <= i:
#         print(f"{i}*{j} = {i*j}",end="\t")
#         j += 1
#     print()
#     i += 1

# a = "Hello World"
# for i in a:
#     print(i)

# for i in range(1,6):                     #左闭右开
#     print(i)
# for i in range(5):                       从零开始
#     print(i)

# s=0
# for i in range(1,101):
#     # s = 0                              s在这里无用
#     s += i
# print(s)

# i = 1
# while i <=5:
#     print(i)
#     if i == 3:
#         break
#     i += 1

# i = 1
# while i <= 5:
#     print(i)
#     if i == 3:
#         print('欸嘿')
#         i += 1
#         continue                     #跳过,所以上下两个print输出不同
#     print(i)
#     i += 1

# a = "欸嘿"
# a1 = a.encode("utf-8")                              #编码
# print(a1)
# a2 = a1.decode("utf-8")                             #解码
# print(a2)

# a = "欸"
# b = "嘿"
# print(a+b)
# print(a , b , sep="\n")
# print("欸嘿\n"*3)                                  #后面加 sep= 无效，只能在引号内操作

# a = "eihei"
# print("h" in a)                                    #包含为Ture，不包含为False
# print("eih" not in a)                                #与上述相反

# a = "eihei"
# print(a[2])                                         #从左到右第一个字母下标从0开始
# print(a[1:4])                                       #左开右闭
# print(a[-2])                                        #从右到左第一个字母下标从-1开始
# print(a[::-1])                                      #[开始：结束：步长]步长绝对值指截取间隔，正负代表截取方向，正为从右到左，默认为1

# a = "eihei"
# print(a.find("i"))                                   #fing(子字符串，开始下标，结束下标) 打印第一个子字符串位置，找不到打印0
# print(a.find("ei",1))                   #查找多个字符打印第一个字符的位置，范围前闭后开
# print(a.index("i",2))                   #找不到则报错，其他同find
# print(a.count("i"))                                 #打印出现次数，没有打印0，前闭后开，格式同理

# a = "asdfghjkl"
# print(a.startswith("s",1,3))      #在某个范围内判断是否以某个字符串开头，是则输出Ture，
# print(a.endswith("s",1,3))         #判断结尾，规则同上
# print(a[1:4].isupper())                                #自动打的
# print(a.isupper())                                     #判断是否全部是大写，是则输出True
# print("EIHEI".isupper())

# a = "asdfghjkl"
# print(a.replace("f","g"))                  #旧内容，新内容，次数     默认全部替换
# print(a.split("f"))                                    #字符，次数          指定符号进行分割，该符号会消失
# print(a.capitalize())                                  #改为第一个字母大写，其他都小写
# print(a.upper())                                       #小写字母全改成大写

# li = ["a",1,2,3,4,5]
# print(li[1])
# for i in li:
#     print(i)

# li = ["one","two","three","four","five"]
# li.append("six")                                         #整体插入，只能添加一个
# print(li)
# li.extend("six")                                         #拆开元素再插入，只能添加可迭代对象，可添加多个
# print(li)
# li.extend(["six"])                                       #将列表拆开插入，所以一次可插入多个元素
# print(li)
# li.extend(li)                                            #补全的，不详
# print(li)
# li.insert(0,"six")                       #指定位置插入
# print(li)

# li = [1,2,3,]
# li[1] = 4                                  #直接写下标即可修改
# print(li)

# li = [1,2,3,]
# print(2 in li)                                          #存在为True   用途；判断昵称是否重复
# print(2 not in li)                                      #与上相反

# name_list = ["1","2","3","4","5","6","7","8","9"]            #输入的是字符串，这里若是数字便不可能一致
# while True:
#     name = input("请输入昵称:")                                #Tap整体缩进
#     if name in name_list:
#         print("NO")
#     else:
#         print("YES")
#         name_list.append(name)
#         print(name_list)
#         break

# li = ["1","2","3"]                                         #查找同上，可用index和count
# print(li.index("1",0))
# print(li.count("1"))
# print("列表长度：",len(li))                                  #显示字符串、列表等长度

# li = ["1","2","3"]
# del li[0]                                                             #删除对应下标
# print(li)
# del li                                                                #删除全部，则无法输出
# print(li)

# li = ["1","2","3"]
# li.pop()                                                              #指定下标删除，默认删除最后一个，下标超出范围报错
# print(li)
# li.pop(0)
# print(li)
# li.remove("2")                                                        #指定删除元素，若列表中有两个相同元素，默认删除第一个

# li = ["agf",'str','dbf','f','ade']
# li.sort()                                                                #从大到小排序
# print(li)
# li.sort(reverse=True)                                                    #补全的    倒叙
# print(li)
# li.sort(reverse=False)                                                   #？    还原倒叙，之前没有倒叙就不变
# print(li)
# li.reverse()                                                             #倒叙
# print(li)

# li = [1,2,3,4,5]
# [print(i,end ="\t") for i in li]                                   #[表达式 for 变量 in 列表 / range()函数 / 可迭代对象]

# li = []
# for i in range(4):
#     li.append(i)                                                        #上下意思一样
# print(li)
# li = []
# [li.append(i) for i in range(4)]                                        #同上
# print(li)

# li = []
# for i in range(12):
#     if i % 2 == 0:
#         li.append(i)
# print(li)                                                               #再向后缩进print两次，不知为什么

# li = []
# [li.append(i) for i in range(12) if i % 2 == 0]                 #[表达式 for 变量 in 列表 / range()函数 / 可迭代对象 if 条件]
# print(li)                                                       #同上，简洁

# li = [i for i in range(12)]                                              #补全的
# print(li)

# li = [1,2,3,[4,5,6]]                                            #嵌套，就像集合中套集合
# print(li)
# li1 = [1,2,3,4]
# li = [1,2,li1]
# print(li)
# print(li[2][2])                                                #第一个括号选择内列表，第二个括号选择内列表中的元素

# tua = (1,'a',[2,3])                                            #元组用小括号,可包含多种数据类型
# print(tua)
# tub = (1)                                                #元组内只有一个元素时，其后要加“，”，负责数据类型不是元组，而是那个元素的
# print(type(tub))
# tub = (1,)
# print(type(tub))

# tua = (1,'a',[2])
# print(tua[1])
# print(tua.index(1))
# print('元组长度：',len(tua))
# print(tua[1:])