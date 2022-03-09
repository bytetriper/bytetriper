from matplotlib import markers
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import numpy as np
import math
import time
def init_with_pace(pace,a=0,b=10):#create a x axis and corrsponding v and t in [a,b]
    x=np.arange(a,b,pace)#create an x axis,deltat=pace
    v0=1#arbitatrily set
    #now create y,indicating the velocity
    y=[]
    v=float(v0)
    for i in x:
        y.append(v)
        v-=pace*v#use a to update v
    y=np.asarray(y)#convert y into a numpy object
    #now create y2,indicating the x(t)
    y2=[]
    for vt in y:
        y2.append(vt*pace)
    y2=np.asarray(y2)#convert y2 into a numpy object
    y2=np.cumsum(y2)#accumulate the x as integral
    return [x,y,y2]
    #done
def make_into_scatter(x,y,y2,ax,a=0,b=10):
    line1=ax.scatter(x,y,label='$velocity$',marker='H')
    line2=ax.scatter(x,y2,label="$x(t)$",marker='.')
    ax.set_xticks(np.arange(a,b,(b-a)/10))  
    ax.legend(handles=[line1,line2])
def make_into_plot(x,y,y2,ax,a=0,b=10):
    line1,=ax.plot(x,y,label='$velocity$')
    line2,=ax.plot(x,y2,label="$x(t)$")
    ax.set_xticks(np.arange(a,b,(b-a)/10))  
    ax.legend(handles=[line1,line2])
# a=-v -> vt=v0-v0*delta(t)
#goals:calculate the instant velocity and use it's integral(finite) as x
a=float(input("left bound="))
b=float(input("right bound="))
pace1=float(input("pace1="))
pace2=float(input("pace2="))
fig, ((ax, ax2)) = plt.subplots(ncols=2)
#create a figure and two axes
x,y,y2=init_with_pace(pace1,a,b)
ax.set_title('$x=$'+str(y2.max())+' and deltat= '+str(pace1),size=8)
make_into_scatter(x,y,y2,ax,a,b)
#ax is for v\x with pace#1 while ax1 is with pace#2
x,y,y2=init_with_pace(pace2,a,b)
ax2.set_title('$x=$'+str(y2.max())+' and deltat= '+str(pace2),size=8)
make_into_scatter(x,y,y2,ax2,a,b)
plt.show()
