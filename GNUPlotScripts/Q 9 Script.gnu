set terminal pngcairo enhanced size 1800,800 font 'Verdana,12'
set output 'century_temperature_comparison.png'

# Define data file
datafile18 = "century_max_min_18.txt"
datafile19 = "century_max_min_19.txt"
datafile20 = "century_max_min_20.txt"
datafile21 = "century_max_min_21.txt"

# Set bar width
box_width = 0.5

# Plot setup
set ylabel "Temperature"
set ytics 2
set xrange [17:22]
set yrange [0:17]
set key outside top right

set multiplot layout 1,3

# Plot land average temperatures
set title "Land Average Temperature Comparison"
set boxwidth box_width
plot datafile18 using ($1):2 with boxes lc rgb "green" title "18th Century" fill solid, \
     datafile19 using ($1):2 with boxes lc rgb "blue" title "19th Century" fill solid, \
     datafile20 using ($1):2 with boxes lc rgb "orange" title "20th Century" fill solid, \
     datafile21 using ($1):2 with boxes lc rgb "red" title "21st Century" fill solid

# Plot land max temperatures
set title "Land Max Temperature Comparison"
set boxwidth box_width
plot datafile18 using ($1):3 with boxes lc rgb "green" title "18th Century" fill solid, \
     datafile19 using ($1):3 with boxes lc rgb "blue" title "19th Century" fill solid, \
     datafile20 using ($1):3 with boxes lc rgb "orange" title "20th Century" fill solid, \
     datafile21 using ($1):3 with boxes lc rgb "red" title "21st Century" fill solid

# Plot land min temperatures
set title "Land Min Temperature Comparison"
set boxwidth box_width
plot datafile18 using ($1):4 with boxes lc rgb "green" title "18th Century" fill solid, \
     datafile19 using ($1):4 with boxes lc rgb "blue" title "19th Century" fill solid, \
     datafile20 using ($1):4 with boxes lc rgb "orange" title "20th Century" fill solid, \
     datafile21 using ($1):4 with boxes lc rgb "red" title "21st Century" fill solid

unset multiplot
