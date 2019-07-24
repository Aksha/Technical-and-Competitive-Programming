from PIL import Image
from PIL import ImageOps
from PIL import ImageFilter
from PIL import ImageChops


im = Image.open("shoe.png")
im = im.convert("RGBA")

negate = ImageOps.invert(im)
negate.save('negatePIL.png')

imageWithEdges = negate.filter(ImageFilter.FIND_EDGES)
imageWithEdges.save('edgePIL.png')

imageAfterBlur = imageWithEdges.filter(ImageFilter.GaussianBlur)
imageAfterBlur.save('blurPIL.png')

threshold = 5
imageAfterThreshold = imageAfterBlur.point(lambda p: p > threshold and 255)
#imageAfterThreshold.show()
imageAfterThreshold.save('thresholdPIL.png')

print(imageAfterThreshold.mode)


'''
img = imageAfterThreshold.convert("RGBA")
pixdata = img.load()

width, height = img.size
for y in range(height):
    for x in range(width):
        if pixdata[x, y] == (255, 255, 255, 255):
            pixdata[x, y] = (255, 255, 255, 0)

img.save("transparentPIL.png")

final = Image.new('RGBA', img.size, (255, 255, 255, 255))  # white

im = im.convert("RGBA")

alphaComposite = Image.alpha_composite(im,img)
#alphaComposite.show()



def trim(im, border):
    bg = Image.new(im.mode, im.size, border)
    diff = ImageChops.difference(im, bg)
    bbox = diff.getbbox()
    if bbox:
     return im.crop(bbox)
    else:
     # found no content
     raise ValueError("cannot trim; image was empty")

final = trim(alphaComposite,255)
final.save("outPIL.png")
final.show()
'''


Improvised Working Code:
    
    
from PIL import Image
from PIL import ImageOps
from PIL import ImageFilter
from PIL import ImageChops

im = Image.open("blueshoe.png")

negate = ImageOps.invert(im)
# negate.save('negatePIL.png')

imageWithEdges = negate.filter(ImageFilter.FIND_EDGES)
# imageWithEdges.save('edgePIL.png')

imageAfterBlur = imageWithEdges.filter(ImageFilter.BLUR)
# imageAfterBlur.save('blurPIL.png')

threshold = 5
imageAfterThreshold = imageAfterBlur.point(lambda p: p > threshold and 255)
imageAfterThreshold.save('thresholdPIL.png')

# Changing background pixel color to magenta
changeBackgroundPixelColor = imageAfterThreshold  # .convert("RGBA")
pixdata = changeBackgroundPixelColor.load()

width, height = changeBackgroundPixelColor.size
for y in range(height):
    for x in range(width):
        if pixdata[x, y] == (0, 0, 0):
            pixdata[x, y] = (255, 0, 255)

changeBackgroundPixelColor.save("floodfillPIL.png")

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
transparencyImage.save("transparent_piltest.png", "PNG")

alpha_composite = transparencyImage


datas_layer1 = im.getdata()
datas_layer2 = alpha_composite.getdata()

newData = []
for item_layer2, item_layer1 in zip(datas_layer2, datas_layer1):
    if item_layer2[0] == 255 and item_layer2[1] == 255 and item_layer2[2] == 255 and item_layer2[3] == 255:
        newData.append(item_layer1)
    else:
        newData.append(item_layer2)

alpha_composite.putdata(newData)
alpha_composite.save("alphaComposite_PIL", "PNG")
alpha_composite.show()
