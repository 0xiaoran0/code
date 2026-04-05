#判断100000内的数字是否为质数
# li = []
# while True:
#     a = int(input(""))
#     for i in range(2,a):
#         if a%int(i) == 0:
#             print("NO")
#             break
#         else:
#             print("OK")
#             li.append(a)
#             break
#     li.sort(reverse=False)
#     print(li)                                            #有问题

li = []
while True:
    b = True
    i = 2
    a = int(input(""))
    while i <= a-1:
        if a % i == 0:
            b = False
        i += 1
    if b:
        li.append(a)
    li.sort(reverse=False)
    print(li)
    continue                                        #好了，但b、i、a的赋值只能在循环内，否则会出问题