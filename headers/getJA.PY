#encoding=gb2312
import webbrowser
from autologin import LoginError
from matplotlib.style import use
import selenium
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
import time
import re
import autologin
import sys
def get_jaccount(ac):
    options=webdriver.ChromeOptions()
    #bs=webdriver.Chrome(options=options)
    with open("D:/VS_C/spiders/JA.txt","r") as f:
        username=f.read(10)
        f.read(1)
        password=f.read()
    try:
        bs=autologin.login(username,password)
    except(SystemExit):
        print("LoginError")
        exit()
    bs.get("https://my.sjtu.edu.cn")
    bs.implicitly_wait(10)
    us1=bs.find_element(By.XPATH,"//*[text()='财务']")
    us1.click()
    us2=bs.find_element(By.XPATH,"//*[text()='校内转账']")
    us2.click()
    bs.switch_to.window(bs.window_handles[2])
    wait=WebDriverWait(bs,10)
    wait.until(EC.presence_of_element_located((By.ID,"V0_CTRL4")))
    us3=bs.find_element(By.ID,"V0_CTRL4")
    us3.click()
    us4=bs.find_element(By.XPATH,"//*[text()='计算服务费']")
    us4.click()
    time.sleep(1)
    us3=bs.find_element(By.XPATH,"//*[@maxlength=100]")
    us3.send_keys(ac)
    time.sleep(3)
    us3.send_keys(Keys.ENTER)
    time.sleep(3)
    us3=bs.find_elements(By.XPATH,"//*[@class='infoplus_control infoplus_labelControl']")
    return us3[1].text
    return
print(get_jaccount('秦仁杰'))