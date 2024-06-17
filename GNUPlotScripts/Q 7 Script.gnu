# Set the output file format and name
set terminal png
set output "temperature_plot_19th_20th_century.png"

# Set the title and labels
set title "Temperature Plot for the 19th and 20th Centuries"
set xlabel "Year Number"
set ylabel "Temperature (°C)"

# Set the data file
datafile = "LandAverageYEAR.txt"

# Define the range for the 19th century
nineteenth_century_start = 1800
nineteenth_century_end = 1899

# Define the range for the 20th century
twentieth_century_start = 1900
twentieth_century_end = 1999

# Plot values for the 19th and 20th century
plot datafile using ($1 >= nineteenth_century_start && $1 <= nineteenth_century_end ? $1 - nineteenth_century_start : NaN):2 \
    with lines lc rgb "red" lw 2 title "19th Century", \
     datafile using ($1 >= twentieth_century_start && $1 <= twentieth_century_end ? $1 - twentieth_century_start : NaN):2 \
    with lines lc rgb "blue" lw 2 title "20th Century"
