import cv2 as cv
import numpy as np
from PIL import Image



#显示图片

# cv.namedWindow("image", cv.WINDOW_NORMAL)
#
# test = cv.imread('car.png')
#
# hsv = cv.cvtColor(test, cv.COLOR_BGR2HSV)
#
# lower_blue = np.array([100, 43, 46])
# upper_blue = np.array([124, 255, 255])
#
# mask = cv.inRange(hsv, lower_blue, upper_blue)
#
# res = cv.bitwise_and(test, test, mask=mask)
#
# cv.imshow('image', test)
# cv.imshow('image', mask)
# cv.imshow('image', res)
#
# key = cv.waitKey(0)
# if key == ord('x'):
#     exit()
#     cv.destroyAllWindows()



#识别镜头中的红色(残缺)

cap = cv.VideoCapture(0)

while True:
    ret, frame = cap.read()

    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)

    # lower_blue = np.array([100, 43, 46])
    # upper_blue = np.array([124, 255, 255])

    lower = np.array([0, 43, 46])
    upper = np.array([10, 255, 255])

    mask = cv.inRange(hsv, lower, upper)

    #cv.imshow('frame', mask)

    mask_ = Image.fromarray(mask)

    bbox = mask_.getbbox()

    if bbox is not None:
        x1, y1, x2, y2 = bbox

        frame = cv.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)

    cv.imshow('frame', frame)

    if cv.waitKey(1) & 0xFF == ord('x'):
        exit()

cap.release()
cv.destroyAllWindows()




#调色

# def callback (a) :
#     pass
#
# cv.namedWindow('image', cv.WINDOW_NORMAL)
#
# cv.createTrackbar("R", "image", 0, 255, callback)
# cv.createTrackbar("G", "image", 0, 255, callback)
# cv.createTrackbar("B", "image", 0, 255, callback)
#
# #创建背景图片
# image = np.zeros((512, 512, 3), np.uint8)
#
# while True:
#     cv.imshow('image', image)
#
#     r = cv.getTrackbarPos("R", "image")
#     g = cv.getTrackbarPos("G", "image")
#     b = cv.getTrackbarPos("B", "image")
#
#     image[:] = [b, g, r]
#
#     k = cv.waitKey(100)
#     if k == ord('x'):
#         exit()
#
# ccv.destroyAllWindows()



#转换色彩空间

# def callback(a):
#     pass
#
# cv.namedWindow("image", cv.WINDOW_NORMAL)
#
# image = cv.imread('car.png')
#
# color = [cv.COLOR_BGR2RGBA]
# cv.createTrackbar("color", "image", 0, len(color), callback)
#
# while True:
#     v = cv.getTrackbarPos("color", "image")
#
#     cvt_image = cv.cvtColor(image, color[v])
#
#     cv.imshow('image', image)
#
#     key = cv.waitKey(10)
#     if key == ord('q'):
#         exit()
#
# cv.destroyAllWindows()



# li = [[1, 2],[3, 4]]
# a = np.array(li)           # array 定义矩阵
# print(a)
#
# b = np.zeros((8, 8), np.uint8)      # zeros 定义矩阵，ones 相同
# print(b)
#
# c = np.full((8, 8), 255, np.uint8)            # full 定义矩阵
# print(c)
#
# d = np.identity(8)            # identity 定义单位矩阵
# print(d)
#
# e = np.eye(4, 5)                 # eye 定义长方形"单位"矩阵
# print(e)



# image = np.zeros((512,512,3), np.uint8)
#
# count = 0
# while count < 200:
#     count += 1
#     image[count, 200] = 255
#     # image[count, 200, 0] = 255
#     # image[count, 200] = [255, 255, 255]
#
#     im = []
#     im = image[0:400, 0:400]                      # 浅拷贝
#     im[ : , : ] = [0, 0, 255]
#
# cv.imshow('image', image)
# cv.imshow("im", im)
#
# cv.waitKey(0)
# cv.destroyAllWindows()