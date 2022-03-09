from tesserocr import PyTessBaseAPI
import tesserocr
from PIL import Image
'''
with PyTessBaseAPI() as api:
    api.SetImageFile('C:\\Users\\Zheng\'bo\'yang\\Desktop\\VS_C\\spiders\\for_ocr\\ck.png')
    print(api.GetUTF8Text())

image=image.convert('L')
th=188
table=[]
for i in range(256):
    if i<th:
        table.append(0)
    else:
        table.append(1)
image=image.point(table,'1')'''
image=Image.open("C:\\Users\\Zheng\'bo\'yang\\Desktop\\VS_C\\spiders\\for_ocr\\ck.png")
result=tesserocr.image_to_text(image)
#image.show()
print(result)