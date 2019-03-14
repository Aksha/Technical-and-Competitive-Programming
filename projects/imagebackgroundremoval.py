Input: 
    Fix color analysis of images (was: "white shoe" / "white dress" / "white bag" problem)
    any idea why these searches for white return non white product images?
    it might be that these products come in white, too.
    
My Inference: 
    Most products returned in the search results have a white background. 
    I believe there’s code that sets a threshold for the amount of white pixels in an image and and returns those images that 
    cross the threshold when you search for white products, i.e., shoes, dresses, handbags, etc. Since the background size is
    more than actual image size for shoes, the search results are worse.


https://making.lyst.com/2014/02/13/background-removal/
    
Code that does it: (Use ipython in terminal)
    
import pgmagick as pg

def trans_mask_sobel(img):
    """ Generate a transparency mask for a given image """

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
    image.floodFillColor('0x0+%s+0' % (w-1), 'magenta')
    image.floodFillColor('0x0+0+%s' % (h-1), 'magenta')
    image.floodFillColor('0x0+%s+%s' % (w-1, h-1), 'magenta')

    image.transparent('magenta')
    return image

def alpha_composite(image, mask):
    """ Composite two images together by overriding one opacity channel """

    compos = pg.Image(mask)
    compos.composite(
        image,
        image.size(),
        pg.CompositeOperator.CopyOpacityCompositeOp
    )
    return compos

def remove_background(filename):
    """ Remove the background of the image in 'filename' """

    img = pg.Image(filename)
    transmask = trans_mask_sobel(img)
    img = alphacomposite(transmask, img)
    img.trim()
    img.write('out.png')

    Question here: Does Java have pgmagick library or it's equivalent?
        
    To be continued...
    
