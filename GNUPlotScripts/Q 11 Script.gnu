set terminal pngcairo enhanced font 'Verdana,12' size 1200,600
set output 'yearly_lo_temp_plot.png'

set title "Yearly Average Land and Land+Ocean Temperatures (1850-2015)"
set xlabel "Year"
set ylabel "Temperature (°C)"
set grid

set style data linespoints
set style line 1 lc rgb 'blue' lt 1 lw 2 pt 7 ps 0.5   # blue (smaller circle)
set style line 2 lc rgb 'red' lt 1 lw 2 pt 7 ps 0.5 # red (smaller circle)

set key outside right top

plot "yearly_LandOceantemperatures.txt" using 1:2 with linespoints linestyle 1 title "Land", \
     "yearly_LandOceantemperatures.txt" using 1:3 with linespoints linestyle 2 title "Land+Ocean"
