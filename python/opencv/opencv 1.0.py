# import cv2 as cv                                                   #成功打开一张照片
# import matplotlib.pyplot as plt
# image = cv.imread('D:/python   wenjianjia/opencv/lena.jpg')
# cv.imshow('image', image)
# cv.waitKey(0)

# plt.imshow(image[:,:,::-1])
# plt.show()



import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
image = cv.imread('lena.jpg')
cv.imshow('image', image)

a = int (input(""))
b = int (input(""))
c = int (input(""))
d = int (input(""))

im1 = image[a:b , c:d]

hsv_im1 = cv.cvtColor(im1, cv.COLOR_BGR2HSV)
cv.imshow('image', hsv_im1)
cv.waitKey(0)