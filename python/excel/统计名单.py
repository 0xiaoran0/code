import xlrd

book1 = xlrd.open_workbook("计算机类202501班.xlsx")
book2 = xlrd.open_workbook("国庆人员统计.xlsx")

b1 = book1.sheet_by_index(0)
b2 = book2.sheet_by_index(0)

li1 = [i+1 for i in range(27)]
li2 = [i+1 for i in range(27)]
li3 = []
li4 = []

for i in li1:
    ai = b1.cell_value(rowx = i, colx = 0)
    li3.append(ai)

for i in li2:
    bi = b2.cell_value(rowx = i, colx = 1)
    li4.append(bi)

for i in range(len(li3)):
    for j in range(len(li4)):
        if li3[i] == li4[j]:
            li3[i] = ""

for i in li3:
    print(i)

a = int(input(""))







# for i in li1:
#     for j in li2:
#         a = b1.cell_value(rowx = i, colx = 0)
#         b = b2.cell_value(rowx = i, colx = 1)
#         if a == b:
#             a = 0