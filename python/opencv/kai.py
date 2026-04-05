import cv2
import numpy as np

image = cv2.imread('test.jpg')

cv2.imshow('image', image)

def open_close (self):
    self.kernel = np.ones((3, 3), np.uint8)

    opening = cv2.morphologyEx(image, cv2.MORPH_OPEN, self.kernel, iterations=3)

    closing = cv2.morphologyEx(image, cv2.MORPH_CLOSE, self.kernel, iterations=5)

    return opening, closing

opening, closing = open_close(image)

cv2.imshow("")