# C DataFrame Project : Efreixel

You can access the repository [here](https://github.com/AndreaCodinLife/Efreixel).

## Project Idea

The C DataFrame project is a C implementation of the popular DataFrame data structure commonly used in data analysis. It provides a convenient and efficient way to handle and manipulate structured data.

DataFrames are two-dimensional, size-mutable, heterogeneous tabular data structures with labeled axes (rows and columns). They are very similar to tables in a relational database or an Excel spreadsheet (That's why Efreixel). DataFrames are extremely useful for data manipulation, data cleaning, and data analysis.

In this project, we have implemented a DataFrame-like structure in C, called `CDATAFRAME`. The `CDATAFRAME` struct is defined in `cdataframe.h` and its functions are implemented in `cdataframe.c`.

The project also includes files for managing columns (`column.c` and `column.h`) and lists (`list.c` and `list.h`). The `main.c` file is the main entry point for the program.

The project provides various functions for creating and manipulating data frames, such as adding and deleting rows and columns, renaming columns, searching for values, and counting rows, columns, and cells. It also includes a function for storing the contents of a `CDATAFRAME` in a .csv file (`store_cdataframe_to_csv`).

To be developed in the future...