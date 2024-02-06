import json
from time import sleep
import cv2

st = [[[]]]

i = 0
video_path = 'C:\\Users\\56279\\Desktop\\video.mp4'
cap = cv2.VideoCapture(video_path)
print(cap)
if cap.isOpened():
    while True:
        ret, frame = cap.read()
        if ret == False:
            break
        height, width, channels = frame.shape
        sttt = [[]]
        for iii in range(0,width,2):
            for jjj in range(0,height,2):
                bbb, ggg, rrr = frame[jjj, iii]
                sttt.append([int(rrr),int(ggg),int(bbb),0])
        i += 1
        st.append(sttt)
        
else:
    print("The video play failed!")

with open('st.h', 'w') as file:
    json.dump(st,file)
print(i)
cap.release()
