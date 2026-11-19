# B3 – Text File vs Binary File Comparison

## 1. Objective
To compare text and binary files based on storage size, writing time and updating records.

## 2. Text File
- Stores data in readable character format.
- Easy to open and understand.
- Uses fprintf() to write records.
- Updating a particular record usually requires rewriting the file.

## 3. Binary File
- Stores data in binary format.
- Uses fwrite() and fread().
- Supports direct record access using fseek().
- Suitable for updating fixed-size records.

## 4. Performance Comparison

The program tests:
- 10 records
- 1,000 records
- 10,000 records
- 100,000 records

Record the actual values displayed by your program:

| Records | Text Size | Binary Size | Text Time | Binary Time |
|---|---|---|---|---|
| 10 | | | | |
| 1,000 | | | | |
| 10,000 | | | | |
| 100,000 | | | | |

## 5. Binary Record Update

The update_units() function uses:
- fseek() to locate a record.
- fread() to read the record.
- fwrite() to save the updated record.

## 6. Conclusion

Text files are easy to read, while binary files support direct access to fixed-size records. Binary storage is useful when individual records must be updated efficiently.
