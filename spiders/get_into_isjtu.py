#encoding:gb2312
from concurrent.futures import BrokenExecutor
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC 
import time
options=webdriver.ChromeOptions()
options.binary_location=r'C:/Program Files/Google/Chrome/Application/chrome.exe'
browser=webdriver.Chrome(options=options)
browser.get("https://i.sjtu.edu.cn/xtgl/login_slogin.html")
button=browser.find_element(By.ID,"jAccount")
button.click()
time.sleep(10)
ck=browser.get_cookies()
browser.close()
browser=webdriver.Chrome()
browser.delete_all_cookies()
print(ck)
browser.add_cookie(ck)
browser.get("https://i.sjtu.edu.cn")
time.sleep(3)
browser.close()
