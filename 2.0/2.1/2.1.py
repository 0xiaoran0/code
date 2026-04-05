import cv2
import numpy as np

image = cv2.imread('car.png')

hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

lower_blue = np.array([100, 150, 0])
upper_blue = np.array([140, 255, 255])

mask = cv2.inRange(hsv, lower_blue, upper_blue)

contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

for contour in contours:
    x, y, w, h = cv2.boundingRect(contour)
    aspect_ratio = float(w) / h
    area = cv2.contourArea(contour)

    if 2 < aspect_ratio < 5 and area > 1000:
        out = image[y:y + h, x:x + w]

        output_image = np.zeros_like(image)
        output_image[y:y + h, x:x + w] = out

        cv2.imshow('output_image', output_image)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
        break