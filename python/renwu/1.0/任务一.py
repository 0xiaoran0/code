def process_numbers (li):
    b = sum(li) / len(li)
    c = max(li)
    d = min(li)
    e = 0
    for j in li:
        if j % 2 == 0:
            e += j
    tua = (float("%.4f"%b), c, d, e)
    return tua

print("请输入:", end = "")
a = input("")
li = [int(i.strip()) for i in a.split(",")]
print(process_numbers(li))



li = [2, 1, 5, 4, 6, 3]                  #顺序输出
for i in range (6):
    j = i + 1
    while j < 6 :
        if li[i] > li [j]:
            a = li[i]
            li[i] = li[j]
            li[j] = a
        j += 1
for i in range(6) :
    print(li[i])