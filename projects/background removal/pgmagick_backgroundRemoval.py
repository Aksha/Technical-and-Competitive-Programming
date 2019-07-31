import pgmagick as pg
import sys

def trans_mask_sobel(img):
    image = pg.Image(img)
     # Find object
    image.negate()
    image.edge()
    image.blur(1)
    image.threshold(24)
    image.adaptiveThreshold(5, 5, 5)
     # Fill background
    image.fillColor('magenta')
    w, h = image.size().width(), image.size().height()
    image.floodFillColor('0x0', 'magenta')
    image.floodFillColor('0x0+%s+0' % (w - 1), 'magenta')
    image.floodFillColor('0x0+0+%s' % (h - 1), 'magenta')
    image.floodFillColor('0x0+%s+%s' % (w - 1, h - 1), 'magenta')
    image.transparent('magenta')
    return image

def alpha_composite(image, mask):
    compos = pg.Image(mask)
    compos.composite(
        image,
        image.size(),
        pg.CompositeOperator.CopyOpacityCompositeOp
    )
    return compos

def remove_background(filenameIn, filenameOut):
    img = pg.Image(filenameIn)
    transmask = trans_mask_sobel(img)
    img = alpha_composite(transmask, img)
    img.trim()
    img.write(filenameOut)

filenameIn = sys.argv[1]
filenameOut = sys.argv[2]
remove_background(filenameIn, filenameOut)

