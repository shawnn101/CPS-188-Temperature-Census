# Temperature-Census

This project aims to examine previous temperature data collected from several global weather monitoring systems. The monthly land and ocean temperature values from 1750 to 2015 are included in the dataset. The project includes computations and graphs to determine insightful information and trends using C programming and GNU Plot. <br>

The main file is separated into 'questions' that answer prompts regarding the data. When running the code, use the following options to create and observe the necessary files. These files are also found on the main branch.

## Prompts

Question 1 (q1) - Yearly Average (1760-2015) <br>
Question 2 (q2) - Century Averages (18th-21st) <br>
Question 3 (q3) - Monthly Averages (1900-2015)<br>
Question 4 (q4) - Hottest and Coldest Month<br>
Question 5 (q5) - Hottest and Coldest Year<br>
Question 6 (q6) - GNU - Yearly Temp (1760-2015)<br>
Question 7 (q7) - GNU - 100 Year Temp (19th-20th Centuries)<br>
Question 8 (q8) - GNU - Land, Max, Min Temp (1850-2015)<br>
Question 9 (q9) - GNU - Land, Max, Min Temp (18th-21st Century)<br>
Question 10 (q10) - GNU - Average Temperature per Month with Uncertainty (2000-2015)<br>
Question 11 (q11) - GNU - Land and Ocean Temperature Average (1850-2015)<br>



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

## Information

Date Created: March 2024 <br>
Date Published: April 2024 (Private Viewing), 
