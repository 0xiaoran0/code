import os
import cv2

file_path = "lena.jpg"  # 替换为实际路径

# 步骤1：检查文件是否存在
if not os.path.isfile(file_path):
    print(f"错误：文件 {file_path} 不存在，请检查路径！")
else:
    # 步骤2：尝试用OpenCV读取
    img = cv2.imread(file_path)
    if img is not None:
        # 读取成功，显示图片
        cv2.imshow("Image", img)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
    else:
        print("图片读取失败，可能文件损坏或OpenCV环境异常。")