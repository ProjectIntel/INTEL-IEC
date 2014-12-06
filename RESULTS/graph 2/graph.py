import numpy as np
import pylab as pl
# Use numpy to load the data contained in the file

data = np.loadtxt('xy.txt')
fig=pl.figure()
fig.suptitle('distance along x-axis vs distance along y-axis')
# plot the first column as x, and second column as y
pl.plot(data[:,0], data[:,1],'ro')
pl.xlabel('x-cm')
pl.ylabel('y-cm')
#pl.subplot(2,1,1)
#pl.xlim(0.0, 10.)
pl.show()

import numpy as np1
import pylab as pl1
# Use numpy to load the data contained in the file

data = np1.loadtxt('xt.txt')
fig=pl1.figure()
fig.suptitle('distance along x-axis vs time')
# plot the first column as x, and second column as y
pl1.plot(data[:,1], data[:,0],'ro')
pl1.xlabel('t-sec')
pl1.ylabel('x-cm')
#pl1.subplot(2,1,1)
#pl1.xlim(0.0, 10.)
pl1.show()



import numpy as np2
import pylab as pl2
# Use numpy to load the data contained in the file

data = np2.loadtxt('yt.txt')
fig=pl2.figure()
fig.suptitle('diatance along y-axis vs time')
# plot the first column as x, and second column as y
pl2.plot(data[:,1], data[:,0],'ro')
pl2.xlabel('t-sec')
pl2.ylabel('y-cm')
#pl2.subplot(2,1,1)
#pl.xlim(0.0, 10.)
pl2.show()


import numpy as np3
import pylab as pl3
# Use numpy to load the data contained in the file

data = np3.loadtxt('dist-ang.txt')
fig=pl3.figure()
fig.suptitle('distance vs angle')
# plot the first column as x, and second column as y
pl3.plot(data[:,1], data[:,0],'ro')
pl3.xlabel('deg')
pl3.ylabel('dis')
#pl3.subplot(2,1,1)
#pl3.xlim(0.0, 10.)
pl3.show()


import numpy as np4
import pylab as pl4
# Use numpy to load the data contained in the file

data = np4.loadtxt('x-speed.txt')
fig=pl4.figure()
fig.suptitle('speed along x-axis vs time')
# plot the first column as x, and second column as y
pl4.plot(data[:,1], data[:,0],'ro')
pl4.xlabel('t-sec')
pl4.ylabel('speed-cm/sec')
#pl4.subplot(2,1,1)
#pl4.xlim(0.0, 10.)
pl4.show()


import numpy as np5
import pylab as pl5
# Use numpy to load the data contained in the file

data = np5.loadtxt('x-ang.txt')
fig=pl5.figure()
fig.suptitle('distance along x-axis vs angle')
# plot the first column as x, and second column as y
pl5.plot(data[:,1], data[:,0],'ro')
pl5.xlabel('deg')
pl5.ylabel('x-cm')
#pl5.subplot(2,1,1)
#pl5.xlim(0.0, 10.)
pl5.show()


import numpy as np6
import pylab as pl6
# Use numpy to load the data contained in the file

data = np6.loadtxt('y-ang.txt')
fig=pl6.figure()
fig.suptitle('distance along y-axis vs angle')
# plot the first column as x, and second column as y
pl6.plot(data[:,1], data[:,0],'ro')
pl6.xlabel('deg')
pl6.ylabel('y-cm')
#pl4.subplot(2,1,1)
#pl4.xlim(0.0, 10.)
pl6.show()
