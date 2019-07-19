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
