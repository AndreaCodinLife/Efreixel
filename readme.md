# C DataFrame Project : Efreixel

Welcome to the Efreixel repository, a C implementation of the popular DataFrame data structure commonly used in data analysis. You can access the repository [here](https://github.com/AndreaCodinLife/Efreixel).

## Overview

DataFrames are two-dimensional, size-mutable, heterogeneous tabular data structures with labeled axes (rows and columns). They are very similar to tables in a relational database or an Excel spreadsheet. DataFrames are extremely useful for data manipulation, data cleaning, and data analysis.

In this project, we have implemented a DataFrame-like structure in C, called `CDATAFRAME`. The `CDATAFRAME` struct is defined in [`cdataframe.h`] and its functions are implemented in [`cdataframe.c`].

## Project Structure

The project includes files for managing columns ([`column.c`] and [`column.h`]) and lists ([`list.c`] and [`list.h`]). The [`main.c`] file is the main entry point for the program.

Here are some of the key files in the project:

- [``cdataframe.c``] and [``cdataframe.h``]: These files contain the implementation and declaration of the `CDATAFRAME` struct and its associated functions.
- [`column.c`] and [`column.h`] and [`column.h`]: These files contain the implementation and declaration of the `COLUMN` struct and its associated functions.
- [`[`list.c`]`] and [``list.h``]: These files contain the implementation and declaration of the `LIST` struct and its associated functions.
- [``sort.c``] and [``sort.h``]: These files contain the implementation and declaration of various sorting algorithms used in the project.
- [``main.c``]: This is the main entry point for the program.

## Features

The project provides various functions for creating and manipulating data frames, such as:

- Adding and deleting rows and columns
- Accessing and modifying data
- Searching for values
- Counting rows, columns, and cells
- Sorting data frames
- Storing the contents of a `CDATAFRAME` in a .csv file (`store_cdataframe_to_csv`)
- Loading the contents of a .csv file into a `CDATAFRAME` (`load_cdataframe_from_csv`)
- Displaying the contents of a `CDATAFRAME` (`display_cdataframe`)
- And more...

## Future Developments

Stay tuned for future updates and improvements to the project. We are always looking to enhance the functionality and performance of our DataFrame implementation.

## Contributing

We welcome contributions from the community. If you have any suggestions or improvements, feel free to create a pull request or open an issue.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.