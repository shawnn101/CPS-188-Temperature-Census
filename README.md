# Temperature-Census

This project aims to examine previous temperature data collected from several global weather monitoring systems. The monthly land and ocean temperature values from 1750 to 2015 are included in the dataset. The project includes computations and graphs to determine insightful information and trends using C programming and GNU Plot. The main file is separated into 'questions' that answer prompts regarding the data.

## Prompts

Question 1 (q1) -  /<br>
Question 1 (q1) - 
Question 1 (q1) - 
Question 1 (q1) - 
Question 1 (q1) - 
Question 1 (q1) - 
Question 1 (q1) - 
Question 1 (q1) - 
Question 1 (q1) - 
Question 1 (q1) - 
Question 1 (q1) - 
Question 1 (q1) - 


## Libraries

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
```

## GNU Plot Sample Script 

```gnuplot
# Question 6

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
     '' using 1:2 smooth bezier title 'Trend' # Note that this line of code can be changed to create a visual of your liking
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
