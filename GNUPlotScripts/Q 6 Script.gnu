# Set output format to PNG
set terminal pngcairo enhanced font 'Verdana,10'
set output 'annual temp_plot.png'

# Set titles and labels
set title "Yearly Average Temperatures"
set xlabel "Year"
set ylabel "Temperature (°C)"

# Set grid
set grid

# Plot the data from the specified file
plot "LandAverageYEAR.txt" using 1:2 with linespoints title 'Temperature', \
     '' using 1:2 smooth bezier title 'Trend'



