import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import csv

# Bring asc file to the code
file = 'background_50115.asc'     

# Define names of columns of interest
names = ['energy','intensity']

# Import only columns of interest from file
data = pd.read_csv(file,usecols=[1,2],names=names, sep='\t')

# Print data and check that it matches with what is on livechart
#print(data)

# Plot energy vs intensity
#plt.plot(data['energy'],data['intensity'])
#plt.xlim(0,1000)

# Write to the .dat file needed for Geant4
w = open('Background-G4Hist.dat','w')     

# Divide by 1000 to convert to MeV
energy_kev = data['energy']/1000
num_rows = len(data)

# Make array for the energy and intensity data
energy_dat = [0]
intensity_dat = [0]
 
for i in range(num_rows):
    energy_dat.append(energy_kev[i])
    intensity_dat.append(data['intensity'][i])
    
# Find length of energy_dat
num_dat = len(energy_dat)

# Write a for loop to write into the .dat file
for i in range(num_dat):
    w.write(str(energy_dat[i]))
    w.write(' ')
    w.write(str(intensity_dat[i]))
    w.write('\n')
    
w.close()

# Plot data to see what is going on 
#plt.clf()
#plt.plot(energy_dat,intensity_dat)
##plt.xlim(0,0.2)
##plt.ylim(0,5)

#plt.show()