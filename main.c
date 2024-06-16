#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_L 1024
#define START 1760
#define START_Q5 1900
#define START_Q8 1850
#define END 2015
#define CENTURIES 4
#define NUM_MONTHS 12
#define RANGE (END - START + 1) // Number of years in the range

#define MAX_L 1024
#define START_18 1760
#define END_18 1799
#define START_19 1800
#define END_19 1899
#define START_20 1900
#define END_20 1999
#define START_21 2000
#define END_21 2015


int q1 (void) {
  FILE *in;
      FILE *out;
      char line[MAX_L];
      double temp_sum[RANGE] = {0};
      int month_num[RANGE] = {0};
      int year;
      double temp;

      in = fopen("GlobalTemperatures.csv", "r");
      out = fopen("LandAverageYEAR.txt", "w");

      if (!in || !out) {
          printf("Error: Unable to open file.\n");
          if(in) fclose(in);
          if(out) fclose(out);
          return 1;
      }

      // Skip the header line
      fgets(line, MAX_L, in);

      // Read each line from the CSV file
      while (fgets(line, MAX_L, in) != NULL) {
          // Attempt to read the year and temperature from the current line
          if (sscanf(line, "%4d", &year) == 1) { // Successfully read the year
              // Move to the temperature part of the line
              char *vari = strtok(line, ",");
              vari = strtok(NULL, ",");

              if (vari != NULL && year >= START && year <= END) {
                  temp = atof(vari);
                  int index = year - START; // Index in the array
                  temp_sum[index] += temp;
                  month_num[index]++;
              }
          }
      }
      fclose(in);

      // Calculate and write the yearly temperatures to the out
      printf("\nYearly temperature (%d to %d):\n\n", START, END);
      for (int i = 0; i < RANGE; i++) {
          if (month_num[i] > 0) {
              double temp_avg = temp_sum[i] / month_num[i]; // Calculate the temprature average 

            fprintf(out, "%d\t%.2f\n", START + i, temp_avg); printf("%d: %.2f\n",
  START + i, temp_avg); // Also print the year and its average temprature
          }
      }
      fclose(out);

      return 0;
  }

int q2(void){
      FILE *in;
      FILE *out;
      char line[MAX_L];
      double land_sum_18 = 0; // Total land temperature sum for 18th century
      double land_avg_18; // Average land temperature for 18th century
      int land_count_18 = 0; // Count of land temperature readings for 18th century

      int cent1 = 18;
      int cent2 = 19;
      int cent3 = 20;
      int cent4 = 21;

      double land_sum_19 = 0; 
      double land_avg_19; 
      int land_count_19 = 0; 

      double land_sum_20 = 0; 
      double land_avg_20; 
      int land_count_20 = 0; 

      double land_sum_21 = 0; 
      double land_avg_21; 
      int land_count_21 = 0; 

      int year, month, day;
      double land_temp;

      in = fopen("GlobalTemperatures.csv", "r");
      out = fopen("LandAverageCentury.txt", "w");

      if (!in || !out) {
          printf("Error: Unable to open files.\n");
          return 1;
      }

      // Skip the header line
      fgets(line, MAX_L, in);

      // Read each line from the CSV file
      while (fgets(line, MAX_L, in) != NULL) {
          // Attempt to read the year, month, day, land temperature, and ocean temperature from the current line
          if (sscanf(line, "%4d-%2d-%2d,%lf", &year, &month, &day, &land_temp) == 4) {
              if (year >= START_18 && year <= END_18) {
                  land_sum_18 += land_temp;
                  land_count_18++;
              } else if (year >= START_19 && year <= END_19) {
                  land_sum_19 += land_temp;
                  land_count_19++;
              } else if (year >= START_20 && year <= END_20) {
                  land_sum_20 += land_temp;
                  land_count_20++;
              } else if (year >= START_21 && year <= END_21) {
                  land_sum_21 += land_temp;
                  land_count_21++;
              }
          }
      }

      // Calculate average land temperature for each century
      land_avg_18 = land_sum_18 / land_count_18;
      fprintf(out, "%d  %.2lf\n", cent1, land_avg_18);

      land_avg_19 = land_sum_19 / land_count_19;
      fprintf(out, "%d  %.2lf\n", cent2,land_avg_19);

      land_avg_20 = land_sum_20 / land_count_20;
      fprintf(out, "%d  %.2lf\n", cent3, land_avg_20);

      land_avg_21 = land_sum_21 / land_count_21;
      fprintf(out, "%d  %.2lf\n", cent4, land_avg_21);

      fclose(in);
      fclose(out);

      return 0;
  }


int q3(void){
      FILE *inputFile;
      double monthlySum[NUM_MONTHS] = {0};
      int monthCount[NUM_MONTHS] = {0};
      char line[MAX_L];

      // Open the input file for reading
      inputFile = fopen("GlobalTemperatures.csv", "r");
      if (!inputFile) {
          printf("Failed to open the file.\n");
          return 1;
      }

      // Skip the header line
      fgets(line, sizeof(line), inputFile);

      while (fgets(line, MAX_L, inputFile) != NULL)
        {
          int year, month, day;
          double temperature;
          // Use sscanf to directly extract year, month, and temperature
          if (sscanf(line, "%4d-%2d-%2d,%lf", &year, &month, &day, &temperature) == 4) {          
              // Check if the year is within the specified range
              if (year >= START_Q5 && year <= END && month >= 1 && month <= NUM_MONTHS) {
                  monthlySum[month - 1] += temperature; // Add temperature to sum for the month
                  monthCount[month - 1]++; // Increment count of data points for the month
              }
          }
      }

      fclose(inputFile);

      // Open the output file for writing
      FILE *outputFile = fopen("LandAveragePerMonth.txt", "w");
      if (!outputFile) {
          printf("Failed to open the output file.\n");
          return 1;
      }

      // Calculate and write monthly averages to output file

    printf("\nAverage Temprature per Month (1900-2015): \n\n");
      for (int i = 0; i < NUM_MONTHS; i++) {
          if (monthCount[i] > 0) {
              double average = monthlySum[i] / monthCount[i];
              printf("Month %d: %.2f\n", i + 1, average);
              fprintf(outputFile, "%d  %.2f\n", i + 1, average);
          }
      }

      fclose(outputFile);

      return 0;
  }


int q4(void){
      FILE *in;
      FILE *out;
      char line[MAX_L];
      double month_sum[NUM_MONTHS] = {0}; // Array to store sum of temperatures for each month
      int month_num[NUM_MONTHS] = {0};   // Array to store count of data points for each month
      int year, month, day;
      double temp;

      // Hottest temperature is set to a low number so any number being updated is greater, making it the hottest temperature
      // Coldest temperature is set to a high number so any number being updated is less, making it the coldest temperature
      double hot_temp = -1024;
      double cold_temp = 1024;
      int hot_yr = 0, hot_month = 0;
      int cold_yr = 0, cold_month = 0;

      in = fopen("GlobalTemperatures.csv", "r");
      out = fopen("HotColdMONTH.txt", "w");

      if (!in || !out) {
          printf("Error: Unable to open file.\n");
          if (in) fclose(in);
          if (out) fclose(out);
          return 1;
      }

      // Skip the header line
      fgets(line, MAX_L, in);

      // Read each line from the CSV file
      while (fgets(line, MAX_L, in) != NULL) {
          // Attempt to read the year, month, day, and temperature from the current line
          if (sscanf(line, "%4d-%2d-%2d,%lf", &year, &month, &day, &temp) == 4) {
              if (year >= START && year <= END && month >= 1 && month <= NUM_MONTHS) {
                  month_sum[month - 1] += temp; // Add temperature to sum for the month
                  month_num[month - 1]++;              // Increment count of data points for the month

                  // Update hottest and coldest temperatures and corresponding year and month
                  if (temp > hot_temp) {
                      hot_temp = temp;
                      hot_yr = year;
                      hot_month = month;
                  }
                  if (temp < cold_temp) {
                      cold_temp = temp;
                      cold_yr = year;
                      cold_month = month;
                  }
              }
          }
      }

      fclose(in);


      // Write hottest and coldest temperatures and corresponding year and month to output file
      printf("\nHottest Month-Year: %d-%d, Temperature: %.2f\n", hot_month, hot_yr, hot_temp);
      printf("Coldest Month: %d-%d, Temperature: %.2f\n", cold_month, cold_yr, cold_temp);
      fprintf(out, "Hottest Month-Year: %d-%d, Temperature: %.2f\n", hot_month, hot_yr, hot_temp);
      fprintf(out, "Coldest Month-Year: %d-%d, Temperature: %.2f\n", cold_month, cold_yr, cold_temp);

      fclose(out);

      return 0;
  }


int q5(void) {
    FILE *in;
    FILE *out;
    char line[MAX_L];
    double temp_sum[RANGE] = {0};
    int month_num[RANGE] = {0};
    int year;
    double temp;
    int hot_yr = 0;
    int cold_yr = 0;


    // Hottest temperature is set to a low number so any number being updated is greater, making it the hottest temprature
    // Coldest temprature is set to a high number so any number being updated is less, making it the coldest temperature
    double hot_temp = -1024; 
    double cold_temp = 1024; 

    in = fopen("LandAverageYEAR.txt", "r");
    out = fopen("HotColdYEAR.txt", "w");

    if (!in || !out) {
        printf("Error: Unable to open file.\n");
        if (in) fclose(in);
        if (out) fclose(out);
        return 1;
    }

    // Skip the header line
    fgets(line, MAX_L, in);

    // Read each line from the CSV file
    while (fgets(line, MAX_L, in) != NULL) {
        // Attempt to read the year and temperature from the current line
        if (sscanf(line, "%4d", &year) == 1) { // Successfully read the year
            // Move to the temp part of the line
            char *vari = strtok(line, "\t");
            vari = strtok(NULL, "\t");

            if (vari != NULL && year >= START && year <= END) {
                temp = atof(vari);
                int index = year - START; // Index in the array
                temp_sum[index] += temp;
                month_num[index]++;

                // Update hottest and coldest temperatures and corresponding years
                double temp_avg = temp_sum[index] / month_num[index];
                if (temp_avg > hot_temp) {
                    hot_temp = temp_avg;
                    hot_yr = year;
                }
                if (temp_avg < cold_temp) {
                    cold_temp = temp_avg;
                    cold_yr = year;
                }
            }
        }
    }
    fclose(in);

        // Print hottest and coldest years and their temperatures
       printf("\nHottest Year: %d, Average Temperature: %.2f\n", hot_yr, hot_temp);
       printf("Coldest Year: %d, Average Temperature: %.2f\n", cold_yr, cold_temp);
       fprintf(out,"Hottest Year: %d, Average Temperature: %.2f\n", hot_yr, hot_temp);
       fprintf(out,"Coldest Year: %d, Average Temperature: %.2f\n", cold_yr, cold_temp);



    fclose(out);

    return 0;
}

int q8(void){
      FILE *in, *out;
      char line[MAX_L];
      int year, month, day;
      double avg_temp, max_temp, min_temp;
      double sum_avg_temp = 0, sum_max_temp = 0, sum_min_temp = 0;
      int current_year = START_Q8;
      int iter = 0;

      // Open the CSV file for reading
      in = fopen("GlobalTemperatures.csv", "r");
      if (in == NULL) {
          fprintf(stderr, "Error: Unable to open file.\n");
          return 1;
      }

      // Open the output file
      out = fopen("LandMinMaxTemp.txt", "w");
      if (out == NULL) {
          fprintf(stderr, "Error: Unable to create output file.\n");
          fclose(in);
          return 1;
      }

      // Skip the header line
      fgets(line, sizeof(line), in);

      // Read each line from the CSV file
      while (fgets(line, sizeof(line), in) != NULL) {
          // Parse the line to extract data, skipping the fourth column
          if (sscanf(line, "%4d-%2d-%2d,%lf,%*[^,],%lf, %*[^,], %lf", &year, &month, &day, &avg_temp, &max_temp, &min_temp) == 6) {
              // Check if the year is within the range 1850-2015
              if (year >= START && year <= END) {
                  // Aggregate temperatures for the current year
                  if (year == current_year) {
                      sum_avg_temp += avg_temp;
                      sum_max_temp += max_temp;
                      sum_min_temp += min_temp;
                      iter++;
                  } else {
                      // Calculate and write the averages for the previous year
                      fprintf(out, "%d  %.2f  %.2f  %.2f\n", current_year, sum_avg_temp / iter, sum_max_temp / iter, sum_min_temp / iter);

                      // Reset for the new year
                      sum_avg_temp = avg_temp;
                      sum_max_temp = max_temp;
                      sum_min_temp = min_temp;
                      current_year = year;
                      iter = 1;
                  }
              }
          }
      }

      // Write the averages for the last year in the file
      if (iter > 0) { // Ensure there were entries for the last year

      printf("Year: %d, LandAverageTemperature: %.2f, LandMaxTemperature: %.2f, LandMinTemperature: %.2f\n", year, avg_temp, max_temp, min_temp);
          fprintf(out, "%d  %.2f  %.2f  %.2f\n", current_year, sum_avg_temp / iter, sum_max_temp / iter, sum_min_temp / iter);
      }

      // Close the files
      fclose(in);
      fclose(out);

      return 0;
  }


int q9(void){
    FILE *in;
    FILE *out, *out18, *out19, *out20, *out21;

    char line[MAX_L];
    double land_sum_18 = 0; // Total land temperature sum for 18th century
    double max_sum_18 = 0; // Total maximum temperature sum for 18th century
    double min_sum_18 = 0; // Total minimum temperature sum for 18th century
    double land_count_18 = 0.0; // Count of land temperature readings for 18th century
    double temp_count_18 = 0.0; // Count of max and min land temperature readings for 18th century

    double land_sum_19 = 0; 
    double max_sum_19 = 0; 
    double min_sum_19 = 0; 
    double land_count_19 = 0.0; 
    double temp_count_19 = 0.0;

    double land_sum_20 = 0; 
    double max_sum_20 = 0; 
    double min_sum_20 = 0; 
    double land_count_20 = 0.0; 
    double temp_count_20 = 0.0;

    double land_sum_21 = 0;
    double max_sum_21 = 0; 
    double min_sum_21 = 0; 
    double land_count_21 = 0.0; 
    double temp_count_21 = 0.0;

    int centone = 18;
    int centwo = 19;
    int centthree = 20;
    int centfour = 21;

    int year, month, day;
    double land_temp, max_temp, min_temp;


    in = fopen("GlobalTemperatures.csv", "r");
    out = fopen("century_max_min_Landtemps.txt", "w");
    out18 = fopen("century_max_min_18.txt", "w");
    out19 = fopen("century_max_min_19.txt", "w");
    out20 = fopen("century_max_min_20.txt", "w");
    out21 = fopen("century_max_min_21.txt", "w");



    if (!in || !out) {
        printf("Error: Unable to open files.\n");
        return 1;
    }

    // Skip the header line
    fgets(line, MAX_L, in);

    // Read each line from the CSV file
    while (fgets(line, MAX_L, in) != NULL) {
        // Attempt to read the year, month, day, land temperature, and ocean temperature from the current line
        if (sscanf(line, "%4d-%2d-%2d,%lf", &year, &month, &day, &land_temp) == 4) {
            // Treat NaN values as 0
            // Calcualte for Land averages for each century
            if (year >= START_18 && year <= END_18) {
                land_sum_18 += isnan(land_temp) ? 0 : land_temp;
                land_count_18++; // Max and Min temps nor present for 18th century

            } else if (year >= START_19 && year <= END_19) {
                land_sum_19 += isnan(land_temp) ? 0 : land_temp;
                land_count_19++;

            } else if (year >= START_20 && year <= END_20) {
                land_sum_20 += isnan(land_temp) ? 0 : land_temp;
                land_count_20++;

            } else if (year >= START_21 && year <= END_21) {
                land_sum_21 += isnan(land_temp) ? 0 : land_temp;
                land_count_21++;
            }
        }

      // Calcualte for Max/Min averages for each century

      if (sscanf(line, "%*[^,],%*[^,],%*[^,],%lf,%*[^,],%lf", &max_temp, &min_temp) == 2) {

        if (year >= START_18 && year <= END_18) {
            max_sum_18 += isnan(max_temp) ? 0 : max_temp;
            min_sum_18 += isnan(min_temp) ? 0 : min_temp;
            temp_count_18++;


        } else if (year >= START_19 && year <= END_19) {
            max_sum_19 += isnan(max_temp) ? 0 : max_temp;
            min_sum_19 += isnan(min_temp) ? 0 : min_temp;
            temp_count_19++;

        } else if (year >= START_20 && year <= END_20) {
            max_sum_20 += isnan(max_temp) ? 0 : max_temp;
            min_sum_20 += isnan(min_temp) ? 0 : min_temp;

            temp_count_20++;

        } else if (year >= START_21 && year <= END_21) {
            max_sum_21 += isnan(max_temp) ? 0 : max_temp;
            min_sum_21 += isnan(min_temp) ? 0 : min_temp;

            temp_count_21++;
        }

       }
    }


    // Calculate average land temperature for each century. Write the averages in thier respective files
    double land_avg_18 = land_sum_18 / land_count_18;
    double max_avg_18 = max_sum_18 / temp_count_18;
    double min_avg_18 = min_sum_18 / temp_count_18;

    fprintf(out, "%d  %.2lf  %.2lf  %.2lf\n", centone, land_avg_18, max_avg_18, min_avg_18);
    fprintf(out18, "%d  %.2lf  %.2lf  %.2lf\n", centone, land_avg_18, max_avg_18, min_avg_18);

    double land_avg_19 = land_sum_19 / land_count_19;
    double max_avg_19 = max_sum_19 / temp_count_19;
    double min_avg_19 = min_sum_19 / temp_count_19;

    fprintf(out, "%d  %.2lf  %.2lf  %.2lf\n", centwo, land_avg_19, max_avg_19, min_avg_19);
  fprintf(out19, "%d  %.2lf  %.2lf  %.2lf\n", centwo, land_avg_19, max_avg_19, min_avg_19);

    double land_avg_20 = land_sum_20 / land_count_20;
    double max_avg_20 = max_sum_20 / temp_count_20;
    double min_avg_20 = min_sum_20 / temp_count_20;
    fprintf(out, "%d  %.2lf  %.2lf  %.2lf\n", centthree, land_avg_20, max_avg_20, min_avg_20);
  fprintf(out20, "%d  %.2lf  %.2lf  %.2lf\n", centthree, land_avg_20, max_avg_20, min_avg_20);

    double land_avg_21 = land_sum_21 / land_count_21;
    double max_avg_21 = max_sum_21 / temp_count_21;
    double min_avg_21 = min_sum_21 / temp_count_21;
    fprintf(out, "%d  %.2lf  %.2lf  %.2lf\n", centfour, land_avg_21, max_avg_21, min_avg_21);
  fprintf(out21, "%d  %.2lf  %.2lf  %.2lf\n", centfour, land_avg_21, max_avg_21, min_avg_21);

    fclose(in);
    fclose(out);

    return 0;
}


int q10(void){
      FILE *in;
      FILE *out;
      char line[MAX_L];
      double temp_sum[NUM_MONTHS] = {0}; // Array to store temperature sums for each month
      double uncer_sum[NUM_MONTHS] = {0}; // Array to store uncertainty sums for each month
      int count[NUM_MONTHS] = {0}; // Array to store the count of data points for each month
      int year, month, day;
      double temp, uncer;

      in = fopen("GlobalTemperatures.csv", "r");
      out = fopen("monthly_averages_error.txt", "w");

      if (!in || !out) {
          printf("Error: Unable to open files.\n");
          return 1;
      }

      // Skip the header line
      fgets(line, MAX_L, in);

      // Read each line from the CSV file
      while (fgets(line, MAX_L, in) != NULL) {
          // Attempt to read the year, month, day, temperature, and uncer from the current line
          if (sscanf(line, "%d-%d-%d,%lf,%lf", &year, &month, &day, &temp, &uncer) == 5 && year >= START && year <= END) {
              temp_sum[month - 1] += temp; // Subtract 1 from month to match array indexing (0-based)
              uncer_sum[month - 1] += uncer;
              count[month - 1]++;
          }
      }

      fclose(in);

      // Write the data to the output file
      for (int i = 0; i < NUM_MONTHS; i++) {
          if (count[i] > 0) {
              double avg_temp = temp_sum[i] / count[i];
              double avg_uncertainty = uncer_sum[i] / count[i];
              fprintf(out, "%d  %.2f  %.2f\n", i + 1, avg_temp, avg_uncertainty); // Add 1 to month to match the 1-based index
          }
      }

      fclose(out);

      return 0;
  }

int q11(void){
      FILE *in;
      FILE *out;
      char line[MAX_L];
      double land_sum = 0; // Total land temperature sum for each year
      double lo_sum = 0; // Total land and ocean temperature sum for each year
      double land_avg = 0; // Average land temperature for each year
      double lo_avg = 0; // Average land and ocean temperature for each year
      int land_count = 0; // Count of land temperature readings for each year
      int lo_count = 0; // Count of land and ocean temperature readings for each year
      int year, month, day;
      double land_temp, lo_temp;

      in = fopen("GlobalTemperatures.csv", "r");
      out = fopen("yearly_LandOceantemperatures.txt", "w");

      if (!in || !out) {
          printf("Error: Unable to open files.\n");
          return 1;
      }

      // Skip the header line
      fgets(line, MAX_L, in);

      // Read each line from the CSV file
      while (fgets(line, MAX_L, in) != NULL) {
          // Attempt to read the year, month, day, land temperature, and ocean temperature from the current line
          if (sscanf(line, "%d-%d-%d,%lf, %*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%lf", &year, &month, &day, &land_temp, &lo_temp) == 5) {
              if (year >= START && year <= END) {
                  land_sum += land_temp;
                  lo_sum += lo_temp;
                  land_count++;
                  lo_count++;

                  // Check if we have data for 12 months
                  if (land_count % 12 == 0) {
                      // Calculate the average temperatures for this year
                      land_avg = land_sum / 12;
                      lo_avg = lo_sum / 12;

                      // Write the yearly temperatures to the output file
                      fprintf(out, "%d\t%.2f\t%.2f\n", year, land_avg, lo_avg);

                      // Reset accumulators for the next year
                      land_sum = 0;
                      lo_sum = 0;
                      land_count = 0;
                      lo_count = 0;
                  }
              }
          }
      }

      fclose(in);
      fclose(out);

      return 0;
  }



int main(void){

  int sel_num;

  printf("Please select a Question: \n\n");
  
  for (int i = 1; i <= 11; i++) {
      if (i == 6 || i == 7) {
          continue; // Skip the rest of the loop body for 6 and 7
      }
      printf("Question %d\n", i);
  }

  scanf("%d", &sel_num);

  // Select which question you would like to run
  // Note that 6 and 7 were skipped as they only required the GNU script and previous files to plot
  // Q6 and Q7 requires file created in Q1
  switch (sel_num){

    case 1:
      q1();
      printf("\n");
      break;

    case 2:
      q2();
      printf("\n");
      break;

    case 3:
      q3();
      printf("\n");
      break;
    
    case 4:
      q4();
      printf("\n");
      break;

    case 5:
      q5();
      printf("\n");
      break;

    case 8:
      q8();
      printf("\n");
      break;

    case 9:
      q9();
      printf("\n");
      break;
    
    case 10:
      q10();
      printf("\n");
      break;

    case 11:
      q11();
      printf("\n");
      break;
    
    default:
      printf("Invalid Input\n");
      break;


  }

  return 0;
}

