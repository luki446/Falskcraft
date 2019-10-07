import os
from PIL import Image

size = 64

images = [Image.open(f"raw/{i}") for i in os.listdir("raw/")]

print([i.size for i in images])

out = Image.new("RGBA", (size * len(images), size))

images = [i.resize((size, size), Image.LANCZOS) for i in images]

print([i.size for i in images])

for e, i in enumerate(images):
    out.paste(i, (e * size, 0))

out.save("pack.png")