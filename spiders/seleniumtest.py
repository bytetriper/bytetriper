from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC 
import time
browser=webdriver.Chrome()
browser.get('https://search.bilibili.com/all?keyword=%E4%B8%AD%E6%96%87&from_source=webtop_search&spm_id_from=333.1007')
kw=input("Search in bilibili:")
it=browser.find_element(By.ID,"search-keyword")
j=0
while it.get_attribute("value"):
    it.send_keys(Keys.BACK_SPACE)
    j+=1
    if(j>10):
        print("NO!")
        break
it.send_keys(kw)
it.send_keys(Keys.ENTER)
'''
wait=WebDriverWait(browser,5)
wait.until(EC.presence_of_all_elements_located((By.XPATH,"//*")))

'''
time.sleep(3) #10s
print(browser.current_url)
with open("spiders/bsearch.html","w+",encoding="utf8") as f:
    f.write(browser.page_source)
browser.back()
print(browser.current_url)
time.sleep(3)
browser.close()