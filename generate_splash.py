o = """#pragma once
const unsigned char SPLASH[100][100] = {
"""
with open('decor/splash.data', 'rb') as i:
    for x in range(100):
        o += '{'
        for y in range(100):
            c = i.read(1) # color
            i.read(1) # alpha
            o += f'0x{c.hex()},'
        o += '},\n'
with open('src/image.hpp', 'w') as h:
    o += "};"
    h.write(o)
