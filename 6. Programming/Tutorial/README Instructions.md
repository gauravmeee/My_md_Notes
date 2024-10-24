Here’s the content for your `README.md` file without Markdown formatting:

---

# United Airlines Call Center Analysis

This project provides a comprehensive analysis of the United Airlines call center data, focusing on Average Handle Time (AHT) and Average Speed to Answer (AST). The analysis is modularized into separate Python scripts for better organization and maintainability.

## Project Structure

data_preparation.py         # Loads and prepares the data  
aht_analysis.py             # Analyzes Average Handle Time  
ast_analysis.py             # Analyzes Average Speed to Answer  
call_volume_analysis.py      # Analyzes call volume patterns  
correlation_analysis.py      # Analyzes correlation between AHT and AST  
common_reasons_analysis.py   # Analyzes most common call reasons  
percentage_difference_analysis.py  # Calculates percentage difference in AHT  
silence_analysis.py          # Analyzes relationship between silence percentage and AHT  
main.py                     # Main script to run all analyses  

## Requirements

Before running the scripts, ensure you have the following Python packages installed:

- pandas
- matplotlib
- seaborn
- numpy

You can install the required packages using pip:

pip install pandas matplotlib seaborn numpy

## Data Files

Ensure you have the required CSV files in the same directory as the scripts, or adjust the file paths in the scripts accordingly.

## Running the Analysis

To run the complete analysis, execute the main.py script:

python main.py

This will sequentially run all analyses and generate visualizations saved as PNG files in the working directory.

## Analysis Components

1. **Data Preparation**  
   data_preparation.py: Loads data from CSV files, converts datetime columns, calculates AHT and AST, and merges dataframes.

2. **AHT Analysis**  
   aht_analysis.py: Computes overall average AHT, AHT by call reason, agent performance, sentiment category, and customer tone.

3. **AST Analysis**  
   ast_analysis.py: Computes overall average AST and AST by call reason and hour of the day.

4. **Call Volume Analysis**  
   call_volume_analysis.py: Analyzes call volume patterns by hour.

5. **Correlation Analysis**  
   correlation_analysis.py: Examines the correlation between AST and AHT.

6. **Common Call Reasons**  
   common_reasons_analysis.py: Identifies and visualizes the most frequent call reasons.

7. **Percentage Difference Analysis**  
   percentage_difference_analysis.py: Calculates the percentage difference in AHT between the most and least frequent call reasons.

8. **Silence Percentage Analysis**  
   silence_analysis.py: Analyzes the relationship between silence percentage and AHT.

## Visualizations

All visualizations generated from the analyses will be saved as PNG files in the working directory.

## Conclusion

This project aims to provide valuable insights into the call center's performance and identify areas for improvement based on AHT, AST, and call volume data.

For any questions or feedback, please feel free to reach out!
