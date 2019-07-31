from PIL import Image
from PIL import ImageOps
from PIL import ImageFilter
import sys

def trans_mask_sobel(im):
    negate = ImageOps.invert(im)

    imageWithEdges = negate.filter(ImageFilter.FIND_EDGES)

    imageAfterBlur = imageWithEdges.filter(ImageFilter.GaussianBlur)

    threshold = 0
    imageAfterThreshold = imageAfterBlur.point(lambda p: p > threshold and 255)
    imageAfterThreshold.save("threshold_PIL","PNG")

    # Changing background pixel color to magenta
    changeBackgroundPixelColor = imageAfterThreshold
    pixdata = changeBackgroundPixelColor.load()

    width, height = changeBackgroundPixelColor.size
    for y in range(height):
        for x in range(width):
            if pixdata[x, y] == (0, 0, 0):
                pixdata[x, y] = (255, 0, 255)

    # Set Transparency
    transparencyImage = changeBackgroundPixelColor.convert("RGBA")
    datas = transparencyImage.getdata()

    newData = []
    for item in datas:
        if item[0] == 255 and item[1] == 0 and item[2] == 255:
            newData.append((255, 0, 255, 1))
        else:
            newData.append(item)

    transparencyImage.putdata(newData)
    return transparencyImage

def alpha_composite(transmask,im):
    alpha_composite_image = transmask


    datas_layer1 = im.getdata()
    datas_layer2 = alpha_composite_image.getdata()

    newData = []
    for item_layer2, item_layer1 in zip(datas_layer2, datas_layer1):
        if item_layer2[0] == 255 and item_layer2[1] == 255 and item_layer2[2] == 255 and item_layer2[3] == 255:
            newData.append(item_layer1)
        else:
            newData.append(item_layer2)

    alpha_composite_image.putdata(newData)
    return alpha_composite_image

def remove_background(filenameIn, filenameOut):
    img = Image.open(filenameIn)
    transmask = trans_mask_sobel(img)
    img = alpha_composite(transmask, img)
    img.save(filenameOut)

filenameIn = sys.argv[1]
filenameOut = sys.argv[2]
remove_background(filenameIn, filenameOut)