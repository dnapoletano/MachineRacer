import gimp

img    = gimp.image_list()[-1]
layers = img.layers
bkg = (0,0,0,0)

mymatrix = [[0 for j in range(img.height/8)] for i in range(img.width/8)]
for j in range(img.height/8):
  for i in range(img.width/8):
    tarmac_map = list(layers[0].mask_bounds)
    tarmac_map[0] += layers[0].offsets[0]
    tarmac_map[2] += layers[0].offsets[0]
    tarmac_map[1] += layers[0].offsets[1]
    tarmac_map[3] += layers[0].offsets[1]

    # check if current pixel is tarmac:

    if((i*8 >= tarmac_map[0] and i*8 < tarmac_map[2])
      and (j*8 >= tarmac_map[1] and j*8 < tarmac_map[3])):
      if(layers[0].get_pixel(i*8 - layers[0].offsets[0] ,j*8-layers[0].offsets[1])!=bkg):
        mymatrix[j][i] = 3
        continue

    grass_map = list(layers[2].mask_bounds)
    grass_map[0] += layers[2].offsets[0]
    grass_map[2] += layers[2].offsets[0]
    grass_map[1] += layers[2].offsets[1]
    grass_map[3] += layers[2].offsets[1]

    # check if current pixel is grass:

    if((i*8 >= grass_map[0] and i*8 < grass_map[2])
      and (j*8 >= grass_map[1] and j*8 < grass_map[3])):
      if(layers[2].get_pixel(i*8 - layers[2].offsets[0] ,j*8-layers[2].offsets[1])!=bkg):
        mymatrix[j][i] = 1
        continue

    curbes_map = list(layers[1].mask_bounds)
    curbes_map[0] += layers[1].offsets[0]
    curbes_map[2] += layers[1].offsets[0]
    curbes_map[1] += layers[1].offsets[1]
    curbes_map[3] += layers[1].offsets[1]

    # check if current pixel is grass:

    if((i*8 >= curbes_map[0] and i*8 < curbes_map[2])
      and (j*8 >= curbes_map[1] and j*8 < curbes_map[3])):
      if(layers[1].get_pixel(i*8 - layers[1].offsets[0] ,j*8-layers[1].offsets[1])!=bkg):
        mymatrix[j][i] = 2
        continue

mystringmatrix = ''
for j in range(img.height/8):
  for i in range(img.width/8):
    mystringmatrix += str(mymatrix[j][i])
    if(i!= img.width/8 -1): mystringmatrix += ','
    else: mystringmatrix += '\n'

f = open("map.map","w")
f.write(mystringmatrix)
f.close()
