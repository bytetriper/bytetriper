#encoding=gb2312
import re
class students:
    name=[]
    jac=[]
    major=[]
    def __init__(self):
        with open("D:/VS_C/latex/box_opener/form.txt","r",encoding='utf8') as f:
            tmp=f.readlines()
        j=0
        for i in tmp:
            s=i.split('\t')
            students.name.append(s[0])
            students.jac.append(int(s[1]))
            s[2]=s[2].split('\n')[0]
            students.major.append(s[2])
            j+=1
    def search_name(self,s):
        print(s)
        ds={}
        j=0
        while 1:
            try:
                if(re.match(s,students.name[j])):
                    #tmp={students.name[j]:students.jac[j]}
                    #ds.update(tmp)
                    return students.jac[j]
                j+=1
            except:
                return "Error\n"
        return ds
A=students()
s=input()
print(A.search_name(s))