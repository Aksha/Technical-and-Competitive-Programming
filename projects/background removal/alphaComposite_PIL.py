from PIL import Image

layer1 = Image.open("blueshoe.png")
layer2 = Image.open("transparent_piltest.png")


datas_layer1 = layer1.getdata()
datas_layer2 = layer2.getdata()

newData = []
for item_layer2, item_layer1 in zip(datas_layer2, datas_layer1):
    if item_layer2[0] == 255 and item_layer2[1] == 255 and item_layer2[2] == 255 and item_layer2[3] == 255:
        newData.append(item_layer1)
    else:
        newData.append(item_layer2)

layer2.putdata(newData)
layer2.save("final_test_PIL", "PNG")
layer2.show()
