import cv2 as cv
import numpy as np

cv.namedWindow("image", cv.WINDOW_NORMAL)
test = cv.imread('car.png')

hsv = cv.cvtColor(test, cv.COLOR_BGR2HSV)

lower_blue = np.array([100, 43, 46])
upper_blue = np.array([124, 255, 255])

mask = cv.inRange(hsv, lower_blue, upper_blue)

res = cv.bitwise_and(test, test, mask=mask)

cv.imshow('image', test)
cv.imshow('image', mask)
cv.imshow('image', res)

key = cv.waitKey(0)
if key == ord('x'):
    exit()
    cv.destroyAllWindows()