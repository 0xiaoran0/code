import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def a1 (h, s, v, color) :
    for k, l in color.items():
        if l["H"]["min"] <= h <= l["H"]["max"] \
            and l["S"]["min"] <= s <= l["S"]["max"] \
            and l["V"]["min"] <= v <= l["V"]["max"] :
            return k
    return "未知"

color = {
    "黑": {
        "H": {"min": 0, "max": 180},
        "S": {"min": 0, "max": 255},
        "V": {"min": 0, "max": 46}
    },
    "灰": {
        "H": {"min": 0, "max": 180},
        "S": {"min": 0, "max": 43},
        "V": {"min": 46, "max": 220}
    },
    "白": {
        "H": {"min": 0, "max": 180},
        "S": {"min": 0, "max": 30},
        "V": {"min": 221, "max": 255}
    },
    "红1": {
        "H": {"min": 0, "max": 10},
        "S": {"min": 43, "max": 255},
        "V": {"min": 46, "max": 255}
    },
    "红2": {
        "H": {"min": 156, "max": 180},
        "S": {"min": 43, "max": 255},
        "V": {"min": 46, "max": 255}
    },
    "橙": {
        "H": {"min": 11, "max": 25},
        "S": {"min": 43, "max": 255},
        "V": {"min": 46, "max": 255}
    },
    "黄": {
        "H": {"min": 26, "max": 34},
        "S": {"min": 43, "max": 255},
        "V": {"min": 46, "max": 255}
    },
    "绿": {
        "H": {"min": 35, "max": 77},
        "S": {"min": 43, "max": 255},
        "V": {"min": 46, "max": 255}
    },
    "青": {
        "H": {"min": 78, "max": 99},
        "S": {"min": 43, "max": 255},
        "V": {"min": 46, "max": 255}
    },
    "蓝": {
        "H": {"min": 100, "max": 124},
        "S": {"min": 43, "max": 255},
        "V": {"min": 46, "max": 255}
    },
    "紫": {
        "H": {"min": 125, "max": 155},
        "S": {"min": 43, "max": 255},
        "V": {"min": 46, "max": 255}
    }
}

place = 'lena.jpg'
image = cv.imread(place)

a = int (input(""))
b = int (input(""))
c = int (input(""))
d = int (input(""))

im = image[a:b , c:d]
cv.imshow('image', im)
cv.waitKey(0)

hsv = cv.cvtColor(im, cv.COLOR_BGR2HSV)

li = []
for i in range (hsv.shape[0]):
    for j in range (hsv.shape[1]):
        h, s, v = hsv[i, j]
        re = a1(h, s, v, color)
        if re == "红1" or re == "红2" :
            re = "红"
        if re not in li:
            li.append(re)
print(li)