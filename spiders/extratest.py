import requests
from lxml import etree
res=requests.get("https://i0.hdslb.com/bfs/feed-admin/d8c09a27abc4ac4f2d465f3ddcd845989cd67afb.png")
with open("spiders/tmp.txt","wb") as f:
    print(res.content)