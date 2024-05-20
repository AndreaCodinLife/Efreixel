# C DataFrame Project : Efreixel

Welcome to the Efreixel repository, a C implementation of the popular DataFrame data structure commonly used in data analysis. You can access the repository [here](https://github.com/AndreaCodinLife/Efreixel).

## Overview

DataFrames are two-dimensional, size-mutable, heterogeneous tabular data structures with labeled axes (rows and columns). They are very similar to tables in a relational database or an Excel spreadsheet. DataFrames are extremely useful for data manipulation, data cleaning, and data analysis.

In this project, we have implemented a DataFrame-like structure in C, called `CDATAFRAME`. The `CDATAFRAME` struct is defined in [`cdataframe.h`](command:_github.copilot.openSymbolInFile?%5B%22cdataframe.h%22%2C%22cdataframe.h%22%5D "cdataframe.h") and its functions are implemented in [`cdataframe.c`](command:_github.copilot.openSymbolInFile?%5B%22cdataframe.c%22%2C%22cdataframe.c%22%5D "cdataframe.c").

## Project Structure

The project includes files for managing columns ([`column.c`](command:_github.copilot.openSymbolInFile?%5B%22column.c%22%2C%22column.c%22%5D "column.c") and [`column.h`](command:_github.copilot.openSymbolInFile?%5B%22column.h%22%2C%22column.h%22%5D "column.h")) and lists ([`list.c`](command:_github.copilot.openSymbolInFile?%5B%22list.c%22%2C%22list.c%22%5D "list.c") and [`list.h`](command:_github.copilot.openSymbolInFile?%5B%22list.h%22%2C%22list.h%22%5D "list.h")). The [`main.c`](command:_github.copilot.openSymbolInFile?%5B%22main.c%22%2C%22main.c%22%5D "main.c") file is the main entry point for the program.

Here are some of the key files in the project:

- [``cdataframe.c``](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22vsls%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fcdataframe.c%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/cdataframe.c") and [``cdataframe.h``](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22vsls%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fcdataframe.h%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/cdataframe.h"): These files contain the implementation and declaration of the `CDATAFRAME` struct and its associated functions.
- [`[`column.c`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22path%22%3A%22%2Fcolumn.h%22%2C%22scheme%22%3A%22vsls%22%7D%2C%7B%22line%22%3A0%2C%22character%22%3A0%7D%5D "column.h")`](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22vsls%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fcolumn.c%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/column.c") and [`[`column.h`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22path%22%3A%22%2Fcolumn.h%22%2C%22scheme%22%3A%22vsls%22%7D%2C%7B%22line%22%3A0%2C%22character%22%3A0%7D%5D "column.h")`](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22vsls%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fcolumn.h%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/column.h"): These files contain the implementation and declaration of the `COLUMN` struct and its associated functions.
- [`[`list.c`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22path%22%3A%22%2Flist.h%22%2C%22scheme%22%3A%22vsls%22%7D%2C%7B%22line%22%3A0%2C%22character%22%3A0%7D%5D "list.h")`](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22vsls%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Flist.c%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/list.c") and [``list.h``](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22vsls%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Flist.h%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/list.h"): These files contain the implementation and declaration of the `LIST` struct and its associated functions.
- [``sort.c``](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22vsls%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fsort.c%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/sort.c") and [``sort.h``](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22vsls%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fsort.h%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/sort.h"): These files contain the implementation and declaration of various sorting algorithms used in the project.
- [``main.c``](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22vsls%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fmain.c%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/main.c"): This is the main entry point for the program.

## Features

The project provides various functions for creating and manipulating data frames, such as:

- Adding and deleting rows and columns
- Renaming columns
- Searching for values
- Counting rows, columns, and cells
- Sorting data frames
- Storing the contents of a `CDATAFRAME` in a .csv file (`store_cdataframe_to_csv`)

## Future Developments

Stay tuned for future updates and improvements to the project. We are always looking to enhance the functionality and performance of our DataFrame implementation.

## Contributing

We welcome contributions from the community. If you have any suggestions or improvements, feel free to create a pull request or open an issue.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.