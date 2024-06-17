REQUIRES A NEW C PROGRAM

set terminal pngcairo size 1200, 500  # Set the output format to PNG
set output 'LandMinMaxTemp.png'  # Set the output file name

set title 'Land Temperatures from 1850 to 2015'  # Set the chart title
set xlabel 'Year'  # Label for the X-axis
set ylabel 'Temperature (°C)'  # Label for the Y-axis
set key outside  # Place the legend outside the plot
set grid  # Enable grid

# Plotting the data
plot 'LandMinMaxTemp.txt' using 1:2 with lines linewidth 3 title 'Average Temperature', \
     '' using 1:3 with lines linewidth 1 title 'Max Temperature', \
     '' using 1:4 with lines linewidth 1 title 'Min Temperature'
