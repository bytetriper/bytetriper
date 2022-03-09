#coding=gb2312
import webbrowser
import selenium
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
import tesserocr
from PIL import Image
import getpass
import time
import requests
import re
import sys
class LoginError:
    pass
def login(us,ps):#receives a username and password,returns a webdriver.chrome() variable
    options=webdriver.ChromeOptions()
    #options.binary_location=r"C:\Users\Zheng'bo'yang\Downloads\user\chromedriver.exe"
    #options.add_argument("--user-data-dir="+r"C:\C:\Users\Zheng'bo'yang\AppData\Local\Google\Chrome\User Data\Default")
    #options.add_argument('--profile-directory=Default')
    options.add_argument('--headless')
    username=us
    psword=ps
    bs=webdriver.Chrome(options=options)
    bs.get("https://i.sjtu.edu.cn/xtgl/login_slogin.html")    
    us=bs.find_element(By.ID,"jAccount")
    us.click()
    print(bs.current_url)
    j=1
    while re.match(r"^i",bs.current_url)==None:
        j+=1
        if j>40:
            print("Badluck")
            raise SystemExit
        try:
            us=bs.find_element(By.ID,"user")
            us.send_keys(username)
            us=bs.find_element(By.ID,"pass")
            us.send_keys(psword)
            #time.sleep(3)
            us=bs.find_element(By.ID,"captcha-img")
            #wait=WebDriverWait(bs,3)
            url=us.get_attribute("src")
            req=requests.get(url=url)
            with open("D:/VS_C/spiders/for_ocr/capcha.png","wb+") as f:
                f.write(req.content)
            #time.sleep(5)
            image=Image.open("D:/VS_C/spiders/for_ocr/capcha.png")
            #image=image.convert('L')
            result=tesserocr.image_to_text(image)
            us=bs.find_element(By.ID,"captcha")
            us.send_keys(result)
            print(result)
        except: 
            break
    bs.implicitly_wait(3)
    us=bs.find_element(By.XPATH,"//a[text()='信息查询']")
    try:
        us.click()
    except:
        pass
    us=bs.find_element(By.XPATH,"//a[text()='GPA/学积分查询']")
    try:
        us.click()
    except:
        pass
    bs.switch_to.window(bs.window_handles[1])
    '''
    us=bs.find_element(By.ID,"btn_tj")
    us.click()
    us=bs.find_element(By.XPATH,"//td[@aria-describedby='tabGrid_gpa']")
    print(us.text)'''
    return bs