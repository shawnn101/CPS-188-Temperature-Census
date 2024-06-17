# Set the terminal to PNG and specify the output file name
set terminal pngcairo enhanced font "arial,10" size 1200,600
set output "monthly_averages_error_with_trendline.png"

# Set the style of the plot
set title "Monthly Averages with Error Bars (2000-2015)"
set xlabel "Month"
set ylabel "Temperature (°C)"
set xrange [0.5:12.5]
set yrange [-2:35]
set grid

# Define the data file
datafile = "monthly_averages_error.txt"

# Plot the data with error bars
plot datafile using 1:2:3 with yerrorbars title "Temperature with Uncertainty" lc rgb "blue", \
     datafile using 1:2 smooth bezier title "Trendline" lc rgb "red", \
     datafile using 1:2 with lines title "Monthly Averages" lc rgb "green"
