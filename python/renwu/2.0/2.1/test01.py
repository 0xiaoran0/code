# import cv2 as cv                      #没用
# import numpy as np
# from PIL import Image
#
#
#
# car = cv.imread("car.png")
#
# hsv = cv.cvtColor(car, cv.COLOR_BGR2HSV)
#
# lower = np.array([100, 150, 0])
# upper = np.array([140, 255, 255])
#
# mask = cv.inRange(hsv, lower, upper)
#
# mask_ = Image.fromarray(mask)
#
# bbox = mask_.getbbox()
#
# if bbox is not None:
#     x1, y1, x2, y2 = bbox
#
#     frame = cv.rectangle(car, (x1, y1), (x2, y2), (0, 255, 0), 2)
#
# cv.imshow('frame', frame)
#
# if cv.waitKey(0) & 0xFF == ord('x'):
#     exit()
#
# cv.destroyAllWindows()




# import cv2 as cv                              #在车牌旁改变画框
# import numpy as np
#
# # 读取图像
# car = cv.imread("car.png")
#
# # 预处理：高斯模糊去噪
# blurred = cv.GaussianBlur(car, (11, 11), 0)
#
# # 转HSV
# hsv = cv.cvtColor(blurred, cv.COLOR_BGR2HSV)
#
# # 设置蓝色HSV范围（你原先是100~124，保留）
# lower = np.array([100, 150, 0])
# upper = np.array([140, 255, 255])
#
# # 阈值分割
# mask = cv.inRange(hsv, lower, upper)
#
# # 形态学去噪（关键）
# kernel = cv.getStructuringElement(cv.MORPH_ELLIPSE, (5, 5))
# mask = cv.morphologyEx(mask, cv.MORPH_OPEN, kernel)  # 去小噪点
# mask = cv.morphologyEx(mask, cv.MORPH_CLOSE, kernel) # 填补小空洞
#
# # 找轮廓
# contours, _ = cv.findContours(mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
#
# # 遍历轮廓，找最大区域（或面积>阈值）
# max_area = 0
# best_cnt = None
# for cnt in contours:
#     area = cv.contourArea(cnt)
#     if area > 500 and area > max_area:  # 过滤小轮廓
#         max_area = area
#         best_cnt = cnt
#
# # 画框
# if best_cnt is not None:
#     x, y, w, h = cv.boundingRect(best_cnt)
#     cv.rectangle(car, (x, y), (x + w, y + h), (0, 255, 0), 2)
#
# # 显示
# cv.imshow('result', car)
# cv.waitKey(0)
# cv.destroyAllWindows()





# import cv2
# import numpy as np
#
# # 读取图片
# image = cv2.imread('car.png')
#
# # 转换到HSV颜色空间
# hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
#
# # 定义蓝色范围
# lower_blue = np.array([100, 150, 0])
# upper_blue = np.array([140, 255, 255])
#
# # 创建蓝色掩膜
# mask = cv2.inRange(hsv_image, lower_blue, upper_blue)
#
# # 使用轮廓检测定位车牌区域
# contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
#
# out = np.zeros_like(image)
#
# # 遍历轮廓并筛选出车牌区域
# for contour in contours:
#     x, y, w, h = cv2.boundingRect(contour)
#
#     aspect_ratio = float(w) / h
#     area = cv2.contourArea(contour)
#
#     # 筛选车牌的宽高比和面积
#     if 2 < aspect_ratio < 5 and area > 1000:
#         cv2.drawContours(out, [contour], 0, (0, 0, 255), 2)
#         break
#
# result = cv2.bitwise_and(image, image, mask=mask)
#
# out = cv2.bitwise_and(out, out, result)
# cv2.imshow('out', out)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

# mask1 = np.zeros_like(image)
# cv2.drawContours(mask1, [contour], 0, 255, -1)
# cv2.imshow('mask1', mask1)
# cv2.waitKey(0)
#
# res = cv2.bitwise_and(image, image, mask=mask)
# cv2.imshow('res', res)
# cv2.waitKey(0)
# cv2.destroyAllWindows()







import cv2
import numpy as np

# 读取图片
image = cv2.imread('car.png')
cv2.imshow('input_image', image)
cv2.waitKey(0)

# 转换到HSV颜色空间
hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# 定义蓝色范围（根据车牌颜色调整）
lower_blue = np.array([100, 150, 0])
upper_blue = np.array([140, 255, 255])

# 创建蓝色掩膜
mask = cv2.inRange(hsv_image, lower_blue, upper_blue)

# 使用轮廓检测定位车牌区域
contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

# 创建一个全黑背景
output_image = np.zeros_like(image)

# 遍历轮廓并筛选出车牌区域
for contour in contours:
    x, y, w, h = cv2.boundingRect(contour)
    aspect_ratio = float(w) / h  # 宽高比
    area = cv2.contourArea(contour)

    # 筛选车牌的宽高比和面积（根据实际车牌调整）
    if 2 < aspect_ratio < 5 and area > 1000:
        # 在全黑背景上绘制车牌区域
        out = image[y:y + h, x:x + w]

        # 将结果居中显示在全黑背景上
        output_image[y:y + h, x:x + w] = out

        cv2.imshow('output_image', output_image)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
        break  # 只处理第一个符合条件的车牌区域