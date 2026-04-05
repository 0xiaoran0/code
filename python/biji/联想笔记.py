# a = input("")
#
# b = input("")
#
# print(int(a) * int(b))

# name = input("请输入姓名:")
#
# age = input("请输入年龄:")
#
# a = f'''
# {name}是大SB(帅比)
# {age}岁的大SB
# '''
#
# print(a)

# a = range(10)
#
# print(list(a))                       #不知道有什么用

# a = 8
# for i in range(3):
#     b = int(input("猜数字：(三次机会)"))         #输入为字符串，要改为整型，也可在下方b前加int
#     if b > a:
#         print("菜，大了")
#     elif b < a:
#         print("菜，小了")
#     else:
#         print("行")
#         break                                 #或把print改为exit

# for i in range(10):                                 #打印等腰三角形
#     if i <= 5:
#         print("*" * i)
#     else:
#         print("*" * (10-i))

# i = 1
# while i <= 10:
#     j = 1
#     while j <= i :
#         print(f"{i}*{j} = {i*j}",end="\t")
#         j += 1
#     print()
#     i += 1

# li = [1,2,3,4,5,6,7]
# import random
# print(random.choice(li))                                      #随机一个元素
# print(random.sample(li,3))                                    #随机多个元素

# import random
# li1 = [1,2,3,4,5,6,7,8,9]
# li2 = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","R","S","T","U","V","W","X","Y","Z"]
# li3 = []
# li3.extend(li1)
# li3.extend(li1)
# li3.extend(li1)
# li3.extend(li2)
# a = random.choice(li3)
# c = random.choice(li3)
# d = random.choice(li3)
# e = random.choice(li3)
# f = random.choice(li3)
# b = random.choice(li2)
# print(f"京{b}.{a}{c}{d}{e}{f}")

# import random
# li1 = ["1","2","3",'4','5','6','7','8','9']
# li2 = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","R","S","T","U","V","W","X","Y","Z"]
# li3 = []
# li3.extend(li1)
# li3.extend(li1)
# li3.extend(li1)
# li3.extend(li2)
# a = "".join(random.sample(li3,5))                      #join可用“”内的符号将括号内的内容连起来，只能连接字符串     省事
# b = random.choice(li2)
# for i in range(3):
#     k = 1
#     li = []
#     while k < 21:
#         a = "".join(random.sample(li3, 5))
#         b = random.choice(li2)
#         c = f"京{b}.{a}"
#         print(c)
#         li.append(c)
#         k += 1
#     j = int(input())
#     if j < 21:
#         print(li[j])
#         break
#     elif j == 21:
#         break
#     else:
#         continue

# import string
# a = random.sample(string.ascii_uppercase,1)                             #随机大写字母
# b = random.sample(string.ascii_lowercase,1)                             #随机小写字母
# c = random.sample(string.punctuation,2)                                 #随机特殊符号
# d = random.sample(string.digits,3)                                      #随机数字

# import random
# import string
# i = 0
# while i < 3:
#     li = []                                                           #这个列表不能放在for下面
#     for j in range(20):
#         a = random.choice(string.ascii_uppercase)
#         b = "".join(random.sample(string.ascii_uppercase + string.digits , 5))
#         c = f"{j}   京{a}-{b}"
#         print(c)
#         li.append(c)
#     k = int(input())
#     if k < 21:
#         exit(li[k])
#     else:
#         bresk
#     i += 1

# import random
# li1 = [1]
# li2 = [1]
# li3 = [1]
# li4 = []
# i = 0
# while i < 9:
#     li1.append(int(0))
#     li2.append(int(0))
#     li3.append(int(0))
#     i += 1
# while i < 49:
#     li2.append(int(0))
#     li3.append(int(0))
#     i += 1
# while i < 99:
#     li3.append(int(0))
#     i += 1
# li4.append(li1)
# li4.append(li2)
# li4.append(li3)
# j = 0
# while j < 3 :
#     k = input("")
#     a = int(random.choice(li4[j]))
#     if a == 1 :
#         print(f"得{3-j}等奖")
#     else:
#         print("没得奖")
#     j += 1

a = "asdfghjkl"
print(a.center(20, '='))              #把数字均分，用后面的符号填充前后
print(a.count(a))                              #计数
print(a.encode())                              #编码
print(a.decode())                              #解码
print(a.startswith(a))                         #判断是否以a开头
print(a.endswith(a))                           #判断是否以a结尾
print(a.isdigit())                             #判断是否为整数，可判断字符串内
a = a.replace("a","s")                   #不允许替换，只能重新赋值
print(a)

li = [1,2,3]
print("-".join(li))                             #拼接字符串
