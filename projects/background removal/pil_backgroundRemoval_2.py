from PIL import Image
from PIL import ImageOps
import sys

im = Image.open("whiteshoe.png")

def image_transformation(img):
    transparencyImage = img.convert("RGBA")
    datas = transparencyImage.getdata()
    newData = []
    for item in datas:
        if item[0] == 255 and item[1] == 255 and item[2] == 255:
            newData.append((255, 255, 255, 1))
        else:
            newData.append(item)
    transparencyImage.putdata(newData)
    return transparencyImage

def remove_background(filenameIn, filenameOut):
    img = Image.open(filenameIn)
    img = image_transformation(img)
    img.save(filenameOut)
    img.show(filenameOut)

filenameIn = sys.argv[1]
filenameOut = sys.argv[2]
remove_background(filenameIn, filenameOut)