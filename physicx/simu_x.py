import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import numpy as np
import math
v0=1
pace=0.05
x=np.arange(0,1,pace)
tmpv=float(v0)
y=[]
cnt=0
for i in x:
    y.append(tmpv)
    cnt+=1
    tmpv=tmpv-tmpv*pace
fig,ax=plt.subplots()
line,=ax.plot(x,y,marker='H',color='r',label="velocity")
y=np.sin(y)
line1,=ax.plot(x,y,marker='.',color='y',label="sicks")
rp=mpatches.Patch(color="red",label="sss")
fr=ax.legend([line,line1],["1","2"],loc="lower right")
ax.add_artist(fr)
ax.legend([rp],['yyy'])
ax.set_title("shift",fontsize=30,pad=0,loc='right',style='italic',rotation=45,weight='bold')
plt.show()