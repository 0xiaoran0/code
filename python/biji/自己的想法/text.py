# k = 0
# while k <= 20:
#     print(1)
#     k += 1

# import random                                      #猜数字
# a = random.randint(1, 100)
# while True:
#     b = int(input())
#     if b > a:
#         print("菜，大了")
#         continue
#     elif b < a:
#         print("菜，小了")
#     else:
#         print(a,"对了")
#         break

# li1 = [1,2,3]
# a = 1
# li2 = f"li{a}"
# print(li2)                                    #输出字符串li1

# import random
# li1 = [1,2,3]
# li2 = [2]
# li3 = []
# li3.append(li1)
# li3.append(li2)
# b = 0
# a = random.choice(li3[b])
# print(a)                                       #输li3中第一个元素，也是一个列表

# import random
# import string
# li1 = []
# for i in range(3):
#     a = random.choice(string.digits)
#     li1.append(a)
# print(li1)
# li1.sort(reverse=False)
# print(li1)

# a = "1, 2, 3, 4"
# li = [int(b) for b in a.split(",")]
# print(li)
# li1 = [1,2,3,4]
# print(li1)

# tua = ()                                      #检验没有元素的元组的类型
# print(type(tua))

# li = [i for i in "11 ,22 ,3,4".split(",")]
# for j in range(4):
#     print(li[j])

# a = "1, 2, 3"
# b = "11, 22, 33"
# li = [i for i in a]
# li1 = [i for i in b]
# for i in range (len(li)):
#     print(li[i])

# for i in range (len(li1)):
#     print(li1[i])

# a = "11, 2, 3, 4"
# li = [int(i.strip()) for i in a.split(",")]
# for i in range (len(li)):
#     print(li[i])

# color = {
#     "黑": {
#         "H": {"min": 0, "max": 180},
#         "S": {"min": 0, "max": 255},
#         "V": {"min": 0, "max": 46}
#     },
#     "灰": {
#         "H": {"min": 0, "max": 180},
#         "S": {"min": 0, "max": 43},
#         "V": {"min": 46, "max": 220}
#     }
# }
# for k ,l in color.items():
#     print(l)

# li = [1, 2]                                #not in 的使用
# if 3 not in li:
#     li.append(3)
#     print(li)

import random                             #验证区间
while True:
    b = int(input(""))
    a = random.randint(1, 2)
    print(a)